
// PLEASE COMPLETE THE NEXT COMMENTS WITH:
// your student id: 20627493
// your last name: Jia
// your first name: Hengli
// what you prefer to be called: Krish
// a phonetic spelling of what you prefer to be called: Krish

// WRITE YOUR NAME AFTER THIS COMMENT TO ACKNOWLEDGE THAT YOU HAVE READ AND
// UNDERSTOOD IT: The purpose of 22B programming projects is for me to gain
// understanding and practice as a developer of original software and to provide
// a complete record of that development for evaluation. Understanding this, I
// will not paste code into my 22B projects. I will author code originally, and
// perform editing of my code soley within this IDE. Understood and agreed:
// <your name here> Hengli Jia


#include "ConsoleGrid.h"
#include "ConsoleInput.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string MessageLine(int turnCount) {
	ostringstream messageBuf;
	messageBuf << "Turn: " << turnCount << " (press 'q' to quit)";
	return messageBuf.str();
}

int main() {
	int playerRow = 5;
	int playerCol = 5;
	int turnCount = 0;

	ConsoleGrid grid(10, 20);
	UserConsoleInput ci;

	// DJH: Remember DRY. There's lot of repeated code in the various cases.
	// DJH: There's no need to call drawCharAt in any of the cases because
	// drawCharAt is always called above, before the switch.

	while (true) {
		grid.drawCharAt(playerRow, playerCol, '@', Color::cyan);
		grid.setStatusLine(MessageLine(turnCount));

		char cmd = ci.nextCommandKey(0);

		int newPlayerRow = playerRow;
		int newPlayerCol = playerCol;

		switch (cmd) {
		case arrowUpKey:
			newPlayerRow -= 1;
			break;
		case arrowDownKey:
			newPlayerRow += 1;
			break;
		case arrowRightKey:
			newPlayerCol += 1;
			break;
		case arrowLeftKey:
			newPlayerCol -= 1;
			break;
		case '?':
			cout << "Position: "
				 << "Row " << newPlayerRow << " Col " << newPlayerCol;
			break;
		case 'q':
		case 'Q':
			goto gameOver;
			break;
		default:
			break;
		}

		// HJ Fixed
		if (newPlayerRow >= 0 && newPlayerRow < 10 && newPlayerCol >= 0 &&
			newPlayerCol < 20) {
			grid.eraseCharAt(playerRow, playerCol);
			playerRow = newPlayerRow;
			playerCol = newPlayerCol;
			++turnCount;
		} else {
			newPlayerRow = playerRow;
			newPlayerCol = playerCol;
		}
	}

gameOver:
	cout << endl;
	cout << "Final Turn: " << turnCount << endl;
	cout << "Final Position: "
		 << "Row " << playerRow << " Col " << playerCol;
	return 0;
}

// DJH: -3, Hard-coded (and repeated) use of literal bounds values
// Krish: I have fixeded the problem form 80 to 89.
// DJH: Good job. 17/20