#pragma once
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <list>
#include "Deck.h"
using namespace std;

class Hand {
private:
	vector<Card> hand;
public:
	Hand();
	Hand(Card c1, Card c2, Card c3);
	~Hand();

	void addToHand(Card card);
	void clearHand();
	int handTotal();

	vector<Card> getHand();
	void setHand(vector<Card> hand);
	string toString();

};
#endif