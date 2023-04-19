package com.example.jsp;

public class MemberBean  implements java.io.Serializable{
    private int id = 5;
    private String name = "D7";
    public MemberBean(){}

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
