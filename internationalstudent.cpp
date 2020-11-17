//student.cpp to implement your classes
#include "internationalstudent.hpp"
#include "ToeflScore.hpp"
#include <iostream>

InternationalStudent::InternationalStudent(std::string FName, std::string LName, float grade, int RScore, int id, std::string Con, ToeflScore toefl)
    : Student(FName, LName, grade, RScore, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent(std::string FName, std::string LName, int id, std::string Con, ToeflScore toefl) :
    Student(FName, LName, id), Country(Con), theirscore(toefl){
}

InternationalStudent::InternationalStudent() 
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
    return outs;
}


InternationalStudent* InterArray(InternationalStudent *ptr, int &size){
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

      thetoefl = new ToeflScore[1];  
      thetoefl -> setReading(reading);
      thetoefl -> setListening(listening); 
      thetoefl -> setWriting(writing); 
      thetoefl -> setSpeaking(speaking); 

      (ptr + stu_count - 1) -> setFirstName(firstName);
      (ptr + stu_count - 1) -> setLastName(lastName);
      (ptr + stu_count - 1) -> setCGPA(cgpa);
      (ptr + stu_count - 1) -> setResearchScore(researchScore);
      (ptr + stu_count - 1) -> setAppID(stu_count);
      (ptr + stu_count - 1) -> setCountry(country);
      (ptr + stu_count - 1) -> settoefl(*(thetoefl));
      delete [] thetoefl; 
      stu_count++;
    }
 
    //close your file
    internationalFile2.close();
    return ptr;
}


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
      mergeSortInt(arr, i, j, 'K'); 
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