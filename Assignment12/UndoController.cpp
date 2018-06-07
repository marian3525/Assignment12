#include "UndoController.h"

void UndoController::onAdd(string title, string presenter, int duration, int likes, string link, string repoType)
{
	/*
		repoType - the repo the item was added to, main/watchlist
		
	*/
	Operation* operation;
	if (repoType == "main") {
		operation = (Operation*) new Remove{ title, repo };
		undoStack.push(operation);

	}
	else {
		operation = (Operation*) new Remove{ title, watchlist };
		undoStack.push(operation);
	}

}

void UndoController::onRemove(string title, string repoType)
{
	/*
				**called before removing the object form the repo!!!
	*/
	Operation* operation;
	if (repoType == "main") {

		Tutorial t = repo.getByTitle(title);
		string presenter = t.getPresenter();
		int duration = t.getDuration();
		int likes = t.getDuration();
		string link = t.getLink();

		operation = (Operation*) new Add{ title, presenter, duration, likes, link, repo };
		undoStack.push(operation);
	}
	if (repoType == "watchlist") {


		Tutorial t = watchlist.getByTitle(title);
		string presenter = t.getPresenter();
		int duration = t.getDuration();
		int likes = t.getDuration();
		string link = t.getLink();

		operation = (Operation*) new Add{ title, presenter, duration, likes, link, watchlist };
		undoStack.push(operation);
	}

}

void UndoController::onUpdate(string title, string presenter, int duration, int likes, string link, string repoType, 
	 string newPresenter, int newDuration, int newLikes, string newLink)
{
	/*
				**called before removing the object form the repo!!!
	*/
	Operation* operation;
	if (repoType == "main") {
		operation = (Operation*) new Update(title, presenter, duration, likes, link, repo);
		undoStack.push(operation);

	}
	else {
		operation = (Operation*) new Update(title, presenter, duration, likes, link, watchlist);
		undoStack.push(operation);
	}
	
}

void UndoController::onLike(string title) {

	Operation* operation;
	operation = (Operation*) new Dislike{ title, repo, watchlist };
	undoStack.push(operation);
}

void UndoController::undo(){
	/*
		Called by the controller. 
		undoes the last operation if there is such a thing
	*/
	if (undoStack.size() > 0) {
		Operation* op = undoStack.top();
		Operation* reop;

		try {
			string classType = op->getClassName();
			//depending on the type of operation being undone, push the opposite operation into the redo stack
			if (classType == "Add") {
				//push a remove
					reop = (Operation*) new Remove(op->getTitle(), op->getRepo());
			}
			if (classType == "Remove") {
				//push an add
				Tutorial t = op->getRepo().getByTitle(op->getTitle());
				reop = (Operation*) new Add(t.getTitle(), t.getPresenter(), t.getDuration(), t.getLikes(), t.getLink(), 
											op->getRepo());
			}
			if (classType == "Update") {
				//push an update with the old params
				Tutorial t = op->getRepo().getByTitle(op->getTitle());
				reop = (Operation*) new Update(t.getTitle(), t.getPresenter(), t.getDuration(), t.getLikes(), t.getLink(), 
											op->getRepo());

			}

			if (classType == "Like") {
				reop = (Operation*) new Dislike{ op->getTitle(), repo, watchlist };
			}

			if (classType == "Dislike") {
				reop = (Operation*) new Like{ op->getTitle(), repo, watchlist };
			}
			
			redoStack.push(reop);

			op->execute();
		}
		catch (RepositoryException& re) {
		}

		undoStack.pop();
	}
}

void UndoController::redo() {

	if (redoStack.size() > 0) {
		Operation* op = redoStack.top();
		Operation* unop;

		try {
			string classType = op->getClassName();
			//depending on the type of operation being undone, push the opposite operation into the redo stack
			if (classType == "Add") {
				//push a remove
				unop = (Operation*) new Remove(op->getTitle(), op->getRepo());
			}
			if (classType == "Remove") {
				//push an add
				Tutorial t = op->getRepo().getByTitle(op->getTitle());
				unop = (Operation*) new Add(t.getTitle(), t.getPresenter(), t.getDuration(), t.getLikes(), t.getLink(),
					op->getRepo());
			}
			if (classType == "Update") {
				//push an update with the old params
				Tutorial t = op->getRepo().getByTitle(op->getTitle());
				unop = (Operation*) new Update(t.getTitle(), t.getPresenter(), t.getDuration(), t.getLikes(), t.getLink(),
					op->getRepo());
			}
			if (classType == "Like") {
				//push a like of -1 if like(1) or like of 1 if like(-1)
				//TODO
				unop = (Operation*) new Dislike{ op->getTitle(), repo, watchlist };
			}
			if (classType == "Dislike") {
				unop = (Operation*) new Like{ op->getTitle(), repo, watchlist };
			}
			undoStack.push(unop);

			op->execute();
		}
		catch (RepositoryException& re) {
		}

		redoStack.pop();
	}
}

void UndoController::clearUndoStack() {
	undoStack.empty();
}

void UndoController::clearRedoStack() {
	redoStack.empty();
}

void UndoController::clearStacks() {
	while (!undoStack.empty()) { undoStack.pop(); }
	while (!redoStack.empty()) { redoStack.pop(); }
}