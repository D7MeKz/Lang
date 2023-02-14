#include <iostream>
#include<tchar.h>
#include <string>
#include <string_view>

// 컴파일러가 string&을 사용할때는 스트링 리터럴 복사본을 사용한다.(string만 사용할 수 있다.)
// 그러나 우리는 string <-> (const) char*를 많이 사용한다. 그러기때문에 data()(char), c_str(const char*)  -> 오버헤드 발생
std::string_view extract_extension(std::string_view filename)
{
    return filename.substr(filename.rfind('.'));
}

int main()
{
    // string 
    std::string file1 = R"(c:\temp\my_file.ext)"; // string 객체 복사 
    std::cout << "C++ string" << extract_extension(file1) << std::endl;
    
    // string_view
    // string 복제가 발생하지 않는다.  
    std::cout << "String view" << extract_extension(R"(c:\temp\view_sam.exe)");

    // string 생성자를 직접 얻고 싶다면 data()를 사용해야한다.
    std::string_view sv = "Hello"?
    std::string cpy_sv =  sv.data();
    
    return 0;
}

