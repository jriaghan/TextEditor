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
  /** List shall be a doubly-linked list that would be the basis of
  storing text used by the program.*/
	struct List
	{
		struct Node
		{
			const char * x;
			Node * next;
			Node * prev;
			Node(const char * chr);
			Node(const char * chr, Node * prv, Node * nxt);
			~Node();
		};
    List();
    /** Should display each item in the List, followed by a newline */
    void dispList();
    /** Should add an item on the tail of the list */
    void addtoList(const char * val);
    /**
    Should add an item before the index'th entry, starting from 0.
    For example, if index is 0, it should add before the zeroth entry (i.e.
    the head of the said list). Then, the new node is the index'th entry.

    If index is greater than the length of the list, or less than 0, print out
    an error to stdout, and do nothing.
    */
    void addByIndex(const char * val, int index);
    Node * head;
    Node * tail;
    /** The length of the list. It shall be modified after every "operation".
    */
    int length;
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










