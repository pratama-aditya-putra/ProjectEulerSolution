#include <bits/stdc++.h>
using namespace std;

long int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
int prime[] = {2, 3, 5, 7, 11, 13, 17};
long int sum = 0;

bool pandigital(long int x)
{
    long int temp = x;
    string result = "";
    vector<int> digit;
    for (int i = 0; i < 10; i++)
        digit.push_back(i);

    for (int i = 9; i >= 0; i--)
    {
        result += to_string(digit[temp / fact[i]]);
        digit.erase(digit.begin() + temp / fact[i]);
        temp = temp % fact[i];
        if (i <= 6)
        {
            string temp1 = "";
            int temp2 = 0;
            for (int j = 3; j >= 1; j--)
                temp1 += result[result.length() - j];
            if (stoi(temp1) % prime[result.length() - 4] != 0)
                return false;
        }
    }
    cout << result << endl;
    return true;
}

bool conditionChecker(string x)
{
    string temp = "";
    for (int i = 0; i < 7; i++)
    {
        temp = "";
        for (int j = 1; j <= 3; j++)
            temp += x[i + j];
        if (stoi(temp) % prime[i] != 0)
            return false;
    }
    return true;
}

bool solution(int i, int x)
{
    string temp = to_string(x);
    if ((i == 6) && (x % prime[i] == 0))
        return true;
    if (x % prime[i])
    {
        for (int a = 0; a < 9; a++)
            solution(i + 1, (x % 100) * 10 + a);
    }
    return true;
}

int main()
{
    int sum = 0;
    for (int i = 0; i < fact[10]; i++)
    {
        pandigital(i);
    }
    // cout << conditionChecker(pandigital(10000));
    //  cout << conditionChecker("1406357289");
}