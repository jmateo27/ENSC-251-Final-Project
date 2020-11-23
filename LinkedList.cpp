#include "LinkedList.hpp"
#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
IntLinkedList::IntLinkedList(){
    head = NULL;
    tail = NULL;
}

DomLinkedList::DomLinkedList(){
    head = NULL;
    tail = NULL;
}

GenLinkedList::GenLinkedList(){
    head = NULL;
    tail = NULL;
}

void DomLinkedList::printList() const{
    DomesticStudent* temp = head;
    while (temp != NULL){
        cout << *temp << "\n\n";
        temp = temp -> next;
    }    
    return;
}

void IntLinkedList::printList() const{
    InternationalStudent* temp = head;
    while (temp != NULL){
        cout << *temp << "\n\n";
        temp = temp -> next;
    }    
    return;
}



DomesticStudent* DomLinkedList::getHead(){
    return head; 
}

DomesticStudent* makeDomStu(){
    return new DomesticStudent;
}

//Adding International student sorted
void IntLinkedList::addIntStudent(InternationalStudent* stud){
    if (head == NULL){//placing first student
        head = stud;
        tail = stud;
        tail -> next = NULL;
        return;
    }
    if (tail == head){//placing second student
        switch(compareResearchScore(*stud, *head)){
            case 1:
                stud -> next = head;
                head = stud;
                stud -> next = tail;
                tail -> next = NULL;
                return;
            case -1:
                head -> next = stud;
                tail = stud;
                tail -> next = NULL;
                return;
            default:
                switch(compareCGPA(*stud, *head)){
                    case 1:
                        stud -> next = head;    
                        head = stud;
                        stud -> next = tail;
                        tail -> next = NULL;
                        return;
                    case -1:
                        head -> next = stud;
                        tail = stud;
                        tail -> next = NULL;
                        return;
                    default:
                        switch(compareCountry(*stud, *head)){
                            case 1:
                                stud -> next = head;    
                                head = stud;
                                stud -> next = tail;
                                tail -> next = NULL;
                                return;
                            default:
                                head -> next = stud;
                                tail = stud;
                                tail -> next = NULL;
                                return;
                        }
                }
        }
        return;
    }
    InternationalStudent* temp = head;
    InternationalStudent* prev;
    float CGPA = stud -> getCGPA();
    int RS = stud -> getRScore();

    while (temp -> next != NULL){
        if (temp == head){
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = head;
                    head = stud;
                    return;
                case -1: //temp < stud
                    temp = temp -> next;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = head;
                            head = stud;
                            return;
                        case -1:
                           temp = temp -> next; 
                           break;
                        default:
                            switch(compareCountry(*stud, *temp)){
                                case -1:
                                    temp = temp -> next;
                                    break;
                                default:
                                    stud -> next = head;
                                    head = stud;
                                    return;
                            }
                    }
            }
            prev = head; //commence prev use
        }
        else{//temp is in the body
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = temp;
                    prev -> next = stud;
                    return;
                case -1: //temp < stud
                    prev = prev -> next;
                    temp = temp -> next;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = temp;
                            prev -> next = stud;
                            return;
                        case -1:
                            prev = prev -> next;
                            temp = temp -> next; 
                            break;
                        default:
                            switch(compareCountry(*stud, *temp)){
                                case -1:
                                    prev = prev -> next;
                                    temp = temp -> next;
                                    break;
                                default:
                                    stud -> next = temp;
                                    prev -> next = stud;
                                    return;
                            }
                    }
            }
        }
    }
    //if past the while, then place the student at the very end
    tail -> next = stud;
    tail = stud;
    tail -> next = NULL;
    return;
}

//Adding Domestic student while sorted
void DomLinkedList::addDomStudent(DomesticStudent* stud){
    if (head == NULL){//placing first student
        head = stud;
        tail = stud;
        tail -> next = NULL;
        return;
    }
    if (tail == head){//placing second student
        switch(compareResearchScore(*stud, *head)){
            case 1:
                stud -> next = head;
                head = stud;
                stud -> next = tail;
                tail -> next = NULL;
                return;
            case -1:
                head -> next = stud;
                tail = stud;
                tail -> next = NULL;
                return;
            default:
                switch(compareCGPA(*stud, *head)){
                    case 1:
                        stud -> next = head;    
                        head = stud;
                        stud -> next = tail;
                        tail -> next = NULL;
                        return;
                    case -1:
                        head -> next = stud;
                        tail = stud;
                        tail -> next = NULL;
                        return;
                    default:
                        switch(compareProvince(*stud, *head)){
                            case 1:
                                stud -> next = head;    
                                head = stud;
                                stud -> next = tail;
                                tail -> next = NULL;
                                return;
                            default:
                                head -> next = stud;
                                tail = stud;
                                tail -> next = NULL;
                                return;
                        }
                }
        }
        return;
    }
    DomesticStudent* temp = head;
    DomesticStudent* prev;
    float CGPA = stud -> getCGPA();
    int RS = stud -> getRScore();

    while (temp -> next != NULL){
        if (temp == head){
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = head;
                    head = stud;
                    return;
                case -1: //temp < stud
                    temp = temp -> next;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = head;
                            head = stud;
                            return;
                        case -1:
                           temp = temp -> next; 
                           break;
                        default:
                            switch(compareProvince(*stud, *temp)){
                                case -1:
                                    temp = temp -> next;
                                    break;
                                default:
                                    stud -> next = head;
                                    head = stud;
                                    return;
                            }
                    }
            }
            prev = head; //commence prev use
        }
        else{//temp is in the body
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = temp;
                    prev -> next = stud;
                    return;
                case -1: //temp < stud
                    prev = prev -> next;
                    temp = temp -> next;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = temp;
                            prev -> next = stud;
                            return;
                        case -1:
                            prev = prev -> next;
                            temp = temp -> next; 
                            break;
                        default:
                            switch(compareProvince(*stud, *temp)){
                                case -1:
                                    prev = prev -> next;
                                    temp = temp -> next;
                                    break;
                                default:
                                    stud -> next = temp;
                                    prev -> next = stud;
                                    return;
                            }
                    }
            }
        }
    }
    //if past the while, then place the student at the very end
    tail -> next = stud;
    tail = stud;
    tail -> next = NULL;
    return;
}

