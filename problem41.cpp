#include <bits/stdc++.h>
#define MAX 100000000
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

bool pandigital(string x)
{
    bool temp[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = x.length() + 1; i <= 9; i++)
        temp[i] = 1;
    for (int i = 0; i < x.length(); i++)
    {
        if (temp[x[i] - '0'] == 1)
            return false;
        else
            temp[x[i] - '0'] = 1;
    }
    return true;
}

int main()
{
    generatePrime();
    for (int i = MAX; i >= i; i--)
    {
        if (prime[i])
        {
            if (pandigital(to_string(i)))
            {
                cout << i;
                break;
            }
        }
    }
}