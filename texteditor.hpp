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
  /** List shall be a singly-linked list that would be the basis of
  storing text used by the program. For efficiency sake, this should
  be a doubly-linked list by release of v0.1, thus being easier to
  modify. */
	struct List
	{
		struct Node
		{
			const char * x;
			Node *next;
			Node(const char * x, Node * next = NULL);
		};
    List();
    void dispList();
    void addtoList(const char * val);
    Node *head;

	};

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










