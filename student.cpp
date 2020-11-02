//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

/**********************************Student class constructors****************************************/
Student::Student(std::string FName, std::string LName, float grade, int RScore, int id) //uses the colon operator to make the constructor more subtle
    : FirstName(FName), LastName(LName), ResearchScore(RScore), AppID(id){
      setCGPA(grade);
}

Student::Student(std::string FName, std::string LName, int id)
    : FirstName(FName), LastName(LName), AppID(id){
}

Student::Student() //default constructor
{}

/***************************************Set functions***********************************************/
void Student::setFirstName(std::string FName){  //sets the first name
    FirstName = FName;
}

void Student::setLastName(std::string LName){   //sets the last name
    LastName = LName;
}

void Student::setCGPA(float grade){   //sets the CGPA, makes sure that the CGPA is in the range, and makes it one decimal
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

void Student::setResearchScore(int RScore){   //sets the research score
    ResearchScore = RScore; 
}

void Student::setAppID(int id){   //sets the student id, no fixing statements as that's done elsewhere
    AppID = id; 
}

/*****************************************Get functions*********************************************/
//make sure to make the functions a const to be able to use in the overloaded exertion operator
std::string Student::getFirstName() const{    //gets the first name
    return FirstName; 
}

std::string Student::getLastName() const{   //gets the last name
    return LastName; 
}

float Student::getCGPA() const{    //gets the CGPA
    return CGPA; 
}

int Student::getRScore() const{   //gets the Research score
    return ResearchScore; 
}

int Student::getid() const{   //gets the student id
    return AppID;
}
/**************************Overloaded exertion operator for Student*******************************/
std::ostream& operator <<(std::ostream& outs, const Student& theStudent)
{//outputs the input student's information with the following format
    outs << "The student's name is: " << theStudent.getFirstName() << " " << theStudent.getLastName();
    outs << "\nThe CGPA is: " << theStudent.getCGPA();
    outs << "\nThe Reseach Score is: " << theStudent.getRScore();
    outs << "\nThe student ID is: 2020";
    formatID(outs, theStudent.getid()); //student id is just a 4 digit number and is concatenated with a "2020" to display whole student number
    outs << "\n"; //skip line for formatting
}


/****************************Compare functions for Student****************************************/
//All compare functions have the same trend of returning the following:
//If first is less than the second, output -1
//If first is greater than the second, output 1
//If the two are equal, output 0
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

/*************************************Domestic Student***************************************/

/*************************************Constructors*******************************************/
//Same processes as the parent class constructors, will not be repeated
DomesticStudent::DomesticStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Prov)
    : Student(FName, LName, grade, RScore, id), Province(Prov){//Takes info from student class
}

DomesticStudent::DomesticStudent(std::string FName, std::string LName, int id, std::string Prov):
    Student(FName, LName, id), Province(Prov){//Takes info from student class
}

DomesticStudent::DomesticStudent() //default constructor
{}


/*************************************Get functions*****************************************/ 
std::string DomesticStudent::getProvince() const{
    return Province;
}

void DomesticStudent::setProvince(std::string Prov){
  Province = Prov; 
}

/**************************************Set functions****************************************/
//only new information to be compared is the province
//same process as comparing first/last names, comments will not be repeated
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

/********************************Overloaded exertion operator for Domestic Student*********************************/
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

/*******************************International Student******************************************/

