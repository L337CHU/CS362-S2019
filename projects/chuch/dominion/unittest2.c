/*
 *
 * Demonstrating how to write unit test
 * 
 * include in makefile
 * 	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest2.c" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    //unit test on villageRef
    printf("Unit test on villageRef\n");
    struct gameState state;
    
    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);

    //get the previous handcount before villageRef played
    int player = whoseTurn(&state);
    int handCountPrev = state.handCount[player];
    //printf("%d", handCountPrev);

    //call villageRef
    villageRef(0, &state);

    //get the post handCount after smithy is played
    int handCountPost = state.handCount[player];
    //printf("%d", handCountPost);

    //COMPARE
    //it should be noted that a card is drawn but a card is also discared from hand
    int compareControl = handCountPrev;
    if(compareControl == handCountPost){
        printf("unit test2 passed \n");
    }
    else{
        printf("unit test2 failed");
    }


    return 0;
}

