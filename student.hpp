//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H // defining the header file
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string.h> //needed for the string types (Names)

class Student{ // Creating the Student Class
//parent class of the DomesticStudent and InternationalStudent class
    public:// The following are the public members

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
         

    private: // The following are the private members
        std::string FirstName; // private member variable First Name for ADT
        std::string LastName; // private member variable Last Name for ADT
        float CGPA; // private member variable CGPA of type float and follows ADT
        int ResearchScore; // private member variable Research Score for ADT
        int AppID; //just four digits and is a private member variable for ADT
};

class ToeflScore{ // Creating the TOEFL class
    public: // The following are the public members
        ToeflScore(int read, int listen, int speak, int write);
        //Precondition: Defining the constructor for ToeflScore with its 4 parameters
        // which will be used by used only by mututator and accessor functions for ADT
        ToeflScore();
        //Precondition: Initializes the constructors to its parameters

        //set
        void setReading(int read);
        // Precondition: the Mutator function for the read parameter, allows to change the 
        // Reading score and is used to insert data from text file to the arrays
        void setListening(int listen);
        // Precondition: the Mutator function for the listen parameter, allows to change the 
        // Listening score and is used to insert data from text file to the arrays
        void setSpeaking(int speak);
        // Precondition: the Mutator function for the speak parameter, allows to change the 
        // Speaking score and is used to insert data from text file to the arrays
        void setWriting(int write);
        // Precondition: the Mutator function for the write parameter, allows to change the 
        // Writing score and is used to insert data from text file to the arrays

        //get
        int getReading() const;
        // Precondition: the Accessor function for the reading variable, it returns the value 
        // of the reading variable once this is called and is of type static (const)
        int getListening() const;
        // Precondition: the Accessor function for the listening variable, it returns the value 
        // of the listeningn variable once this is called and is of type static (const)
        int getSpeaking() const;
        // Precondition: the Accessor function for the speaking variable, it returns the value 
        // of the speaking variable once this is called and is of type static (const)
        int getWriting() const;
        // Precondition: the Accessor function for the writing variable, it returns the value 
        // of the writing variable once this is called and is of type static (const)
        int getTOEFL() const;
        // Precondition: the Accessor function for the TOEFL variable, it returns the value 
        // of the TOEFL variable (the sum) once this is called and is of type static (const)

    private: // The following are the private members
        int reading, listening, speaking, writing, TOEFL;// defining the private members for ADT

};

class DomesticStudent : public Student{ //Creating a Domestic child class
//child class of the Student class
    public: // The following are the public members
        DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov);
        //Precondition: Defining the constructor with all parameters from the parent class Student with province
        DomesticStudent(std::string FName, std::string LName, int id, std::string Prov);
        //Precondition: Defining the constructor with Name and ID parameters from the parent class Student with province
        DomesticStudent();
        //Precondition: Initializing the constructor to initialized state

        std::string getProvince() const; 
        //Precondition: the Accessor function for the Province which returns the variable Province

        void setProvince(std::string Prov);
        //Precondition: the Mutator function for the Province which is 
        //used to set the array from the txt file

        friend std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent);
        //Precondition: The insertion operator is used to output information 
        //from the cpp files to the terminal
        friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
        //Precondition: this function is used to compare the Province of 2 students,
        //Depending on which input is greater (alphabetically) the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function


    private: // The following are the private members
        std::string Province; // only the province member is private because it is unique to the Domestic Students Class
                              // The rest are here, but since they are defined in the parent class they do not need to be redeclared
};


class InternationalStudent : public Student{ //Creating an International child class
//child class of the Student class
    public: // The following are the public members
        InternationalStudent(std::string FName, std::string LName, float grade,int RScore, int id, std::string Con, ToeflScore toefl);
        //Precondition: Defining the constructor with all parameters from the parent class Student with Country and TOEFL
        InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl);
        //Precondition: Defining the constructor with Name and ID parameters from the parent class Student with Country and TEOFL
        InternationalStudent();
        //Precondition: Initializing the constructor to initialized state

        std::string getCountry() const;
        //Precondition: the Accessor function returns the Country of origin 
        ToeflScore getToefl() const;
        //Precondition: the Accessor function returns the Toefl score 

        void settoefl(ToeflScore thescore);
        //Precondition: the Mutator function is used to alter the Teofl score of the student
        //and is used by our cpp to input the input data from the txt to an array
        void setCountry(std::string Con);
        //Precondition: the Mutator function is used to alter the Country of origin of the student
        //and is used by our cpp to input the input data from the txt to an array

        InternationalStudent* InterArray(InternationalStudent *ptr, std::string *filename, int &size); 
        
        friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent);
        //Precondition: the Insertion operator is used to perform outputs within the class InternationalStudent
        
        friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
        //Precondition: this function is used to compare the Country of 2 students,
        //Depending on which input is greater (alphabetically) the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function

    private: // The following are the private members
        std::string Country; // only the Coutnry member is private because it is unique to the International Students Class
        ToeflScore theirscore; // only the theirscore (TOEFL score) member is private because it is unique to the Internation Students Class
        // The rest are here, but since they are defined in the parent class they do not need to be redeclared
};

#endif //STUDENT_H

char upper2lowercase(char c);   // converts inputs to lower case
void formatID(std::ostream& outs, const int num); // formats the ID for use with the concatenation to a single digit ie. 4.33 becomes 4.3
char giveback(std::string student, int n ); // used within the Student class
DomesticStudent* DomArray(DomesticStudent *ptr, int &size); // used to set data from the txt file to an array
InternationalStudent* InterArray(InternationalStudent *ptr, int &size);// used to set data from the txt file to an array
void getDomArray(DomesticStudent *ptr, int size); // returns the value from the domestic array
void getInterArray(InternationalStudent *ptr, int size); //returns the value from the international array
void mergeSortInt(InternationalStudent *arr, int min, int max, char c); // merge sort function for the indernational 
                                                                        // students depending on parameter ie. CGPA etc.
void mergeIntCGPA2(InternationalStudent *arr, int min, int max);  //merging the sorted array for CGPA
void mergeInt3(InternationalStudent *arr, int min, int max);  // merging the sorted international array
void mergeSortDom(DomesticStudent *arr, int min, int max, char c); // merge sort function for the domestic students depending on parameter 
                                                                   // ie. First Name, Research Score etc.
void mergeDomCGPA2(DomesticStudent *arr, int min, int max); // merging the sorted array for CGPA
void mergeDom3(DomesticStudent *arr, int min, int max); // merging the sorted domestic array
void dumpStu(InternationalStudent *arr, int &size); // used to remove students with below threshold Research score (93) or min 20 in each category