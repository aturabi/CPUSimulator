#include "memory.h"
#include "word.h"
#include "data.h"
#include "registers.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Memory::Memory()
{
  head = NULL;
}// Memory()

Memory::~Memory()
{
  delete head;

}//~Memory()


void Memory::insert(Word *w)
{
  cout<< "hi" <<endl;
  ListNode *ptr, *prev = NULL;

  for(ptr = head; ptr && *ptr->word < *w; ptr = ptr -> next)
    prev = ptr;

  if(prev)
    prev->next = new ListNode(w, ptr);
  else // if prev is NULL
    head = new ListNode(w, ptr);

} //insert()


Word& Memory::operator[] (int addr)
{
  Word w(addr);
  ListNode *ptr;
  ptr = head;

  for(ptr = head; ptr && *ptr->word < w; ptr = ptr->next);

  if ((ptr) && !(*ptr->word < w) && !(w < *ptr->word))
    return *ptr->word;

  Data *data = new Data(addr);
  insert(data);
  return *data;

} // operator[]

Word& Memory::operator[](int addr)const
{
  Word w(addr);
  ListNode *ptr;
  ptr = head;

  for(ptr = head; ptr && *ptr->word < w; ptr = ptr->next);

  if ((ptr) && !(*ptr->word < w) && !(w < *ptr->word))
    return *ptr->word;

  if(ptr == NULL)
  {
    cout << "Seg fault at address: <" << addr << ">";
    exit(1);
  } // if ptr is NULL

  return *ptr->word;

} // operator[] const
 

ListNode::ListNode(Word *w, ListNode *listN)
{
  word = w;
  next = listN;
} // ListNode()


ListNode::~ListNode()
{
  delete word;
} // ~ListNode()


const Instruction& Memory::fetch(Registers *registers) const 
{
  const Instruction &instruction = 
   dynamic_cast<const Instruction&> ((*this)[registers->get(Registers::eip)]);
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
  return instruction; 
} // fetch()


istream& operator>> (istream &is, Memory &memory)
{
  char line[256], *ptr;
  int address = 100;
  Instruction *instruction;
  
  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(!(*(ptr + strlen(ptr) - 1) == ':') && !(*ptr == '.'))
    {
      instruction = new Instruction(address);
      address += 4;
      *instruction = ptr;
      memory.insert(instruction);
    } // if not directive, nor main:
  }  // while more in file
  
  return is;
}  // operator>>
