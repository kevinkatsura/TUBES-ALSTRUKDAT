import csv
import globals as g
#asumsi semua masukan valid

def Top_up():
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;
    topup_username = input("Masukkan username: ")
    topup_saldo = int(input("Masukkan saldo yang di-top up: "))
    i=1
    while (g.array_File_User[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[i][3]==topup_username):
            #bila username yang dimasukkan terdapat pada file user maka akan dilakukan top up saldo
            current_saldo = int(g.array_File_User[i][6]) #mengambil jumlah saldo terakhir yang dimiliki pengguna
            current_saldo += topup_saldo #menambahkan saldo terakhir pengguna dengan jumlah yang di top up
            g.array_File_User[i][6]=current_saldo # mengembalikan nilai saldo yang sudah di top up ke file user
            break
        i+=1
    print()
    print("Top up berhasil. Saldo Willy Wangky bertambah menjadi "+str(current_saldo)) #menampilkan saldo terbaru
