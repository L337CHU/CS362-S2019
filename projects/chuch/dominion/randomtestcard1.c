/*
 *
 * Demonstrating how to create a random tester for smithy
 * 
 * randomtestcard1.c
 * 
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



///*

int main(){


    srand(time(NULL));
    //smithy test
    printf("Begin test");

    //initialize the game
    //struct gameState state;
    int kingdomCards[10] = {smithy, village, council_room, adventurer, great_hall, steward,ambassador, salvager, copper, gardens};
    int randomSeed = 1;
    int count = 0;
    
    
    for (int i = 0; i < 100; i++){

        struct gameState state;
        count = count + 1;                          //increment count w/ each iteration
        printf("Number count: %d \n", count);
        int numPlayers = rand() % 20;
        //printf("%d\n", numPlayers);
        
        
        //initialize game w/ random number of Players
        initializeGame(numPlayers, kingdomCards, randomSeed, &state);
       
        int player = whoseTurn(&state);

        
        //get previous handcount
        int handCountPrev = state.handCount[player];
        //printf("%d\n", handCountPrev);

        //call smithyRef
        cardEffect(smithy, 0, 0, 0, &state, 0 ,0);

        //get post handcount
        int handCountPost = state.handCount[player];
        //printf("%d\n", handCountPost);


        //comparison
        if (handCountPrev == handCountPost - 2){
            printf("test passed \n");
        }
        else{
            printf("test failed\n");
        }

    //}
    }

    return 0;

}

//*/

