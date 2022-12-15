#include<bits/stdc++.h>
using namespace std;
int exponent[10] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};
vector<bool> track(295246, 0);

bool compare(vector<int> vect,long int sum){
	vector<int> vect2;
	for(int i=0;i<5;i++){
		vect2.push_back(sum%10);
		sum = sum/10;
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<vect.size();j++){
			if(vect[j] == vect2[i]){
				vect.erase(vect.begin() + j);
				break;
			} 
		}
	}
	if(vect.empty()) return true;
	return false;
}

int main(){
	long int answer=0;
	vector<int> myVector;
	for(int i=0;i<5;i++) myVector.push_back(0);
	int n, temp, flag;
	long int sum = 0;
	do{
		temp = 1;
		n = 4;
		sum = 0;
		flag = 0;
		do{
			myVector[n] += temp;
			if(myVector[n] > 9){
				temp = 1;
				myVector[n] = 0;
			}
			else temp = 0;
			n--;
		}while((n >= 0) && (temp > 0));
		for(int i=0;i<5;i++)
			sum += exponent[myVector[i]];
		for(int i=0;i<5;i++)
			flag += myVector[i];
		if((sum < 10000) || (sum > 99999) || (track[sum] == 1))  {
			continue;
		}
		else{
			if(compare(myVector, sum) == 1){
				answer += sum;
				cout << sum << " " << compare(myVector, sum) << endl;
				for(int i=0;i<5;i++)
					cout << myVector[i] << " ";
		
			cout << endl;
			}
			track[sum] = 1;
		}
	}while(flag < 45);
	cout << answer;
}
