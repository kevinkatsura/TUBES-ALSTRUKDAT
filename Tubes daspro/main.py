import csv
import F01 as a
import F02 as b
import F03 as c
import F04 as d
import F05 as e
import F06 as f
import F07 as g
import F08 as h
import F09 as i
import F10 as j
import F11 as k
import F12 as l
import F13 as m
import F14 as n
import F15 as o
import F16 as p
import B02 as q
import B03 as r
import B04 as s
import globals as Glob

# a.Load_File()
# d.Login_User()
# c.Sign_Up(Glob.User_Role)
# e.Cari_Pemain(Glob.User_Role)
# f.Cari_Wahana()
# g.beli_tiket()
# h.Main_Wahana()
# i.refund()
# j.kritik_saran()
# k.lihat_kritik_saran()
# l.Tambah_Wahana()
# m.Top_up()
# n.Riwayat_Pemain(Glob.User_Role)
# o.lihat_jumlahtiket(Glob.User_Role)
# b.Save_File()
# p.Exit()

print("  _   _   _   _   _   _   _     _   _   _   _   _   _")
print(" / \ / \ / \ / \ / \ / \ / \   / \ / \ / \ / \ / \ / \ ")
print("( S | e | l | a | m | a | t ) ( D | a | t | a | n | g )")
print(" \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ \_/ \_/ \_/ \_/ \_/ ")


print(" _       ___ ____         _       __                  __")
print("| |     / (_) / /_  __   | |     / /___ _____  ____ _/ /____  __")
print("| | /| / / / / / / / /   | | /| / / __ `/ __ \/ __ `/ //_/ / / /")
print("| |/ |/ / / / / /_/ /    | |/ |/ / /_/ / / / / /_/ / ,< / /_/ /")
print("|__/|__/_/_/_/\__, /     |__/|__/\__,_/_/ /_/\__, /_/|_|\__, /")
print("             /____/                         /____/     /____/")

Glob.initialize()
while (not(Glob.exit_program)):
    print()
    aktivitas = input("$ ")
    if (aktivitas == "load"):
        a.Load_File()
    elif(aktivitas == "login"):
        b.Login_User()
    elif(aktivitas == "save"):
        c.Save_File()
    elif(aktivitas == "signup"):
        d.Sign_Up()
    elif(aktivitas == "cari_pemain"):
        e.Cari_Pemain()
    elif(aktivitas == "cari"):
        f.Cari_Wahana()
    elif(aktivitas == "beli_tiket"):
        g.beli_tiket()
    elif(aktivitas == "main"):
        h.Main_Wahana()
    elif(aktivitas == "refund"):
        i.refund()
    elif(aktivitas == "kritik_saran"):
        j.kritik_saran()
    elif(aktivitas == "lihat_laporan"):
        k.lihat_kritik_saran()
    elif(aktivitas == "tambah_wahana"):
        l.Tambah_Wahana()
    elif(aktivitas == "topup"):
        m.Top_up()
    elif(aktivitas == "riwayat_wahana"):
        n.Riwayat_Wahana()
    elif(aktivitas == "tiket_pemain"):
        o.lihat_jumlahtiket()
    elif(aktivitas == "exit"):
        p.Exit()
        sudahexit = True
    elif(aktivitas == "upgrade_gold"):
        q.upgrade_gold()
    elif (aktivitas == "best_wahana"):
        r.best_wahana()
    elif (aktivitas == "tiket_hilang"):
        s.Hilang_Tiket()

print("+-+-+-+-+-+-+ +-+-+-+-+-+")
print("|S|a|m|p|a|i| |J|u|m|p|a|")
print("+-+-+-+-+-+-+ +-+-+-+-+-+")
