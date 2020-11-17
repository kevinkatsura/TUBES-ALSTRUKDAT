#ifndef header_H
#define header_H
#include "boolean.h"


/**** Definisi Abstract Data Type POINT ****/
typedef struct {
    float x; /* absis */ float y; /* ordinat */
} point;
/**** Selektor point ****/
#define Absis(P) (P).x 
#define Ordinat(P) (P).y



/**** Definisi Abstract Data Type JAM ****/
#define Hour(J) (J).HH 
#define Minute(J) (J).MM 
#define Second(J) (J).SS
typedef struct {
    int HH; /* 0..23 */ int MM; /* 0..59 */ int SS; /* 0..59 */
} Jam;


#endif 