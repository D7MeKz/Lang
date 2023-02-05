#include <stdio.h>

void func1(int x, int y, int *sum, int *product)
{
    *sum = x + y;
    *product = x * y;
}

int sum, product; 

int main()
{
    func1(5, 5, &sum, &product);
    printf("%d",sum);
    return 0;
}