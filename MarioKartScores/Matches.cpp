#include "stdafx.h"
#include "Matches.h"
#include <iostream>

using namespace std; 

// PRIVATE FUNCTIONS

int Matches::get_ck_highest_score()
{
	int highest = 0;
	for (int i = 0; i < matches.size(); i++) {
		int multiplier = (32 / matches[i].get_races());
		if ((matches[i].get_CKScore() * multiplier) > highest)
			highest = matches[i].get_CKScore();
	}
	return highest;
}

int Matches::get_jas_highest_score()
{
	int highest = 0;
	for (int i = 0; i < matches.size(); i++) {
		int multiplier = (32 / matches[i].get_races());
		if ((matches[i].get_JasScore() * multiplier) > highest)
			highest = matches[i].get_JasScore();
	}
	return highest;
}

int Matches::get_ck_lowest_score()
{
	int lowest = 481;
	for (int i = 0; i < matches.size(); i++) {
		int multiplier = (32 / matches[i].get_races());
		if ((matches[i].get_CKScore() * multiplier) < lowest)
			lowest = matches[i].get_CKScore();
	}
	return lowest;
}

int Matches::get_jas_lowest_score()
{
	int lowest = 481;
	for (int i = 0; i < matches.size(); i++) {
		int multiplier = (32 / matches[i].get_races());
		if ((matches[i].get_JasScore() * multiplier) < lowest)
			lowest = matches[i].get_JasScore();
	}
	return lowest;
}

void Matches::snapshot(int ck_total, int jas_total, int pos) {
	if (pos >= matches.size())
		return;
	int char_score = (ck_total + matches[pos].get_CKScore());
	int jas_score = (jas_total + matches[pos].get_JasScore());
	cout << matches[pos].get_date() << ": ";
	if (char_score > jas_score) {
		cout << "Charankanwal leads by " << char_score - jas_score << " points!" << endl;
	}
	else if (jas_score > char_score) {
		cout << "Jasleen leads by " << jas_score - char_score << " points!" << endl;
	}
	else if (char_score = jas_score) {
		cout << "IT WAS A TIE!" << endl;
	}
	snapshot(char_score, jas_score, pos + 1);
}

// PUBLIC FUNCTIONS

void Matches::print_matches() {
	for (int i = 0; i < matches.size(); i++) {
		cout << i + 1 << ": " << matches[i] << endl;
	}
	cout << "There has been " << matches.size() << " matches in total\n" << endl;
}

int Matches::get_ck_total() {
	int total = 0;
	for (int i = 0; i < matches.size(); i++) {
		total += matches[i].get_CKScore();
	}
	return total;
}

int Matches::get_jas_total() {
	int total = 0;
	for (int i = 0; i < matches.size(); i++) {
		total += matches[i].get_JasScore();
	}
	return total;
}

float Matches::get_race_average(int total) {
	return (float)total / get_num_races();
}

float Matches::get_match_average(int total)
{
	return ((float) total / matches.size());
}

int Matches::get_num_races() {
	int total = 0;
	for (int i = 0; i < matches.size(); i++) {
		total += matches[i].get_races();
	}
	return total;
}



