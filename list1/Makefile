all: fa kmp clean

fa: fa.o StatesMaker.o
	g++ -o FA fa.o StatesMaker.o

kmp: kmp.o FunctionsMaker.o
	g++ -o KMP kmp.o FunctionsMaker.o
	
fa.o: fa.cpp
	g++ -c fa.cpp
	
StatesMaker.o: src/StatesMaker.cpp src/StatesMaker.h
	g++ -c src/StatesMaker.cpp -o StatesMaker.o

kmp.o: kmp.cpp
	g++ -c kmp.cpp

FunctionsMaker.o: src/FunctionsMaker.cpp src/FunctionsMaker.h
	g++ -c src/FunctionsMaker.cpp -o FunctionsMaker.o

clean:
	rm -f *.o
