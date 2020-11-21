#include <stdio.h>
#include <stdlib.h>

#include "../stack/stack.c"
#include "../queue/queue.c"
#include "../mesin/mesinkata.c"

//dibuat .c supaya bisa di run

int main(){
	string nama="wangkie kumalasari";
	printf("// Welcome to Willy wangky's fum factory!!// \n // New game / load game / exit? // \n");
	Kata cc;
	
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
	
	InputUser(&cc);
	Stack Perintah;		//stack yang akan menampung semua printah yang ada
	Queue Antrian;
	if(IsKataSama(cc,newk) || IsKataSama(cc,exit)){
		
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
		DETAILS.TabKata[0]='D';
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
		
		if(IsKataSama(cc,newk)){
			printf("Memulai permainan baru...");
			boolean bermain = true;
			boolean main=false;		//main=true berarti main phase, main=false berarti preparation phase
			/*
				masukkan semua kondisi awal, map awal, stack awal, apapun yang harus ada di awal
			
			
			*/
		} else {
			/*
				load semua data
			*/
		}	
		while(bermain){
			Kata perintah;
			//menampilkan waktu(preparation atau main), map, status laiinya
			printf("Masukkan perintah: ");
			InputUser(&perintah);
			if (!main){
				if(IsKataSama(perintah,BUILD)){
					//menambahkan perintah build ke dalam stack perintah
				}else if(IsKataSama(perintah,UPGRADE)){
					//menambahkan perintah upgrade ke dalam stack perintah
				}else if(IsKataSama(perintah,BUY)){
					//menambahkan perintah buy ke dalam stack perintah
				}else if(IsKataSama(perintah,UNDO)){
					//pop sekali di stack perintah
				}else if(IsKataSama(perintah,EXECUTE)){
					//mengeksekusi semua perintah yang ada di stack perintah
				}else if(IsKataSama(perintah,MAIN)){
					CreateEmpty(&Perintah);
					main=true;
				}else{
					printf("input unknown or can't be done in preparation phase");
				}	
			} else {
				if(IsKataSama(perintah,SERVE)){
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
				}
			}
		}			
	} else if (IsKataSama(cc,exit)){
		printf("thanks for playing");
	}
		
	
	
	return 0;
}
