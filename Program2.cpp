//program ini adalah program untuk menginputkan biodata
//dan mengeluarkannya pada output layar
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(){
	restart: //label yang digunakan untuk melompat ke awal
	system("cls"); // perintah untuk membersihan layar
	char nama[35],ttl[35],kelamin,alamat[35],confirm;
	string gender; // deklarasi variabel yang akan digunakan
	cout << "                 Program  Memasukkan Biodata\n";
	cout << "============================================================\n";
	cout << "Masukkan nama anda                 : "; gets(nama); 
	//penggunaan perintah gets agar bisa memasukkan nilai ke variabel nama
	cout << "Masukkan tempat tanggal lahir anda : "; gets(ttl);
	cout << "Masukkan jenis kelamin  (W/L)      : ";
	while((kelamin!='L')||(kelamin!='P')){
	/*syarat agar ketika user memasukkan huruf l atau w maka secara 
	otomatis program akan mengeluarkan wanita jika inputan w dan
	laki-laki apabila inputan l*/
		kelamin=getche();				 
		kelamin=toupper(kelamin);		
		if(kelamin=='L') {
			cout << "(Laki-laki)\n"; gender="Laki-Laki"; break;
		}
		else if (kelamin=='W') {
			cout << "(Wanita)\n"; gender="Wanita"; break;
		}
	}
	cout << "Masukkan alamat anda               : "; gets(alamat);
	system("cls");
	cout << "                     Biodata\n";
	cout << "======================================================\n";
	//bagian untuk mengeluarkan hasil dari inputan
	cout << "Nama                  : " << nama << endl;
	cout << "Tempat, Tanggal Lahir : " << ttl << endl;
	cout << "Jenis kelamin         : " << gender << endl;
	cout << "Alamat                : " << alamat << endl;
	cout << "======================================================\n";
	cout << "Ingin Mengulang? (Y/N)" << endl;
	input://label yang digunakan untuk melompat kembali ke proses input
	confirm=getchar();//perintah untuk menginputkan karakter
	confirm=toupper(confirm);
	//perintah untuk membuat inputtan menjadi huruf besar
	if(confirm=='Y') goto restart;
	//jika inputan = 'Y' maka akan lompat ke label restart awal
	else if (confirm=='N') return 0;
	//jika inputan = 'N' maka program akan berhenti
	else goto input;
	//jika inputan tidak dari kedua kemungkinan di atas maka akan kembali ke label input
	system("pause");
	return 0;
}
