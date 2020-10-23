import csv
import globals as g
def dapetinnama(id): #mengembalikan nama wahana
    i = 1  #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_Wahana[i][0] != '*' and i < 1000):  #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Wahana[i][0]==id):
            return g.array_File_Wahana[i][1]
        i+=1
        
def lihat_jumlahtiket():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    #apabila bukan admin
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;
    #apabila sudah login dan merupakan admin
    username = input("Masukkan username: ")  #admin menginput username pemain

    #menampilkan jumlah tiket pemain
    print("Riwayat:")
    i=1 #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_Kepemilikan[i][0] != '*' and i < 1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Kepemilikan[i][0] == username):
            nama=dapetinnama(g.array_File_Kepemilikan[i][1])
            print(g.array_File_Kepemilikan[i][1], '|', nama, "|", g.array_File_Kepemilikan[i][2])
        i+=1
       #output berupa "ID Wahana | Nama Wahana | Jumlah Tiket"
