/*
 *
 * Demonstrating how to create a random tester for villageRef
 * 
 * randomtestcard2.c
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
    //unit test on villageRef
    printf("random test on villageRef\n");
    struct gameState state;
    
    //initialize the game
    int numPlayers = 2;
    int kingdomCards [10];
   //for (int i = 0;i < 20; i++){

        for (int y=0;y < 10; y++){
             kingdomCards[y] = rand() % 10;
             printf("%d \n", kingdomCards[y]);
             
        }
        
        int randomSeed = 1;
        
        initializeGame(numPlayers,kingdomCards, randomSeed, &state);

        //get the previous handcount before villageRef played
        int player = whoseTurn(&state);
        int handCountPrev = state.handCount[player];
        printf("%d\n", handCountPrev);

        //call villageRef
        cardEffect(village, 1, 1, 1, &state, 0 ,1);

        //get the post handCount after village is played
        int handCountPost = state.handCount[player];
        printf("%d\n", handCountPost);

        //COMPARE
        //it should be noted that a card is drawn but a card is also discared from hand
        int compareControl = handCountPrev;
        if(compareControl == handCountPost){
            printf("test passed \n");
        }
        else{
            printf("test failed\n");
        }

   // }
    return 0;
}
