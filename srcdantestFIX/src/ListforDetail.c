#include "ListforDetail.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyB (ListB L)
/* Mengirim true jika list kosong */
{
    return (FirstB(L) == NilW) ;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyB (ListB *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FirstB(*L) = NilW ;
}

/****************** Manajemen Memori ******************/
addressB AlokasiB (Kata X,point y)

{
    addressB P = (addressB) malloc (sizeof(Bangunan));
    if (P != NilW)
    {
        Absis(KordinatB(P)) = Absis(y);
        Ordinat(KordinatB(P)) = Ordinat(y);
        namaWahana(P) = X ;
        NextBangunan(P) = NilW ;
    }
    return P;
}
void DealokasiB (addressB *P)

{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressB SearchKataB (ListB L, Kata X)

{
    addressB P = FirstB(L) ;
    while (P != NilW && !IsKataSama(namaWahana(P),X))
    {
        P = NextBangunan(P);
    }
    return P ;
}
addressB SearchTitikB (ListB L,int x, int y){
    addressB P = FirstB(L);
    while (P != NilW && x != Absis(KordinatB(P)) && Ordinat(KordinatB(P))!= y)
    {
        P = NextBangunan(P);
    }
    return P ;
}

void InsVLastB (ListB *L, Kata X, point Y)
{
    addressB newnode = AlokasiB(X,Y);
    if (IsEmptyB(*L))
    {
        FirstB(*L) = newnode ;

    } else
    {
        addressB P = FirstB(*L);
        while (NextBangunan(P)!=NilW)
        {
            P = NextBangunan(P);
        }
        NextBangunan(P) = newnode; 
    }
    NextBangunan(newnode) = NilW;
}