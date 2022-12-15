#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

string reverseString(string x)
{
    string result;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        result += x[i];
    }
    return result;
}

string intToBinary(int x)
{
    if (x <= 1)
        return to_string(x);
    string result = to_string(x % 2);
    return result += intToBinary(x / 2);
}

bool palindromeChecker(string x)
{

    bool flag = true;
    int a = 0, b = x.length() - 1;
    while (a < b)
    {
        if (x[a] != x[b])
        {
            return false;
            break;
        }
        a++;
        b--;
    }
    return flag;
}

int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;
    if (isOdd)
    {
        n /= b;
    }

    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }

    return palin;
}

int main()
{
    int result = 0;
    int number;

    for (int j = 0; j < 2; j++)
    {
        bool isOdd = (j % 2 == 0);
        int i = 1;
        while ((number = createPalindrome(i, 10, isOdd)) < 1000000)
        {
            if (palindromeChecker(intToBinary(number)))
            {
                // cout << number << endl;
                result += number;
            }
            i++;
        }
    }
    cout << result;
}