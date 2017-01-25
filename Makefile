CPU.out : decoder.o instruction.o instruction2.o labels.o main.o registers.o data.o memory.o word.o 
	g++ -ansi -Wall -g -o CPU.out decoder.o instruction.o instruction2.o labels.o main.o registers.o data.o memory.o word.o 

decoder.o : decoder.cpp decoder.h instruction.h registers.h 
	g++ -ansi -Wall -g -c decoder.cpp memory.h

instruction.o : instruction.cpp instruction.h 
	g++ -ansi -Wall -g -c instruction.cpp

instruction2.o : instruction2.cpp instruction2.h
	g++ -ansi -Wall -g -c instruction2.cpp

labels.o : labels.cpp labels.h instruction2.h
	g++ -ansi -Wall -g -c labels.cpp

main.o : main.cpp registers.h decoder.h instruction.h labels.h memory.h 
	g++ -ansi -Wall -g -c main.cpp

registers.o : registers.cpp registers.h 
	g++ -ansi -Wall -g -c registers.cpp

data.o : data.cpp data.h
	g++ -ansi -Wall -g -c data.cpp

memory.o : memory.cpp memory.h data.h
	g++ -ansi -Wall -g -c memory.cpp

word.o : word.cpp word.h
	g++ -ansi -Wall -g -c word.cpp

clean : 
	rm -f CPU.out decoder.o instruction.o instruction2.o labels.o main.o registers.o data.o memory.o word.o
