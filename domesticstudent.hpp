
#ifndef DSTUDENT_H
#define DSTUDENT_H
#include "student.hpp"

class DomesticStudent : public Student{ //Creating a Domestic child class
//child class of the Student class
    public: // The following are the public members
        DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov);
        //Precondition: Defining the constructor with all parameters from the parent class Student with province
        DomesticStudent(std::string FName, std::string LName, int id, std::string Prov);
        //Precondition: Defining the constructor with Name and ID parameters from the parent class Student with province
        DomesticStudent(DomesticStudent &stud);
        DomesticStudent();
        virtual Student* copystu();
        ~DomesticStudent(){
            delete next;
        }
        //Precondition: Initializing the constructor to initialized state
        DomesticStudent& operator =(const DomesticStudent& r);

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
        void printInfo();
        DomesticStudent* next;

    private: // The following are the private members
        std::string Province; // only the province member is private because it is unique to the Domestic Students Class
                              // The rest are here, but since they are defined in the parent class they do not need to be redeclared
};
#endif


DomesticStudent* DomArray(DomesticStudent *ptr, int &size); // used to set data from the txt file to an array
void mergeSortDom(DomesticStudent *arr, int min, int max, char c); // merge sort function for the domestic students depending on parameter 
// ie. First Name, Research Score etc.
void mergeDomCGPA2(DomesticStudent *arr, int min, int max); // merging the sorted array for CGPA
void mergeDom3(DomesticStudent *arr, int min, int max); // merging the sorted domestic array
void getDomArray(DomesticStudent *ptr, int size); // returns the value from the domestic array
