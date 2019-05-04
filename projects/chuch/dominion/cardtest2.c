/*
 *
 * cardtest adventurer
 * 
 * include in makefile
 * 	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest2.c" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("yay lets test adventurer \n");

    struct gameState state;

    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    int player = whoseTurn(&state);
    int drawCardCount = state.handCount[player];
    //printf("%d", drawCardCount);

    //play adventurer
    cardEffect(adventurer, 1, 1, 1, &state, 0, 1);
    int drawCardPost = state.handCount[player];
   // printf("%d", drawCardPost);

    //adventurer calls drawCard
    //we know that draw treasure starts at 0
    //so the while loop goes two times, drawing two cards

    if (drawCardCount == drawCardPost - 2){
        printf("test passed");
    }
    else{
        printf("test didn't pass");
    }

    return 0;
}

