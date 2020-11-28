/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../boolean.h"
#include "../matriks/matriks.c"
#define Nil NULL

/* Definisi Type Data */
typedef struct MAP *address;
typedef struct MAP
{
    address prev;
    MATRIKS matriks;
    address next;
}tMAP;
typedef struct {
    point Kordinat;
    int Nomor;
    address Current;
} List;


/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define matriks(P) (P)->matriks
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define Current(L) ((L).Current)
#define Kordinat(L) ((L).Kordinat)
#define Nomor(L) ((L).Nomor)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */
/****************** Manajemen Memori ******************/
address AlokMap (MATRIKS M);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void DealokMap (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void InsVLast (List *L, MATRIKS X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


#endif