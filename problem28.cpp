#include<bits/stdc++.h>
using namespace std;

int main(){
	long int sum = 1, temp;
	for(int i = 3; i <= 1001;i+=2){
		temp = i * i * 4 - (i - 1) * 6;
		sum += temp;
	}
	cout << sum;
}
