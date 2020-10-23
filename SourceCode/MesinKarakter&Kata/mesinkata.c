#include "mesinkata.h"
#include "stdio.h"

boolean EndKata ;
Kata CKata ;

    void IgnoreBlank()
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang 
    F.S. : CC ≠ BLANK atau CC = MARK */
    {    
        while (CC == BLANK)
        {
            ADV() ;
        }
    }

    void STARTKATA()
    /* I.S. : CC sembarang 
    F.S. : EndKata = true, dan CC = MARK; 
            atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
            CC karakter pertama sesudah karakter terakhir kata */
        {
            START() ;
            CKata.Length = 0 ;
            IgnoreBlank() ;
            ADVKATA();
        }

    void ADVKATA()
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
    F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
            CC adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika CC = MARK, EndKata = true.		  
    Proses : Akuisisi kata menggunakan procedure SalinKata */
    {
            SalinKata() ;
            if (CC == BLANK)
            {
                IgnoreBlank() ;
                if (CC == MARK)
                {
                    EndKata = true ;
                }
                else
                {
                    EndKata = false ;
                }
            }
            else if (CC == MARK)
            {
                EndKata = true ;
            }        
    }

    void SalinKata()
    /* Mengakuisisi kata, menyimpan dalam CKata
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CKata berisi kata yang sudah diakuisisi; 
            CC = BLANK atau CC = MARK; 
            CC adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
        {
            int i = (CKata.Length) ;
            while (CC != MARK && CC != BLANK && CKata.Length != NMax)
            {
                CKata.TabKata[i] = CC ;
                i++ ;
                CKata.Length += 1 ;
                ADV() ;
            }
        }
