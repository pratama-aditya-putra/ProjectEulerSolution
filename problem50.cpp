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
            for (int j = i * 2; j <= MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    generatePrime();
    vector<int> primeList;
    long long sum = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (prime[i])
            primeList.push_back(i);
    }
    for (int i = primeList.size(); i > 0; i--)
    {
        for (int j = 0; j < (i - primeList.size()); j++)
        {
            sum = 0;
            for (int k = j; k <= (j + i); k++)
            {
                sum += primeList[k];
                if (sum > MAX)
                    break;
            }
            if (sum > MAX)
                break;
            else
            {
                if (prime[sum])
                    break;
            }
        }
        if (prime[sum])
        {
            cout << sum;
            break;
        }
    }
}