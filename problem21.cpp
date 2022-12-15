#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){ 
	string names;
	std::ifstream inFile;
    inFile.open("C:/Users/USER/Desktop/p022_names.txt");

    stringstream strStream;
    strStream << inFile.rdbuf();
    names = strStream.str();
    
	vector<string> myStack;
	vector<long int> floatStack;
	long int temp1=0;
	string temp = "";
	for(int i=0; names[i]; i++){
		if(names[i] < 44)
			continue;
		if(names[i] == ',' || int(names[i+1]) == 0){
			myStack.push_back(temp);
			temp = "";
			continue;
		}
		temp += names[i];
	}
	myStack.push_back(temp);
	sort(myStack.begin(), myStack.end());
	for(int i=0; i < myStack.size(); i++){
		temp1 = 0;
		for(int j=0;myStack.at(i)[j]; j++)
			temp1 += int(myStack.at(i)[j]) - 64;
		floatStack.push_back(temp1);
	}
	/*
	for(int i=0;i < myStack.size();i++){
		cout << myStack.at(i) << endl;
		cout << floatStack.at(i) << endl;
	}*/
	temp1 = 0; 
	for(int i=0;i < floatStack.size();i++){
		temp1 += floatStack.at(i) * (i+1);
	}
	cout << setprecision(12) << temp1;
}
