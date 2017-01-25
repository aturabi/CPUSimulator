#include "instruction.h"
#include <iostream>
#include <cstring>

Instruction::Instruction(int addr) : Word(addr)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction


const char* Instruction::getInfo() const
{
  return info;
} // get()


void Instruction::setInfo(const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
} // setInfo()

void Instruction::operator=(const char* a)
{
  info = new char[strlen(a) + 1];
  strcpy(info, a);
} // operator==

ostream& operator<< (ostream &out, const Instruction &instruction)
{
  out << instruction.getInfo();
  return out;
} // operator<<
