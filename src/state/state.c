
#include "state.h"
#include <stdio.h>

void NewPrepState(State *PS, Kata Nama)
{
    Name(*PS) = Nama;
    Money(*PS) = 1000;
    CurrTime(*PS) = 75600;
    OpTime(*PS) = 32400;
    TimeRem(*PS) = CurrTime(*PS)-OpTime(*PS);
    TAksi(*PS) = 0;
    TWaktu(*PS) = 0;
    TUang(*PS) = 0;
    TabInt I;
    MakeEmpty(&I,5);
    Inventory(*PS) = I;
    Lok(*PS) = MakePoint(1,1);
}

/*void NewMainState(State *PS)
{

}*/

void PrintPrepState(State PS)
{
    printf("Preparation phase day 1\n");
    printf("----------MAP----------\n");
    Jam JCurr,JOpen, JRemaining, JTWaktu;
    JCurr = DetikToJam(CurrTime(PS));
    JOpen = DetikToJam(OpTime(PS));
    JRemaining = DetikToJam(TimeRem(PS));
    JTWaktu = DetikToJam(TWaktu(PS));
    printf("Name: ");
    PrintKata(Name(PS));
    printf("\n"); 
    printf("Money: %d\n", Money(PS));
    printf("Current Time: ");
    TulisJam(JCurr);
    printf("\n");
    printf("Opening Time: ");
    TulisJam(JOpen);
    printf("\n");
    printf("Time Remaining: ");
    TulisJam(JRemaining);
    printf("\n");
    printf("Total aksi yang akan dilakukan: %d", TAksi(PS));
    printf("\n");
    printf("Total waktu yang dibutuhkan: ");
    TulisJam(JTWaktu);
    printf("\n");
    printf("Total uang yang dibutuhkan: %d", TUang(PS));
    printf("\n");
    /*printf("Inventory: ");
    TulisIsiTab(Inventory(PS));
    printf("\n");
    TulisPOINT(Lok(PS));*/
}

/*int main(){
    State PS;
    Kata nama;
    InputUser(&nama);
    NewPrepState(&PS, nama);
    PrintPrepState(PS);
    int h;
    scanf("%d",&h);
    return 0;
}*/