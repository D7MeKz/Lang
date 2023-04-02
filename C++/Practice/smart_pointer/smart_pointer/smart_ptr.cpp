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

// unique_ptr�� �ܵ� �������� ǥ���ϱ� ������ ������ �� ����. 
class Foo {
public:
	// ���簡 ���� �ʱ� ������ �������� �������� �̵��Ѵٴ� ������ ����ؾ� �Ѵ�. 
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
	// �̷��� �ڵ��ϸ� �޸� ������ �߻��� ���ɼ��� �����ִ�. 
	// go method�� Exception�� �߻��ϸ� delete�� ���������� ������� �ʴ´�. 
	Sample* mySamplePtr = new Sample();
	(*mySamplePtr).go();  // = mySamplePtr->go()
	delete mySamplePtr;
}

void not_leaky()
{
	// �Լ��� �����ų� ���ܰ� �߻��ϸ� �Ҹ��ڰ� ȣ���Ҷ� Simple ��ü�� �ڵ����� �����ȴ�. 
	auto mySimpleSmartPtr = std::unique_ptr<Sample>();
	mySimpleSmartPtr->go();
}

int main(void)
{
	auto sample_main = std::unique_ptr<Sample>();
	//  ���� ������ ���� ����
	std::cout << sample_main.get() << std::endl;

	// ���� ������ ���� �� nullptr�� �ʱ�ȭ
	sample_main.reset();
	sample_main.reset(new Sample()); // ���ο� ��ü�ε� ���� 

	// ���� �������� ���� ���� 
	Sample* simple = sample_main.release(); // ������ ����
	delete simple; // ���� ��������� �Ѵ�. 

	// ������ ����!!
	simple = nullptr; 


}