#include <bits/stdc++.h>
#define MAX 100000
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

vector<int> insertionSort(vector<int> input)
{
    int n = input.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] > input[i])
            {
                int temp;
                temp = input[i];
                input.erase(input.begin() + i);
                input.insert(input.begin() + j, temp);
                break;
            }
        }
    }
    return input;
}

bool conditionChecker(int x, int y)
{
    vector<int> temp;
    while (x > 0)
    {
        temp.push_back(x % 10);
        x /= 10;
    }

    vector<int> temp1;
    while (y > 0)
    {
        temp1.push_back(y % 10);
        y /= 10;
    }

    bool solution = true;
    vector<int> result = insertionSort(temp);
    vector<int> result1 = insertionSort(temp1);
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != result1[i])
            solution = false;
    }
    return solution;
}

int main()
{
    bool flag;
    generatePrime();
    for (int i = 1000; i + 3330 < 10000; i++)
    {
        flag = 1;
        if (!prime[i])
            continue;

        for (int j = i; j < 10000; j += 3330)
        {
            if (!prime[j])
            {
                flag = 0;
                break;
            }
            if (!conditionChecker(i, j))
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
            continue;
        if (i == 1487)
            continue;
        for (int k = i; k < 10000; k += 3330)
            cout << k;
        break;
    }
}