#include "CollegeProgram.h"

int mainMenu()
{
	system("cls");
	int chooseMenu;
	cout << "\n\n\t Main menu";
	cout << "\n\t ============";
	cout << "\n\n\t1 Teacher menu";
	cout << "\n\t2 Student menu";
	cout << "\n\t3 About us";
	cout << "\n\t4 Exit";
	cout << "\n\n\tPlease choose the number: ";
	cin >> chooseMenu;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	validationNumber(&chooseMenu);
	return chooseMenu;
}
int teacher_Menu()  //teacherMenu
{
	int chooseMenu;
	system("cls");
	cout << "\n\n\tTeacher menu ";
	cout << "\n\t================\n\n";
	cout << "\n\t1.1 List all the courses ";
	cout << "\n\t1.2 Enter students information";
	cout << "\n\t1.3 Enter students’ grades for a given course";
	cout << "\n\t1.4 Display the grade";
	cout << "\n\t1.5 Sort the student list by Student ID ";
	cout << "\n\t1.6 Search ";
	cout << "\n\t1.7 Return to main menu";
	cout << "\n\n\tPlease choose the item: ";
	cin >> chooseMenu;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	validationNumber(&chooseMenu);
	return chooseMenu;
}
int student_Menu()  //teacherMenu
{
	int chooseMenu;
	system("cls");
	cout << "\n\n\t2 Student menu";
	cout << "\n\t================"<<endl;


	cout << "\n\t2.1 List all the courses ";
	cout << "\n\t2.2 View the grade ";
	cout << "\n\t2.3 View the grade of courses has been done";
	cout << "\n\t2.4 Exit";
	cout << "\n\n\tPlease choose the item: ";
	cin >> chooseMenu;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	validationNumber(&chooseMenu);
	return chooseMenu;
}
int searchMenu()
{
	cout << "\n\n\tSearch Menu";
	cout << "\n\n\t===========";
	cout << "\n\t1) Search by ID";
	cout << "\n\t2) Search by First Name";
	cout << "\n\t3) Search by Last Name";
	cout << "\n\t4) Search by First Name & Last Name";
	cout << "\n\t5) Exit";
	cout << "\n\n\t Please choose item : ";
	int choose = 0;
	cin >> choose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choose;
}
int resultmenu()
{
	system("cls");
	cout << "\n\n\tResult Menu";
	cout << "\n\n\t===========";
	cout << "\n\t1) Project_Grade";
	cout << "\n\t2) Midterm_Exam_Grade";
	cout << "\n\t3) Final_Exam_Grade";
	cout << "\n\t4) finalResult";
	cout << "\n\t5) Exit";
	cout << "\n\n\tPlease select menu: ";
	int choose = 0;
	cin >> choose;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choose;
}

bool teacherPassword()
{
	system("cls");
	cout << "\n\n\tVerify the password";
	cout << "\n\t======================";
	cout << "\n\n\tUsername: ";
	string username = "";
	getline(cin, username);
	cout << "\t----------------------";
	string pass = "";
	char ch;
	cout << "\n\tEnter pass: ";
	ch = _getch();
	while (ch != 13)
	{//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		/*cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
		ch = _getch();
	}
	cout << "\n\t======================";
	cout << endl << endl << endl << endl;
	if ((username == "1") && (pass == "1"))  //
	{
		cout << "\n";
		cout << setw(63) << "**********************************************";
		cout << endl << setw(63) << "***            Access granted :            ***";
		cout << endl << setw(63) << "**********************************************";
		system("pause>>nul");
		return true;
	}
	else
	{
		cout << endl << endl << setw(63) << "**********************************************";
		cout << endl << setw(63) << "***           Access aborted...            ***";
		cout << endl << setw(63) << "**********************************************" << endl;
		system("pause>nul");

		return false;

	}
}
int studentPassword(Student tableStudent[], int SIZE)
{
	cout << "\n\t\Please inter your name: ";
	string findname = csLetter();
	string findpassword = "";
	cout << "\n\t\Please inter your password: ";
	getline(cin, findpassword);

	for (int i = 0; i < SIZE; i++)
	{
		if ((tableStudent[i].first_Name == findname) && (tableStudent[i].password == findpassword))
		{
			return i;
		}
	}

	return -1;


}


