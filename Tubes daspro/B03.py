import csv
import globals as g

def best_wahana():
    #mengecek apakah sudah login
    if (not(g.Login_success)):
        print("Silahkan login terlebih dahulu untuk menggunakan fitur ini.")
        return

    #membuat list baru
    listbest = [['*' for j in range(3)] for i in range(1000)]

    #mengisi list baru
    wahanake = 1
    while (g.array_File_Wahana[wahanake][0]!='*' and wahanake<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        tiketbaru = 0
        belike = 1
        while (g.array_File_Pembelian[belike][0]!='*' and belike<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (g.array_File_Wahana[wahanake][0] == g.array_File_Pembelian[belike][2]):
                tiketbaru += int(g.array_File_Pembelian[belike][3])
                belike += 1
            else:
                belike += 1

        listbest[wahanake][0] = g.array_File_Wahana[wahanake][0]
        listbest[wahanake][1] = g.array_File_Wahana[wahanake][1]
        listbest[wahanake][2] = tiketbaru
        wahanake += 1

    #megurutkan listbest
    i = 1
    while (listbest[i][0]!='*' and i<1000): #mark ketika membaca '*' atau lebih dari 1000 data
        j=i+1
        while (listbest[j][0]!='*' and j<1000): #mark ketika membaca '*' atau lebih dari 1000 data
            if (listbest[j][2] > listbest[i][2]):
                tmp = listbest[j]
                listbest[j] = listbest[i]
                listbest[i] = tmp
            j += 1
        i += 1

    #menampilkan listbest 3 wahana
    for i in range(1,4):
        print(i, "|", listbest[i][0], "|", listbest[i][1], "|", listbest[i][2])
