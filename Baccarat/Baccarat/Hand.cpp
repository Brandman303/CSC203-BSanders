#include "Hand.h"

Hand::Hand() {
	hand.reserve(3);
}
Hand::Hand(Card c1, Card c2, Card c3) {
	
}
Hand::~Hand() {

}
void Hand::addToHand(Card card) {
	hand.push_back(card);
}
void Hand::clearHand() {
	hand.clear();
}
int Hand::handTotal() {
	int sum;
	for (Card card : hand) {
		if (card.getRank() > 9) {
			sum += 0;
		}
		else {
			sum += card.getRank();
		}
	}
	if (sum > 9) {
		sum = sum % 10;
	}
	return sum;
}
vector<Card> Hand::getHand() {
	return hand;
}
void Hand::setHand(vector<Card> hand) {
	this->hand = hand;
}
string Hand::toString() {
	return hand[0].toString() + ", " + hand[1].toString() + ", " + hand[2].toString();
}