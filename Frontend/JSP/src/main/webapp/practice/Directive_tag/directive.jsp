<%--
  Created by IntelliJ IDEA.
  User: D7MeKz
  Date: 2023-04-18
  Time: 오전 9:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.util.Date, java.lang.Math" %>
<html>
<head>
    <title>Directive Tag Practice</title>
</head>
<body>
    <h3>Page Directive Tag Practice</h3>
    <p>현재 날짜 : <%=new Date()%></p>
    <p>5의 제곱: <%=Math.pow(5,2)%></p>
    <hr>

    <h3>Include Directive Tag Practice</h3>
    <h4>Hello, Java Server Pages</h4>
    <%@include file="include.jsp"%>
    <hr>

</body>
</html>
