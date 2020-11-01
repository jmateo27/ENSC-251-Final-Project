//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

//constructs
Student::Student(std::string FName, std::string LName, float grade, int RScore, int id)
    : FirstName(FName), LastName(LName), ResearchScore(RScore), AppID(id){
      setCGPA(grade);
}

Student::Student(std::string FName, std::string LName, int id)
    : FirstName(FName), LastName(LName), AppID(id){
}

Student::Student() //default constructor
{}

//set functions 
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
    ResearchScore = RScore; 
}

void Student::setAppID(int id){
    AppID = id; 
}

//getfunctions
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

std::ostream& operator <<(std::ostream& outs, const Student& theStudent)
{
    outs << "The student's name is: " << theStudent.getFirstName() << " " << theStudent.getLastName();
    outs << "\nThe CGPA is: " << theStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theStudent.getid());
    outs << "\n";
}


//compare functions
int compareResearchScore(Student student1, Student student2){
    int rscore1 = student1.getRScore(); 
    int rscore2 = student2.getRScore(); 

    if (rscore1 == rscore2)
        return 0;
    else if (rscore1 > rscore2)
        return 1;
    else // rscore1 < rscore2
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

DomesticStudent::DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov)
    : Student(FName, LName, grade, RScore, id), Province(Prov){//Takes info from student class
}

DomesticStudent::DomesticStudent(std::string FName, std::string LName, int id, std::string Prov):
    Student(FName, LName, id), Province(Prov){//Takes info from student class
}

DomesticStudent::DomesticStudent() //default constructor
{}

std::string DomesticStudent::getProvince() const{
    return Province;
}

void DomesticStudent::setProvince(std::string Prov){
  Province = Prov; 
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
    outs << "\nThe CGPA is: " << theDomStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theDomStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theDomStudent.getid());
    outs << "\n";
}