void initial(Student tableStudent[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		tableStudent[i].student_ID = 0;
		tableStudent[i].first_Name = "-";
		tableStudent[i].last_Name = "-";
		tableStudent[i].project_Grade = 0;
		tableStudent[i].midterm_Exam_Grade = 0;
		tableStudent[i].final_Exam_Grade = 0;
		tableStudent[i].password = "";
		tableStudent[i].finalResult = 0;
		tableStudent[i].courseName = "-";
		tableStudent[i].courseNumber = "000-000-00";
		tableStudent[i].group = "0000";
	}


}
int Sign_up(Student tableStudent[], int SIZE_, Teacher tableTeacher[], int teachersize, int  counter)  //singUp
{
	system("cls");
	cout << endl << setw(24) << "1.2 Sign up students ";
	cout << endl << setw(25) << "======================\n";

	bool loopcondition = true;

	do
	{
		loopcondition = true;
		tableStudent[counter].student_ID = getValidStudentId(tableStudent, counter);



		cout << endl << setw(28) << "Please Insert first_Name : ";
		tableStudent[counter].first_Name = csLetter();




		cout << endl << setw(28) << "Please Insert last_Name : ";
		tableStudent[counter].last_Name = csLetter();


		cout << endl << setw(27) << "Please Insert password :  ";
		getline(cin, tableStudent[counter].password);
		Display_table_Teacher(tableTeacher, teachersize);
		cout << setw(66) << "===============================================================";
		bool miniloop = true;
		do
		{
			miniloop = true;
			cout << endl << setw(30) << "Please enter your choice (1 ~ 4):  ";
			int choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 1)
			{
				tableStudent[counter].courseNumber = "420-P16-AS";
				tableStudent[counter].courseName = "Structured Programming";
				tableStudent[counter].group = "7148";
				cout << "\n\t\t*******************************************";
				cout << "\n\t\t*** Until now you registed " << counter + 1 << " student(s) ***\n";
				cout << "\t\t*******************************************\n\n";
				miniloop = false;
			}
			else if (choice == 2)
			{
				tableStudent[counter].courseNumber = "420-P16-AS";
				tableStudent[counter].courseName = "Structured Programming";
				tableStudent[counter].group = "7150";
				cout << "\n\t\t*******************************************";
				cout << "\n\t\t*** Until now you registed " << counter + 1 << " student(s) ***\n";
				cout << "\t\t*******************************************\n\n";
				miniloop = false;
			}
			else if (choice == 3)
			{
				tableStudent[counter].courseNumber = "420-P16-AS";
				tableStudent[counter].courseName = "Introduction a la programmation structuree";
				tableStudent[counter].group = "7151";
				cout << "\n\t\t*******************************************";
				cout << "\n\t\t*** Until now you registed " << counter + 1 << " student(s) ***\n";
				cout << "\t\t*******************************************\n\n";
				miniloop = false;
			}
			else if (choice == 4)
			{
				tableStudent[counter].courseNumber = "420-P34-AS";
				tableStudent[counter].courseName = "Advanced Object Programming";
				tableStudent[counter].group = "7256";
				cout << "\n\t\t*******************************************";
				cout << "\n\t\t*** Until now you registed " << counter + 1 << " student(s) ***\n";
				cout << "\t\t*******************************************\n\n";
				miniloop = false;
			}
			else
			{
				cout << "Please choose the correct number ";
				counter--;
				system("pause>null");
			}

			counter++;
		} while (miniloop);

		cout << setw(54) << "Do you want add another student information? (y/n) ";
		string answer = " ";
		getline(cin, answer);

		if ((answer == "Y") || (answer == "Yes") || (answer == "y") || (answer == "yes") || (answer == "YES"))
		{
			loopcondition = true;
		}
		else
		{
			loopcondition = false;
		}

	} while (loopcondition == true);

	return counter;
}


