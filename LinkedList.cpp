#include "LinkedList.hpp"
#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <typeinfo>

/****************************************************CONSTRUCTORS****************************************************/
IntLinkedList::IntLinkedList(){
    head = NULL;
    tail = NULL;
}

DomLinkedList::DomLinkedList(){
    head = NULL;
    tail = NULL;
}

GenLinkedList::GenLinkedList(){
	Student* temp = new Student; 
    temp = nullptr; 
    head = NULL;
    tail = NULL;
}
/****************************************************PRINT_LIST****************************************************/
void DomLinkedList::printList() const{
    DomesticStudent* temp = head;
	//title
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    while (temp != nullptr){
        temp -> printInfo();
        cout<< endl;
        temp = temp -> next;
    }    
    return;
}

void IntLinkedList::printList() const{
	//title
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    InternationalStudent* temp = head;
    while (temp != nullptr){
        temp -> printInfo();
        cout << "\n";
        temp = temp -> next;
    }    
    return;
}

void GenLinkedList::printList() const{
    Student* temp = head;
	//title
    cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";

    while (temp != tail){
        temp -> printInfo();
        temp = temp -> next;
        cout << endl;
    }
    return;
}

void GenLinkedList::printByThresh(float CGPAThresh, float RSThresh){
    Student* temp = head;
    bool present = 0;
    int count = 0;
	int i = 0; 
    while (temp != nullptr){
        if(temp->getRScore() >= RSThresh && 
           ((temp->getCGPA() > CGPAThresh || CompareFloats2(temp->getCGPA(), CGPAThresh)))){
            if (count == 0){
				//title
                cout << "\n          Name            | StudentID | CGPA | ResearchScore |   From   | ToeflScore\n";
                count++;
            }
            temp -> printInfo();
            cout << endl;
            present = 1;
			i++;
        }
        temp = temp -> next;
    }
    if (present == 0){
        cout << "Threshold given does not include any existing students.\n";
    }
    else{
        cout << "Threshold given includes " << i << " students\n";
    }
}


/****************************************************GET_FUNCTIONS****************************************************/
DomesticStudent* DomLinkedList::getHead(){
    return head; 
}

InternationalStudent* IntLinkedList::getHead(){
  return head;
}

DomesticStudent* DomLinkedList::getTail(){
	return tail;
	}

InternationalStudent* IntLinkedList::getTail(){
	return tail;
	}


