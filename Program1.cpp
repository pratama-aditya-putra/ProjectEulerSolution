/*Program ini adalah program untuk menghitung jumlah
belanja*/
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
using namespace std;

void line(){//fungsi untuk membuat garis lurus
	int i;	
	for(i=1;i<=40;i++)
		putchar('=');
	putchar('\n');
}

int main(){
	restart://label untuk lompat ke awal
	int i,n;
	string name[20];
	int qty[20],payment[20];
	long int sum=0,price;
	char confirm;//deklarasi variabel
	system("cls");
	line();
	puts("===    Welcome to Cashier Program    ===");
	line();
	cout << "Enter the number of items = "; cin >> n;
	line();
	for(i=1;i<=n;i++){
	/*Perulangan yang dibuat sebanyak n kali untuk memasukka
	data belanja dari seorang user*/
		cin.ignore();//agar syntax get line tidak terlompati
		cout << "Product name = "; getline(cin,name[i]);
		cout << "Quantity     = "; cin >> qty[i];
		cout << "Price        = "; cin >> price;
		payment[i]=qty[i]*price;
		//payment=harga yang harus dibayar pada setiap item
		sum+=payment[i];//operasi untuk menghitung jumlah total belanja
		line();
	}
	system("cls");line();
	//proses output dari array string dan integer 
	//berdasarkan masukkan user
	puts("===            666 Mart              ===");line();	
	puts("Product name       | Qty | Payment        ");line();
	for(i=1;i<=n;i++){
		cout << setiosflags(ios::left) << setw(20) << name[i];
		cout << setiosflags(ios::left) << setw(7) << qty[i];
		cout << setiosflags(ios::left) << setw(15) << payment[i] << endl;
	}
	cout << setiosflags(ios::right) << setw(41) << "=====================\n";
	cout << setiosflags(ios::right) << setw(27) << "Total  ";
	cout << setiosflags(ios::left) << setw(4) << sum << endl;
	cout << resetiosflags(ios::right);
	line();
	puts("=============================");
	puts("| Would you like to repeat? |");
	puts("=============================");
	puts("|  Enter(yes)  |   Esc(no)  |");
	puts("=============================");
	while((confirm!=27)||(confirm!=13)){
	//sebuah perulangan yang dipakai untuk memastikan
	//apakah user ingin keluar atau mengulang
		confirm=getch();
		if(confirm==13) {
			goto restart;
		}
		else if(confirm==27) return 0;
	}
}