//////////////////DOMESTIC//////////////////////////////

void DomLinkedList::searchDomCGPA(float CGPA) {
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a CGPA of: " << CGPA << "\n";
  
}

void DomLinkedList::searchDomRScore(int RScore){
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(std::abs(current->getRScore() - RScore) < 0.001){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a Research Score of: " << RScore << "\n";
  
}


void DomLinkedList::searchDomAppID(int AppID){
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(AppID - current->getid() == 20200000){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a Applicant ID of: " << AppID << "\n";
  
}

void DomLinkedList::searchDomName(std::string name){
	int i = 0;
  DomesticStudent* current = head;
  while (current != nullptr){
    string fullname = current->getFirstName() + " " + current->getLastName(); 
    if (compareFullName(fullname, name) == 0){
      cout << *current << "\n";
      i++;
    }
    current = current -> next;
  }
  cout << i << " student(s) with the name of: " << name << "\n";
  
}

void DomLinkedList::createDomStu(int& count){
	DomesticStudent *create = new DomesticStudent; 
	std::string firstName, lastName, province, s_cgpa, s_researchScore;
	float cgpa;
	int researchScore;
	cout << "Enter the correct values below\n";
  	cout << "First Name ";
    	cin >> firstName;
    cout << "Last Name ";
    	cin  >> lastName;
	cout << "Research Score: ";
  		cin >> s_researchScore;
	cout << "CGPA: ";
  		cin >> s_cgpa;
  	cout << "Province: ";
  		cin >> province;

	cgpa = atof(s_cgpa.c_str());
	researchScore = atoi(s_researchScore.c_str());

	create -> setFirstName(firstName);  
	create -> setLastName(lastName);  
	create -> setCGPA(cgpa);   
	create -> setResearchScore(researchScore);   
	create -> setAppID(count++);   
	create -> setProvince(province);  
	addDomStudent(create);
  return;
}

void DomLinkedList::deleteDomStu(string name){
  DomesticStudent* temp = head;
  DomesticStudent* prev = head;
  bool y = 0;
  if (temp == nullptr){
    cout << "Nothing to delete\n";
    return;
  }
  while (temp != nullptr){
    string fullname = temp -> getFirstName() + " " + temp -> getLastName(); 
    if(compareFullName(fullname, name) == 0){
      if (temp == head){
        head = temp -> next;
        delete temp;
      }
      else if (temp == tail){
        delete tail;
        tail = prev;
        tail -> next = nullptr;
      }
      else{
        prev -> next = temp -> next;
        delete temp;
      }
    y =  1;
    cout << fullname << " successfully deleted\n";
    }
    if (temp == head -> next){
      prev = head;
    }
    prev = prev -> next;
    temp = temp -> next;
  }
  if (y == 0)
    cout << "Nobody with the name " << name << " in the list\n";
}

void DomLinkedList::deleteDomHeadTail(){
	DomesticStudent *temp = head; 
	DomesticStudent* prev = head;

	if(head != nullptr){
		head = temp -> next;
		delete temp;
	}
	while(temp != tail){
		if (temp == head -> next){
		  prev = head;
		}
		prev = prev -> next;
		temp = temp -> next; 
	}
	
	delete tail;
	tail = prev;
  if (tail != nullptr)
	  tail -> next = nullptr;
}

//////////////////INTERNATIONAL//////////////////////////////
void IntLinkedList::searchIntCGPA(float CGPA) {
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a CGPA of: " << CGPA << "\n";
}

void IntLinkedList::searchIntRScore(int RScore){
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(std::abs(current->getRScore() - RScore) < 0.001){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a Research Score of: " << RScore << "\n";
}


void IntLinkedList::searchIntAppID(int AppID){
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(current->getid() - AppID == 20200000){
    	cout << *current << "\n";
		i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with a Applicant ID of: " << AppID << "\n";
}

void IntLinkedList::searchIntName(string name){
	int i = 0;
  InternationalStudent* current = head;
  while (current != nullptr){
	  std::string fullname = current -> getFirstName() + " " + current -> getLastName(); 
    if (compareFullName(fullname, name) == 0){
      cout << *current << "\n";
      i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with the name of: " << name << "\n";
}

void IntLinkedList::createIntStu(int& count){
	InternationalStudent *create = new InternationalStudent; 
	std::string firstName, lastName, country, s_cgpa, s_researchScore;
	float cgpa;
	int researchScore;
	cout << "Enter the correct values below\n";
  	cout << "First Name ";
    cin >> firstName;
    cout << "Last Name ";
    cin  >> lastName;
	  cout << "Research Score: ";
  	cin >> s_researchScore;
	  cout << "CGPA: ";
  	cin >> s_cgpa;
  	cout << "Country: ";
  	cin >> country;

	cgpa = atof(s_cgpa.c_str());
	researchScore = atoi(s_researchScore.c_str());

	create -> setFirstName(firstName);  
	create -> setLastName(lastName);  
	create -> setCGPA(cgpa);   
	create -> setResearchScore(researchScore);   
	create -> setAppID(count++);   
	create -> setCountry(country);  
  //cout << *create;
	addIntStudent(create);
  return;
}

void IntLinkedList::deleteIntStu(string name){
  InternationalStudent* temp = head;
  InternationalStudent* prev = head;
  bool y = 0;
  if (temp == nullptr){
    cout << "Nothing to delete\n";
    return;
  }
  while (temp != nullptr){
    string fullname = temp -> getFirstName() + " " + temp -> getLastName(); 
    if(compareFullName(fullname, name) == 0){
      if (temp == head){
        head = temp -> next;
        delete temp;
      }
      else if (temp == tail){
        delete tail;
        tail = prev;
        tail -> next = nullptr;
      }
      else{
        prev -> next = temp -> next;
        delete temp;
      }
    y =  1;
    cout << fullname << " successfully deleted\n";
    }
    if (temp == head -> next){
      prev = head;
    }
    prev = prev -> next;
    temp = temp -> next;
  }
  if (y == 0)
    cout << "Nobody with the name " << name << " in the list\n";
}
void IntLinkedList::deleteIntHeadTail(){
    InternationalStudent *temp = head; 
	InternationalStudent* prev = head;

	if(head != nullptr){
		head = temp -> next;
		delete temp;
	}
	while(temp != tail){
		if (temp == head -> next){
		  prev = head;
		}
		prev = prev -> next;
		temp = temp -> next; 
	}
	
	delete tail;
	tail = prev;
  if (tail != nullptr)
	  tail -> next = nullptr;
}

InternationalStudent* IntLinkedList::getHead(){
  return head;
}

////////////////////////STUDENT////////////////////////////////
//research score -> cgpa -> domestic > international
int sizeofLists(IntLinkedList inter, DomLinkedList dom, int &sizeI, int &sizeD){
  int size = 0;
  InternationalStudent* temp1 = inter.getHead();
  DomesticStudent* temp2 = dom.getHead(); //getHead isn't a good name
  while (temp1 != nullptr){
	  temp1 = temp1 -> next; 
	  size++;
	  sizeI++;
  }
  while (temp2 != nullptr){
	  temp2 = temp2 -> next; 
	  size++; 
	  sizeD++;
  }
  return size; 
}
 
 
void GenLinkedList::mergeGenStudent(IntLinkedList inter, DomLinkedList dom){
    int sizeI = 0, sizeD = 0;
    int size = sizeofLists(inter, dom, sizeI, sizeD);
    InternationalStudent* temp1 = inter.getHead();
    DomesticStudent* temp2 = dom.getHead();
	Student stud[size];
	std::cout << "sizeD: " << sizeD << "\n";
	std::cout << "sizeI: " << sizeI << "\n";
	int i = 0;

	while (temp1 != nullptr){
        stud[i] = *temp1;
		temp1 = temp1 -> next; 
        i++;
    }
    while (temp2 != nullptr){
        stud[i] = *temp2;
		temp2 = temp2 -> next; 
        i++;
		
    }
	mergeSortGen(stud, 0, size - 1, 'r');
    mergeGenCGPA2(stud, 0, size - 1);
    mergeGen3(stud, 0, size - 1);
	
	Student *temp = new Student; 

	for (int j = 0; j < size ; j++){

		if(j == 0){
			*temp = stud[j];
			head = temp; 
			head->next = temp -> next; 
		}else if (j == size-1){
			*temp = stud[j];
			tail = temp; 
		}else{
			*temp = stud[j];
		}
		cout << "temp: " << *temp << "\n";
		temp = temp -> next; 
		temp = new Student;  

	}
	
	temp->next = nullptr; 
	cout << "last temp: " << temp << "\n";

}

//only prints head
void GenLinkedList::printList() const{
    Student* temp = head;
    while (temp != tail){
        cout << *temp << "\n\n";
        temp = temp -> next;
    }    
    return;
}