/*************************************************DOMESTIC_FUNCTIONS*************************************************/
//This is the insert function for the domestic class
//This function ensures that the student is placed into the list properly,
//keeping the sortedness of the list intact
void DomLinkedList::addDomStudent(DomesticStudent* stud){ 
    if (head == NULL){ //placing first student
    //in this case, no checks need to be made to determine where the student will be placed.
        head = stud; 
        tail = stud;
        tail -> next = NULL;
        return;
    }
    if (tail == head){//placing second student
    //in this case, there are two possibilities, either the student becomes the new head,
    //or becomes the new tail. the same logic is used throughout to determine which.
        switch(compareResearchScore(*stud, *head)){ //will not be repeated.
        //case 1 represents if the research score of the inputted student is bigger, it will
        //inevitably be place atop the current head
        //case -1 represents if the research score of the inputted student is smaller, it will
        //inevitably be placed below the current head.
        //case default is when the two students have the same research score and will then
        //be further assessed by CGPA
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
        //in this case, the list has at least two components, and will now need more checking on what
        //was before and what is the current node.
        //same logic as before
        if (temp == head){
            switch(compareResearchScore(*stud, *temp)){
                case 1: //temp > stud
                    stud -> next = head;
                    head = stud;
                    return;
                case -1: //temp < stud
                    temp = temp -> next;
                    prev = head;// this commences the prev node for the traversal 
                                //through the body of the linked list
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
        else{
            //this portion is when there are more than 2 elements in the list.
            //need to be a bit more careful on where the previous node is to set the link characteristic
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
    //at this point, the student will either be place below or above the current tail
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

//this function represents the addition of the domesic-stu.txt file into the inputted Linked list
DomLinkedList makeDomLinkedList(DomLinkedList& DList, int &stu_count){
    string line;
    char temp; 
    ifstream domesticFile("domestic-stu.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << std::endl;
		cout << "\033[0m";
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
        //here is an instance of error checking, we make sure that the second last
        //expected parameter exists, if so, it will pass correctly,
        //this if will cause a throw and make the program exit
        try{
            if (!getline(ss, s_cgpa, ',').good()){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
			cout << "\033[0m";
            exit(0);
        }
        cgpa = atof(s_cgpa.c_str());
        
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
        try{
            //adding the components into the actual student
            DomesticStudent* aStu = new DomesticStudent;
            aStu -> setFirstName(firstName);
            aStu -> setLastName(lastName);
            aStu -> setCGPA(cgpa);
            aStu -> setResearchScore(researchScore);
            aStu -> setAppID(stu_count);         
            aStu -> setProvince(province);
            //then adding this student into the list, maintaining sortedness
            DList.addDomStudent(aStu);
            stu_count++;      
        }
        catch(bad_alloc){
            //part of the error checking of the project
            //catch bad_allocs and tell the user and exit.
            cout << "Bad Allocation... exiting\n";
			cout << "\033[0m";
            exit(1);
        }
    }
    domesticFile.close();
    return DList;
}

//this function allows an interactive section that lets the user input the desired 
//characteristics of their student.
void DomLinkedList::createDomStu(int& count){
    try{
        DomesticStudent *create = new DomesticStudent; 
        std::string firstName, lastName, province, s_cgpa, s_researchScore;
        string provinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON",
								"MB","SK", "AB", "BC", "YT", "NT", "NU"};
        bool correct = 0, bad = 0;
        float cgpa;
        int researchScore, testcount = 0;;
            //error checking to make sure the user is inputting correct values for
            //each respective prompt
            while(!correct){
                cin.clear();
				
                firstName.clear();
                cout << "Please enter Full Name : ";
                if (bad == 1)
				    cin.ignore(); 
				    cin.ignore(100, '\n'); 
                    getline(cin, firstName, ' ');
				if (!getline(cin, lastName, '\n').good()){
                    cin.clear();
                    bad = 1;
                    cout << "last\n";
                    cout << "Incompatible input, please re-enter the full name.\n";
                    continue;
                }
                
                correct = 1;
            }
            correct = 0;
            while(!correct){
                cout << "CGPA (4.33 Scale): ";
                cin.clear();
				cin >> s_cgpa;
        	    cgpa = atof(s_cgpa.c_str());
				//cin >> cgpa;
                if (cgpa > 4.34 || CompareFloats2(cgpa, 4.34)){
                    cout << "\nThis input is above the maximum 4.33 CGPA, so it has been rounded down to 4.3.\n";
                    cgpa = 4.3;
                    correct = 1;
                }
                else if (cgpa < 0.05){
                    cout << "\nInvalid Entry. Please try again.\n";
                    correct = 0;
                }
                else{
                    correct = 1;
                }
            }
            correct = 0;
            while(!correct){
                cout << "Research Score ( <= 100 ): ";
                cin.clear();
                cin >> s_researchScore;
		        researchScore = atoi(s_researchScore.c_str());
                if (researchScore > 100){
                    cout << "\nThis input is above the maximum 100 Research score, it has been rounded down to 100.\n";
                    researchScore = 100;
                    correct = 1;
                }
                else if (researchScore <= 0){
                    cout << "\nInvalid Entry. Please try again. \n";
                    correct = 0;
                }
                else{
                    correct = 1;
                    continue;
                }
			}
            correct = 0;

			while(!correct){
				cout << "Province Abbreviation: ";
                // cin.clear();
				cin >> province; 

				for(int i = 0; i < 13; i++){
					std::string prov = provinces[i];
					for(int k = 0; k < 2; k++){
						province[k] = tolower(province[k]);
						prov[k] = tolower(prov[k]);
					}
						
					if (province.compare(prov) == 0){
						province = provinces[i];
						correct = 1;
						break;
					}
				}

                if (correct == 0){
                    cout << "Incorrect input for province, please try again.\n";
                }
        
                //correct = 1;
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
		cout << "\033[0m";
        exit(1);
    }
}



/*************************************************SEARCH_FUNCTIONS*************************************************/
void DomLinkedList::searchDomCGPA(float CGPA) {
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){ //prints if cgpa's are equal
        current -> printInfo();
        cout << endl;
		i++;
    }
    current = current -> next;
  }
  	cout << "\x1b[36m"; //teal
    cout << i << " student(s) with a CGPA of: " << CGPA << "\n";
	cout << "\033[0m"; //reset color
}

void DomLinkedList::searchDomRScore(int RScore){
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(std::abs(current->getRScore() - RScore) < 0.001){//prints if research Score's are equal
        current -> printInfo();
        cout << endl;
		i++;
    }
    current = current -> next;
  }

  	cout << "\x1b[36m"; //teal
    cout << i << " student(s) with a Research Score of: " << RScore << "\n";
  	cout << "\033[0m"; //resets color
  
}

void DomLinkedList::searchDomAppID(int AppID){
  int i = 0;
  DomesticStudent* current = head;
  
  while (current != nullptr){
    if(AppID - current->getid() == 20200000){ //prints if id's are equal
        current -> printInfo();
        cout << endl;
		i++;
    }
    current = current -> next;
  }
  	cout << "\x1b[36m";//teal
    cout << i << " student(s) with a Applicant ID of: " << AppID << "\n";
  	cout << "\033[0m";//reset
}

void DomLinkedList::searchDomName(std::string name){
	int i = 0;
  DomesticStudent* current = head;
  while (current != nullptr){
    string fullname = current->getFirstName() + " " + current->getLastName(); 
    if (compareFullName(fullname, name) == 0){ //prints if name's are equal
        current -> printInfo();
        cout << endl;
      i++;
    }
    current = current -> next;
  }
	cout << "\x1b[36m"; //teal
  	cout << i << " student(s) with the name of: " << name << "\n";
  	cout << "\033[0m"; //reset

}

/*************************************************DELETE_FUNCTIONS*************************************************/
void DomLinkedList::deleteDomStu(string name){
    DomesticStudent* previous = nullptr;
    DomesticStudent* current = head;
    bool y = 0;

    while (current != NULL) {
        string fullname = current -> getFirstName() + " " + current -> getLastName();
        if (compareFullName(fullname, name) == 0){ //enters to delete if names are equal
            if (previous == nullptr) {
                head = current -> next;
                y = 1;
            } else {
                previous -> next = current -> next;
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
	
	//deletes head
	if(head != nullptr){
		head = head -> next;
		delete temp;
		temp = head; 
	}
	while(temp != tail){
		prev = prev -> next;
		temp = temp -> next; 
	}
	
	//deletes tail
	delete tail;
	tail = prev;
    if (tail != nullptr)
        tail -> next = nullptr;
}


/*********************************************INTERNATIONAL_FUNCTIONS*********************************************/
//this function is identical to the domestic counterpart, so explanations will not be repeated
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

//this function is identical to the domestic counterpart, so explanations will not be repeated
void IntLinkedList::createIntStu(int& count){
    try{
        InternationalStudent *create = new InternationalStudent; 
        std::string firstName, lastName, country, s_cgpa, s_researchScore;
        int reading, writing, speaking, listening;
        std::string sreading, swriting, sspeaking, slistening;
        string countries[13] = {"Korea", "China", "India", "Iran"};
        bool correct = 0, bad = 0;
        float cgpa;
        int researchScore;
        cin.clear();
            while(!correct){
                cin.clear(); 
                firstName.clear();
                cout << "Please enter Full Name : ";
                if (bad == 1)
				    cin.ignore(); 
				cin.ignore(100, '\n'); 
                getline(cin, firstName, ' ');
				if (!getline(cin, lastName, '\n').good()){
                    cin.clear();
                    cout << "\nIncompatible input, please re-enter the full name.\n";
                    bad = 1;
                    continue;
                }
                correct = 1;
                bad = 0;
            }
            correct = 0;
            while(!correct){
                cout << "CGPA (4.33 Scale): ";
                cin.clear();
				cin >> s_cgpa;
        		cgpa = atof(s_cgpa.c_str());
				
                if (cgpa > 4.34 || CompareFloats2(cgpa, 4.34)){
                    cout << "\nThis input is above the maximum 4.33 CGPA, so it has been rounded down to 4.3.\n";\
                    cgpa = 4.3;
                    correct = 1;
                }
                else if (cgpa < 0.05){
                    cout << "\nThis input is below the minimum 0.5 CGPA, so it has been rounded to 0.\n";
                    cgpa = 0;
                    correct = 1;
                }
                else{
                    correct = 1;
                    continue;
                }
            }
            correct = 0;
            while(!correct){
                cout << "Research Score ( <= 100 ): ";
                cin >> s_researchScore;
		        researchScore = atoi(s_researchScore.c_str());
                if (researchScore > 100){
                    cout << "\nThis input is above the maximum 100 Research score, it has been rounded down to 120.\n";
                    researchScore = 100;
                    correct = 1;
                }
                else if (researchScore < 0){
                    cout << "\nThis input is below the minimum 0 Research score, it has been rounded up to 0.\n";
                    researchScore = 0;
                    correct = 1;
                }
                else{
                    correct = 1;
                    continue;
                }
			}
            correct = 0;

			while(!correct){
				cout << "Country name: ";
				cin >> country; 
				for(int i = 0; i < 4; i++){
					std::string cntry = countries[i];
					for(int j = 0; j < cntry.length(); j++){
						cntry[j] = tolower(cntry[j]);
					}

					for(int k = 0; k < country.length(); k++){
						country[k] = tolower(country[k]);
					}

					if(country.compare(cntry) == 0){
						country = countries[i];
						correct = 1; 
						break; 
					}
				}
                /* for (string i:countries)
                    if (!compareFullName(i, country)){
                        country = i;
                        correct = 1;
                        break;
                    } */
                if (correct == 0){
                    cout << "Incorrect input for country, please try again.\n";
                }
			}

                if (correct == 0){
                    cout << "Incorrect input for province, please try again.\n";
                }
            //this portion ensures that the inputted values will 
            //allow a student that is able to be considered during the 
            //graduate school enrollment process
            correct = 0;
			int lo = 10; 
			while(!correct){
				lo = 10;
				while(lo == 10){
					cout << "\nToeflScore -> "
						<< "Reading : ";
					cin >> sreading;
					if(atoi(sreading.c_str()) > 0 && atoi(sreading.c_str()) <= 30){
						reading = atoi(sreading.c_str()); 
						lo = 0; 
						break; 
					}else{
						std::cout << "Invalid entry, please enter again\n";
						lo = 10;
						// break; 
					}
				}
				
				lo = 10; 
				while(lo == 10){
					cout << "ToeflScore -> Writing : ";
					cin >> swriting;
					if(atoi(swriting.c_str()) > 0 && atoi(swriting.c_str()) <= 30){
						writing = atoi(swriting.c_str()); 
						lo = 0; 
						break; 
					}else{
						std::cout << "Invalid entry, please enter again\n";
						lo = 10;
						// break; 
					}
				}

				lo = 10; 
				while(lo == 10){
					cout << "ToeflScore -> Listening : ";
					cin >> slistening;
					if(atoi(slistening.c_str()) > 0 && atoi(slistening.c_str()) <= 30){
						listening = atoi(slistening.c_str()); 
						lo = 0; 
						break; 
					}else{
						std::cout << "Invalid entry, please enter again\n";
						lo = 10;
						// break; 
					}
				}

				lo = 10; 
				while(lo == 10){
					cout << "ToeflScore -> Speaking : ";
					cin >> sspeaking;
					if(atoi(sspeaking.c_str()) > 0 && atoi(sspeaking.c_str()) <= 30){
						speaking = atoi(sspeaking.c_str()); 
						lo = 0; 
						break; 
					}else{
						std::cout << "Invalid entry, please enter again\n";
						lo = 10;
						// break; 
					}
				}
				
				if (reading < 20 || writing < 20 ||
						listening < 20 || speaking < 20 ||
						reading + writing + listening + speaking < 93){
						cout << "This student does not meet the Toefl requirements \n"
							<< "All components must be over 20 and add up to more than 93\n";
						continue; 
				}else
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
		cout << "\033[0m";
        exit(1);
    }
}

//this function is identical to the domestic counterpart, so explanations will not be repeated
IntLinkedList makeIntLinkedList(IntLinkedList &IList, int &stu_count, int &idian){
    string line2;
    ToeflScore *thetoefl;
    ifstream internationalFile("international-stu.txt");
    
    if(!internationalFile.is_open()) {
      cout << "Unable to open file international-stu.txt" << endl;
	  cout << "\033[0m";
      exit(1);
    }

    getline(internationalFile, line2);
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
			cout << "\033[0m";
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
			cout << "\033[0m";
            exit(1);
        }

    }
    //close your file
    internationalFile.close();
    return IList;
}

/*************************************************SEARCH_FUNCTIONS*************************************************/
void IntLinkedList::searchIntCGPA(float CGPA) {
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(fabs(current->getCGPA() - CGPA) < 0.001){ //prints if cgpa's are equal
		current->printInfo();
    	cout <<"\n";
		i++;
    }
    current = current -> next;
  }
	cout << "\033[33m"; //yellow
    cout << i << " student(s) with a CGPA of: " << CGPA << "\n";
	cout << "\033[0m"; //resets
}

void IntLinkedList::searchIntRScore(int RScore){
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(std::abs(current->getRScore() - RScore) < 0.001){//prints if scores's are equal
    	current->printInfo();
    	cout <<"\n";
		i++;
    }
    current = current -> next;
  }
	cout << "\033[33m"; //yellow
    cout << i << " student(s) with a Research Score of: " << RScore << "\n";
	cout << "\033[0m"; //reset
}

void IntLinkedList::searchIntAppID(int AppID){
  int i = 0;
  InternationalStudent* current = head;
  
  while (current != nullptr){
    if(AppID - current->getid() == 20200000){//prints if id's are equal
		current->printInfo();
    	cout <<"\n";
		i++;
    }
    current = current -> next;
  }
	cout << "\033[33m"; //yellow
    cout << i << " student(s) with a Applicant ID of: " << AppID << "\n";
	cout << "\033[0m"; //reset
}

void IntLinkedList::searchIntName(string name){
	int i = 0;
  InternationalStudent* current = head;
  while (current != nullptr){
	  std::string fullname = current -> getFirstName() + " " + current -> getLastName(); 
    if (compareFullName(fullname, name) == 0){//prints if name's are equal
      current->printInfo();
    	cout <<"\n";
      i++;
    }
    current = current -> next;
  }
	cout << "\033[33m"; //yellow
    cout << i << " student(s) with the name of: " << name << "\n";
	cout << "\033[0m"; //reset
}

/*************************************************DELETE_FUNCTIONS*************************************************/
void IntLinkedList::deleteIntStu(string name){
    InternationalStudent* previous = NULL;
    InternationalStudent* current = head;
    bool y = 0;

    while (current != NULL) {
        string fullname = current -> getFirstName() + " " + current -> getLastName();
        if (compareFullName(fullname, name) == 0){//enters to delete if names are equal
            if (previous == NULL) {
                head = current -> next;
                y = 1;
            } else {
                previous -> next = current -> next;
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

/*************************************************GENERAL_FUNCTIONS*************************************************/
int sizeofLists(IntLinkedList inter, DomLinkedList dom, int &sizeI, int &sizeD){
  int size = 0;
  InternationalStudent* temp1 = inter.getHead();
  DomesticStudent* temp2 = dom.getHead(); 

	//iterates through entire lists and updates size
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
    int size = sizeofLists(inter, dom, sizeI, sizeD); 	//finds the size of array

    if (size == 0){
        cout << "\x1b[31mEmpty Lists, no action executed.\n\033[0m";
        return;
    }

	//initializing variables needed
    InternationalStudent* temp1 = inter.getHead();
    DomesticStudent* temp2 = dom.getHead();
    Student* prev = inter.getHead();
    Student* stud[size];
    DomesticStudent* dupDom;
    InternationalStudent* dupInt;
	int i = 0;

	//assigns values in each list into an array
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
    
	//calls sort functions using array
	mergeSortGen(stud, 0, size - 1, 'r');
    mergeGenCGPA2(stud, 0, size - 1);
    mergeGen3(stud, 0, size - 1);

	//puts sorted array elements into a genlinkedlist 
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
    cout << "\x1b[31mMerged Students together\n" << "\033[0m";
    return;

}

bool CompareFloats2 (float y1, float y2) {
   float diff = y1 - y2;
   return (diff < 0.01) && (-diff < 0.01); //returns if floats are equal or not
}


void GenLinkedList::addGenStudent(Student* stud){
    char domstr[] = "DomesticStudent";
    //char intstr[] = "InternationalStudent";
	const char *typ = typeid(stud).name();
	const char *typ2;
    if (head == NULL){//placing first student
        head = stud;
        tail = stud;
        tail -> next = NULL;
        return;
    }
    if (tail == head){//placing second student
        typ2 = typeid(head).name();
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
                        switch((int)!strcmp(typ, domstr)){
                            case 1: //is domestic
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
    Student* temp = head;
    Student* prev;
    float CGPA = stud -> getCGPA();
    int RS = stud -> getRScore();

    while (temp != tail){
        if (temp == head){
            typ2 = typeid(temp).name();
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
                            switch((int)!strcmp(typ, domstr)){
                                case 1:
                                    stud -> next = head;
                                    head = stud;
                                    return;
                                default:
                                    stud -> next = head -> next;
                                    head -> next = stud;
                            }
                    }
            }
        }
        else{//temp is in the body
            typ2 = typeid(temp).name();
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
                            switch((int)!strcmp(typ, domstr)){
                                case 1:
                                    prev -> next = stud;
                                    stud -> next = temp;
                                    return;
                                default:
                                    stud -> next = temp -> next;
                                    temp -> next = stud;
                                    return;
                            }
                    }
            }
        }
    }
    //if past the while, then place the student at the very end
    typ2 = typeid(temp).name();
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
                    switch((int)!strcmp(typ, domstr)){
                        case 1:
                            prev -> next = stud;
                            stud -> next = tail;
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

/*************************************************SEARCH_FUNCTIONS*************************************************/

void GenLinkedList::searchGenCGPA(float CGPA){
  int i = 0;
  Student* current = head;
  
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

void GenLinkedList::searchGenRScore(int RScore){
  int i = 0;
  Student* current = head;
  
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

void GenLinkedList::searchGenAppID(int AppID){
  int i = 0;
  Student* current = head;
  
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

void GenLinkedList::searchGenName(std::string name){
	int i = 0;
    Student* current = head;
    while (current != nullptr){
        string fullname = current->getFirstName() + " " + current->getLastName(); 
        if (compareFullName(fullname, name) == 0){ //prints if name's are equal
            current -> printInfo();
            cout << endl;
        i++;
    }
    current = current -> next;
  }
	cout << "\x1b[31m"; //pink
  	cout << i << " student(s) with the name of: " << name << "\n";
  	cout << "\033[0m"; //reset

}

void GenLinkedList::createGenStu(int &count){
    Student* create; 
    string countries[5] = {"Canada", "Korea", "China", "India", "Iran"};
    string country;
    cout << "What country is your student from?\n";
    cin >> country;
    if (!strcmp(country.c_str(), "Canada")){
        try{
            DomesticStudent *created = new DomesticStudent;

            std::string firstName, lastName, province, s_cgpa, s_researchScore;
            string provinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON",
									"MB","SK", "AB", "BC", "YT", "NT", "NU"};
            bool correct = 0, bad = 0;
            float cgpa;
            int researchScore;
            while(!correct){
                cin.clear();
                firstName.clear();
                cout << "Please enter Full Name : ";
                if (bad == 1)
                    cin.ignore(); 
				cin.ignore(100, '\n'); 
                getline(cin, firstName, ' ');
                if (!getline(cin, lastName, '\n').good()){
                    cin.clear();
                    cout << "\nIncompatible input, please re-enter the full name.\n";
                    bad = 1;
                    continue;
                }
                bad = 0;
                correct = 1;
            }
            correct = 0;
            while(!correct){
                cout << "CGPA (4.33 Scale): ";
                cin.clear();
                cin >> s_cgpa;
                cgpa = atof(s_cgpa.c_str());
                //cin >> cgpa;
                if (cgpa > 4.34){
                    cout << "\nThis input is above the maximum 4.33 CGPA, so it has been rounded down to 4.3.\n";
                    cgpa = 4.33;
                    correct = 1;
                }
                else if (cgpa < 0.05){
                    cout << "\nThis input is below the minimum 0.5 CGPA, so it has been rounded to 0.\n";
                    cgpa = 0;
                    correct = 1;
                }
                else{
                    correct = 1;
                }
            }
            correct = 0;
            while(!correct){
                cout << "Research Score ( <= 100 ): ";
                cin.clear();
                cin >> s_researchScore;
                researchScore = atoi(s_researchScore.c_str());
                if (researchScore > 100){
                    cout << "\nThis input is above the maximum 100 Research score, it has been rounded down to 100.\n";
                    researchScore = 100;
                    correct = 1;
                }
                else if (researchScore < 0){
                    cout << "\nThis input is below the minimum 0 Research score, it has been rounded up to 0.\n";
                    researchScore = 0;
                    correct = 1;
                }
                else{
                    correct = 1;
                    continue;
                }
            }
            correct = 0;
			while(!correct){
				cout << "Province Abbreviation: ";
                // cin.clear();
				cin >> province; 

				for(int i = 0; i < 13; i++){
					std::string prov = provinces[i];
					for(int k = 0; k < 2; k++){
						province[k] = tolower(province[k]);
						prov[k] = tolower(prov[k]);
					}
						
					if (province.compare(prov) == 0){
						province = provinces[i];
						correct = 1;
						break;
					}
				}

                if (correct == 0){
                    cout << "Incorrect input for province, please try again.\n";
                }
			}
            created -> setFirstName(firstName);  
            created -> setLastName(lastName);  
            created -> setCGPA(cgpa);   
            created -> setResearchScore(researchScore);   
            created -> setAppID(count++);   
            created -> setProvince(province);  
            create = created;
            addGenStudent(create);
            return;
        }
        catch(bad_alloc){
                cout << "Bad Allocation... exiting\n";
				cout << "\033[0m";
                exit(1);
        }
    }
    else{ //international student
        try{
            InternationalStudent *createi = new InternationalStudent; 
            std::string firstName, lastName, s_cgpa, s_researchScore;
            int reading, writing, speaking, listening;
            std::string sreading, swriting, sspeaking, slistening;
            string countries[13] = {"Korea", "China", "India", "Iran"};
            bool correct = 0, bad = 0;
            float cgpa;
            int researchScore;
                while(!correct){
                    cin.clear();
                    firstName.clear();
                    cout << "Please enter Full Name: ";
                    if (bad == 1)
                        cin.clear(); 
				    cin.ignore(100, '\n'); 
                    getline(cin, firstName, ' ');
                    if (!getline(cin, lastName, '\n').good()){
                        cin.clear();
                        cout << "\nIncompatible input, please re-enter the full name.\n";
                        bad = 1;
                        continue;
                    }
                    bad = 0;
                    correct = 1;
                }
                correct = 0;
                while(!correct){
                    cout << "CGPA (4.33 Scale): ";
                    cin.clear();
                    cin >> s_cgpa;
                    cgpa = atof(s_cgpa.c_str());
                    
                    if (cgpa > 4.3){
                        cout << "\nThis input is above the maximum 4.3 CGPA, so it has been rounded down to 4.3.\n";
                        correct = 1;
                    }
                    else if (cgpa < 0.05){
                        cout << "\nThis input is below the minimum 0.5 CGPA, so it has been rounded to 0.\n";
                        correct = 1;
                    }
                    else{
                        correct = 1;
                        continue;
                    }
                }
                correct = 0;
                while(!correct){
                    cout << "Research Score ( <= 100 ): ";
                    cin >> s_researchScore;
                    researchScore = atoi(s_researchScore.c_str());
                    if (researchScore > 100){
                        cout << "\nThis input is above the maximum 100 Research score, it has been rounded down to 100.\n";
                        correct = 1;
                    }
                    else if (researchScore < 0){
                        cout << "\nThis input is below the minimum 0 Research score, it has been rounded up to 0.\n";
                        correct = 1;
                    }
                    else{
                        correct = 1;
                        continue;
                    }
                }

                correct = 0;
                while (!correct){
                    int lo = 10; 
                    while(lo == 10){
                        cout << "\nToeflScore -> "
                            << "Reading : ";
                        cin >> sreading;
                        if(atoi(sreading.c_str()) > 0 && atoi(sreading.c_str()) <= 30){
                            lo = 0; 
                            // break; 
                        }else{
                            std::cout << "Invalid entry, please enter again\n";
                            lo = 10;
                            // break; 
                        }
                    }
                    
                    lo = 10; 
                    while(lo == 10){
                        cout << "ToeflScore -> Writing : ";
                        cin >> swriting;
                        if(atoi(swriting.c_str()) > 0 && atoi(swriting.c_str()) <= 30){
                            lo = 0; 
                            // break; 
                        }else{
                            std::cout << "Invalid entry, please enter again\n";
                            lo = 10;
                            // break; 
                        }
                    }

                    lo = 10; 
                    while(lo == 10){
                        cout << "ToeflScore -> Speaking : ";
                        cin >> sspeaking;
                        if(atoi(sspeaking.c_str()) > 0 && atoi(sspeaking.c_str()) <= 30){
                            lo = 0; 
                            // break; 
                        }else{
                            std::cout << "Invalid entry, please enter again\n";
                            lo = 10;
                            // break; 
                        }
                    }

                    lo = 10; 
                    while(lo == 10){
                        cout << "ToeflScore -> Listening : ";
                        cin >> slistening;
                        if(atoi(slistening.c_str()) > 0 && atoi(slistening.c_str()) <= 30){
                            lo = 0; 
                            // break; 
                        }else{
                            std::cout << "Invalid entry, please enter again\n";
                            lo = 10;
                            // break; 
                        }
                    }
                    reading = atoi(sreading.c_str());
                    writing = atoi(swriting.c_str());
                    speaking = atoi(sspeaking.c_str());
                    listening = atoi(slistening.c_str());
                    if (reading < 20 || writing < 20 ||
                        listening < 20 || speaking < 20 ||
                        reading + writing + listening + speaking < 93){
                        cout << "This student does not meet the Toefl requirements \n"
                            << "All components must be over 20 and add up to more than 93\n";
                        correct = 0;
                    }
                    else
                        correct = 1;
                }   
                ToeflScore newscore(reading, listening, speaking, writing);
                createi -> setFirstName(firstName);
                createi -> setLastName(lastName);
                createi -> setCGPA(cgpa);
                createi -> setResearchScore(researchScore);
                createi -> setAppID(count++);
                createi -> setCountry(country);
                createi -> settoefl(newscore);
                create = createi;
                addGenStudent(create);
            return;
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
			cout << "\033[0m";
            exit(1);
        }
    }
}

void GenLinkedList::deleteGenStu(string name){
    Student* previous = nullptr;
    Student* current = head;

    bool y = 0;

    while (current != NULL) {
        string fullname = current -> getFirstName() + " " + current -> getLastName();
        if (compareFullName(fullname, name) == 0){ //enters to delete if names are equal
            if (previous == nullptr) {
                head = current -> next;
                y = 1;
            } else {
                previous -> next = current -> next;
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

/*************************************************ERROR_CHECK_TESTS*************************************************/
DomLinkedList makeerror1(DomLinkedList& E1, int &stu_count){
    string line;
    char temp; 
    int test = 1;
    ifstream domesticFile("errorcheck1.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file errorcheck1.txt" << std::endl;
        cout <<  "\033[0m"; 
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
            if (!getline(ss, s_cgpa, ',').good()){ //|| test == 1){
                bad = 1;
                throw bad;
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
            cout <<  "\033[0m"; 
            exit(1);
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
            //E1.addDomStudent(aStu);   
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            cout <<  "\033[0m"; 
            exit(1);
        }
    }
    domesticFile.close();
    return E1;
}

DomLinkedList makeerror2(DomLinkedList& E2, int &stu_count){
    string line;
    char temp; 
    ifstream domesticFile("errorcheck2.txt");
    
    if(!domesticFile.is_open()) {
        cout << "Unable to open file errorcheck2.txt" << std::endl;
        cout <<  "\033[0m"; 
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
            if (!getline(ss, s_cgpa, ',').good()){ //|| test == 1){
                bad = 1;
                throw bad;
                cout << "throw\n";
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName <<" is lacking field parameter(s), exiting...\n";
            cout <<  "\033[0m"; 
            exit(1);
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
            //E2.addDomStudent(aStu);    
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            cout <<  "\033[0m"; 
            exit(1);
        }
    }
    domesticFile.close();
    return E2;
}

IntLinkedList makeerror3(IntLinkedList &E3, int &stu_count){
    string line2;
    ToeflScore *thetoefl;
    ifstream internationalFile("errorcheck3.txt");
    
    if(!internationalFile.is_open()) {
      cout << "Unable to open file errorcheck3.txt" << endl;
	  cout << "\033[0m";
      exit(1);
    }

    getline(internationalFile, line2);
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
            if (!getline(ss, s_speaking, ',').good()){ //|| test == 1){
                bad = 1;
                throw bad;
                cout << "throw\n";
            }
        }
        catch(bool e){
            cout << firstName << " " << lastName << " is lacking field parameter(s), exiting...\n";
            cout <<  "\033[0m"; 
            exit(1);
        }
        speaking = atoi(s_speaking.c_str());
        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

		//set Toefl scores
        thetoefl = new ToeflScore[1];  
        thetoefl -> setReading(reading);   
        thetoefl -> setListening(listening);   
        thetoefl -> setWriting(writing);   
        thetoefl -> setSpeaking(speaking);    
        try{
            InternationalStudent* iStu = new InternationalStudent;        
            iStu -> setFirstName(firstName);
            iStu -> setLastName(lastName);
            iStu -> setCGPA(cgpa);
            iStu -> setResearchScore(researchScore);
            iStu -> setCountry(country);
            iStu -> setAppID(stu_count);
            iStu -> settoefl(*(thetoefl));
            //E3.addIntStudent(iStu);
            delete [] thetoefl; 
        }
        catch(bad_alloc){
            cout << "Bad Allocation... exiting\n";
            cout <<  "\033[0m"; 
            exit(1);
        }

    }
    internationalFile.close();
    return E3;
}



