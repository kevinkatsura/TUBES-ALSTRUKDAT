#include <stdio.h>
#include <stdlib.h>

// yang di atas ditujukan terkhusus untuk queue


void undo(Stack *S){
	string var;
	Pop(S,&var);
}

void execute (Stack *S1, Stack *S2, Stack *S3, Stack *S4){
	//asumsikan S1 untuk perintah, S2 stack untuk build, S3 stack untuk upgrade, S4 stack untuk buy
	string var;
	while (!IsEmpty(*S)){
		Pop(S,&var);
		switch(var){
			case "build":
				build(S2);
				break;
			case "upgrade":
				upgrade(S3);
				break;
			case "buy":
				buy(S4);
				break;
			default:
				break;
			}
		}
	}	
}

void main (Stack *S){ 	//harus ada tambahan parameter untuk mengubah curent time
	//Stack S adalah stack untuk perintah
	CreateEmpty(*S);
	//CurentTime=09.00
	//setiap memanggil main, pastikan mengubah boolean main menjadi true atau kondisi lainnya yang membuat kondisi menjadi main phase
}

void serve(Queue *Q){
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
	*/
}


