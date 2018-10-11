//////////////////////////////////////////////////////////
// name: Grant Walter                                   //
// date: Sep 05, 2018                                   //
// file: Friends.cpp                                    //
// description: decides whether person is friend or not //
//////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

//function allows for the appearence of loading
void load () {
    cout << "Loading";
    for (int i = 0; i < 80; i++) {
        cout << ".";
        sleep_for(milliseconds(rand() % 350 + 50)); //provides "random" values for wait times.
        cout.flush(); //allows fuction to work
    }
    cout << endl;
}

int main () {
    srand (time(NULL));
	cout << "Welcome to Friends: the dating app that's taking the world by storm." <<endl;
	
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Hello " << name << ", we are now retrieving your files." <<endl;
	load (); //load function to create loading sequence
	
	//beginning questionare
	int rank = 0; //value to rank compatability
	int answer; //stores value from respondent's answer
	cout << "Beginning session(?'s are on a 1-3 scale: 1 = least, 3 = most): " << endl;
	
	
	//---------------------------------------------------------------------------------------------
	// Some questions have multiple questions. Questions may + or - rank  points to varible "rank"
	// rank will be used to distinguish how many answers were closest to my preferences.
	//---------------------------------------------------------------------------------------------
	
	//first question
	cout << "How likely would you be to go out to dinner?: ";
	cin >> answer;
	switch (answer) {
		case 1:
			cout << "Who put you on the planet, Ugh!";
			rank -= 5;
			break;
		case 2:
			rank += 10;
			break;
		case 3:
			rank += 20;
			cout << "What is your favorite thing to eat?: " <<endl << "	Burger(1)" <<endl << "	Salad(2)" <<endl <<"	Steak(3)" <<endl;
			cout << "Answer: ";
			cin >> answer;
			switch (answer) {
				case 1:
					rank += 20;
					break;
				case 2:
					rank += 10;
					break;
				case 3:
					rank += 20;
					break;
			}
			break;
	}
	cout <<endl;
	
	//second question
	cout << "How likely would you be to get a drink?: ";
	cin >> answer;
	switch (answer) {
		case 1:
			cout << "How unfortunate." << endl;
			break;
		case 2:
			rank += 10;
		case 3:
			rank +=20;
			cout << "What drink: " <<endl << "	Soda(1)" <<endl << "	Water(2)" <<endl <<"	Coffee(3)" <<endl;
			cout << "Answer: ";
			cin >> answer;
			switch (answer) {
				case 1:
					rank += 10;
					break;
				case 2:
					rank += 10;
					break;
				case 3:
					rank += 20;
					break;
			}
			break;
	}
	cout <<endl;
	
	//third question
	cout << "How much do you enjoy boardgames?: ";
	cin >> answer;
	switch (answer) {
		case 1:
			break;
		case 2:
			rank += 10;
			cout << "Okay response." <<endl;
			break;
		case 3:
			rank += 20;
			cout <<"Which of the following games is your favorite: " <<endl << "	Snakes and Ladders(1)" <<endl << "	Candy Land(2)" <<endl <<"	Monopoly(3)" <<endl;
			cout << "Answer: ";
			cin >> answer;
			switch (answer) {
				case 1:
					rank += 10;
					break;
				case 2:
					break;
				case 3:
					rank += 20;
					break;
			}
			break;
	}
	cout <<endl;
	
	//fourth question
	cout << "How joyful are you?: ";
	cin >> answer;
	switch (answer) {
		case 1:
			break;
		case 2:
			rank += 10;
			break;
		case 3:
			rank += 20;
			break;
	}
	cout <<endl;
	
	//fith question
	cout << "How greatly do you enjoy skiing?: ";
	cin >> answer;
	switch (answer) {
		case 1:
			break;
		case 2:
			rank += 10;
			break;
		case 3:
			rank += 20;
			break;
	}
	cout <<endl;
	
	
	//sixth question
	answer = 0;
	while (answer < 3) { //loop is intentional: classical music is the only answer...
		cout << "How would you rank classical music?: ";
		cin >> answer;
		switch (answer) {
			case 1:
			case 2:
				break;
			case 3:
				cout << "Thank you for choosing the correct answer." <<endl;
				break;
		}
	}
	cout <<endl;
	
	//prints friendship ranking
	if (rank <= 30) {
		cout << "Go home, it's getting late anyway." <<endl;
	}
	else if (rank >60) {
		cout << "You would be a good friend." <<endl;
	}
	else {
		cout << "You would be an okay friend." <<endl;
	}
	cout <<endl;
	
	//small exit "function"
	string exit;
	cout << "Press any button and then the enter key to exit.";
	cin >> exit;
	
	return 0;
}