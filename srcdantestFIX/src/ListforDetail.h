#include "mesin/mesinkata.h"
#include "point/point.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef bangunan_H
#define bangunan_H

#define NilW NULL

/*          ADT BANGUNAN        */
// Sebagai wadah penyimpanan posisi wahana berdasarkan nama masing masing wahana
typedef struct DaftarLetakBangunan * addressB;
typedef struct DaftarLetakBangunan{
    point p ;
    Kata namaWahana;
    addressB Next;
} Bangunan;

typedef struct {            //Bentuk List Linier
	addressB First;
} ListB;
//Konstruktor untuk ADT Bangunan
#define KordinatB(L) (L)->p
#define namaWahana(L) (L)->namaWahana
#define NextBangunan(L) (L)->Next
#define FirstB(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyB (ListB L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyB (ListB *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressB AlokasiB (Kata X,point y);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiB (addressB *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressB SearchKataB (ListB L, Kata X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
addressB SearchTitikB (ListB L, int kolom , int baris);

void InsVLastB (ListB *L, Kata X, point P);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */




/*          detailArray         */
//Sebagai Array penampung untuk mengetahui daftar wahana yang ada di sekeliling player
typedef struct {
    Kata A[4];
    int Nbelmt ;
} detailArray;
//Konstruktor untuk ADT detailArray
#define Array(L,i) L->A[i]
#define NbElmtB(L) L->Nbelmt
#define ArrayNP(L,i) L.A[i]
#define NbElmtBNP(L) L.Nbelmt


#endif