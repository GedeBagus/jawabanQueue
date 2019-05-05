/*	
	Nama program	: Soal 2
	Nama			: M. Risqullah Sudanta G. , Gede Bagus Darmagita
	NPM				: 140810180066 , 140810180068
	Tanggal buat	: 4 Mei 2019
    Deskripai       : Mengatur Prioritas duduk
*/
#include <iostream>
#include <conio.h>
using namespace std;

struct ElemenQueue{
	int prior;
	char nama[100];
	ElemenQueue* next;
	ElemenQueue* prev;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue{
	List Head;
	List Tail;
};
Queue Q;

void createQueue(Queue &Q){
	Q.Head = NULL;
	Q.Tail = NULL;
}

void createElement(pointer& pBaru){
	pBaru = new ElemenQueue;
	cout<<"Nama : "; cin.ignore(); cin.getline(pBaru->nama, 50);
	cout<<"Umur : "; cin>>pBaru->prior;
	pBaru->next = NULL;
	pBaru->prev = NULL;
}

void insertLastQueue(Queue& Q, pointer pBaru){
	if(Q.Head==NULL && Q.Tail==NULL){		//kosong
		Q.Head = pBaru;
		Q.Tail = pBaru;
	}
	else{									//berisi
		Q.Tail->next = pBaru;
		Q.Tail = pBaru;		
	}
}

void insertFirstQueue(Queue& Q, pointer pBaru){
	
	if(Q.Head==NULL && Q.Tail==NULL){		//kosong
		Q.Head = pBaru;
		Q.Tail = pBaru;
	}
	else{									//berisi
		pBaru->next = Q.Head;
		Q.Head->prev = pBaru;
		Q.Head = pBaru;		
	}
}

void insertBeforeQueue(Queue &Q, pointer pBaru, pointer pBantu){
	pBantu = Q.Head;
	while (pBantu->prior > pBaru->prior){
		pBantu=pBantu->next;
	}
	pBaru->next=pBantu;
	pBantu->prev->next=pBaru;
	pBaru->prev=pBantu->prev;
	pBantu->prev=pBaru;
}

void deleteQueue(Queue& Q, pointer& pHapus){
	cout<<"Menghapus Data"<<endl;
	if(Q.Head==NULL && Q.Tail==NULL){		//kasus kosong
		pHapus = NULL;
		cout<<"List kosong"<<endl;
	}
	else if(Q.Head->next==NULL){			//kasus 1 elemen
		pHapus = Q.Head;
		Q.Head = NULL;
		Q.Tail = NULL;
	}
	else{									//kasus > 1 elemen
		pHapus = Q.Head;
		Q.Head = Q.Head->next;
		Q.Head->prev = NULL;
		pHapus->next = NULL;
	}
}

void inputQueue(Queue &Q, pointer &pBaru, pointer pBantu){
	createElement(pBaru);
	if(Q.Head == NULL){
		Q.Head = pBaru;
		Q.Tail = pBaru;
	}
else if(pBaru->prior < Q.Tail->prior || pBaru->prior == Q.Tail->prior){
		insertLastQueue(Q, pBaru);
	}  
	else if(pBaru->prior > Q.Head->prior){
		insertFirstQueue(Q, pBaru);
	}
	else insertBeforeQueue(Q, pBaru, pBantu);
}

void traversal(Queue Q){
	pointer pBantu;
	cout<<"Prioritas Duduk (Diurutkan dari atas)"<<endl<<endl;
	cout<<"Umur\t\tNama"<<endl;
	cout<<"---------------------------------------------"<<endl;
	if (Q.Head == NULL && Q.Tail == NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		pBantu=Q.Head; 
		do{
			cout<<pBantu->prior<<"\t\t\t"<<pBantu->nama<<endl;
			pBantu = pBantu->next;
		}while(pBantu != NULL); 	}
}

int main(){
	int n, pilih;
	char jawab;
	pointer p, pBantu;
	createQueue(Q);
	do{
		system("cls");
		cout<<"BUS BAGUS\n";
		cout<<"1. Masukkan Data"<<endl;
		cout<<"2. Hapus Data Prioritas Pertama"<<endl;
		cout<<"3. Show Data"<<endl<<endl;
		cout<<"Pilihan : "; cin>>pilih;
		switch(pilih){
			case 1 : 
				system("cls");
				cout<<"Banyak Penumpang : "; cin>>n;
				for (int i = 0; i<n ; i++){
					cout<<"Input Data Penumpang ke-"<<i+1<<endl;
					inputQueue(Q, p, pBantu);
				}
				cout<<endl<<endl;
				traversal(Q);

				break;
			case 2 :
				system("cls");
				
				cout<<"\t\tData Awal"<<endl;
				cout<<"=========================================="<<endl<<endl;
				traversal(Q);
				
				deleteQueue(Q, p);
				
				cout<<"\n\t\tData Akhir"<<endl;
				cout<<"=========================================="<<endl<<endl;
				traversal(Q);
				break;
				
			case 3 :
				system("cls");
				
				traversal(Q);
				break;
		};
		cout<<endl<<endl;	
		cout<<"Kembali ke menu ? (Y/N) : "; cin>>jawab;	
	}
	while (jawab=='Y' || jawab=='y');
	cout<<"Selesai";
	getch();
}
