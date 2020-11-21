#include "perintah.h"
void ObjectSurroundList(List L,char*A[]){
    int i = 0;
    if (Info(Current(L),Ordinat(L)+1,Absis(L))=='W' || Info(Current(L),Ordinat(L)+1,Absis(L))=='A' ||Info(Current(L),Ordinat(L)+1,Absis(L))=='O')
    {
        *A[i] = Info(Current(L),Ordinat(L)+1,Absis(L));
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L),Absis(L)+1)=='W'||Info(Current(L),Ordinat(L),Absis(L)+1)=='A'||Info(Current(L),Ordinat(L),Absis(L)+1)=='O')
    {
        *A[i] = Info(Current(L),Ordinat(L),Absis(L)+1);
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L)-1,Absis(L))=='W'||Info(Current(L),Ordinat(L)-1,Absis(L))=='A'||Info(Current(L),Ordinat(L)-1,Absis(L))=='O')
    {
        *A[i] = Info(Current(L),Ordinat(L)-1,Absis(L));
        i+=1;
    }
    else if (Info(Current(L),Ordinat(L),Absis(L)-1)=='W'||Info(Current(L),Ordinat(L),Absis(L)-1)=='A'||Info(Current(L),Ordinat(L),Absis(L)-1)=='O')
    {)
    {
        *A[i] = Info(Current(L),Ordinat(L),Absis(L)-1) ;
    }
}