InternationalStudent::InternationalStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Con, ToeflScore toefl)
    : Student(FName, LName, grade, RScore, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl) :
    Student(FName, LName, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent() //default constructor
{}

int compareCountry(InternationalStudent student1, InternationalStudent student2){
    std::string c1 = student1.getCountry();
    std::string c2 = student2.getCountry();
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
    
std::string InternationalStudent::getCountry() const{
    return Country;
}

ToeflScore InternationalStudent::getToefl() const{
    return theirscore;
}

void InternationalStudent::settoefl(ToeflScore thescore){
    theirscore = thescore;
}

void InternationalStudent::setCountry(std::string Con){
    Country = Con;
}


std::ostream& operator <<(std::ostream& outs, const InternationalStudent& theIntStudent)
{
    ToeflScore thescore = theIntStudent.getToefl();
    outs << "The international student's name is: " << theIntStudent.getFirstName() << " " << theIntStudent.getLastName();
    outs << "\nThey are from: " << theIntStudent.getCountry();
    outs << "\nThe CGPA is: " << theIntStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theIntStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theIntStudent.getid());
    outs << "\nThe student TOEFL score is: \nReading: " << thescore.getReading() << "/30" << "\nListening: " << thescore.getListening();
    outs << "/30" << "\nSpeaking: " << thescore.getSpeaking() << "/30" << "\nWriting: " << thescore.getWriting() << "/30\n";
  
}


ToeflScore::ToeflScore(int read, int listen, int speak, int write)
    : reading(read), listening(listen), speaking(speak), writing(write){
}

ToeflScore::ToeflScore() //default constructor
{}
   
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

int ToeflScore::getReading() const{
     return reading;
}

int ToeflScore::getListening() const{
    return listening;
}

int ToeflScore::getSpeaking() const{
    return speaking;
}

int ToeflScore::getWriting() const{
    return writing;
}

//Total score
int ToeflScore::getTOEFL() const{
    return (reading + listening + speaking + writing);
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

    if (num - 10 < 0)
        i = 3;
    else if (num - 100 < 0)
        i = 2;
    else if (num - 1000 < 0)
        i = 1;
    else
        i = 0;

    while (i != 0){
        outs << "0";
        i--;
    } 
    outs << num;
}

char giveback(std::string student, int n ){
  return student[n];
}

DomesticStudent* DomArray(DomesticStudent *ptr, int &size){
  ////////////////////////////////////////part 4/////////////////////////////////////////////////
    //Read the domestic-stu.txt file and exit if failed
    std::string line;
    char temp; 
    ifstream domesticFile("domestic-stu.txt");
    
    if(!domesticFile.is_open()) {
      std::cout << "Unable to open file domestic-stu.txt" << std::endl;
      return NULL;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);
  //  cout << "File format: " << line << endl;

    /*Keep reading the rest of the lines in domestic-stu.txt.
    *In the example code here, I will read each data separated
    *by a comma, and then print it out to the screen.
    *In your lab assignment 1, you should use these read data
    *to initialize your DomesticStudent object. Then you can
    *use get and set functions to manipulate your object, and
    *print the object content to the screen
    */
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
    //std::cout << lines << "\n" << line << "\n";
    

    while( getline(domesticFile2, line) ) {
    // arrDom = new DomesticStudent[1];
      /* process each line, get each field separated by a comma.
      *We use istringstream to handle it.
      *Note in this example code here, we assume the file format
      *is perfect and do NOT handle error cases. We will leave the
      *error and exception handling of file format to Lab Assignment 4
      */ 
      istringstream ss(line);

      std::string firstName, lastName, province, s_cgpa, s_researchScore;
      float cgpa;
      int researchScore;

      //get firstName separated by comma
      getline(ss, firstName, ',');

      //get lastName separated by comma
      getline(ss, lastName, ',');

      //get province separated by comma
      getline(ss, province, ',');

      //get cpga separated by comma, and convert string to float
      getline(ss, s_cgpa, ',');
      cgpa = atof(s_cgpa.c_str());
      
      //get researchScore separated by comma, and convert it to int
      getline(ss, s_researchScore, ',');
      researchScore = atoi(s_researchScore.c_str());

      //print the student info to the screen
/*       cout << "Domestic student " << stu_count << " " << firstName << " " 
    << lastName << " from " << province << " province has cgpa of "
    << cgpa << ", and research score of " << researchScore << endl; */
    

  //DomesticStudent *temp = ptr + stu_count - 1;

    (ptr + stu_count - 1) ->setFirstName(firstName);
    (ptr + stu_count - 1)->setLastName(lastName);
    (ptr + stu_count - 1)->setCGPA(cgpa);
    (ptr + stu_count - 1)->setResearchScore(researchScore);
    (ptr + stu_count - 1)->setAppID(stu_count);
    (ptr + stu_count - 1)->setProvince(province);

    //std::cout << *(ptr + stu_count - 1) << std::endl;

    stu_count++;
    
    }
 
    //close your file
    domesticFile2.close();
    return ptr;
}

InternationalStudent* InterArray(InternationalStudent *ptr, int &size){
  ////////////////////////////////////////part 4/////////////////////////////////////////////////
    //Read the domestic-stu.txt file and exit if failed
    std::string line;
    char temp; 
    ToeflScore *thetoefl;
    ifstream internationalFile("international-stu.txt");
    
    if(!internationalFile.is_open()) {
      std::cout << "Unable to open file international-stu.txt" << std::endl;
      return NULL;
    }

    getline(internationalFile, line);

    int stu_count = 1;

    int lines = 0; 
    while(getline(internationalFile, line)){
      lines++; 
    }
    internationalFile.close();
    ifstream internationalFile2("international-stu.txt"); 
    ptr = new InternationalStudent[lines];
    size = lines; //might not work :)

    getline(internationalFile2, line);
    //std::cout << lines << "\n" << line << "\n";
    

    while( getline(internationalFile2, line) ) {

      istringstream ss(line);

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

      getline(ss, s_speaking, ',');
      speaking = atoi(s_speaking.c_str());

      getline(ss, s_writing, ',');
      writing = atoi(s_writing.c_str());

      thetoefl = new ToeflScore[1];
      thetoefl -> setReading(reading);
      thetoefl -> setListening(listening);
      thetoefl -> setWriting(writing);
      thetoefl -> setSpeaking(speaking);

      //InternationalStudent *temp = ptr + stu_count - 1;

      (ptr + stu_count - 1) -> setFirstName(firstName);
      (ptr + stu_count - 1) -> setLastName(lastName);
      (ptr + stu_count - 1) -> setCGPA(cgpa);
      (ptr + stu_count - 1) -> setResearchScore(researchScore);
      (ptr + stu_count - 1) -> setAppID(stu_count);
      (ptr + stu_count - 1) -> setCountry(country);
      (ptr + stu_count - 1) -> settoefl(*(thetoefl));
      delete [] thetoefl;

      //std::cout << *(ptr + stu_count - 1) << std::endl;

      stu_count++;
    
    }
 
    //close your file
    internationalFile2.close();
    return ptr;
}

void getDomArray(DomesticStudent *ptr, int size){
  for (int i = 0; i < size; i++)
    std::cout << *(ptr + i) << "\n";
}
void getInterArray(InternationalStudent *ptr, int size){
    for (int i = 0; i < size; i++)
    std::cout << *(ptr + i) << "\n";
}

//////////////////////////////////INTERNATIONAL/////////////////////////////////////

void mergeInt(InternationalStudent *arr, int min, int mid, int max, char c)
{
  int n1 = mid - min + 1, n2 = max - mid;
  InternationalStudent leftArray[n1], rightArray[n2];

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
    //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
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
      //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
      k++;
    }

  }else if (c == 'k' || c == 'K'){
    while (i < n1 && j < n2){
      if (compareCountry(leftArray[i], rightArray[j]) == 1){
        arr[k] = leftArray[i];
        i++;
      }
      else if(compareCountry(leftArray[i], rightArray[j]) == -1){
        arr[k] = rightArray[j];
        j++;
      }else if (compareCountry(leftArray[i], rightArray[j]) == 0){
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

void mergeIntCGPA(InternationalStudent *arr, int min, int mid, int max, char c)
{
  int n1 = mid - min + 1, n2 = max - mid;

  InternationalStudent leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++)
    leftArray[i] = arr[min + i];
  for(int j = 0; j < n2; j++)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = min; 
    
  while (i < n1 && j < n2){
    if (leftArray[i].getCGPA() >= rightArray[j].getCGPA()){
      arr[k] = leftArray[i];
      i++;
    }
    else{ //if (leftArray[i].getRScore() < rightArray[j].getRScore()){
      arr[k] = rightArray[j];
      j++;
    }
    //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
    k++;
  }
  while (i < n1){
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

void mergeSortInt(InternationalStudent *arr, int min, int max, char c){
  if (min < max){
    int mid = min + (max - min) / 2;
    mergeSortInt(arr, min, mid, c);
    mergeSortInt(arr, mid + 1, max, c);
    mergeInt(arr, min, mid, max, c);
  }
}

void mergeIntCGPA2(InternationalStudent *arr, int min, int max){
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
      mergeSortInt(arr, i, j, 'C');
      i = j;
      activate = 0;    
    }else{
      i++; 
    }
  }
}

void mergeInt3(InternationalStudent *arr, int min, int max){
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
      mergeSortInt(arr, i, j, 'K'); //country merge
      i = j;
      activate = 0;    
    }else{
      i++; 
    }

  }
}

