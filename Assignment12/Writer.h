#pragma once
#include "Repository.h"

class Writer {
public:
	virtual void write(Repository& repo) = 0;
};
