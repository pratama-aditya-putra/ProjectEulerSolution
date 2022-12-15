#include<bits/stdc++.h>
using namespace std;
int exponent[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

int main(){
	//The Most digit that can be the sum of 9 to the power of 5 is 6 digit
	//9^5 x 5 = 295245
	//9^5 x 6 = 354294
	//9^5 x 7 = 413343
	//as you can see seven digit of 9 ^ 5 can only be the sum of 6 digit number
	//therefore the max digit that can be written as the sum of 9 ^ 5 is 6 digit
	int result = 0;
	int temp, x;
	for(long int i=2; i<=355000; i++){
		int powerSum = 0;
		temp = i;
		while(temp > 0){
			x = temp%10;
			temp = temp/10;
			powerSum += exponent[x];
		}
		if(powerSum == i)
			result += powerSum;
	}
	cout << result;
}
