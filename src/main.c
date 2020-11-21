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
							
						case "upgrade":
							
						case "buy":
							
						case "undo":
						
						case "execute":
						
						case "main":
						
						default:
							printf("input unknown or can't be done in preparation phase");
							break:	
					}
				} else {
					switch(perintah){
						case "serve":
							
						case "repair":
							
						case "detail":
							
						case "office":
							
						case "prepare":
							
						default:
							printf("input unknown or can't be done in preparation phase");
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
