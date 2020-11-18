import csv
import globals as g

def umurorang(tanggal1, tanggal2):
    #mengubah tanggal awal menjadi jumlah hari
    hari1 = int(tanggal1[0]) * 10 + int(tanggal1[1])
    bulanawal = int(tanggal1[3]) * 10 + int(tanggal1[4])
    tahun1 = int(tanggal1[6]) * 1000 + int(tanggal1[7]) * 100 + int(tanggal1[8]) * 10 + int(tanggal1[9])
    bulan1 = 0
    for i in range(1, bulanawal):
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12):
            bulan1 += 31
        elif (i == 4 or i == 6 or i == 9 or i == 11):
            bulan1 += 30
        elif (i == 2):
            bulan1 += 28
    tahun1 = tahun1 * 365

    #mengubah tanggal akhir menjadi jumlah hari
    hari2 = int(tanggal2[0]) * 10 + int(tanggal2[1])
    bulanakhir = int(tanggal2[3]) * 10 + int(tanggal2[4])
    tahun2 = int(tanggal2[6]) * 1000 + int(tanggal2[7]) * 100 + int(tanggal2[8]) * 10 + int(tanggal2[9])
    bulan2 = 0
    for j in range(1, bulanakhir):
        if (j == 1 or j == 3 or j == 5 or j == 7 or j == 8 or j == 10 or j == 12):
            bulan2 += 31
        elif (j == 4 or j == 6 or j == 9 or j == 11):
            bulan2 += 30
        elif (j == 2):
            bulan2 += 28
    tahun2 = tahun2 * 365

    #menghitung selisih dari tanggal akhir dan tanggal awal
    jumlahhari = (hari2 + bulan2 + tahun2) - (hari1 + bulan1 + tahun1)
    return jumlahhari // 365

def updatedatakepemilikan(username, id, tiket):
    found=False
    kepemilik = 1
    #merewrite data kepemilikan jika terdapat kecocokan username dan id
    while (g.array_File_Kepemilikan[kepemilik][0]!='*' and kepemilik<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Kepemilikan[kepemilik][0]==username and g.array_File_Kepemilikan[kepemilik][1]==id):
            curr = int(g.array_File_Kepemilikan[kepemilik][2])
            g.array_File_Kepemilikan[kepemilik][2]= curr + int(tiket)
            found=True
            kepemilik += 1
            break
        else:
            kepemilik += 1

    #menambah data kepemilikan jika tidak ditemukan kecocokan sebelumnya
    if (not(found)):
        g.array_File_Kepemilikan[kepemilik][0] = username
        g.array_File_Kepemilikan[kepemilik][1] = id
        g.array_File_Kepemilikan[kepemilik][2] = int(tiket)

def updatedatauser(username, saldo):
    userke = 1
    #merewrite data user saldo
    while (g.array_File_User[userke][0]!='*' and userke<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[userke][3]==username):
            curr = int(g.array_File_User[userke][6])
            g.array_File_User[userke][6]=curr-int(saldo)
            g.User_Saldo=g.array_File_User[userke][6]
            break
        userke += 1

def beli_tiket():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return
    idwahana = input("Masukkan ID wahana: ")
    tanggalbeli = input("Masukkan tanggal hari ini: ")
    jumlahtiket = int(input("Jumlah tiket yang dibeli: "))
    found=False
    #mendefinisikan syarat tiap wahana
    wahanake = 1
    while (g.array_File_Wahana[wahanake][0]!='*' and wahanake<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Wahana[wahanake][0] == idwahana):
            batasumur = g.array_File_Wahana[wahanake][3]
            batastinggi = g.array_File_Wahana[wahanake][4]
            hargatiket = int(g.array_File_Wahana[wahanake][2])
            namawahana = g.array_File_Wahana[wahanake][1]
            found=True
            break
        wahanake += 1

    if (not(found)):
        print()
        print("ID Wahana tidak valid.")
        return

    found=False

    #mengecek status golden user
    if (g.User_Golden == "True"):
        hargatiket = (0.5*hargatiket)*jumlahtiket
    else:
        hargatiket *=jumlahtiket

    #mendefinisikan kondisi user
    umur = umurorang(g.User_Tanggal_Lahir, tanggalbeli)
    kriteriatinggi=False
    kriteriaumur=False
    kriteriasaldo=False

    #membandingkan kondisi user dengan syarat wahana
    if (int(g.User_Saldo) >= hargatiket):
        kriteriasaldo=True

    if (batastinggi==">=170cm" and int(g.User_Tinggi_Badan)>=170):
        kriteriatinggi=True
    elif (batastinggi=="tanpa batasan"):
        kriteriatinggi=True

    if (batasumur == 'semua umur'):
        kriteriaumur=True
    elif (batasumur == 'dewasa' and umur>=17):
        kriteriaumur = True
    elif (batasumur == 'anak-anak' and umur<17):
        kriteriaumur=True

    #eksekusi
    if (kriteriaumur and kriteriatinggi and kriteriasaldo):
        found = False
        belike = 1
        while (g.array_File_Pembelian[belike][0]!='*' and belike<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (g.array_File_Pembelian[belike][0]==g.User_Username and g.array_File_Pembelian[belike][1]==tanggalbeli and g.array_File_Pembelian[belike][2] == idwahana):
                curr = int(g.array_File_Pembelian[belike][3])
                g.array_File_Pembelian[belike][3] = curr + int(jumlahtiket)
                found = True
                belike += 1
                break
            else:
                belike += 1

        if(not(found)):
            g.array_File_Pembelian[belike][0] = g.User_Username
            g.array_File_Pembelian[belike][1] = tanggalbeli
            g.array_File_Pembelian[belike][2] = idwahana
            g.array_File_Pembelian[belike][3] = int(jumlahtiket)

        updatedatakepemilikan(g.User_Username, idwahana, jumlahtiket)
        updatedatauser(g.User_Username, hargatiket)
        print()
        print("Selamat bersenang-senang di", namawahana)
    elif (not(kriteriaumur) or not(kriteriatinggi)):
        print()
        print("Anda tidak memenuhi persyaratan untuk memainkan wahana ini.")
        print("Silahkan menggunakan wahana lain yang tersedia.")
    elif (not(kriteriasaldo)):
        print()
        print("Saldo Anda tidak cukup")
        print("Silakan mengisi saldo Anda")
