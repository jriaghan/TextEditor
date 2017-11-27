#include "texteditor.hpp"

textEditor::List::List()
{
	head = NULL;
}

void textEditor::Node::setData(const char *data)
{
	x=data;
}

void textEditor::Node::setNext(Node* anext)
{
	next=anext;
}

const char * textEditor::Node::Data() 
{ 
	return x; 
}

void textEditor::List::display()
{
	//temp pointer
	Node *tmp = head;
	
	//no nodes
	if ( tmp == NULL ) 
	{
		std::cout<<"NO LINES";
    return;
  }
  //one node
  if ( tmp->next == NULL ) 
	{
    std::cout << tmp->Data();
    std::cout << "\n";
  }
  else 
	{
    // Parse and print the list
    do 
		{
      std::cout << tmp->Data();
      std::cout << "\n";
      tmp = tmp->next;
    }
    while ( tmp != NULL );
  }
}

void textEditor::List::append(const char *data)
{
	// Create a new node
  Node* newNode = new Node();
  newNode->setData(data);
  newNode->setNext(NULL);
  
  // Create a temp pointer
  Node *tmp = head;

  if ( tmp != NULL ) 
	{
  	// Nodes already present in the list
  	// Parse to end of list
  	while ( tmp->next != NULL ) 
		{
      tmp = tmp->next;
  	}

  	// Point the last node to the new node
  	tmp->setNext(newNode);
  }
  
  else 
	{
  // First node in the list
  head = newNode;
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
			//output list
		}
		else
		{
			const char * temp;
			temp = input.c_str();
			
		}
		
		++x;	
	}while(input!="E");
	
}