void sorting(Student tableStudent[], int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (tableStudent[i].student_ID>tableStudent[j].student_ID)
			{
				Student temp = tableStudent[i];
				tableStudent[i] = tableStudent[j];
				tableStudent[j] = temp;
			}
		}
	}



}
void grade(Student tableStudent[], int SIZE)
{
	system("cls");
	cout << "\n\t1.3 Enter students’ grades for a given course";
	cout << "\n\t===============================================\n\t";
	bool loopcondition = true;
	do
	{
		int findID;
		cout << setw(4) << "Please enter the ID number of student: ";
		cin >> findID;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		int indexValid = findvalidID(tableStudent, SIZE, findID);
		if (indexValid != -1)
		{
			cout << "\n\tPlease Insert project_Grade: ";
			tableStudent[indexValid].project_Grade = validGrade();


			//cin >> tableStudent[indexValid].project_Grade;
			//cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\tPlease Insert midterm_Exam_Grade: ";
			tableStudent[indexValid].midterm_Exam_Grade = validGrade();

			//cin >> tableStudent[indexValid].midterm_Exam_Grade;
			//cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\tPlease Insert final_Exam_Grade: ";
			tableStudent[indexValid].final_Exam_Grade = validGrade();
			//cin >> tableStudent[indexValid].final_Exam_Grade;
			//cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			tableStudent[indexValid].finalResult = ((tableStudent[indexValid].project_Grade*0.3) + (tableStudent[indexValid].midterm_Exam_Grade*0.3) + (tableStudent[indexValid].final_Exam_Grade*0.4));

		}
		else
		{
			cout << "\n\n\tPlease enter the correct ID student:  \n";
		}

		cout << "\n\tDo you want to countinue? ( y / n ) ";
		string answer = " ";
		getline(cin, answer);

		if ((answer == "Y") || (answer == "Yes") || (answer == "y") || (answer == "yes") || (answer == "YES"))
		{
			loopcondition = true;
		}
		else
		{
			loopcondition = false;
		}
	} while (loopcondition == true);
}


void validationNumber(int *number)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\tWarning!!! Please Enter a NUMBER ";
		*number = 0;
		system("pause>>nul");
		break;
	}


	
}
int getValidStudentId(Student tableStudent[], int counter)
{
	do
	{
		cout << endl << setw(29) << "Please Insert student_ID ] :";
		int temp = 0;

		cin >> temp;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (temp >= 1000000 && temp <= 9999999)
		{
			int condi = findvalidID(tableStudent, counter, temp);
			if (condi == -1)
			{
				return temp;
			}

			else
			{
				cout << "\n\t This ID has been used with the other student. ";
			}

		}
		else
		{
			cout << endl << setw(60) << "**********************************************";
			cout << endl << setw(60) << "***       Please enter 7 digit number      ***";
			cout << endl << setw(60) << "**********************************************";
		}
	} while (true);
}


void displayefunction(Student tableStudent[SIZE], int SIZE)
{
	system("cls");
	cout << "\n\n";
	cout << "+==============================================================================+";
	cout << "|                                    DISPLAY                                   |";
	cout << "+==============================================================================+" << endl;
	cout << " " << left << setw(9) << "ID" << left << setw(18) << "F&L Name" << left << setw(15) << "Course-Number" << left << setw(7) << "group" << left << setw(6) << "proj" << left << setw(5) << "mid" << left << setw(10) << "fin-Exam" << left << setw(8) << "Result" << "\n";
	cout << " " << left << setw(9) << "=======" << left << setw(18) << "================" << left << setw(15) << "=============" << left << setw(7) << "=====" << left << setw(6) << "====" << left << setw(5) << "===" << left << setw(10) << "========" << left << setw(8) << "======" << "\n";
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << " " << left << setw(9) << tableStudent[i].student_ID << left << setw(18) << tableStudent[i].first_Name + "-" + tableStudent[i].last_Name << left << setw(15) << tableStudent[i].courseNumber << left << setw(7) << tableStudent[i].group << left << setw(6) << tableStudent[i].project_Grade << left << setw(5) << tableStudent[i].midterm_Exam_Grade << left << setw(10) << tableStudent[i].final_Exam_Grade << left << setw(8) << tableStudent[i].finalResult << "\n";
		}

	}




}
void DisplaybyID(Student tableStudent[], int index)
{
	system("cls");
	cout << "\n\n";
	cout << "+==============================================================================+";
	cout << "|                                    DISPLAY                                   |";
	cout << "+==============================================================================+" << endl;
	cout << " " << left << setw(9) << "ID" << left << setw(18) << "F&L Name" << left << setw(15) << "Course-Number" << left << setw(7) << "group" << left << setw(6) << "proj" << left << setw(5) << "mid" << left << setw(10) << "fin-Exam" << left << setw(8) << "Result" << "\n";

	cout << " " << left << setw(9) << "=======" << left << setw(18) << "================" << left << setw(15) << "=============" << left << setw(7) << "=====" << left << setw(6) << "====" << left << setw(5) << "===" << left << setw(10) << "========" << left << setw(8) << "======" << "\n";

	cout << " " << left << setw(9) << tableStudent[index].student_ID << left << setw(18) << tableStudent[index].first_Name + "-" + tableStudent[index].last_Name << left << setw(15) << tableStudent[index].courseNumber << left << setw(7) << tableStudent[index].group << left << setw(6) << tableStudent[index].project_Grade << left << setw(5) << tableStudent[index].midterm_Exam_Grade << left << setw(10) << tableStudent[index].final_Exam_Grade << left << setw(8) << tableStudent[index].finalResult << "\n";
}
void Display_table_Teacher(Teacher tableTeacher[], int teachersize)
{
	cout << setw(66) << "===============================================================";
	cout << "\n\n";
	cout << left << setw(16) << "  course_Number";
	cout << left << setw(43) << " course_Title";
	cout << right << setw(6) << "group";

	cout << "\n";
	cout << left << setw(16) << "  -------------";
	cout << left << setw(43) << " ------------";
	cout << right << setw(6) << "-----" << endl;
	for (int i = 0; i < 4; i++)
	{
		string cn;
		cn.append("  ");
		cn.append(std::to_string(i + 1));
		cn.append(") ");
		cn.append(tableTeacher[i].course_Number);
		cout << left << setw(16) << cn;
		cout << left << setw(43) << " " + tableTeacher[i].course_Title;
		cout << right << setw(6) << tableTeacher[i].group << endl;
	}


}


