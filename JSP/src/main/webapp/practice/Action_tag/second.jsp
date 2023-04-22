<%--
  Created by IntelliJ IDEA.
  User: D7MeKz
  Date: 2023-04-18
  Time: 오전 9:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.util.Date" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
  <h3>This is second page!! <%=new Date()%></h3>
    <p>My id is <%=request.getParameter("id")%></p>
    <p>My name is <%=request.getParameter("name")%></p>
    <p>Today is <%=request.getParameter("date")%></p>
</body>
</html>
