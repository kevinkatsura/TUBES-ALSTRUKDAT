#include <stdio.h>
#include "readWahana.h"

Kata namaW[max];
Kata hargaW[max];
Kata kapasitasW[max];
Kata durasiW[max];
Kata deskripsiW[max];
Kata kayuW[max];
Kata batuW[max];
Kata pasirW[max];
Kata besiW[max];
Kata semenW[max];


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
			kayuW[i]=CKata;
			ADV();
			SalinKata();
			batuW[i]=CKata;
			ADV();
			SalinKata();
			pasirW[i]=CKata;
			ADV();
			SalinKata();
			besiW[i]=CKata;
			ADV();
			SalinKata();
			semenW[i]=CKata;
		}
		if (CC!=MARK)
			ADV();
			i++;
	}
} 	
