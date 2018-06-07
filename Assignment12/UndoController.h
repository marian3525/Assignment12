#pragma once
#include <Operation.h>
#include <stack>
#include "Repository.h"
#include "Add.h"
#include "Remove.h"
#include "Update.h"
#include "Like.h"
#include "Dislike.h"
#include "Exception.h"
using namespace std;

class UndoController
{
public:
	UndoController(Repository& repo, Repository& watchlist) : repo{ repo }, watchlist{ watchlist } {};
	void onAdd(string title, string presenter, int duration, int likes, string link, string repoType);
	void onRemove(string title, string repoType);
	void onUpdate(string title, string presenter, int duration, int likes, string link, string repoType, string newPresenter, int newDuration, int newLikes, string newLink);
	void onLike(string title);
	void undo();
	void redo();
	void clearStacks();
	void clearUndoStack();
	void clearRedoStack();
private:
	stack<Operation*> undoStack;
	stack<Operation*> redoStack;
	Repository& repo;
	Repository& watchlist;
};

