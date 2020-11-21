#ifndef PERINTAH_H
#define PERINTAH_H

#include "stack/stackt.h"
#include "queue/queue.h"
void newGame();

void exit();

void loadGame();

void W();

void A();

void S();

void D();

void build (Stack *S);

void upgrade (Stack *S);

void buy (Stack *S);

void undo (Stack *S);

void execute (Stack *S);

void main (Stack *S);

void serve(Queue *Q);

void repair();

void detail();

void office();

void prepare();

void ObjectSurroundList();

#endif