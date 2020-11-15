import csv
import globals as g
import B01 as rahasia

def Sign_Up():
    if (not(g.Login_success)):
        print("Silakan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.") #hanya admin yang bisa menggunakan fitur ini
        return;
    Nama = input("Masukkan nama pemain: ")
    Tanggal_Lahir = input("Masukkan tanggal lahir pemain (DD/MM/YYYY): ")
    Tinggi_Badan = input("Masukkan tinggi badan pemain (cm): ")
    daftar = False
    while (not daftar) :
        Username = input("Masukkan username pemain: ")
        daftar=True
        #mengecek apakah username yang akan digunakan sudah terdaftar atau belum
        i=1 #dimulai dari 1 karena pada i=0 merupakan header file
        while (g.array_File_User[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (g.array_File_User[i][3]==Username):
                print("Username sudah digunakan") #bila username yang akan digunakan sudah terdaftar
                daftar=False
                break
            i+=1
    Password = input("Masukkan password pemain: ")
    Password = rahasia.enkripsi(Password) #menyimpan password
    g.array_File_User[i]=([Nama,Tanggal_Lahir,Tinggi_Badan,Username,Password,"Pemain", 0, False]) #meambahkan data user baru ke file user.csv
    print()
    print("Selamat menjadi pemain, Willy Wangky. Selamat bermain.")
