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
    int sizeI, sizeD, lo;
    std::string tem, intdec, domdec;

    DomesticStudent *domstu;
    domstu = DomArray(domstu, sizeD);
    DomesticStudent arrDom[sizeD];

    InternationalStudent *intstu;
    intstu = InterArray(intstu, sizeI);
    InternationalStudent arrInter[sizeI];
  
    for (int i = 0; i < sizeI; i++)
      arrInter[i] = *(intstu + i);

    for (int i = 0; i < sizeD; i++)
      arrDom[i] = *(domstu + i);

    char intstate, domstate, state, dinp, iinp, inp ;

    do{
      state = 'i';
      std::cout << "Welcome to the Graduate Student Admission System\n"
                << "Today we will be facilitating your admission inquiry needs\n"
                << "First please enter which applicant list of students to check \nInternational (I) or Domestic (D): \n";
      std::cin >> state;  // user inputs the list of students due
      if (state <= 'z' && state >= 'a')
        state -= 32;  
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
                  
        std::cin >> intdec;
        if (intdec == "f" || intdec == "F")
          intstate = 'F';
        else if(intdec == "l" || intdec == "L")
          intstate = 'L';
        else if(intdec == "c" || intdec == "C")
          intstate = 'C';
        else if(intdec == "r" || intdec == "R")
          intstate = 'R';
        else if(intdec == "e" || intdec == "E")
          intstate = 'E';
        else
          intstate = 'a';
        if (intstate <= 'z' && intstate >= 'a')
          intstate -= 32;
        switch(intstate){
          case 'F':
            mergeSortInt(arrInter, 0, sizeI - 1, intstate);
                  for(int i = 0; i < sizeI; i++){
                    *(intstu +i) = arrInter[i];
                    std::cout << *(intstu + i) << "\n";
                  }                  
            break;
          case 'L':
          mergeSortInt(arrInter, 0, sizeI - 1, intstate);
                  for(int i = 0; i < sizeI; i++){
                    *(intstu +i) = arrInter[i];
                    std::cout << *(intstu + i) << "\n";
                  }                  
            break;
          case 'C':
          mergeSortInt(arrInter, 0, sizeI - 1, intstate);
                  for(int i = 0; i < sizeI; i++){
                    *(intstu +i) = arrInter[i];
                    std::cout << *(intstu + i) << "\n";
                  }                  
            break;
          case 'R':
          mergeSortInt(arrInter, 0, sizeI - 1, intstate);
                  for(int i = 0; i < sizeI; i++){
                    *(intstu +i) = arrInter[i];
                    std::cout << *(intstu + i) << "\n";
                  }                  
            break;
          case 'E':
            dumpStu(arrInter, sizeI);
            mergeSortInt(arrInter, 0, sizeI - 1, 'R');
            mergeIntCGPA2(arrInter, 0, sizeI - 1);
            mergeInt3(arrInter, 0, sizeI - 1);
            for (int i = 0; i < sizeI; i++){
              *(intstu + i) = arrInter[i];
              std::cout << *(intstu + i) << std::endl;
            }      

           // std::cout << *(intstu+98); 
            break;

          default :
            std::cout << "Invalid entry.\n";
        }
          std::cout << "Would you like to check another sorting method? (y/n)\n";
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
    case 'D':{
        do{
          std::cout << "You have entered the Domestic Student Applicants list\n"
                  << "Please choose from the following options:\n"
                  << "Assort students by first name (A-Z), enter (F)\n"
                  << "Assort students by last name (A-Z), enter (L)\n"
                  << "Assort students by CGPA (4.3 to 0), enter (C)\n"
                  << "Assort students by Research Score (100 to 0), enter (R)\n"
                  << "Assort students starting from Research Score, then CGPA, then Province (E)\n";
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
          case 'F':
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";
            }                     
          break;
          case 'L':
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";     
            }             
          break;
          case 'C':
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";
            }                  
          break;
          case 'R':
            mergeSortDom(arrDom, 0, sizeD - 1, domstate);
            for(int i = 0; i < sizeD; i++){
              *(domstu +i) = arrDom[i];
              std::cout << *(domstu + i) << "\n"; 
            }                 
          break;
          case 'E':
            mergeSortDom(arrDom, 0, sizeD - 1, 'R');
            mergeDomCGPA2(arrDom, 0, sizeD - 1);
            mergeDom3(arrDom, 0, sizeD - 1);
            for(int i = 0; i < sizeD; i++){
              *(domstu + i) = arrDom[i];
              std::cout << *(domstu + i) << "\n";    
            }             
          break;
          default :
            std::cout << "Invalid entry.\n";
          }
        std::cout << "Would you like to check another sorting method? (y/n)\n";
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
    default :
      std::cout << "Invalid entry.\n";
    }
    std::cout << "Would you like to check another list of students? (y/n) \n";
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
//////////////////////////////ENDOFMENU//////////////////////////////////////////////////
  delete [] domstu;
  delete [] intstu;
  return 0;
}
