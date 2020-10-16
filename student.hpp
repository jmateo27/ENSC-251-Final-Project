//header file student.hpp to declare your classes
#ifndef STUDENT_H
#define STUDENT_H
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student{
//parent class of the DomesticStudent and InternationalStudent class
    public:
        Student(string FirstName, string LastName, float CGPA, int ResearchScore, int AppID);
        Student();
        void set_FirstName(string FirstName);
        void set_LastName(string LastName);
        void set_CGPA(float CGPA_in);
        void set_ResearchScore(int ResearchScore_in);
        void set_AppID(int AppID_in);
        friend int compareCGPA(Student student1, Student student2);
        friend int compareResearchScore(Student student1, Student student2);
        friend int compareFirstName(Student student1, Student student2);
        friend int compareLastName(Student student1, Student student2);
    private:
        string FirstName;
        string LastName;
        float CGPA;
        int ResearchScore;
        int AppID; //just four digits
}
};

class DomesticStudent public: Student{
//child class of the Student class

};

class InternationalStudent public: Student{
//child class of the Student class

};
#endif //STUDENT_H