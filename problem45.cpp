#include <bits/stdc++.h>
using namespace std;

unsigned long long triangleSequence(int x)
{
    return x * (x + 1) / 2;
}

unsigned long long pentagonalSequence(int x)
{
    return x * (3 * x - 1) / 2;
}

unsigned long long hexagonalSequence(int x)
{
    return x * (2 * x - 1);
}

bool isPentagonal(unsigned long long x)
{
    unsigned long long n = ((sqrt(1 + 24 * x) + 1) / 6);

    auto pen_Test = n * (3 * n - 1) / 2;
    return pen_Test == x;
}

bool isHexagonal(int x)
{
    double hexTest = (sqrt(1 + 8 * x) + 1.0) / 4.0;
    return hexTest == ((long int)hexTest);
}

int main()
{
    unsigned long long i = 143;
    unsigned long long result;

    while (true)
    {
        i++;
        result = i * (2 * i - 1);

        if (isPentagonal(result))
        {
            cout << result << endl;
            break;
        }
    }
}