#include <stdio.h>
#include "mesin/mesinkata.c"

int main(){
	int nData=1;
	START("../test/wahana.txt");
	while (!EOP){
		if (CC==NEWLINE)
			nData++;
		ADV();
	} 
	
	Kata namaW[nData];
	Kata hargaW[nData];
	Kata kapasitasW[nData];
	Kata durasiW[nData];
	Kata deskripsiW[nData];
	Kata kayu[nData];
	Kata batu[nData];
	Kata pasir[nData];
	Kata besi[nData];
	Kata semen[nData];
	
	int i=0;
	START("../test/wahana.txt");
	while(CC!=MARK){
		while ((CC!=NEWLINE) && (CC!=MARK)){
			SalinKata();
			namaW[i]=CKata;
			ADV();
			SalinKata();
			hargaW[i]=CKata;
			ADV();
			SalinKata();
			kapasitasW[i]=CKata;
			ADV();
			SalinKata();
			durasiW[i]=CKata;
			ADV();
			SalinKata();
			deskripsiW[i]=CKata;
			ADV();
			SalinKata();
			kayu[i]=CKata;
			ADV();
			SalinKata();
			batu[i]=CKata;
			ADV();
			SalinKata();
			pasir[i]=CKata;
			ADV();
			SalinKata();
			besi[i]=CKata;
			ADV();
			SalinKata();
			semen[i]=CKata;
		}
		if (CC!=MARK)
			ADV();
			i++;
	}
	/*Contoh penggunaan*/
	int j;
	for (j=0;j<nData;j++){
		PrintKata(besi[j]);
	} 
}

