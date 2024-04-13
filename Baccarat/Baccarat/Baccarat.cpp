#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;
void ideal(Deck& deck, Hand& player, Hand& banker);
void deal(Deck& deck, Hand& hand);
int gameOverCheck(Hand player, Hand banker);
//game works, but check the game logic. Banker was standing on 0 when player had 0. banker should hit I believe.
//consider making pas by value of Deck deck in function to pass by reference to increase efficiency.
//ask Robert if the IDE provides some sort of indicator for efficiency, Would it be how long the build took?
int main() {
	Deck deck;
	Hand player;
	Hand banker;
	bool play = true;
	while (play) {
		deck.shuffle();
		int winner = gameOverCheck(player, banker);
		string yesNo;
		ideal(deck, player, banker);
		cout << "Player's hand: " << player.toString(player) << endl;
		cout << "Banker's hand: " << banker.toString(banker) << endl;
		if (player.handTotal() == (8 || 9) || banker.handTotal() == (8 || 9)) {
			winner = gameOverCheck(player, banker);
		}
		if (player.handTotal() == (6, 7)) {
			if (banker.handTotal() < 7) {
				deal(deck, banker);
				cout << "Player's hand: " << player.toString(player) << endl;
				cout << "Banker's hand: " << banker.toString(banker) << endl;
				winner = gameOverCheck(player, banker);
			}
			else {
				winner = gameOverCheck(player, banker);
			}
		}
		if (player.handTotal() < 6) {
			deal(deck, player);
			cout << "Player's hand: " << player.toString(player) << endl;
			cout << "Banker's hand: " << banker.toString(banker) << endl;
			switch (banker.handTotal()) {
			case 1: 
				deal(deck, banker);
				cout << "Player's hand: " << player.toString(player) << endl;
				cout << "Banker's hand: " << banker.toString(banker) << endl;
				winner = gameOverCheck(player, banker);
			case 2:
				deal(deck, banker);
				cout << "Player's hand: " << player.toString(player) << endl;
				cout << "Banker's hand: " << banker.toString(banker) << endl;
				winner = gameOverCheck(player, banker);
			case 3:
				if (player.getCard(2).getRank() < 8) {
					deal(deck, banker);
					cout << "Player's hand: " << player.toString(player) << endl;
					cout << "Banker's hand: " << banker.toString(banker) << endl;
					winner = gameOverCheck(player, banker);
				}
				else {
					winner = gameOverCheck(player, banker);
				}
			case 4:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 1) {
					deal(deck, banker);
					cout << "Player's hand: " << player.toString(player) << endl;
					cout << "Banker's hand: " << banker.toString(banker) << endl;
					winner = gameOverCheck(player, banker);
				}
				else {
					winner = gameOverCheck(player, banker);
				}
			case 5:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 3) {
					deal(deck, banker);
					cout << "Player's hand: " << player.toString(player) << endl;
					cout << "Banker's hand: " << banker.toString(banker) << endl;
					winner = gameOverCheck(player, banker);
				}
				else {
					winner = gameOverCheck(player, banker);
				}
			case 6:
				if (player.getCard(2).getRank() < 8 && player.getCard(2).getRank() > 5) {
					deal(deck, banker);
					cout << "Player's hand: " << player.toString(player) << endl;
					cout << "Banker's hand: " << banker.toString(banker) << endl;
					winner = gameOverCheck(player, banker);
				}
				else {
					winner = gameOverCheck(player, banker);
				}
			case 7:
				winner = gameOverCheck(player, banker);
			default:
				winner = gameOverCheck(player, banker);
			}
		}

		if (winner > 0) {
			cout << "Player wins!" << endl;
			
		}
		else if (winner < 0) {
			cout << "Banker wins!" << endl;
		}
		else {
			cout << "Tie!" << endl;
		}
		cout << "Player's hand: " << player.toString(player) << endl;
		cout << "Banker's hand: " << banker.toString(banker) << endl;
		cout << "Play Again? (Y/N)" << endl;
		cin >> yesNo;
		(yesNo == "Y" || yesNo == "y") ? play = true : play = false;
		player.clearHand();
		banker.clearHand();
	}
	cout << "Game Over" << endl;
}

void ideal(Deck& deck, Hand& player, Hand& banker) {
	if (player.handSize() == 0 && banker.handSize() == 0) {
		while (banker.handSize() < 2) {
			player.addToHand(deck.getCard());
			banker.addToHand(deck.getCard());
		}
	}
}
void deal(Deck& deck, Hand& hand) {
	hand.addToHand(deck.getCard());
}
//consider renaming to tableResult or determineWinner
int gameOverCheck(Hand player, Hand banker) {
	if (player.handTotal() > banker.handTotal()) {
		return 1;
	}
	else if (player.handTotal() < banker.handTotal()) {
		return -1;
	}
	else {
		return 0;
	}
}