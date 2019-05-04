/*
 *
 * cardtest steward
 * 
 * include in makefile
 * 	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest3.c" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("lets test steward \n");

    struct gameState state;

    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int drawCardCount = state.handCount[player];
    printf("%d", drawCardCount);

    //play steward
    cardEffect(steward, 1, 1, 1, &state, 0, 1);
    int drawCardPost = state.handCount[player];
    printf("%d", drawCardPost);

    //steward caseeffect
    //we know that steward w/ choice 1 has +2 drawcard
    //however, after, we discard one hand 

    if (drawCardCount == drawCardPost - 1){
        printf("test passed");
    }
    else{
        printf("test didn't pass");
    }

    return 0;
}


