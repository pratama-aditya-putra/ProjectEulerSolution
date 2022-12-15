#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int j, k, l=1, month[12],hasil=0;
	long long i;
	month[0]=31;
	month[2]=31;
	month[3]=30;
	month[4]=31;
	month[5]=30;
	month[6]=31;
	month[7]=31;
	month[8]=30;
	month[9]=31;
	month[10]=30;
	month[11]=31;
	for(i=190;i<=2000;i++){
		if(i%400==0)
			month[1]=29;
		else if(i%100==0)
			month[i]=28;
		else if(i%4==0)
			month[1]=29;
		else
			month[1]=28;
		cout << i << endl;
		for(j=0;j<=11;j++){
			for(k=1;k<=month[j];k++){
				cout << l++ << " ";
				if(l==7){
					if(k==1)
						hasil++;
					l=0;
				}
			}
			cout << '\n';
		}
	}
	cout << '\n' << hasil;
}
