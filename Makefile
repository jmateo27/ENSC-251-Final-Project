#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o domesticstudent.o internationalstudent.o ToeflScore.o LinkedList.o
	g++ -g -o main main.o student.o domesticstudent.o internationalstudent.o ToeflScore.o LinkedList.o

test: main.cpp student.cpp internationalstudent.cpp domesticstudent.cpp LinkedList.cpp ToeflScore.cpp
	g++ -o test -g main.cpp student.cpp internationalstudent.cpp domesticstudent.cpp LinkedList.cpp ToeflScore.cpp -std=c++11

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11
    
#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp -std=c++11

#compile the domesticstudent.cpp to domesticstudent.cpp.o 
domesticstudent.o: domesticstudent.cpp
	g++ -g -c domesticstudent.cpp -std=c++11

#compile the internationalstudent.cpp to internationalstudent.o
internationalstudent.o: internationalstudent.cpp
	g++ -g -c internationalstudent.cpp -std=c++11

#compile the ToeflScore.cpp to ToeflScore.o
ToeflScore.o: ToeflScore.cpp
	g++ -g -c ToeflScore.cpp -std=c++11
  
#compile the LinkedList.cpp to LinkedList.o
LinkedList.o: LinkedList.cpp
	g++ -g -c LinkedList.cpp -std=c++11

#remove built files
clean:
	rm -rf main main.o student.o internationalstudent.o domesticstudent.o ToeflScore.o LinkedList.o test *~


