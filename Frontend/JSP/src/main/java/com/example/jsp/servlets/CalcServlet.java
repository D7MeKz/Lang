package com.example.jsp.servlets;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "CalcServlet", value = "/CalcServlet")
public class CalcServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        int n1 = Integer.parseInt(req.getParameter("n1"));
        int n2 = Integer.parseInt(req.getParameter("n2"));
        String op = req.getParameter("op");
        long result = 0;

        switch (req.getParameter("op")){
            case "+": result = n1 + n2; break; // break는 필수로 넣어야 한다.
            case "-": result = n1 - n2; break;
            case "*" : result = n1 * n2; break;
        }
        res.setContentType("text/html; charset=utf-8");
        PrintWriter out =res.getWriter();
        out.println("<html><body><h2>계산기 서블릿<h2><br>");
        out.println("<h4>"+ result  + "</h4></body></html>");

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        doGet(req,res);
    }
}
