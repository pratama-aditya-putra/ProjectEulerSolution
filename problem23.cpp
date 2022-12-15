#include <bits/stdc++.h>
using namespace std;

long int fakt(int x){
	if(x <= 0)
		return 1;
	else
		return x * fakt(x-1);
}

int main(){ 
	vector<int> myStack;
    vector<int>::iterator it;
	long int n = 999999;
	float temp;
	
	for(int i=0;i<10;i++)
		myStack.push_back(i);
	
	int m = myStack.size() - 1;
	for(int i=m; i> 0; i--){
		temp = n/fakt(i);
		temp = ceil(temp);
		cout << myStack.at(temp);
		n = n - fakt(i)*temp;
	    it = myStack.begin() + temp;
	    myStack.erase(it);
	}
	cout << myStack.at(0);
	
}
