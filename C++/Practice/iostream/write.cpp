#include<iostream>
#include <fstream>
#include <string>

int main()
{
    // * app은 append라고 보면 된다. 
    // ! 파일을 열때 위치 지정자가 파일 끝으로 하고 싶다면 ios::ate를 설정하자.
    std::ofstream out("./sample.txt", std::ios::app);
    std::string s;

    if(out.is_open())
    {
        out << "ENDL APPEND!!\n";
    }

    out.close(); // out을 쓰고 나면 바로 닫아주자.

    std::ifstream in("./sample.txt");
    if(in.is_open())    
    {
        in.seekg(0, std::ios::end);
        int size= in.tellg();
        s.resize(size);

        in.seekg(0, std::ios::beg);
        in.read(&s[0], size);
        std::cout << s;
    }
    in.close();
    return 0;
}