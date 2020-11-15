#ifndef POINT_H 
#define POINT_H
#include "../boolean.h"


/**** Definisi Abstract Data Type POINT ****/
typedef struct {
float x; /* absis */ float y; /* ordinat */
} point;


/**** Selektor point ****/
#define Absis(P) (P).x 
#define Ordinat(P) (P).y


/**** Konstruktor POINT ****/
point MakePoint (float x, float y);
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */
/**** Predikat ****/
boolean IsOrigin (point P);
/* Mengirimkan nilai benar jika P adalah titik origin yaitu titik <0,0> */
/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void BacaPOINT (point * P);
/* Membentuk P dari x dan y yang dibaca dari keyboard */ 
void TulisPOINT (point P);
/* Nilai P ditulis ke layar dg format "(X,Y)" */
/**** Fungsi/Operasi lain terhadap point ****/
point geser (point P, float dx, float dy);
/* Menghasilkan point yang merupakan hasil penggeseran P */ /* sebesar dx arah sumbu x dan dy arah sumbu y */
#endif