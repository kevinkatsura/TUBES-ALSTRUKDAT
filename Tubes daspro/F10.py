import csv
import globals as g

def kritik_saran():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return
    idwahana = input("Masukkan ID Wahana: ")
    tanggallapor = input("Masukkan tanggal pelaporan: ")
    isikritik = input("Kritik/saran Anda: ")

    #mengisi file
    kritike = 1
    while (g.array_File_Kritik[kritike][0]!='*' and kritike<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        kritike += 1
    g.array_File_Kritik[kritike][0] = g.User_Username
    g.array_File_Kritik[kritike][1] = tanggallapor
    g.array_File_Kritik[kritike][2] = idwahana
    g.array_File_Kritik[kritike][3] = isikritik
    print()
    print("Kritik dan saran Anda kami terima.")
