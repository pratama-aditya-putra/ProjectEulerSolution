#include <bits/stdc++.h>
using namespace std;
vector<int> abundantList;

bool isAbundantSum(int x){
	int temp;
	for (vector<int>::iterator i = abundantList.begin(); i!=abundantList.end(); i++) {
		if(*i > x/2){
			return false;
		}
		temp = x - *i;
		if(count(abundantList.begin(), abundantList.end(), temp) == 0)
			continue;
		return true;
	}
}

int main(){
	long int sum = 0;
	long int temp, k=0;
	for(int i=2;i<28123;i++){
		temp = 0;
		for(int j=1;j<=(i/2);j++){
			if(i%j == 0){
				temp+=j;
			}
		}
		if(temp > i)
			abundantList.push_back(i);
	}
	
	temp = 0;
	for(int i=1;i<28124;i++){
		if(isAbundantSum(i) == false)
			sum += i;
	}
	cout << sum;
	
}
