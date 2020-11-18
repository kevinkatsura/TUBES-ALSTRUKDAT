import csv
import globals as g

def Cari_Pemain():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    #apabila bukan admin
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;
    Cari_Username = input("Masukkan username: ")
    found=False
    i=1 #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_User[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[i][3]==Cari_Username):
            print("Nama Pemain: ", g.array_File_User[i][0])
            print("Tinggi Pemain: ", g.array_File_User[i][2], "cm")
            print("Tanggal Lahir Pemain: ", g.array_File_User[i][1])
            found=True #tanda apabila ditemukan
            break;
        i+=1
    #apabila tidak ditemukan
    if (not(found)):
        print()
        print("Pemain Tidak Ditemukan!")
