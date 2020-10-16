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

