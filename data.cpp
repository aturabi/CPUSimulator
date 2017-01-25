#include "data.h"

Data::Data(int a) : Word(a)
{
} // Data()


const int& Data::get()const
{
  return num;
} // get()


int& Data::get()
{
  return num;
} // get()


void Data::operator=(int d)
{
  num = d;
} // operator=
