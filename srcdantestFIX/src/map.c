#include <stdio.h>
#include "movement.h"

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
	TulisMATRIKS(M2);
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
	S(&L);
	TulisMATRIKS(matriks(Current(L)));
	int h;
	scanf("%d",&h);
	return 0;
}
