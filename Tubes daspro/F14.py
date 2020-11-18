import csv
import globals as g
def Riwayat_Wahana():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    #apabila bukan admin
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;
    Cari_ID_Wahana = input("Masukkan ID wahana: ")
    print("Riwayat:")
    found=False
    i=0
    while (g.array_File_Penggunaan[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Penggunaan[i][2]==Cari_ID_Wahana):
            found=True
            print(g.array_File_Penggunaan[i][1], "|", g.array_File_Penggunaan[i][0], "|", g.array_File_Penggunaan[i][3])
        i+=1

    #apabila belum pernah digunakan
    if(not(found)):
        print("Wahana yang Anda cari tidak pernah digunakan.")
