#ifndef DATA_H
#define DATA_H

#include "word.h"

class Data: public Word 
{
  int num;
public:
  Data(int a);
  const int& get()const;
  int& get();
  void operator=(int d);
}; // Data()

#endif
