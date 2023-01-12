// Class 4-2
// Overloading 시 여러 절차가 존재한다.
// 만약에 변경할 수 있는 자료형이 2개 이상 존재하면 ambiguous하다고 한다. 

#include<iostream>

class Date{
    int year_;
    int month_;
    int day_;

public:
    // Default Constructor 
    Date() {
        year_ = 2022;
        month_ = 1;
        day_ = 1;
    }
    Date(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetCurrentMonthTotalDays(int year, int month);
    
    void ShowDate();
};


int Date::GetCurrentMonthTotalDays(int year, int month)
{
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_day[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 29;  // 윤년
    } else {
        return 28;
    }
}

void Date::AddDay(int inc)
{
    int max_day = GetCurrentMonthTotalDays(year_, month_);

    if(day_ + inc <= max_day){
        day_ += inc;
        return ;
    }
    else{
        AddMonth(1);
        day_ = (day_ + inc ) - max_day;
        return ;
    }
}

void Date::AddMonth(int inc){
    if(month_ + inc < 12)
    {
        month_ += inc;
    }
    else{
        AddYear(1);
        month_ = (month_ + inc) - 12; 
    }
}

void Date::AddYear(int inc){
    year_ += inc;
}

void Date::ShowDate()
{
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일"<< "\n";
}

int main()
{
    Date day1(2022, 2, 1); // 암시적인 방법
    Date day2;

    day1.ShowDate();
    day2.ShowDate();
}

