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

bool conditionCheck(int x)
{
    int a = x;
    int b = x;
    while (a >= 10)
    {
        a /= 10;
        if (!prime[a])
            return false;
        // cout << " " << a << endl;
    }
    while (b >= 10)
    {
        b %= int(pow(10, floor(log10(b))));
        if (!prime[b])
            return false;
        // cout << " " << b << endl;
    }
    return true;
}

int main()
{
    int sum = 0, limit = 0;
    generatePrime();
    for (int i = 11; i <= MAX; i++)
    {
        if (limit >= 11)
            break;
        if (prime[i])
        {
            if (conditionCheck(i))
            {
                // cout << i << endl;
                sum += i;
                limit++;
            }
        }
    }
    cout << sum;
}