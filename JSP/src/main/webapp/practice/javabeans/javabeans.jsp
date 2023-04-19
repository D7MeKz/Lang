<%@ page import="com.example.jsp.MemberBean" %><%--
  Created by IntelliJ IDEA.
  User: D7MeKz
  Date: 2023-04-19
  Time: 오후 2:08
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:useBean id="Member" class="com.example.jsp.MemberBean" scope="request" />
    <jsp:setProperty name="Member" property="id" value="8" />
    <jsp:setProperty name="Member" property="name" value="sample"/>
    <p>Id : <%=Member.getId()%></p>
    <p>Name :<jsp:getProperty name="Member" property="id"/></p>
</body>
</html>
