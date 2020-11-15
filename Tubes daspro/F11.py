import csv
import globals as g

def lihat_kritik_saran():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    #apabila bukan admin
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;

    #apabila sudah login dan merupakan admin
    i=1 #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_Kritik[i][0] != '*' and i < 1000):  #mark ketika membaca '*' atau lebih dari 1000 data
        #mengurutkan data menggunakan bubble sort
        j=i+1
        while (g.array_File_Kritik[j][0] != '*' and j < 1000):
            if (g.array_File_Kritik[i][2]>g.array_File_Kritik[j][2]):
                tmp = g.array_File_Kritik[i]
                g.array_File_Kritik[i]=g.array_File_Kritik[j]
                g.array_File_Kritik[j]=tmp
            j+=1
        i+=1

    #menampilkan kritik dan saran
    print("Kritik dan Saran:")
    i=0
    while (g.array_File_Kritik[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        print(g.array_File_Kritik[i][2], "|", g.array_File_Kritik[i][1], "|", g.array_File_Kritik[i][0], "|", g.array_File_Kritik[i][3])
        i+=1
        #output yang ditampilkan berupa "ID Wahana | Tanggal Pelaporan | Username Pemain | Isi kritik dan saran"
