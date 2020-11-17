#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "student.hpp"
#include "domesticstudent.hpp"
#include "internationalstudent.hpp"

class IntLinkedList{
  public:
    IntLinkedList();
	void addIntStudent(InternationalStudent stud); 
	int searchIntStudent(InternationalStudent stud,InternationalStudent *ptr);
  private:
    InternationalStudent *head,*tail, *next;
};

class DomLinkedList{
  public:
    DomLinkedList();
    void addDomStudent(DomesticStudent stud);
    void printList() const;
    int searchDomStudent(DomesticStudent stud);
    DomesticStudent* getHead();
  private:
    DomesticStudent *head,*tail, *next;
};

#endif