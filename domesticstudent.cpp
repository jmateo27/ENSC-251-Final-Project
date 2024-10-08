#include "domesticstudent.hpp"
#include <iostream>
#include <iomanip>

//Constructor functions
DomesticStudent::DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov)
    : Student(FName, LName, grade, RScore, id){
    setProvince(Prov);
}

DomesticStudent::DomesticStudent(std::string FName, std::string LName, int id, std::string Prov):
    Student(FName, LName, id){
    setProvince(Prov);
}

DomesticStudent::DomesticStudent(DomesticStudent &stud) :
    Student(stud.getFirstName(), stud.getLastName(), stud.getCGPA(), stud.getRScore(), stud.getid()), next(NULL){
}

//setting all values to be empty or null
DomesticStudent::DomesticStudent() : Student("", "", 0, 0, 0), Province(""), next(nullptr) {
}


DomesticStudent& DomesticStudent::operator =(const DomesticStudent& r){
	FirstName = r.getFirstName();
	LastName = r.getLastName();
	Province = r.getProvince();
	ResearchScore = r.getRScore();
	AppID = r.getid(); 
	CGPA = r.getCGPA(); 
    return *this;
}

Student* DomesticStudent::copystu(){
	try{
		Student* toreturn;
		DomesticStudent* copy = new DomesticStudent;
		copy -> setFirstName(FirstName);
		copy -> setLastName(LastName);
		copy -> setCGPA(CGPA);
		copy -> setResearchScore(ResearchScore);
		copy -> setProvince(Province);
		copy -> setAppID(AppID);
		copy -> next = NULL;
		toreturn = copy;
		return toreturn;
	}
	catch(bad_alloc){
		cout << "Bad Allocation... exiting\n";
		cout << "\033[0m";
		exit(1);
    }
}

std::string DomesticStudent::getProvince() const{
    return Province;
}

void DomesticStudent::setProvince(string Prov){
    const char* provinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON",
                              "MB","SK", "AB", "BC", "YT", "NT", "NU"};
    for (const char* i:provinces)
        if (!strcmp(Prov.c_str(), i)){
            Province = Prov;
            return;
        }
    cout <<"\nFor " << getFirstName() << " " << getLastName() << "\n";
    cout << Prov << " is not a valid province, exiting...\n";
    cout <<  "\033[0m";
    exit(1);
}


int compareProvince(DomesticStudent student1, DomesticStudent student2){
    std::string c1 = student1.getProvince();
    std::string c2 = student2.getProvince();
    int len = 0;
    if (c1.length() >= c2.length())
        len = c1.length();
    else
        len = c2.length();

    for (int i = 0; i < len; i++){
        if (upper2lowercase(c1[i]) < upper2lowercase(c2[i])){
            return 1;
        }
        else if (upper2lowercase(c1[i]) > upper2lowercase(c2[i])){
            return -1;
        }
    }
    return 0;
}


std::ostream& operator <<(std::ostream& outs, const DomesticStudent& theDomStudent)
{
    outs << "The domestic student's name is: " << theDomStudent.getFirstName() << " " << theDomStudent.getLastName();
    outs << "\nThe student is from: " << theDomStudent.getProvince();
    outs << "\nThe CGPA is: " << fixed << setprecision(1) << theDomStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theDomStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theDomStudent.getid());
    outs << "\n";
    return outs;
}

DomesticStudent* DomArray(DomesticStudent *ptr, int &size){
try{
    std::string line;
    char temp; 
    ifstream domesticFile("domestic-stu.txt");
    
    if(!domesticFile.is_open()) {
      std::cout << "Unable to open file domestic-stu.txt" << std::endl;
      return NULL;
    }

    getline(domesticFile, line);

    int stu_count = 1;

    int lines = 0; 
    while(getline(domesticFile, line)){
      lines++;      
    }
    domesticFile.close(); 
    ifstream domesticFile2("domestic-stu.txt"); 
    ptr = new DomesticStudent[lines];       
    size = lines;                           

    getline(domesticFile2, line);          
    

    while( getline(domesticFile2, line) ) {
      istringstream ss(line);

      std::string firstName, lastName, province, s_cgpa, s_researchScore;
      float cgpa;
      int researchScore;

  
      getline(ss, firstName, ',');


      getline(ss, lastName, ',');

      //get province separated by comma
      getline(ss, province, ',');

      
      getline(ss, s_cgpa, ',');
      cgpa = atof(s_cgpa.c_str());
      
      //get researchScore separated by comma, and convert it to int
      getline(ss, s_researchScore, ',');
      researchScore = atoi(s_researchScore.c_str());

      (ptr + stu_count - 1) -> setFirstName(firstName);    //set the first name of the given student
      (ptr + stu_count - 1) -> setLastName(lastName);     //set the last name of the given student
      (ptr + stu_count - 1) -> setCGPA(cgpa);   //set the CGPA of the given student
      (ptr + stu_count - 1) -> setResearchScore(researchScore);   //set the research score of the given student 
      (ptr + stu_count - 1) -> setAppID(stu_count);   //set the student ID of the given student
      (ptr + stu_count - 1) -> setProvince(province);   //set the province of the given student

      stu_count++;      //increment by one to keep count of where to allocate the next student
    }
 
    //close your file
    domesticFile2.close();
    
    return ptr;
	}
	catch(bad_alloc){
		cout << "Bad Allocation... exiting\n";
		cout << "\033[0m";
		exit(1);
    }
}

