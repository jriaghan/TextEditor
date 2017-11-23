#include "texteditor.hpp"

textEditor::List::List()
{
	head = NULL;
}

//not yet final addtoList
void textEditor::List::addtoList(char val)
{
	Node *n = new Node();
	n->x = val;
	n->next = head;
	
	head = n;
}

void textEditor::List::dispList(Node *head)
{
	if (head == NULL)
	{
		std::cout<<"\n";
		return;
	}
	
	std::cout<< head->x;
	textEditor::List::dispList(head->next);
}

void textEditor::start()
{
	char word;
	do
	{
		
	}while()
}
