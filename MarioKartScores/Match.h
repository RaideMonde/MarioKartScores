#pragma once
#ifndef MATCH_H_
#define MATCH_H_
#include <string>

class Match
{
private:
	/** The date of the match */
	std::string date;
	/** The number of races */
	int races;
	/** Charankwanwal's Score */
	int CKScore;
	/** Jasleen's Score */
	int JasScore;

public:
	// Constructors
	/** Constructor with given value
		@param day The date of the match
		@param races The number of races played that day
		@param CScore Charanbear's Score
		@param JScore Jasleen's Score
	*/
	Match(std::string day, int races, int CScore, int JScore) :
		date(day), races(races), CKScore(CScore), JasScore(JScore) {}

	// Accessors Functions
	/** Returns the date of the match */
	std::string get_date() const { return date; }

	/** Returns the number of races */
	int get_races() const { return races; }

	/** Returns Charankanwal's Score of the day */
	int get_CKScore() const {	return CKScore;	}

	/** Returns Jasleen's Score of the day */
	int get_JasScore() const { return JasScore; }

	// Other Functions
	/** Prints out the information of a match 
		@param os The target ostream
		@param match The match to be printed
		@return the updated output stream 
	*/
	friend std::ostream& operator<<(std::ostream &os, const Match& match)
	{
		os << "Date: " << match.get_date() << '\n'
			<< "The number of races played was " << match.get_races() << '\n'
			<< "Charankwanwal's score was: " << match.get_CKScore() << '\n'
			<< "Jasleen's score was : " << match.get_JasScore() << '\n';
		return os;
	}
};

#endif