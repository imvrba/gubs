//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEV_MODE 1

//define functions here
    //shuffle remaining cards
    //look at the top three cards
    //show hand to:


//define global variables
int remainingCards;


//main
int main() {
    //initial remarks
    printf("Starting a fresh game of Gubs...\n");

    int deck[70];

    //initialize the card deck
    for (int i=0; i < 70; i++) {
        deck[i] = i;
    }

    //shuffle cards
    for (int i=0; i < 1000; i++)   {
        int source = rand() % 52;
        int dest = rand() % 52;
        int shuffleCard = deck[source];
        deck[source] = deck[dest];
        deck[dest] = shuffleCard;
    }

    //show shuffled cards
    if (DEV_MODE == 1) {
        printf("List of Shuffled Cards:\n");
        for(int i = 0; i < 70; i++){
            printf("%d\n", deck[i]);
        }
    }

} //end of main