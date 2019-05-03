/*
 *
 * Demonstrating how to write unit test
 * 
 * include in makefile
 * 	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest1.c" >> unittestresults.out
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int main(){
    //smithyRef test
    printf("Unit test on smithyRef\n");
    struct gameState state;
    
    //initialize the game
    int numPlayers = 2;
    int kingdomCards[10] = {0,1,2,3,4,5,6,7,8,9};
    int randomSeed = 1;
    initializeGame(numPlayers,kingdomCards, randomSeed, &state);
  
    //get the previous handcount before smithy is played
    int player = whoseTurn(&state);
    int handCountPrev = state.handCount[player];
    //printf("%d", handCountPrev);

    //call smithyRef
    smithyRef(0, &state);

    //get the post handCount after smithy is played
    int handCountPost = state.handCount[player];
    //printf("%d", handCountPost);

    //COMPARE
    int compareControl = handCountPrev + 2;
    if(compareControl == handCountPost){
        printf("unit test1 passed \n");
    }
    else{
        printf("unit test1 failed");
    }



    return 0;





}