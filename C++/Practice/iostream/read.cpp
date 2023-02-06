#include <iostream>
#include <fstream>
#include <string>

// * std::endl는 '\n'과 더불어 flush 역할을 해준다.
// flush는 버퍼에 얼마나 쌓였는지 상관 없이 데이터를 바로 출력해준다. 

// stream은 문자열을 순차적으로 나열하는 것이라고 보면 된다. 
// 시작 포인터, 스트림 위치 지정자, 끝 포인터 
// C++ 입출력 라이브러리는 스트림 버퍼도 추상화해서 클래스로 만들었다.
// streambuf를 도입한 이유 - wide character를 지원하기 위해서!!


int main()
{
    // Binary 형태로 받겠다!! 
    std::ifstream in("./sample.txt", std::ios::binary);
    std::string s;
    int x;
    
    // 공백은 출력해주지 않는다. 
    if(in.is_open())
    {
        in.seekg(0, std::ios::end); // 위치 지정자를 파일 끝으로!!, c언어에서 fseek 
        int size = in.tellg(); // 위치를 읽는다. -> 파일의 크기를 구한다. 시작점으로부터의 크기 반환(바이트 단위)
        s.resize(size); // 사이즈만큼 크기를 할당한다. 

        in.seekg(0, std::ios::beg); // 위치 지정자를 맨 앞으로 옮긴다.
        in.read(&s[0],size); // 파일 전체를 읽는다.
        std::cout << s;
    }
    in.close();
    // 파일 전체를 한줄씩 읽기 

    std::ifstream in_line("./sample2.txt");
    char buf[100];
    while(in_line)// bool로 casting되어 있음! 단 failbit가 켜져있으면 안된다. 
    {
        in_line.getline(buf, 100); // 한줄씩 읽는다. (최대 99)
        std::cout << buf << std::endl;
    }
    in_line.close();
}