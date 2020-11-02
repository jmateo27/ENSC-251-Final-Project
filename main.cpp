//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout

#include "student.hpp"

int main(){
  /////////////////////////////////////////MENU/////////////////////////////////////////////////////////////
    int sizeI, sizeD, lo;
    std::string tem, intdec, domdec;
    char intstate, domstate, state, dinp, iinp, inp ;

    //initializing Domestic Students
    DomesticStudent *domstu;
    domstu = DomArray(domstu, sizeD);
    DomesticStudent arrDom[sizeD];

    //initializing international Students
    InternationalStudent *intstu;
    intstu = InterArray(intstu, sizeI);
    InternationalStudent arrInter[sizeI];
  
    //assigns students to arrays for future manipulation
    for (int i = 0; i < sizeI; i++)
      arrInter[i] = *(intstu + i);

    for (int i = 0; i < sizeD; i++)
      arrDom[i] = *(domstu + i);

////////////////////////////////////START_OF_MENU////////////////////////////////////////////
    do{
      state = 'i';
      std::cout << "Welcome to the Graduate Student Admission System\n"
                << "Today we will be facilitating your admission inquiry needs\n"
                << "First please enter which applicant list of students to check \nInternational (I) or Domestic (D): \n";
      std::cin >> state;  // user inputs the list of students due
      if (state <= 'z' && state >= 'a')
        state -= 32;  
    switch(state){
////////////////////////////////////INTERNATIONAL_STUDENTS////////////////////////////////////////////
    case 'I':
      do{
        std::cout << "You have entered the International Student Applicants list\n"
                  << "Please choose from the following options:\n"
                  << "Assort students by first name (A-Z), enter (F)\n"
                  << "Assort students by last name (A-Z), enter (L)\n"
                  << "Assort students by CGPA (4.3 to 0), enter (C)\n"
                  << "Assort students by Research Score (100 to 0), enter (R)\n"
                  << "Assort students starting from Research Score, then CGPA, then Country (E)\n";
        //takes decision to sort the students accordigly 
        std::cin >> intdec;
        if (intdec == "f" || intdec == "F")     //sort by first name, goes to case F
          intstate = 'F';
        else if(intdec == "l" || intdec == "L") //sort by last name, goes to case L 
          intstate = 'L';
        else if(intdec == "c" || intdec == "C") //sort by CGPA, goes to case C 
          intstate = 'C';
        else if(intdec == "r" || intdec == "R") //sort by Research Score, goes to case R
          intstate = 'R';
        else if(intdec == "e" || intdec == "E") //sort by Research Score, then CGPA, then Country , goes to case E
          intstate = 'E';
        else                                    //safety catch
          intstate = 'a';
        if (intstate <= 'z' && intstate >= 'a')
          intstate -= 32;
        switch(intstate){
          case 'F': //first name
            mergeSortInt(arrInter, 0, sizeI - 1, intstate);
              //reassigns pointers, and prints value stored at the address
              for(int i = 0; i < sizeI; i++){
                *(intstu +i) = arrInter[i];
                std::cout << *(intstu + i) << "\n";
              }                  
            break;
          case 'L': //Last name
            mergeSortInt(arrInter, 0, sizeI - 1, intstate);
            for(int i = 0; i < sizeI; i++){
              *(intstu +i) = arrInter[i];
              std::cout << *(intstu + i) << "\n";
            }      
            break;
          case 'C': //CGPA
            mergeSortInt(arrInter, 0, sizeI - 1, intstate);
            for(int i = 0; i < sizeI; i++){
              *(intstu +i) = arrInter[i];
              std::cout << *(intstu + i) << "\n";
            }                  
            break;
          case 'R': //Research Score
            mergeSortInt(arrInter, 0, sizeI - 1, intstate);
            for(int i = 0; i < sizeI; i++){
              *(intstu +i) = arrInter[i];
              std::cout << *(intstu + i) << "\n";
            }                  
            break;
          case 'E': //reserach, then cgpa, then country
            dumpStu(arrInter, sizeI);                       //removes the international Students that do not meet TOEL requirements
            mergeSortInt(arrInter, 0, sizeI - 1, 'R');      //sorts research score
            mergeIntCGPA2(arrInter, 0, sizeI - 1);          //sorts by CGPA
            mergeInt3(arrInter, 0, sizeI - 1);              //sorts by country 
            for (int i = 0; i < sizeI; i++){
              *(intstu + i) = arrInter[i];
              std::cout << *(intstu + i) << std::endl;
            }      
            break;

          default :
            std::cout << "Invalid entry.\n";
        }
          std::cout << "Would you like to check another sorting method? (y/n)\n";
          //checks to exit program
          do{
            std::cin >> tem;
            lo = 0;
            if(tem == "y" || tem == "Y"){
              iinp = 'y';
            }else if(tem == "n" || tem == "N"){
              iinp = 'n';
            }else{
              std::cout << "Invalid entry, please enter again(y/n)\n";
              lo = 10;
            }
          }while(lo == 10);
          }while (iinp == 'y' || iinp == 'Y');
      break;
////////////////////////////////////DOMESTIC_STUDENTS////////////////////////////////////////////
    case 'D':{
        do{
          std::cout << "You have entered the Domestic Student Applicants list\n"
                  << "Please choose from the following options:\n"
                  << "Assort students by first name (A-Z), enter (F)\n"
                  << "Assort students by last name (A-Z), enter (L)\n"
                  << "Assort students by CGPA (4.3 to 0), enter (C)\n"
                  << "Assort students by Research Score (100 to 0), enter (R)\n"
                  << "Assort students starting from Research Score, then CGPA, then Province (E)\n";
          //converts decision domdec to domstate, then takes the program to the appropriate state
          std::cin >> domdec;
          if (domdec == "f" || domdec == "F")
            domstate = 'F';
          else if(domdec == "l" || domdec == "L")
            domstate = 'L';
          else if(domdec == "c" || domdec == "C")
            domstate = 'C';
          else if(domdec == "r" || domdec == "R")
            domstate = 'R';
          else if(domdec == "e" || domdec == "E")
            domstate = 'E';
          else
          domstate = 'a';
          if (domstate <= 'z' && domstate >= 'a')
            domstate -= 32;
          switch(domstate){
          case 'F': //First Name
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            //reassigns pointers with the value stored in the array, then prints, the newly stored value
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";
            }                     
          break;
          case 'L': //Last Name
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";     
            }             
          break;
          case 'C': //CGPA
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";
            }                  
          break;
          case 'R': //research Score
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n"; 
            }                 
          break;
          case 'E': //research score, CGPA, then Province
            mergeSortDom(arrDom, 0, sizeD - 1, 'R');  //sorts by research score
            mergeDomCGPA2(arrDom, 0, sizeD - 1);      //sorts by CGPA
            mergeDom3(arrDom, 0, sizeD - 1);          //sorts by Province
            for(int i = 0; i < sizeD; i++){
              *(domstu + i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";    
            }             
          break;
          default :
            std::cout << "Invalid entry.\n";
          }
        std::cout << "Would you like to check another sorting method? (y/n)\n";
        //checks to exit program
        do{
          std::cin >> tem;
          lo = 0;
          if(tem == "y" || tem == "Y"){
            dinp = 'y';
          }else if(tem == "n" || tem == "N"){
            dinp = 'n';
          }else{
            std::cout << "Invalid entry, please enter again(y/n)\n";
            lo = 10;
          }
        }while(lo == 10);
        } while (dinp == 'y' || dinp == 'Y');     
        break;
    }
    default : //safety catch
      std::cout << "Invalid entry.\n";
    }
    std::cout << "Would you like to check another list of students? (y/n) \n";
    //checks to exit program
    do{
      std::cin >> tem;
       lo = 0;
    if(tem == "y" || tem == "Y"){
      inp = 'y';
    }
    else if(tem == "n" || tem == "N"){
      inp = 'n';
    }
    else{
      std::cout << "Invalid entry, please enter again(y/n)\n";
      lo = 10;
    }
    }while(lo == 10);

  } while (inp == 'y' || inp == 'Y');
//////////////////////////////END_OF_MENU//////////////////////////////////////////////////
  //deletes dynamic memory 
  delete [] domstu;
  delete [] intstu;
  return 0;
}
