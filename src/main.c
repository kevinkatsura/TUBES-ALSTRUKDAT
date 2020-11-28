#include <stdio.h>
#include <stdlib.h>

#include "mesin/mesinkata.h"
#include "state/state.h"
#include "stackP/stackP.h"

int main(){
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
            Kata InputKedua;
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
                printf("Memulai permainan baru...\n");
                printf("Masukkan nama: ");
                InputUser(&nama);
                NewPrepState(&Player,nama);
                PrintPrepState(Player);

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
    int h;
    scanf("%d",&h);
    return 0;
}
