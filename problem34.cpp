#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int numberFactorial(int x)
{
    int temp = x;
    int result = 0;
    for (int i = floor(log10(x)); i >= 0; i--)
    {
        result += fact[int(temp / int(pow(10, i)))];
        /*cout << temp / int(pow(10, i)) << " ";
        cout << temp % int(pow(10, i)) << endl;*/
        temp = temp % int(pow(10, i));
    }
    return result;
}

int main()
{
    int answer = 0;
    for (int i = 10; i <= MAX; i++)
    {
        if (numberFactorial(i) == i)
            answer += i;
    }
    cout << answer << endl;
}