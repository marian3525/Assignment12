 #include <string>
#include <iostream>
#include <algorithm>
#include "Controller.h"
#include "CLI.h"
#include "Exception.h"
#include "Writer.h"
#include "HTMLWriter.h"
#include "CSVWriter.h"
#include <Windows.h>
#include <vector>
#include <iterator>
#include <sstream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
using namespace std;

vector<string> split(string str) {
	stringstream ss(str);
	string token;
	vector<string> result;
	char delim = ' ';
	while (getline(ss, token, delim)) {
		result.push_back(token);
	}
	return result;
}

string getInput() {
	/**
	* Read user input from the keyboard
	* Returns the read string or "" if an endline char is read
	*/
	string input;
	char input_cstr[100];
	cin.getline(input_cstr, 100);
	return string(input_cstr);
}

string CLI::getCommand(string input) {
	vector<string> splitString = split(input);
	return splitString[0];
}
vector<string> CLI::getParams(string input) {
	vector<string> splitString = split(input);
	splitString.erase(splitString.begin());
	return splitString;
}

#pragma warning(disable : 4996)
int CLI::getMinutes(string s) {
	/**
	* s: string in the format xmys, where x and y are integers
	* Return the number of minutes as an int
	*/
	size_t endPosition = s.find("m");
	int minutes;
	char* aux = new char[endPosition + 1];
	//put the substr. with the number of minutes in the aux string
	s.copy(aux, endPosition, 0);  //copy endPosition chars starting from 0
	aux[endPosition] = 0;
	sscanf_s(aux, "%d", &minutes);
	delete[] aux;
	return minutes;
}
#pragma warning(disable : 4996)
int CLI::getSeconds(string s) {
	/**
	* s: string in the format xmys, where x and y are integers
	* Return the number of seconds as an int
	*/
	size_t endPosition = s.find("s");
	size_t startPosition = s.find("m") + 1;
	int minutes;
	//12m30s
	//012345
	char* aux = new char[endPosition - startPosition + 1];
	//put the substr. with the number of seconds in the aux string
	s.copy(aux, endPosition - startPosition, startPosition);
	aux[endPosition - startPosition] = 0;
	sscanf_s(aux, "%d", &minutes);
	delete[] aux;
	return minutes;
}

void CLI::showResults(vector<Tutorial> results, string name) {
	/**
	* Show each tutorial in the result list and offer the option to like or go to the next
	* Continue until the user enters "done". If the end of the list is reached, "next" will provide the first tutorial
	* in the list
	* @param results: list of tutorials
	* @param name: The name the results were filtered by
	* @param n: number of tutorials in the list
	* @return None
	*/
	int index = 0;
	string response;
	if (!results.empty()) {
		do {
			cout << results[index].toString();
			cout << "Did you enjoy this tutorial? (yes/no or done to exit the submenu)" << endl;
			cin >> response;

			if (response == "yes") {
				this->controller.likeTutorial(results[index].getTitle());
				results = controller.filterByPresenter(name);    //reload the tutorials with the updated likes
				cout << "Liked. Add to watchlist?" << endl;
				cin >> response;
				if (response == "yes" || response == "add")
					//add the tutorial to the watch list if not added already

					try {
					this->controller.addToWatchList(results[index].getTitle());
					cout << "Tutorial added to your watchlist" << endl;
				}
				catch (const ControllerException& ce) {
					cout << "The current tutorial was already added to your watchlist" << endl;
				}
			}
			if (response == "no") {
				cout << "Too bad. Maybe the next one will be more interesting" << endl;
			}
			if (response == "next") {
				index++;
			}
			if (response == "done") {
				break;
			}
			if (index == results.size()) {
				cout << "Starting from the beginning of the list:" << endl;
				index = 0;
			}
		} while (true);
	}
	else {
		cout << "No tutorials" << endl;
	}
	cin.get();  //???
}

