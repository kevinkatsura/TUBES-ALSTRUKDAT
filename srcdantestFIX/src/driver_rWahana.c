#include "readWahana.h"

int main(){
    int n;
    ekstrakWahana(&n);
    int i;
    for (i=0;i<n;i++){
        PrintKata(namaW[i]);
    }	
}