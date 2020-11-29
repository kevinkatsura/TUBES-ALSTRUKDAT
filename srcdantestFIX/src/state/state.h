#ifndef STATE_H
#define STATE_H

#include "../jam/jam.h"
#include "../arraydin/arraydin.h"
#include "../point/point.h"
#include "../mesin/mesinkata.h"
#include "../matriks/matriks.h"


typedef struct
{
    Kata name;
    int money; //PREP/MAIN
    int currentTime; //PREP/MAIN
    int openingTime; //PREP
    int closingTime; //MAIN
    int timeRemaining; //PREP/MAIN
    int totalAksi; //PREP
    int totalWaktu; //PREP
    int totalUang; //PREP
    TabInt inventory; //PREP
    point lokasi; //PREP/MAIN
    //infotypeQ antrian; //MAIN

} State;

#define Name(PS) (PS).name
#define Money(PS) (PS).money
#define CurrTime(PS) (PS).currentTime
#define OpTime(PS) (PS).openingTime
#define ClosTime(PS) (PS).closingTime
#define TimeRem(PS) (PS).timeRemaining
#define TAksi(PS) (PS).totalAksi
#define TWaktu(PS) (PS).totalWaktu
#define TUang(PS) (PS).totalUang
#define Inventory(PS) (PS).inventory
#define Lok(PS) (PS).lokasi
//#define Antrian(PS) (PS).antrian

void NewPrepState(State *PS, Kata Nama);

void NewMainState(State *PS);

void PrintPrepState(State PS);

void PrintMainState(State PS);

boolean IsResourceAda(State PS, Kata wahana, char *File);

#endif