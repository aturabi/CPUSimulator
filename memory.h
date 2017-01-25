#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include "instruction.h"
#include "word.h"
using namespace std;

class Registers;

class ListNode
{
  Word * word;
  ListNode *next;

  public:
     ListNode(Word *w, ListNode *listN);
     ~ListNode();
     friend class Memory;
}; // end class ListNode

class Memory
{
  ListNode *head;
 
  public: 
  Memory();
  ~Memory();
  void insert(Word *w);
  Word& operator[](int addr);
  Word& operator[](int addr)const;
  const Instruction& fetch(Registers *registers) const;
  friend istream& operator>> (istream &is, Memory &memory);

}; // end class Memory

#endif
