#include "stack/stackt.h"
#include "mesin/mesinkata.h"
#include "matriks/matriks.h"
#include "jam/jam.h"
#include "point/point.h"
typedef int infotype;

typedef struct {
    infotype money; //dalam dollar (?)
    infotype timeNow; //current time dalam detik
    infotype timeOpening; //time opening dalam detik
    infotype timeRemaining; //remaining time dalam detik
    infotype totalAksi; //total aksi yang dibutuhkan
    infotype totalTime; //total waktu yang dibutuhkan
    infotype moneyNeed; //uang yang dibutuhkan
} State; //State Buat Preparation Phase, mungkin nanti perlu buat State yg Main Phase juga

#define Money(St) (St).money
#define TNow(St) (St).timeNow
#define TOpen(St) (St).timeOpening
#define TRemaining(St) (St).timeRemaining
#define TAksi(St) (St).totalAksi
#define TTime(St) (St).totalTime
#define MoneyNeed(St) (St).moneyNeed

void NewState (State *St)
{
    Money(*St) = 1000;
    TNow(*St) = 75600;
    TOpen(*St) = 32400;
    TRemaining(*St) = TNow(*St)-TOpen(*St);
    TAksi(*St) = 0;
    TTime(*St) = 0;
    MoneyNeed(*St) = 0;
}

void PrintState (State St)
{
    Jam JNow, JRemaining;
    JNow = DetikToJam(tNow(St));
    JRemaining = DetikToJam(tRemaining(St));
    printf("Name: wangkie kumalasari"); //ini perlu dimasukin ke tipe bentukan state gak ya
    printf("Money: %d", money(St));
    printf("Current Time: ");
    TulisJam(JNow);
    printf("Opening Time: ");
    printf("Total aksi yang akan dilakukan: %d", tAksi(St));
    printf("Total waktu yang dibutuhkan: ");
    TulisJam(JRemaining);
    printf("Total uang yang dibutuhkan: %d", moneyNeed(St));
}

void PrintPerintah(char *perintah)
{
    printf("Masukkan Perintah: ");
    scanf("%c", perintah);
}

void build (Stack *S, State *St) //Harusnya di sini tambahin matriks sama point tapi nanti dulu deh
{
    // daftarMaterial = (HASIL LOAD FILE EKSTERNAL)
    char *input;
    printf("Ingin membangun apa?\n");
    printf("List:\n");
    printDaftarWahana(); //HASIL LOAD FILE EKSTERNAL
    boolean WahanaAda = false;
    while (!WahanaAda) //verifikasi inputan wahananya ada di daftar wahana atau nggak
    {
        scanf("%c", &input);
        if (!IsWahanaAda(input)) //fungsi ini nanti didefinisiin di tempat lain
        {
            printf("Wahana tidak terdaftar. Silahkan ketik wahana yang ada di daftar wahana.");
        }
        else
        {
            WahanaAda = true;
        }
    }
    if (!IsResourceAda(input)) //fungsi ini nanti didefinisiin di tempat lain
    {
        printf("Material tidak mencukupi. Silahkan membeli material terlebih dahulu.");
    }
    else
    {
        printPetadanLegenda(); //fungsi ini nanti didefinisiin di tempat lain
        TAksi(*St) +=1;
        TTime(*St) = DurasiWahana(input); //fungsi ini nanti didefinisiin di tempat lain
        MoneyNeed(*St) = BiayaWahana(input); //fungsi ini nanti didefinisiin di tempat lain
        printf("// Memasukkan perintah: build"); printf(input); printf("ke Stack//");
        Push(S,Aksi); //belum, perlu diskusi dan koordinasi sama yg ngerjain map biar buildingnya bisa dioutputin ke peta
    }
}

void upgrade (Stack *S, State *St, MATRIKS M, Bangunan B) //ADT Bangunan blm ada
{
    //Daftar Upgrade memakai adt tree :(
    char *input;
    int TotalAksi = 0;
    int waktuUpgrade;
    printf("Ingin melakukan upgrade apa?\n");
    printf("List:\n");
    PrintListUpgrade(B);
    scanf("%c", &input);
    boolean UpgradeAda = false;
    while (!UpgradeAda)
    {
        scanf("%c", &input);
        if (!IsUpgradeAda(input)) //fungsi ini nanti didefinisiin di tempat lain
        {
            printf("Upgrade tidak terdaftar. Silahkan ketik upgrade yang ada di daftar upgrade");
        }
        else
        {
            UpgradeAda = true;
        }
    }
    if (IsResourceAda(input)) //fungsi ini nanti didefinisiin di tempat lain
    {
        printf("Material tidak mencukupi. Silahkan membeli material terlebih dahulu.");
    }
    else
    {
        printPetaLegenda(); //fungsi ini nanti didefinisiin di tempat lain
        TAksi(*St)+=1;
        TTime(*St) += DurasiUpgrade(input); //fungsi ini nanti didefinisiin di tempat lain
        MoneyNeed(*St) = BiayaUpgrade(input); //fungsi ini nanti didefinisiin di tempat lain
        printf("//Memasukkan perintah"); printf(input); printf("untuk lokasi "); printf(printLokasi(Titik)); printf(" pada stack//");
        printf("Wahana pada lokasi "); printf(printLokasi(Titik)); printf("berubah menjadi "); printf(input); printf("//");
        Push(S,Aksi); //belum, perlu diskusi dan koordinasi sama yg ngerjain map biar buildingnya bisa dioutputin ke peta
    }
    
}

void buy (Stack *S, State *St)
{
    //Daftar bahan bangunan memakai ADT LIST IMPLEMENTASI ARRAY
    char *input;
    printf("Ingin membeli apa?\n");
    printf("List:\n");
    printDaftarBangunan(); //fungsi ini nanti didefinisiin di tempat lain
    scanf("%c", &input);
    if (Money(*St)<HargaBangunan(input)) //fungsi ini nanti didefinisiin di tempat lain
    {
        printf("Uang Anda tidak cukup. Silahkan Mencari Uang lagi.");
    }
    else 
    {
        printPetaLegenda(); //fungsi ini nanti didefinisiin di tempat lain
        TAksi(*St)+=1;
        TTime(*St) += DurasiBuy(input); //fungsi ini nanti didefinisiin di tempat lain
        MoneyNeed(*St) = BiayaBuy(input); //fungsi ini nanti didefinisiin di tempat lain
        printf("// Memasukkan perintah membeli "); printf(Bahan()); printf(" sebanyak "); printf(jumlah()); printf(" pada stack //");
        Push(S,Aksi); //belum, perlu diskusi 
    }
    
}

