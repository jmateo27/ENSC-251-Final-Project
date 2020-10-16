//student.cpp to implement your classes
#include "student.hpp"

//constructs
Student::Student(string FName, string LName, float grade, int RScore, int id){
    FirstName = FName; 
    LastName = LName; 
    CGPA = grade; 
    ResearchScore = RScore; 
    AppID = id; 
}

Student::Student(string FName, string LName, int id){
    FirstName = FName; 
    LastName = LName; 
    AppID = id; 
}

Student::Student(){
    //default constructor
}

//set functions 
void Student::set_FirstName(string FName){
    FirstName = FName; 
}

void Student::set_LastName(string LName){
    LastName = LName;
}

void Student::set_CGPA(float grade){
    CGPA = grade; 
}

void Student::set_ResearchScore(int RScore){
    ResearchScore = RScore; 
}

void Student::set_AppID(int id){
    AppID = id; 
}