#pragma once
#include "Writer.h"
#include "Repository.h"

class CSVWriter : Writer {
public:
	void write(Repository& repo) override;
	CSVWriter(const string& filename);
private:
	string filename;
};
