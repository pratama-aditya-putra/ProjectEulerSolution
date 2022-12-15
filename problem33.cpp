#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    int sumNumerator = 1;
    int sumDenominator = 1;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (j == i)
                continue;
            if (float(i) / j > 1)
                continue;
            for (int x = 1; x <= 9; x++)
            {
                if ((float(i * 10 + x) / (j * 10 + x)) == (float(i) / j))
                {
                    sumNumerator *= (i * 10 + x);
                    sumDenominator *= (j * 10 + x);
                }
                if ((float(i * 10 + x) / (x * 10 + j)) == (float(i) / j))
                {
                    sumNumerator *= (i * 10 + x);
                    sumDenominator *= (x * 10 + j);
                }
                if ((float(x * 10 + i) / (j * 10 + x)) == (float(i) / j))
                {
                    sumNumerator *= (x * 10 + i);
                    sumDenominator *= (j * 10 + x);
                }
                if ((float(x * 10 + i) / (x * 10 + j)) == (float(i) / j))
                {
                    sumNumerator *= (x * 10 + i);
                    sumDenominator *= (x * 10 + j);
                }
            }
        }
    }
    // cout << sumNumerator << " / " << sumDenominator;
    cout << sumDenominator / gcd(sumDenominator, sumNumerator);
}