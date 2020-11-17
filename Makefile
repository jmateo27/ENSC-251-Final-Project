#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o domesticstudent.o internationalstudent.o ToeflScore.o
	g++ -g -o main main.o student.o domesticstudent.o internationalstudent.o ToeflScore.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp -std=c++11

#compile the domesticstudent.cpp to domesticstudent.cpp.o 
domesticstudent.o: domesticstudent.cpp
	g++ -g -c domesticstudent.cpp -std=c++11

#compile the student.cpp to student.o
internationalstudent.o: internationalstudent.cpp
	g++ -g -c internationalstudent.cpp -std=c++11

#compile the ToeflScore.cpp to ToeflScore.o
ToeflScore.o: ToeflScore.cpp
	g++ -g -c ToeflScore.cpp -std=c++11
  
#remove built files
clean:
	rm -rf main main.o student.o internationalstudent.o domesticstudent.o ToeflScore.o *~