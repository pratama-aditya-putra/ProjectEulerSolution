#include <iostream>
#include <math.h>
using namespace std;

int main(){
int a = 1;
int bil = 0;
int faktor, bilFaktor;
bool stat = false;
while (!stat) {
     bil = bil+a;
     a++;
     faktor = 0;
     bilFaktor = 1;
     while (bilFaktor <= sqrt(bil)) {
           if (bil%bilFaktor == 0) {
                if (sqrt(bil) == bilFaktor) {
                     faktor++;
                } else {
                     faktor = faktor+2;
                }
           }
           bilFaktor++;
      }
      stat = (faktor > 500);
	}
	cout << bil;
}