void dumpStu(InternationalStudent *arr, int &size){
  ToeflScore empty(0,0,0,0);
  InternationalStudent fake("", "", 0,0,0,"", empty);

  int newSize = 0; 
  for(int i = 0; i < size; i++){  
    ToeflScore tempToefl = arr[i].getToefl();
    if (tempToefl.getWriting() < 20 || tempToefl.getReading() < 20 || 
        tempToefl.getListening() < 20 || tempToefl.getSpeaking() < 20 || tempToefl.getTOEFL() < 93){
      continue; 
    }else 
      newSize++; 
  }

  InternationalStudent copy[newSize];
  for(int i = 0, j = 0; i < size; i++){  
    ToeflScore tempToefl = arr[i].getToefl();
    if (tempToefl.getWriting() < 20 || tempToefl.getReading() < 20 || 
        tempToefl.getListening() < 20 || tempToefl.getSpeaking() < 20 || tempToefl.getTOEFL() < 93){
      continue; 
    }else 
      copy[j] = arr[i];  
      j++; 
  }
  
  for (int i = 0; i < newSize; i++){
    arr[i] = copy[i];
  }

  for(int i = newSize; i < size; i++){
    arr[i] = fake; 
  }
  size = newSize;
}


//////////////////////////////////DOMESTIC/////////////////////////////////////

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
    //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
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
      //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
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

void mergeDomCGPA(DomesticStudent *arr, int min, int mid, int max, char c)
{
  int n1 = mid - min + 1, n2 = max - mid;

  DomesticStudent leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++)
    leftArray[i] = arr[min + i];
  for(int j = 0; j < n2; j++)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = min; 
    
  while (i < n1 && j < n2){
    if (leftArray[i].getCGPA() >= rightArray[j].getCGPA()){
      arr[k] = leftArray[i];
      i++;
    }
    else{ //if (leftArray[i].getRScore() < rightArray[j].getRScore()){
      arr[k] = rightArray[j];
      j++;
    }
    //extend else so that we use mergeCGPA recursively to update left/rightArray then put into arr[k].
    k++;
  }
  while (i < n1){
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
      mergeSortDom(arr, i, j, 'P'); //country merge
      i = j;
      activate = 0;    
    }else{
      i++; 
    }

  }
}