//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student{
//parent class of the DomesticStudent and InternationalStudent class
    public:

        //constructs
        Student(string FName, string LName, float grade, int RScore, int id);
        Student(string FName, string LName, int id);
        Student();

        //set functions
        void setFirstName(string FName);
        void setLastName(string LName);
        void setCGPA(float grade);
        void setResearchScore(int RScore);
        void setAppID(int id);

        //get functions 
        string getFirstName(); 
        string getLastName(); 
        float getCGPA(); 
        int getRScore(); 
        int getid(); 

        //compare functions
        friend int compareCGPA(Student student1, Student student2);
        friend int compareResearchScore(Student student1, Student student2);
        friend int compareFirstName(Student student1, Student student2, unsigned int len);
        friend int compareLastName(Student student1, Student student2, unsigned int len);

        //extra stuff
        friend unsigned int findlen(string student1, string student2); 

    private:
        string FirstName;
        string LastName;
        float CGPA;
        int ResearchScore;
        int AppID; //just four digits
};

class DomesticStudent : public Student{
//child class of the Student class
    public:
        DomesticStudent(string FName, string LName, float grade, int RScore, int id, string Prov);
        DomesticStudent(string FName, string LName, int id, string Prov);
        DomesticStudent();
        void set_Province(string Prov);
    private:
        string Province;
};

class InternationalStudent : public Student{
//child class of the Student class
    public:
        InternationalStudent(string FName, string LName, float grade, int RScore, int id, string Con, int TOEFL);
        InternationalStudent(string FName, string LName, int id, string Con, int TOEFL);
        InternationalStudent();
        void set_Country(string Con);
        void set_TOEFLScore(int TOEFL);
    private:
        string Country;
        int TOEFLScore;
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
        int getTOEFL();

    private:
        int reading, listening, speaking, writing, TOEFL;

};
#endif //STUDENT_H