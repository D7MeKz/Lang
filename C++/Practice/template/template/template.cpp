#include "template.h"

/*Practice 1*/
// Wow C++11 �����̶��
// template���� �Ϲ� �Լ��� �켱������ �� ���� ������
// �ش� ���ڿ� �°� print�� ��µǸ� template�� �ƴ� 
// �Ʒ��� �Լ��� �����ϰ� �ȴ�. 
void print(double arg, const char* args)
{
	std::cout << arg << ", " << std::endl;
	print(args);
}

// template�� ������ �߿��ϴ�. 
// ��� ȣ�� ������� ���Ǳ� ������ Base case�� �ʿ��ϴ�. 
template<typename T>
void print(T arg) // ���ڸ� ������ ���� 
{
	std::cout << arg << std::endl;
}

template<typename T, typename... Types> // ... template parameter pack
void print(T arg, Types... args) // ... Function Parameter pack , ���ڸ� ���� �Է¹��� 
{
	std::cout << arg << std::endl; // ù��° ���ڸ� ���� ex) 1 
	print(args...); // �� ������ ��� ex) 3.1, "abc"
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

// �����ͷ� �޴´�. 
template<typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... str)
{
	concat_str->append(s); // concat_str�� 
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
	
	// sizeof...�� �Ķ���� ���� ������ ��Ÿ�� 
	std::cout << "The number of str's: " << sizeof...(strs);
	
	AppendToString(&concat_str, s, strs...);
	return concat_str;
}

/*Practice3*/
// C++17 Fold ���� 
// Fold���� ����Ҷ��� �ݵ�� ()�� ������� �Ѵ�.

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