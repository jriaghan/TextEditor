#include "texteditor.hpp"

textEditor::List::List()
{
	head = NULL;
	tail = NULL;
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
  textEditor::List::Node * pt = this->head;
  if (this->head == NULL)  // what if it's null?!
  {
    this->head = new textEditor::List::Node(val, 0, 0);
    this->tail = this->head;
  }
  else
  {
    /*
    while (pt->next != NULL)
    {
      pt = pt->next;
    }
    // now do what with pt?
    textEditor::List::Node & last = *(pt);
    last.next = new textEditor::List::Node(val, pt, 0);
    this->tail = last.next;
    */
    this->tail = new textEditor::List::Node(val, this->tail, 0);
    this->tail->prev->next = this->tail;
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
	textEditor::userInput();
	// do stuff

}

void textEditor::userInput()
{
	int x = 1;
	std::string input;
	textEditor::List a;
	do
	{
		std::cout<<x<<"> ";
		std::getline (std::cin,input);
		if (input == "A") //save as text file
		{
			std::ofstream textfile;
			textfile.open("output.txt");
			textfile<<"OUTPUT SOMETHING HERE";
			textfile.close();
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
			a.dispList();
		}
		else
		{
			const char * temp;
			temp = input.c_str();
			a.addtoList(temp);
		}
		++x;	
	} while(input!="E");
	
}
