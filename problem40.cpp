#include <bits/stdc++.h>
using namespace std;

int digit(int x)
{
    if (x < 10)
        return x;
    if (x == 10)
        return 1;
    int a = 1, a1 = 9;
    int temp = 0;
    int b = 1;
    for (b = 2; x > a1; b++)
    {
        a = a1 + 1;
        a1 = a1 + (9 * pow(10, b - 1) * b);
    }
    b--;
    string temp2 = to_string(int((x - a + 1) / b + pow(10, b - 1) - 1));
    if ((x - a + 1) % b == 0)
        return int(temp2[b - 1] - '0');
    else
        return int(temp2[(x - a + 1) % b - 1] - '0');
}

int main()
{
    int sum = 1;
    for (int i = 1; i <= 1000000; i *= 10)
    {
        sum *= digit(i);
    }
    cout << sum;
}