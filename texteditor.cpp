#include "texteditor.hpp"

textEditor::List::List()
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

textEditor::List::Node::~Node()
{
  delete [] this->x;
}

textEditor::List::Node::Node(const char * chr)
{
  this->x = chr;
}

textEditor::List::Node::Node(const char * chr, Node * prv, Node * nxt)
{
  this->x = chr;
  this->next = nxt;
  this->prev = prv;
}

void textEditor::List::addtoList(const char * val)
{
  // let's point it to somewhere
  if (this->head == NULL)  // what if it's null?!
  {
    this->head = new textEditor::List::Node(val, 0, 0);
    this->tail = this->head;
  }
  else
  {
    this->tail = new textEditor::List::Node(val, this->tail, 0);
    this->tail->prev->next = this->tail;
  }
  ++this->length;
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

void textEditor::List::addByIndex(const char * val, int index)
{
  // first check whether index is even fucking valid
  if (index > this->length || index < 0)
  {
    std::cout <<
    "[ERROR] Invalid value placed in textEditor::List::addByIndex"
    << std::endl;
    return;
  }
  // and case when it is at the very end (i.e. index == length)
  if (index == this->length)
  {
    textEditor::List::addtoList(val);
    return;
  }
  Node * a = this->head;
  // and iterate it an index number of times
  for (int i = 0; i < index; ++i)
  {
    a = a->next;
  }
  
  if (a == this->head)
  {
    // case when it is head
    this->head = new Node(val, 0, this->head);
    a->prev = this->head;
  }
  else
  {
    // for "normal" circumstances
    textEditor::List::Node * prv = a->prev;
    prv->next = new Node(val, prv, a);
    a->prev = prv->next;
  }

  // then add length
  ++this->length;
}

void textEditor::start()
{ 
  // do stuff
}
