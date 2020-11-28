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
		}
		if (CC!=MARK)
			ADV();
			i++;
	}
	/*Contoh penggunaan*/
	int j;
	for (j=0;j<nData;j++){
		PrintKata(namaW[j]);
	} 
}

