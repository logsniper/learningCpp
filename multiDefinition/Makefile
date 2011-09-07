main : A.o B.o main.cpp head.o
	g++ main.cpp A.o B.o head.o -o main
A.o : A.h A.cpp
	g++ -c A.cpp
B.o : B.h B.cpp 
	g++ -c B.cpp 
head.o : head.h head.cpp
	g++ -c head.cpp

clean:
	rm -rf *.o main
