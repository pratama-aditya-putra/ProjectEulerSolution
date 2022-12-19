#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

vector<string> generateWordList(string x)
{
    vector<string> result;
    string temp = "";
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == ',')
        {
            result.push_back(temp);
            temp = "";
            continue;
        }
        if (x[i] == '"' || x[i] == ' ')
            continue;
        temp += x[i];
    }
    return result;
}

int wordSum(string x)
{
    int sum = 0;
    for (int i = 0; i < x.length(); i++)
    {
        sum += int(x[i] - 'A' + 1);
    }
    return sum;
}

int main()
{
    int result = 0;
    bool triangleNumber[1001];

    memset(triangleNumber, false, sizeof(triangleNumber));

    int temp = 0;
    for (int i = 1;; i++)
    {
        temp = 0.5 * i * (i + 1);
        if (temp > 1000)
            break;
        triangleNumber[temp] = true;
    }

    fstream newfile;
    string stringInput = "";
    newfile.open("p042_words.txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            stringInput += tp;
        }
        newfile.close();
    }

    vector<string> wordList = generateWordList(stringInput);

    for (int i = 0; i < wordList.size(); i++)
    {
        if (triangleNumber[wordSum(wordList[i])])
            result++;
    }
    cout << result;
}