#include <iostream>
using namespace std;

int main(){
	int j,i,hasil,bil,divisor,n,k;
	string array[4][10]=
	{
		{"\0","one","two","three","four","five","six","seven","eight","nine"},
		{"\0","eleven","twelve","thirteen","fourteen","fiveteen","sixteen","seventeen","eighteen","nineteen"},
		{"\0","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"},
		{"\0","onehundred","twohundred","threehundred","fourhundred","fivehundred","sixhundred","sevenhundred","eighthundred","ninehundred"},
	};
	cin >> n;
	for(i=1;i<=n;i++){
		bil=i;
		while(bil>0){
			if(bil<10){
				cout << array[0][bil] << " ";
				bil=0;
			}
			else if((bil>10)&&(bil<20)){
				cout << array[1][bil-10] << " ";
				bil=0;
			}
			else if((bil>=20)&&(bil<100)){
				cout << array[2][bil/10] << " ";
				bil=bil-(bil/10)*10;
		 	}
		}
		cout << " = " << i << endl;
	}
}
