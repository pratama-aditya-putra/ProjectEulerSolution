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
    bool flag;
    for (int i = 9; i <= MAX; i += 2)
    {
        if (!prime[i])
        {
            flag = false;
            for (int j = 1; 2 * j * j < i; j++)
            {
                if (prime[i - 2 * j * j])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << i << endl;
                break;
            }
        }
    }
}