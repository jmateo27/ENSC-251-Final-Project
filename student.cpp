#include "student.hpp"
#include "LinkedList.hpp"
#include <typeinfo>
#include <iostream>
/**********************************Student class constructors****************************************/
Student::Student(std::string FName, std::string LName, float grade, int RScore, int id) 
  : FirstName(FName), LastName(LName){
    setResearchScore(RScore);
    setAppID(id);
    setCGPA(grade);
}

Student::Student(std::string FName, std::string LName, int id)
    : FirstName(FName), LastName(LName){
    setAppID(id);
}

Student::Student() 
{}

//virtual function
Student* Student::copystu(){
    cout << "Shouldn't be here.\n";
    exit(1);
}

/***************************************Set functions***********************************************/
void Student::setFirstName(std::string FName){
    FirstName = FName;
}

void Student::setLastName(std::string LName){  
    LastName = LName;
}

void Student::setCGPA(float grade){   
  CGPA = grade;
  if (CGPA < 0.05)
    CGPA = 0; 
  else if (CGPA > 4.3)
    CGPA = 4.3;

  for(float i = 0.1; i <= 4.3; i+=0.1){
    if (((i - 0.05) <= CGPA) && (CGPA <= (i + 0.04999)))
        CGPA = i;
  }
}

void Student::setResearchScore(int RScore){  
    if (RScore > 100)
        ResearchScore = 100;
    else if (RScore < 0)
        ResearchScore = 0;
    else
        ResearchScore = RScore; 
}

void Student::setAppID(int id){
    if (id > 9999)
        AppID = 9999;
    else if (id < 0)
        AppID = 0;
    else
        AppID = id;   
}

/*****************************************Get functions*********************************************/
std::string Student::getFirstName() const{    
    return FirstName; 
}

std::string Student::getLastName() const{   
    return LastName; 
}

float Student::getCGPA() const{    
    return CGPA; 
}

int Student::getRScore() const{
    return ResearchScore; 
}

int Student::getid() const{
    return AppID;
}
/**************************Overloaded exertion operator for Student*******************************/
std::ostream& operator <<(std::ostream& outs, const Student& theStudent)
{
    outs << "The student's name is: " << theStudent.getFirstName() << " " << theStudent.getLastName();
    outs << "\nThe CGPA is: " << theStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theStudent.getid()); 
    outs << "\n";
    return outs;
}

/****************************Compare functions for Student****************************************/
int compareResearchScore(Student student1, Student student2){
    int rscore1 = student1.getRScore(); 
    int rscore2 = student2.getRScore(); 

    if (rscore1 == rscore2)
      return 0;
    else if (rscore1 > rscore2)
      return 1;
    else
      return -1;
    
}

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

    if (name1.length() >= name2.length()) //determine until what length to compare
        len = name1.length();
    else
        len = name2.length();

    for (int i = 0; i < len; i++){    //start comparing the names relying on the ascii table
        if (upper2lowercase(name1[i]) < upper2lowercase(name2[i])){   //to make the math easier, the upper2lowercase function is used
            return 1;
        }
        else if (upper2lowercase(name1[i]) > upper2lowercase(name2[i])){
            return -1;
        }
    }
    return 0;   //if not greater or lesser, equal
}

//same process as the compare first name, will not be repeated
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

void formatID(std::ostream& outs, const int num) {
    int i = 0;

	//fills with the appropriate amount of digits
    if (num - 10 < 0) 
        i = 3;
    else if (num - 100 < 0) 
        i = 2;
    else if (num - 1000 < 0) 
        i = 1;
    else                  
        i = 0;
	//displaying the output depending on how many digits
    while (i != 0){     
        outs << "0";
        i--;
    } 
    outs << num;
}


int compareFullName(string n1, string n2){

    int len = 0;
	//assigns largest length to len
    if (n1.length() >= n2.length())
        len = n1.length();
    else
        len = n2.length();

	
    for (int i = 0; i < len; i++){
        if (upper2lowercase(n1[i]) < upper2lowercase(n2[i])){ //n1 > n2
            return 1; 
        }
        else if (upper2lowercase(n2[i]) > upper2lowercase(n2[i])){ //n2 > n1
            return -1;
        }
    }
	//n1 == n2
    return 0;
}


//mergesorting functions
void mergeSortGen(Student *arr[], int min, int max, char c){
	if (min < max){   
		int mid = min + (max - min) / 2;
		mergeSortGen(arr, min, mid, c);
		mergeSortGen(arr, mid + 1, max, c);
		mergeGen(arr, min, mid, max, c);
	}
}

void mergeGen(Student *arr[], int min, int mid, int max, char c){
  int n1 = mid - min + 1, n2 = max - mid;
  Student *leftArray[n1], *rightArray[n2];


  for(int i = 0; i < n1; i++){
    leftArray[i] = arr[min + i];
  }

  for(int j = 0; j < n2; j++){
	rightArray[j] = arr[mid + 1 + j];
  }


  int i = 0, j = 0, k = min; 
  
  if (c == 't' || c == 'T'){   //sorts by type of student
    char domstr[] = "DomesticStudent";
    char intstr[] = "InternationalStudent";
  while (i < n1 && j < n2){
	const char *typ = typeid(leftArray[i]).name();
	const char *typ2 = typeid(rightArray[j]).name();
    if (!strcmp(typ, domstr)){    
      arr[k] = leftArray[i];
      i++;
    }
    else if(!strcmp(typ2, domstr)){ 
      arr[k] = rightArray[j];
      j++;
    }
    else{
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  } else if (c == 'r' || c == 'R'){ //sorts by research score
    while (i < n1 && j < n2){
      if (leftArray[i] -> getRScore() >= rightArray[j] -> getRScore()){
        arr[k] = leftArray[i];
        i++;
      }
      else{
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }

  }else if(c == 'c' || c == 'C'){   //sorts by cgpa
    while (i < n1 && j < n2){
      if (leftArray[i]->getCGPA() >= rightArray[j]->getCGPA()){   
        arr[k] = leftArray[i];
        i++;
      }
      else{                                     
        arr[k] = rightArray[j];
        j++;  
      }
    k++;
  }
  }else    
    exit(1);

  while (i <  n1){
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2){ 
    arr[k] = rightArray[j];
    j++;
    k++;
  }

}

void mergeGenCGPA2(Student *arr[], int min, int max){
  int i = min, j = min, activate = 0; 

  //iterates to find a chunk with the same values then sorts the chunk 
  while (j != max || i != max){   
    j = i;   
    while(j != max && compareResearchScore(*arr[j], *arr[j+1]) == 0){
      if (j == max + 1){  
        j = max;
      }else
        j++;
      activate = 1;
    }

    if (activate == 1){   
      mergeSortGen(arr, i, j, 'c');   
      i = j;      
      activate = 0;
    }else{
      i++;   
    }
  }
}


void mergeGen3(Student *arr[], int min, int max){
  int i = min, j = min, activate = 0;
  while (j != max || i != max){
    j = i;   
    while(j != max && compareCGPA(*arr[j], *arr[j+1]) == 0){
      if (j == max + 1){
        j = max;
      }else 
        j++;

      activate = 1; 
    }

    if (activate == 1){
	//sends to sort by type
      mergeSortGen(arr, i, j, 't');
      i = j;
      activate = 0; 
    }else{
      i++; 
    }
  }
}

//error catch
void Student::printInfo(){
    cout << "Error. Info not available for base type." << endl;
    return;
}
