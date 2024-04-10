#include "Deck.h"

/*learned keywords.push_back creates a new object then adds to the end of a vector
* while emplace_back essentially builds the new object in place, and doesnt need to move it
* into the vector.
* reserve will be used to allocate memory, in this case for our vector.
* in summary reserve will set aside memory for a vector and emplace_back will build each object in place.
* 
* Deck() uses Card constructor to create then allocate cards into a deck (vector).
*/

Deck::Deck() {
	cards.reserve(52);
	
	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			cards.emplace_back(i, j);
		}
	}
}
//Deck(int numCards) reserves memory for cards.
Deck::Deck(int numCards) {
	cards.reserve(numCards);
}
Deck::~Deck() {

}
void Deck::shuffle() {

}
void Deck::selectionSort() {

}
void Deck::swap(const vector<Card>& cards, int index1, int index2) {

}
const vector<Card>& Deck::getCards() const {

}
void Deck::setCards(const vector<Card>& cards) {

}
string Deck::toString() {

}