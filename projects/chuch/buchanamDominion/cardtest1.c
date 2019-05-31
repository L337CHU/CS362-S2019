/*
 *
 * cardtest smithy
 * 
 * include in makefile
 * 	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest1.c" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("yay lets test smithy\n");

    struct gameState state;

    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int discardCount = state.playedCardCount;
   // printf("%d", discardCount);
    //play smithy
    cardEffect(smithy, 1, 1, 1, &state, 0, 1);
    int discardCountPost = state.playedCardCount;
    //printf("%d", discardCountPost);

    //smithy calls for discarding card
    //when discardcard function is called, the played card count increases by one
    //unit test to see if card was discarded properly from playedcardcount

    if (discardCount == discardCountPost -1){
        printf("test passed");
    }
    else{
        printf("test didn't pass");
    }

    return 0;
}
