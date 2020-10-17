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

std::string Student::getLastName(){
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
    std::string name1 = student1.getFirstName();
    std::string name2 = student2.getFirstName();
    int len = 0;
    if (name1.length() >= name2.length())
        len = name1.length();
    else
        len = name2.length();

    for (int i = 0; i < len; i++){
        if (upper2lowercase(name1[i]) < upper2lowercase(name2[i])){
            return 1;
        }
        else if (upper2lowercase(name1[i]) > upper2lowercase(name2[i])){
            return -1;
        }
    }
    return 0;
}
int compareLastName (Student student1, Student student2){
    std::string name1 = student1.getLastName();
    std::string name2 = student2.getLastName();
    int len = 0;
    if (name1.length() >= name2.length())
        len = name1.length();
    else
        len = name2.length();

    for (int i = 0; i < len; i++){
        if (upper2lowercase(name1[i]) < upper2lowercase(name2[i])){
            return 1;
        }
        else if (upper2lowercase(name1[i]) > upper2lowercase(name2[i])){
            return -1;
        }
    }
    return 0;
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

void DomesticStudent::dstu(std::ostream& outs, Student theStudent) const
{
    std::cout << "The student name is: " << theStudent.getFirstName() << theStudent.getLastName();
    std::cout << "\nThe student is from: " << get_Province();
    std::cout << "\nThe CGPA is: " << theStudent.getCGPA();
    std::cout << "\nThe Reseach Score is: " << theStudent.getRScore();
    std::cout << "\nThe student ID is: " << theStudent.getid()<< "\n";
}
std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent)
{
    theDomStudent.dstu(outs);
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
string InternationalStudent::get_Country()
{ return Country;}

void InternationalStudent::istu(std::ostream& outs, Student theStudent) const
{
    std::cout << "The student name is: " << theStudent.getFirstName() << theStudent.getLastName();
    std::cout << "\nThey are from: " << get_Country();
    std::cout << "\nThe CGPA is: " << theStudent.getCGPA();
    std::cout << "\nThe Reseach Score is: " << theStudent.getRScore();
    std::cout << "\nThe student ID is: " << theStudent.getid();
    std::cout << "\nThe student TOEFL score is: \nReading:" << ToeflScore.getReading() << "/30";
    std::cout << "\nListening:" << ToeflScore.getListening() << "/30" << "\nSpeaking: " << ToeflScore.getSpeaking() << "/30" << "\nWriting: " << ToeflScore.getWriting();
}

std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent)
{
    theIntStudent.istu(outs);
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
}

char upper2lowercase(char c){
  //checks if letter is within the scope
  if (c >= 'A' && c <= 'Z'){
    c += 32;
    //add 32 according to the ascii table
  }
  else{
    //no changes made otherwise
    return c; 
  }
  return c; 
}
