<%@ page language="java"contentType="text/html; charset=UTF-8"pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8");%>
<!doctype html><!--	formPublic1.jsp	-->
<html>
<head>
<meta charset="utf-8"/>
<meta name="viewport"content="width=device-width,initial-scale=1"/>
<title>폼 학습</title>
</head>
<body>
<section>
<h2>JSP form</h2>
<section>
<h2>대중교통로</h2><br/>
<h2><%=request.getParameter("fromx")%>에서<%=request.getParameter("tox")%>까지<br/></h2>

</section>
</section>

<footer>
<p>&copy; 20XXMade by Korea. All rights reserved.</p></footer>
</body>
</html>