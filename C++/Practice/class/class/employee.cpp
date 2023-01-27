#include "employee.h"

void Employee::print_info() const {
    std::cout << name << " , "<< position << " , " << age  << std::endl;
}