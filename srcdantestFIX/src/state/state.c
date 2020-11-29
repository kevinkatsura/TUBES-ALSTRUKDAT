
#include "state.h"
#include <stdio.h>

void NewPrepState(State *PS, Kata Nama)
{
    Name(*PS) = Nama;
    Money(*PS) = 100000;
    CurrTime(*PS) = 75600;
    OpTime(*PS) = 32400;
    TimeRem(*PS) = CurrTime(*PS)-OpTime(*PS);
    TAksi(*PS) = 0;
    TWaktu(*PS) = 0;
    TUang(*PS) = 0;
    TabInt I;
    MakeEmpty(&I,5);
    //i=0:kayu ; i=1:Batu ; i=2:Pasir ; i=3:Besi ; i=4:Semen
    for (int i=0; i<5; i++)
    {
        Elmt(I,i) = 10;
    }
    Neff(I) = 5;
    Inventory(*PS) = I;
    Lok(*PS) = MakePoint(1,1);
}

/*void NewMainState(State *PS)
{

}*/

void PrintPrepState(State PS)
{
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<,^,>,V = Gerbang\n\n");
    Jam JCurr,JOpen, JRemaining, JTWaktu;
    JCurr = DetikToJam(CurrTime(PS));
    JOpen = DetikToJam(OpTime(PS));
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
    printf("%d",TimeRem(PS)/3600);printf(" hour(s)");
    printf("\n");
    printf("Total aksi yang akan dilakukan: %d", TAksi(PS));
    printf("\n");
    printf("Total waktu yang dibutuhkan: ");
    printf("%d",TWaktu(PS)/3600);printf(" hour(s)");
    printf("\n");
    printf("Total uang yang dibutuhkan: %d", TUang(PS));
    printf("\n");
    printf("Inventory: ");
    TulisIsiTab(Inventory(PS));
    printf("\n");
    //printf("\n");
    //TulisPOINT(Lok(PS));*/
}

void PrintMainState(State PS)
{
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<,^,>,V = Gerbang\n\n");
    Jam JCurr,JClose, JRemaining, JTWaktu;
    JCurr = DetikToJam(CurrTime(PS));
    JClose = DetikToJam(ClosTime(PS));
    JRemaining = DetikToJam(TimeRem(PS));
    printf("Name: ");
    PrintKata(Name(PS));
    printf("\n"); 
    printf("Money: %d\n", Money(PS));
    printf("Current Time: ");
    TulisJam(JCurr);
    printf("\n");
    printf("Closing Time: ");
    TulisJam(JClose);
    printf("\n");
    printf("Time Remaining: ");
    TulisJam(JRemaining);printf(" hour(s)");
    printf("\n");
    //PrintQ(InfoHead(Antrian(PS)));
}

boolean IsResourceAda (State PS, Kata wahana, char *File)
{
    int nData=1;
	START(File);
	while (!EOP){
		if (CC==NEWLINE)
			nData++;
		ADV();
	}
    Kata namaW[nData];
    Kata kayuW[nData];
	Kata batuW[nData];
	Kata pasirW[nData];
	Kata besiW[nData];
	Kata semenW[nData];

    int i=0;
	START(File);
	while(CC!=MARK){
		while ((CC!=NEWLINE) && (CC!=MARK)){
			SalinKata();
			namaW[i]=CKata;
			ADV();
			SalinKata();
			ADV();
			SalinKata();
			ADV();
			SalinKata();
			ADV();
			SalinKata();
			ADV();
			SalinKata();
			kayuW[i]=CKata;
			ADV();
			SalinKata();
			batuW[i]=CKata;
			ADV();
			SalinKata();
			pasirW[i]=CKata;
			ADV();
			SalinKata();
			besiW[i]=CKata;
			ADV();
			SalinKata();
			semenW[i]=CKata;
		}
		if (CC!=MARK)
			ADV();
			i++;
	}
    boolean valid = true;
    int j = 0;
    while (valid && j<nData)
    {
        if (IsKataSama(wahana,namaW[j])) 
        {
            if (Elmt(Inventory(PS),0) < KataToInt(kayuW[j]))
            {
                valid = false;
            }
            else if (Elmt(Inventory(PS),1) < KataToInt(batuW[j]))
            {
                valid = false;
            }
            else if (Elmt(Inventory(PS),2) < KataToInt(pasirW[j]))
            {
                valid = false;
            }
            else if (Elmt(Inventory(PS),3) < KataToInt(besiW[j]))
            {
                valid = false;
            }
            else if (Elmt(Inventory(PS),4) < KataToInt(semenW[j]))
            {
                valid = false;
            }
            else
            {
                valid = true;
            } 
        }
        j++;
    }
    return valid;

}


/*int main(){
    State PS;
    Kata nama, wahana;
    InputUser(&nama);
    printf("JJJ");
    NewPrepState(&PS, nama);
    printf("AAA");
    PrintPrepState(PS);
    printf("AAFSAGA");
    printf("\n");
    int h;
    scanf("%d",&h);
    return 0;
}*/