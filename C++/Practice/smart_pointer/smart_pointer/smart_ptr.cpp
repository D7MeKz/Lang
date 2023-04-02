#include<iostream>
#include<memory>

class Sample {
private:
	int a;
	int b;
public:
	void go()
	{
		std::cout << "This is Go Example!!" << std::endl;
	}
};

// unique_ptr는 단독 소유권을 표현하기 때문에 복사할 수 없다. 
class Foo {
public:
	// 복사가 되지 않기 때문에 포인터의 소유권을 이동한다는 개념을 사용해야 한다. 
	Foo(std::unique_ptr<int> data) : mData(move(data)) {}; 
private:
	std::unique_ptr<int> mData;
};

void leaky()
{
	Sample* mySamplePtr = new Sample();
	mySamplePtr->go();
}

void could_be_leaky()
{
	// 이렇게 코딩하면 메모리 누수가 발생할 가능성이 남아있다. 
	// go method에 Exception이 발생하면 delete가 정상적으로 실행되지 않는다. 
	Sample* mySamplePtr = new Sample();
	(*mySamplePtr).go();  // = mySamplePtr->go()
	delete mySamplePtr;
}

void not_leaky()
{
	// 함수가 끝나거나 예외가 발생하면 소멸자가 호출할때 Simple 객체가 자동으로 해제된다. 
	auto mySimpleSmartPtr = std::unique_ptr<Sample>();
	mySimpleSmartPtr->go();
}

int main(void)
{
	auto sample_main = std::unique_ptr<Sample>();
	//  내부 포인터 직접 접근
	std::cout << sample_main.get() << std::endl;

	// 내부 포인터 해제 후 nullptr로 초기화
	sample_main.reset();
	sample_main.reset(new Sample()); // 새로운 객체로도 가능 

	// 내부 포인터의 관계 끊기 
	Sample* simple = sample_main.release(); // 소유권 해제
	delete simple; // 직접 해제해줘야 한다. 

	// 재사용을 위해!!
	simple = nullptr; 


}