#include "perintah.h"
void ObjectSurroundList(Bangunan B, List L,char*A[]){
    int i = 0;
    if (Info(Current(L),Ordinat(L)+1,Absis(L))=='W' || Info(Current(L),Ordinat(L)+1,Absis(L))=='A' ||Info(Current(L),Ordinat(L)+1,Absis(L))=='O')
    {
        if(Info(Current(L),Ordinat(L)+1,Absis(L))== 'W' ){
            while (AbsisBangunan(B)!= Absis(L) && OrdinatBangunan(B) != Ordinat(L)+1)
            {
                B = NextBangunan(B);
            }
            *A[i] = namaWahana(B);
        }
        else
        {
            *A[i] = Info(Current(L),Ordinat(L)+1,Absis(L));
        }
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L),Absis(L)+1)=='W'||Info(Current(L),Ordinat(L),Absis(L)+1)=='A'||Info(Current(L),Ordinat(L),Absis(L)+1)=='O')
    {
        if(Info(Current(L),Ordinat(L),Absis(L)+1)== 'W' ){
            while (AbsisBangunan(B)!= Absis(L)+1 && OrdinatBangunan(B) != Ordinat(L))
            {
                B = NextBangunan(B);
            }
            *A[i] = namaWahana(B);
        }
        else
        {
            *A[i] = Info(Current(L),Ordinat(L),Absis(L)+1);
        }
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L)-1,Absis(L))=='W'||Info(Current(L),Ordinat(L)-1,Absis(L))=='A'||Info(Current(L),Ordinat(L)-1,Absis(L))=='O')
    {
        if(Info(Current(L),Ordinat(L)-1,Absis(L))== 'W' ){
            while (AbsisBangunan(B)!= Absis(L) && OrdinatBangunan(B) != Ordinat(L)-1)
            {
                B = NextBangunan(B);
            }
            *A[i] = namaWahana(B);
        }
        else
        {
            *A[i] = Info(Current(L),Ordinat(L)-1,Absis(L));
        }
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L),Absis(L)-1)=='W'||Info(Current(L),Ordinat(L),Absis(L)-1)=='A'||Info(Current(L),Ordinat(L),Absis(L)-1)=='O')
    {
    {
        if(Info(Current(L),Ordinat(L),Absis(L)-1)== 'W' ){
            while (AbsisBangunan(B)!= Absis(L)-1 && OrdinatBangunan(B) != Ordinat(L))
            {
                B = NextBangunan(B);
            }
            *A[i] = namaWahana(B);
        }
        else
        {
            *A[i] = Info(Current(L),Ordinat(L),Absis(L)-1);
        }
        i+=1;
    }
}