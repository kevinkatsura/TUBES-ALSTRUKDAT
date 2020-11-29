#include "ListforDetail.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyB (ListB L)
/* Mengirim true jika list kosong */
{
    return (FirstB(L) == Nil) ;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyB (ListB *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FirstB(*L) = Nil ;
}

/****************** Manajemen Memori ******************/
addressB AlokasiB (Kata X,point y)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressB P = (addressB) malloc (sizeof(Bangunan));
    if (P != Nil)
    {
        Absis(KordinatB(P)) = Absis(y);
        Ordinat(KordinatB(P)) = Ordinat(y);
        namaWahana(P) = X ;
        NextBangunan(P) = Nil ;
    }
    return P;
}
void DealokasiB (addressB *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressB SearchKataB (ListB L, Kata X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressB P = FirstB(L) ;
    while (P != Nil && !IsKataSama(namaWahana(P),X))
    {
        P = NextBangunan(P);
    }
    return P ;
}
addressB SearchTitikB (ListB L,int x, int y){
    addressB P = FirstB(L);
    while (P != Nil && x != Absis(KordinatB(P)) && Ordinat(KordinatB(P))!= y)
    {
        P = NextBangunan(P);
    }
    return P ;
}

void InsVLastB (ListB *L, Kata X, point Y)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressB P = FirstB(*L);
    addressB newnode = AlokasiB(X,Y) ;
    while (NextBangunan(P) != Nil)
    {
        P = NextBangunan(P);
    }
    if (IsEmptyB(*L))
    {
        FirstB(*L) = newnode ;
    }
    else
    {
        NextBangunan(P) = newnode;
    }
    NextBangunan(newnode) =  Nil ;
}