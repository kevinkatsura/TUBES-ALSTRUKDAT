#include "listdp/listdp.c"
#include "point/point.h"

void W (List *L){
        if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L))-1,Absis(Kordinat(*L)))!='*' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L))-1,Absis(Kordinat(*L)))!='A' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L))-1,Absis(Kordinat(*L)))!='W')
        {
            Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) ='-';
            if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L))-1,Absis(Kordinat(*L)))=='^')
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
                while (!found && i<NBrs(matriks(Current(*L))))
                {
                    j = 0;
                    while (!found && j <NKol(matriks(Current(*L))))
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
                Ordinat(Kordinat(*L)) = i-1;
                Absis(Kordinat(*L)) = j;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';                
            }
            else
            {
                Ordinat(Kordinat(*L)) = Ordinat(Kordinat(*L))-1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';  
            }
        }
}

void A (List *L){
    if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))-1)!='*' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))-1)!='A' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))-1)!='W')
        {
            Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = '-';
            if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))-1)=='<')
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
                while (!found && i<NBrs(matriks(Current(*L))))
                {
                    j = 0;
                    while (!found && j <NKol(matriks(Current(*L))))
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
                Ordinat(Kordinat(*L)) = i;
                Absis(Kordinat(*L)) = j-1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';                
            }
            else
            {
                Absis(Kordinat(*L)) = Absis(Kordinat(*L))-1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';  
            }
        }
}

void S (List *L){
        if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L))+1,Absis(Kordinat(*L)))!='*' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L))+1,Absis(Kordinat(*L)))!='A' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L))+1,Absis(Kordinat(*L)))!='W')
        {
            Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = '-';
            if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L))+1,Absis(Kordinat(*L)))=='v')
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
                while (!found && i<NBrs(matriks(Current(*L))))
                {
                    j = 0;
                    while (!found && j <NKol(matriks(Current(*L))))
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
                Ordinat(Kordinat(*L)) = i+1;
                Absis(Kordinat(*L)) = j;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';                
            }
            else
            {
                Ordinat(Kordinat(*L)) = Ordinat(Kordinat(*L))+1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';  
            }
        }
}

void D (List *L){
    if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))+1)!='*' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))+1)!='A' && Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))+1)!='W')
        {
            Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = '-';
            if (Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))-1)=='>')
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
                while (!found && i<NBrs(matriks(Current(*L))))
                {
                    j = 0;
                    while (!found && j <NKol(matriks(Current(*L))))
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
                Ordinat(Kordinat(*L)) = i;
                Absis(Kordinat(*L)) = j+1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';               
            }
            else
            {
                Absis(Kordinat(*L)) = Absis(Kordinat(*L))+1;
                Info(matriks(Current(*L)),Ordinat(Kordinat(*L)),Absis(Kordinat(*L))) = 'P';  
            }
        }
}
