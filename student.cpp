//student.cpp to implement your classes
#include "student.hpp"

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