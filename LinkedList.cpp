#include "LinkedList.hpp"
#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>

IntLinkedList::IntLinkedList(){
	
    head = NULL;
    tail = NULL;
}

/* IntLinkedList::~IntLinkedList(){
    InternationalStudent *ptr;

    for (ptr = head; head; ptr = head ){
		head = head -> next;
		delete ptr;
    }
    delete head;
}  */

DomLinkedList::DomLinkedList(){
    head = NULL;
    tail = NULL;
}

/* DomLinkedList::~DomLinkedList(){
    DomesticStudent *ptr;

    for (ptr = head; head; ptr = head ){
		head = head -> next;
		delete ptr;
    }
    delete head;
} */

GenLinkedList::GenLinkedList(){
    //head = new Student;
	Student* temp = new Student; 
    temp = nullptr; 
    head = NULL;
    tail = NULL;
}

/* GenLinkedList::~GenLinkedList(){
	Student *ptr;

    for (ptr = head; head; ptr = head ){
		head = head -> next;
		delete ptr;
    }
    delete head;
} */

void DomLinkedList::printList() const{
    DomesticStudent* temp = head;
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    while (temp != nullptr){
        temp -> printInfo();
        cout<< endl;
        temp = temp -> next;
    }    
    return;
}

void IntLinkedList::printList() const{
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    InternationalStudent* temp = head;
    while (temp != nullptr){
        temp -> printInfo();
        cout << "\n";
        //cout << *temp << "\n\n";
        temp = temp -> next;
    }    
    return;
}

DomesticStudent* DomLinkedList::getHead(){
    return head; 
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
                    prev = head;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = head;
                            head = stud;
                            return;
                        case -1:
                           temp = temp -> next; 
                           prev = head;
                           break;
                        default:
                            switch(compareCountry(*stud, *temp)){
                                case -1:
                                    temp = temp -> next;
                                    prev = head;
                                    break;
                                default:
                                    stud -> next = head;
                                    head = stud;
                                    return;
                            }
                    }
            }
        }
        else{//temp is in the body
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp < stud
                    stud -> next = temp;
                    prev -> next = stud;
                    return;
                case -1: //temp > stud
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
    switch(compareResearchScore(*stud, *temp)){
        case 1: //temp < stud
            prev -> next = stud;
            stud -> next = temp;
            return;

        case -1: //temp > stud
            tail -> next = stud;
            tail = stud;
            tail -> next = NULL;
            break;
        default: //temp = stud
            switch(compareCGPA(*stud, *temp)){
                case 1:
                    stud -> next = temp;
                    prev -> next = stud;
                    return;
                case -1:
                    tail -> next = stud;
                    tail = stud;
                    tail -> next = NULL;
                    break;
                default:
                    switch(compareCountry(*stud, *temp)){
                        case 1:
                            tail -> next = stud;
                            tail = stud;
                            tail -> next = NULL;
                            break;
                        default:
                            tail -> next = stud;
                            tail = stud;
                            tail -> next = NULL;
                            return;
                    }
            }
    }
    return;
}

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

    while (temp != tail){
        if (temp == head){
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = head;
                    head = stud;
                    return;
                case -1: //temp < stud
                    temp = temp -> next;
                    prev = head;
                    break;
                default: //temp = stud
                    switch(compareCGPA(*stud, *temp)){
                        case 1:
                            stud -> next = head;
                            head = stud;
                            return;
                        case -1:
                           temp = temp -> next; 
                           prev = head;
                           break;
                        default:
                            switch(compareProvince(*stud, *temp)){
                                case -1:
                                    temp = temp -> next;
                                    prev = head;
                                    break;
                                default:
                                    stud -> next = head;
                                    head = stud;
                                    return;
                            }
                    }
            }
        }
        else{//temp is in the body
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp < stud
                    stud -> next = temp;
                    prev -> next = stud;
                    return;

                case -1: //temp > stud
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
    switch(compareResearchScore(*stud, *temp)){
        case 1: //temp < stud
            prev -> next = stud;
            stud -> next = temp;
            return;

        case -1: //temp > stud
            tail -> next = stud;
            tail = stud;
            tail -> next = NULL;
            break;
        default: //temp = stud
            switch(compareCGPA(*stud, *temp)){
                case 1:
                    stud -> next = temp;
                    prev -> next = stud;
                    return;
                case -1:
                    tail -> next = stud;
                    tail = stud;
                    tail -> next = NULL;
                    break;
                default:
                    switch(compareProvince(*stud, *temp)){
                        case 1:
                            tail -> next = stud;
                            tail = stud;
                            tail -> next = NULL;
                            break;
                        default:
                            tail -> next = stud;
                            tail = stud;
                            tail -> next = NULL;
                            return;
                    }
            }
    }
    return;
}

