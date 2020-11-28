
#include "listdp.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (Current( L) == Nil) ;
}

/****************** Manajemen Memori ******************/
address AlokMap (MATRIKS M)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address P = (address) malloc (sizeof(tMAP));
    if (P != Nil) {
        matriks(P) = M;
        Prev(P) = Nil;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    Next(P) = Nil ;
    Prev(P) = Nil ;
    free(P);
}

void InsVLast (List *L, MATRIKS X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address newnode ;
    newnode = AlokMap(X);
    if (newnode != Nil)
    {
        if (IsEmpty(*L))
        {
            Current(*L) = newnode;
            Next(Current(*L)) = Current(*L);
            Prev(Current(*L)) = Current(*L);
        }
        else{
            address P = Current(*L);
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
