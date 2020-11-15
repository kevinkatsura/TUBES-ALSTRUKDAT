#include <stdio.h> 
#include "point.h"

/**** Konstruktor POINT ****/
point MakePoint (float x, float y)
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */ 
{ /* KAMUS */
    point P;
    /* ALGORITMA */
    Absis(P) = x; Ordinat(P) = y; return P;
}

/**** Predikat ****/
boolean IsOrigin (point P)
/* Mengirimkan nilai benar jika P adalah titik origin yaitu titik <0,0> */ 
{ /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0)); 
}

/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void BacaPOINT (point * P)
/* Membentuk P dari x dan y yang dibaca dari keyboard */ 
{ /* KAMUS */
    float x, y;
    /* ALGORITMA */ scanf("%f", &x); scanf("%f", &y);
    *P = MakePoint(x,y);
}

void TulisPOINT (point P)
/* Nilai P ditulis ke layar dg format "(X,Y)" */ 
{ /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P)); 
}

/**** Fungsi/Operasi lain terhadap point ****/
point geser (point P, float dx, float dy)
/* Menghasilkan point yang merupakan hasil penggeseran P */ /* sebesar dx arah sumbu x dan dy arah sumbu y */
{ /* ALGORITMA */
    return (MakePoint(Absis(P)+dx, Ordinat(P)+dy)); 
}