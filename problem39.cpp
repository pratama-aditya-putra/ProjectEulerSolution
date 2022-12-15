#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int main()
{
    int c = 0;
    int max = 0, max1 = 0;
    for (int p = 2; p <= MAX; p += 2)
    {
        c = 0;
        for (int a = 2; a < p / 3; a++)
        {
            if ((p * p - 2 * p * a) % (2 * (p - a)) == 0)
            {
                c++;
            }
        }
        if (c > max1)
        {
            max1 = c;
            max = p;
        }
    }
    cout << max1 << " " << max << endl;
}