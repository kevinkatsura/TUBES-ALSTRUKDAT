/*
    Nama        : Kevin Katsura Dani Sitanggang
    NIM         : 13519216
    Topik       : list double pointer
*/


#include "listdp.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(Last(*L))= P ;
        Prev(P) = Last(*L);
        Next(P) = Nil;
        Last(*L) = P ;
    }
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if (Prec == Last(*L))
    {
        Last(*L) = P;
        Next(Prec) = Last(*L);
        Next(Last(*L)) =Nil;
        Prev(Last(*L)) = Prec;
    }
    else{
        Next(P) = Next(Prec);
        Next(Prec) = P ;
        Prev(P) = Prec ;
        Prev(Next(P)) = P ;
    }
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    if (Succ == First(*L))
    {
        First(*L) = P;
        Prev(P) = Nil;
        Next(P) = Succ ;
        Prev(Succ) = First(*L);
    }
    else{
        Prev(P) = Prev(Succ) ;
        Prev(Succ) = P ;
        Next(Prev(P)) = P ;
        Next(P) = Succ ;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L) ;
    if(First(*L)==Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        address new = First(*L);
        First(*L) = Next(First(*L));
        Next(new) = Nil;
        Prev(First(*L)) = Nil;
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    *P = Last(*L) ;
    if(First(*L)==Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else{
        address new = Last(*L) ;
        Last(*L) = Prev(new) ;
        Next(Last(*L)) = Nil ;
        Prev(new) = Nil;
    }
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L,X);
    if (P != Nil)
    {
        if (P == First(*L))
        {
            First(*L) = Next(P);
            if (P == Last(*L))
            {
                Last(*L)= Nil ;
            }
            else
            {
                Next(P) = Nil;
                Prev(First(*L)) = Nil;
            }
        }
        else
        {
            if (Last(*L)==P)
            {
                Last(*L) = Prev(P);
                Next(Last(*L)) = Nil;
                Prev(P) = Nil ;
            }
            else
            {
                Next(Prev(P)) = Next(P);
                Prev(Next(P)) = Prev(P);
                Prev(P) = Nil ;
                Next(P) = Nil ;
            } 
        }
        Dealokasi(P);  
    } 
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    address P1 = Next(Prec);
    *Pdel = P1;
    if (P1 == Last(*L))
    {
        Prev(P1) = Nil;
        Next(Prec) = Nil;
        Last(*L) = Prec ;
    }
    else
    {
        address P2 = Next(P1) ;
        Prev(P2) = Prec ;
        Next(P1) =Nil ;
        Prev(P1) = Nil;
        Next(Prec) = P2;
    }
   
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    address P1 = Prev(Succ);
    *Pdel = P1 ;
    if (P1 == First(*L))
    {
        Prev(Succ) = Nil;
        Next(P1) = Nil;
        First(*L) = Succ;
    }
    else
    {
        address P2 = Prev(P1);
        Next(P2) = Succ;
        Prev(P1) = Nil;
        Next(P1) = Nil ;
        Prev(Succ) = P2;
    }
    
    
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address x = First(L) ;
    printf("[") ;
    if (IsEmpty(L))
    {
        printf("]");
    }
    else{
        while (Next(x)!=Nil)
        {
            printf("%d,",Info(x)) ;
            x = Next(x) ;
        }
        printf("%d]", Info(x)) ;
    }
}
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address x = Last(L) ;
    printf("[") ;
    if (IsEmpty(L))
    {
        printf("]");
    }
    else{
        while (Prev(x)!=Nil)
        {
            printf("%d,",Info(x)) ;
            x = Prev(x) ;
        }
        printf("%d]", Info(x)) ;
    }
}
