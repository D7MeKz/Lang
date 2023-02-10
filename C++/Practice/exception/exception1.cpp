#include<iostream>

template <typename T>
class Vector{
private:
    T* data_;
    size_t size_;
public:
    Vector(size_t size) : size_(size)
    {
        data_ = new T[size_];
        for(int i = 0 ; i < size; i++)
        {
            data_[i] = 3; 
        }
    }

    const T& at(size_t index) const {
        if(index >= size_)
        {
            // * 예외가 발생하면 throw 아래의 코드는 실행되지 않는다. 
            // * 예외를 던진다!!!
            // ! 함수에서 예외 처리하는 부분에 도달하기까지 함수를 빠져나가면서,
            // ! stack에 생성되었던 객체들을 소멸시켜준다. (소멸자가 있다.)
            throw std::out_of_range("Out of the range");
        }
        return data_[index];
    }
    ~Vector() {delete[] data_;}
};

int main()
{
    Vector<int> vec(3);
    int index, data = 0;
    std::cin >> index;

    try
    {
        data = vec.at(index);
    }catch(std::out_of_range& e){
        // throw에서 선언한 부분이 e.what로 저장되어 있다. 
        std::cout << "예외 발생" << e.what() << std::endl;
    }

    std::cout << "읽은 데이터" << data << std::endl;
}
// 참고로 생성자에서 예외를 던질때에는 소멸자를 생성하지 않는다. 
// 그러므로 예외를 처리할때는 소멸자를 실행시켜야한다. 