//////////////////DOMESTIC//////////////////////////////

void DomLinkedList::searchDomCGPA(float CGPA) {
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){
        current -> printInfo();
        cout << endl;
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
        current -> printInfo();
        cout << endl;
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
        current -> printInfo();
        cout << endl;
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
        current -> printInfo();
        cout << endl;
      i++;
    }
    current = current -> next;
  }
  cout << i << " student(s) with the name of: " << name << "\n";
}

void DomLinkedList::createDomStu(int& count){
    try{
        DomesticStudent *create = new DomesticStudent; 
        std::string firstName, lastName, province, s_cgpa, s_researchScore;
        string provinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON",
									"MB","SK", "AB", "BC", "YT", "NT", "NU"};
        bool correct = 0;
        float cgpa;
        int researchScore;
            while(!correct){
                cout << "Fullname: ";
                getline(cin, firstName, ' ');
				if (!getline(cin, lastName, '\n').good()){
                    continue;
                }
                correct = 1;
            }
            correct = 0;
            while(!correct){
                cout << "CGPA (4.33 Scale): ";
				cin >> s_cgpa;
        		cgpa = atof(s_cgpa.c_str());
				
                if (!(cin >> s_cgpa)){
                    continue;
                }
                else if (cgpa > 4.3){
                    cout << "\nThis input is above the maximum 4.3 CGPA, so it has been rounded down to 4.3.\n";
                    correct = 1;
                }
                else if (cgpa < 0.05){
                    cout << "\nThis input is below the minimum 0.5 CGPA, so it has been rounded to 0.\n";
                    correct = 1;
                }
            }
            correct = 0;
            while(!correct){
                cout << "Research Score ( <= 120 ): ";
                cin >> s_researchScore;
		        researchScore = atoi(s_researchScore.c_str());
                if (researchScore > 120){
                    cout << "\nThis input is above the maximum 120 Research score, it has been rounded down to 120.\n";
                    correct = 1;
                }
                else if (researchScore < 0){
                    cout << "\nThis input is below the minimum 0 Research score, it has been rounded up to 0.\n";
                    correct = 1;
                }
                else{
                    continue;
                }
			}
            correct = 0;

			while(!correct){
				cout << "Province Abbreviation: ";
				cin >> province; 
                for (string i:provinces)
                    if (!compareFullName(i, province)){
                        province = i;
                        correct = 1;
                        break;
                    }
                if (correct == 0){
                    cout << "Incorrect input for province, please try again.\n";
                }
			}

        create -> setFirstName(firstName);  
        create -> setLastName(lastName);  
        create -> setCGPA(cgpa);   
        create -> setResearchScore(researchScore);   
        create -> setAppID(count++);   
        create -> setProvince(province);  
        addDomStudent(create);
        return;
    }
    catch(bad_alloc){
        cout << "Bad Allocation... exiting\n";
        exit(1);
    }
}

void DomLinkedList::deleteDomStu(string name){
    DomesticStudent* previous = nullptr;
    DomesticStudent* current = head;
    bool y = 0;

    while (current != NULL) {
        string fullname = current -> getFirstName() + " " + current -> getLastName();
        if (compareFullName(fullname, name) == 0){
            if (previous == NULL) {
                head = current -> next;
            } else {
                previous -> next = current -> next;
                cout << current -> getFirstName() << " " << current -> getLastName()
                     << " successfully deleted.\n";
                y = 1;
            }
        } else {
            previous = current; // if we removed current, let previous remain the same
        }
        current = current -> next;
    }
    if (!y){
        cout << "No student with the name " << name << ".\n";
    }
    return;
}

void DomLinkedList::deleteDomHeadTail(){
	DomesticStudent *temp = head;
	DomesticStudent* prev = head;

	if(head != nullptr){
		head = head -> next;
		delete temp;
		temp = head; 
	}
	while(temp != tail){
		prev = prev -> next;
		temp = temp -> next; 
	}
	
	delete tail;
	tail = prev;
    //tail -> next = nullptr;
 if (tail != nullptr)
	  tail -> next = nullptr;
}

//////////////////INTERNATIONAL//////////////////////////////
void IntLinkedList::searchIntCGPA(float CGPA) {
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){
		current->printInfo();
    	cout <<"\n";
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
    	current->printInfo();
    	cout <<"\n";
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
		current->printInfo();
    	cout <<"\n";
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
      current->printInfo();
    	cout <<"\n";
      i++;
    }
    current = current -> next;
  }
    cout << i << " student(s) with the name of: " << name << "\n";
}

