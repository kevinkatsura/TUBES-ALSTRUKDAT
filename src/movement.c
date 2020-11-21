#include "matriks/matriks.h"
#include "point/point.h"
#include "listdp/listdp.h"
#include "perintah.h"

void W (List *L){
        if (Info(matriks(Current(*L)),Ordinat(*L)-1,Absis(*L))!='*' && Info(matriks(Current(*L)),Ordinat(*L)-1,Absis(*L))!='A' && Info(matriks(Current(*L)),Ordinat(*L)-1,Absis(*L))!='W')
        {
            Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) == '-';
            if (Info(matriks(Current(*L)),Ordinat(*L)-1,Absis(*L))=='^')
            {
                if (Nomor(*L)==3)
                {
                    Current(*L) = Next(Current(*L));
                    Nomor(*L) = 2;
                }
                else
                {
                    Current(*L) = Prev(Current(*L));
                    Nomor(*L) = 1;
                }
                boolean found = false;
                int i,j;
                i = 0;
                while (!found and i<=9)
                {
                    j = 0;
                    while (!found and j <=19)
                    {
                        if (Info(matriks(Current(*L)),i,j)=='v')
                        {
                            found = true;
                        }
                        else
                        {
                            j+=1;
                        }
                    }
                    i+=1;
                }
                Ordinat(*L) = i-1;
                Absis(*L) = j;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';                
            }
            else
            {
                Ordinat(*L) = Ordinat(*L)-1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';  
            }
        }
}

void A (List *L){
    if (Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)-1)!='*' && Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)-1)!='A' && Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)-1)!='W')
        {
            Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) == '-';
            if (Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)-1)=='<')
            {
                if (Nomor(*L)==4)
                {
                    Current(*L) = Next(Current(*L));
                    Nomor(*L) = 3;
                }
                else
                {
                    Current(*L) = Prev(Current(*L));
                    Nomor(*L) = 2;
                }
                boolean found = false;
                int i,j;
                i = 0;
                while (!found and i<=9)
                {
                    j = 0;
                    while (!found and j <=19)
                    {
                        if (Info(matriks(Current(*L)),i,j)=='>')
                        {
                            found = true;
                        }
                        else
                        {
                            j+=1;
                        }
                    }
                    i+=1;
                }
                Ordinat(*L) = i;
                Absis(*L) = j-1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';                
            }
            else
            {
                Absis(*L) = Absis(*L)-1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';  
            }
        }
}

void S (List *L){
        if (Info(matriks(Current(*L)),Ordinat(*L)+1,Absis(*L))!='*' && Info(matriks(Current(*L)),Ordinat(*L)+1,Absis(*L))!='A' && Info(matriks(Current(*L)),Ordinat(*L)+1,Absis(*L))!='W')
        {
            Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) == '-';
            if (Info(matriks(Current(*L)),Ordinat(*L)+1,Absis(*L))=='v')
            {
                if (Nomor(*L)==1)
                {
                    Current(*L) = Next(Current(*L));
                    Nomor(*L) = 4;
                }
                else
                {
                    Current(*L) = Prev(Current(*L));
                    Nomor(*L) = 3;
                }
                boolean found = false;
                int i,j;
                i = 0;
                while (!found and i<=9)
                {
                    j = 0;
                    while (!found and j <=19)
                    {
                        if (Info(matriks(Current(*L)),i,j)=='^')
                        {
                            found = true;
                        }
                        else
                        {
                            j+=1;
                        }
                    }
                    i+=1;
                }
                Ordinat(*L) = i+1;
                Absis(*L) = j;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';                
            }
            else
            {
                Ordinat(*L) = Ordinat(*L)+1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';  
            }
        }
}

void D (List *L){
    if (Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)+1)!='*' && Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)+1)!='A' && Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)+1)!='W')
        {
            Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) == '-';
            if (Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)-1)=='>')
            {
                if (Nomor(*L)==2)
                {
                    Current(*L) = Next(Current(*L));
                    Nomor(*L) = 1;
                }
                else
                {
                    Current(*L) = Prev(Current(*L));
                    Nomor(*L) = 4;
                }
                boolean found = false;
                int i,j;
                i = 0;
                while (!found and i<=9)
                {
                    j = 0;
                    while (!found and j <=19)
                    {
                        if (Info(matriks(Current(*L)),i,j)=='<')
                        {
                            found = true;
                        }
                        else
                        {
                            j+=1;
                        }
                    }
                    i+=1;
                }
                Ordinat(*L) = i;
                Absis(*L) = j+1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';               
            }
            else
            {
                Absis(*L) = Absis(*L)+1;
                Info(matriks(Current(*L)),Ordinat(*L),Absis(*L)) = 'P';  
            }
        }
}