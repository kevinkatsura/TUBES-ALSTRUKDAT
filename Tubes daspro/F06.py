import csv
import globals as g

def Cari_Wahana():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    print("Jenis batasan umur:")
    print("1. Anak-anak (<17 tahun)")
    print("2. Dewasa (>=17 tahun)")
    print("3. Semua umur")
    print()
    print("Jenis batasan tinggi badan:")
    print("1. Lebih dari 170 cm")
    print("2. Tanpa batasan")
    print()
    Cari_Batas_Umur = input("Batasan umur pemain: ")
    while (Cari_Batas_Umur != "3" and Cari_Batas_Umur != "2" and Cari_Batas_Umur != "1" ): #ulangi input hingga valid
        print("Batasan umur tidak valid!")
        Cari_Batas_Umur = input("Batasan umur pemain: ")
    Cari_Batas_Tinggi = input("Batasan tinggi badan: ")
    while (Cari_Batas_Tinggi != "2" and Cari_Batas_Tinggi != "1" ): #ulangi input hingga valid
        print("Batasan tinggi tidak valid! ")
        Cari_Batas_Tinggi = input("Batasan tinggi badan: ")

    if (Cari_Batas_Umur=="1"):
        Cari_Batas_Umur="anak-anak"
    elif (Cari_Batas_Umur=="2"):
        Cari_Batas_Umur="dewasa"
    elif (Cari_Batas_Umur=="3"):
        Cari_Batas_Umur="semua umur"

    if (Cari_Batas_Tinggi=="1"):
        Cari_Batas_Tinggi=">=170cm"
    elif (Cari_Batas_Tinggi=="2"):
        Cari_Batas_Tinggi="tanpa batasan"

    cnt=0
    print()
    print("Hasil Pencarian:")
    i=0
    while (g.array_File_Wahana[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Wahana[i][3]==Cari_Batas_Umur and g.array_File_Wahana[i][4]==Cari_Batas_Tinggi):
            cnt+=1;
            print(g.array_File_Wahana[i][0], "|", g.array_File_Wahana[i][1], "|", g.array_File_Wahana[i][2])
        i+=1
    #apabila tidak menemukan wahana sama sekali
    if (cnt==0):
        print("Tidak ada wahana yang sesuai dengan pencarian kamu.")