/*******************************Constructor functions***************************************/
//Same processes as the parent class, comments will not be repeated
InternationalStudent::InternationalStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Con, ToeflScore toefl)
    : Student(FName, LName, grade, RScore, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl) :
    Student(FName, LName, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent() //default constructor
{}

/********************************Compare functions******************************************/
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

/*******************************Get and set functions*******************************************/
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

/*******************************Overloaded exertion operator for International Student***********************************/
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

/***************************************Toefl Score*****************************************/

/*********************************Constructor functions*****************************************/
//Same processes as the Student class constructors, comments will not be repeated
ToeflScore::ToeflScore(int read, int listen, int speak, int write)
    : reading(read), listening(listen), speaking(speak), writing(write){
}

ToeflScore::ToeflScore() //default constructor
{}
   
/**********************************Set functions**********************************/
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

/**********************************Get functions******************************************/
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

/********************************Non-member functions******************************************/
//Used in the compare functions that compare strings
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

//makes sure the end of the student id has enough digits
void formatID(std::ostream& outs, const int num) {
    int i = 0;

    if (num - 10 < 0) //if one digit, follow with 3 zeros
        i = 3;
    else if (num - 100 < 0) //if two digits, follow with 2 zeros
        i = 2;
    else if (num - 1000 < 0) //if three digits, follow with 1 zero
        i = 1;
    else                  //if four digits, follow with no zeros
        i = 0;

    while (i != 0){     //displaying the output depending on how many digits
        outs << "0";
        i--;
    } 
    outs << num;      //output to outs, general output stream
}

/***************************Read the following file and place into allocated array***************************/

//This function is a copy of the given code from Dr. Fang, not much more comments are done
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

    int lines = 0; //count how many lines there are, initialize at zero
    while(getline(domesticFile, line)){
      lines++;      //final number should be how many students there are in the given file
    }
    domesticFile.close();     //close and reopen to use for reading the file
    ifstream domesticFile2("domestic-stu.txt"); 
    ptr = new DomesticStudent[lines];       //allocate just enough memory for the amount of students in the file
    size = lines;                           //size is updated by reference to be used for functions in the main

    getline(domesticFile2, line);           //reads the first line in the file which is the format of the values in the file
    //std::cout << lines << "\n" << line << "\n";
    

    while( getline(domesticFile2, line) ) {
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
    
    return ptr;    //return the pointer to then update the pointer in the main
}


//comments in the function are repetative of the previous function so will not be repeated
InternationalStudent* InterArray(InternationalStudent *ptr, int &size){
  ////////////////////////////////////////part 4/////////////////////////////////////////////////
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
    size = lines;

    getline(internationalFile2, line);

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

      thetoefl = new ToeflScore[1];   //allocate memory for the given student's Toefl score to then set their toefl score
      thetoefl -> setReading(reading);    //set the reading score of the given student
      thetoefl -> setListening(listening);    //set the listening score of the given student
      thetoefl -> setWriting(writing);    //set the writing score of the given student
      thetoefl -> setSpeaking(speaking);    //set the speaking score of the given student

      (ptr + stu_count - 1) -> setFirstName(firstName);
      (ptr + stu_count - 1) -> setLastName(lastName);
      (ptr + stu_count - 1) -> setCGPA(cgpa);
      (ptr + stu_count - 1) -> setResearchScore(researchScore);
      (ptr + stu_count - 1) -> setAppID(stu_count);
      (ptr + stu_count - 1) -> setCountry(country);
      (ptr + stu_count - 1) -> settoefl(*(thetoefl));
      delete [] thetoefl;   //delete the allocated memory of the given student's toefl score
                            //as it has been set in the student already, not needed anymore
      stu_count++;
    }
 
    //close your file
    internationalFile2.close();
    return ptr;
}

/****************************Sorting functions************************************/
//Merge Sort functions were the only sorting algorithm used in this project//
//////////////////////////////////INTERNATIONAL/////////////////////////////////////

