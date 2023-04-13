
/*   ***************************** this program is written by M Amin Kiani *****************************   */
								   /* a system for student information. */


/* LIBRARIES : */
#include <iostream>
#include<stdio.h>      /* for remove() function & ...*/
#include <fstream>    /* for Work with files */
#include<string>     /* For string Arrays & getline(string) function */
#include<cstring>   /* For char string Arrays */


/* RULES : */
// ifstream for read
// ofstream for write 
// getline for 1 line of stream
// cin.get for sizeof User desired
// 1000 is number of students
// 20 is number of courses
// remove is for file content   &   system cls is for all exe screen
// using { } or not, It does not matter in execution or error of switch case
// 1.37cm go with [ /t ]
// go next line with [ /n ] or [ endl ]


/* GLOBAL INFO & DECLARATIONS :*/
using namespace std;

void Write_stu(string content, string fname, string lname);
string* Read_all_file();
string* Split(string content);

class Lesson              // subset of student class
{
public:
	string lessname;   // the name of each lesson
	string grade_constant;  // for change into double ( stod : string gradesss to double grade) 
	string unit_constant;  // for change into double ( stod : string unitsss to double unit )
	double grade;
	double unit;

};
/* [ why stod ? ] The desired number (grade & unit) is stored between the letter strings, so it must be of type string (gradesss & unitsss),
	but then we need to perform mathematical operations on it,so it must be of type number, in this way we use the conversion function (stod) */


class student
{
public:
	double average;
	double sumgrade = 0;
	double sumunit = 0;
	string name;
	string family;
	string id;
	Lesson all_stu_lesson_info[20];            // The list of lessons that can be taken with their details
									// class to class (Sliding fields)

};

void Write_course(Lesson grades);
void getloading();             // uses an calls the split function


string* reading = Read_all_file();
student stdlists[1000];
int counter_exist_student = 0;       // number of exist student
int lesson_split_counter = 0, course_counter[1000];  //counter of course loops


