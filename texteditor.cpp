#include "texteditor.hpp"

textEditor::List::List()
{
	head = NULL;
}

textEditor::List::Node::Node(const char * a, Node * b)
{
  this->x = a;
  this->next = b;
}

//not yet final addtoList
void textEditor::List::addtoList(const char * val)
{
  // let's point it to somewhere
  textEditor::List::Node * pt = this->head;
  if (pt == NULL)  // what if it's null?!
  {
    this->head = new textEditor::List::Node(val);
  }
  else
  {
    while (pt->next != NULL)
    {
      pt = pt->next;
    }
    // now do what with pt?
    textEditor::List::Node & last = *(pt);
    last.next = new textEditor::List::Node(val);
  }
}

void textEditor::List::dispList()
{
  Node * a = this->head;
  while (a != NULL)
  {
    std::cout << a->x << std::endl;
    a = a->next;
  }
}

void textEditor::start()
{
	// do stuff

}
