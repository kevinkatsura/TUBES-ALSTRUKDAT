/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../boolean.h"
#include "../point/point.h"
#include "../mesin/mesinkar.h"

#define NBmax 100
#define NKmax 100

typedef int indeks; /* indeks baris, kolom */
typedef struct {
	point lokasi; /*koordinat lokasi dari sel matriks*/
	char info; /*info dari lokasi*/
} ElType; 

typedef struct{ 
	ElType Mem[NBmax][NKmax];
	int NBrs; /*jumlah baris efektif*/
	int NKol; /*jumlah kolom efektif*/
} MATRIKS;



/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */       
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (MATRIKS *M, char *file); 
/* Memasukkan tiap karakter dalam file ke dalam matriks M */
/* I.S. NBrs dan NKol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define Lokasi(M,i,j) (M).Mem[(i)][(j)].lokasi
#define Info(M,i,j) (M).Mem[(i)][(j)].info
#define NBrs(M) (M).NBrs
#define NKol(M) (M).NKol

/* ********** KELOMPOK BACA/TULIS ********** */ 
void TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10 */

#endif
