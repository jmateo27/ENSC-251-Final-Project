#ifndef ISTUDENT_H
#define ISTUDENT_H

#include "student.hpp"
#include "ToeflScore.hpp"
class InternationalStudent : public Student{ //Creating an International child class
//child class of the Student class
    public: // The following are the public members
        InternationalStudent(std::string FName, std::string LName, float grade,int RScore, int id, std::string Con, ToeflScore toefl);
        InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl);
        InternationalStudent(InternationalStudent &stud);
        InternationalStudent();
        ~InternationalStudent(){
            delete next;
        }
        virtual Student* copystu();
        InternationalStudent& operator =(const InternationalStudent& r);
        std::string getCountry() const;
        ToeflScore getToefl() const;

        void settoefl(ToeflScore thescore);
        bool setCountry(std::string Con);
        
/*         friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent); */
        
        friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
        void printInfo();
		InternationalStudent* next;

    private: // The following are the private members
        std::string Country; // only the Coutnry member is private because it is unique to the International Students Class
        ToeflScore theirscore; // only the theirscore (TOEFL score) member is private because it is unique to the Internation Students Class
};

#endif

void getInterArray(InternationalStudent *ptr, int size); //returns the value from the international array
void mergeSortInt(InternationalStudent *arr, int min, int max, char c); // merge sort function for the indernational 
void mergeIntCGPA2(InternationalStudent *arr, int min, int max);  //merging the sorted array for CGPA
void mergeInt3(InternationalStudent *arr, int min, int max);  // merging the sorted international array
void dumpStu(InternationalStudent *arr, int &size); // used to remove students with below threshold Research score (93) or min 20 in each category
InternationalStudent* InterArray(InternationalStudent *ptr, int &size);// used to set data from the txt file to an array
