/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "../boolean.h"
#include "../mesin/mesinkata.h"

#define Nil -1
#define MAX 10
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */

typedef int PATIENCE;
typedef int PRIORITY;
typedef struct {
	PATIENCE patience;
	PRIORITY priority;
	Kata wahana[MAX];
	int idxksg;
}infotypeQ;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotypeQ * T;   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxElQ;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define InfoQ(Q,P) (Q).T[P]
#define Priority(Q,P) (Q).T[P].priority
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define PriorityHead(Q) (Q).T[(Q).HEAD].priority
#define PriorityTail(Q) (Q).T[(Q).TAIL].priority
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q) (Q).MaxElQ

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQ (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQ (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueueQ (Queue * Q, infotypeQ X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DequeueQ (Queue * Q, infotypeQ * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
        
void PushQ (infotypeQ * X, Kata Y );
/*memasukkan string Y (nama wahana) ke dalam X.wahana (list wahana)*/

void PopQ (infotypeQ * X, int i);
/*mengeluarkan string dari list wahana index ke i dari list*/
void PrintQ (infotypeQ X);

void Basic(infotypeQ * X);
/*membuat X ke dalam kondisi awal:priority: 1, patience : 1, idxksg (idxkosong):0 */


#endif
