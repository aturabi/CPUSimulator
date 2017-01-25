#ifndef WORD_H
#define WORD_H
#include <iostream>
class Word
{

  int address;
  public:
    Word(int a);
    virtual ~Word();
    bool operator<(Word w);
}; //class Word

#endif
