#include <stdio.h>

int main(){
	long long i,product,j,maks=0;
	for(i=1;i<=1000000;i++){
		j=0;
		product=i;
		if(i%2==0)
			continue;
		while(product!=1){
			if(product%2==0){
				product/=2;
				j++;
			}
			else if(product%2==1){
				product=product*3+1;
				j++;
			}
		}
		if(j>maks){
			maks=j;
			printf("%d \n",i);
		}
	}
}
