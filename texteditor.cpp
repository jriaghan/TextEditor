#include "texteditor.hpp"

textEditor::List::List()
{
	head = NULL;
}

//not yet final addtoList
void textEditor::List::addtoList(std::string val)
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
	// do stuff

}
