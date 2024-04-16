#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//function prototypes
void play(Deck& deck, Hand& player, Hand& banker);
void initialDeal(Deck& deck, Hand& player, Hand& banker);
void deal(Deck& deck, Hand& hand);
void printHands(Hand& player, Hand& banker);
int tableResult(Hand player, Hand banker);
long betResult(long& wallet, int betType, long bet, int winner);
long makeBet(long& wallet);

//game works, but check the game logic. Banker was standing on 0 when player had 0. banker should hit I believe.
// I no longer think banker is standing on zero but instead standing whenver player has natural 8 or 9
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
	long wallet = 1000;
	long bet = 5;
	long result = 0;
	while (play) {
		deck.shuffle();
		int winner = 0; //gameOverCheck(player, banker);
		string yesNo;
		int betType;

		cout << "Wallet: " << wallet << endl;
		cout << "1. Bet on player" << endl;
		cout << "2. Bet on banker" << endl;
		cout << "3. Bet on Tie" << endl;
		cout << "Please enter your choice by corresponding number: " << endl;
		cin >> betType;

		switch (betType) {
		case 1:
			cout << "You have chosen to bet on Player, with payout 1:1" << endl;
			bet = makeBet(wallet);
			break;
		case 2:
			cout << "You have chosen to bet on Banker, with payout 0.95:1" << endl;
			bet = makeBet(wallet);
			break;
		case 3:
			cout << "You have chosen to bet on Tie, with payout 8:1" << endl;
			bet = makeBet(wallet);
			break;
		}
		initialDeal(deck, player, banker);
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
					//winner = tableResult(player, banker);
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
		winner = tableResult(player, banker);

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
		//put bet result if win or loss here
		result = betResult(wallet, betType, bet, winner); //do not call multiple times since it runs through the function each time. that is causeing extra changes to wallet
		if (winner > 0) {
			cout << "bet result: " << result << endl;
		}
		if (winner < 0) {
			cout << "bet result: " << result - bet<< endl;
		}
		if (winner == 0) {
			cout << "bet result: push" << endl;
		}
		cout << "wallet: " << wallet << endl; // may or may not want this here.
		cout << "Play Again? (Y/N)" << endl;
		std::cin >> yesNo;
		(yesNo == "Y" || yesNo == "y") ? play = true : play = false;
		player.clearHand();
		banker.clearHand();
	}
}
//Initial deal of two cards to each player
void initialDeal(Deck& deck, Hand& player, Hand& banker) {
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
//handles the winnings or losses. may not need the wallet, just change it in play function.
long betResult(long& wallet, int betType, long bet, int winner) {
	long result = 0;
	//case 1 and 2 need another if statment to handle if a tie happens but they player did not bet on it, the bet should be push.
	switch (betType) {
	case 1:
		if (winner > 0) {
			result = bet * 2;
			wallet += result;
		}
		if (winner < 0) {
			wallet -= bet;
		}
		break;
	case 2:
		if (winner < 0) {
			//check the accuracy of this. I am using multiple types here may need to use double. see if long has decimals
			result = bet * 1.95;
			wallet += result;
		}
		if (winner > 0) {
			wallet -= bet;
		}
		break;
	case 3:
		if (winner == 0) {
			result = bet * 9; // check this math
			wallet += result;
		}
		else {
			wallet -= bet;
		}
		break;
	default:
		cout << "something went wrong in bet result." << endl;
		break;
	}
	return result;
}

long makeBet(long& wallet) {
	long bet = 5;
	if (bet < 1000 && bet >= 5) {
		cout << "Minimum bet is 5. Place your bets: " << endl;
		cin >> bet;
		if (bet > wallet) {
			cout << "Bet exceeds wallet. Please re-enter bet." << endl;
		}
		else {
			//wallet -= bet;
		}
	}
	else {
		cout << "Invalid bet. Please re-enter bet." << endl;
	}
	return bet; //check if it returns correct value.
}
//consider renaming to tableResult or determineWinner
int tableResult(Hand player, Hand banker) {
	if (player.handTotal() > banker.handTotal()) {
		return 1;
	}
	if (player.handTotal() < banker.handTotal()) {
		return -1;
	}
	return 0;
}