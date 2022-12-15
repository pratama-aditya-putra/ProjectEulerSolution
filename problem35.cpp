#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

bool prime[MAX + 1];

void generatePrime()
{
    memset(prime, true, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (prime[i] == true)
        {
            // cout << i << endl;
            for (int j = i * 2; j <= MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

bool circularPrimeChecker(int x)
{
    int temp = x;
    int n = floor(log10(x));
    if (x < 10)
        return true;
    for (int i = n; i > 0; i--)
    {
        temp = (temp % 10) * pow(10, n) + (temp / 10);
        // cout << temp << endl;
        if (!prime[temp])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int answer = 0;
    generatePrime();
    for (int i = 0; i <= MAX; i++)
    {
        if (prime[i])
        {
            if (circularPrimeChecker(i))
            {
                answer++;
            }
        }
    }
    cout << answer;
}