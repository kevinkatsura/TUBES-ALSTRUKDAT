#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "mesin/mesinkata.h"
#include "state/state.h"
#include "stackP/stackP.h"
#include "ListforDetail.h"

int main(){
	MATRIKS M1;
	MATRIKS M2;
	MATRIKS M3;
	MATRIKS M4;
	MakeMATRIKS(&M1,"../test/map1.txt");
	MakeMATRIKS(&M2,"../test/map2.txt");
	MakeMATRIKS(&M3,"../test/map3.txt");
	MakeMATRIKS(&M4,"../test/map4.txt");
	int i,j;
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			Lokasi(M1,i,j)=MakePoint(j+NKol(M2),i);
		}
	}
	
	for (i=0;i<NBrs(M2);i++){
		for (j=0;j<NKol(M2);j++){
			Lokasi(M2,i,j)=MakePoint(j,i);
		}
	}
	
	for (i=0;i<NBrs(M3);i++){
		for (j=0;j<NKol(M3);j++){
			Lokasi(M3,i,j)=MakePoint(j,i+NBrs(M2));
		}
	}
	
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			Lokasi(M4,i,j)=MakePoint(j+NKol(M2),i+NBrs(M2));
		}
	}
	/*
	for (i=0;i<NBrs(M1);i++){
		for (j=0;j<NKol(M1);j++){
			TulisPOINT(Lokasi(M1,i,j));
		}
		if (i!=NBrs(M1)) {
			printf("\n");
		}
	}*/
	List L ;
	Nomor(L) = 2 ;
	for (i=0;i<NBrs(M2);i++){
		for (j=0;j<NKol(M2);j++){
			if (Info(M2,i,j)=='P'){
				Ordinat(Kordinat(L)) = i ;
				Absis(Kordinat(L)) = j ;
			}
		}
	}
	Current(L)=NilL;
	InsVLast(&L,M2);
	InsVLast(&L,M1);
	InsVLast(&L,M4);
	InsVLast(&L,M3);
	Kata InputPertama, game;
    game.TabKata[0]='.';
    game.TabKata[1]='/';
    game.TabKata[2]='w';
    game.TabKata[3]='i';
    game.TabKata[4]='l';
    game.TabKata[5]='l';
    game.TabKata[6]='y';
    game.TabKata[7]='g';
    game.TabKata[8]='a';
    game.TabKata[9]='m';
    game.TabKata[10]='e';
    game.Length=11;
    printf("Silahkan mengetik './willygame' untuk memulai permainan.\n");
    boolean gamemulai = false;
	while (!gamemulai)
	{
		InputUser(&InputPertama);
		if(IsKataSama(InputPertama,game))
		{
			gamemulai = true;
            printf("// Welcome to Willy wangky's fum factory!!//\n// New game / load game / exit? // \n");
            StackP Perintah;
            CreateEmpty(&Perintah);
            Kata InputKedua;
			ListB LWahana;
            //Queue Antrian;
            
            Kata newk;
            newk.TabKata[0]='n';
            newk.TabKata[1]='e';
            newk.TabKata[2]='w';
            newk.Length = 3;

            Kata exit;
            exit.TabKata[0]='e';
            exit.TabKata[1]='x';
            exit.TabKata[2]='i';
            exit.TabKata[3]='t';
            exit.Length = 4;

            InputUser(&InputKedua);
			if (IsKataSama(InputKedua,newk))
			{
				boolean bermain = true;
                boolean main = false;

                Kata WMove;
                WMove.TabKata[0]='w';
                WMove.Length = 1;

                Kata AMove;
                AMove.TabKata[0]='a';
                AMove.Length = 1;

                Kata SMove;
                SMove.TabKata[0]='s';
                SMove.Length = 1;

                Kata DMove;
                DMove.TabKata[0]='d';
                DMove.Length = 1;

				Kata Kayu;
				Kayu.TabKata[0]='K';
				Kayu.TabKata[1]='a';
				Kayu.TabKata[2]='y';
				Kayu.TabKata[3]='u';
				Kayu.Length = 4;

				Kata Batu;
				Batu.TabKata[0]='B';
				Batu.TabKata[1]='a';
				Batu.TabKata[2]='t';
				Batu.TabKata[3]='u';
				Batu.Length = 4;

				Kata Pasir;
				Pasir.TabKata[0]='P';
				Pasir.TabKata[1]='a';
				Pasir.TabKata[2]='s';
				Pasir.TabKata[3]='i';
				Pasir.TabKata[4]='r';
				Pasir.Length = 5;

				Kata Besi;
				Besi.TabKata[0]='B';
				Besi.TabKata[1]='e';
				Besi.TabKata[2]='s';
				Besi.TabKata[3]='i';
				Besi.Length = 4;

				Kata Semen;
				Semen.TabKata[0]='S';
				Semen.TabKata[1]='e';
				Semen.TabKata[2]='m';
				Semen.TabKata[3]='e';
				Semen.TabKata[4]='n';
				Semen.Length = 5;

                Kata BUILD;
                BUILD.TabKata[0]='b';
                BUILD.TabKata[1]='u';
                BUILD.TabKata[2]='i';
                BUILD.TabKata[3]='l';
                BUILD.TabKata[4]='d';
                BUILD.Length = 5;
                
                Kata UPGRADE;
                UPGRADE.TabKata[0]='u';
                UPGRADE.TabKata[1]='p';
                UPGRADE.TabKata[2]='g';
                UPGRADE.TabKata[3]='r';
                UPGRADE.TabKata[4]='a';
                UPGRADE.TabKata[5]='d';
                UPGRADE.TabKata[6]='e';
                UPGRADE.Length = 7;
                
                Kata BUY;
                BUY.TabKata[0]='b';
                BUY.TabKata[1]='u';
                BUY.TabKata[2]='y';
                BUY.Length = 3;
                
                Kata UNDO;
                UNDO.TabKata[0]='u';
                UNDO.TabKata[1]='n';
                UNDO.TabKata[2]='d';
                UNDO.TabKata[3]='o';
                UNDO.Length = 4;
                
                Kata EXECUTE;
                EXECUTE.TabKata[0]='e';
                EXECUTE.TabKata[1]='x';
                EXECUTE.TabKata[2]='e';
                EXECUTE.TabKata[3]='c';
                EXECUTE.TabKata[4]='u';
                EXECUTE.TabKata[5]='t';
                EXECUTE.TabKata[6]='e';
                EXECUTE.Length = 7;
                
                Kata MAIN;
                MAIN.TabKata[0]='m';
                MAIN.TabKata[1]='a';
                MAIN.TabKata[2]='i';
                MAIN.TabKata[3]='n';
                MAIN.Length = 4;
                
                Kata SERVE;
                SERVE.TabKata[0]='s';
                SERVE.TabKata[1]='e';
                SERVE.TabKata[2]='r';
                SERVE.TabKata[3]='v';
                SERVE.TabKata[4]='e';
                SERVE.Length = 5;
                
                Kata REPAIR;
                REPAIR.TabKata[0]='r';
                REPAIR.TabKata[1]='e';
                REPAIR.TabKata[2]='p';
                REPAIR.TabKata[3]='a';
                REPAIR.TabKata[4]='i';
                REPAIR.TabKata[5]='r';
                REPAIR.Length = 6;
                
                Kata DETAIL;
                DETAIL.TabKata[0]='d';
                DETAIL.TabKata[1]='e';
                DETAIL.TabKata[2]='t';
                DETAIL.TabKata[3]='a';
                DETAIL.TabKata[4]='i';
                DETAIL.TabKata[5]='l';
                DETAIL.Length = 6;
                
                Kata OFFICE;
                OFFICE.TabKata[0]='o';
                OFFICE.TabKata[1]='f';
                OFFICE.TabKata[2]='f';
                OFFICE.TabKata[3]='i';
                OFFICE.TabKata[4]='c';
                OFFICE.TabKata[5]='e';
                OFFICE.Length = 6;
                
                Kata PREPARE;
                PREPARE.TabKata[0]='p';
                PREPARE.TabKata[1]='r';
                PREPARE.TabKata[2]='e';
                PREPARE.TabKata[3]='p';
                PREPARE.TabKata[4]='a';
                PREPARE.TabKata[5]='r';
                PREPARE.TabKata[6]='e';
                PREPARE.Length = 7;
                
                Kata DETAILS;
                DETAILS.TabKata[0]='d';
                DETAILS.TabKata[1]='e';
                DETAILS.TabKata[2]='t';
                DETAILS.TabKata[3]='a';
                DETAILS.TabKata[4]='i';
                DETAILS.TabKata[5]='l';
                DETAILS.TabKata[6]='s';
                DETAILS.Length = 7;
                
                Kata REPORT;
                REPORT.TabKata[0]='R';
                REPORT.TabKata[1]='e';
                REPORT.TabKata[2]='p';
                REPORT.TabKata[3]='o';
                REPORT.TabKata[4]='r';
                REPORT.TabKata[5]='t';
                REPORT.Length = 6;
                
                Kata EXIT;
                EXIT.TabKata[0]='E';
                EXIT.TabKata[1]='x';
                EXIT.TabKata[2]='i';
                EXIT.TabKata[3]='t';
                EXIT.Length = 4;
            
                State Player;
                Kata nama;

                Action AA;
                Materials B;
                ListAction(&AA,"../test/aksi.txt");
                ListMaterial(&B, "../test/material.txt");

				printf("Memulai permainan baru...\n");
                printf("Masukkan nama: ");
                InputUser(&nama);
                printf("\n\n");
				TulisMATRIKS(matriks(Current(L)));
                NewPrepState(&Player,nama);
                PrintPrepState(Player);

				while(bermain)
                {
                    Kata perintah;
                    
                    if (!main)
                    {
						printf("Masukkan perintah: ");
                        InputUser(&perintah);
                        if (IsKataSama(perintah,WMove))
                        {
                            W(&L);
                            TulisMATRIKS(matriks(Current(L)));
                            CurrTime(Player)+=60;
                            PrintPrepState(Player);
                        }
                        else if (IsKataSama(perintah,AMove))
                        {
                            A(&L);
                            TulisMATRIKS(matriks(Current(L)));
                            CurrTime(Player)+=60;
                            PrintPrepState(Player);
                        }
                        else if (IsKataSama(perintah,SMove))
                        {
                            S(&L);
                            TulisMATRIKS(matriks(Current(L)));
                            CurrTime(Player)+=60;
                            PrintPrepState(Player);
                        }
                        else if (IsKataSama(perintah,DMove))
                        {
                            D(&L);
                            TulisMATRIKS(matriks(Current(L)));
                            CurrTime(Player)+=60;
                            PrintPrepState(Player);
                        }
                        else if (IsKataSama(perintah,BUILD))
                        {
                            Kata inputW;
                            infotypeP itP;
                            printf("Ingin membangun apa?\n");
                            printf("List:\n");
                            PrintListWahana("../test/wahana.txt");
                            boolean WahanaAda = false;
                            while (!WahanaAda)
                            {
                                InputUser(&inputW);
                                if (!IsWahanaAda(inputW,"../test/wahana.txt"))
                                {
                                    printf("Wahana tidak terdaftar. Silahkan ketik wahana yang sesuai.");
                                }
                                else
                                {
                                    WahanaAda = true;
                                }
                            }
                            
                            if (!IsResourceAda(Player,inputW,"../test/wahana.txt"))
                            {
                                printf("Resource tidak cukup. Silahkan membeli resource terlebih dahulu dengan perintah buy.\n");
                            }
                            else
                            {
                                if (TimeRem(Player)<(TWaktu(Player)+AA.durasi[0]))
                                {
                                    printf("Anda tidak dapat melakukan perintah build karena waktu tidak mencukupi!");
                                }
                                else
                                {
                                    printf("// Memasukkan perintah: "); PrintKata(perintah);printf(" "); PrintKata(inputW); printf(" ke stack //\n");
                                    InsVLastB(&LWahana,inputW,Kordinat(L));
                                    if (Info(matriks(Current(L)),Ordinat(Kordinat(L))-1,Absis(Kordinat(L)))!='A' && Info(matriks(Current(L)),Ordinat(Kordinat(L))-1,Absis(Kordinat(L)))!='O' && Info(matriks(Current(L)),Ordinat(Kordinat(L))-1,Absis(Kordinat(L)))!='W' && Info(matriks(Current(L)),Ordinat(Kordinat(L))-1,Absis(Kordinat(L)))!='*')
                                    {
                                        W(&L);
                                        Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L))) = 'W';
                                    }
                                    else
                                    {
                                        if (Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))-1)!='A' && Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))-1)!='O' && Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L))-1)!='W' && Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L))-1)!='*') {
                                            A(&L);
                                            Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))+1) = 'W';
                                        }
                                        else
                                        {
                                            if (Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L)))!='A' && Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L)))!='O' && Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L)))!='W' && Info(matriks(Current(L)),Ordinat(Kordinat(L))+1,Absis(Kordinat(L)))!='*'){
                                                S(&L);
                                                Info(matriks(Current(L)),Ordinat(Kordinat(L))-1,Absis(Kordinat(L))) = 'W';
                                            }
                                            else
                                            {
                                                if (Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))+1)!='A' && Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))+1)!='O' && Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))+1)!='W' && Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))+1)!='*'){
                                                    D(&L);
                                                    Info(matriks(Current(L)),Ordinat(Kordinat(L)),Absis(Kordinat(L))-1) = 'W';
                                                }
                                            }  
                                        }
                                    }
                                    TulisMATRIKS(matriks(Current(L)));
                                    TAksi(Player) +=1;
                                    TWaktu(Player) += AA.durasi[0];
                                    TUang(Player) += 1000;
                                    PrintPrepState(Player);
                                    Command(itP) = perintah;
                                    input(itP) = inputW;
                                    lok(itP) = Kordinat(L);
                                    PushP(&Perintah, itP);
                                }
                                
                            }
                        }
                        /*
                        else if(IsKataSama(perintah,UPGRADE))
                        {
                            if (IsWahanaSekitar(L)){
                                Kata inputU;
                                infotypeP itP2;
                                printf("Ingin melakukan upgrade apa?\n");
                                printf("List:\n");
                                PrintListWahana("../test/wahana.txt");
                                boolean UpgradeAda = false;
                                while (!UpgradeAda)
                                {
                                    InputUser(&inputU);
                                    if (!IsWahanaAda(inputU,"../test/wahana.txt"))
                                    {
                                        printf("Upgrade tidak terdaftar. Silahkan ketik upgrade yang ada di list.\n");
                                    }
                                    else
                                    {
                                        UpgradeAda = true;
                                    }
                                }
                                if (!IsResourceAda(Player,inputU,"../test/wahana.txt"))
                                {
                                        printf("Resource tidak cukup. Silahkan membeli resource terlebih dahulu dengan perintah buy\n");
                                }
                                else
                                {
                                    Command(itP2) = perintah;
                                    input(itP2) = inputU;
                                    lok(itP2) = Kordinat(L);
                                    PushP(&Perintah, itP2);
                                }
                            }
                            else
                            {
                                printf("Tidak ada wahana di sekitar Anda!");
                            }*/   
                        }
                        else if (IsKataSama(perintah,BUY)){
                            Kata inputB, jlh, bahan;
                            infotypeP itP3;
                            printf("Ingin membeli apa?\n");
                            printf("List:\n");
                            PrintListBahan("../test/material.txt");

                            boolean MaterialAda = false;
                            while (!MaterialAda)
                            {
                                InputUser(&inputB);
                                ParsePilihBahan(inputB,&jlh,&bahan);
                                if (!IsBahanAda(bahan,"../test/material.txt"))
                                {
                                    printf("Bahan tidak terdaftar. Silahkan ketik bahan yang ada di list bahan.");
                                }
                                else
                                {
                                    MaterialAda = true;
                                }
                            }
                            int jumlah = KataToInt(jlh);
                            if (Money(Player)<jumlah*HargaBahan(bahan,"../test/material.txt"))
                            {
                                printf("Uang tidak mencukupi. Silahkan jadi kaya dulu.\n");
                            }
                            else
                            {
                                if (TimeRem(Player)<(TWaktu(Player)+AA.durasi[2]))
                                {
                                    printf("Anda tidak dapat melakukan perintah buy karena waktu tidak mencukupi!");
                                }
                                else
                                {
                                    printf("// Memasukkan perintah membeli ");PrintKata(bahan);printf(" sebanyak ");PrintKata(jlh);printf(" pada stack //\n");
                                    TulisMATRIKS(matriks(Current(L)));
                                    TAksi(Player)+=1;
                                    TWaktu(Player)+=AA.durasi[2];
                                    TUang(Player)+=jumlah*HargaBahan(bahan,"../test/material.txt");
                                    PrintPrepState(Player);
                                    Command(itP3) = perintah;
                                    input(itP3) = inputB;
                                    lok(itP3) = Kordinat(L);
                                    PushP(&Perintah,itP3);
                                }
                            }
                        }else if (IsKataSama(perintah,UNDO)){
                            infotypeP itP;
                            PopP(&Perintah,&itP);
                            //pop sekali di stack perintah
                        }else if(IsKataSama(perintah,EXECUTE)){
                            //mengeksekusi semua perintah yang ada di stack perintah
                            Money(Player)-=TUang(Player);
                            infotypeP itP;
                            StackP Target;
                            while(!IsEmptyP(Perintah))
                            {
                                PopP(&Perintah, &itP);
                                PushP(&Target, itP);
                            } 
                            while (!IsEmptyP(Target))
                            {
                                infotypeP itP2;
                                PopP(&Target, &itP2);
                                if (IsKataSama(Command(itP2),BUY)){
                                    Kata jmlh,bhn;
                                    ParsePilihBahan(input(itP2),&jmlh,&bhn);
                                    if (IsKataSama(Kayu,bhn))
                                    {
                                        Elmt(Inventory(Player),0)+=KataToInt(jmlh);
                                    }
                                    else if (IsKataSama(Batu,bhn))
                                    {
                                        Elmt(Inventory(Player),1)+=KataToInt(jmlh);
                                    }
                                    else if (IsKataSama(Pasir,bhn))
                                    {
                                        Elmt(Inventory(Player),2)+=KataToInt(jmlh);
                                    }
                                    else if (IsKataSama(Besi,bhn))
                                    {
                                        Elmt(Inventory(Player),3)+=KataToInt(jmlh);
                                    }
                                    else if (IsKataSama(Semen,bhn))
                                    {
                                        Elmt(Inventory(Player),4)+=KataToInt(jmlh);
                                    }
                                }
                            }
                            PrintMainState(Player);
                            main = true;
                        }else if (IsKataSama(perintah,MAIN)){
                            CreateEmpty(&Perintah);
                            main = true;
                        }else
                        {
                            printf("Input tidak diketahui. Silahkan masukkan input kembali.");
                        }
                    }
                    //MASUK KE MAIN
                    /*if(IsKataSama(perintah,SERVE)){
                        info X;
                        infotype X;
                        Dequeue(Q,&X);
                        boolean masuk=false;
                        int i=0;
                        while(!masuk && i<X.idxksg){
                            //X.wahana[i] menunjuk ke nama wahana di list wahana index ke i
                            //lakukan pemeriksaan untuk setiap wahana yang ada di pesanan
                            //jika ada satu yang belum penuh, maka hapus wahana tersebut dari daftar pesanan
                            //lalu tambah uang sesuai harga wahana yang dihapus tadi
                            //cek apakah masih ada wahana tersisa di pesanan, jika ada masuk kembali ke antrian(di belakang), jika tidak maka keluar dari antrian
                            i++;
                        }
                        //di dalam infotype ada nama wahana
                        /*
                        boolean masuk=false					->proses mengecek mau masuk wahana yang mana
                        while(!masuk  && wahana !=Nil){
                            if (tidakpenuh(wahana){
                                proses						->masih belum jelas mau digimanain
                            }
                        }
                        
                        //menjalankan fungsi serve
                        //menjalankan randomize untuk kerusakan wahana
                    }else if(IsKataSama(perintah,REPAIR)){
                        //memperbaiki wahana yang rusak
                    }else if(IsKataSama(perintah,DETAIL)){
                        //menampilkan detail wahana di sebelah pemain
                    }else if(IsKataSama(perintah,OFFICE)){
                        //player memasuki office
                        boolean office=true;
                        while(office){
                            Kata command;
                            printf("Masukkan perintah (Details / Report / Exit):");
                            InputUser(&command);
                            if(IsKataSama(command,DETAILS)){
                                //menampilkan details sesuai instuksi
                            }else if(IsKataSama(command,REPORT)){
                                //fungsi report
                            }else if(IsKataSama(command,EXIT)){
                                office=false;
                            }else{
                                printf("input unknown or can't be done in office");
                            }
                        }
                        
                    }else if(IsKataSama(perintah,PREPARE)){
                        prepare(&Antrian);
                        main=false;
                    }else{
                        printf("input unknown or can't be done in main phase");
                    }*/
                }*/
            }
            else if (IsKataSama(InputKedua, exit))
            {
                printf("Thank you for playing the game!");
            }
        }
        else
        {
            printf("Instruksi Salah. Silahkan ketik './willygame' kembali.\n");
        }
        
    }
	return 0;
}
