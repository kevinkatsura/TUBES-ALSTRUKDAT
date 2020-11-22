/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS2_H
#define MATRIKS2_H

#include "../boolean.h"
#include "../mesin/mesinkata.c"

#define NBmax 100
#define NKmax 100

typedef int indeks; /* indeks baris, kolom */
typedef Kata ElType;
/*typedef struct {
	Kata isi; /*isi dari matriks di indeks yang dimaksud
} ElType; */

typedef struct { 
	ElType Mem[NBmax][NKmax];
	int NBrs; /*jumlah baris efektif*/
	int NKol; /*jumlah kolom efektif*/
} MATRIKS;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */       
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS2 (MATRIKS2 *M, char *file); 
/* Memasukkan tiap karakter dalam file ke dalam matriks M */
/* I.S. NBrs dan NKol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
#define NBrs2(M) (M).NBrs
#define NKol2(M) (M).NKol

/* ********** KELOMPOK BACA/TULIS ********** */ 
void TulisMATRIKS2 (MATRIKS2 M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10 */

#endif
