#include "texteditor.hpp"

textEditor::List::List()
{
  this->head = NULL;
  this->tail = NULL;
  this->length = 0;
}

textEditor::List::Node::~Node()
{
  // do nothing here dear; automatic handling of string destruction
}

textEditor::List::Node::Node(std::string chr)
{
  this->x = chr;
}

textEditor::List::Node::Node(std::string chr, Node * prv, Node * nxt)
{
  this->x = chr;
  this->prev = prv;
  this->next = nxt;
}

void textEditor::List::addtoList(std::string val)
{
  if (this->head == NULL)  // what if it's null?!
  {
    this->head = new textEditor::List::Node(val, 0, 0);
    this->tail = this->head;
  }
  else
  {
    Node * tmp = new Node(val);
    tmp->prev = this->tail;
    this->tail->next = tmp;
    this->tail = tmp;
    this->tail->next = 0;
  }
  ++this->length;
}

void textEditor::List::dispList(int strt)
{
    Node * a = this->head;
    int x = strt;
    while (a != NULL)
    {
        std::cout << x << "] " << a->x << std::endl;
        a = a->next;
        ++x;
    }
}


void textEditor::List::ofstreamList(std::string fileName)
{
	std::ofstream textfile;
	textfile.open(fileName);
	Node * a = this->head;
  while (a != NULL)
  {
    textfile << a->x << std::endl;
    a = a->next;
  }
}


void textEditor::List::addByIndex(std::string val, int index)
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

void textEditor::List::deleteByIndex(int index)
{
  // check for validity
  if (index >= this->length || index < 0)
  {
    std::cout <<
    "ERROR: Invalid value placed in textEditor::List::deleteByIndex"
    << std::endl;
    return;
  }
  // what if the list is of length one?!
  if (this->length == 1)
  {
    delete this->head;
    this->head = 0;
    this->tail = 0;
    --this->length;
    return;
  }
  // case if it's the head
  if (index == 0)
  {
    this->head = this->head->next;
    delete this->head->prev;
    this->head->prev = 0;
    --this->length;
    return;
  }
  // case if it's the tail
  if (index == this->length - 1)
  {
    this->tail = this->tail->prev;
    delete this->tail->next;
    this->tail->next = 0;
    --this->length;
    return;
  }
  // and for other cases
  Node * a = this->head;
  for (int i = 0; i < index; ++i)
  {
    a = a->next;
  }
  a->prev->next = a->next;
  a->next->prev = a->prev;
  delete a;
  --this->length;
}


void textEditor::start()
{
	textEditor::userInput();
}

