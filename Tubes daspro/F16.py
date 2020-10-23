import csv
import globals as g
import F03 as c
def Exit():
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    pilih = str(input("Apakah Anda mau melakukan penyimpanan file yang sudah dilakukan (Y/N)? "))
    #apabila masukan bukan 'Y', 'y', 'N', atau 'n', pemain diminta untuk menginput ulang
    while not (pilih == 'y' or pilih == 'Y' or pilih == 'n' or pilih == 'N'):
        print("Masukan harus berupa Y atau N.")
        pilih = str(input("Apakah Anda mau melakukan penyimpanan file yang sudah dilakukan (Y/N)? "))
    #apabila input berupa 'Y' atau 'y', penyimpanan file dilaksanakan
    #apabila input berupa 'N' atau 'n', penyimpanan file tidak dilaksanakan

    #menyimpan file
    if (pilih == 'Y' or pilih == 'y'):
        c.Save_File()
    #pemain keluar dari program
    g.exit_program = True

    print()
    print("Terima kasih telah menggunakan aplikasi kami!")
