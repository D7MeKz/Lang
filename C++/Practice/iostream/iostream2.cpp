#include <iostream>
#include <string>

// std::endl는 '\n'과 더불어 flush 역할을 해준다.
// flush는 버퍼에 얼마나 쌓였는지 상관 없이 데이터를 바로 출력해준다. 

// stream은 문자열을 순차적으로 나열하는 것이라고 보면 된다. 
// 시작 포인터, 스트림 위치 지정자, 끝 포인터 
// C++ 입출력 라이브러리는 스트림 버퍼도 추상화해서 클래스로 만들었다.
// streambuf를 도입한 이유 - wide character를 지원하기 위해서!! 