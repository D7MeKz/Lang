#include<iostream>
#include <typeinfo>

template<int X, int Y>
struct GCD{
    static const int value = GCD<Y, X%Y>::value;
};

template<int X>
struct GCD{
    static const int value = X;
};

template<int N, int D=1>
struct Ratio{
private:
    const static int _gcd = GCD<N, D>::value;

public:
    typedef Ratio<N / _gcd, D/_gcd> type;
    static const int num = N / _gcd;
    static const int den = D / _gcd;
};

template<class R1, class R2>
struct _Ratio_add{
    using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

// 상속 받음.. wow... 
template<class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type{};