// start program ... 
int main()
{
	int menu, repeated = 0;    // menu is a case of switch so must be int
	double gradeh;            // sum grade of each course
	string check, file;      //  check is a conststant number of id cause id does not need to change!
	char checker;           // yes or no question char
	int counter2 = 0;

	cout << "                                                                                                                  \n";
	cout << " ________________________    ! Welcome to the University Student Information System !    ________________________ \n";
	cout << " __________________________                                                            __________________________ \n";
	cout << " ____________________________                 * Owner: Amin Kiani *                  ____________________________ \n";
	cout << "                                                                                                                  \n";

	// true means the program continues forever unless the user commands to exit with 0
	while (true)
	{
		cout << "Choose Your Desired Option :\n\n1-Student ID  \n2-Lesson Info \n3-Calculation and Show Average \n4-Save Information \n5-Load Data \n6-Show Information \n0-Exit \n\n*****************************\nEnter Your Option : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			system("cls");                                           // clear all before outputs
			cout << "                                                                                                                  \n";
			cout << "*(Adding Student Info)*\n\n";
			cout << "                                                                                                                  \n";
			cout << "Enter Student ID : ";                         // battle for id
			for (int i = counter_exist_student; i < 1000; i++)    // i = counter for not considering previous id when user choose case 1 after breaking this case
			{
				repeated = 0;
				cin >> check;                                  // for finding duplicates or adding new id
				for (int j = 0; j < 1000; j++)
				{
					if (stdlists[j].id == check)
					{
						repeated++;                        // existence of duplicate(s) so is for deny doing next if(flag==0) that adds id
					}
				}
				if (repeated == 0)                      // no duplicate
				{
					stdlists[i].id = check;
					course_counter[i] = 0;          // Initial value of numbers of courses of i om student
					counter_exist_student++;       // for not considering previous id

				}
				else                            // existence of duplicate(s) and  [ flag != 0 ]
				{
					system("cls");
					cout << "                                                                                                                  \n";
					cout << "     *Error!*\n Student is Available !\n\n\n";
					cout << " ----------------------------------------------------------------------------------------------------------------- \n";
					break;                  // go to for(   i++)

				}
				cout << "Enter First Name : ";
				cin >> stdlists[i].name;
				cout << "Enter Last Name : ";
				cin >> stdlists[i].family;
				cout << "                                                                                                                  \n";
				cout << "\n\nInfomations Added ! \n\n******** \n\n";
				cout << " ----------------------------------------------------------------------------------------------------------------- \n";
				break;               // break of 1000 loops
			}
			break;                 // break of each case => if you dont use them at the last of cases, all the cases run from case that has the constant of menu

		}
		case 2:
		{
			system("cls");
			cout << "                                                                                                                  \n";
			cout << "*(Adding Lesson Info)*\n\nEnter Student ID : ";
			cin >> check;
			for (int i = 0; i < 1000; i++)
			{
				if (stdlists[i].id == check)
				{
					cout << endl << "Name : " << stdlists[i].name << " " << stdlists[i].family << "\n\n";
					for (int j = course_counter[i]; j < 20; j++)                  // j = counter for not considering previous when user choose case 2
					{
						cout << "What is the name of the lesson? ";
						cin >> stdlists[i].all_stu_lesson_info[j].lessname;
						course_counter[i]++;                                  // go for next lesson adding
						cout << "Enter the grade obtained from the lesson : ";
						cin >> stdlists[i].all_stu_lesson_info[j].grade;
						cout << "Enter the number of course units : ";
						cin >> stdlists[i].all_stu_lesson_info[j].unit;

						cout << "                                                                                                                  \n";
						cout << " ----------------------------------------------------------------------------------------------------------------- \n";
						cout << "Lesson Added Successfully. Do you Want to Add Another Lesson ? (y or n) ";
						cin >> checker;
						cout << "                                                                                                                  \n";
						if (checker == 'n')
						{
							break;                                  // go out of lessons of i om student
						}
						else if (checker == 'y')
						{
							continue;                           // add new lesson in the next array cause we ++ course_counter
						}
						else
						{
							cout << "\n*Error! Input is not valid!*\n\n ";
							cout << " ----------------------------------------------------------------------------------------------------------------- \n";
							break;                        // go out of lessons of i om student
						}
					}
					break;                             // for aviod to not run Infinite loop of 1000,  after (checker != y)
				}
			}
			break;                                   // break of each case
		}
		case 3:
		{
			// similar to case 2
			system("cls");
			cout << "                                                                                                                  \n";
			cout << "*(Showing Student Average)*\n\nEnter Student ID : ";
			cin >> check;   // id
			for (int i = 0; i < 1000; i++)
			{
				for (int j = 0; j < course_counter[i]; j++)                     // until course_counter cause for avarage we need until that
				{
					gradeh = stdlists[i].all_stu_lesson_info[j].grade * stdlists[i].all_stu_lesson_info[j].unit;
					stdlists[i].sumgrade += gradeh;
					stdlists[i].sumunit += stdlists[i].all_stu_lesson_info[j].unit;
					stdlists[i].average = stdlists[i].sumgrade / stdlists[i].sumunit;
				}                                                          // calculate ave of all coureses of students!
				if (stdlists[i].id == check)
				{
					cout << endl << stdlists[i].name << " " << stdlists[i].family << "'s Average is : " << stdlists[i].average << "\n\n";
					break;                                            // break the hole loop
				}
				// else : continue seach for another that is the same as check
			}
			break;
		}
		case 4:
		{
			remove("H:\\database.txt");                                              // include stdio.h => delete the previous file if exists, to add new data (if you dont load the previous!)
			for (int i = 0; i < counter_exist_student; i++)
			{

				Write_stu(stdlists[i].id, stdlists[i].name, stdlists[i].family);  // writes are functions for Shorten and optimize main() lines that create(or edit) a file !
				for (int j = 0; j < course_counter[i]; j++)
				{
					Write_course(stdlists[i].all_stu_lesson_info[j]);                     // content of write_course Sticks to previous content of file (write_stu) in one line
				}
				ofstream sfile("H:\\database.txt", ios::app);                 // open the file again to Makes the content, move to the next line from now!
				sfile << endl;                                               // break each line that content of student details

			}
			system("cls");                                                // To delete messages that [[ may ]] already be on the screen
			cout << "                                                                                                                  \n";
			cout << "* Information Saved Successfully! *\n";
			cout << " ----------------------------------------------------------------------------------------------------------------- \n";
			break;
		}
		case 5:
		{
			getloading();
			system("cls");                                         //  To delete messages that [[ may ]] already be on the screen
			cout << "                                                                                                                  \n";
			cout << "* Data Loaded Successfully! * \n\n";
			cout << " ----------------------------------------------------------------------------------------------------------------- \n";
			counter_exist_student = counter_exist_student / 3;    // cause amount of [ : ] in 1 record is 3 ( from split() )! so we need this counter, same as before that!
			break;
		}
		case 6:
		{
			system("cls");
			cout << "-------------------------------------------------------------" << endl;
			for (int i = 0; i < counter_exist_student; i++)              // i+1 => means Student number row
			{
				cout << i + 1 << "-" << "ID : " << stdlists[i].id << "\t" << "Name : " << stdlists[i].name << "\t" << "Family : " << stdlists[i].family << endl;
				for (int j = 0; j < course_counter[i]; j++)
				{
					cout << "Lesson : " << stdlists[i].all_stu_lesson_info[j].lessname << "\t\t";
					cout << "Grade : " << stdlists[i].all_stu_lesson_info[j].grade << "\t\t";
					cout << "Unit : " << stdlists[i].all_stu_lesson_info[j].unit << endl;
					gradeh = stdlists[i].all_stu_lesson_info[j].grade * stdlists[i].all_stu_lesson_info[j].unit;
					stdlists[i].sumgrade += gradeh;
					stdlists[i].sumunit += stdlists[i].all_stu_lesson_info[j].unit;
					stdlists[i].average = stdlists[i].sumgrade / stdlists[i].sumunit;
				}
				if (course_counter[i] == 0)
				{
					cout << "No Course Information Entered For This Studnet ! " << endl;
				}
				else
				{
					cout << "The Student Average is : " << stdlists[i].average << endl;
				}
				cout << "-------------------------------------------------------------" << endl;
			}

			break;
		}
		case 0:
		{
			return 0;       // exit from program and close all !
			break;
		}
		default:          // if you dont use any cases, it runs as a 
			system("cls");
			cout << "                                                                                                                  \n";
			cout << " wrong! please try again... \n";
			cout << " ----------------------------------------------------------------------------------------------------------------- \n";
			break;
		}
	}
}