void textEditor::userInput()
{
  int x = 1;
  std::string input;
  textEditor::List a;
  std::string fileName = "output.txt";
  std::cout << "Enter file name (default: output.txt): ";
  std::getline(std::cin, fileName);
  for (auto & x : {"<", ">", ":", "\"", "/", "\\", "|", "?", "*", ".."})
  {
    if (fileName.find(x) != std::string::npos)
    {
      std::cout << "Sorry, but that's an invalid filename.\n";
      std::cout << "We'll just stick with output.txt\n";
      fileName = "output.txt";
      break;
    }
  }
  do
  {
    std::cout << x << "> ";
    std::cin.clear();
    std::getline (std::cin,input);
    if (input == "A")
    {
      //save as text file
      std::cout << "Writing...";
      a.ofstreamList(fileName);
      std::cout << "done.\n";
    }
    else if (input == "I")
    {
      // go back to end of the list
      x = a.length + 1;
      continue;
    }
    else if (input[0] == 'I' && input[1] == ' ')
    {
      //insert to some part of the damned list
      if (input.size() <= 2)
      {
        std::cout << "ERROR: NO LINE NUMBER IN I COMMAND.\n";
      }
      else
      {
        // first check whether what has been inputed is valid
        bool isThereInt = 0;
        for (auto & x : "1234567890")
        {
          if (x == input.substr(2).at(0))
          {
            isThereInt = 1;
          }
        }
        if (isThereInt == 0)
        {
          // there are no integers
          std::cout << "ERROR: INVALID I COMMAND INPUT.\n";
          continue;
        }
        int whereToInput = std::stoi(input.substr(2));
        // check whether it's even valid (i.e. if >=1 but <= the length)
        if (whereToInput >= 1 && whereToInput <= a.length + 1)
        {
          x = whereToInput;
        }
        else
        {
          std::cout << "ERROR: INVALID LINE NUMBER IN I COMMAND.\n";
          continue;
        }
      }
    }
    else if (input[0] == 'D' && input[1] == ' ')
    {
      // deletion of lines
      // of course, check whether input is actually valid
      if (input.size() <= 2)
      {
        std::cout << "ERROR: NO LINE NUMBER IN D COMMAND.\n";
        continue;
      }
      if (input.find(' ') == input.rfind(' '))
      {
        // first, check whether's next is a number
        bool isThereInt = 0;
        for (auto & x : "1234567890")
        {
          if (input.substr(2).at(0) == x)
          {
            isThereInt = 1;
          }
        }
        if (isThereInt == 0)
        {
          std::cout << "ERROR: INVALID INPUT IN D COMMAND.\n";
          continue;
        }
        // now it's assumed that it's a number
        // now check for validity
        // how? if it's 0, negative, or greater than length
        if (std::stoi(input.substr(2)) <= 0 || std::stoi(input.substr(2)) > a.length)
        {
          std::cout << "ERROR: INVALID LINE NUMBER IN D COMMAND\n";
          std::cout << "\tnice try nigger.\n";
          continue;
        }
        // and do the proper deletion desu
        a.deleteByIndex(std::stoi(input.substr(2)) - 1);
        // subtract x (for certain cases only)
        if (std::stoi(input.substr(2)) < x)
        {
          --x;
        }
      }
      else
      {
        //in case there are 2 numbers, e.g. D 1 4
        //we have to figure out how to tell diff between 1st and 2nd number.
        int firstspace = input.find(' ');
        int secondspace = input.find(' ', 2);
        int numberlength = (secondspace - firstspace);
        // WHAT IF THE USER INPUTS S.TH LIKE "D 13 " (NO SECOND NUMBER!)
        bool okwhatevs = false;
        for (auto & x : input.substr(2+numberlength))
        {
          for (auto & y : "1234567890")
          {
            if (x == y)
            {
              okwhatevs = true;
            }
          }
        }
        if (okwhatevs == false)
        {
          std::cout << "ERROR: INVALID LINE NUMBERS IN D COMMAND.\n";
          std::cout << "\tInfo: ends with space\n";
          continue;
        }
        // assign the input shits
        int firstInt = std::stoi(input.substr(2));
        int secondInt = std::stoi(input.substr(2+numberlength));
        // now, check for validity; if greater than
        if (firstInt >= secondInt)
        {
          std::cout << "ERROR: INVALID LINE NUMBERS IN D COMMAND.\n";
          std::cout << "\tInfo: first integer greater than second\n";
          continue;
        }
        // and if it's 0 or less, or greater than length of list
        if (firstInt <= 0 || secondInt > a.length)
        {
          std::cout << "ERROR: INVALID LINE NUMBERS IN D COMMAND.\n";
          std::cout << "\tInfo: either <= 0 or greater than list length.\n";
          continue;
        }
        for (int i = firstInt; i<=secondInt; ++i)
        {
          // WARNING : DO NOT DELETE THAT OF INDEX i !
          // NOTE THAT THE VALUE OF i CHANGES EVERY TIME THE LOOP IS ITERATED
          a.deleteByIndex(firstInt - 1);  // -1 because index starts at 0
          // and subtract x (if only necessary)
        }
      }
    }
    else if (input == "L")
    {
      a.dispList(1);
    }
    else
    {
      std::string tmp(input);
      a.addByIndex(tmp, x-1);
      ++x;
    }
  } while(input != "E");
  std::cout << "Exiting...\n";
}
