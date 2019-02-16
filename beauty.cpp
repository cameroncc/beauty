#include <stdio.h>
#include <iostream>

using std::cin;

void add(int a, int b)
{
    throw (a+b);
}

int main()
{
    printf("Enter a number: ");
    int a;
    cin >> a;
    printf("\nEnter another number: ");
    int b;
    cin >> b;
    try
    {
        add(a, b);
    }
    catch(int ans)
    {
        printf("\n%d + %d = %d\n", a, b, ans);
    }
}