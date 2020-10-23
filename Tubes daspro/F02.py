import csv
import globals as g
import B01 as rahasia

def Login_User():
    if (g.Login_success):
        print()
        print("Anda sudah login.")
        return;
        #apabila g.Login_Succes bernilai True, kembali ke program utama
        #apabila g.Login_Succes bernilai False, prosedur login dilanjutkan
    g.User_Username = input("Masukkan username: ")
    g.User_Password = input("Masukkan password: ")
    g.User_Password = rahasia.enkripsi(g.User_Password)  #password dienkripsi

    i=1 #dimulai dari 1 karena pada i=0 merupakan header file
    while (g.array_File_User[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[i][3]==g.User_Username and g.User_Password == g.array_File_User[i][4]):
            #apabila username dan password sinkron dan terdaftar dalam sistem, login berhasil
            g.Login_success = True
            #memasukkan semua data pemain yang bersangkutan dari g.array_File_User
            g.User_Nama = g.array_File_User[i][0]
            g.User_Tanggal_Lahir = g.array_File_User[i][1]
            g.User_Tinggi_Badan = g.array_File_User[i][2]
            g.User_Role = g.array_File_User[i][5]
            g.User_Saldo = g.array_File_User[i][6]
            g.User_Golden = g.array_File_User[i][7]
            print("Selamat bersenang-senang, Willy Wangky!")
            break;
        i+=1

    #apabila login belum berhasil
    if (not(g.Login_success)):
        print()
        print("Ups, password salah atau kamu tidak terdaftar dalam sistem kami. Silakan coba lagi!")

#g.Login_succes bernilai True apabila login berhasil, bernilai False apabila belum berhasil
