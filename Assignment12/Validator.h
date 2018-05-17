#pragma once
using namespace std;

class Validator {
public:
	static void validateAdd(string title, string presenter, int duration, int likes, string link);
	static void validateRemove(string title);
	static int validateUpdate(string title, string presenter, int duration, int likes, string link);
	static void validateAddToWatchlist(string title);
};