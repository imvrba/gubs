/*
 * NOTES:
 *  - ISSUES: dealt card is often the same value,
 *      needs to be unique and can't pick same card. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
int TOTAL_NUM_CARDS = 70;

// card attributes
typedef struct {
    int card_id;    // unique id for each card
    char card_type;  // harzard, event, etc. 
} card;


// initialize the deck with the correct card attributes
//card deck[TOTAL_NUM_CARDS];

// shuffle deck function
void shuffle_deck(card *deck, int *size) {
    int j, k;
    card temp;

    // seed random number generator
    srand(time(NULL));

    // shuffle deck
    for (int i = 0; i < *size; i++) {
        j = rand() % *size;
        k = rand() % *size;
        temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}

// deal cards function
card dealCard(card *deck, int *size) {
    card dealt_card = deck[0];
    *size = *size - 1;
    return dealt_card;
}


//main
int main() {
    card deck[TOTAL_NUM_CARDS];
    card player1_hand[8];// player 1 hand
    card player2_hand[8];
    int numCardsPlayer1 = 8; // FIXME: replace this to be dynamic
    int choice; //FIXME: used for game controls

    // init player hands
    for(int i = 0; i < 8; i++) {
        player1_hand[i].card_id = 0;
        player2_hand[i].card_id = 0;
    }

    // create all cards and shuffle deck
    for (int i = 0; i < TOTAL_NUM_CARDS; i++) {
        deck[i].card_id = i;
        deck[i].card_type = 'g'; // gub card
    } shuffle_deck(deck, &TOTAL_NUM_CARDS);

    // deal a card
    int size = TOTAL_NUM_CARDS;
    card dealt_card = dealCard(deck, &size);

    // initial remarks
    printf("Starting a fresh game of Gubs\n");
    printf("Dealt card id %d\n", dealt_card.card_id);
    printf("Dealt card type %c\n", dealt_card.card_type);

    // game loop
    while(true) {
        // game controls/options
        printf("What would you like to do?\n");
        printf("1 = Draw a card\n");
        printf("2 = End turn\n");
        scanf("%d", &choice);

        // Game Decisions
        if(choice == 1) {
            // draw a card
            card dealt_card = dealCard(deck, &size);
            // place dealt_card into first empty slot in player1_hand
            for(int i = 0; i < numCardsPlayer1; i++) {
                if (player1_hand[i].card_id == 0) {
                    player1_hand[i] = dealt_card;
                    break;
                }
                // // if no space for dealt_card, announce it
                // if (i == numCardsPlayer1 - 1) {
                //     printf("No space for card %d\n", dealt_card.card_id);
                // }
            }

            printf("Dealt card id %d\n", dealt_card.card_id);
        }
        if(choice == 2) {
            // end turn
            printf("Ending turn\n");
            printf("does nothing for now\n");
            break;
        }

        // figure out how many cards each player has


        // print out the cards in player 1's hand
        for(int j = 0; j < numCardsPlayer1; j++) {
            printf("Player 1 card %d is %d\n", j, player1_hand[j].card_id);
        }
    } // end of game loop

} //end of main