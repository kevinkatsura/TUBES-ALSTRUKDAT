/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#ifndef listdp_H
#define listdp_H

#include "../boolean.h"
#include "../matriks/matriks.h"
#define NilL NULL

/* Definisi Type Data */
typedef struct MAP *addressM;
typedef struct MAP
{
    addressM prev;
    MATRIKS matriks;
    addressM next;
}tMAP;
typedef struct {
    point Kordinat;
    int Nomor;
    addressM Current;
} List;


/* Definisi list : */
/* List kosong : First(L) = NilL dan Last(L) = NilL */
/* Setiap elemen dengan addressM P dapat diacu Info(P), Next(P), Prev(P) */
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
boolean IsEmptyLMap (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */
/****************** Manajemen Memori ******************/
addressM AlokMap (MATRIKS M);
/* Mengirimkan addressM hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressM tidak NilL. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilL, Prev(P)=NilL */
/* Jika alokasi gagal, mengirimkan NilL. */

void DealokMap (addressM P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressM P */

void InsVLast (List *L, MATRIKS X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


#endif