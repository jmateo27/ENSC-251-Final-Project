#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "student.hpp"
#include "domesticstudent.hpp"
#include "internationalstudent.hpp"

//International Student Linked List
class IntLinkedList{
    public:
        //default constuctor
        IntLinkedList();
        //this function will add the inputted student while also keeping the linked list sorted
        void addIntStudent(InternationalStudent* stud);
        //prints the whole list
        void printList() const;
        //search functions, these will output the students' information who have the exact
        //characteristic as the input
        void searchIntCGPA(float CGPA);
        void searchIntRScore(int RScore);
        void searchIntAppID(int AppID);
        void searchIntName(string name);
        //user inputted information of a new student will be asked from the user
        //the new student will then be placed into the current linked list
        void createIntStu(int& count);
        //deletes the student in the linked list with the inputted name
        void deleteIntStu(string name);
        //deletes the head and the tail of the linked list while 
        //also redefining the new head and tail of the linked list
        void deleteIntHeadTail();
        //deletes the students in the linked list that don't meet the toefl requirements
        //particular requirements are dove deeper in the actual function definition
        void deleteLowToefl();
        
        //get functions, keep ADT functionality
        InternationalStudent* getHead();
        InternationalStudent* getTail();
        //~IntLinkedList();
    private:
        InternationalStudent *head, *tail;
};

//Domestic Student Linked List
class DomLinkedList{
    public:
        //default constructor
        DomLinkedList();
        //this function will add the inputted student while also keeping the linked list sorted
        void addDomStudent(DomesticStudent *stud);
        //prints the whole list
        void printList() const;
        //search functions, these will output the students' information who have the exact
        //characteristic as the input
        int searchDomStudent(DomesticStudent stud);
        void searchDomCGPA(float CGPA);
        void searchDomRScore(int RScore);
        void searchDomAppID(int AppID);
        void searchDomName(string name);
        //user inputted information of a new student will be asked from the user
        //the new student will then be placed into the current linked list
        void createDomStu(int& count);
        //get functions to maintain ADT property
        DomesticStudent* getHead();
        DomesticStudent* getTail();
        //deletes the student in the linked list with the inputted name
        void deleteDomStu(string name);
        //deletes the students in the linked list that don't meet the toefl requirements
        //particular requirements are dove deeper in the actual function definition
        void deleteDomHeadTail();
        //~DomLinkedList();
  private:
        DomesticStudent *head, *tail;
};

//Student Linked List
class GenLinkedList{
    public:
        //default constructor
        GenLinkedList();
        //this function merges the two given lists into one merged list, and this list
        //is then stored into the GenLinkedList object itself
        void mergeGenStudent(IntLinkedList, DomLinkedList);
        //prints the contents of the linked list
        void printList() const;
        //prints all students in the linked list that have characteristics
        //that satisfy the minimum value given in the input
        void printByThresh(float CGPAThresh, float RSThresh);
        //search functions, these will output the students' information who have the exact
        //characteristic as the input
        void searchGenCGPA(float CGPA);
        void searchGenRScore(int RScore);
        void searchGenAppID(int AppID);
        void searchGenName(std::string name);
        //user inputted information of a new student will be asked from the user
        //the new student will then be placed into the current linked list
        void createGenStu(int& count);
        //deletes the student in the list with the given name
        void deleteGenStu(string name);
        //deletes the head and tail of the current list, and also
        //redefines the new head and tail of the list
        void deleteGenHeadTail(); 
        //adds the inputted student into the merged list, while keeping it sorted
        void addGenStudent(Student* stud);       
        //~GenLinkedList();
    private:
        Student *head, *tail;
};

//this function adds up the sizes of the International/DomesticStudent linked list and returns it
int sizeofLists(IntLinkedList inter, DomLinkedList dom);
//this function compares the two inputted floats, needed because comparing two floats is not as intuitive
//outputs 0 if they are equal
bool CompareFloats2 (float y1, float y2);
//adds the students found in the domestic-stu.txt file into the linked list
DomLinkedList makeDomLinkedList(DomLinkedList &DList, int &stu_count);
//adds the students found in the international-stu.txt file into the linked list
IntLinkedList makeIntLinkedList(IntLinkedList &IList, int &stu_count, int &idian);
//error functions used for part 3 of the main
DomLinkedList makeerror1(DomLinkedList &E1, int &stu_count);
DomLinkedList makeerror2(DomLinkedList &E2, int &stu_count);
IntLinkedList makeerror3(IntLinkedList &E3, int &stu_count);
#endif
