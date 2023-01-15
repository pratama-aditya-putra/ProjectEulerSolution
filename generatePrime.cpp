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

int main(){
    
}