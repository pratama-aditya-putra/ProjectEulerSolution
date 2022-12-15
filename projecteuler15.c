#include <stdio.h>
#include <math.h>
double fakt(int x){
	if((x==1)||(x==0))
		return 1;
	else
		return x*fakt(x-1);
}

int main(){
	double hasil=0,temp;
	int i=0,n;
	scanf("%d",&n);
	while(i<=n){
		temp=fakt(n)/(fakt(n-i)*fakt(i));
		hasil+=pow(temp,2);
		i++;
	}
	printf("%.0f\n",hasil);
	return 0;
}
