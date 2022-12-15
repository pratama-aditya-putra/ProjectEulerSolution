#include <bits/stdc++.h>
using namespace std;

bool palindromeChecker(int x, int y, int result)
{
    bool temp[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string stringTotal;
    stringTotal = to_string(x) + to_string(y) + to_string(result);
    if (stringTotal.length() != 9)
        return 0;
    for (int i = 0; i < 9; i++)
    {
        if (temp[int(stringTotal[i] - '0')] == 0)
            temp[int(stringTotal[i] - '0')] = 1;
        else
            return 0;
    }
    return 1;
}

int main()
{
    vector<int> productList;
    int sum = 0;
    for (int i = 1; i <= 99; i++)
    {
        for (int j = 100; j <= 9999; j++)
        {
            if (palindromeChecker(i, j, i * j))
            {
                bool temp = 1;
                for (int k = 0; k < productList.size(); k++)
                {
                    if (productList[k] == i * j)
                        temp = 0;
                }
                if (temp)
                    productList.push_back(i * j);
            }
        }
    }
    for (int k = 0; k < productList.size(); k++)
    {
        sum += productList[k];
    }
    cout << sum;
}