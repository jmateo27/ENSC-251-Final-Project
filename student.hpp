//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string.h>

class Student{
//parent class of the DomesticStudent and InternationalStudent class
    public:

        //constructs
        Student(std::string FName, std::string LName, float grade, int RScore, int id);
        Student(std::string FName, std::string LName, int id);
        Student();

        //set functions
        void setFirstName(std::string FName);
        void setLastName(std::string LName);
        void setCGPA(float grade);
        void setResearchScore(int RScore);
        void setAppID(int id);

        //get functions 
        std::string getFirstName() const; 
        std::string getLastName() const; 
        float getCGPA() const; 
        int getRScore() const; 
        int getid() const; 

        //compare functions
        friend int compareCGPA(Student student1, Student student2);
        friend int compareResearchScore(Student student1, Student student2);
        friend int compareFirstName(Student student1, Student student2);
        friend int compareLastName(Student student1, Student student2);
        friend std::ostream& operator <<(std::ostream& outs, const Student& theStudent);
         

    private:
        std::string FirstName;
        std::string LastName;
        float CGPA;
        int ResearchScore;
        int AppID; //just four digits
};

class ToeflScore{
    public:
        ToeflScore(int read, int listen, int speak, int write);
        ToeflScore();
        //set
        void setReading(int read);
        void setListening(int listen);
        void setSpeaking(int speak);
        void setWriting(int write);
        //get
        int getReading() const;
        int getListening() const;
        int getSpeaking() const;
        int getWriting() const;
        int getTOEFL() const;

    private:
        int reading, listening, speaking, writing, TOEFL;

};

class DomesticStudent : public Student{
//child class of the Student class
    public:
        DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov);
        DomesticStudent(std::string FName, std::string LName, int id, std::string Prov);
        DomesticStudent();
        std::string getProvince() const;
        
        void setProvince(std::string Prov);
        friend std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent);
        friend int compareProvince(DomesticStudent student1, DomesticStudent student2);

    // friend operator << (string FName, string LName, float grade, int RScore, int id, string Prov);
    private:
        std::string Province;
};


class InternationalStudent : public Student{
//child class of the Student class
    public:
        InternationalStudent(std::string FName, std::string LName, float grade,int RScore, int id, std::string Con, ToeflScore toefl);
        InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl);
        InternationalStudent();
        std::string getCountry() const;
        ToeflScore getToefl() const;
        void settoefl(ToeflScore thescore);
        void setCountry(std::string Con);
        InternationalStudent* InterArray(InternationalStudent *ptr, std::string *filename, int &size);
        
        friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent);
        friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
    private:
        std::string Country;
        ToeflScore theirscore;
};

#endif //STUDENT_H

char upper2lowercase(char c);
void formatID(std::ostream& outs, const int num);
char giveback(std::string student, int n );
DomesticStudent* DomArray(DomesticStudent *ptr, int &size);
InternationalStudent* InterArray(InternationalStudent *ptr, int &size);
void getDomArray(DomesticStudent *ptr, int size);
void getInterArray(InternationalStudent *ptr, int size);
void mergeSortInt(InternationalStudent *arr, int min, int max, char c);
void mergeIntCGPA2(InternationalStudent *arr, int min, int max);
void mergeInt3(InternationalStudent *arr, int min, int max);
void mergeSortDom(DomesticStudent *arr, int min, int max, char c);
void mergeDomCGPA2(DomesticStudent *arr, int min, int max);
void mergeDom3(DomesticStudent *arr, int min, int max);
void dumpStu(InternationalStudent *arr, int &size);