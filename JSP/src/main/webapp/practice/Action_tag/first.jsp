<%--
  Created by IntelliJ IDEA.
  User: D7MeKz
  Date: 2023-04-18
  Time: 오전 9:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.util.Calendar" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
  <h2>This is first page</h2>
  <jsp:include page="second.jsp">
      <jsp:param name="id" value="damekz7"/>
      <jsp:param name="name" value="dam"/>
      <jsp:param name="date" value="<%=Calendar.getInstance().getTime()%>"/>
  </jsp:include>
</body>
</html>
