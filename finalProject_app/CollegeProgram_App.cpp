#include "CollegeProgram.h"

int main()
{
	setlocale(LC_ALL, ""); //accept of french world

	Student tableStudent[SIZE];
	const int teachersize = 4;
	Teacher tableTeacher[teachersize] = { { "420-P16-AS", "Structured Programming", "7148" }, { "420-P16-AS", "Structured Programming", "7150" }, { "420-P16-AS", "Introduction à la programmation structurée", "7151" }, { "420-P34-AS", "Advanced Object Programming", "7256" } };

	bool boolSubMenu = true;
	bool boolMainMenu = true;
	bool boolsearchmenu = true;
	bool boolresultmenu = true;

	initial(tableStudent, SIZE);
	int counter = 0;
	welcomepage();

	do
	{
		
		int chooseMenu = mainMenu();
		string testMainLoop;
		switch (chooseMenu)
		{
			case 1:
			{
					  cout << "\n\tPlease enter the password  ";
					  bool tPassword=teacherPassword();
					  if (tPassword==true)
					  {
						  do
						  {
							  boolSubMenu = true;
							  int teacherMenu = teacher_Menu();
							  switch (teacherMenu)
							  {
								  case 1:
								  {
											system("cls");
											cout << "\n\n" << setw(32) << "1.1 List all the courses\n\n";
											Display_table_Teacher(tableTeacher, teachersize);  
											cout << endl << setw(60) << "**********************************************";
											cout << endl << setw(60) << "***    Press any key to return to menu     ***";
											cout << endl << setw(60) << "**********************************************";
											cout << endl;
											system("pause>>nul");
								  }
									  break;
								  case 2:
								  {	
											counter = Sign_up(tableStudent, SIZE, tableTeacher, teachersize, counter);		
								  }
									  break;
								  case 3:
								  {
											grade(tableStudent, SIZE);
											system("pause>>nul");
								  }
									  break;
								  case 4:
								  {
											displayefunction(tableStudent, counter);
											system("pause>>nul");
								  }
									  break;
								  case 5:
								  {
											system("cls");
											cout << "\n\t1.5 Sort the student list by Student ID ";
											sorting(tableStudent, counter);
											cout << endl << endl << endl << endl;
											cout << setw(60) << "**********************************************" << endl;
											cout << setw(60) << "***            Sorting is done             ***" << endl;
											cout << setw(60) << "**********************************************" << endl;
											cout << endl << endl;
											cout  << setw(56) << "press any key to turn back to main menu";
											system("pause>>nul");
								  }
									  break;
								  case 6:
								  {
											do
											{
												boolsearchmenu = true;
												system("cls");
												int i = searchMenu();
														switch (i)
													{
															case 1:
															{
																	  system("cls");
																	  cout << "\n\t1) Search by ID";
																	  cout << "\n\t===============\n";
																	  cout << "\n\tPlease enter the ID:  ";
																	  int lookid = 0;
																	  cin >> lookid;
																	  cin.clear();
																	  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
																	  int i=findvalidID(tableStudent, SIZE, lookid);
																	  if (i==-1)
																	  {
																		  cout << "\n\n\tID is not vaid \n";
																	  }
																	  else
																	  {
																		  DisplaybyID(tableStudent, i);
																	  }
																	  system("pause>>nul");
															}
																break;
															case 2:
															{
																	  system("cls");
																	  cout << "\n\t2) Search by First Name";
																	  cout << "\n\t======================\n";
																	  cout << "\n\tPlease enter the first name:  ";
																	  string lookid = "";
																	  lookid = csLetter();
																	  int i = findvalidFname(tableStudent, SIZE, lookid, counter);
																	  if (i > -1)
																	  {
																		  DisplaybyID(tableStudent, i);
																	  }
																	  else
																	  {
																		  cout << "\n\tThis first name is not exist ";
																		  cout << "\n\tPlease enter any key to return to manu \n";
																	  }
																	  system("pause>>nul");
															}
																break;
															case 3:
															{
																	  system("cls");
																	  cout << "\n\t3) Search by Last Name";
																	  cout << "\n\t======================\n";
																	  cout << "\n\tPlease enter the Last name:  ";
																	  string lookid = "";
																	  lookid = csLetter();
																	  int i = findvalidLname(tableStudent, SIZE, lookid, counter);
																	  if (i > -1)
																	  {
																		  DisplaybyID(tableStudent, i);
																	  }
																	  else
																	  {
																		  cout << "\n\tThis Last name is not exist ";
																		  cout << "\n\tPlease enter any key to return to manu \n";
																	  }
																	  system("pause>>nul");

															}
																break;
															case 4:
															{
																	  system("cls");
																	  cout << "\n\t4) Search by First Name & Last Name";
																	  cout << "\n\t===================================\n";
																	  cout << "\n\tPlease enter the First name:  ";
																	  string lookid = "";
																	  lookid = csLetter();
																	  int i = findvalidFnamewithoutmessage(tableStudent,SIZE,lookid,counter);

																	  cout << "\n\tPlease enter the Last name:  ";
																	  //string lookid = "";
																	  lookid = csLetter();
																	  int j = findvalidLnamewithoutmessage(tableStudent,SIZE,lookid,counter);
																	  if ((i==j)&&(i!=-1)&&(j!=-1))
																	  {
																		  DisplaybyID(tableStudent, i);
																	  }
																	  else
																	  {
																		  cout << "\n\tThis first name and last name is not exist ";
																		  cout << "\n\tPlease enter any key to return to manu \n";
																	  }
																	  system("pause>>nul");
															}
																break;
															case 5:
															{
																	  boolsearchmenu = false;
																	  system("pause>>nul");
															}
																break;
																
															default:
														{
																   cout << endl << setw(60) << "**********************************************";
																   cout << endl << setw(60) << "***  Please choose the number between 1-4  ***";
																   cout << endl << setw(60) << "**********************************************";
																   system("pause>null");
																   boolsearchmenu = true;
																   
														}
														//break;
													}
													
											} while (boolsearchmenu == true);
								  }
									  break;
								  case 7:
								  {
											boolSubMenu = false;
								  }
									  break;
								  default:
								  {
											 cout << endl << setw(60) << "**********************************************";
											 cout <<endl<< setw(60) << "***  Please choose the number between 1-7  ***";
											 cout << endl << setw(60) << "**********************************************";
											 system("pause>null");
								  }
									  break;
							  }
						  } while (boolSubMenu == true);
					  }
					  else
					  {
						  cout << "\n\n\tplease enter correct username and password"<<endl;
						  char d = (char)(7);
						  printf("%c\n", d);
						  system("pause>>nul");
					  }
			}
				break;
			case 2:
			{
					  int primarykey=studentPassword(tableStudent, counter);
					  if (primarykey != -1)
					  {
								do
							  {
								 boolSubMenu = true;
								 int studentMenu=student_Menu();
								 switch (studentMenu)
								 {
								 case 1:
									 {
										   system("cls");
										   cout << "\n";
										   cout <<right<< setw(40) << "List of courses that " << tableStudent[primarykey].first_Name << " " << tableStudent[primarykey].last_Name << " has token \n" ;
										   cout << setw(60) << "============================================\n\n";
										   cout<<"     ";
										   cout <<left<< setw(25) << "Course Number" << setw(42) << "Course Title" << setw(11) << "Group\n";
										   cout << setw(25) << "-------------" << setw(42) << "------------" << setw(11) << "-----\n";
										   cout << setw(25) << tableStudent[primarykey].courseNumber << setw(42) <<  tableStudent[primarykey].courseName << setw(11) << tableStudent[primarykey].group << endl;
										   system("pause>>nul");
									 }
									 break;
								 case 2:
								 {
										   do
										   {   
												   boolresultmenu = true;
												   int resultchoise=resultmenu();
												   switch (resultchoise)
												   {
												   case 1:
													   {
															 cout << "\n\n\tProject Grade";
															 cout << "\n\t===================";
															 cout << "\n\t" << tableStudent[primarykey].courseName<<"\t" << tableStudent[primarykey].project_Grade;
															 cout << "\n\tPress any key to return menu \n";
															 system("pause>>nul");
													   }
													   break;
												   case 2:
													   {
															 cout << "\n\n\tMidterm Exam Grade";
															 cout << "\n\t========================";
															 cout << "\n\t" << tableStudent[primarykey].courseName << "\t" << tableStudent[primarykey].midterm_Exam_Grade;
															 cout << "\n\tPress any key to return menu \n";
															 system("pause>>nul");
													   }
													   break;
												   case 3:
													   {
															 cout << "\n\n\tFinal Exam Grade";
															 cout << "\n\t======================";
															 cout << "\n\t" << tableStudent[primarykey].courseName << "\t" << tableStudent[primarykey].final_Exam_Grade;
															 cout << "\n\tPress any key to return menu \n";
															 system("pause>>nul");
													   }
													   break;
												   case 4:
													   {
															 cout << "\n\n\tFinal Result";
															 cout << "\n\t==================";
															 cout << "\n\t" << tableStudent[primarykey].courseName << "\t" << tableStudent[primarykey].finalResult;
															 cout << "\n\tPress any key to return menu \n";
															 system("pause>>nul");
													   }
													   break;
												   case 5:
													   {
															 boolresultmenu = false;
													   }
													   break;
												   default:{
															   cout << "\n\tPlease enter number between 1 - 5";
															   system("pause>>nul");
														   }
													   break;
												   }
											 } while (boolresultmenu == true);
										   

								 }
									 break;
								 case 3:
								 {
										   DisplaybyID(tableStudent, primarykey);
										   system("pause>>nul");
								 }
									 break;
								 case 4:
								 {
										   boolSubMenu = false;
										   
								 }
									 break;
							 
								 default:
										 {cout << "Please enter number between 1-4";
										 system("pause>>nul");
										 }
									 break;
								 }
							  } while (boolSubMenu == true);
					  }
					  else
					  {
						  cout << endl << endl << setw(63) << "**********************************************";
						  cout << endl << setw(63) << "***           Access aborted...            ***";
						  cout << endl << setw(63) << "**********************************************" << endl;
						  system("pause>>nul");
					  }	 
			}
				break;
			case 3:
			{
					  system("cls");
					  cout << "\n\n\t3 About us";
					  cout << "\n\t============";
					  cout << "\n\n\n\tThis program is written on 2015-11-19.";
					  cout << "\n\n\tThis is a final project.";
					  system("pause>>nul");
			}
				break;
			case 4:
			{
					  system("cls");
					  cout << "\n\n\t4 Exit";
					  cout << "\n\t========";
					  cout <<"\n\n\n\n\n\n\n"<<setw(54)<< "Do you want exit the program?    " ;
					  getline(cin, testMainLoop);
					  if ((testMainLoop == "Y")||(testMainLoop == "Yes") || (testMainLoop == "y") || (testMainLoop == "yes") || (testMainLoop == "YES")) 
					  {
						  boolMainMenu = false;
						  cout <<"\n\n\n"<< setw(51) << "\t********************************"<<endl;
						  cout << setw(51) << "\tThanks, for choosing our program"<<endl;
						  cout << setw(51) << "\t********************************"<<endl;
						  //system("pause>>nul");
					  }
			}
				break;
			default:
			{
					   cout << endl << setw(60) << "**********************************************";
					   cout << endl << setw(60) << "***  Please choose the number between 1-4  ***";
					   cout << endl << setw(60) << "**********************************************";
					   system("pause>>nul");
					   break;
			}
		}
	} while (boolMainMenu);
	system("pause>nul");
	return 0;
}