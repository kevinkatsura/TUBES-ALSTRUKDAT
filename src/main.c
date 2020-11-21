#include <stdio.h>
#include <stdlib.h>

#include "../stack/stack.c"
#include "../queue/queue.c"

//dibuat .c supaya bisa di run

int main(){
	string nama="wangkie kumalasari";
	printf("// Welcome to Willy wangky's fum factory!!// \n // New game / load game / exit? // \n");
	string s;
	scanf("%s", &s);
	Stack Perintah;		//stack yang akan menampung semua printah yang ada
	Queue Antrian;
	switch(s){
		case "new":
			printf("Memulai permainan baru...");
			boolean bermain = true;
			boolean main=false;		//main=true berarti main phase, main=false berarti preparation phase
			/*
				masukkan semua kondisi awal, map awal, stack awal, apapun yang harus ada di awal
			
			
			*/
			while(bermain){
				string perintah;
				//menampilkan waktu(preparation atau main), map, status laiinya
				printf("Masukkan perintah: ");
				scanf("%s", &perintah);
				if (!main){
					switch(perintah){
						case "build":
							//menambahkan perintah build ke dalam stack perintah
						case "upgrade":
							//menambahkan perintah upgrade ke dalam stack perintah
						case "buy":
							//menambahkan perintah buy ke dalam stack perintah
						case "undo":
							//pop sekali di stack perintah
						case "execute":
							//mengeksekusi semua perintah yang ada di stack perintah
						case "main":
							CreateEmpty(&Perintah);
							main=true;
							break;
						default:
							printf("input unknown or can't be done in preparation phase");
							break:	
					}
				} else {
					switch(perintah){
						case "serve":
							//menjalankan fungsi serve
							//menjalankan randomize untuk kerusakan wahana
						case "repair":
							//memperbaiki wahana yang rusak
						case "detail":
							//menampilkan detail wahana di sebelah pemain	
						case "office":
							//player memasuki office
							boolean office=true;
							while(office){
								string command;
								printf("Masukkan perintah (Details / Report / Exit):");
								scanf("%s", &command);
								switch(command){
									case "Details":
										
									case "Report":
										
									case "Exit":
										office=false;
										break;
									default:
										printf("input unknown or can't be done in office");
										break:
								}
							}
							break;
						case "prepare":
							prepare(&Antrian);
							main=false;
							break;
						default:
							printf("input unknown or can't be done in main phase");
							break:
					}
				}
			}
		
		case "load":
			
			
		case "exit":
			printf("// Thanks for playing!!! //");
			break;
			
	}
		
	
	
	return 0;
}
