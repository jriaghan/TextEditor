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

namespace textEditor
{
	class List
	{
		struct Node
		{
			char x;
			Node *next;
		};
		
		public:
			List();
			void dispList(Node *head);
			void addtoList(char val);
			
		private:
			Node *head;
		
	};
	
	void start();

	
}

#endif










