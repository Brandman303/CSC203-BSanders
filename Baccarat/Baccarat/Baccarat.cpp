#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//function prototypes
void play(Deck& deck, Hand& player, Hand& banker);
void ideal(Deck& deck, Hand& player, Hand& banker);
void deal(Deck& deck, Hand& hand);
void printHands(Hand& player, Hand& banker);
int gameOverCheck(Hand player, Hand banker);
//game works, but check the game logic. Banker was standing on 0 when player had 0. banker should hit I believe.
//consider making pas by value of Deck deck in function to pass by reference to increase efficiency.
//ask Robert if the IDE provides some sort of indicator for efficiency, Would it be how long the build took?
int main() {
	Deck deck;
	Hand player;
	Hand banker;
	long wallet = 1000;
	cout << "Welcome to Baccarat!" << endl;
	cout << "Rules:  " << endl;
	cout << "How To Play: " << endl;

	play(deck, player, banker);
	cout << "Game Over" << endl;
}
void play(Deck& deck, Hand& player, Hand& banker) {
	bool play = true;
	
	while (play) {
		deck.shuffle();
		int winner = 0; //gameOverCheck(player, banker);
		string yesNo;
		ideal(deck, player, banker);
		cout << "Player's hand: " << player.toString(player) << endl;
		cout << "Banker's hand: " << banker.toString(banker) << endl;
		if (player.handTotal() == 6 || player.handTotal() == 7) {
			if (banker.handTotal() <= 6) {
				deal(deck, banker);
				//printHands(player, banker);
			}
		}
		if (player.handTotal() <= 5) {
			deal(deck, player);
			//printHands(player, banker);
			switch (banker.handTotal()) {
			case 1:
				deal(deck, banker);
				//printHands(player, banker);
				break;
			case 2:
				deal(deck, banker);
				//printHands(player, banker);
				break;
			case 3:
				if (player.getCard(2).getRank() != 8) {
					deal(deck, banker);
					//printHands(player, banker);
				}
				break;
			case 4:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 1) {
					deal(deck, banker);
					//printHands(player, banker);
				}
				break;
			case 5:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 3) {
					deal(deck, banker);
					//printHands(player, banker);
				}
				break;
			case 6:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 5) {
					deal(deck, banker);
					//printHands(player, banker);
					winner = gameOverCheck(player, banker);
				}
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				break;
			}
		}
		cout << endl << "DEALING" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "." << endl << flush;
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << endl;
		printHands(player, banker);
		winner = gameOverCheck(player, banker);

		if (winner > 0) {
			cout << "Player wins!" << endl;

		}
		if (winner < 0) {
			cout << "Banker wins!" << endl;
		}
		if (winner == 0) {
			cout << "Tie!" << endl;
		}
		//cout << "Player's hand: " << player.toString(player) << endl;
		//cout << "Banker's hand: " << banker.toString(banker) << endl;
		cout << "Play Again? (Y/N)" << endl;
		std::cin >> yesNo;
		(yesNo == "Y" || yesNo == "y") ? play = true : play = false;
		player.clearHand();
		banker.clearHand();
	}
}
//Initial deal of two cards to each player
void ideal(Deck& deck, Hand& player, Hand& banker) {
	if (player.handSize() == 0 && banker.handSize() == 0) {
		while (banker.handSize() < 2) {
			player.addToHand(deck.getCard());
			banker.addToHand(deck.getCard());
		}
	}
}
//deals a single card
void deal(Deck& deck, Hand& hand) {
	if (hand.handSize() < 3) {
		hand.addToHand(deck.getCard());
	}
}
//prints the player and banker hands.
void printHands(Hand& player, Hand& banker) {
	cout << "player's Hand: " << player.toString(player) << endl;
	cout << "Banker's Hand: " << banker.toString(banker) << endl;
}
int handleBet(long& wallet) {
}

//consider renaming to tableResult or determineWinner
int gameOverCheck(Hand player, Hand banker) {
	if (player.handTotal() > banker.handTotal()) {
		return 1;
	}
	if (player.handTotal() < banker.handTotal()) {
		return -1;
	}
	return 0;
}