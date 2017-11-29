#include "TextEditor.hpp"
#include <string>

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
    this->prev = prv;
    this->next = nxt;
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
        Node * tmp = new Node(val);
        tmp->prev = this->tail;
        this->tail->next = tmp;
        this->tail = tmp;
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

void textEditor::List::deleteByIndex(int index)
{
    if (index >= this->length || index < 0)
    {
        std::cout << "[ERROR] Invalid value placed in textEditor::List::addByIndex" << std::endl;
        return;
    }
    Node * a = this->head;
    for (int i = 0; i < index; ++i)
    {
        a = a->next;
    }
    if (a == this->head)
    {
        this->head = a->next;
        delete a;
        this->head->prev = 0;
    }
    if (a == this->tail)
    {
        this->tail = a->prev;
        delete a;
        this->tail->next = 0;
    }
    else
    {
        a->prev->next = a->next;
        a->next->prev = a->prev;
        delete a;
    }
    --this->length;
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
        std::cin.clear();
        std::getline (std::cin,input);
        if (input[0] == 'A') //save as text file
        {
            std::ofstream textfile;
            textfile.open("output.txt");
            textfile << "OUTPUT SOMETHING HERE";
            textfile.close();
        }
        else if (input[0] == 'I' && input[1] == ' ')
        {
            //insert to list
            if (input.size() < 2)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Invalid input; you forgot to type line number.";
            }
            else
            {
                std::string content;
                std::getline (std::cin, content);
                a.addByIndex(content.c_str(), std::stoi(input.substr(2)));
            }
        }
        else if (input[0] == 'D' && input[1] == ' ')
        {
            //delete lines
            if (input.find(' ') == input.rfind(' '))
            {
                a.deleteByIndex(std::stoi(input.substr(2)));
            }
            else
            {
                //in case there are 2 numbers, e.g. D 1 4
                //we have to figure out how to tell diff between 1st and 2nd number.
            }
        else if (input[0] == 'L')
        {
            a.dispList(1);
        }
        else
        {
            a.addtoList(input.c_str());
            ++x;
        }
    } while(input[0] != 'E');
}
