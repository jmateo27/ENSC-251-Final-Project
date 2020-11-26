//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H // defining the header file
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string.h> //needed for the string types (Names)
using std::string;

class Student{ // Creating the Student Class
//parent class of the DomesticStudent and InternationalStudent class
    public:

        //constructs
        Student(std::string FName, std::string LName, float grade, int RScore, int id);
        //Precondition: Constructor with all parameters for the function used within our code
        // determined by all the values in the private members
        Student(std::string FName, std::string LName, int id);
        //Precondition: Constructor with the First Name and Last Name and the student ID
        Student();
        //Precondition: Initializer for the constructors, it sets the values of the parameters to 
        //their initialized state

        //set functions
        void setFirstName(std::string FName);
        //Precondition: Mutator function for the first name of students
        //used to create the arrays we use in our code from the text files
        void setLastName(std::string LName);
        // Precondition: Mutator function for the last name of students, 
        //used to create the arrays we use in our code from the text files
        void setCGPA(float grade);
        // Precondition: Mutator function for the CGPA of students, 
        //used to create the arrays we use in our code from the text files
        void setResearchScore(int RScore);
        // Precondition: Mutator function for the Research Score of students, 
        //used to create the arrays we use in our code from the text files
        void setAppID(int id);
        // Precondition: Mutator function for the Student ID of students, 
        //used to create the arrays we use in our code from the text files
		
        //get functions 
        std::string getFirstName() const; 
        // Precondition: Accessor function for the first name of students, 
        //used to retrieve data from arrays we use in our code from the text files
        std::string getLastName() const; 
        // Precondition: Accessor function for the last name of students, 
        //used to retrieve data from arrays we use in our code from the text files
        float getCGPA() const; 
        // Precondition: Accessor function for the CGPA of students, 
        //used to retrieve data from arrays we use in our code from the text files
        int getRScore() const; 
        // Precondition: Accessor function for the Research Score of students, 
        //used to retrieve data from arrays we use in our code from the text files
        int getid() const; 
        // Precondition: Accessor function for the Student ID of students, 
        //used to retrieve data from arrays we use in our code from the text files

        //compare functions
        friend int compareCGPA(Student student1, Student student2);
        //Precondition: this function is used to compare the CGPA of 2 students,
        //Depending on which input is greater the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function
        friend int compareResearchScore(Student student1, Student student2);
        //Precondition: this function is used to compare the Research Score of 2 students,
        //Depending on which input is greater the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function
        friend int compareFirstName(Student student1, Student student2);
        //Precondition: this function is used to compare the First Names of 2 students,
        //Depending on which input is greater (alphabetically) the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function
        friend int compareLastName(Student student1, Student student2);
        //Precondition: this function is used to compare the Last Names of 2 students,
        //Depending on which input is greater (alphabetically) the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function
        friend std::ostream& operator <<(std::ostream& outs, const Student& theStudent);
        //Precondition: the insertion operator for use within our functions and to output
        //in the terminal
        virtual void printInfo(ostream& outs);
        Student* next;
        
    private: // The following are the private members
        std::string FirstName; // private member variable First Name for ADT
        std::string LastName; // private member variable Last Name for ADT
        float CGPA; // private member variable CGPA of type float and follows ADT
        int ResearchScore; // private member variable Research Score for ADT
        int AppID; //just four digits and is a private member variable for ADT
};


#endif //STUDENT_H

char upper2lowercase(char c);   // converts inputs to lower case
void formatID(std::ostream& outs, const int num); // formats the ID for use with the concatenation to a single digit ie. 4.33 becomes 4.3
char giveback(std::string student, int n ); // used within the Student class
int compareFullName(string n1, string n2);

void mergeSortGen(Student *arr[], int min, int max, char c);
void mergeGenCGPA2(Student *arr[], int min, int max);
void mergeGen3(Student *arr[], int min, int max);
void mergeGen(Student *arr[], int min, int mid, int max, char c);