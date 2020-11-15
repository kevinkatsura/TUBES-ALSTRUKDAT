import csv
import globals as g
#Asumsi semua masukkan valid

def Tambah_Wahana():
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.") #hanya admin yang bisa menggunakan fitur ini
        return;
    print("Masukkan Informasi Wahana yang ditambahkan:")
    ID_Wahana = input("Masukkan ID Wahana: ")
    Nama_Wahana = input("Masukkan Nama Wahana: ")
    Harga_Tiket = int(input("Masukkan Harga Tiket: "))
    Batasan_Umur = input("Batasan umur: ")
    Batasan_Tinggi = input("Batasan tinggi badan: ")
    i=1
    while (g.array_File_Wahana[i][0]!='*' and i<1000):
        i+=1
    g.array_File_Wahana[i]=([ID_Wahana, Nama_Wahana, Harga_Tiket, Batasan_Umur, Batasan_Tinggi]) #menambahkan data wahana baru pada file wahana

    print()
    print("Info wahana telah ditambahkan!")
