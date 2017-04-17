/**
@file		20151639.c
@brief		프로그래밍 기초 및 실습(04분반) 김홍준 교수님 
@intro		FinalProject 통신중계기 과제
@author		Jungin Park(pjinup@gmail.com)
@date		2016-11-27	13:22:00
*/

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

///>전역변수 배열로 선언
char A[100][100] = { 0, };



/**
@brief	파일을 열어서 값을 가져오는 function
@param	void
@return 함수 실행 정상 여부
*/

int main(void)
{
	///> test_case  행렬의 갯수
	///> row  행크기
	///> hight 열크기
	///> null 버리는 값
	///> count_h 중계기가 닿지 않는 집의 갯수
	int test_case;
	int row;
	int column;
	char null;
	int count_h = 0;


	FILE* fp = NULL;
	fp = fopen("sample_input.txt", "r");	///>Sample_input.txt에서 읽기로 가져오겠다.
	if (fp == NULL)
	{
		printf("Error 발생~!!\n");
		return -1;
	}


	fscanf(fp, "%d", &test_case);			///>메모장 첫번째 숫자를 test_case에 저장합니다.
	
	for (int i = 0; i < test_case; i++)		///>저장된 test_case만큼 반복합니다.
	{
		int count_h = 0;

		fscanf(fp, "%d", &row);				///>두번째 숫자를 row에 저장합니다.

		fscanf(fp, "%d", &column);			///>세번째 숫자를 hight에 저장합니다.
		
		fscanf(fp, "%c", &null);			///>열에서 행렬값으로 이동하는 한칸을 없애기 위해서(숫자다음 행렬이 시작하는 부분인 커서가 이동하는 한칸을 없애기 위해서)

		for (int i = 0;i < row;i++)			///>행렬을 불러온것
		{
			for (int j = 0;j < column;j++)
			{
				fscanf(fp, "%c", &A[i][j]);
			}
			fscanf(fp, "%c", &null);
		}

		/*불러온 행렬을 가공하는 반복문*/
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (A[i][j] == 'C' || A[i][j] == 'B' || A[i][j] == 'A')		///>A[i][j]의 값이 A또는 B또는 C이면 왼쪽 오른쪽 위 아래의 배열의 값을 O로 교체한다.
				{
					A[i][j - 1] = 'O';										
					A[i - 1][j] = 'O';										
					A[i][j + 1] = 'O';										
					A[i + 1][j] = 'O';										
				}
				if (A[i][j] == 'B' || A[i][j] == 'A')						///>A[i][j]의 값이 A또는 B이면 왼쪽 오른쪽 위 아래 두 번째 배열의 값을 O로 교체한다.
				{
					A[i][j - 2] = 'O';										
					A[i - 2][j] = 'O';										
					A[i][j + 2] = 'O';										
					A[i + 2][j] = 'O';										
				}
				if (A[i][j] == 'A')											///>A[i][j]의 값이 A이면 왼쪽 오른쪽 위 아래 세 번째 배열의 값을 O로 교체한다.
				{
					A[i][j - 3] = 'O';										
					A[i - 3][j] = 'O';										
					A[i][j + 3] = 'O';										
					A[i + 3][j] = 'O';										
				}
			}
		}

		 /*가공된 행렬에서 중계기 범위에서 벗어난 집의 개수를 세는 반복문*/
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (A[i][j] == 'H')
					count_h++;												///>배열에서 'H' 의 갯수를 센다.
			}
		}

		printf("중계기가 커버하지 못하는 집의 갯수 : %d\n", count_h);			///>결과를 출력한다.
		memset(A, 0, sizeof(A));											///>모든 배열 A의 값을 0으로 설정
	}

	fclose(fp);																///>불러온 파일 닫기
	return 0;
}

