#include <bits/stdc++.h>
#define MAX 1000000
#define DIGITS 4
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

vector<int> distinctPrimeFactor(int x)
{
    vector<int> result;
    bool flag = true;
    while (flag)
    {
        if (prime[x])
        {
            flag = false;
            if (count(result.begin(), result.end(), x) == 0)
                result.push_back(x);
            return result;
        }
        for (int i = 2; i <= x; i++)
        {
            if (prime[i])
            {
                if (x % i == 0)
                {
                    if (count(result.begin(), result.end(), i) == 0)
                        result.push_back(i);
                    x /= i;
                    // cout << x << " " << i << endl;
                    break;
                }
            }
        }
    }
}

int main()
{
    generatePrime();
    int counts = 0;
    int lastNumber = 0;
    for (int i = 100; true; i++)
    {
        if (prime[i])
            continue;
        vector<int> temp = distinctPrimeFactor(i);
        if (temp.size() != DIGITS)
            continue;
        if (lastNumber != i - 1)
            counts = 0;
        counts++;
        /*
        cout << i << " = ";
        for (int j = 0; j < DIGITS; j++)
            cout << temp[j] << " ";
        cout << endl;*/
        if (counts == DIGITS)
        {
            cout << i - DIGITS + 1 << " ";
            break;
        }
        lastNumber = i;
    }
}