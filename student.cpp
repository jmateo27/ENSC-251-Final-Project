//student.cpp to implement your classes
#include "student.hpp"

//constructs
Student::Student(string FName, string LName, float grade, int RScore, int id){
    FirstName = FName + ","; 
    LastName = LName + ","; 
    CGPA = grade; 
    ResearchScore = RScore; 
    AppID = id; 
}

Student::Student(string FName, string LName, int id){
    FirstName = FName + ","; 
    LastName = LName + ","; 
    AppID = id; 
}

Student::Student(){
    //default constructor
}

//set functions 
void Student::setFirstName(string FName){
    FirstName = FName + ","; 
}

void Student::setLastName(string LName){
    LastName = LName + ",";
}

void Student::setCGPA(float grade){
    CGPA = grade; 
}

void Student::setResearchScore(int RScore){
    ResearchScore = RScore; 
}

void Student::setAppID(int id){
    AppID = id; 
}

//getfunctions
string Student::getFirstName(){
    return FirstName; 
}

string Student::getLastName(){
    return LastName; 
}

float Student::getCGPA(){
    return CGPA; 
}

int Student::getRScore(){
    return ResearchScore; 
}

int Student::getid(){
    return AppID;
}

//compare functions
int compareCGPA(Student student1, Student student2){
    float CGPA1 = student1.getCGPA();
    float CGPA2 = student2.getCGPA();
    if (CGPA1 == CGPA2)
        return 0;
    else if (CGPA1 > CGPA2)
        return 1;
    else // CGPA1 < CGPA2
        return -1;
}

int compareFirstName (Student student1, Student student2){
    //if (student1.getFirstName() 
}

unsigned int findlen(Student student1, Student student2){
    string name1 = student1.getFirstName();
    string name2 = student2.getFirstName();
    unsigned int i = 0;
    while (name1[i] != (char)"," || name2[i] != (char)","){
        i++;
    }

    return i;
}

DomesticStudent::DomesticStudent(string FName, string LName, float grade, int RScore, int id, string Prov): 
    Student(FName, LName, grade, RScore, id){//Takes info from student class
        Province = Prov;
    }

DomesticStudent::DomesticStudent(string FName, string LName, int id, string Prov):
    Student(FName, LName, id){//Takes info from student class
        Province = Prov;
    }

DomesticStudent::DomesticStudent(){
    //default constructor
}

InternationalStudent::InternationalStudent(string FName, string LName, float grade, int RScore, int id, string Con, int TOEFL):
    Student(FName, LName, grade, RScore, id){
            Country = Con;
            TOEFLScore = TOEFL;
    }

InternationalStudent::InternationalStudent(string FName, string LName, float id, string Con, int TOEFL) :
    Student(FName, LName, id){
            Country = Con;
            TOEFLScore = TOEFL;
    }

InternationalStudent::InternationalStudent(){
    //default constructor
}



