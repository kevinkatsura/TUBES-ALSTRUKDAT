/*
    Nama        : Kevin Katusura Dani Sitanggang
    NIM         : 13519216
    Tanggal     : 1 Oktober 2020
    TOPIK       : ADT Mesin Kata dan karakter 
*/

#include "mesintoken.h"
#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"

boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
   {    
        while ((CC == BLANK) && (CC != MARK)){
            ADV();
        }
    }

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
    {
    EndToken = false;
    START();
    ADVTOKEN();
    }

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
   {
    IgnoreBlank();
    if (CC == MARK) {
        EndToken= true;
    }
    else {
        SalinToken();
    }     
   }

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    {
        int i = 1 ;
        CToken.val = 0 ;
        do{
            if (CC == '*' ||  CC == '/' || CC ==  '+' || CC == '-' || CC == '^')
            {
                CToken.tkn = CC ;
                CToken.val = -1 ;
            }
            else if (CC == '1' || CC == '2' || CC == '3' || CC == '4' ||CC == '5' ||CC == '6' ||CC == '7' ||CC == '8' ||CC == '9' ||CC == '0')
            {

                    switch (CC){
                    case '0' : CToken.val = CToken.val*10 + 0; break;
                    case '1' : CToken.val = CToken.val*10 + 1;break;
                    case '2' : CToken.val = CToken.val*10 + 2;break;
                    case '3' : CToken.val = CToken.val*10 + 3;break;
                    case '4' : CToken.val = CToken.val*10 + 4;break;
                    case '5' : CToken.val = CToken.val*10 + 5;break;
                    case '6' : CToken.val = CToken.val*10 + 6;break;
                    case '7' : CToken.val = CToken.val*10 + 7;break;
                    case '8' : CToken.val = CToken.val*10 + 8;break;
                    case '9' : CToken.val = CToken.val*10 + 9;break;
                    default : CToken.val = CToken.val*10 + 0;break;
                }
                CToken.tkn = 'b' ;
            }
        i++ ;
        ADV() ;
        } while((CC != BLANK) && (CC != MARK) && (i <= NMax)) ;
        IgnoreBlank();
    }