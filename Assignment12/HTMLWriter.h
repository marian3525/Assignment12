#pragma once

#include "Writer.h"
#include "Repository.h"

class HTMLWriter : Writer {
public:
	void write(Repository& repo) override;
	HTMLWriter(const string& filename);
private:
	Repository repo{ true };
	string filename;
};