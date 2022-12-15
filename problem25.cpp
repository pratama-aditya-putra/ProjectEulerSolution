#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a;
	vector<int> b;
	int temp, temp1, temp2, temp3=0;
	a.push_back(1);
	b.push_back(1);
	int i = 2;
	while(a.size() < 1000){
		temp3 = 0;
		if(a.size() > b.size()) b.push_back(0);
		for(int j=0;j<a.size();j++){
			temp = a.at(j);
			temp1 = a.at(j)+b.at(j) + temp3;
			temp2 = temp1%10;
			temp3 = temp1/10;
			a.at(j)= temp2;
			b.at(j) = temp;
		}
		if(temp3) a.push_back(1);
		i++;
		/*cout << "b = ";
		for(int j=0;j<b.size();j++){
			cout << b.at(j);
		}
		cout << endl;*/
	}
		cout << "a = ";
		for(int j=0;j<a.size();j++){
			cout << a.at(j);
		}
		cout << endl << i << endl;
	/*int x, y, z;
	x = 0;
	y = 1;
	while(z < 1000000){
		z = x + y;
		temp = x;
		x = y;
		y = z;
		cout << z << " ";
	}*/
}
