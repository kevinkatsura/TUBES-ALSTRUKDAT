
#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
{
      /* I.S. T sembarang, maxel > 0 */
      /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
      TI(*T) = (int *)malloc(maxel * sizeof(int));
      Neff(*T) = 0;
      MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T)
{
      /* I.S. T terdefinisi; */
      /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
      free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
      /* Mengirimkan banyaknya elemen efektif tabel */
      /* Mengirimkan nol jika tabel kosong */
      if (IsEmpty(T))
      {
            return 0;
      }
      else
      {
            return Neff(T);
      }
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
{
      /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
      return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
{
      /* Prekondisi : Tabel T tidak kosong */
      /* Mengirimkan indeks elemen T pertama */
      return IdxMin;
}
IdxType GetLastIdx(TabInt T)
{
      /* Prekondisi : Tabel T tidak kosong */
      /* Mengirimkan indeks elemen T terakhir */
      return Neff(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
      /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
      /* yaitu antara indeks yang terdefinisi utk container*/
      return (i >= GetFirstIdx(T) && i <= MaxEl(T) - 1);
}
boolean IsIdxEff(TabInt T, IdxType i)
{
      /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
      /* yaitu antara FirstIdx(T)..LastIdx(T) */
      return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
{
      /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
      return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
{
      /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
      return (NbElmt(T) == MaxElement(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
{
      /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
      /* F.S. Tabel T terdefinisi */
      /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
      /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
      /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
      /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
      /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
      /*    Jika N = 0; hanya terbentuk T kosong */
      int N;
      IdxType i;
      scanf("%d\n", &N);
      while (0 > N || N > MaxElement(*T))
      {
            scanf("%d\n", &N);
      }
      if (N == 0)
      {
            return MakeEmpty(T, MaxEl(*T));
      }
      else
      {
            for (i = GetFirstIdx(*T); i < N; i++)
            {
                  scanf("%d", &Elmt(*T, i));
                  Neff(*T) = N;
            }
      }
}
void TulisIsiTab(TabInt T)
{
      /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
      /* I.S. T boleh kosong */
      /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
      /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
      /* Jika tabel kosong : menulis [] */
      if (IsEmpty(T))
      {
            printf("[]");
      }
      else
      {
            IdxType i;
            printf("[");
            for (i = GetFirstIdx(T); i < GetLastIdx(T); i++)
            {
                  printf("%d", Elmt(T, i));
                  printf(",");
            }
            printf("%d", Elmt(T, GetLastIdx(T)));
            printf("]");
      }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
{
      /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
      /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
      /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
      //kamus lokal
      IdxType i;
      TabInt T3;
      //alokasi T3
      MakeEmpty(&T3, MaxEl(T1));
      //algoritma
      if (plus)
      {
            for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
            {
                  Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
            }
            Neff(T3) = Neff(T1);
            return T3;
      }
      else
      {
            for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
            {
                  Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
            }
            Neff(T3) = Neff(T1);
            return T3;
      }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
{
      /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
      IdxType i;
      boolean sama;
      sama = true;
      //mengecek ukuran
      if (NbElmt(T1) != NbElmt(T2))
      {
            sama = false;
      }
      else
      {
            i = GetFirstIdx(T1);
            while (sama && i <= GetLastIdx(T2))
            {
                  if (Elmt(T1, i) != Elmt(T2, i))
                  {
                        sama = false;
                  }
                  else
                  {
                        i += 1;
                  }
            }
      }

      return (sama);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElTypeA X)
{
      /* Search apakah ada elemen tabel T yang bernilai X */
      /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
      /* Jika tidak ada, mengirimkan IdxUndef */
      /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
      /* Skema Searching yang digunakan bebas */
      if (IsEmpty(T))
      {
            return IdxUndef;
      }
      else
      {
            boolean found = false;
            IdxType i;
            i = GetFirstIdx(T);
            while ((!found) && (i <= GetLastIdx(T)))
            {
                  if (Elmt(T, i) == X)
                  {
                        found = true;
                  }
                  else
                  {
                        i++;
                  }
            }
            if (found)
            {
                  return i;
            }
            else
            {
                  return IdxUndef;
            }
      }
}
boolean SearchB(TabInt T, ElTypeA X)
{
      /* Search apakah ada elemen tabel T yang bernilai X */
      /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
      /* Skema searching yang digunakan bebas */
      return (Search1(T, X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElTypeA *Max, ElTypeA *Min)
{
      /* I.S. Tabel T tidak kosong */
      /* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
      IdxType i;
      int maks, min;
      maks = 0;
      min = 99999999;
      for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
      {
            if (Elmt(T, i) >= maks)
            {
                  maks = Elmt(T, i);
            }
            if (Elmt(T, i) <= min)
            {
                  min = Elmt(T, i);
            }
      }
      *Max = maks;
      *Min = min;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
{
      /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
      /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
      /* Proses : Menyalin isi Tin ke Tout */
      IdxType i;
      MakeEmpty(Tout, MaxEl(Tin));
      Neff(*Tout) = Neff(Tin);
      for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
      {
            Elmt(*Tout, i) = Elmt(Tin, i);
      }
}
ElTypeA SumTab(TabInt T)
{
      /* Menghasilkan hasil penjumlahan semua elemen T */
      /* Jika T kosong menghasilkan 0 */
      if (IsEmpty(T))
      {
            return 0;
      }
      else
      {
            IdxType i;
            int sum;
            sum = 0;
            for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
            {
                  sum += Elmt(T, i);
            }
            return sum;
      }
}
int CountX(TabInt T, ElTypeA X)
{
      /* Menghasilkan berapa banyak kemunculan X di T */
      /* Jika T kosong menghasilkan 0 */
      if (IsEmpty(T))
      {
            return 0;
      }
      else
      {
            IdxType i;
            int count;
            count = 0;
            for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
            {
                  if (Elmt(T, i) == X)
                  {
                        count++;
                  }
            }
            return count;
      }
}
boolean IsAllGenap(TabInt T)
{
      /* Menghailkan true jika semua elemen T genap. T boleh kosong */
      if (IsEmpty(T))
      {
            return true;
      }
      else
      {
            IdxType i = GetFirstIdx(T);
            boolean genap = true;
            while (genap && i <= GetLastIdx(T))
            {
                  if (Elmt(T, i) % 2 != 0)
                  {
                        genap = false;
                  }
                  else
                  {
                        i++;
                  }
            }
            return genap;
      }
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
{
      /* I.S. T boleh kosong */
      /* F.S. Jika asc = true, T terurut membesar */
      /*      Jika asc = false, T terurut mengecil */
      /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
      IdxType i, iMax, iMin, Pass;
      ElTypeA Temp;
      if (!asc)
      {
            for (Pass = GetFirstIdx(*T); Pass <= GetLastIdx(*T); Pass++)
            {
                  iMax = Pass;
                  for (i = Pass + 1; i <= GetLastIdx(*T); i++)
                  {
                        if (Elmt(*T, iMax) < Elmt(*T, i))
                        {
                              iMax = i;
                        }
                  }
                  Temp = Elmt(*T, iMax);
                  Elmt(*T, iMax) = Elmt(*T, Pass);
                  Elmt(*T, Pass) = Temp;
            }
      }
      else
      {
            for (Pass = GetFirstIdx(*T); Pass <= GetLastIdx(*T); Pass++)
            {
                  iMin = Pass;
                  for (i = Pass + 1; i <= GetLastIdx(*T); i++)
                  {
                        if (Elmt(*T, iMin) > Elmt(*T, i))
                        {
                              iMin = i;
                        }
                  }
                  Temp = Elmt(*T, iMin);
                  Elmt(*T, iMin) = Elmt(*T, Pass);
                  Elmt(*T, Pass) = Temp;
            }
      }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElTypeA X)
{
      /* Proses: Menambahkan X sebagai elemen terakhir tabel */
      /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
      /* F.S. X adalah elemen terakhir T yang baru */
      Elmt(*T, GetLastIdx(*T) + 1) = X;
      Neff(*T) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElTypeA *X)
{
      /* Proses : Menghapus elemen terakhir tabel */
      /* I.S. Tabel tidak kosong */
      /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
      /*      Banyaknya elemen tabel berkurang satu */
      /*      Tabel T mungkin menjadi kosong */
      *X = Elmt(*T, GetLastIdx(*T));
      Neff(*T) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
{
      /* Proses : Menambahkan max element sebanyak num */
      /* I.S. Tabel sudah terdefinisi */
      /* F.S. Ukuran tabel bertambah sebanyak num */
      // kamus lokal
      TabInt temp;
      IdxType i;
      CopyTab(*T, &temp);
      Dealokasi(T);
      // deklarasi kembali T dengan max element sebanyak num
      MakeEmpty(T, (MaxEl(temp) + num));
      // salin isi temp ke T yang baru
      for (i = GetFirstIdx(temp); i <= GetLastIdx(temp); i++)
      {
            Elmt(*T, i) = Elmt(temp, i);
            Neff(*T) = Neff(temp);
      }
}

void ShrinkTab(TabInt *T, int num)
{
      /* Proses : Mengurangi max element sebanyak num */
      /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
      /* F.S. Ukuran tabel berkurang sebanyak num. */
      // kamus lokal
      TabInt temp;
      IdxType i;
      CopyTab(*T, &temp);
      Dealokasi(T);
      // deklarasi kembali T dengan max element sebanyak num
      MakeEmpty(T, (MaxEl(temp) - num));
      // salin isi temp ke T yang baru
      for (i = GetFirstIdx(temp); i <= GetLastIdx(temp); i++)
      {
            Elmt(*T, i) = Elmt(temp, i);
            Neff(*T) = Neff(temp);
      }
}

void CompactTab(TabInt *T)
{
      /* Proses : Mengurangi max element sehingga Neff = MaxEl */
      /* I.S. Tabel tidak kosong */
      /* F.S. Ukuran MaxEl = Neff */
      // kamus lokal
      TabInt temp;
      IdxType i;
      CopyTab(*T, &temp);
      Dealokasi(T);
      // deklarasi kembali T dengan max element sebanyak num
      MakeEmpty(T, Neff(temp));
      // salin isi temp ke T yang baru
      for (i = GetFirstIdx(temp); i <= GetLastIdx(temp); i++)
      {
            Elmt(*T, i) = Elmt(temp, i);
            Neff(*T) = Neff(temp);
      }
}
