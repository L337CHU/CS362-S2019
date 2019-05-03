/*
 *
 * Demonstrating how to write unit test
 * 
 * include in makefile
 * 	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest4.c" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    //unit test on council_roomRef
    struct gameState state;
    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int numBuysPrev = state.numBuys;
    //printf("%d", numBuysPrev);

    //call council_roomRef
    council_roomRef(0, &state);
    int numBuysPost = state.numBuys;
   // printf("%d", numBuysPost);

    //compare buys
    int controlBuys;
    controlBuys = numBuysPrev + 1;
    if (controlBuys == numBuysPost){
        printf("unit test passed");
    }
    else{
        printf("unit test failed");
    }




    return 0;
}
