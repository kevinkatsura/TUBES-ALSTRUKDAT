import csv
import globals as g
def Load_File():
    Nama_File = input("Masukkan nama File User: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_User[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Daftar Wahana: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Wahana[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Pembelian Tiket: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Pembelian[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Penggunaan Tiket: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Penggunaan[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Kepemilikan Tiket: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Kepemilikan[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Refund Tiket: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Refund[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Kritik dan Saran: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
    #menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Kritik[i][j]=column
            j+=1
        i+=1
    output_File.close()

    Nama_File = input("Masukkan nama File Kehilangan Tiket: ")
    output_File = open(Nama_File, 'r', newline='', encoding="utf8")
    reader_File = csv.reader(output_File, delimiter=';')
#menyalin satu per satu data ke array
    i=0
    for row in reader_File:
        j=0
        for column in row:
            g.array_File_Kehilangan[i][j]=column
            j+=1
        i+=1
    output_File.close()

    print()
    print("File perusahaan Willy Wangky’s Chocolate Factory telah di-load.")
