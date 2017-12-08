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
#include <string>

namespace textEditor
{
  /**
   * @class List
   * @file texteditor.hpp
   * @brief A doubly-linked list of List::Node
   *
   * A doubly-linked list consisting of a head, a tail, and several Nodes
   * connected to whichever is before and after it.
   */
	struct List
	{
		struct Node
		{
			std::string x; // the data for the Node
			Node * next; // the pointer for the next Node
			Node * prev; // the pointer for the previous Node
			Node(std::string chr);
			/**
       * The constructor, which shall create a Node, with a given data
       * (in a const char-array), whilst pointing to the Node's previous
       * and next to it.
       */
			Node(std::string chr, Node * prv, Node * nxt);
			/**
       * The destructor, that shall destroy the const char-array to free up
       * memory.
       */
			~Node();
		};
    List();
    /**
     * @brief Displays the list
     * @param strt
     * Displays the list by printing a number starting from strt, followed by
     * the value of each Node, followed by a newline.
     */
    void dispList(int strt=0);
    /**
     * @brief writes into file
     * @param fileName
     * Basically does the same thing as dispList but instead of
     * using std::cout, it works with the ofstream library to output
     * the list into some file
    */
    void ofstreamList(std::string fileName);
    /**
     * @brief Add a node on tail
     * @param val
     * Adds a node on the tail of the list. It does this by linking the last
     * node to another node, and setting that new node as the tail.
  	 */
    void addtoList(std::string val);
    /**
     * @brief Adds an item in entry index.
     * @param val
     * @param index
     *
     * Should add an item before the index'th entry, starting from 0. For
     * example, if index is 0, it should add before the zeroth entry (i.e.
     * the head of the said list). This would mean that the new node is
     * the index'th entry.
     *
     * If index is greater than the length of the list, or less than 0, it
     * will print an error to stdout, and shall not modify the list.
     */
    void addByIndex(std::string val, int index);
    /**
   	 * @brief Delete node by index
     * @param index
     *
     * Deletes node by index. For example, if index is 0, it shall delete the
     * zeroth entry, i.e. the head.
     *
     * If index is less than 0, or no less than List::length, it shall print
     * an erorr to stdout, and shall not modify the list.
     */
    void deleteByIndex(int index);
    /** The head of the list. */
    Node * head;
    /** The tail of the list. */
    Node * tail;
    /**
     * The length of the list, which shall be modified after every operation.
     * An "operation" is any modification of the list (e.g. addition/deletion
     * of a node).
     */
    int length;
	};

	/** The list that shall contain the text file to be written.
	A list of char*, wherein each char* is separated by "\n" in the
	actual file.
	*/
	static List masterList;
	/**
  * @brief The start helper function
  *
  * This shall be responsible for calling all other functions that it may
  * require; when using this header file for other applications, start() should
  * be invoked.
  */
  void start();
  /**
  * The function that collects input from the user.
  * Inside the function, a set of if-else statements would
  * determine which action to make, based on the input from the user
  */
  void userInput();
}

#endif










