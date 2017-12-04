#include "Pipe.h"
#include <iostream>
#include <thread>
#include "gameManager.h"

using namespace std;
void main()
{

	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	gameManager manager(msgToGraphics);
										  // get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	

	while (msgFromGraphics != "quit")
	{
		// should handle the string sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		std::string answer = std::to_string(manager.makeTurn(msgFromGraphics));
		// YOUR CODE
		strcpy_s(msgToGraphics, answer.c_str()); // msgToGraphics should contain the result of the operation

											  // return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}