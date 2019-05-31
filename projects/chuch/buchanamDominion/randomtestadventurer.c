/*
 *
 * Demonstrating how to create a random tester for adventurer
 * 
 * randomtestadventurer.c
 * 
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
    printf("yay adventurer");

    srand(time(NULL));
    //randomtestadventurer
    printf("Begin test");

    //initialize the game
    struct gameState state;
    int kingdomCards[10] = {smithy, village, council_room, adventurer, great_hall, steward,ambassador, salvager, copper, gardens};
    int randomSeed = 1;
    int count = 0;
    int choice[2] = {2,4};

       
    //get random numPlayers from given choice
    int numPlayers = rand() % 2;
    int choose = choice[numPlayers];
    //printf("%d\n", numPlayers);
        
    //initialize game w/ random number of Players
    initializeGame(choose, kingdomCards, randomSeed, &state);
    
    int player = whoseTurn(&state);

        
    //get previous drawCard
    int drawCardCount = state.handCount[player];
    printf("%d\n", drawCardCount);

    //call smithyRef
    cardEffect(adventurer, 1, 1, 1, &state, 0 ,1);

    //get post drawCount
    int drawCardPost = state.handCount[player];
    printf("%d\n", drawCardPost);


    //comparison w/ the number of handcounts
    //adventure calls drawCard and draw treasure begins at 0, the while loop goes two times drawing two cards
    if (drawCardCount == drawCardPost - 2){
        printf("test passed \n");
    }

    return 0;
}