void mergeDom(DomesticStudent *arr, int min, int mid, int max, char c)
{
  int n1 = mid - min + 1, n2 = max - mid;
  DomesticStudent leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++)
    leftArray[i] = arr[min + i];
  for(int j = 0; j < n2; j++)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = min; 
  if (c == 'f' || c == 'F'){
  while (i < n1 && j < n2){
    if (compareFirstName(leftArray[i], rightArray[j]) == 1){
      arr[k] = leftArray[i];
      i++;
    }
    else if(compareFirstName(leftArray[i], rightArray[j]) == -1){
      arr[k] = rightArray[j];
      j++;
    }else if (compareFirstName(leftArray[i], rightArray[j]) == 0){
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  }else if(c == 'l' || c == 'L'){
      while (i < n1 && j < n2){
    if (compareLastName(leftArray[i], rightArray[j]) == 1){
      arr[k] = leftArray[i];
      i++;
    }
    else if(compareLastName(leftArray[i], rightArray[j]) == -1){
      arr[k] = rightArray[j];
      j++;
    }else if (compareLastName(leftArray[i], rightArray[j]) == 0){
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  }else if(c == 'c' || c == 'C'){
    while (i < n1 && j < n2){
      if (leftArray[i].getCGPA() >= rightArray[j].getCGPA()){
        arr[k] = leftArray[i];
        i++;
      }
      else{
        arr[k] = rightArray[j];
        j++;  
      }
    k++;
  }
  } else if (c == 'r' || c == 'R'){
    while (i < n1 && j < n2){
      if (leftArray[i].getRScore() >= rightArray[j].getRScore()){
        arr[k] = leftArray[i];
        i++;
      }
      else{
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }

  }else if (c == 'p' || c == 'P'){
    while (i < n1 && j < n2){
      if (compareProvince(leftArray[i], rightArray[j]) == 1){
        arr[k] = leftArray[i];
        i++;
      }
      else if(compareProvince(leftArray[i], rightArray[j]) == -1){
        arr[k] = rightArray[j];
        j++;
      }else if (compareProvince(leftArray[i], rightArray[j]) == 0){
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }
  }else
    exit (1);   
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

void DomesticStudent::printInfo(){
    string fullname = getFirstName() + " " + getLastName();
    cout << "\x1b[36m" << left << setw(25) << fullname << "   2020"; 
    formatID(cout, getid());
    cout << "     " << fixed << setprecision(1) << getCGPA() << "        " << setw(3) << getRScore() << "       " 
		 << setw(12) <<   getProvince() << "\033[0m";// << "     ";
	return; 
}


void mergeSortDom(DomesticStudent *arr, int min, int max, char c){
  if (min < max){
    int mid = min + (max - min) / 2;
    mergeSortDom(arr, min, mid, c);
    mergeSortDom(arr, mid + 1, max, c);
    mergeDom(arr, min, mid, max, c);
  }
}

void mergeDomCGPA2(DomesticStudent *arr, int min, int max){
  int i = min, j = min, activate = 0; 
  while (j != max || i != max){
    j = i;   
    while(j != max && compareResearchScore(arr[j], arr[j+1]) == 0){
      
      if (j == max + 1){
        j = max;
      }else 
        j++;

      activate = 1; 
    }

    if (activate == 1){
      mergeSortDom(arr, i, j, 'C');
      i = j;
      activate = 0;    
    }else{
      i++; 
    }

  }
}

void mergeDom3(DomesticStudent *arr, int min, int max){
  int i = min, j = min, activate = 0; 
  while (j != max || i != max){
    j = i;   
    while(j != max && compareCGPA(arr[j], arr[j+1]) == 0){
      if (j == max + 1){
        j = max;
      }else 
        j++;

      activate = 1; 
    }

    if (activate == 1){
      mergeSortDom(arr, i, j, 'P'); 
      i = j;
      activate = 0;    
    }else{
      i++; 
    }

  }
}
