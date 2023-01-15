#include <bits/stdc++.h>
#define Mod 10000000000

#define LIMIT 1000
using namespace std;

unsigned long long mulmodBitwise(unsigned long long a, unsigned long long b, unsigned long long modulo)
{
    a %= modulo;
    b %= modulo;

    if (a < 0xFFFFFFF && b < 0xFFFFFFF)
        return (a * b) % modulo;

    if (a < b)
        swap(a, b);

    unsigned long long result = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            result += a;
            result %= modulo;
        }

        a <<= 1;
        b >>= 1;
        a %= modulo;
    }
    return result;
}

unsigned long long powmod(unsigned long long base, unsigned long long exponent, unsigned long long modulo)
{
    unsigned long long result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = mulmodBitwise(result, base, modulo);

        base = mulmodBitwise(base, base, modulo);
        exponent >>= 1;
    }
    return result;
}

int main()
{
    unsigned long long sum = 0;
    for (int i = 1; i <= LIMIT; i++)
    {
        sum += powmod(i, i, Mod);
    }
    cout << sum % Mod;
}