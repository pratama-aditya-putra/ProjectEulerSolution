#include <bits/stdc++.h>
#include <math.h>
#define MAX 100

using namespace  std;

int main(){
	int temp, repeated = 0;
	int maxExponent = 6;
	vector<int> exponent(MAX*maxExponent + 1);
	
	for(int i=1; i <= maxExponent; i++)
		for(int j=1; j <= MAX; j++)
			if(exponent[i*j] == 0)
				exponent[i*j] = i;
	
	vector<int> base((MAX + 1), 0);
	for(int i=2; i <= MAX; i++){
		if(base[i] == 0){
			for(int j = 1; pow(i,j) <= MAX; j++)
				if(base[pow(i,j)] == 0)
					base[pow(i,j)] = i;	
			
			continue;
		}
		
		temp = log(i) / log(base[i]);
		//repeated += count(exponent.begin(), exponent.end(), temp);
		for(int j = 2; j <= MAX ; j++){
			if(exponent[temp * j] < temp)
				repeated++;
		}
	}
	
	cout << (99 * 99) - repeated;
	/*for(int i = 0; i <= exponent.size(); i++)
		cout << exponent[i] << " ";*/
}
