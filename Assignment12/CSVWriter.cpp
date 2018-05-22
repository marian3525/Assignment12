#include "CSVWriter.h"
#include "Tutorial.h"
#include "Repository.h"
#include <Windows.h>
#include <fstream>
#include <vector>

void CSVWriter::write(Repository& repo) {
	vector<Tutorial> all = repo.getAll();
	ofstream ofstream1(filename);

	for (const auto& t : all) {
		ofstream1 << t;
	}
	//for_each(all.begin(), all.end(), [&ofstream1](Tutorial& t){ofstream1<<t;});
	ofstream1.close();

	HWND hwnd = GetDesktopWindow();
	ShellExecute(hwnd, L"open", L"watchlist.csv", NULL, NULL, SW_MAXIMIZE);
}

CSVWriter::CSVWriter(const string& filename) {
	this->filename = filename;
}
