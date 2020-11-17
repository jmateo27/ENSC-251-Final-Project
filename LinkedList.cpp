#include "LinkedList.hpp"
#include <iostream>

IntLinkedList::IntLinkedList(){
    head = NULL;
    tail = NULL;
}

DomLinkedList::DomLinkedList(){
    head = NULL;
    tail = NULL;
}

void IntLinkedList::addIntStudent(InternationalStudent stud){
	InternationalStudent *tmpstud = new InternationalStudent; 
	if(head == NULL){
		head = tmpstud; 
	}else{
		int placeholder = searchIntStudent(stud, tmpstud);
		if(placeholder == 1){//stud < tmpstud 
			//need to figure out how to add :P
		}else if (placeholder == 0){// stud > tmpstud
			
		}
	}
}

int IntLinkedList::searchIntStudent(InternationalStudent stud, InternationalStudent *ptr){

	int comp, comp2, comp3; 
    ptr = stud.next; 
	comp = compareResearchScore(stud, *ptr);
	std::cout << "this is comp: " << comp << "\n";
	
	while (ptr != tail ){
		if (comp == 0){
			comp2 = compareCGPA(stud, *ptr);
		}else if(comp == -1){
        	return -1; 
        }

		if (comp2 == 0){
			comp3 = compareCountry(stud, *ptr);
		}else if(comp2 == 1){ //stud > stud->next
			return 1; 
		}else if(comp2 == -1){
			return -1; 
		}

		if(comp3 == 1){ //stud > stud->next
			return 1; 
		}else{
			return -1; 
		}

        ptr = ptr->next; 
        int comp = compareResearchScore(stud, *ptr);
	}

	if (ptr == tail){
		return -1;
	}
}

void DomLinkedList::printList() const{
    DomesticStudent* temp = head;
    while (temp != NULL){
        cout << *temp << "\n\n";
    }    
    return;
}

DomesticStudent* DomLinkedList::getHead(){
    return head; 
}


void DomLinkedList::addDomStudent(DomesticStudent stud){
    DomesticStudent *toAdd = new DomesticStudent;
    DomesticStudent *temp = head;
    DomesticStudent *prev;
    *toAdd = stud;
    int RScore = 0, CGPA = 0;
    string province;
    if(head == NULL){
        head = toAdd;
        tail = toAdd;
    } else{
        RScore = stud.getRScore();
        CGPA = stud.getCGPA();
        province = stud.getProvince();
        prev = head;
        do{
            if (temp == head){
                if (RScore == temp -> getRScore()){//keep going
                    if (CGPA == temp -> getCGPA()){
                        if (compareProvince(*toAdd, *temp) == 0 ||
                            compareProvince(*toAdd, *temp) == 1){
                            temp -> next = head;
                            head = temp;
                        } else if (compareProvince(*toAdd, *temp) == -1)
                            temp = temp -> next;
                        else exit(1);
                    } else if (CGPA > temp -> getCGPA()){
                        temp -> next = head;
                        head = temp;
                    } else if (CGPA < temp -> getCGPA())
                        temp = temp -> next;
                    else exit(1);
                } else if (RScore > temp -> getRScore()){
                    temp -> next = head;
                    head = temp;
                } else if (RScore < temp -> getRScore())
                    temp = temp -> next;
                else exit(1);
            } else{
                if (RScore == temp -> getRScore()){ //compare research score
                    if (CGPA == temp -> getCGPA()){
                        if (compareProvince(*toAdd, *temp) == 0 ||
                            compareProvince(*toAdd, *temp) == 1){
                            temp -> next = prev -> next;
                            prev -> next = temp;
                        } else if (compareProvince(*toAdd, *temp) == -1){
                            prev = prev -> next;
                            temp = temp -> next;
                        } else exit(1);
                    } else if (CGPA > temp -> getCGPA()){
                        temp -> next = prev -> next;
                        prev -> next = temp;
                    } else if (CGPA < temp -> getCGPA()){
                        prev = prev -> next;
                        temp = temp -> next;
                    } else exit(1);
                } else if (RScore > temp -> getRScore()){
                    temp -> next = prev -> next;
                    prev -> next = temp;
                } else if (RScore < temp -> getRScore()){
                    prev = prev -> next;
                    temp = temp -> next;
                } else exit(1);
            }
            if (head -> next != NULL){
                if (head -> next == temp)
                    prev = head;
            }
        } while (temp != tail);
        if (temp == tail){ //if is the lowest
            tail -> next = temp;
            tail = temp;
        }
    }
    return;
} 