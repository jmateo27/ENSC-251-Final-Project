/*****************************************************************/
//Final Project of ENSC 251
//This main file includes the Unit Test, an interactive section
//and even an error checking portion that displays
//the robustness of the code.
//MADE BY:
//Raymond Cao
//Danieva Paraiso
//Justin Mateo
//Sina Haghighi
//Date: 2020-11-29 
/*****************************************************************/
#include <iostream> //cin and cout
#include <cstdlib> 
#include <iomanip>
//#include "student.hpp"
#include "domesticstudent.hpp" 
#include "internationalstudent.hpp"
#include "LinkedList.hpp"
//defines to make reading the code easier
#define underline "\033[4m" 
#define stopunderline "\033[0m"
#define blue "\x1b[36m"
#define yellow  "\033[33m"
#define red "\033[0m\x1b[31m"
using std::cin;

int main(){

try{
    //Used for the Unit test and the interactive menu portion
    DomLinkedList DList;
    GenLinkedList GList;
    IntLinkedList IList;

    //normal case elements for the unit test
    ToeflScore raymondsscore(20, 25, 25, 30);
    DomesticStudent *sinaptr;
    InternationalStudent* raymondptr;
    DomesticStudent sina("Sina", "Haghighi", 3.9, 89, 678, "BC");
    InternationalStudent raymond("Raymond", "Cao", 2.7, 96, 398, "China", raymondsscore);
    sinaptr = &sina;
    raymondptr = &raymond;
    
    //corner case elements for the unit test
    ToeflScore muskidscore(0, 0, 30, 30);
    DomesticStudent *daniptr;
    InternationalStudent *muskidptr;
    DomesticStudent dani("Danieva", "Paraiso", -1, 101, 9999, "NU");
    InternationalStudent muskid("Elonkid", "Musk", 4.4, -1, 432, "Idian", muskidscore);
    daniptr = &dani;
    muskidptr = &muskid;
   
    //elements for the interactive menu portion
    DomLinkedList* D2List;
    GenLinkedList* G2List;
    IntLinkedList* I2List;
    //elements for the error checking portion
    DomLinkedList E1;
    DomLinkedList E2;
    IntLinkedList E3;
    int stu_count = 0;
    int idian = 0;
	//////////////////////////////////////////////////////////////   
    //this calls the function that adds the students from
    //the text files into their respective linked list 
    DList = makeDomLinkedList(DList, stu_count);
    IList = makeIntLinkedList(IList, stu_count, idian);
    //////////////////////////////////////////////////////////////
 	//variables used for the interactive portions of the main
    bool good = 1, stay = 1, correct = 1, correct1 = 1, estay, egood;
    char stutype, mode;
    float cgpa;
    int rscore, id, done1 = 0, done2 = 0, acr, init, emode;
    string yorn, sinit, semode, emodetry, emodesure, tempstudent;
    string fname, lname, province, country, fullname, state, sacr, sid, scgpa, srscore, tryagain;
    
    cout << "\nWelcome to the Graduate Admissions System!\n"
         << "Today we will be facilitating your admission system needs\n"
		 << "\x1b[36m" << "Blue Represents Domestic Students\n" << "\033[0m"
		 << "\033[33m" << "Yellow Represents International Students\n" << "\033[0m"; 
    do{    
        cout << "\nPlease select one of the following options:\n"
             << "1. Unit Tests\n"
             << "2. Menu Options\n"
             << "3. Error Handling\n"
		     << "Enter the number of your choice : ";

        cin >> sinit;
		init = atoi(sinit.c_str());
        switch(init){
///////////////////////////////////////////////UNIT_TESTS//////////////////////////////////////////////////////////
//This portion of the code is to represent our Part 3 of the project
//It represents the normal and corner case checking of our code.
            case 1:
///////////////////////////////////////////////PART_1//////////////////////////////////////////////////////////
                cout << underline <<"\nEntering Normal Cases portion\n\n" << stopunderline;
                //corner cases at line 222
                //illegal cases at line 402
			    while(correct){
                    cout << "\x1b[36m" << "\n";
                    cout << "Adding a Domestic Student, Sina Haghighi: \n";
                    cout << sina; 			 
                    DList.addDomStudent(sinaptr);
                    cout << "\033[0m" << "\n";

                    cout << "\033[33m";
                    cout << "Adding an International Student, Raymond Cao: \n";
                    cout << raymond; 			 
                    cout << "\033[0m" << "\n";
                    IList.addIntStudent(raymondptr);
                    cout << "\nEnter 'y' when you are ready to enter the next state: ";
                    while(correct1){
                        cin >> state;
						//here is the first instance of one of our many error checking strategies
						//our way of making sure that they input a certain character is 
						//make the input a string so that big inputs are caught and no extra outputs
						//are executed 
                        if ( state.compare("Y") == 0 || state.compare("y") == 0){
                            correct = 0;
                            correct1 = 0; 
                        }else{
                            cout << "Invalid input, ready: ";
                        }
                    }
  		        }   
			    correct = 1; 
			    correct1 = 1;
            
///////////////////////////////////////////////PART_2a//////////////////////////////////////////////////////////
			while(correct){
				//searching dom list
				cout << "\x1b[36m" << underline;
				cout << "\nSearching the Domestic List:\n\n" << stopunderline
					<< "\033[0m" << "Searching for 20200091 application ID: \n";
					DList.searchDomAppID(20200091);
				cout << "\nSearching for CGPA 3.7: \n";
					DList.searchDomCGPA(3.7);
				cout << "\nSearching for research score 81: \n";
					DList.searchDomRScore(81);
///////////////////////////////////////////////PART_3a//////////////////////////////////////////////////////////
				cout << "\nSearching for student named Sebastian Ward: \n";
					DList.searchDomName("Sebastian Ward"); 
				cout << "\033[0m";
///////////////////////////////////////////////PART_2b//////////////////////////////////////////////////////////
				//searching int list
				cout << "\033[33m" << underline
					<< "\nSearching the International List:\n\n"
					<< stopunderline
					<< "\033[0m" <<  "Searching for 20200167 application ID\n";
					IList.searchIntAppID(20200167);
				cout << "\nSearching for CGPA 3.5:\n";
					IList.searchIntCGPA(3.5);
				cout << "\nSearching for research score 81:\n";
					IList.searchIntRScore(81);
///////////////////////////////////////////////PART_3b//////////////////////////////////////////////////////////
				cout << "\nSearching for the student named Sima Javadi:\n";
					IList.searchIntName("Sima Javadi");
				cout << "\033[0m";

				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1;
			correct1 = 1;
///////////////////////////////////////////////PART_4a//////////////////////////////////////////////////////////
			while(correct){
				//deleting some of domestic list
				cout << "\n\n\x1b[36m" << underline
					<< "Deleting from the Domestic List:\n\n" << stopunderline;
					DList.searchDomName("Alexander Murphy");
				cout << "Deleting the student named Alexander Murphy\n";
					DList.deleteDomStu("Alexander Murphy");
					DList.searchDomName("Alexander Murphy");
				cout << "Alexander Murphy has been deleted\n\n";
///////////////////////////////////////////////PART_5a//////////////////////////////////////////////////////////				
				cout << "\x1b[36m" << underline
					 <<"Deleting the head and tail: " << stopunderline;
				cout << "\n\x1b[36m" << "The current head is: "
					 << DList.getHead()->getFirstName() + " " + DList.getHead()->getLastName();
				cout << "\nThe current tail is: "
					 << DList.getTail()->getFirstName() + " " + DList.getTail()->getLastName();
					DList.deleteDomHeadTail();
				cout << "\n\033[0mDeleted.\x1b[36m\nThe current head is: "
					 << DList.getHead()->getFirstName() + " " + DList.getHead()->getLastName();
				cout << "\nThe current tail is: "
					 << DList.getTail()->getFirstName() + " " + DList.getTail()->getLastName();
				cout << "\033[0m";

///////////////////////////////////////////////PART_4b//////////////////////////////////////////////////////////
				//deleting some of international list
				cout << "\033[33m" << underline
					<< "\n\n\nDeleting from the International List:\n\n" << stopunderline;
					IList.searchIntName("Aditya Bhattathiri");
				cout << "Deleting the student named Aditya Bhattathiri\n";
					IList.deleteIntStu("Aditya Bhattathiri");
					IList.searchIntName("Aditya Bhattathiri");
				cout << "Aditya Bhattathriri has been deleted\n\n";
///////////////////////////////////////////////PART_5b//////////////////////////////////////////////////////////
				cout << "\033[33m" << underline
					 << "Deleting the head and tail: " << stopunderline
                     << "\n\033[33m" << "The current head is: "
                     << IList.getHead() -> getFirstName() + " " + IList.getHead() -> getLastName();
                    
                cout << "\nThe current tail is: "
                     << IList.getTail() -> getFirstName() + " " + IList.getTail()->getLastName();
                     IList.deleteIntHeadTail();
                cout << "\n\033[0mDeleted.\033[33m\nThe current head is: "
                     << IList.getHead() -> getFirstName() + " " + IList.getHead() -> getLastName();
                cout << "\nThe current tail is: "
                     << IList.getTail() -> getFirstName() + " " + IList.getTail()->getLastName();

				cout << "\033[0m"; 
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
				
			}
			correct = 1;
			correct1 = 1;
///////////////////////////////////////////////PART_6//////////////////////////////////////////////////////////
			while(correct){
            cout << underline << "\n\nMerging the International and Domestic Lists into one.\n"
				 <<stopunderline;
                 GList.mergeGenStudent(IList, DList);
            cout << "Merged.\n ";
///////////////////////////////////////////////PART_7//////////////////////////////////////////////////////////
            cout << underline << "\n\nSearching the merged list with thresholds:\n"
				 <<stopunderline
                 << "CGPA >= 3.6 and Research Score >= 78\n";                 
                 GList.printByThresh(3.6, 78);
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1; 
			correct1 = 1;
///////////////////////////////////////////////CORNER CASES//////////////////////////////////////////////////////////
///////////////////////////////////////////////PART_1c//////////////////////////////////////////////////////////
			while(correct){
				cout << "\x1b[36m" << "\n" << underline;
				cout << "Adding a Domestic Student, Danieva Paraiso: \n" << stopunderline
					 << "\x1b[36m"
                     << "Danieva is constructed with a research score of 101 and CGPA -1\n";
				cout << dani; 			 
				DList.addDomStudent(daniptr);
				cout << "\033[0m" << "\n";

				cout << "\033[33m" << underline; 
				cout << "Adding an International Student, Elonkid Musk: \n" << stopunderline
                     << "\033[33m"
					 << "Elonkid is constructed with a research score of -1 and CGPA 4.4\n";
				cout << muskid; 			 
				cout << "\033[0m" << "\n";
				IList.addIntStudent(muskidptr);
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
  		}   
			correct = 1; 
			correct1 = 1;
///////////////////////////////////////////////PART_2c//////////////////////////////////////////////////////////
			while(correct){
				//searching dom list
				cout << "\x1b[36m" << underline; 
				cout << "\nSearching the Domestic List:\n\n"
					 << stopunderline
					 << "\033[0m" <<  "Searching for 20210000 application ID: \n" ;
					DList.searchDomAppID(20210000);
				cout << "\nSearching for CGPA 0: \n" ;
					DList.searchDomCGPA(0);
				cout <<  "\nSearching for research score 100: \n" ;
					DList.searchDomRScore(100);

				cout << "\033[0m";
					
				//searching int list
				cout << "\033[33m" 
					<< "\nSearching the International List:\n\n"
					<< "\033[0m" <<  "Searching for 20000000 application ID\n" ;
					IList.searchIntAppID(20000000);
				cout <<  "\nSearching for CGPA 4.3:\n" ;
					IList.searchIntCGPA(4.3);
				cout <<  "\nSearching for research score 0:\n" ;
					IList.searchIntRScore(0);

				cout << "\033[0m";

				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 
					//getline(cin, state, '\n');
					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1;
			correct1 = 1;
///////////////////////////////////////////////PART_3c//////////////////////////////////////////////////////////
			while(correct){
				//deleting some of domestic list
				cout << "\n\n\x1b[36m" << underline
					<< "Deleting from the Domestic List:\n\n"
					<< stopunderline;
					DList.searchDomName("Danieva Paraiso");
				cout << "Deleting the student named Danieva Paraiso\n";
					DList.deleteDomStu("Danieva Paraiso");
					DList.searchDomName("Danieva Paraiso");
				cout << "Danieva Paraiso has been deleted\n\n";

				//deleting some of international list
				cout << "\033[33m" << underline
					<< "\n\n\nDeleting from the International List:\n\n"
					<< stopunderline;
					IList.searchIntName("Elonkid Musk");
				cout << "Deleting the student named Elonkid Musk\n";
					IList.deleteIntStu("Elonkid Musk");
					IList.searchIntName("Elonkid Musk");
				cout << "Elonkid Musk has been deleted\n\n";

				cout << "\033[0m"; 
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
				
			}
			correct = 1;
			correct1 = 1;
///////////////////////////////////////////////PART_4c//////////////////////////////////////////////////////////
			while(correct){
				cout << "\n\n\x1b[36m" << underline;
				cout << "This is the resulting Domestic List:\n"
					 << stopunderline;
					DList.printList();
				cout << "\033[0m";
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			} 
			correct = 1; 
			correct1 = 1;
		
///////////////////////////////////////////////PART_5c//////////////////////////////////////////////////////////
			while(correct){
				cout << "\n\n\033[33m" << underline;
				cout << "This is the resulting International List:\n"
					 <<stopunderline;
                    if (idian == 1){
                        cout << "Warning! Typo(s) detected, we have set 'Idian' to 'India'\n";
                    }
					IList.printList();
				cout << "\033[0m"; 
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1;
			correct1 = 1;

///////////////////////////////////////////////MENU_OPTIONS//////////////////////////////////////////////////////////
			while(correct){
            cout << underline << "\n\nSearching the merged list with thresholds:\n"
				 <<stopunderline
                 << "CGPA >= 4.3 and Research Score >= 100\n";
                 GList.printByThresh(4.3, 100);
				cout << "\nEnter 'y' when you are ready to enter the next state: ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1; 
			correct1 = 1;

			while(correct){
            cout << underline << "\n\nSearching the merged list with thresholds:\n"
				 <<stopunderline
                 << "CGPA >= 0 and Research Score >= 0\n";
                 GList.printByThresh(0.0, 0);
				cout << "This is the end of the unit test, would you like to continue? (y/n): ";
				while(correct1){
					cin >> state; 

					if ( state.compare("Y") == 0 || state.compare("y") == 0){
						correct = 0;
						correct1 = 0; 
					}else{
						cout << "try again: ";
					}
				}
			}
			correct = 1;
			correct1 = 1;
            //CORNER CASES
            break;
        case 2:{ 
            int done, done2;
            char inp = 0;
            char yorn;
            D2List = new DomLinkedList;
            I2List = new IntLinkedList;
            G2List = new GenLinkedList;
            cout << "\nYou have successfully entered the user menu mode\n";
        do{
            cout << "Would you like to:\n1. Work on current elements in lists?\n2. Evaluate a new empty program\n";
            cout << "Please enter your choice:";
            cin >> inp;
///////////////////////////////////////////////OPTION_1//////////////////////////////////////////////////////////
            if (inp == '2'){
                do{//Line 511
                    cout << "\n\033[4m" << "LEGEND" << "\033[0m\n" << "\033[36m" << "-> Domestic\n" << "\033[0m\033[33m" << "-> International\n" 
                        << "\033[0m\x1b[31m" << "-> Merged\n" << "\033[0m";
                    cout << "Please select one of the following options:\n"
                    << "Print | Insert | Search | Delete | Merge \n";
                    cout << "\033[36m" << " (a)     (d)      (g)       (j)" << "\033[0m" << endl;//blue
                    cout << "\033[33m" << " (b)     (e)      (h)       (k)" << "\033[0m" << endl;//orange
                    cout << "\x1b[31m" << " (c)     (f)      (i)       (l)     (m)\n" << "\x1b[0m" 
						 << "\nEnter your choice here: " ;//red
                    cin >> mode;
                    //another way we error check, all capital inputs are forced to be lower case
                    //so that the input can be a little bit more diverse
					if (mode >= 'A' && mode <= 'Z' ){
						mode = mode + 32; 
					}
                    switch(mode){
						
///////////////////////////////////////////////1CASE_A//////////////////////////////////////////////////////////
                        case 'a': // print dom list
                            cout << "\033[36mPrinting the Domestic List of Students\n\033[0m";
                            D2List -> printList();
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_B//////////////////////////////////////////////////////////
                        case 'b': // print int list
                            cout << "\033[33mPrinting the International List\n\033[0m";
                            if (idian == 1){
                                cout << "Warning! Typo(s) detected, we have set 'Idian' to 'India'\n";
                            }
                            I2List -> printList();
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_C//////////////////////////////////////////////////////////
                        case 'c': // print merged list
                            cout << "\x1b[31mPrinting the General (merged) List\n\x1b[0m";
                            G2List -> printList();
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_D//////////////////////////////////////////////////////////
                        case 'd': // insert dom stu
                            cout << "\033[36mCreating a Domestic Student,\nPlease enter the corresponding values\n";
                            D2List -> createDomStu(stu_count);
                            done = 1;
                            cout << "Successfully created a Domestic student!" << stopunderline << "\n";
                            break;
///////////////////////////////////////////////1CASE_E//////////////////////////////////////////////////////////
                        case 'e': // insert int stu
                            cout << "\033[33mCreating an International Student,\nPlease enter the corresponding values\n";
                            I2List -> createIntStu(stu_count);
                            done = 1;
                            cout << "Successfully created a International student!\033[0m\n";
                            break;
///////////////////////////////////////////////1CASE_F//////////////////////////////////////////////////////////
                        case 'f': //insert gen stu
                            cout << "\x1b[31mCreating a General Student in the merged list,\nPlease enter the corresponding values\n";
                            G2List -> createGenStu(stu_count);
                            done = 1;
                            cout << "Successfully created a General (merged) student!\n" << stopunderline;
                            break;
///////////////////////////////////////////////1CASE_G//////////////////////////////////////////////////////////
                        case 'g': // search dom stu
                            done2 = 0;
                            while(done2 == 0){
                                cout << "\033[36m\nSearch Domestic List by:\n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full Name\n"
                                     << "Enter choice here : "
                                     << "\033[0m";
                                //another instance of error checking is here,
                                //we let the user inputs an integer into a string so that
                                //extraneous inputs don't ruin the output
                                //the string is then converted to an integer
                                cin.clear();
                                sacr.clear();
                                cin >> sacr;
							    acr = atoi(sacr.c_str());
                                switch(acr){
                                    case 1:
                                        cout << "\033[36m"; 
                                        cout << "Please input an Application ID : ";
									    correct = 1;
                                        while(correct){
										    cin >> sid;
										    id = atoi(sid.c_str());
										
										    if (id == 0 || id < 20200000){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    D2List -> searchDomAppID(id);
											    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 2:
                                        cout << "\033[36m";
									    cout << "Please input a CGPA : ";           
                                        correct = 1;
									    while(correct){                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
											    D2List -> searchDomCGPA(cgpa);
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 3:
                                        cout << "\033[36m";
                                        cout << "Please input a Research Score: ";
									    correct = 1;
                                        while(correct){
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    D2List -> searchDomRScore(rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 4:
                                        cout << "\033[36m";
                                        cout << "Please input the Full Name: ";
                                        // cin >> fullname;
                                        cin.ignore();
									    getline(cin, fname, ' ');
									    getline(cin, lname, '\n');
									    fullname = fname + " " + lname; 
                                        D2List -> searchDomName(fullname);
									    done2 = 1; 
                                        cout << "\033[0m";
                                        break;
                                    default:
                                        cout << "\033[0mIncorrect input, please try again\n";
                                        done2 = 0;                          
                                        break;
                                }
                            }
                            cout << "\033[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_H//////////////////////////////////////////////////////////
                        case 'h': // search int stu
                            done2 = 0;
						    while(done2 == 0){
                                cout << "\n\033[33mSearch International List by: \n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full Name\n";
                                cin >> acr;
                                switch(acr){
                                    case 1:
									    cout << "\033[36m"; 
                                        cout << "Please input an Application ID : ";
									    correct = 1;
                                        while(correct){
										    cin >> sid;
										    id = atoi(sid.c_str());
										    if (id == 0 || id < 20200000){
											cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    I2List -> searchIntAppID(id);
											    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 2:
									    cout << "\033[36m";
									    cout << "Please input a CGPA : ";           
                                        correct = 1;
									    while(correct){                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
											    I2List -> searchIntCGPA(cgpa);
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 3:
									    cout << "\033[36m";
                                        cout << "Please input a Research Score";
									    correct = 1;
                                        while(correct){
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    I2List -> searchIntRScore(rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 4:
									    cout << "\033[36m";
                                        cout << "Please input the Full Name: ";
                                        cin.ignore();
									    getline(cin, fname, ' ');
									    getline(cin, lname, '\n');
									    fullname = fname + " " + lname; 
                                        D2List -> searchDomName(fullname);
									    done2 = 1; 
                                        cout << "\033[0m";
                                        break;
                                    default:
                                        cout << "\033[0mIncorrect input, please try again";
                                        done2 = 0;                                    
                                }
                            }
                            cout << "\033[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_I//////////////////////////////////////////////////////////
                        case 'i': // search merged stu
                            done2 = 0;
                            while(done2 == 0){
                                cout << "\x1b[31m\nSearch General (merged) List by: \n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full name\n"
                                     << "5. Threshold\n"
                                     << stopunderline;
                                cin.clear();
                                sacr.clear();
                                cin >> sacr;
							    acr = atoi(sacr.c_str());
                                switch(acr){
                                    case 1:
									    cout << "\x1b[31m"; 
                                        cout << "Please input an Application ID : ";
									    correct = 1;
                                        while(correct){
										    cin >> sid;
										    id = atoi(sid.c_str());
										    if (id == 0 || id < 20200000){
											cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    G2List -> searchGenAppID(id);
											    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 2:
									    cout << "\x1b[31m";
									    cout << "Please input a CGPA : ";           
                                        correct = 1;
									    while(correct){                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
											    G2List -> searchGenCGPA(cgpa);
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 3:
									    cout << "\x1b[31m";
                                        cout << "Please input a Research Score";
									    correct = 1;
                                        while(correct){
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    G2List -> searchGenRScore(rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }   
									    }
									    correct = 1;
									    break;
                                    case 4:
									    cout << "\x1b[31m";
                                        cout << "Please input the Full Name: ";
                                        cin.ignore();
									    getline(cin, fname, ' ');
									    getline(cin, lname, '\n');
									    fullname = fname + " " + lname; 
                                        GList.searchGenName(fullname);
									    done2 = 1; 
                                        cout << "\033[0m";
                                        break;
                                    case 5:
                                        cout << "\x1b[31m";
                                        cout << "Please input the CGPA threshold: ";
                                        correct = 1;
									    while(correct){
                                            cin.clear();                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
                                        correct = 1;
                                        cout << "\x1b[31m";
                                        cout << "Please input a Research Score threshold: ";
									    correct = 1;
                                        while(correct){
                                            cin.clear();
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
											    G2List -> printByThresh(cgpa, rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
                                        break;
                                    default:
                                        cout << "\033[0mIncorrect input, please try again\033[0m";
                                        done2 = 0;                                    
                                }
                            }
                            cout << "\x1b[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////1CASE_J//////////////////////////////////////////////////////////
                        case 'j': // delete dom stu
                            cout << "\033[36m\nDelete Domestic Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname;
                            D2List -> deleteDomStu(fullname);
                            cout << "\033[0m";
                            done = 1;
                            break;                                
///////////////////////////////////////////////1CASE_K//////////////////////////////////////////////////////////
                        case 'k': // delete int stu
                            cout << "\033[33m\nDelete International Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname;
                            I2List -> deleteIntStu(fullname);
                            done = 1;
                            break;           
///////////////////////////////////////////////1CASE_L//////////////////////////////////////////////////////////
                            case 'l': // delete gen stu
                            cout << "\033[33m\nDelete General Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname;
                            G2List -> deleteGenStu(fullname);
                            done = 1;
                            cout << "\033[0m";
                            break;
///////////////////////////////////////////////1CASE_M//////////////////////////////////////////////////////////
                        case 'm': //merge  
                            GList.mergeGenStudent(*I2List, *D2List);
                            done = 1;
                            break;
                        default:
                            cout << "Invalid entry, please try again.\n";
                            done = 0;
                            break;
                    }
                    if(done == 1){
                        cout << "\nWould you like to try another functionality? (y/n): ";
                        cin >> yorn;
                    }
                }while (done == 0 || yorn == 'y' || yorn == 'Y');
            }
            else if (inp == '1'){
///////////////////////////////////////////////OPTION_2//////////////////////////////////////////////////////////
			
                do{//Line 511
         
                    cout << "\n\033[4m" << "LEGEND" << "\033[0m\n" << "\033[36m" << "-> Domestic\n" << "\033[0m\033[33m" 
                         << "-> International\n" 
                         << "\033[0m\x1b[31m" << "-> Merged\n" << "\033[0m";
                    cout << "Please select one of the following options:\n"
                         << "Print | Insert | Search | Delete | Merge\n";
                    cout << "\033[36m" << " (a)     (d)      (g)       (j)" << "\033[0m" << endl;//green
                    cout << "\033[33m" << " (b)     (e)      (h)       (k)" << "\033[0m" << endl;//red
                    cout << "\x1b[31m" << " (c)     (f)      (i)       (l)     (m)" << "\x1b[0m" << endl;//teal
				    cout << "\nEnter your choice here: ";
                    cin >> mode;
					
					if (mode >= 'A' && mode <= 'Z' ){
						mode = mode + 32; 
					}
                    switch(mode){
///////////////////////////////////////////////2CASE_A//////////////////////////////////////////////////////////
                        case 'a': // print dom list
                            cout << "\033[36mPrinting the Domestic List of Students\n\033[0m";
                            DList.printList();
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_B//////////////////////////////////////////////////////////
                        case 'b': // print int list
                            cout << "\033[33mPrinting the International List\n\033[0m";
                            if (idian == 1){
                                cout << "Warning! Typo(s) detected, we have set 'Idian' to 'India'\n";

                            }
                            IList.printList();
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_C//////////////////////////////////////////////////////////
                        case 'c': // print merged list
                            cout << "\x1b[31mPrinting the General (merged) List\n\x1b[0m";
                            //GList.mergeGenStudent(IList, DList);
                            GList.printList();
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_D//////////////////////////////////////////////////////////
                        case 'd': // insert dom stu
                            cout << "\033[36mCreating a Domestic Student,\nPlease enter the corresponding values\n";
                            DList.createDomStu(stu_count);
                            cout << "Sucessfully created a Domestic Student!\n";
                            done = 1;
                            cout << "\033[0m";
                            break;
///////////////////////////////////////////////2CASE_E//////////////////////////////////////////////////////////
                        case 'e': // insert int stu
                            cout << "\033[33mCreating an International Student,\nPlease enter the corresponding values\n";
                            IList.createIntStu(stu_count);
                            cout << "Successfully created an International Student!\n";
                            cout << "\033[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_F//////////////////////////////////////////////////////////
                        case 'f': //insert gen stu
                            cout << "\x1b[31mCreating a General Student in the merged list,\nPlease enter the corresponding values\n";
                            GList.createGenStu(stu_count);
                            cout << "Successfully created a Gerneral Student!\n";
                            cout << "\x1b[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_G//////////////////////////////////////////////////////////
                        case 'g': // search dom stu
                            done2 = 0;
                            while(done2 == 0){
                                cout << "\033[36m\nSearch Domestic List by: \n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full Name\n"
								     << "Enter choice here: "
                                     << "\033[0m";
                                cin.clear();
                                sacr.clear();
                                cin >> sacr;
                                acr = atoi(sacr.c_str());
                                switch(acr){
                                    case 1:
                                        cout << "\033[36m";
                                        cout << "Please input an Application ID : ";
                                        correct = 1;
                                        while(correct){
                                            cin >> sid;
                                            id = atoi(sid.c_str());
                                            if (id == 0 || id < 20200000){
                                                cout << "Invalid Input, try again: ";
                                            }
                                            else{
                                                DList.searchDomAppID(id);
                                                done2 = 1;
                                                cout << "\033[0m";
                                                correct = 0;
                                                break;
                                            }
                                        }
                                        correct = 1;
                                        break;
                                    case 2:
                                        cout << "\033[36m";
									    cout << "Please input a CGPA : ";
                                        correct = 1;
                                        while (correct){
									        cin >> scgpa;
                                            cgpa = atof(scgpa.c_str()); 
                                            if(CompareFloats2(cgpa, 0.0)){
                                                cout << "Invalid Input, try again: ";
                                            }
                                            else{
                                                DList.searchDomCGPA(cgpa);
                                                done2 = 1;
                                                correct = 0;
                                                cout << "\033[0m";
                                                break;
                                            }
                                        }
                                        correct = 1;
                                        break;
                                    case 3:
                                        cout << "\033[36m";
                                        cout << "Please input a Research Score: ";
                                        correct = 1;
                                        while (correct){
                                            cin >> srscore;
                                            rscore = atoi(srscore.c_str());
			
                                            if (rscore > 100 || rscore < 0){
                                                cout << "Invalid Input, try again: ";
                                            }
                                            else{
                                                DList.searchDomRScore(rscore);
                                                done2 = 1;
                                                cout << "\033[0m";
                                                correct = 0;
                                                break;
                                            }
                                        }
                                        correct = 1;
                                        break;
                                    case 4:
                                        cout << "\033[36m";
                                        cout << "Please input the Full Name: \n";
                                        cin.ignore();
                                        getline(cin, fname, ' ');
                                        getline(cin, lname, '\n');
                                        fullname = fname + " " + lname;
                                        DList.searchDomName(fullname);
                                        done2 = 1;
                                        break;
                                    default:
                                        cout << "\033[0mIncorrect input, please try again";
                                        done2 = 0;                                    
                                }
                            }
                            cout << "\033[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_H//////////////////////////////////////////////////////////
                        case 'h': // search int stu
                            done2 = 0;
						    while(done2 == 0){
                                cout << "\033[33m\nSearch International List by: \n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full Name\n"
								     << "Enter choice here: ";
							    cin.clear();
                                sacr.clear();
                                cin >> sacr;
							    acr = atoi(sacr.c_str());
                                switch(acr){
                                    case 1:
									    cout << "\033[33m"; 
                                        cout << "Please input an Application ID : ";
									    correct = 1;
                                        while(correct){
										    cin >> sid;
										    id = atoi(sid.c_str());
										    if (id == 0 || id < 20200000){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
		                                        IList.searchIntAppID(id);
											    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break;
                                    case 2:
									    cout << "\033[33m";
									    cout << "Please input a CGPA : ";           
                                        correct = 1;
									    while(correct){                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
		                                        IList.searchIntCGPA(cgpa);
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 3:
									    cout << "\033[33m";
                                        cout << "Please input a Research Score: ";
									    correct = 1;
                                        while(correct){
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
                                  		  	    IList.searchIntRScore(rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break;
                                    case 4:
									    cout << "\033[33m";
                                        cout << "Please input the Full Name: ";
                                        cin.ignore();
									    getline(cin, fname, ' ');
									    getline(cin, lname, '\n');
									    fullname = fname + " " + lname; 
                                        IList.searchIntName(fullname);
									    done2 = 1; 
                                        cout << "\033[0m";
                                        break;
                                    case 5:
                                        
                                    default:
                                        cout << "\033[0mIncorrect input, please try again";
                                        done2 = 0;                                    
                                }
                            }
                            cout << "\033[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_I//////////////////////////////////////////////////////////
                        case 'i': // search merged stu
                            done2 = 0;
                            while(done2 == 0){
                                cout << "\n\x1b[31mSearch General (merged) List by: \n"
                                     << "1. Application ID\n"
                                     << "2. CGPA\n"
                                     << "3. Research Score\n"
                                     << "4. Full Name\n"
                                     << "5. Threshold\n"
								     << "Enter choice here: "
                                     << stopunderline;
							    cin.clear();
                                sacr.clear();
                                cin >> sacr;
							    acr = atoi(sacr.c_str());
                                switch(acr){
                                    case 1:
									    cout << "\x1b[31m"; 
                                        cout << "Please input an Application ID : ";
									    correct = 1;
                                        while(correct){
                                            cin.clear();
										    cin >> sid;
										    id = atoi(sid.c_str());
										    if (id == 0 || id < 20200000){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
                                   			    GList.searchGenAppID(id);
											    done2 = 1;
											    cout << "\x1b[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break;
                                    case 2:
									    cout << "\x1b[31m";
									    cout << "Please input a CGPA : ";           
                                        correct = 1;
									    while(correct){
                                            cin.clear();                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
											    cout << "Invalid Input, try again: ";
										    }
                                            else{
		                                        GList.searchGenCGPA(cgpa);
											    done2 = 1;
											    correct = 0; 
											    cout << "\x1b[0m";
											    break;
										    }
									    }
									    correct = 1;
									    break; 
                                    case 3:
									    cout << "\x1b[31m";
                                        cout << "Please input a Research Score: ";
									    correct = 1;
                                        while(correct){
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
											    cout << "Invalid Input, try again: "; 
										    }
                                            else{
                                   			    GList.searchGenRScore(rscore);
                                   			    done2 = 1;
											    cout << "\x1b[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
									    break;
                                    case 4:
									    cout << "\x1b[31m";
                                        cout << "Please input the Full Name: ";
                                        cin.ignore();
									    getline(cin, fname, ' ');
									    getline(cin, lname, '\n');
									    fullname = fname + " " + lname; 
                                        GList.searchGenName(fullname);
									    done2 = 1; 
                                        cout << "\033[0m";
                                        break;
                                    case 5:
                                        cout << "\x1b[31m";
                                        cout << "Please input the CGPA threshold: ";
                                        cout << "\033[0m";
                                        correct = 1;
									    while(correct){
                                            cin.clear();                 
										    cin >> scgpa;
										    cgpa = atof(scgpa.c_str());
										    if(CompareFloats2(cgpa, 0.0)){
                                                cout << "\x1b[31m";
											    cout << "Invalid Input, try again: ";
                                                cout << "\033[0m";
										    }
                                            else{
											    done2 = 1;
											    correct = 0; 
											    cout << "\033[0m";
											    break;
										    }
									    }
                                        correct = 1;
                                        cout << "\x1b[31m";
                                        cout << "Please input a Research Score threshold: ";
									    correct = 1;
                                        while(correct){
                                            cin.clear();
                                            cout << "\033[0m";
                                   		    cin >> srscore;
										    rscore = atoi(srscore.c_str());
										    if (rscore > 100 || rscore < 0){
                                                cout << "\x1b[31m";
											    cout << "Invalid Input, try again: "; 
                                                cout << "\033[0m";
										    }
                                            else{
											    GList.printByThresh(cgpa, rscore);
                                   			    done2 = 1;
											    cout << "\033[0m";
											    correct = 0; 
											    break;
										    }
									    }
									    correct = 1;
                                        break;
                                    default:
                                        cout << "\033[0mIncorrect input, please try again\033[0m";
                                        done2 = 0; 
                                }
                            }
                            cout << "\x1b[0m";
                            done = 1;
                            break;
///////////////////////////////////////////////2CASE_J//////////////////////////////////////////////////////////
                        case 'j': // delete dom stu
                            cout << "\033[36m\nDelete Domestic Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname; 
                            DList.deleteDomStu(fullname);
                            cout << "\033[0m";
                            done = 1;
                            break;                                 
///////////////////////////////////////////////2CASE_K//////////////////////////////////////////////////////////
                        case 'k': // delete int stu
                            cout << "\033[33m\nDelete International Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname;
                            IList.deleteIntStu(fullname);
                            done = 1;
                            cout << stopunderline;
                            break;            
///////////////////////////////////////////////2CASE_L//////////////////////////////////////////////////////////
                        case 'l': // delete gen stu
                            cout << "\033[33m\nDelete General Student by Full Name\n"
                                 << "Please enter the full name of the individual to delete: \n";
                            cin.ignore();
                            getline(cin, fname, ' ');
                            getline(cin, lname, '\n');
                            fullname = fname + " " + lname;
                            GList.deleteGenStu(fullname);
                            done = 1;
                            cout << stopunderline;
                            break;           
///////////////////////////////////////////////2CASE_M//////////////////////////////////////////////////////////
                        case 'm': //merge  
                            GList.mergeGenStudent(IList, DList);
                            done = 1;
                            break;
                        default:
                            cout << "Invalid entry, please try again.\n";
                            done = 0;
                            break;
                    }
                    if(done == 1){
                        cout << "\nWould you like to try another functionality? (y/n): ";
                        cin >> yorn;
                    }
                } while (done == 0 || yorn == 'y' || yorn == 'Y');
            }
            else{
                cout << "\nInvalid entry, please try again\n";
                done = 0;
            }
            if(done == 1){
                cout << "Would you like to evaluate another version of list, such as a new list or current list? (y/n): ";
                cin >> yorn;
            }
        }while ( yorn == 'y' || yorn == 'Y' || done == 0);
        delete[] G2List, 
        delete[] I2List, 
        delete[] D2List;
        // possibly add the function for the user to print out the merged version of the 2 groups
        break;       
        } 
///////////////////////////////////////////////ERROR_CHECKING//////////////////////////////////////////////////////////
        case 3:
            cout << "\nYou have successfully entered the error handling mode\n";
            do{ 
                cout << "Please select from one of the following options\n"
                     << "Missing field(1)\nMisspelt province(2)\n"
                     << "Mispelt country(3)\nYour own input(4)\n"
                     << "Enter the number of your choice: ";
                cin.clear();
                semode.clear();
                cin >> semode;
                emode = atoi(semode.c_str());
                switch(emode){
                    case 1:
                        cout << "\033[36m"
                            << "Inputing domestic student\n"
                            << "Name - Terry Cruise\n"
                            << "CGPA - (Missing)\n"
                            << "Research Score - 90\n"
                            << "Province - BC\n"
                            << "\033[0m"
                            << "Checking this case will exit the program as there is an error, are you sure? (y/n) ";
                        cin >> emodesure;
                        if (emodesure == "y" || emodesure == "Y")
                            E1 = makeerror1(E1, stu_count);
                        else if (emodesure == "n" || emodesure == "N")
                            cout << "\nExiting...\n";
                        else
                            cout << "\nInvalid entry, exiting...\n";
                        cout << "\033[0m";
                        break;
                    case 2:
                        cout << "\033[36m"
                            << "Inputing domestic student\n"
                            << "Name - Micheal Scott\n"
                            << "CGPA - 4.0\n"
                            << "Research Score - 75\n"
                            << "Province - BV (Wrong spelling)\n"
                            << "\033[0m"
                            << "Checking this case will exit the program as there is an error, are you sure? (y/n) ";
                        cin >> emodesure;
                        if (emodesure == "y" || emodesure == "Y")
                            E2 = makeerror2(E2, stu_count);
                        else if (emodesure == "n" || emodesure == "N")
                            cout << "\nExiting...\n";
                        else
                            cout << "\nInvalid entry, exiting...\n";
                        cout << "\033[0m";
                        break;
                    case 3:
                        cout << "\033[33m"
                            << "Inputing international student\n"
                            << "Name - Kerry Kim\n"
                            << "CGPA - 4.0\n"
                            << "Research Score - 78\n"
                            << "ToeflScore - 100(R20,L20,S20,W20)\n"
                            << "Country - Korean(wrong spelling, should be Korea)\n"
                            << "\033[0m"
                            << "Checking this case will exit the program as there is an error, are you sure? (y/n) ";
                        cin >> emodesure;
                        if (emodesure == "y" || emodesure == "Y")
                            E3 = makeerror3(E3, stu_count);
                        else if (emodesure == "n" || emodesure == "N")
                            cout << "\nExiting...\n";
                        else
                            cout << "\nInvalid entry, exiting...\n";
                        cout << "\033[0m";
                        break;
                    case 4:
                        cout <<"\x1b[36m" << "Domestic (D)" << "\033[0m" << " or " << "\033[33m" << "International (I)" << "\033[0m"  <<" student?\n";
                        cin >> tempstudent;
                        if(tempstudent.compare("i") == 0 || tempstudent.compare("I") == 0){
                            cout << "\033[33m";
                            cout << "Creating an International Student\n";
                            IList.createIntStu(stu_count);
                            cout << "\033[0m";
                        }
                        else if(tempstudent.compare("d") == 0|| tempstudent.compare("D") == 0){
                            cout << "\x1b[36m";
                            cout << "Creating a Domestic Student\n";
                            DList.createDomStu(stu_count);
                            cout << "\033[0m";
                        }
                        else
                            cout << "\nWrong input, unable to select choice";
                        break;
                    default:
                        cout << "\nWrong input, unsuccessfully entered a choice.";
                }
                cout << "\nWould you like to try again? (y/n)\n";
                do{
                    estay = 1;
                    egood = 0;
                    cin >> emodetry;
                    if (emodetry == "y" || emodetry == "Y")
                        continue;
                    else if (emodetry == "n" || emodetry == "N"){
                        cout << "Thank you for checking the errors.\n";
                        estay = 0;
                        egood = 0;
                    }
                    else{
                        cout << "Incorrect input of choice. Please input again. \n";
                        egood = 1;
                    }
                }while(egood);
            }while(estay);
            break;
        default:
            cout << "\nWrong input, unsuccessfully entered a mode.\n";
        }//i take credit for inspiring this bracket to be created <3
        cout << "Would you like to try another mode? (y/n)\n";
        do{
			cin >> tryagain; 
            /* if (tryagain == "y" || tryagain == "Y"){
                good = 1;
                continue;
            }
            else if (tryagain == "n" || tryagain == "N"){
                cout << "Thank you for choosing our graduate system! Have a nice day.\n";
                stay = 0;
                good = 1;
            } */
            
            if (tryagain.compare("y") == 0 || tryagain.compare("Y") == 0 ){
                good = 1;
                stay = 1;
				continue;
            }
            else if (tryagain.compare("n") == 0 || tryagain.compare("N") == 0){
                cout << "Thank you for choosing our graduate system! Have a nice day.\n";
                stay = 0;
				good = 1;
                continue;
            }
            else
                good = 0;
            if (good == 0)
                cout << "Incorrect input of choice. Please input again. (y/n)\n";
        }while(!good);
	}while (stay);

}
	catch(bad_alloc){
		cout << "Bad Allocation... exiting\n";
		cout << "\033[0m";
		exit(1);
		}
		
	catch(...){
		cout << "\033[0m";
	}

  return 0;
}
