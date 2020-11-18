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

def updatedatauser(username, saldo):
    userke = 1
    #merewrite data user saldo
    while (g.array_File_User[userke][0]!='*' and userke<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_User[userke][3]==username):
            curr = int(g.array_File_User[userke][6])
            g.array_File_User[userke][6] = curr + int(saldo)
            g.User_Saldo = g.array_File_User[userke][6]
            break
        userke += 1

def refund():
    #apabila belum login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return
    userpunyatiket = False
    idwahana = input("Masukkan ID wahana: ")
    tanggalrefund = input("Masukkan Tanggal Refund: ") #file refund ada tanggal refund
    tiketrefund = int(input("Jumlah tiket yang di-refund: "))

    #mencari jumlah tiket user
    kepemilik = 1
    while (g.array_File_Kepemilikan[kepemilik][0]!='*' and kepemilik<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Kepemilikan[kepemilik][0]==g.User_Username and g.array_File_Kepemilikan[kepemilik][1]==idwahana):
            userpunyatiket = True
            jumlahtiketuser = int(g.array_File_Kepemilikan[kepemilik][2])
            break
        kepemilik += 1

    #mencari harga tiket wahana
    wahanake = 1
    while (g.array_File_Wahana[wahanake][0]!='*' and wahanake<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        if (g.array_File_Wahana[wahanake][0] == idwahana):
            hargatiket = int(g.array_File_Wahana[wahanake][2]) * tiketrefund
            break
        wahanake += 1

    #eksekusi
    if (userpunyatiket and jumlahtiketuser >= tiketrefund):
        found = False
        refundke = 1
        while (g.array_File_Refund[refundke][0]!='*' and refundke<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (g.array_File_Refund[refundke][0]==g.User_Username and g.array_File_Refund[refundke][1]==tanggalrefund and g.array_File_Refund[refundke][2] == idwahana):
                curr = int(g.array_File_Refund[refundke][3])
                g.array_File_Refund[refundke][3] = curr + int(tiketrefund)
                found = True
                refundke += 1
                break
            else:
                refundke += 1

        if(not(found)):
            g.array_File_Refund[refundke][0] = g.User_Username
            g.array_File_Refund[refundke][1] = tanggalrefund
            g.array_File_Refund[refundke][2] = idwahana
            g.array_File_Refund[refundke][3] = int(tiketrefund)

        updatedatakepemilikan(g.User_Username, idwahana, tiketrefund)
        updatedatauser(g.User_Username, hargatiket)
        print()
        print("Uang refund sudah kami berikan pada akun Anda.")
    else:
        print()
        print("Anda tidak memiliki tiket terkait.")
