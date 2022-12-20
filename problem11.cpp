#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result = 0;

    vector<vector<int>> myList;
    fstream newfile;
    string stringInput = "";
    newfile.open("p11.txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            stringInput += tp;
            vector<int> tempVector;
            string temp = "";
            for (int i = 0; i < tp.length(); i++)
            {
                if (tp[i] == ' ')
                {
                    tempVector.push_back(stoi(temp));
                    temp = "";
                    continue;
                }
                temp += tp[i];
            }
            tempVector.push_back(stoi(temp));
            myList.push_back(tempVector);
        }
        newfile.close();
    }

    // right adjacent
    int temp = 1;
    for (int i = 0; i < myList.size(); i++)
    {
        for (int j = 0; j < myList[0].size() - 3; j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i][j + k];
                if (temp > result)
                    result = temp;
            }
        }
    }

    // left adjacent
    temp = 1;
    for (int i = 0; i < myList.size(); i++)
    {
        for (int j = 3; j < myList[0].size(); j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i][j - k];
                if (temp > result)
                    result = temp;
            }
        }
    }

    // up adjacent
    temp = 1;
    for (int i = 3; i < myList.size(); i++)
    {
        for (int j = 0; j < myList[0].size(); j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i - k][j];
                if (temp > result)
                    result = temp;
            }
        }
    }

    // down adjacent
    temp = 1;
    for (int i = 0; i < myList.size() - 3; i++)
    {
        for (int j = 0; j < myList[0].size(); j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i + k][j];
                if (temp > result)
                    result = temp;
            }
        }
    }

    // diagonal right adjacent
    temp = 1;
    for (int i = 0; i < myList.size() - 3; i++)
    {
        for (int j = 0; j < myList[0].size() - 3; j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i + k][j + k];
                if (temp > result)
                    result = temp;
            }
        }
    }

    // diagonal left adjacent
    temp = 1;
    for (int i = 0; i < myList.size() - 3; i++)
    {
        for (int j = 3; j < myList[0].size(); j++)
        {
            temp = 1;
            for (int k = 0; k < 4; k++)
            {
                temp *= myList[i + k][j - k];
                if (temp > result)
                    result = temp;
            }
        }
    }
    cout << result;
}