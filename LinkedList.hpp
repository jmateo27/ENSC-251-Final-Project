#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "student.hpp"
#include "domesticstudent.hpp"
#include "internationalstudent.hpp"



class IntLinkedList{
    public:
        IntLinkedList();
        void addIntStudent(InternationalStudent* stud);
        void printList() const;
        void searchIntCGPA(float CGPA);
        void searchIntRScore(int RScore);
        void searchIntAppID(int AppID);
        void createIntStu(int& count);
        void searchIntName(string name);
        void deleteIntStu(string name);
        void deleteIntHeadTail();
        void deleteLowToefl();
        InternationalStudent* getHead();
    private:
        InternationalStudent *head,*tail, *next;
};

class DomLinkedList{
    public:
        DomLinkedList();
        void addDomStudent(DomesticStudent *stud);
        void printList() const;
        DomesticStudent* makeDomStu();
        int searchDomStudent(DomesticStudent stud);
        void searchDomCGPA(float CGPA);
        void searchDomRScore(int RScore);
        void searchDomAppID(int AppID);
        void searchDomName(string name);
        void createDomStu(int& count);
        DomesticStudent* getHead();
        void deleteDomStu(string name);
        void deleteDomHeadTail();
  private:
        DomesticStudent *head, *tail;
};

class GenLinkedList{
    public:
        GenLinkedList();
        void mergeGenStudent(IntLinkedList, DomLinkedList);
        void printList() const;
        void addStudent(Student* theStud);
        void printByThresh(float CGPAThresh, float RSThresh);
    private:
        Student *head, *tail;
};
int sizeofLists(IntLinkedList inter, DomLinkedList dom);
DomesticStudent* makeDomStu();
bool CompareFloats2 (float y1, float y2);
#endif