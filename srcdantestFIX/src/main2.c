#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "mesin/mesinkata.h"
#include "state/state.h"
#include "stackP/stackP.h"
#include "ListforDetail.h"

int main(){
	MATRIKS M1;
	MATRIKS M2;
	MATRIKS M3;
	MATRIKS M4;
	MakeMATRIKS(&M1,"../test/map1.txt");
	MakeMATRIKS(&M2,"../test/map2.txt");
	MakeMATRIKS(&M3,"../test/map3.txt");
	MakeMATRIKS(&M4,"../test/map4.txt");
	int i,j;
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			Lokasi(M1,i,j)=MakePoint(j+NKol(M2),i);
		}
	}
	
	for (i=0;i<NBrs(M2);i++){
		for (j=0;j<NKol(M2);j++){
			Lokasi(M2,i,j)=MakePoint(j,i);
		}
	}
	
	for (i=0;i<NBrs(M3);i++){
		for (j=0;j<NKol(M3);j++){
			Lokasi(M3,i,j)=MakePoint(j,i+NBrs(M2));
		}
	}
	
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			Lokasi(M4,i,j)=MakePoint(j+NKol(M2),i+NBrs(M2));
		}
	}
	/*
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			TulisPOINT(Lokasi(M1,i,j));
		}
		if (i!=NBrs(M1)) {
			printf("\n");
		}
	}*/
	List L ;
	Nomor(L) = 2 ;
	for (i=0;i<NBrs(M2);i++){
		for (j=0;j<NKol(M2);j++){
			if (Info(M2,i,j)=='P'){
				Ordinat(Kordinat(L)) = i ;
				Absis(Kordinat(L)) = j ;
			}
		}
	}
	Current(L)=NilL;
	InsVLast(&L,M2);
	InsVLast(&L,M1);
	InsVLast(&L,M4);
	InsVLast(&L,M3);
	Kata InputPertama, game;
    game.TabKata[0]='.';
    game.TabKata[1]='/';
    game.TabKata[2]='w';
    game.TabKata[3]='i';
    game.TabKata[4]='l';
    game.TabKata[5]='l';
    game.TabKata[6]='y';
    game.TabKata[7]='g';
    game.TabKata[8]='a';
    game.TabKata[9]='m';
    game.TabKata[10]='e';
    game.Length=11;
    printf("Silahkan mengetik './willygame' untuk memulai permainan.\n");
    boolean gamemulai = false;
	while (!gamemulai)
	{
		InputUser(&InputPertama);
		if(IsKataSama(InputPertama,game))
		{
			gamemulai = true;
            printf("// Welcome to Willy wangky's fum factory!!//\n// New game / load game / exit? // \n");
            StackP Perintah;
            CreateEmpty(&Perintah);
            Kata InputKedua;
			ListB LWahana;
            //Queue Antrian;
            
            Kata newk;
            newk.TabKata[0]='n';
            newk.TabKata[1]='e';
            newk.TabKata[2]='w';
            newk.Length = 3;

            Kata exit;
            exit.TabKata[0]='e';
            exit.TabKata[1]='x';
            exit.TabKata[2]='i';
            exit.TabKata[3]='t';
            exit.Length = 4;

            InputUser(&InputKedua);
			if (IsKataSama(InputKedua,newk))
			{
				printf("hm");
            }
            else if (IsKataSama(InputKedua, exit))
            {
                printf("Thank you for playing the game!");
            }
        }
        else
        {
            printf("Instruksi Salah. Silahkan ketik './willygame' kembali.\n");
        }
        
    }
	return 0;
}
