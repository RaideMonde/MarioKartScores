#pragma once
#ifndef MATCHES_H_
#define MATCHES_H_
#include <vector>
#include "Match.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Matches
{
private:
	vector<Match> matches;

	// Private functions

	/** Get CK's highest score */
	int get_ck_highest_score();

	/** Get Jasleen's highest score */
	int get_jas_highest_score();

	/** Get CK's lowest score */
	int get_ck_lowest_score();

	/** Get Jasleen's lowest score */
	int get_jas_lowest_score();

	void snapshot(int, int, int);

public:

	/** Adds a match to the sets of matches */
	void add_match(Match match) { matches.push_back(match); }

	/** Returns the size of the matches */
	size_t size() { return matches.size(); }

	/** Prints out the matches starting from the 
		earliest to the latest.
	*/
	void print_matches();

	/** Get the total score of all of CK's matches */
	int get_ck_total();

	/** Get the total score of all of Jasleen's matches */
	int get_jas_total();

	/** get the average score for each race */
	float get_race_average(int);

	/** get the average score for each match */
	float get_match_average(int);

	/** Get the total number of races across all matches */
	int get_num_races();

	/** Print the highest and lowest scores */
	void print_ck_highest()	{	cout << "Charankanwal's highest score is: "	<< get_ck_highest_score()	<< endl;}
	void print_ck_lowest()	{	cout << "Charankanwal's lowest score is: "	<< get_ck_lowest_score()	<< endl;}
	void print_jas_highest(){	cout << "Jasleen's highest score is: "		<< get_jas_highest_score()	<< endl;}
	void print_jas_lowest()	{	cout << "Jasleen's lowest score is: "		<< get_jas_lowest_score()	<< endl;}

	void snapshot() { snapshot(0, 0, 0); };
};

#endif