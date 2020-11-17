#ifndef ISTUDENT_H
#define ISTUDENT_H

#include "student.hpp"
#include "ToeflScore.hpp"
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

        
        friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent);
        //Precondition: the Insertion operator is used to perform outputs within the class InternationalStudent
        
        friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
        //Precondition: this function is used to compare the Country of 2 students,
        //Depending on which input is greater (alphabetically) the function will output a 1 or -1
        //And if the inputs have the same value, it returns a 0 it is used in the sorting function
		InternationalStudent* next;

    private: // The following are the private members
        std::string Country; // only the Coutnry member is private because it is unique to the International Students Class
        ToeflScore theirscore; // only the theirscore (TOEFL score) member is private because it is unique to the Internation Students Class
        // The rest are here, but since they are defined in the parent class they do not need to be redeclared
};

#endif

void getInterArray(InternationalStudent *ptr, int size); //returns the value from the international array
void mergeSortInt(InternationalStudent *arr, int min, int max, char c); // merge sort function for the indernational 
void mergeIntCGPA2(InternationalStudent *arr, int min, int max);  //merging the sorted array for CGPA
void mergeInt3(InternationalStudent *arr, int min, int max);  // merging the sorted international array
void dumpStu(InternationalStudent *arr, int &size); // used to remove students with below threshold Research score (93) or min 20 in each category
InternationalStudent* InterArray(InternationalStudent *ptr, int &size);// used to set data from the txt file to an array
