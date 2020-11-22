#include <stdio.h>
#include "matriks2.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */       
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS2 (MATRIKS2 *M, char *file){
	START(file);
	indeks i=0;
	while (!EOP){
		indeks j=0;
		while (CC!=KOMA && CC!=MARK){
			SalinKata();
			Elmt(*M,i,j)=CKata;
			PrintKata(CKata);
			j++;
			if (CC==NEWLINE)
				ADV();
		}
		NKol2(*M)=j;
		if (CC==KOMA)
			ADV();
		i++;
	}
	NBrs2(*M)=i;*/
}
/* Memasukkan tiap karakter dalam file ke dalam matriks M */
/* I.S. NBrs dan NKol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS2 (MATRIKS2 M){
	indeks i,j;
	for (i=0;i<NBrs2(M);i++){
		for (j=0;j<NKol2(M);j++){
			PrintKata(Elmt(M,i,j));
		}
		if (i!=NBrs2(M)) {
			printf("\n");
		}
	}
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10 */

