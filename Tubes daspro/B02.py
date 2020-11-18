import csv
import globals as g

def update_data(username,biaya_golden): #update data saldo pemain
    i=1  #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_User[i][0] != '*' and i < 1000):  #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[i][3] == username):
            #saldo pemain dikurangi dengan biaya_golden
            g.array_File_User[i][6] = int(g.array_File_User[i][6])-biaya_golden
            break
        i+=1

def upgrade_gold():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return;
    #apabila bukan admin
    if (g.User_Role=="Pemain"):
        print("Anda tidak dapat menggunakan fitur ini! Silakan hubungi admin untuk menggunakan fitur ini.")
        return;

    #apabila sudah login dan merupakan admin
    username = input("Masukkan username yang ingin di-upgrade: ")  #admin menginput username pemain
    #misalkan biaya untuk upgrade ke golden account adalah 100000
    biaya_golden = 100000
    i=1  #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_User[i][0] != '*' and i < 1000):  #mark ketika membaca '*' atau lebih dari 1000 data
        #apabila akun pemain belum golden account
        if (g.array_File_User[i][3] == username) and (g.array_File_User[i][7] == "False"):
            #apabila saldo mencukupi
            if (int(g.array_File_User[i][6]) >= biaya_golden):
                g.array_File_User[i][7] = True  #akun pemain diupgrade ke golden account
                #mengupdate data saldo pemain
                update_data(username,biaya_golden)
                print()
                print("Akun Anda telah diupgrade.")
                break
            else: #saldo tidak cukup
                print()
                print("Saldo Anda tidak cukup")
                print("Silakan mengisi saldo Anda")
                break
        #apabila akun pemain sudah golden account
        elif (g.array_File_User[i][3] == username) and (g.array_File_User[i][7] == "True"):
            print()
            print("Akun Anda sudah terdaftar sebagai golden account.")
            break
        i+=1
