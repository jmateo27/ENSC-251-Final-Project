//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

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
void Student::setFirstName(string FName){
    FirstName = FName; 
}

void Student::setLastName(string LName){
    LastName = LName;
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
    std::string s1 = student1.getFirstName();
    std::string s2 = student2.getFirstName(); 
    unsigned int len1 = s1.length(); 
    unsigned int len2 = s2.length(); 
    unsigned int len =0; 

    if (len1 >= len2 )
        len = len1; 
    else
        len = len2; 
        
    for(int i = 0; i < len; i++){
        if (s1[i] == s2[i])
            continue; 
        else if (s1[i] > s2[i])
            return 0; 
        else  //s1 < s2
            return 1; 
    }
}
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

string DomesticStudent::get_Province()
{return Province;}

std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent)
{
    std::cout << "The student name is: " << Student.getFirstName() << Student.getLastName();
    std::cout << "\nThe student is from: " << get_Province();
    std::cout << "\nThe CGPA is: " << Student.getCGPA();
    std::cout << "\nThe Reseach Score is: " << Student.getRScore();
    std::cout << "\nThe student ID is: " << Student.getid()<< "\n";
}

InternationalStudent::InternationalStudent(string FName, string LName, float grade, int RScore, int id, string Con, int TOEFL):
    Student(FName, LName, grade, RScore, id){
            Country = Con;
            TOEFLScore = TOEFL;
    }

InternationalStudent::InternationalStudent(string FName, string LName, int id, string Con, int TOEFL) :
    Student(FName, LName, id){
            Country = Con;
            TOEFLScore = TOEFL;
    }

InternationalStudent::InternationalStudent(){
    //default constructor
}
string InternationStudent::get_Country()
{ return Country;}

std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent)
{
    std::cout << "The student name is: " << Student.getFirstName() << Student.getLastName();
    std::cout << "\nThey are from: " << get_Country();
    std::cout << "\nThe CGPA is: " << Student.getCGPA();
    std::cout << "\nThe Reseach Score is: " << Student.getRScore();
    std::cout << "\nThe student ID is: " << Student.getid();
    std::cout << "\nThe student TOEFL score is: \nReading:" << ToeflScore.getReading() << "/30";
    std::cout << "\nListening:" << ToeflScore.getListening() << "/30" << "\nSpeaking: " << ToeflScore.getSpeaking() << "/30" << "\nWriting: " << ToeflScore.getWriting();
}

ToeflScore::ToeflScore(int read, int listen, int speak, int write){
    reading = read;
    listening = listen;
    speaking = speak;
    writing = write;
}

ToeflScore::ToeflScore(){
    //default constructor
}

//set functions for Toefl
void ToeflScore::setReading(int read){
    reading = read;
}

void ToeflScore::setListening(int listen){
    listening = listen;
}

void ToeflScore::setSpeaking(int speak){
    speaking = speak;
}

void ToeflScore::setWriting(int write){
    writing = write;
}

int ToeflScore::getReading()
{ return reading;}

int ToeflScore::getListening()
{ return listening;}

int ToeflScore::getSpeaking()
{ return speaking;}

int ToeflScore::getWriting()
{ return writing;}

//Total score
int ToeflScore::getTOEFL(){
    TOEFL = (reading + listening + speaking + writing);
    return TOEFL;

