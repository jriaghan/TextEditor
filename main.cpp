#include <iostream>
#include "texteditor.hpp"

using namespace std;

int main()
{
  textEditor::List a;
  a.addtoList("NIGGER");
  a.addtoList("FAGGOT");
  a.addtoList("PUSSY");
  a.addByIndex("CUNT", 0);
  a.addByIndex("PUSSYNIGGER", 5);
  a.dispList();
}
