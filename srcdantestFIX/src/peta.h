/* Definisi TYPE PETA */
#ifndef PETA_H
#define PETA_H

#include "matriks/matriks.h"
#include "point/point.h"
#include "boolean.h"
#include <stdio.h>

/* Ukuran minimum dan maksimum PETA */
#define PanjangMin 5
#define PanjangMaks 10
#define LebarMin 5
#define LebarMaks 10

typedef struct 
{
    char L;
    point T;
} LOKASI;

/* Selektor PETA */


void MakePETA (MATRIKS *M, int P, int L);


void TulisPETA (MATRIKS M);


#endif
