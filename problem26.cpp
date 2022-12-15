#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, position, ans = 0, max = 0, sequenceLength=0;
	int i;
	for(i=1000;i>970;i--){
		if(max >= i)
			break;
		
		x = 1;
		position = 1;
		int remainder[i+1];
		 
		for(int j=0;j<i+1;j++) remainder[j] = 0;
		//cout << i << " - ";
		while((x != 0) && (remainder[x] == 0)){
			remainder[x] = position;
			//cout << x << " "; 
			x *= 10;
			x %= i;
			position++;
		}
		//cout << endl;
		if(position - remainder[x] > max){
			max = position - remainder[x];
		}
	}
	cout << ++i;
}
