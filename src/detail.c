#include "ObjectSurroundList.c"
#include "stdio.h"
#include "mesin/mesinkata.h"

void detail(List L, Bangunan B){
    Kata A[4][20],theKata;
    ObjetSurroundLlist(B,L,&A);
    printf("Terdapat : ");
    int i = 0;
    while (A[i+1]!= Nil && i<3)
    {
        printf("%s, ",A[i]);
        i+=1;
    }
    if (A[i]==Nil)
    {
        printf("Tidak ada apapun di sekeliling\n");
    }
    else
    {
        printf("%s.",A[i]);  
        printf("Lihat Detail dari   :");
        InputUser(&theKata);
        int y = 0;
        while (!IsKataSama(theKata,A[y]))
        {
            y+=1;
        }
        if (IsKataSama(theKata,A[y]))
        {
            
        }
        
    }
    

}