/**
@file		20151639.c
@brief		���α׷��� ���� �� �ǽ�(04�й�) ��ȫ�� ������ 
@intro		FinalProject ����߰�� ����
@author		Jungin Park(pjinup@gmail.com)
@date		2016-11-27	13:22:00
*/

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

///>�������� �迭�� ����
char A[100][100] = { 0, };



/**
@brief	������ ��� ���� �������� function
@param	void
@return �Լ� ���� ���� ����
*/

int main(void)
{
	///> test_case  ����� ����
	///> row  ��ũ��
	///> hight ��ũ��
	///> null ������ ��
	///> count_h �߰�Ⱑ ���� �ʴ� ���� ����
	int test_case;
	int row;
	int column;
	char null;
	int count_h = 0;


	FILE* fp = NULL;
	fp = fopen("sample_input.txt", "r");	///>Sample_input.txt���� �б�� �������ڴ�.
	if (fp == NULL)
	{
		printf("Error �߻�~!!\n");
		return -1;
	}


	fscanf(fp, "%d", &test_case);			///>�޸��� ù��° ���ڸ� test_case�� �����մϴ�.
	
	for (int i = 0; i < test_case; i++)		///>����� test_case��ŭ �ݺ��մϴ�.
	{
		int count_h = 0;

		fscanf(fp, "%d", &row);				///>�ι�° ���ڸ� row�� �����մϴ�.

		fscanf(fp, "%d", &column);			///>����° ���ڸ� hight�� �����մϴ�.
		
		fscanf(fp, "%c", &null);			///>������ ��İ����� �̵��ϴ� ��ĭ�� ���ֱ� ���ؼ�(���ڴ��� ����� �����ϴ� �κ��� Ŀ���� �̵��ϴ� ��ĭ�� ���ֱ� ���ؼ�)

		for (int i = 0;i < row;i++)			///>����� �ҷ��°�
		{
			for (int j = 0;j < column;j++)
			{
				fscanf(fp, "%c", &A[i][j]);
			}
			fscanf(fp, "%c", &null);
		}

		/*�ҷ��� ����� �����ϴ� �ݺ���*/
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (A[i][j] == 'C' || A[i][j] == 'B' || A[i][j] == 'A')		///>A[i][j]�� ���� A�Ǵ� B�Ǵ� C�̸� ���� ������ �� �Ʒ��� �迭�� ���� O�� ��ü�Ѵ�.
				{
					A[i][j - 1] = 'O';										
					A[i - 1][j] = 'O';										
					A[i][j + 1] = 'O';										
					A[i + 1][j] = 'O';										
				}
				if (A[i][j] == 'B' || A[i][j] == 'A')						///>A[i][j]�� ���� A�Ǵ� B�̸� ���� ������ �� �Ʒ� �� ��° �迭�� ���� O�� ��ü�Ѵ�.
				{
					A[i][j - 2] = 'O';										
					A[i - 2][j] = 'O';										
					A[i][j + 2] = 'O';										
					A[i + 2][j] = 'O';										
				}
				if (A[i][j] == 'A')											///>A[i][j]�� ���� A�̸� ���� ������ �� �Ʒ� �� ��° �迭�� ���� O�� ��ü�Ѵ�.
				{
					A[i][j - 3] = 'O';										
					A[i - 3][j] = 'O';										
					A[i][j + 3] = 'O';										
					A[i + 3][j] = 'O';										
				}
			}
		}

		 /*������ ��Ŀ��� �߰�� �������� ��� ���� ������ ���� �ݺ���*/
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (A[i][j] == 'H')
					count_h++;												///>�迭���� 'H' �� ������ ����.
			}
		}

		printf("�߰�Ⱑ Ŀ������ ���ϴ� ���� ���� : %d\n", count_h);			///>����� ����Ѵ�.
		memset(A, 0, sizeof(A));											///>��� �迭 A�� ���� 0���� ����
	}

	fclose(fp);																///>�ҷ��� ���� �ݱ�
	return 0;
}

