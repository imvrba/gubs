import java.io.*;
import java.math.*; 
import java.util.Random;



public class gubs {
	//int remainingCards = 17; //make this an array


	public static void shuffleRemainingCards(int deck[]) {
		Random rand = new Random();

		for (int first = 0; first < deck.length; first++)	{
			//select a random number between 0 and 17
			int second  = rand.nextInt(17);

			//swap cards
			int temp = deck[first];
			deck[first] = deck[second];
			deck[second] = temp;
		}
		return;
	}



	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Starting a fresh game of gubs...");

		int numberOfCards = 70;
		Random rand = new Random();

		int deck[] = new int[numberOfCards]; //13 gubs, 4 spears

		for (int i = 0; i < numberOfCards; i++)	{
			deck[i] = i;	//0 can be esteemed?
			//System.out.println();
		}

		shuffleRemainingCards(deck);

		//shuffle and print cards
		for(int cardID:deck)	{

			System.out.println(cardID);
		}
		
		
	}


}