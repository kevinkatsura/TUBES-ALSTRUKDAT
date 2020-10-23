import csv
import globals as g
import F01 as a
csv.register_dialect("titikkoma", delimiter=";")

def Save_File():
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    Nama_File = input("Masukkan nama File User: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_User[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_User[i][0],g.array_File_User[i][1],g.array_File_User[i][2],g.array_File_User[i][3],
        g.array_File_User[i][4],g.array_File_User[i][5],g.array_File_User[i][6],g.array_File_User[i][7])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Daftar Wahana: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Wahana[i][0]!='*' and i < 1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Wahana[i][0],g.array_File_Wahana[i][1],g.array_File_Wahana[i][2],g.array_File_Wahana[i][3],
        g.array_File_Wahana[i][4])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Pembelian Tiket: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Pembelian[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Pembelian[i][0],g.array_File_Pembelian[i][1],g.array_File_Pembelian[i][2],g.array_File_Pembelian[i][3])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Penggunaan Tiket: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Penggunaan[i][0]!='*' and i <1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Penggunaan[i][0],g.array_File_Penggunaan[i][1],g.array_File_Penggunaan[i][2],g.array_File_Penggunaan[i][3])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Kepemilikan Tiket: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save= csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Kepemilikan[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Kepemilikan[i][0],g.array_File_Kepemilikan[i][1],g.array_File_Kepemilikan[i][2])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Refund Tiket: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Refund[i][0]!='*' and i < 1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Refund[i][0],g.array_File_Refund[i][1],g.array_File_Refund[i][2],g.array_File_Refund[i][3])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Kritik dan Saran: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Kritik[i][0]!='*' and i <1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Kritik[i][0],g.array_File_Kritik[i][1],g.array_File_Kritik[i][2],g.array_File_Kritik[i][3])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()

    Nama_File = input("Masukkan nama File Kehilangan Tiket: ")
    File_Save = open(Nama_File, 'w', newline='', encoding="utf8")
    writer_Save = csv.writer(File_Save, dialect="titikkoma")
    #menyalin data array ke dalam file writer
    i=0
    while (g.array_File_Kehilangan[i][0]!='*' and i <1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tmp=(g.array_File_Kehilangan[i][0],g.array_File_Kehilangan[i][1],g.array_File_Kehilangan[i][2],g.array_File_Kehilangan[i][3])
        writer_Save.writerow(tmp)
        i+=1
    File_Save.close()
    print()
    print("Data berhasil disimpan!")
