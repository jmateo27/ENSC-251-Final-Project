//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout

//#include "student.hpp"
#include "domesticstudent.hpp"
#include "internationalstudent.hpp"
#include "LinkedList.hpp"
int main(){
    DomLinkedList theList;
    DomesticStudent* aStu = new DomesticStudent;
    string line;
    char temp; 
    ifstream domesticFile("domestic-stu.txt");
    
    if(!domesticFile.is_open()) {
        std::cout << "Unable to open file domestic-stu.txt" << std::endl;
        exit(1);
    }                      

    getline(domesticFile, line);          
    
    int stu_count = 0;
    while( getline(domesticFile, line) ) {
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

      aStu -> setFirstName(firstName);    //set the first name of the given student
      aStu -> setLastName(lastName);     //set the last name of the given student
      aStu -> setCGPA(cgpa);   //set the CGPA of the given student
      aStu -> setResearchScore(researchScore);   //set the research score of the given student 
      aStu -> setAppID(stu_count);   //set the student ID of the given student
      aStu -> setProvince(province);   //set the province of the given student
      theList.addDomStudent(*aStu);

      stu_count++;      //increment by one to keep count of where to allocate the next student
      delete aStu;
    }
    //close your file
    domesticFile.close();
    theList.printList();
  return 0;
}

