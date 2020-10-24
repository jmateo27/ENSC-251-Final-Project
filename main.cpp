//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout

#include "student.hpp"

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main(){
  /////////////////////////////////////////MENU/////////////////////////////////////////////////////////////
    int sizeD;
    int sizeI;
    DomesticStudent *domstu;
    DomArray(domstu, sizeD);
  
    InternationalStudent *intstu;
    InterArray(intstu, sizeI);

    char intstate, domstate, state, dinp, iinp, inp;
    do{
      state = 'i';
      std::cout << "Welcome to the Graduate Student Admission System\n"
                << "Today we will be facilitating your admission inquiry needs\n"
                << "First please enter which applicant list of students to check \nInternational (I) or Domestic (D): \n";
      std::cin >> state;  // user inputs the list of students due
    switch(state){
    case 'I':
      do{
        std::cout << "You have entered the International Student Applicants list\n"
                  << "Please choose from the following options:\n"
                  << "Assort students by first name (A-Z), enter (F)\n"
                  << "Assort students by last name (A-Z), enter (L)\n"
                  << "Assort students by CGPA (4.3 to 0), enter (C)\n"
                  << "Assort students by Research Score (100 to 0), enter (R)\n"
                  << "Assort students starting from Research Score, then CGPA, then Country (E)\n";
                  
        std::cin >> intstate;
          switch(intstate){
          case 'F':
                  
            break;
          case 'L':
                  
            break;
          case 'C':
                  
            break;
          case 'R':
                  
            break;
          case 'E':
                  
            break;
          default :
            std::cout << "Invalid entry.\n";
          }

          std::cout << "Would you like to check another sorting method? (y/n)\n";
          std::cin>> iinp;
            
        } while (iinp != 'n' || iinp != 'N');
        break;
    case 'D':
        do{
          std::cout << "You have entered the Domestic Student Applicants list\n"
                  << "Please choose from the following options:\n"
                  << "Assort students by first name (A-Z), enter (F)\n"
                  << "Assort students by last name (A-Z), enter (L)\n"
                  << "Assort students by CGPA (4.3 to 0), enter (C)\n"
                  << "Assort students by Research Score (100 to 0), enter (R)\n"
                  << "Assort students starting from Research Score, then CGPA, then Province (E)\n";
          std::cin >> domstate;
          switch(domstate){
          case 'F':
                  
          break;
          case 'L':
                  
          break;
          case 'C':
                  
          break;
          case 'R':
                  
          break;
          case 'E':
                  
          break;
          default :
            std::cout << "Invalid entry.\n";
          }
        std::cout << "Would you like to check another sorting method? (y/n)\n";
        std::cin>> dinp;
                
        } while (dinp != 'n' || dinp != 'N');     
    
    default :
      std::cout << "Invalid entry.\n";
    }
    std::cout << "Would you like to check another list of students? (y/n) \n";
    std::cin >> inp;
  } while (inp != 'n' || inp != 'N');
//////////////////////////////ENDOFMENU//////////////////////////////////////////////////
  delete [] domstu;
  delete [] intstu;
  return 0;
}
