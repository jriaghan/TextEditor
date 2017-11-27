#include "texteditor.hpp"
#include <string>

textEditor::List::List()
{
	head = NULL;
}

//not yet final addtoList
void textEditor::List::addtoList(char * val)
{
  textEditor::List::Node * temp = this->head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  textEditor::List::Node * n = new Node;
  n->x = val;
  n->next = NULL;
  temp->next = n;
}

void textEditor::List::dispList(Node *head)
{
	if (head == NULL)
	{
		std::cout<<"\n";
		return;
	}

	std::cout << head->x << std::endl;
	textEditor::List::dispList(head->next);
}

void textEditor::start()
{
	textEditor::userInput();
	// do stuff

}


void textEditor::userInput()
{
	int x = 1;
	std::string input;
	do
	{
		std::cout<<x<<"> ";
		std::getline (std::cin,input);
		if (input == "A")
		{
			//save  list
		}
		else if (input=="I")
		{
			//insert to list
		}
		else if (input=="D")
		{
			//delete lines
		}
		else if (input=="L")
		{
			//output list
		}
		
		++x;	
	}while(input!="E");
	
}
