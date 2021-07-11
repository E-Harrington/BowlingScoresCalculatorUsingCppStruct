/********************************************************************************
* Week 07 Programming Assignment
* Eric Harrington
*********************************************************************************
********************************before main**************************************
* 1: declare and initialize const ints for the number of bowlers and their score 
*    counts; also, declare const ints--for char count and line count--for a 2D 
*    array that will that will allow program title to be printed using fewer 
*    lines of code than previous version used
* 
* 2: declare a struct "bowler" with a string member for name, an int array for 
*    scores, and an int for average score
* 
* 3: declare function prototypes "bool GetBowlingData", "void GetAverageScore", 
*    and "void PrettyPrintResults".
* 
* 
* ******************************within main**************************************
* 4: declare string filename, bowler array player, and bool dataCheck
* 
* 5: prompt user for name of file and assign to string filename with cin
* 
* 6: call function GetBowlingData and assign its return value to bool dataCheck
* 
* 7: setup if-else statements; if dataCheck is false, output to console that the 
*    program is closing and program closes; if dataCheck is true, program continues
* 
********************************after main***************************************
* 8: define GetBowlingScores: parameters are filename and array of struct bowler;
*    declare ifstream infile and open with filename; if infile is false, output to
*    "error opening file" and return false; if infile is true, nested for loops
*	 begin extracting data from file and assigning it to struct members name and
*    scores array; within outer for loop, inlude if statement that checks whether
*    infile is false; if infile is false, output to console "error extracting name"
*    and return false; within inner for loop, also include if statement that checks
*    whether infile is false; if infile is false, output to console "error extracting
*    score" and return false; after nested for loops, close file and return true
* 
* 9: define GetAverageScore: declare double sum and initialize it to zero; use nested
*    for loops; inner loop increments sum by each set of scores within scores array;
*    outer loop assigns struct member avgScore to sum divided by scoresCount after 
*	 the quotient is rounded using cmath function and then reassigns sum to zero
*
* 10: define PrettyPrintResults:declare and initialize const ints for 2D array, 
*     an int for animation timing, an enum for 2D array indexing, and a 2D array of 
*     size 13 with subarrays of size 8; the members of the subarrays are the lines of 
*     ASCII art characters; use for loop and 2D array for title-scrolling animation; 
*     then use nested for loops to display name, scores, and average score from from 
*     each member of struct array
* 
********************************within main**************************************
* 11: within else statement, call functions with appropiate arguments
* 
*******************************program revision**********************************
* 12: alter code so program reads 5 scores from text file, calculates a new 
*     average, and prints the 5th score and the new average to the console

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <thread>
#include <chrono>
using namespace std;

//Step 1
const int bowlersCount = 10;
const int scoresCount = 5;//Step 12
const int uniqueCharacters = 13;
const int lineCount = 8;

//Step 2
struct bowler 
{
	string name = " ";
	int scores[scoresCount]{}; 
	int avgScore = 0;
};

//Step 3
bool GetBowlingData(string filename, bowler player[]);
void GetAverageScore(bowler player[]);
void PrettyPrintResults(bowler player[]);









int main()
{
	//Step 4
	string filename;
	bowler player[bowlersCount];
	bool dataCheck; 

	//Step 5
	cout << "Enter the file name to process: ";
	cin >> filename;

	//Step 6
	dataCheck = GetBowlingData(filename, player);

	//Step 7
	if (!dataCheck)
	{
		cout << "Program closing..." << endl;
		system("pause");
	}
	
	else
	{
		system("cls");
		//Step 11
		GetAverageScore(player);
		PrettyPrintResults(player);

	}
	
	return 0;
}

//Step 8
bool GetBowlingData(string filename, bowler player[])
{
	ifstream infile;
	infile.open(filename);

	if (!infile)
	{
		infile.close();
		cout << "Error opening file. Check file name and directory." << endl;
		return false;
	}

	else
	{
		for (int iBowler = 0; iBowler < bowlersCount; iBowler++)
		{
			infile >> player[iBowler].name;
			if (!infile)
			{
				cout << "Error reading name from file. Check contents of file." << endl;
				return false;
			}
			
			for (int score = 0; score < scoresCount; score++)
			{
				infile >> player[iBowler].scores[score];
				if (!infile)
				{
					cout << "Error reading score from file. Check contents of file." << endl;
					return false;
				}
			}

		}

		infile.close();
		return true;
	}
}

//Step 9
void GetAverageScore(bowler player[])
{
	double sum = 0.0;

	for (int iBowler = 0; iBowler < bowlersCount; iBowler++)
	{
		for (int score = 0; score < scoresCount; score++)
			sum += player[iBowler].scores[score];

		player[iBowler].avgScore = round(sum / scoresCount);
		sum = 0.0;
	}
}

//Step 10
void PrettyPrintResults(bowler player[])
{
	const int uniqueCharacters = 13;
	const int lineCount = 8;

	int scrollTime = 150;

	//type enum makes it much easier to index 2D array of ASCII art characters
	enum font_pos{ B, o, w, l, i, n, g, S, c, r, e, s, space};
	
	//
	string asciiFont[uniqueCharacters][lineCount]
	{
		{" ____  ", "|  _ \\ ", "| |_) |", "|  _ < ", "| |_) |", "|____/ ", "       ", "       "},//B

		{"       ", "       ", "  ___  ", " / _ \\ ", "| (_) |", " \\___/ ", "       ", "       "},//o

		{"          ", "          ", "__      __", "\\ \\ /\\ / /", " \\ V  V / ", "  \\_/\\_/  ", "          ", "          "},//w

		{" _ ", "| |", "| |", "| |", "| |", "|_|", "   ", "   "},//l

		{" _ ", "(_)", " _ ", "| |", "| |", "|_|", "   ", "   "},//i

		{"       ", "       ", " _ __  ", "| '_ \\ ", "| | | |", "|_| |_|", "       ", "       "},//n

		{"       ", "       ", "  __ _ ", " / _` |", "| (_| |", " \\__, |", "  __/ |", " |___/ "},//g

		{"  _____ ", " / ____|", "| (___  ", " \\___ \\ ", " ____) |", "|_____/ ", "        ", "        "},//S

		{"      ", "      ", "  ___ ", " / __|", "| (__ ", " \\___|", "      ", "      "},//c

		{"      ", "      ", " _ __ ", "| '__|", "| |   ", "|_|   ", "      ", "      "},//r

		{"      ", "      ", "  ___ ", " / _ \\", "|  __/", " \\___|", "      ", "      "},//e

		{"     ", "     ", " ___ ", "/ __|", "\\__ \\", "|___/", "     ", "     ",},//s

		{"     ", "     ", "     ", "     ", "     ", "     ", "     ", "     "}//space
	};


	//Step 12 also below; setw() altered in numerous places to accomodate 5th score
	//********************************begin scrolling title******************************
	//from right to left, each subsequent block adds the next ASCII character from 2D array
	//this produces a right-to-left scrolling effect for title
	cout << setw(20) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[s][index] << endl;

	cout << setw(20) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(26) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(26) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(32) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(32) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(39) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[o][index] << asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(39) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(45) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[c][index] << asciiFont[o][index] << asciiFont[r][index] 
		<< asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(45) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(53) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index] << asciiFont[r][index]
		<< asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(53) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(58) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index]
		<< asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(58) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(65) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[g][index] << asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] 
		<< asciiFont[o][index] << asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(65) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(72) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[n][index] << asciiFont[g][index] << asciiFont[space][index] << asciiFont[S][index] 
		<< asciiFont[c][index] << asciiFont[o][index] << asciiFont[r][index] << asciiFont[e][index] 
		<< asciiFont[s][index] << endl;

	cout << setw(72) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(75) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[i][index] << asciiFont[n][index] << asciiFont[g][index] << asciiFont[space][index] 
		<< asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index] << asciiFont[r][index] 
		<< asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(75) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(78) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[l][index] << asciiFont[i][index] << asciiFont[n][index] << asciiFont[g][index]
		<< asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index]
		<< asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(78) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(88) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[w][index] << asciiFont[l][index] << asciiFont[i][index] << asciiFont[n][index] 
		<< asciiFont[g][index] << asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] 
		<< asciiFont[o][index] << asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(88) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(95) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[o][index] << asciiFont[w][index] << asciiFont[l][index] << asciiFont[i][index] 
		<< asciiFont[n][index] << asciiFont[g][index] << asciiFont[space][index] << asciiFont[S][index] 
		<< asciiFont[c][index] << asciiFont[o][index] << asciiFont[r][index] << asciiFont[e][index] 
		<< asciiFont[s][index] << endl;

	cout << setw(95) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//*********************************************************************************
	cout << setw(102) << setfill('=') << '=' << endl;
	for (int index = 0; index < lineCount; index++)
		cout << asciiFont[B][index] << asciiFont[o][index] << asciiFont[w][index]
		<< asciiFont[l][index] << asciiFont[i][index] << asciiFont[n][index] << asciiFont[g][index]
		<< asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index]
		<< asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(102) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	system("cls");
	//***************************end scrolling title*****************************************

	//**************************print title on more time*************************************
	cout << setw(105) << setfill('=') << '=' << endl;

	for (int index = 0; index < lineCount; index++)
		cout << "         " << asciiFont[B][index] << asciiFont[o][index] << asciiFont[w][index]
		<< asciiFont[l][index] << asciiFont[i][index] << asciiFont[n][index] << asciiFont[g][index]
		<< asciiFont[space][index] << asciiFont[S][index] << asciiFont[c][index] << asciiFont[o][index]
		<< asciiFont[r][index] << asciiFont[e][index] << asciiFont[s][index] << endl;

	cout << setw(105) << setfill('=') << '=' << setfill(' ') << endl << endl << endl;
	//******************************************************************************************

	//******************************print headers for data**************************************
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	cout << setw(15) << "Name" << setw(15) << "Score 1" << setw(15) << "Score 2" << setw(15)
	<< "Score 3" << setw(15) << "Score 4" << setw(15) << "Score 5" << setw(15) << "Avg Score" << endl;
	cout << setw(105) << setfill('-') << '-' << setfill(' ') << endl;
	this_thread::sleep_for(chrono::milliseconds(scrollTime));
	//******************************************************************************************

	//*******************************print data from struct array*******************************
	for (int iBowler = 0; iBowler < bowlersCount; iBowler++)
	{
		cout << setw(15) << player[iBowler].name;
		for (int score = 0; score < scoresCount; score++)
			cout << setw(15) << player[iBowler].scores[score];

		cout << setw(15) << player[iBowler].avgScore << endl;
		cout << setw(105) << setfill('-') << '-' << setfill(' ') << endl;
		this_thread::sleep_for(chrono::milliseconds(scrollTime));
	}
	//********************************************************************************************
	
}


