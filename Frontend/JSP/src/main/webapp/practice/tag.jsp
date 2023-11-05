<%--
  Created by IntelliJ IDEA.
  User: D7MeKz
  Date: 2023-04-18
  Time: 오전 8:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <h2>스크립틀릿, 선언문, 표현문 연습</h2>
    <hr>
    Page Count is:
    <%
        out.println(myMethod(0)); // 스크립틀릿, 자바 로직 코드를 작성하는데 사용
    %>
    <%!
        // 선언문 : 변수 선언, 메소드 정의
        int data = 50;
        public int myMethod(int count){
            return ++count; // 선언문
        }
    %>
    <h5>The Data is <%=data%></h5>
    <hr>
<%--    덧셈을 해라--%>
    <%!
        public int sum(int a, int b){
            return a+b;
        }
    %>
    <%
        out.println("<h4>"+sum(1,2)+"</h4>");
    %>
    <hr>
<%--    Hello world를 소문자로 출력해라.--%>
<%!
    String toLower(String data){
        return data.toLowerCase();
    }
%>
<%
    // 스크립틀릿은 변수만 선언할 수 있다.
    out.println("<h3>"+toLower("Hello WORLD!")+"</h3>");
%>
<hr>
<%
    for(int i = 1; i <=9; i++){
        for(int j = 1; j<=9; j++){
            out.println(i + "*" + j + "=" + i*j + "<br>");
        }
    }
%>
<hr>
<%--외부로 출력할 수 있음--%>
<p>Today's date: <%= new java.util.Date()%></p>
</body>
</html>
