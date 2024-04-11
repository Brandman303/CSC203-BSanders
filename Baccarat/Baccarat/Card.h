#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Card {
private:
	int rank;
	int suit;

public:
	Card();
	Card(int rank, int suit);
	~Card();

	static const array<string, 14> Ranks;
	static const array<string, 4> Suits;

	int getRank() const;
	int getSuit() const;

	void setRank(int newRank);
	void setSuit(int newSuit);

	int compareTo(const Card& oCard);
	string toString() const;
};

#endif
