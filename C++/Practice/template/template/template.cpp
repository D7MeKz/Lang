#include "template.h"

/*Practice 1*/
// Wow C++11 형식이라네
// template보다 일반 함수의 우선순위가 더 높기 때문에
// 해당 인자에 맞게 print가 출력되면 template이 아닌 
// 아래의 함수를 실행하게 된다. 
void print(double arg, const char* args)
{
	std::cout << arg << ", " << std::endl;
	print(args);
}

// template의 순서도 중요하다. 
// 재귀 호출 방식으로 사용되기 때문에 Base case가 필요하다. 
template<typename T>
void print(T arg) // 인자를 여러개 받음 
{
	std::cout << arg << std::endl;
}

template<typename T, typename... Types> // ... template parameter pack
void print(T arg, Types... args) // ... Function Parameter pack , 인자를 많이 입력받음 
{
	std::cout << arg << std::endl; // 첫번째 숫자를 얻음 ex) 1 
	print(args...); // 그 나머지 출력 ex) 3.1, "abc"
}

/*Practice 2*/
size_t GetStringSzie(const char* s) { return strlen(s); }
size_t GetStringSize(std::string s) { return s.size(); }

template<typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... str)
{
	return GetStringSize(s) + GetStringSize(str...);
}

void AppendToString(std::string* concat_str) { return; }

// 포인터로 받는다. 
template<typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... str)
{
	concat_str->append(s); // concat_str에 
	AppendToString(concat_str, str...);
}

template<typename String>
std::string strCat(const String& s)
{
	return std::string(s);
}

template<typename String, typename... Strings>
std::string strCat(const String& s, Strings... strs)
{
	size_t str_len = GetStringSize(s, strs...);

	std::string concat_str;
	concat_str.reserve(str_len);
	
	// sizeof...은 파라미터 팩의 개수를 나타냄 
	std::cout << "The number of str's: " << sizeof...(strs);
	
	AppendToString(&concat_str, s, strs...);
	return concat_str;
}

/*Practice3*/
// C++17 Fold 형식 
// Fold식을 사용할때는 반드시 ()로 묶어줘야 한다.

size_t GetString(const std::string& s)
{
	return s.size();
}
template<typename String, typename... Strings>
size_t GetStringSizeEx(const String& s, Strings... str)
{
	// (5  + 3 + ...) 
	return GetString(s) + (GetString(str) + ... );
}

int main()
{
	// print(1, 3.1, "abc");
	// print(1, 2, 3, 4, 5, 6, 7);

	std::string s1 = "hello";
	std::string s2 = "world?";
	std::string s3 = "hi";
// 	std::string str = strCat(s1, "abc", s2, s3);
//	std::cout << str << std::endl;

	size_t str_size_ex = GetStringSizeEx(s1, s2, s3);
	std::cout << str_size_ex << std::endl;
}