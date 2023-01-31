#include<iostream>

// 나만의 std::array 구현
template<typename T, unsigned int N>
class Array
{
    T data[N];
public:
    Array (T(&arr)[N])// 배열 생성잘 할당 
    {
        for(int i = 0 ; i < N; i++)
        {
            data[i] = arr[i];
        }
    }

    T* get_array(){return data;}

    unsigned int size() {return N;}

    void print_all()
    {
        for(int i = 0 ; i < N ;i++)
        {
            std::cout << data[i] << ",";
        }
        std::cout << std::endl;
    }
};

template<int N>
struct Int{
    // static은 클래스가 생성한 객체들 사이에서 공유되는 값이다.
    // const는 값이 변화하지 않는다.
    // 즉, 이 값은 무조건  클래스거다!! 라는 것을 알려준다. 
    static const int num = N;
};

// template class 
// 이게 왜 template class이지??
template<typename T, typename U>
struct add{
    //T,U를 Int로 받았고, Int가 num을 가지고 있다. 
    typedef Int<T::num + U::num> result;
};

int main()
{
    typedef Int<1> one;
    typedef Int<2> two;
    typedef add<one, two>::result three;
    int arr[3] = {1, 2, 3};

    // T data -> int data
    Array<int, 3> arr_w(arr);
    arr_w.print_all();

    std::cout << "Addtion result: "<< three::num <<std::endl;
}
