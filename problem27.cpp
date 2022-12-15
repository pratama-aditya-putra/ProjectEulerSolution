#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

float equation(int a, int b){
	float x;
	x = float(a)/2;
	return x*x - a*x + b;
}

int main(){
	float temp = 1.5;
	bool flag;
	int i = 3;
	vector<int> primeList;
	while(i < MAX){
		flag = 1;
		for(int j=2;j<i;j++){
			if(i%j == 0) flag = 0;
		}
		if(flag == 1){
			primeList.push_back(i);
		}
		i++;
	}
	int j = 0;
	for(i=0;i<primeList.size();i++){
		if(j >= 166) break;
		do{
				
				if(j < 166) j++;
				else break;
		}while(equation(primeList.at(i), primeList.at(j)) != 40.75);
		cout << primeList.at(i) << " " << primeList.at(j) << " " << -1 * primeList.at(j) * primeList.at(i) << endl;
	}
}
