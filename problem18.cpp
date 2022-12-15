#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
static int temp[17000][20];
static int hasil[17000][20];

int main(){
	int n,j,k,a ,i,z;
	int array[15][15]={
	{75},
{95, 64},
{17, 47, 82},
{18, 35, 87, 10},
{20, 04, 82, 47, 65},
{19, 01, 23, 75, 03, 34},
{88, 02, 77, 73, 07, 63, 67},
{99, 65, 04, 28, 06, 16, 70, 92},
{41, 41, 26, 56, 83, 40, 80, 70, 33},
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
{04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
	};
	temp[0][0]=1;
	for(i=2;i<=15;i++){
		for(j=0;j<pow(2,i-1);j++){
			for(k=0;k<i;k++){
				if(k<i-1){
					if(j%2)
						hasil[j][k]=temp[j/2][k];
					else
						hasil[j][k]=temp[j/2][k];
				}
				else if(k=i-1){
					if(j%2)
						hasil[j][k]=hasil[j][k-1]+1;
					else
						hasil[j][k]=hasil[j][k-1];
				}
			}
			cout << endl;
		}
		for(j=0;j<pow(2,i-1);j++){
			for(k=0;k<i;k++){
				temp[j][k]=hasil[j][k];
			}
		}
	}
	long int sum=0, maks=0;
	for(j=0;j<pow(2,14);j++){
		sum=0;
		for(k=0;k<15;k++){
			sum+=array[k][(hasil[j][k]-1)];
		}
		if(sum>maks)
			maks=sum;
	}
	cout << maks;
}
