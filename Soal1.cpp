/*	
	Nama program	: Soal 1
	Nama			: M. Risqullah Sudanta G. , Gede Bagus Darmagita
	NPM				: 140810180066 , 140810180068
	Tanggal buat	: 4 Mei 2019
    Deskripai       : Perhitungan Uang Amal dengan Queue
*/

#include<iostream>
using namespace std;

struct ElementQueue{
 	char nama[20];
 	int donasi;
 	ElementQueue* next;
};
typedef ElementQueue* pointer;

struct Queue{
 	pointer head;
	pointer tail;
}Q;

void createElement(pointer& pBaru, int& antrian){
 	pBaru = new ElementQueue; 
 	cout << "Antrian ke-" << antrian << endl;
 	cout << "Nama\t: "; cin >> pBaru->nama;
    cout << "Donasi(Rp)\t: "; cin >> pBaru->donasi;
 	pBaru->next = NULL;
    antrian++;
}

void insertQueue(pointer pBaru){
    if (Q.head == NULL && Q.tail == NULL){
        Q.head = pBaru;
        Q.tail = pBaru;
    }
    else {
        Q.tail->next = pBaru;
        Q.tail = pBaru;
    }
}

void cetakDonasi(pointer pBantu){
    pBantu = Q.head;
    cout << "===========================Pendonasi===========================" << endl;
    do{
        cout << "Nama: " << pBantu->nama << "\t\t|| " << "Donasi: " << pBantu->donasi << endl;
        pBantu = pBantu->next;
    }while (pBantu != NULL);
}

void jumlahDonasi (pointer pBantu, int& total){
    pBantu = Q.head;
    total = 0;
    do{
        total += pBantu->donasi;
        pBantu = pBantu->next;
    }while (pBantu != NULL);
}

int main(){
    pointer posko;
    int antrian = 1, day = 1, pilihan;
    int total = 0, n;

    do{
        system("cls");
        cout << "                   --Posko Donasi--" << endl;
        cout << "Percayalah dengan membantu, kamu akan dimudahkan kehidupannya :)\n" << endl;
        cout << "Hari ke-" << day << endl;
        cout << "Dana yang dibutuhkan : 100000000" << endl;
        cout << "Total uang masuk(Rp): " << total << endl;

        cout << "[1] Input Donasi" << endl;
        cout << "[2] Cetak data donasi" << endl;
        cout << "[3] Selesai" << endl;
        cout << "Masukan Pilihan: "; cin >> pilihan;
        switch(pilihan){
            case 1:
                cout << "Berapa banyak pendonasi hari ini: "; cin >> n;
                for (int i = 0; i < n; i++){
                    createElement(posko, antrian);
                    insertQueue(posko);
                }
                day++;
                jumlahDonasi(posko, total);
                system("PAUSE");
                break;

            case 2:
                cetakDonasi(posko);
                system("PAUSE");
                break;

            case 3:
                int sisa;
                sisa = total - 100000000;
                if (sisa < 0){
                    cout << "Dana belum cukup terkumpul!" << endl;
                    system("PAUSE");
                }
                else{
                    system("cls");
                    cout << "Terimakasih sudah berdonasi!" << endl;
                    cout << "Total uang masuk(Rp): " << total << endl;
                    cout << "Total Uang lebih(Rp): " << sisa << endl;
                    cout << "Jumlah Pendonasi: " << antrian-1 << " orang\n" << endl;
                    cetakDonasi(posko);
                    return(0);
                }
                break;
        }
    }while (pilihan != 0);
}