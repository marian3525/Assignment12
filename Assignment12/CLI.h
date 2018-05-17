#pragma once
#include "Controller.h"

class CLI {
public:
	CLI(Controller& controller) : controller{ controller } {};
	~CLI();
	void start();
private:
	Controller controller;
	string getCommand(string input);
	vector<string> getParams(string input);
	int getMinutes(string input);
	int getSeconds(string input);
	string HTMLFilename = "watchlist.html";
	string CSVFilename = "watchlist.csv";
	void showResults(vector<Tutorial> results, string name);
};
