#include<iostream>
#include <string.h>

class MyString{
    char* string_content;
    int string_len;
    int memory_capacity;

public:
    MyString(char c);
    MyString(const char* c); // 문자열로부터 
    MyString(const MyString& c); // 복사 생성자 
    ~MyString();

    int length() const;
    int capacity() const;
    void print() const; 
    void println() const;
    
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
    
};

MyString::MyString(char c)
{
    this->string_content = new char[1];
    this->string_content[0] = c;
    this->string_len = 1;
    this->memory_capacity = 1;
}

MyString::MyString(const char* c)
{
    this->string_len = strlen(c);
    this->memory_capacity = this->string_len;
    this->string_content = new char[this->string_len];
    for(int i = 0 ; i < this->string_len ; i++){
        this->string_content[i] = c[i];
    }
}

MyString::MyString(const MyString& c)
{
    this->string_len = c.string_len;
    this->memory_capacity = c.string_len;
    for(int i = 0 ; i < this->string_len ; i++)
    {
        this->string_content[i] = c.string_content[i];
    }

}

MyString::~MyString()
{
    delete[] this->string_content;
}

int MyString::length() const
{
    return this->string_len;
}

void MyString::print() const
{
    for(int i = 0 ; i < this->string_len ; i++)
    {
        std::cout << this->string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != this->string_len; i++) {
        std::cout << this->string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str)
{
    if(str.string_len > this->memory_capacity)
    { 
        delete[] this->string_content; 
        this->string_content = new char[str.string_len];
        this->memory_capacity = str.string_len;
    }
    for(int i = 0 ; i < str.string_len ; i++)
    {
        this->string_content[i] = str.string_content[i];
    }

    this->string_len = str.string_len;
    return *this;
}

int MyString::capacity() const
{
    return this->memory_capacity;
}

int main()
{
    MyString str1("D7MeKz!!");
    MyString str2(str1);

    str1.println();
    str2.println();
}