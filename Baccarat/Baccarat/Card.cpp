#include "Card.h"

Card::Card() {

}
Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
}
Card::~Card() {

}
const array<string, 14> Card::Ranks = { 
	"0", "A", "2", "3", "4", "5", "6","7", "8",
	"9", "10", "J", "Q", "K" 
};
const array<string, 4> Card::Suits = {
	"Hearts", "Diamonds", "Clubs", "Spades"
};
int Card::getRank() const {
	return rank;
}
int Card::getSuit() const {
	return suit;
}
void Card::setRank(int newRank) {
	rank = newRank;
}
void Card::setSuit(int newSuit) {
	suit = newSuit;
}
string Card::toString() const {
	return Ranks[rank] + " of " + Suits[suit];
}