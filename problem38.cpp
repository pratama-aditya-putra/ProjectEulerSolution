#include <bits/stdc++.h>
#include <time.h>
using namespace std;

bool pandigital(string x)
{
    bool temp[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < x.length(); i++)
    {
        if (temp[x[i] - '0'] == 1)
            return false;
        else
            temp[x[i] - '0'] = 1;
    }
    return true;
}

int conditionChecker(int x)
{
    string temp = "";
    int a = x;
    while (temp.length() < 9)
    {
        temp += to_string(a);
        a += x;
    }
    if (temp.length() != 9)
        return 0;
    if (pandigital(temp))
        return stoi(temp);
    return 0;
}

int main()
{
    clock_t clkStart;
    clock_t clkFinish;

    clkStart = clock();
    int temp;
    int largest = 0;
    for (int i = 1; i <= 99999; i++)
    {
        temp = conditionChecker(i);
        if (temp != 0)
            if (temp > largest)
                largest = temp;
    }
    cout << largest << endl;

    clkFinish = clock();
    std::cout << clkFinish - clkStart;

    return 0;
}