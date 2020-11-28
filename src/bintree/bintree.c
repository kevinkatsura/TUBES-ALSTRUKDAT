/* Sharon Bernadetha Marbun 1319092 */
/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
	addrNode X = AlokNode(Akar);
	if (X!=Nil){
		Left(X)=L;
		Right(X)=R;
	}
	return X;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
	addrNode P = (addrNode) malloc(sizeof(Node));
  	if (P != Nil) {
    	Akar(P) = X;
    	Left(P) = Nil;
    	Right(P) = Nil;
  }
  return P;

}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
	return (P==Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
	if (!IsTreeEmpty(P))
		return ((Left(P)==Nil) && (Right(P)==Nil));
	else
		return false;
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
	if (!IsTreeEmpty(P))
		return ((Left(P)!=Nil) && (Right(P)==Nil));
	else
		return false;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
	if (!IsTreeEmpty(P))
		return ((Left(P)==Nil) && (Right(P)!=Nil));
	else
		return false;
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
	if (!IsTreeEmpty(P))
		return ((Left(P)!=Nil) && (Right(P)!=Nil));
	else
		return false;

}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
	printf("(");
	if (!IsTreeEmpty(P)){
		printf("%d",Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
	printf("(");
	if (!IsTreeEmpty(P)){
		PrintInorder(Left(P));
		printf("%d",Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
	printf("(");
	if (!IsTreeEmpty(P)){
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d",Akar(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree(BinTree P, int h){
	if (!IsTreeEmpty(P)) {
    	PrintKata(Akar(P).nama);
    	if (Left(P) != Nil){
    		int i;
      		for(i=1;i<=h;i++) 
			  printf(" ");
      		PrintTree(Left(P), 2*h);
    	}
    	if (Right(P)!=Nil){
    		int i;
      		for (i=1;i<=h;i++) 
	  			printf(" ");
      		PrintTree(Right(P),2*h);
    	}
	}
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/


