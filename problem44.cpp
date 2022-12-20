#include <bits/stdc++.h>
using namespace std;

bool isPentagonal(int x)
{
    double penTest = (sqrt(1 + 24 * x) + 1.0) / 6.0;
    return penTest == ((int)penTest);
}

int main()
{
    bool flag = true;
    vector<int> myVector;
    myVector.push_back(1);
    for (int i = 2; flag; i++)
    {
        myVector.push_back(i * (3 * i - 1) / 2);
        for (int j = myVector.size() - 2; j >= 0; j--)
        {
            if (isPentagonal(abs(myVector[i - 1] - myVector[j])) && isPentagonal(myVector[i - 1] + myVector[j]))
            {
                cout << abs(myVector[j] - myVector[i - 1]);
                flag = false;
            }
        }
    }
}