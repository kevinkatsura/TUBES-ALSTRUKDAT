/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__


#include "mesinkar.h"
#include "../arraydin/arraydin.h"

#define NMax 1000

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Kata;

typedef struct {
   Kata aksi[5];
   int durasi[5];
} Action;

typedef struct {
   Kata material[5];
   int harga[5];
} Materials;


#define Aksi(A,i) (A).aksi[(i)]
#define DurasiAksi(A,i) (A).durasi[(i)]

#define Material(B,i) (B).material[(i)]
#define HargaMaterial(B,i) (B).harga[(i)]

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ? BLANK atau CC = MARK */

void STARTKATA(char *file);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsKataSama (Kata K1, Kata K2);
/* Mengirimkan true jika K1 = K2 */

char KataToChar (Kata K);
/* Mengonversi Kata K menjadi char, K.Length=1 */

int KataToInt (Kata K);
/* Mengonversi Kata K menjadi integer */

void InputUser (Kata *K);
/* Memasukkan inputan user ke dalam Kata K*/

void PrintKata (Kata K);
/* Menampilkan Kata K ke layar */

Kata KonkatKata (Kata K1, Kata K2);

void ListAction (Action *A, char *File);

void ListMaterial (Materials *B, char *File);

void ParsePilihBahan (Kata Perintah, Kata *jumlah, Kata *bahan);

void MakeListHargaBahan (TabInt *T, char*File);

int HargaBahan(Kata bahan, char *File);

void PrintListBahan (char *File);

boolean IsBahanAda (Kata K, char *File);

int HargaWahana(Kata wahana, char *File1);

void PrintListWahana (char *File);

boolean IsWahanaAda (Kata K, char *File);


#endif