void Write_stu(string content, string fname, string lname)
{
	ofstream sfile("H:\\database.txt", ios::app);    // app means append : that Sticks new contents to the previous end, (instead of replacing the previous ones)
	sfile << content << ":" << fname << ":" << lname << ":";
	sfile.close();
}

void Write_course(Lesson grades)
{
	ofstream sfile("H:\\database.txt", ios::app);
	sfile << grades.lessname << "," << grades.grade << "@" << grades.unit << "@";
	sfile.close();
}

string* Read_all_file()
{
	static string inputs[1000];
	string input;
	ifstream sfile("H:\\database.txt", ios::app);
	int countering = 0;
	while (getline(sfile, input))             // getline() in every call gets 1 line of file that exist text(not empty lines) => so for all content of file we need [ while ] to repeat getting!
	{
		inputs[countering] = input;         // copy each line of file that on input => in the inputs 
		countering++;
	}                                     // when getline() gets all content lines => while loop ends!
	return inputs;                       // copy all line in inputs  => inputs go to string* reading                              
}

string* Split(string content)                                          // content is all of file that has each stu details to split in parts
{
	static string result[1000];                                     // must be static to not changing in all calls & recursive function
	char contentchars[100];                                         // cause for case aption(: , @) we need a char, not string!
	strcpy_s(contentchars, content.c_str());                       // strcpy just for char* so content is string that with c_str() changes to contentchars
	int contentlenght = content.length();                         // length is integer that count all char of a file
	int startindex = 0, counter2 = 0;
	for (int i = startindex; i < contentlenght; i++)
	{                                            // [counter2] at first is 0 => after each spin,  counter2 is ++ after Pour content in result[counter2]
		if (contentchars[i] == ':')
		{
			result[counter2++] = content.substr(startindex, i - startindex);    // i - startindex => is amount that move from startindex
			startindex = i + 1;
			counter_exist_student++;         // at last : it is = 3 => means the amount of [ : ] in 1 record is 3 !
		}
		if (contentchars[i] == ',')
		{
			result[counter2++] = content.substr(startindex, i - startindex);
			startindex = i + 1;
			lesson_split_counter++;    // count number of [ , ] that means of amount of lesson
		}
		if (contentchars[i] == '@')
		{
			result[counter2++] = (content.substr(startindex, i - startindex));
			startindex = i + 1;   
		}
	}
	return result;
}


void getloading()
{
	for (int i = 0; i < 1000; i++)
	{
		string* temp = Split(*(reading + i)); //reading + i =>to avoid print previous each line( A combination of several functions( split & readall ) => to split all info )
		student loading;
		loading.id = *(temp);                         // result[0 om]
		loading.name = *(temp + 1);                  // result[1 om]
		loading.family = *(temp + 2);               // result[2 om] 
		for (int j = 0; j < lesson_split_counter; j++)
		{
			loading.all_stu_lesson_info[j].lessname = *(temp + (j + 1) * 3);                                   // result[3 om]
			loading.all_stu_lesson_info[j].grade_constant = *(temp + ((j + 1) * 3) + 1);                      // result[4 om]
			loading.all_stu_lesson_info[j].grade = stod(loading.all_stu_lesson_info[j].grade_constant); //grade stucks in the strings of file, it must to be of their type, so then convert by [stod]           
			loading.all_stu_lesson_info[j].unit_constant = *(temp + ((j + 1) * 3) + 2);                     // result[5 om]
			loading.all_stu_lesson_info[j].unit = stod(loading.all_stu_lesson_info[j].unit_constant); //grade stucks in the strings of file, it must to be of their type, so then convert by [stod]
		}
		stdlists[i] = loading;
		course_counter[i] = lesson_split_counter;
		lesson_split_counter = 0;           // clear courses => cause we must go for next record that has different courses even more or less!

	}
}