int findvalidFnamewithoutmessage(Student tableStudent[], int SIZE, string lookid, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (tableStudent[i].first_Name == lookid)
		{

			return i;
		}
		else
		{

			return -1;
		}
	}






}
int findvalidLnamewithoutmessage(Student tableStudent[], int SIZE, string lookid, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (tableStudent[i].last_Name == lookid)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}


}
int findvalidLname(Student tableStudent[], int SIZE, string lookid, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (tableStudent[i].last_Name == lookid)
		{
			cout << endl << setw(60) << "**********************************************";
			cout << endl << setw(60) << "***          Last name has founded         ***";
			cout << endl << setw(60) << "**********************************************";
			cout << endl;
			return i;
		}
		else
		{
			cout << endl << setw(60) << "**********************************************";
			cout << endl << setw(60) << "***        Last name has not founded       ***";
			cout << endl << setw(60) << "**********************************************";
			cout << endl;
			cout << "\n\tPress any key to countinue " << endl;
			system("pause>>nul");
			return -1;
		}
	}


}
int findvalidFname(Student tableStudent[], int SIZE, string lookid, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (tableStudent[i].first_Name == lookid)
		{
			cout << endl << setw(60) << "**********************************************";
			cout << endl << setw(60) << "***         First name has founded         ***";
			cout << endl << setw(60) << "**********************************************";
			cout << endl;
			return i;
		}
		else
		{
			cout << endl << setw(60) << "**********************************************";
			cout << endl << setw(60) << "***       First name has not founded       ***";
			cout << endl << setw(60) << "**********************************************";
			cout << endl;
			cout << "\n\tPress any key to countinue " << endl;
			system("pause>>nul");
			return -1;
		}
	}


}
int findvalidID(Student tableStudent[], int SIZE, int id)
{
	
	
	for (int i = 0; i < SIZE; i++)
	{
		if (id == tableStudent[i].student_ID)
		{
			return i;
			break;
		}
	}

	//cout << "ID is not valide";
	return -1;
}
int validGrade()
{
	do
	{
		int temp = -1;
		cin >> temp;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if ((temp >= 0) && (temp <= 100))
		{
			return temp;
		}
		cout << "\n\n\tPlease enter the number between 0-100 \n\t";
	} while (true);

}


void welcomepage()
{
	cout << endl << endl << endl << endl;
	cout  << "**     **    **  *******  **       **          **       **          **  *******";
	cout  << "**    ****   **  **       **    **    **    **    **    ***        ***  **     ";
	cout  << " **  ** **  **   **       **  **          **        **  ****      ****  **     ";
	cout  << " **  ** **  **   *******  **  **          **        **  ** **    ** **  *******";
	cout  << "  ****   ****    **       **  **          **        **  **  **  **  **  **     ";
	cout  << "  ****   ****    **       **    **    **    **    **    **   ****   **  **     ";
	cout  << "   **     **     *******  ******   **          **       **    **    **  *******";
	cout << endl << endl << endl << endl << endl << endl << endl;
	

	cout << "\tPress any key to countinue ...";
	system("pause>>nul");
}
string csLetter()
{
	string temp = "";
	getline(cin, temp);
	temp[0] = toupper(temp[0]);
	for (int i = 1; i < temp.length(); i++)
	{
		temp[i] = tolower(temp[i]);
	}
	return temp;
}