void IntLinkedList::createIntStu(int& count){
    try{
        InternationalStudent *create = new InternationalStudent; 
        std::string firstName, lastName, country, s_cgpa, s_researchScore;
        int reading, writing, speaking, listening;
        string countries[13] = {"Korea", "China", "India", "Iran"};
        bool correct = 0;
        float cgpa;
        int researchScore;
            while(!correct){
                cout << "Fullname: ";
                getline(cin, firstName, ' ');
				if (!getline(cin, lastName, '\n').good()){
                    cout << "\nIncompatible input, please re-enter the full name.\n";
                    continue;
                }
                correct = 1;
            }
            correct = 0;
            while(!correct){
                cout << "CGPA (4.33 Scale): ";
				cin >> s_cgpa;
        		cgpa = atof(s_cgpa.c_str());
				
                if (!(cin >> cgpa)){
                    continue;
                }
                else if (cgpa > 4.3){
                    cout << "\nThis input is above the maximum 4.3 CGPA, so it has been rounded down to 4.3.\n";
                    correct = 1;
                }
                else if (cgpa < 0.05){
                    cout << "\nThis input is below the minimum 0.5 CGPA, so it has been rounded to 0.\n";
                    correct = 1;
                }
            }
            correct = 0;
            while(!correct){
                cout << "Research Score ( <= 120 ): ";
                cin >> s_researchScore;
		        researchScore = atoi(s_researchScore.c_str());
                if (researchScore > 120){
                    cout << "\nThis input is above the maximum 120 Research score, it has been rounded down to 120.\n";
                    correct = 1;
                }
                else if (researchScore < 0){
                    cout << "\nThis input is below the minimum 0 Research score, it has been rounded up to 0.\n";
                    correct = 1;
                }
                else{
                    continue;
                }
			}
            correct = 0;

			while(!correct){
				cout << "Country name: ";
				cin >> country; 
                for (string i:countries)
                    if (!compareFullName(i, country)){
                        country = i;
                        correct = 1;
                        break;
                    }
                if (correct == 0){
                    cout << "Incorrect input for country, please try again.\n";
                }
			}
            correct = 0;
            while(!correct){
                cout << "ToeflScore :\n"
                     << "Reading : ";
                cin >> reading;
                cout << "Writing : ";
                cin >> writing;
                cout << "Listening : ";
                cin >> listening;
                cout << "Speaking : ";
                cin >> speaking;
                if (reading < 20 || writing < 20 ||
                    listening < 20 || speaking < 20 ||
                    reading + writing + listening + speaking < 93){
                    cout << "The student will not be considered with \n"
                         << "the inputted scores. Please re-input.\n";
                    continue;
                }
                correct = 1;
            }
            ToeflScore newscore(reading, listening, speaking, writing);
            create -> setFirstName(firstName);
            create -> setLastName(lastName);
            create -> setCGPA(cgpa);
            create -> setResearchScore(researchScore);
            create -> setAppID(count++);
            create -> setCountry(country);
            create -> settoefl(newscore);
            addIntStudent(create);
        return;
    }
	catch(bad_alloc){
        cout << "Bad Allocation... exiting\n";
        exit(1);
    }
}

