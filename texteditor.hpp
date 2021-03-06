/*
	COMMANDS:
		A - SAVE
		E - EXIT
		I - INSERT TO LINE n
		D - DELETE LINES n to m
		L - DISPLAY LINES

*/


//include guard
#ifndef TEXTEDITOR_HPP
#define TEXTEDITOR_HPP 1

//dependencies
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace textEditor
{
	class List
	{
		struct Node
		{
			const char * x;
			Node *next;
			
		};

		public:
			List();
			void dispList(Node *head);
			void addtoList(const char * val);
			void addtoList(char * val);

		private:
			Node *head;

	};
	
	void userInput();
	
	/** The list that shall contain the text file to be written.
	A list of char*, wherein each char* is separated by "\n" in the
	actual file.
	*/
	static List masterList;

	/** The filename of the file to be read or written.
	*/
	static std::string fileName = "a.txt";

	void start();


}

#endif










