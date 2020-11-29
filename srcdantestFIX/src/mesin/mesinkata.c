#include "mesinkata.h"
#include "stdio.h"

boolean EndKata ;
Kata CKata ;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang 
F.S. : CC ? BLANK atau CC = MARK */
{    
    while ((CC == BLANK) || (CC == NEWLINE)) 
    {
        ADV();
    }
}

void STARTKATA(char *file)
/* I.S. : CC sembarang 
F.S. : EndKata = true, dan CC = MARK; 
        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
        CC karakter pertama sesudah karakter terakhir kata */
    {
        START(file) ;
        //CKata.Length = 0 ;
        //IgnoreBlank() ;
        //ADVKATA();
    }

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
        CC adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika CC = MARK, EndKata = true.		  
Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    SalinKata();
	IgnoreBlank();
	if (CC==MARK){
		EndKata = true;
	} else {
		EndKata = false;
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi; 
        CC = BLANK atau CC = MARK; 
        CC adalah karakter sesudah karakter terakhir yang diakuisisi.
        Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	CKata.Length = 0;
	while ((CC!=MARK) && (CC!=LIMITER) && (CC!=NEWLINE)){
		if (CKata.Length < NMax){
			CKata.TabKata[CKata.Length] = CC;
			CKata.Length++;	
		}
		ADV(); 
	}
}

boolean IsKataSama(Kata K1, Kata K2)
/* Mengirimkan true jika K1 = K2 */
{
    boolean valid = true;
    int i = 0;
    if (K1.Length = K2.Length)
    {
        while (valid && i<K1.Length)
        {
            if (K1.TabKata[i] != K2.TabKata[i])
            {
                valid = false;
            }
            else
            {
                i+=1;
            }
        }
    }
    else
    {
        valid = false;
    }
    return valid;
    
}

char KataToChar (Kata K)
/* Mengonversi Kata K menjadi char, K.Length=1 */
{
	return (K.TabKata[0]);
}

int KataToInt (Kata K)
/* Mengonversi Kata K menjadi integer */
{
	int val = 0;
	int i = 0;
	while (i<K.Length)
	{
		val = val * 10;
		switch (K.TabKata[i]){
			case '0' : val += 0; break;
			case '1' : val += 1; break;
			case '2' : val += 2; break;
			case '3' : val += 3; break;
			case '4' : val += 4; break;
			case '5' : val += 5; break;
			case '6' : val += 6; break;
			case '7' : val += 7; break;
			case '8' : val += 8; break;
			case '9' : val += 9; break;
		};
		i++;
	}
	return val;	
}
void InputUser (Kata *K)
/* Memasukkan inputan user ke dalam Kata K*/
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).TabKata[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).Length = i;
}

void PrintKata (Kata K)
/* Menampilkan Kata K ke layar */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

Kata KonkatKata (Kata K1, Kata K2)
/*Mengembalikan gabungan Kata K1 dan K2 dengan dipisah spasi terlebih dahulu*/
{
	int i = K1.Length;
	K1.TabKata[i]= ' ';
	i++;
	int j;
	for (j=0;j<K2.Length;j++){
		K1.TabKata[i]=K2.TabKata[j];
		i++;
	}
	K1.Length += K2.Length+1;
	return(K1);
}

void ParsePilihBahan (Kata Perintah, Kata *jumlah, Kata *bahan)
{
   int k = 0;
   while (Perintah.TabKata[k]!=BLANK)
   {
      k++;
   }

   (*jumlah).Length = k;
   (*bahan).Length = Perintah.Length - 1;

   for (int ii=0; ii<k; ii++)
   {
      (*jumlah).TabKata[ii] = Perintah.TabKata[ii];
   }
   for (int ii=0; ii<(*bahan).Length;ii++)
   {
      (*bahan).TabKata[ii] = Perintah.TabKata[k+ii+1];
   }
}

void MakeListHargaBahan (TabInt *T, char *File)
{
	MakeEmpty(T,5);
	int i = 0;
    int k = 0;
    int harga;
    START(File);
    while (CC!=MARK)
    {
        SalinKata();
        i+=1;
        if ((i>2)&&(i % 2==0))
        {
            harga = KataToInt(CKata);
            Elmt(*T,k) = harga;
            k++;
        }
        ADV();
    }
    Neff(*T) = 5;
}

int HargaBahan(Kata bahan, char *File)
{
    int nData=1;
	START(File);
	while (!EOP){
		if (CC==NEWLINE)
			nData++;
		ADV();
	}
    Kata namaB[nData];
    Kata hargaB[nData];

    int i=0;
	START(File);
	while(CC!=MARK){
		while ((CC!=NEWLINE) && (CC!=MARK)){
			SalinKata();
			namaB[i]=CKata;
			ADV();
			SalinKata();
            hargaB[i]=CKata;
		}
		if (CC!=MARK)
			ADV();
			i++;
	}
    boolean valid = false;
    int j = 0;
    int hasil;
    while (!valid && j<nData)
    {
        if (IsKataSama(bahan,namaB[j]))
        {
            hasil = KataToInt(hargaB[j]);
            valid = true;
        }
        j++;
    }
    return hasil;
}

void PrintListBahan (char *File)
{
	TabInt T;
    int i = 0;
    int j = 0;
    MakeListHargaBahan(&T,File);
    START(File);
    while(CC!=MARK)
    {
        SalinKata();
        i+=1;
        if ((i>2)&&(i%2!=0))
        {
            printf("-  ");
            PrintKata(CKata);
            printf("  Rp"); 
            printf("%d",Elmt(T,j));
            printf("/satuan\n");
            j+=1;
        }
        ADV();
    }
}

boolean IsBahanAda (Kata K, char *File)
{
	int i = 0;
    boolean valid = false;
    START(File);
    while(CC!=MARK&&!valid)
    {
        SalinKata();
        i+=1;
        if ((i>2)&&(i%2!=0))
        {
            if (IsKataSama(K,CKata))
            {
                valid = true;
            }
        }
        ADV();
    }
    return valid;
}

void PrintListWahana (char *File)
{
    int i = 0;
    START(File);
    while(CC!=MARK)
    {
        SalinKata();
        i+=1;
        if ((i>10)&&((i-1)%10==0))
        {
            printf("-  ");
            PrintKata(CKata);
            printf("\n");
        }
        ADV();
    }
}

boolean IsWahanaAda (Kata K, char *File)
{
    int i = 0;
    boolean valid = false;
    START(File);
    while(CC!=MARK&&!valid)
    {
        SalinKata();
        i+=1;
        if ((i>10)&&(i-1)%10==0)
        {
            if (IsKataSama(K,CKata))
            {
                valid = true;
            }
        }
        ADV();
    }
    return valid;
}
/*int main() {
    Kata input, jumlah, bahan;
    InputUser(&input);
    ParsePilihBahan(input,&jumlah,&bahan);
    PrintKata(jumlah);
    printf("-----------penanda");
    PrintKata(bahan);
    if (IsBahanAda(bahan,"../../test/material.txt"))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    int har;
    printf("PENANDA---");
    har = HargaBahan(bahan,"../../test/material.txt");
    printf("hargaBahan: %d",har);
    

    int h;
    scanf("%d",h);
    return 0;
}*/