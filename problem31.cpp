#include <bits/stdc++.h>
#define MAX 200

using namespace std;

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int sum[MAX + 1];
    for (int i = 0; i <= MAX; i++)
    {
        sum[i] = 0;
    }
    sum[0] = 1;
    for (int i = 0; i < sizeof(coins) / sizeof(int); i++)
    {
        for (int j = coins[i]; j <= MAX; j++)
        {
            sum[j] += sum[j - coins[i]];
        }
    }

    cout << sum[MAX + 1] << " ";
}