void IntLinkedList::deleteIntStu(string name){
    InternationalStudent* previous = NULL;
    InternationalStudent* current = head;
    bool y = 0;

    while (current != NULL) {
        string fullname = current -> getFirstName() + " " + current -> getLastName();
        if (compareFullName(fullname, name) == 0){
            if (previous == NULL) {
                head = current -> next;
            } else {
                previous -> next = current -> next;
                cout << current -> getFirstName() << " " << current -> getLastName()
                     << " successfully deleted.\n";
                y = 1;
            }
        } else {
            previous = current; // if we removed current, let previous remain the same
        }
        current = current -> next;
    }
    if (!y){
        cout << "No student with the name " << name << ".\n";
    }
    return;
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

void IntLinkedList::deleteLowToefl(){
    InternationalStudent* previous = NULL;
    InternationalStudent* current = head;

    while (current != NULL) {
        if (current -> getToefl().getWriting() < 20 ||
            current -> getToefl().getReading() < 20 || 
            current -> getToefl().getListening() < 20 || 
            current -> getToefl().getSpeaking() < 20 || 
            current -> getToefl().getTOEFL() < 93){
            if (previous == NULL) {
                head = current -> next;
            } else {
                previous -> next = current -> next;
            }
        } else {
            previous = current; // if we removed current, let previous remain the same
        }
        current = current -> next;
    }
    return;
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
    Student* prev = inter.getHead();
    Student* stud[size];
    //temp1.printInfo();
    DomesticStudent* dupDom;
    InternationalStudent* dupInt;
	int i = 0;

	while (temp1 != nullptr){
        stud[i] = temp1;
        temp1 = temp1 -> next;
        i++;
    }
    while (temp2 != nullptr){
        stud[i] = temp2;
        temp2 = temp2 -> next;
        i++;
    }
    
	mergeSortGen(stud, 0, size - 1, 'r');
    mergeGenCGPA2(stud, 0, size - 1);
    mergeGen3(stud, 0, size - 1);
    Student* ptr;
    int j = 0;
    head = stud[j] -> copystu();
    j++;
    Student* temp;
	temp = head;
    while (j < size){
        temp -> next = stud[j] -> copystu();
        temp = temp -> next;
        j++;
    }
    tail = temp;
	
	temp->next = nullptr;
    return;

}

void GenLinkedList::printList() const{
    Student* temp = head;
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    while (temp != tail){
        temp -> printInfo();
        //cout << *temp << "\n\n";
        temp = temp -> next;
        cout << endl;
    }
    return;
}

void GenLinkedList::printByThresh(float CGPAThresh, float RSThresh){
    Student* temp = head;
    bool present = 0;
    while (temp != nullptr){
        if(temp->getRScore() >= RSThresh && ((temp->getCGPA() > CGPAThresh || CompareFloats2(temp->getCGPA(), CGPAThresh)))){
            temp -> printInfo();
            cout << endl;
            present = 1;
        }
        temp = temp -> next;
    }
    if (present == 0){
        cout << "Threshold given does not include any existing students.\n";
    }
}

bool CompareFloats2 (float y1, float y2) 
{
   float diff = y1 - y2;
   return (diff < 0.01) && (-diff < 0.01);
}

DomLinkedList makeDomLinkedList(DomLinkedList& DList, int &stu_count){
    string line;
    char temp; 
    ifstream domesticFile("domestic-stu.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << std::endl;
        exit(1);
    }

    getline(domesticFile, line);          
    
    while( getline(domesticFile, line) ) {
        
        istringstream ss(line);

        std::string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;
    
        getline(ss, firstName, ',');

        getline(ss, lastName, ',');

        getline(ss, province, ',');
        bool bad = 0;
        try{
            if (!getline(ss, s_cgpa, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
            exit(0);
        }
        cgpa = atof(s_cgpa.c_str());
        
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
        try{
            DomesticStudent* aStu = new DomesticStudent;
            aStu -> setFirstName(firstName);
            aStu -> setLastName(lastName);
            aStu -> setCGPA(cgpa);
            aStu -> setResearchScore(researchScore);
            aStu -> setAppID(stu_count);         
            aStu -> setProvince(province);
            DList.addDomStudent(aStu);
            stu_count++;      
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            exit(1);
        }
    }
    domesticFile.close();
    return DList;
}

IntLinkedList makeIntLinkedList(IntLinkedList &IList, int &stu_count){
    string line2;
    ToeflScore *thetoefl;
    ifstream internationalFile("international-stu.txt");
    
    if(!internationalFile.is_open()) {
      cout << "Unable to open file international-stu.txt" << endl;
      exit(1);
    }

    getline(internationalFile, line2);
    bool idian = 0;
    while( getline(internationalFile, line2) ) {

        istringstream ss(line2);

        std::string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;

        getline(ss, firstName, ',');

        getline(ss, lastName, ',');

        getline(ss, country, ',');

        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

        bool bad = 0;
        try{
            if (!getline(ss, s_speaking, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName << " is lacking field parameter(s), exiting...\n";
            exit(1);
        }
        speaking = atoi(s_speaking.c_str());
        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

        thetoefl = new ToeflScore[1];   //allocate memory for the given student's Toefl score to then set their toefl score
        thetoefl -> setReading(reading);    //set the reading score of the given student
        thetoefl -> setListening(listening);    //set the listening score of the given student
        thetoefl -> setWriting(writing);    //set the writing score of the given student
        thetoefl -> setSpeaking(speaking);    //set the speaking score of the given student 
        try{
            InternationalStudent* iStu = new InternationalStudent;        
            iStu -> setFirstName(firstName);
            iStu -> setLastName(lastName);
            iStu -> setCGPA(cgpa);
            iStu -> setResearchScore(researchScore);
            iStu -> setAppID(stu_count);
            if (iStu -> setCountry(country) == 1){
                idian = 1;
            }
            iStu -> settoefl(*(thetoefl));
            IList.addIntStudent(iStu);
            delete [] thetoefl; 
            stu_count++;
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            exit(1);
        }

    }

    if (idian == 1){
        cout << "Warning! Typo(s) detected, we have set 'Idian' to 'India'\n";
    }
    //close your file
    internationalFile.close();
    return IList;
}

/////////////////////////////////////ERROR CHECK TESTS///////////////////////////////
DomLinkedList makeerror1(DomLinkedList& DList, int &stu_count){
    string line;
    char temp; 
    ifstream domesticFile("errorcheck1.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file errorcheck1.txt" << std::endl;
        exit(1);
    }

    getline(domesticFile, line);          
    
    while( getline(domesticFile, line) ) {
        
        istringstream ss(line);

        std::string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;
    
        getline(ss, firstName, ',');

        getline(ss, lastName, ',');

        getline(ss, province, ',');
        bool bad = 0;
        try{
            if (!getline(ss, s_cgpa, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
            exit(0);
        }
        cgpa = atof(s_cgpa.c_str());
        
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
        try{
            DomesticStudent* aStu = new DomesticStudent;
            aStu -> setFirstName(firstName);
            aStu -> setLastName(lastName);
            aStu -> setCGPA(cgpa);
            aStu -> setResearchScore(researchScore);
            aStu -> setAppID(stu_count);         
            aStu -> setProvince(province);
            DList.addDomStudent(aStu);
            stu_count++;      
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            exit(1);
        }
    }
    domesticFile.close();
    return DList;
}

DomLinkedList makeerror2(DomLinkedList& DList, int &stu_count){
    string line;
    char temp; 
    ifstream domesticFile("errorcheck2.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file errorcheck2.txt" << std::endl;
        exit(1);
    }

    getline(domesticFile, line);          
    
    while( getline(domesticFile, line) ) {
        
        istringstream ss(line);

        std::string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;
    
        getline(ss, firstName, ',');

        getline(ss, lastName, ',');

        getline(ss, province, ',');
        bool bad = 0;
        try{
            if (!getline(ss, s_cgpa, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
            exit(0);
        }
        cgpa = atof(s_cgpa.c_str());
        
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
        try{
            DomesticStudent* aStu = new DomesticStudent;
            aStu -> setFirstName(firstName);
            aStu -> setLastName(lastName);
            aStu -> setCGPA(cgpa);
            aStu -> setResearchScore(researchScore);
            aStu -> setAppID(stu_count);         
            aStu -> setProvince(province);
            DList.addDomStudent(aStu);
            stu_count++;      
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            exit(1);
        }
    }
    domesticFile.close();
    return DList;
}

IntLinkedList makeerror3(IntLinkedList &E3, int &stu_count){
    string line2;
    ToeflScore *thetoefl;
    ifstream internationalFile("errorcheck3.txt");
    
    if(!internationalFile.is_open()) {
      cout << "Unable to open file errorcheck3.txt" << endl;
      exit(1);
    }

    getline(internationalFile, line2);
    bool idian = 0;
    while( getline(internationalFile, line2) ) {

        istringstream ss(line2);

        std::string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;

        getline(ss, firstName, ',');

        getline(ss, lastName, ',');

        getline(ss, country, ',');

        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

        bool bad = 0;
        try{
            if (!getline(ss, s_speaking, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName << " is lacking field parameter(s), exiting...\n";
            exit(1);
        }
        speaking = atoi(s_speaking.c_str());
        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

        thetoefl = new ToeflScore[1];   //allocate memory for the given student's Toefl score to then set their toefl score
        thetoefl -> setReading(reading);    //set the reading score of the given student
        thetoefl -> setListening(listening);    //set the listening score of the given student
        thetoefl -> setWriting(writing);    //set the writing score of the given student
        thetoefl -> setSpeaking(speaking);    //set the speaking score of the given student 
        try{
            InternationalStudent* iStu = new InternationalStudent;        
            iStu -> setFirstName(firstName);
            iStu -> setLastName(lastName);
            iStu -> setCGPA(cgpa);
            iStu -> setResearchScore(researchScore);
            iStu -> setAppID(stu_count);
            if (iStu -> setCountry(country) == 1){
                idian = 1;
            }
            iStu -> settoefl(*(thetoefl));
            E3.addIntStudent(iStu);
            delete [] thetoefl; 
            stu_count++;
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            exit(1);
        }

    }

    if (idian == 1){
        cout << "Warning! Typo(s) detected, we have set 'Idian' to 'India'\n";
    }
    //close your file
    internationalFile.close();
    return E3;
}