#include <stdio.h>
#include "readWahana.h"

Kata namaW[max];
Kata hargaW[max];
Kata kapasitasW[max];
Kata durasiW[max];
Kata deskripsiW[max];
Kata kayu[max];
Kata batu[max];
Kata pasir[max];
Kata besi[max];
Kata semen[max];


void ekstrakWahana(int *nData){
	int n=0;
	START("../test/wahana.txt");
	while (!EOP){
	if (CC==NEWLINE)
		n++;
	ADV();
	*nData=n+1;
	}
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
} 	
