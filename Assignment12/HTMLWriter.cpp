#include "HTMLWriter.h"
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Tutorial.h"
#include "Repository.h"


void HTMLWriter::write(Repository& repo) {
	vector<Tutorial> all = repo.getAll();
	string output = "";
	ofstream f(filename);

	output += "<!DOCTYPE html>\n";
	output += "<html>\n";
	output += "\t<head>\n";
	output += "\t\t<title>Watchlist</title>\n";
	output += "\t</head>\n";
	output += "\t<body>\n";
	output += "\t\t<table border=\"1\">\n";

	output += "\t\t<tr>\n";
	output += "\t\t\t<td>Title</td>\n";
	output += "\t\t\t<td>Presenter</td>\n";
	output += "\t\t\t<td>Duration</td>\n";
	output += "\t\t\t<td>Likes</td>\n";
	output += "\t\t\t<td>YT Link</td>\n";
	output += "\t\t</tr>";

	for (auto t : all) {

		string duration = t.getFormattedDuration();
		string likes = to_string(t.getLikes());

		output += "\t<tr>\n";

		output += "\t\t\t<td>" + t.getTitle() + "</td>\n";
		output += "\t\t\t<td>" + t.getPresenter() + "</td>\n";
		output += "\t\t\t<td>" + t.getFormattedDuration() + "</td>\n";
		output += "\t\t\t<td>" + to_string(t.getLikes()) + "</td>\n";
		output += "\t\t\t<td><a href=" + t.getLink() + "\">Link</a></td>\n";

		output += "</tr>\n";
	}
	output += "\t\t</table>\n";
	output += "\t</body>\n";
	output += "</html>\n";

	f << output;
	HWND hwnd = GetDesktopWindow();
	ShellExecute(hwnd, L"open", L"watchlist.html", NULL, NULL, SW_MAXIMIZE);
}

HTMLWriter::HTMLWriter(const string& filename) {
	this->filename = filename;
}
