//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

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
        //extra stuff
        friend unsigned int findlen(std::string student1, std::string student2); 

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
        
        void set_Province(std::string Prov);
    friend std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent);

    // friend operator << (string FName, string LName, float grade, int RScore, int id, string Prov);
    private:
        std::string Province;
};

class InternationalStudent : public Student{
//child class of the Student class
    public:
        InternationalStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Con, ToeflScore toefl);
        InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl);
        InternationalStudent();
        std::string getCountry() const;
        ToeflScore getToefl() const;
        void settoefl(ToeflScore thescore);
        void setCountry(std::string Con);
        
        friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent);
    private:
        std::string Country;
        ToeflScore theirscore;
};

#endif //STUDENT_H

char upper2lowercase(char c);
void formatID(std::ostream& outs, const int num);