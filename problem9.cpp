#include <iostream>
#include <math.h>
using namespace std;

int main(){
	float i, j, n=0;
	for(i=1;i<5000;i++){
		for(j=1;j<10000;j++){
			n = sqrt((i*i)+(j*j));
			if((n-round(n)) == 0){
				if(i+j+n == 1000)
					break;
			}
		}
	}
}
