#ifndef College_Program
#define College_Program
#include<iostream>
#include<string>
#include<iomanip> //manipolate setw
#include <conio.h> //password
#include <io.h>  //french
#include <fcntl.h> //french


// Declear constant for size of table
const int teachersize = 4;
const int SIZE = 5;

using namespace std;
// Declear struct
struct Student
{
	int student_ID;
	string first_Name;
	string last_Name;
	string courseNumber;
	string courseName;
	string group;
	//string coursetitle;
	int project_Grade;
	int midterm_Exam_Grade;
	int final_Exam_Grade;
	string password;
	int finalResult;
};
struct Teacher
{
	string course_Number;
	string course_Title;
	string group;
};

// Menu
int mainMenu();
int teacher_Menu();
int student_Menu();
int searchMenu();
int resultmenu();

// Password
int studentPassword(Student[], int);
bool teacherPassword();

// Initial of the table and take the information
void initial(Student[], int);
int Sign_up(Student[], int, Teacher[], int, int);

// Main operation in menu
void sorting(Student[],int);
void grade(Student[],int);
          
// Validation
void validationNumber(int*);
int getValidStudentId(Student[], int);

// Display
void displayefunction(Student[], int);
void DisplaybyID(Student[], int);
void Display_table_Teacher(Teacher[], int);

// Find Valid
int findvalidFnamewithoutmessage(Student[], int, string, int);
int findvalidLnamewithoutmessage(Student[], int, string, int);
int findvalidLname(Student[], int, string, int);
int findvalidFname(Student[], int, string, int);
int findvalidID(Student[], int, int);
int validGrade();

// Other
void welcomepage();
string csLetter();

#endif // !1

