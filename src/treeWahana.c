#include <stdio.h>
#include "bintree/bintree.c"
#include "readWahana.c"

void MakeWahana(BinTree *uWu){
	int nData;
	ekstrakWahana(&nData);
	infotypeW wahana[nData];
	int i;
	for (i=0;i<nData;i++){
		wahana[i].nama=namaW[i];
		wahana[i].harga=KataToInt(hargaW[i]);
		wahana[i].kapasitas=KataToInt(kapasitasW[i]);
		wahana[i].durasi=KataToInt(durasiW[i]);
		wahana[i].deskripsi=deskripsiW[i];
		wahana[i].kayu=KataToInt(kayuW[i]);
		wahana[i].batu=KataToInt(batuW[i]);
		wahana[i].pasir=KataToInt(pasirW[i]);
		wahana[i].besi=KataToInt(besiW[i]);
		wahana[i].semen=KataToInt(semenW[i]);
	}
	BinTree L=Nil;
	BinTree R=Nil;
	BinTree EngiD = Tree(wahana[4],L,R);
	BinTree JBless = Tree(wahana[5],L,R);
	BinTree Wangky = Tree(wahana[3],EngiD,JBless);
	BinTree Halo = Tree(wahana[2],EngiD,R);
	*uWu = Tree(wahana[1],Wangky,Halo);
	
	/*Contoh penggunaan
	int main(){
		BinTree uWu;
		MakeWahana(&uWu);
		PrintTree(Right(uWu),2);
	}*/	
}

	