void mergeInt(InternationalStudent *arr, int min, int mid, int max, char c)
{
  int n1 = mid - min + 1, n2 = max - mid;   //find the sizes of the arrays to be set
                                            //find the first index of each array in the input array
  //initialize the arrays to be assessed
  InternationalStudent leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++) //copying the data in the input array into the initialized arrays
    leftArray[i] = arr[min + i];
  for(int j = 0; j < n2; j++)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = min; 
  
  //This portion of the function depends on the input char, to pick which parameter to sort by
  if (c == 'f' || c == 'F'){    /****************Sort by first name*****************/
  while (i < n1 && j < n2){
    if (compareFirstName(leftArray[i], rightArray[j]) == 1){    //greater goes in first
      arr[k] = leftArray[i];
      i++;
    }
    else if(compareFirstName(leftArray[i], rightArray[j]) == -1){   //lesser goes in after
      arr[k] = rightArray[j];
      j++;
    }else if (compareFirstName(leftArray[i], rightArray[j]) == 0){    //if equal, doesn't matter, but chose go after
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  }else if(c == 'l' || c == 'L'){   /****************Sort by last name*****************/
      while (i < n1 && j < n2){
    if (compareLastName(leftArray[i], rightArray[j]) == 1){    //greater goes in first
      arr[k] = leftArray[i];
      i++;
    }
    else if(compareLastName(leftArray[i], rightArray[j]) == -1){   //lesser goes in after
      arr[k] = rightArray[j];
      j++;
    }else if (compareLastName(leftArray[i], rightArray[j]) == 0){    //if equal, doesn't matter, but chose go after
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }
  }else if(c == 'c' || c == 'C'){   /****************Sort by CGPA*****************/
    while (i < n1 && j < n2){
      if (leftArray[i].getCGPA() >= rightArray[j].getCGPA()){   //greater or equal goes in first
        arr[k] = leftArray[i];
        i++;
      }
      else{                                                     //else means lesser, goes in after
        arr[k] = rightArray[j];
        j++;  
      }
    k++;
  }
  } else if (c == 'r' || c == 'R'){   /****************Sort by Research score*****************/
    while (i < n1 && j < n2){
      if (leftArray[i].getRScore() >= rightArray[j].getRScore()){
        arr[k] = leftArray[i];
        i++;
      }
      else{                                                     //else means lesser, goes in after
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }

  }else if (c == 'k' || c == 'K'){    /****************Sort by Country*****************/
    while (i < n1 && j < n2){
      if (compareCountry(leftArray[i], rightArray[j]) == 1){    //greater goes in first
        arr[k] = leftArray[i];
        i++;
      }
      else if(compareCountry(leftArray[i], rightArray[j]) == -1){   //lesser goes in after
        arr[k] = rightArray[j];
        j++;
      }else if (compareCountry(leftArray[i], rightArray[j]) == 0){    //if equal, doesn't matter, but chose go after
        arr[k] = rightArray[j];
        j++;
      }
      k++;
    }
  }else    //should never be here, catch else statement
    exit(1);

  while (i <  n1){ //starting to merge the left array into the left portion of the input array
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2){ //starting to merge the right array into the right portion of the input array
    arr[k] = rightArray[j];
    j++;
    k++;
  }

}

//This is the function that is called in the main
//determines when to stop splitting the input array, stopping case
void mergeSortInt(InternationalStudent *arr, int min, int max, char c){
  if (min < max){   //should stop when min = max, meaning that the array is now size 1, and is ok to be merged now
    int mid = min + (max - min) / 2;    //calculation for the middle index of the given array
    mergeSortInt(arr, min, mid, c);     //merge sort the left side of the input array
    mergeSortInt(arr, mid + 1, max, c);   //merge sort the right side of the input array
    mergeInt(arr, min, mid, max, c);    //recursion
  }
}

//This function is for part 6
//Precondition: The given array must be sorted by Research score by the time this function is called
void mergeIntCGPA2(InternationalStudent *arr, int min, int max){
  int i = min, j = min, activate = 0;  //initialize the parameters to be used later
  while (j != max || i != max){   //stop when past the last index of the input array
    j = i;   //update j as i is mostly updated
    while(j != max && compareResearchScore(arr[j], arr[j+1]) == 0){ 
    //this part calculates where the mini array of students have the same research score,
    //beginning and ending index to use later when wanting to sort the mini array by CGPA 
      if (j == max + 1){  //edge case when j is past the max index, so it does not give segmentation fault.
        j = max;
      }else //should go into this else most of the time
        j++;

      activate = 1; //tells the next if to 'activate'
    }

    if (activate == 1){   //ready to sort the section of the input array by CGPA with the current i and j indices
      mergeSortInt(arr, i, j, 'C');   //call the sorting function with input char 'C'
      i = j;      //update i to where j is to continue to the rest of the input array, to make sure
                  //all groups of students with same research score can be sorted by CGPA
      activate = 0;    //reset the activate variable to 0 to be ready for another iteration
    }else{
      i++;    //if activate = 0 then continue on finding student with same research score
    }
  }
}

//Used for part 6
//Precondition: mergeIntCGPA2 must be called prior, as the input array must be sorted by research score
//THEN by CGPA by this time, this function is to catch the students with same CGPA
//This function has the same process as the last function so comments won't be repeated
//Only difference is that sections are now being sorted by Country
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


//This function is also used for step 6, to get rid of international students with a toefl score component less than
//20 or overall toefl score less then 93
void dumpStu(InternationalStudent *arr, int &size){
  ToeflScore empty(0,0,0,0);    //initalize toefl score of dummy international students to fill the rest of the indices of the array
  InternationalStudent fake("", "", 0,0,0,"", empty);   //construct the filler international 'student'

  int newSize = 0; //intialize the new size of the array at 0

  for(int i = 0; i < size; i++){  //this section is to count how big the new array of students will be
    ToeflScore tempToefl = arr[i].getToefl();
    if (tempToefl.getWriting() < 20 || tempToefl.getReading() < 20 || 
        tempToefl.getListening() < 20 || tempToefl.getSpeaking() < 20 || tempToefl.getTOEFL() < 93){
      //if in here, the given student is ignored
      continue; 
    }else 
      newSize++; //size of the new array is incremented when it is a valid student
  }

  InternationalStudent copy[newSize]; //intialize the new array of students with size newSize calculated prior
  for(int i = 0, j = 0; i < size; i++){  
    ToeflScore tempToefl = arr[i].getToefl();  //every iteration a new international student's toefl score is taken
    if (tempToefl.getWriting() < 20 || tempToefl.getReading() < 20 || 
        tempToefl.getListening() < 20 || tempToefl.getSpeaking() < 20 || tempToefl.getTOEFL() < 93){
      //if in here, the given student does not have a sufficient toefl score and is dropped
      continue; 
    }else 
      copy[j] = arr[i];  //the given student is copied into the new array
      j++;    
  }
  
  for (int i = 0; i < newSize; i++){    //the new array is copied into the input array to update it with the good students
    arr[i] = copy[i];
  }

  for(int i = newSize; i < size; i++){    //the extra space in the array is filled with the filler students
    arr[i] = fake; 
  }

  size = newSize;   //the size of the array is updated by reference to help the functions in the main to
                    //prevent outputting the filler students when using the overloaded exertion operator
                    //The overloaded exertion operator is used with a for loop stopping at the size of the array
}


//////////////////////////////////DOMESTIC/////////////////////////////////////


//The functions below are very similar to its international student counterpart so some comments will not be repeated
//Differences in the two will be pointed out

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

  }else if (c == 'p' || c == 'P'){/*Sort by province and not by country, one difference between the counterpart functions*/
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
    exit (1);   //should never be here, catch else statement

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


//This is the merge sort function to be called in the main, will recur
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

//This function is used for part 6
//Precondition: mergeSortDom must have been called prior to calling this function
//purpose is to sort the sections of the array by province other then country, other difference
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