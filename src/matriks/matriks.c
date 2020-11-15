#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	return((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
	return(BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
	return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
	return(NBrsEff(M)-1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
	return((NKolEff(M)-1));
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	return((i>=BrsMin) && (i<=GetLastIdxBrs(M)) && (j>=KolMin) && (j<=GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
	return(Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	indeks i,j;
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn), MHsl);
	
	for (i=BrsMin;i<=GetLastIdxBrs(MIn);i++){
		for (j=KolMin;j<=GetLastIdxKol(MIn);j++){
			Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
		}
	}
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	indeks i,j;
	MakeMATRIKS(NB,NK,M);
	
	for (i=BrsMin;i<=GetLastIdxBrs(*M);i++){
		for (j=KolMin;j<=GetLastIdxKol(*M);j++){
			scanf("%d", &Elmt(*M,i,j));
		}
	}
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
	indeks i,j;
	
for (i=GetFirstIdxBrs(M); i<= GetLastIdxBrs(M); i++){
        for (j=GetFirstIdxKol(M); j<= GetLastIdxKol(M); j++){
            if (j == GetLastIdxKol(M)){
				printf("%d",Elmt(M,i,j));
			}else{
                printf("%d ",Elmt(M,i,j));
            }
        }
        if(i != GetLastIdxBrs(M)){printf("\n");}
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i,j;
	
	for (i=BrsMin;i<=GetLastIdxBrs(M1);i++){
		for (j=KolMin;j<=GetLastIdxKol(M1);j++){
			Elmt(M1,i,j)+=Elmt(M2,i,j);
		}
	}
	return(M1);
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i,j;
	
	for (i=BrsMin;i<=GetLastIdxBrs(M1);i++){
		for (j=KolMin;j<=GetLastIdxKol(M1);j++){
			Elmt(M1,i,j)-=Elmt(M2,i,j);
		}
	}
	return(M1);
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
	indeks i,j,k;
	ElType sum;
	MATRIKS M3;
	
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
	
	for (i=BrsMin;i<=GetLastIdxBrs(M1);i++){
		for (j=KolMin;j<=GetLastIdxKol(M2);j++){
			sum=0;
			for (k=KolMin;k<=GetLastIdxKol(M1);k++){
				sum+=Elmt(M1,i,k)*Elmt(M2,k,j);
			}
			Elmt(M3,i,j)=sum;
		}
	}
	return(M3);
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
	indeks i,j;
	
	for (i=BrsMin;i<=GetLastIdxBrs(M);i++){
		for (j=KolMin;j<=GetLastIdxKol(M);j++){
			Elmt(M,i,j)*=X;
		}
	}
	return(M);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
	(*M)=KaliKons(*M,K);
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	indeks i,j;
	boolean equal=false;
	
	if (EQSize(M1,M2)){
		for (i=BrsMin;i<=GetLastIdxBrs(M1);i++){
			for (j=KolMin;j<=GetLastIdxKol(M1);j++){
				if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
					break;
				} else if ((i==GetLastIdxBrs(M1)) && (j==GetLastIdxKol(M1))){
					equal = true;
				}
			}
			if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
				break;
			}
		}
	}
	return equal;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
	return(!EQ(M1,M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	return((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
	return(NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
	boolean simetri=false;
	MATRIKS MT;
	
	if (IsBujurSangkar(M)){
		CopyMATRIKS(M,&MT);
		Transpose(&MT);
		if (EQ(M,MT)){
			simetri=true;
		}
	}
	return simetri;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
	indeks i,j;
	boolean satuan=true;
	
	if (IsBujurSangkar(M)){
		for (i=BrsMin;i<=GetLastIdxBrs(M);i++){
			for (j=KolMin;j<=GetLastIdxKol(M);j++){
				if (((i==j) && (Elmt(M,i,j) !=1)) || ((i!=j) && (Elmt(M,i,j)!=0))){
					satuan=false;
					break;
				}
			}
		}
	} else{
		satuan=false;
	}
	return satuan;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
	float percentage= 5*NBElmt(M)/100;
	int count=0;
	indeks i,j;
	
	for (i=BrsMin;i<=GetLastIdxBrs(M);i++){
		for (j=KolMin;j<=GetLastIdxKol(M);j++){
			if (Elmt(M,i,j)!=0){
				count++;
			}
		}
	}
	return(count<=percentage);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
	return (KaliKons(M,-1));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
	float det=0;
    if ((NBrsEff(M)==2) && (NKolEff(M)==2)){
        det =(Elmt(M,0,0)*Elmt(M,1,1)) - (Elmt(M,0,1)*Elmt(M,1,0));
        return det;
    }
    else{
        indeks i,j,k;
        MATRIKS Mtemp;
        MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &Mtemp);
        for (k = GetFirstIdxKol(M); k<= GetLastIdxKol(M); k++){
            for (i=GetFirstIdxBrs(M)+1; i<=GetLastIdxBrs(M); i++){
                for(j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
                    if (j>k){
                        Elmt(Mtemp,i-1,j-1) = Elmt(M,i,j);
                    }
                    else{
                        Elmt(Mtemp,i-1,j) = Elmt(M,i,j);
                    }
                }
            }
            if (k%2 ==0){
                det += Elmt(M,0,k)*Determinan(Mtemp);
            }
            else{
                det -= Elmt(M,0,k)*Determinan(Mtemp);
            }
        }
        return det;

    }
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
	(*M)=Inverse1(*M);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
	indeks i,j;
	ElType Temp;
	
	for (i=BrsMin;i<=GetLastIdxBrs(*M);i++){
		for (j=i+1;j<=GetLastIdxKol(*M);j++){
			Temp = Elmt(*M,i,j);
			Elmt(*M,i,j)=Elmt(*M,j,i);
			Elmt(*M,j,i)= Temp;
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
	ElType jumlah=0;
	int count=0;
	indeks j;
	float rata;
	for (j=KolMin;j<=GetLastIdxKol(M);j++){
		jumlah += Elmt(M,i,j);
		count++;
	}
	rata = jumlah/count;
	return (rata);
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float RataKol (MATRIKS M, indeks j){
	ElType jumlah=0;
	int count=0;
	indeks i;
	float rata;
	for (i=BrsMin;i<=GetLastIdxBrs(M);i++){
		jumlah += Elmt(M,i,j);
		count++;
	}
	rata = jumlah/count;
	return (rata);
}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
	indeks j;
	*max = Elmt(M,i,0);
	*min = Elmt(M,i,0);
	for (j=KolMin+1;j<=GetLastIdxKol(M);j++){
		if (*max<Elmt(M,i,j)){
			*max = Elmt(M,i,j);
		}
		if (*min>Elmt(M,i,j)){
			*min = Elmt(M,i,j);
		}
	}
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
	indeks i;
	*max = Elmt(M,0,j);
	*min = Elmt(M,0,j);
	for (i=BrsMin+1;i<=GetLastIdxBrs(M);i++){
		if (*max<Elmt(M,i,j)){
			*max = Elmt(M,i,j);
		}
		if (*min>Elmt(M,i,j)){
			*min = Elmt(M,i,j);
		}
	}
}
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
int CountXBrs (MATRIKS M, indeks i, ElType X){
	int count=0;
	indeks j;
	for (j=KolMin;j<=GetLastIdxKol(M);j++){
		if (Elmt(M,i,j)==X){
			count++;
		}
	}
	return (count);
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXKol (MATRIKS M, indeks j, ElType X){
	int count=0;
	indeks i;
	for (i=BrsMin;i<=GetLastIdxBrs(M);i++){
		if (Elmt(M,i,j)==X){
			count++;
		}
	}
	return (count);
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
