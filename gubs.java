/*
 * start with 13 gubs and 4 spears
 */
import java.io.*;
import java.math.*; 
import java.util.Random;


public class gubs {

	public static void main(String[] args) {
		System.out.println("Starting a fresh game of gubs");
		//assign card values to card ids
		//shuffle remaining cards
		int numberOfCards = 17;
		Random rand = new Random();

		int deck[] = new int[numberOfCards]; //13 gubs, 4 spears

		for (int i = 0; i < numberOfCards; i++)	{
			deck[i] = i;	//0 can be esteemed?
			//System.out.println();
		}


		//shuffle and print cards
		for(int cardID:deck)	{
			//int source = rand.nextInt() % 52;
			//int dest = rand.nextInt() % 52;

			//System.out.println(source);
			//System.out.println(dest);

			// int shuffleCard = deck[source];
	        // deck[source] = deck[dest];
	        // deck[dest] = shuffleCard;
			
			System.out.println(cardID);
		}
		
		
	}


}