import csv
import globals as g

def updatedatakepemilikan(username, id, tiket):
    kepemilik = 1
    #merewrite data kepemilikan jika terdapat kecocokan username dan id
    while (g.array_File_Kepemilikan[kepemilik][0]!='*' and kepemilik<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Kepemilikan[kepemilik][0]==username and g.array_File_Kepemilikan[kepemilik][1]==id):
            curr = int(g.array_File_Kepemilikan[kepemilik][2])
            g.array_File_Kepemilikan[kepemilik][2]= curr - int(tiket)
            if(int(g.array_File_Kepemilikan[kepemilik][2])==0):
                while (g.array_File_Kepemilikan[kepemilik][0]!='*' and kepemilik+1<1000):
                    g.array_File_Kepemilikan[kepemilik][0] = g.array_File_Kepemilikan[kepemilik+1][0]
                    g.array_File_Kepemilikan[kepemilik][1] = g.array_File_Kepemilikan[kepemilik+1][1]
                    g.array_File_Kepemilikan[kepemilik][2] = g.array_File_Kepemilikan[kepemilik+1][2]
                    kepemilik+=1
            break
        kepemilik += 1

def Main_Wahana():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return
    found=False
    tiketcukup=False
    idwahana = input("Masukkan ID wahana: ")
    tanggalmain = input("Masukkan tanggal hari ini: ")
    tiketpakai = int(input("Masukkan tiket yang digunakan: "))
    jumlahtiketuser=-1
    #mencari jumlah tiket user
    kepemilik = 1
    while (g.array_File_Kepemilikan[kepemilik][0]!='*' and kepemilik<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Kepemilikan[kepemilik][0] == g.User_Username and g.array_File_Kepemilikan[kepemilik][1] == idwahana):
            jumlahtiketuser = int(g.array_File_Kepemilikan[kepemilik][2])
            break
        kepemilik += 1

    #eksekusi
    if (jumlahtiketuser >= tiketpakai):
        gunake = 1
        while(g.array_File_Penggunaan[gunake][0]!='*' and gunake<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (g.array_File_Penggunaan[gunake][0]==g.User_Username and g.array_File_Penggunaan[gunake][1]==tanggalmain and g.array_File_Penggunaan[gunake][2] == idwahana):
                curr = int(g.array_File_Penggunaan[gunake][3])
                g.array_File_Penggunaan[gunake][3] = curr + tiketpakai
                found=True
                gunake += 1
                break
            else:
                gunake += 1

        if (not(found)):
            g.array_File_Penggunaan[gunake][0] = g.User_Username
            g.array_File_Penggunaan[gunake][1] = tanggalmain
            g.array_File_Penggunaan[gunake][2] = idwahana
            g.array_File_Penggunaan[gunake][3] = tiketpakai

        updatedatakepemilikan(g.User_Username, idwahana, tiketpakai)
        tiketcukup = True
        print()
        print("Terima kasih telah bermain")

    if(not(tiketcukup)):
        print()
        print("Tiket Anda tidak valid dalam sistem kami")
