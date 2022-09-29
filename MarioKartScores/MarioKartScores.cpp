// MarioKartScores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "Matches.h"
using namespace std;


int main()
{
	Matches matches;
	//vector<Match> matches;
	ifstream inFile;

	inFile.open("RecordedScores.txt");
	// Check for Error
	if (inFile.fail()) {
		cerr << "File failed to open\n";
		getchar();
		exit(1);
	}

	// Take the data from "Recorded Scores.txt" and insert them into a vector
	while (!inFile.eof()) {
		string new_date;
		string temp;
		int num_races;
		int ck_score;
		int jas_score;

		// Gets the date from the file
		getline(inFile, new_date);

		// Gets the number of races from the file
		getline(inFile, temp);
		num_races = atoi(temp.c_str());

		// Sets Charankanwal's Score
		getline(inFile, temp);
		ck_score = atoi(temp.c_str());

		// Sets Jasleen's Score
		getline(inFile, temp);
		jas_score = atoi(temp.c_str());

		Match new_match(new_date, num_races, ck_score, jas_score);

		matches.add_match(new_match);
	}

	int CK_Total = matches.get_ck_total();
	int Jas_Total = matches.get_jas_total(); 
	int numRaces = matches.get_num_races();

	while (true) {
		int command;
		cout << "Select an action: \n"
			<< "0: Quit \n"
			<< "1: Print matches\n"
			<< "2: Print totals\n" 
			<< "3: Print lead\n" 
			<< "4: Print race average\n"
			<< "5: Print match Averages\n"
			<< "6: Get high/low\n" 
			<< "7: Snapshot " << endl;
		cin >> command;
		switch (command){
			cout << endl;
		case 0:
			exit(1);

		case 1:	// Prints matches
			matches.print_matches();
			break;

		case 2:	// Prints total scores
			cout << "Charankanwal currently has " << CK_Total << " points" << endl;
			cout << "Jasleen currently has " << Jas_Total << " points" << endl << endl;
			break;

		case 3:	// Prints the lead
			if (CK_Total > Jas_Total) {
				cout << "Charankanwal is leading by " << CK_Total - Jas_Total << " points\n" << endl;
			} else if (Jas_Total > CK_Total) {
				cout << "Jasleen is leading by " << Jas_Total - CK_Total << " points\n" << endl;
			}
			else if (CK_Total == Jas_Total) {
				cout << "OMG IS THIS A TIE!?" << endl;
			}
			break;

		case 4:	// prints the average race score
			cout << "Charankanwal averages " << matches.get_race_average(CK_Total) << " points per race " << endl;
			cout << "Jasleen averages " << matches.get_race_average(Jas_Total) << " points per race" << endl;
			cout << "There have been " << numRaces << " races\n" << endl;
			break;

		case 5:	// Prints the average match score
			cout << "Charankanwal averages " << matches.get_match_average(CK_Total) << " points per match" << endl;
			cout << "Jasleen averages " << matches.get_match_average(Jas_Total) << " points per match" << endl;
			cout << "There have been " << matches.size() << " matches" << endl;
			break;

		case 6: // Prints the highest/lowest score of either
			matches.print_ck_highest();
			matches.print_ck_lowest();
			cout << endl;
			matches.print_jas_highest();
			matches.print_jas_lowest();
			break;
		case 7: // Prints a snapshot after each match
			matches.snapshot();
			break;
		default:
			cout << "That's an invalid input you dummy " << endl;
			cout << "Press enter to continue" << endl << endl;
			break;
		}

		cout << "Press enter to continue " << endl;
		getchar();
		getchar();
	}

	getchar();
    return 0;
}