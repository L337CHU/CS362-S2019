/*
 *
 * cardtest salvager
 * 
 * include in makefile
 * 	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest4.c" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("lets test salvager \n");

    struct gameState state;

    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int numBuysPrev = state.numBuys;
    //printf("%d", numBuysPrev);

    //play salvager
    cardEffect(salvager, 1, 1, 1, &state, 0, 1);
    int numBuysPost = state.numBuys;
    //printf("%d", numBuysPost);

    //salvager cardffect
    //we know that salvager's numBuys increases by 1
    //compare previous and post number of buys
    if (numBuysPrev == numBuysPost - 1){
        printf("test passed");
    }
    else{
        printf("test didn't pass");
    }

    return 0;
}



