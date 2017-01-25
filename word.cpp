#include "word.h"
#include <iostream>
using namespace std;

Word::Word(int a)
{
  address = a;
} // Word()


Word::~Word()
{
} // Word()


bool Word::operator<(Word w)
{

  if(address < w.address)
     return true;
  else // if address is equal or greater 
     return false;
} // operator<


