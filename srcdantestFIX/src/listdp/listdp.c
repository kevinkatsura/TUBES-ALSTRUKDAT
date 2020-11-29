
#include "listdp.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

boolean IsEmptyLMap (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (Current( L) == NilL) ;
}

/****************** Manajemen Memori ******************/
addressM AlokMap (MATRIKS M)
/* Mengirimkan addressM hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressM tidak NilL. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilL, Prev(P)=NilL */
/* Jika alokasi gagal, mengirimkan NilL. */
{
    addressM P = (addressM) malloc (sizeof(tMAP));
    if (P != NilL) {
        matriks(P) = M;
        Prev(P) = NilL;
        Next(P) = NilL;
    }
    return P;
}
void DealokasiM (addressM P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressM P */
{
    Next(P) = NilL ;
    Prev(P) = NilL ;
    free(P);
}

void InsVLast (List *L, MATRIKS X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berniLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressM newnode ;
    newnode = AlokMap(X);
    if (newnode != NilL)
    {
        if (IsEmptyLMap(*L))
        {
            Current(*L) = newnode;
            Next(Current(*L)) = Current(*L);
            Prev(Current(*L)) = Current(*L);
        }
        else{
            addressM P = Current(*L);
            while (Next(P)!= Current(*L))
            {
                P = Next(P);
            }
            Prev(Next(P)) = newnode ;
            Next(newnode) = Next(P);
            Next(P) = newnode;
            Prev(newnode) = P;
        }
    }
}