void CLI::start() {
	string command;
	string input;
	vector<string> params;
	bool stopped = false;
	bool adminMode = false;
	string mode = "";
	Writer* writer = nullptr;


	do {
		cout << "HTML or CSV mode for the watchlist?" << endl;
		cin >> mode;
	} while (mode != "html" && mode != "csv");
	if (mode == "html") {

		writer = (Writer*) new HTMLWriter(HTMLFilename);
	}
	if (mode == "csv") {
		writer = (Writer*) new CSVWriter(CSVFilename);
	}

	controller.setMode(writer);

	while (!stopped) {
		if (adminMode) {
			cout << "(admin)";
		}
		else {
			cout << "(user)";
		}
		printf(">>>");

		input = getInput();
		if (input == "") {
			continue;
		}
		params = split(input);

		command = params[0];
		params.erase(params.begin());

		if (command == "exit") {
			stopped = true;
		}

		if (command == "toadmin") {
			adminMode = true;
		}
		if (command == "touser") {
			adminMode = false;
		}
		if (adminMode) {
			//admin features
			if (command == "add") { //no leaks
									//add a tutorial
									//add <title> <presenter> <duration: xmys> <likes> <link>
				string title, presenter, link;
				int duration, likes;

				title = string(params[0]);
				presenter = params[1];
				duration = getMinutes(params[2]) * 60 + getSeconds(params[2]);

				//sscanf_s(params[3], "%d", &likes);
				likes = stoi(params[3]);

				link = params[4];
				try {
					this->controller.addTutorial(title, presenter, duration, likes, link);
					controller.sync();
				}
				catch (const ValidatorException& ve) {
					//cout << ve.getMessage();
				}
			}
			if (command == "remove") {  //no leaks
										//remove <tutorial_title>
				string title = params[0];
				try {
					this->controller.removeTutorial(title);
					controller.sync();
				}
				catch (const ControllerException& ce) {
					//cout << ce.getMessage();
				}
				catch (const ValidatorException& ve) {
					//cout << ve.getMessage();
				}
			}
			if (command == "update") { //no leaks
				string title, presenter, link;
				int duration, likes;
				title = string(params[0]);
				presenter = params[1];
				duration = getMinutes(params[2]) * 60 + getSeconds(params[2]);

				likes = stoi(params[3]);
				link = params[4];

				try {
					this->controller.updateTutorial(title, presenter, duration, likes, link);
					controller.sync();
				}
				catch (const ControllerException& ce) {
					//cout << ce.getMessage();
				}
				catch (const ValidatorException& ve) {
					//cout << ve.getMessage();
				}
			}
			if (command == "print") { //no leaks
				vector<string> output = this->controller.getAllPrintable();
				for (const string &current : output)
					cout << current, cout << endl;
			}
		}
		else {
			//user features

			if (command == "watch") {
				if (mode == "html") {
					controller.write();
				}
				if (mode == "csv") {
					controller.write();
				}
			}

			if (command == "filter") {
				//filter "presenterName"
				string name;

				for_each(params.begin(), params.end(), [](const string& s) {cout << s << endl; });

				if (params.size() > 0) {
					if (params.size() == 2)
						name = string(params[0]) + string(" ") + string(params[1]);
					if (params.size() == 1) {
						name = string(params[0]);
					}

					vector<Tutorial> results = controller.filterByPresenter(name);

					showResults(results, name);
				}
				else {
					vector<Tutorial> results = controller.filterByPresenter(string(""));

					showResults(results, "");
				}
			}
			if (command == "remove") {
				try {
					controller.deleteFromWatchlist(params[0]);
				}
				catch (const RepositoryException& re) {
					//cout << re.getMessage();
				}
			}
			if (command == "print") { //no leaks
				cout << "Watch list:" << endl;
				vector<Tutorial> tutorials = this->controller.getWatchList();
				if (tutorials.empty()) {
					cout << "Your watch list is empty!" << endl;
				}
				else {

					for (const auto &tutorial : tutorials) {
						cout << tutorial.toString() << endl;
					}
				}
			}
		}
	}
}

CLI::~CLI() {
}
