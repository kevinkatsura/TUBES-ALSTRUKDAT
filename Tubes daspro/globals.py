def initialize():
    #array sebagai penyimpan isi file sementara
    #array diisi dengan mark semua sehingga dapat dengan mudah melacak posisi akhir data
    global array_File_User
    array_File_User=[['*' for j in range(8)] for i in range(1000)]
    global array_File_Wahana
    array_File_Wahana=[['*' for j in range(5)] for i in range(1000)]
    global array_File_Pembelian
    array_File_Pembelian=[['*' for j in range(4)] for i in range(1000)]
    global array_File_Penggunaan
    array_File_Penggunaan=[['*' for j in range(4)] for i in range(1000)]
    global array_File_Kepemilikan
    array_File_Kepemilikan=[['*' for j in range(3)] for i in range(1000)]
    global array_File_Refund
    array_File_Refund=[['*' for j in range(4)] for i in range(1000)]
    global array_File_Kritik
    array_File_Kritik=[['*' for j in range(4)] for i in range(1000)]
    global array_File_Kehilangan
    array_File_Kehilangan=[['*' for j in range(4)] for i in range(1000)]

    #menyimpan keadaan login
    global Login_success
    Login_success=False

    #menyimpan info dari user yang telah login
    global User_Nama
    global User_Tanggal_Lahir
    global User_Tinggi_Badan
    global User_Username
    global User_Password
    global User_Role
    global User_Saldo
    global User_Golden

    #mengubah kondisi program ketika ingin keluar
    global exit_program
    exit_program = False
