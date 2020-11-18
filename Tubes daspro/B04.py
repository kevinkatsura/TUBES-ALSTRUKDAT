import csv
import globals as g
#asumsi semua input benar

#fungsi untuk melakukan update data pada file kepemilikan
def update_data(uname, idwahana, tiket):
    i=1
    while (g.array_File_Kepemilikan[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if ((g.array_File_Kepemilikan[i][0] == uname) and (g.array_File_Kepemilikan[i][1] == idwahana)):
            current_tiket = int(g.array_File_Kepemilikan[i][2])
            current_tiket -= tiket
            g.array_File_Kepemilikan[i][2] = current_tiket
            if(int(g.array_File_Kepemilikan[i][2])==0):
                while (g.array_File_Kepemilikan[i][0]!='*' and i+1<1000):
                    g.array_File_Kepemilikan[i][0] = g.array_File_Kepemilikan[i+1][0]
                    g.array_File_Kepemilikan[i][1] = g.array_File_Kepemilikan[i+1][1]
                    g.array_File_Kepemilikan[i][2] = g.array_File_Kepemilikan[i+1][2]
                    i+=1
            break
        i+=1

def Hilang_Tiket():
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    hilang_username = input("Masukkan username: ")
    hilang_tanggal = input("Tanggal kehilangan tiket: ")
    hilang_id = input("ID wahana: ")
    hilang_tiket = int(input("Jumlah tiket yang dihilangkan: "))

    #mengsisi laporan kehilangan pada file kehilangan.csv
    i=1
    while (g.array_File_Kehilangan[i][0]!='*' and i<1000):
        i+=1 #mendapatkan indeks terakhir
    g.array_File_Kehilangan[i]=([g.User_Username, hilang_tanggal, hilang_id, hilang_tiket])

    #melakukan update jumlah tiket yang dimiliki pada file kepemilikan.csv
    i = 1
    while (g.array_File_Kepemilikan[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if ((g.array_File_Kepemilikan[i][0] == hilang_username) and (g.array_File_Kepemilikan[i][1] == hilang_id)):
            update_data(hilang_username, hilang_id, hilang_tiket)
            break
        i += 1

    print()
    print("Laporan kehilangan tiket Anda telah direkam.")
