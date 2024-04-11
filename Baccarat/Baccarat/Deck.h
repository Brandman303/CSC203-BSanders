#pragma once
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class Deck {
private:
	vector<Card> cards;;
public:
	Deck();
	Deck(int numCards);
	~Deck();

	void shuffle();
	void selectionSort();
	void swap(vector<Card>& cards, int index1, int index2);
	
	const vector<Card>& getCards() const;
	void setCards(const vector<Card>& cards);
	string toString();
};

#endif
