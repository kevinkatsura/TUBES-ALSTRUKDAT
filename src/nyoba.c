#include <stdio.h>
#include "mesin/mesinkata.c"

int main(){
	Kata haha;
	boolean serve;
	InputUser(&haha,&serve);
	PrintKata(haha);
	if (serve){
		printf("serve");
	}
}
