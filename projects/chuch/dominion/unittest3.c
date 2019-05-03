/*
 *
 * Demonstrating how to write unit test
 * 
 * include in makefile
 * 	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest3.c" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    //unit test on great_hallRef
    struct gameState state;
    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int numActionsPrev = state.numActions;
   // printf("%d", numActionsPrev);

    //call great_hallRef
    great_hallRef(0, &state);
    int numActionsPost = state.numActions;
    //printf("%d", numActionsPost);

    //compare number of actions
    int compareControl = numActionsPrev + 1;
    if(compareControl == numActionsPost){
        printf("unit test pass");
    }
    else{
        printf("unit test failed");
    }


    return 0;
}