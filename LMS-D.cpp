#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstddef>
using namespace std;

// Global Variables

	int counterList[1000]={0}, n = 0 , p = 0 , s = 0 , i ;

// Following Functions are used in the Program
bool ifalpha(char a);

bool ifdig(char b);

bool isValidcodeList(string c);

bool isValidcrtHrsListours(int d);

bool isValidSemester(int e);

bool isValidnameList(string f);

bool isValidRegistrationNumber(string regNo);

bool isValidStudentName(string studentName);

int scan_array(string arr[],string element,int size);

int scan2d_array(string arr[][20],string element,int size);

void ViewSemesterCourses(string codeList[], int crtHrsList[], int semList[], string nameList[], int sem);

void addStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo);

void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo);

void deleteStudent( string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string regNo);

void registerCourse(string stdRegNoList[], string stdCourseList[][20], string codeList[], string regNo, string courseCode);

void unRegisterCourse(string stdRegNoList[],string stdCourseList[][20],string regNo,string courseCode);

void ViewAllStudents(string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string codeList[], int crtHrsList[], int semList[], string nameList[]);

void ViewStdCourses(string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string codeList[], int crtHrsList[], int semList[], string nameList[]);

void ViewCourses(string codeList[], int crtHrsList[], int semList[], string nameList[]);

void DeleteCourse(string codeList[], int crtHrsList[], int semList[], string nameList[], string stdCourseList[][20], string courseCode);

void EditCourse(string codeList[], int crtHrsList[], int semList[], string nameList[],string courseCode,int crdHrs,int semester,string courseName);

void AddCourse(string codeList[], int crtHrsList[], int semList[], string nameList[],string courseCode,int crdHrs,int semester,string courseName);

bool saveCourses(string codeList[], int crtHrsList[], int semList[], string nameList[]);

bool saveStudents(string stdRegNoList[], string stdNamesList[], string StdCourseList[][20]);

bool loadCourses(string codeList[], int crtHrsList[], int semList[], string nameList[]);

bool LoadStudents(string stdRegNoList[], string stdNamesList[], string stdCourseList[][20]);

bool loadUsers(string usersList[] , string passwordsList[]);

bool isValidID(string usersList[] , string passwordsList[]);

bool StdLogin(string stdRegNoList[], string stdNamesList[]);


//******************************************************************************************************************************************************

int main()
{
	// Variables
	string codeList[100], nameList[100], usersList[100], passwordsList[100] ;
	string stdNamesList[1000], stdRegNoList[1000], stdCourseList[1000][20];
	int semList[100], crtHrsList[100];
	string courseCode, courseName, studentName, regNo ;
	int crdHrs, semester, f, a, option;
	
	/////////////////////////////////////////////////////////////////////////
	
	if(LoadStudents(stdRegNoList, stdNamesList, stdCourseList))
		cout<<"Students are successfully loaded.\n\n";
	else
		cout<<"There are no students present previously in file.\n\n";
	if(loadCourses( codeList,  crtHrsList,  semList,  nameList))
		cout<<"Courses are successfully loaded.\n\n";
	else
		cout<<"There are no courses present previously in file.\n\n";
	while(true)
	{		
	cout << "Choose the option for Login\n";
	cout << "1     for Admin\n";
	cout << "2     for Student\n";
	cout << "Enter option: ";
	cin>>option;
		if(cin.peek()!='\n')
			{				
				cin.clear();
				cin.ignore(200,'\n');
				cout<<"You gave wrong input.\n";
				option=-1;		
			}
	if(option==1)
	{
	if(loadUsers( usersList , passwordsList))
	{
		do
		{
		cout<<"\n";
		cout << "** Welcome to University Learning Management System **\n";
		cout << "Dear User, current software is intended for authorized users only.\n";
		cout <<"Login to the system to get access.";
		
		if(isValidID( usersList , passwordsList))
		{
			cout<<"You have successfully logged into the system\n\n";			
			do
			{		
			cout << "choose the following option\n";
			cout << "1     Add Course\n";
			cout << "2     Update Course\n";
			cout << "3     Delete Course\n";
			cout << "4     View All Course\n";
			cout << "5     View Courses of a Semester\n";
			cout << "6     Add New Student\n";
			cout << "7     Update Student\n";
			cout << "8     Delete Student\n";
			cout << "9     View All Students\n";
			cout << "10    Register the course for student\n";
			cout << "11    Unregister the course for student\n";
			cout << "12    Logout of the system\n";
			cout << "13    Exit Program\n\n";
			cout<<"-----------------------\n";
			cout<<"Choose the option: ";
			cin >> option;
			cout<<"-----------------------\n";
			if(cin.peek()!='\n')
			{				
				cin.clear();
				cin.ignore(200,'\n');
				cout<<"You gave wrong input.\n\n";
				option=-1;		
			}		
			switch (option)
			{
			case -1:
				{
					break;
				}
			case 1:
				{
				cout << "Now Enter the details of course: ";
				cin >> courseCode >> crdHrs >> semester;
				cin.ignore('\n', ' ');
				getline(cin, courseName);
				 f=0;
				if (isValidcodeList( courseCode ))
				{
					a=scan_array(codeList,courseCode,n);
					if(a==-1)
						f++;
					else
						cout<<"This course with same code is already present\n\n";
				}
				else
					cout << "Your course code is not valid\n\n";
	
				if (isValidcrtHrsListours( crdHrs ))
				{
					f++;
				}
				else
					cout << "Credit hours you entered is incorrect\n\n";
		
				if (isValidSemester( semester ))
				{
					f++;
				}
				else
					cout << "Semester numer is incorrect\n\n";
				
				if (isValidnameList(courseName))
				{
					f++;
				}
				else
					cout << "Course Name is incorrect\n\n";
					
				if(f==4)
					AddCourse(codeList, crtHrsList, semList, nameList, courseCode, crdHrs, semester, courseName);
				else
					cout<<"Enter valid details\n\n";
				cin.clear();

				break;
				}
			case 2:
				{
				 a=0;
				string course;
				cout << "Enter the course code to edit: ";
				cin >> course;
				for ( i = 0; i < n; i++)
				{
					f=0;
					if (course == codeList[i])
					{
						cout << "Enter the details of new course: ";
						cin >> courseCode >> crdHrs >> semester;
						cin.ignore('\n', ' ');
						getline(cin, courseName);
						if ( courseCode == codeList[i])
						{
							f++;
						}
						else
							cout << "Your course code did not match the old one.\n\n";
	
						if (isValidcrtHrsListours( crdHrs ))
						{
							f++;
						}
						else
							cout << "New Credit hours you entered is incorrect.\n\n";
			
						if (isValidSemester( semester ))
						{
							f++;
						}
						else
							cout << "New Semester numer is incorrect.\n\n";
					
						if (isValidnameList(courseName))
						{
							f++;
						}
						else
							cout << "New Course Name is incorrect.\n\n";
						
						if(f==4)
							EditCourse( codeList,  crtHrsList,  semList,  nameList, courseCode, crdHrs, semester, courseName);

						else
							cout<<"Enter valid details.\n\n";
					}
						else
							a++;
				}
						if (a == n)
							cout << "\nCourse Code does not exist.\n\n";
					cout<<"Hit Enter";
					cin.clear();
					cin.ignore(15, '\n');
					break;
				}

			case 3:
				{
					 a=0;
				cout << "Enter the course code to delete: ";
				cin >> courseCode;
				for ( i = 0; i < n; i++)
				{
					a=i;
					if (courseCode == codeList[i])
						DeleteCourse(codeList, crtHrsList, semList, nameList, stdCourseList, courseCode);
					else
						f++;
				}
				if (f ==a+1 )
				{
					cout << "\nCourse Code you entered does not exist.\n\n";}
				break;
				}
			case 4:
				{
				cout << left << setw(15) << "Course Code" << setw(50) << "Name" << setw(15) << "Credit Hours" << setw(15) << "Semester Number" << endl;
				if(n==0)
					cout<<"\nNO courses are present.\n\n";
				else
					ViewCourses(codeList, crtHrsList, semList, nameList);

				break;
				}
			case 5:
				{
				cout << "Enter the semester: ";
				cin >> semester;
				if(cin.peek()!='\n')
				{				
					cin.clear();
					cin.ignore(200,'\n');
					cout<<"You gave wrong input.\n";
					option=-1;		
				}
				if(n==0)
					cout<<"\nNO courses are present.\n\n";
				else
					ViewSemesterCourses(codeList, crtHrsList, semList, nameList, semester);	
				break;
				}
			case 6:
				{
					f=0;
				cout<<"Enter details of Students: ";
				cin>>regNo;
				cin.ignore('\n',' ');
				getline(cin, studentName);
				if(isValidRegistrationNumber(regNo))
				{
					 a=scan_array(stdRegNoList,regNo,s);
					 if(a==-1)
					 	f++;
					else
						cout<<"There is already a Student with the same Registration Number.\n";
					}	
				else
					cout<<"Registration Number is not correct.\n";
				if( isValidStudentName(studentName))
					f++;
				else
					cout<<"Name of the student is not correctly Entered\n";
					
				if(f==2)
				{
					addStudent( stdNamesList, stdRegNoList, studentName, regNo);
				}
				else
					cout<<"Enter Valid details.\n\n";
				break;
				}
			case 7:
				{
					 a=0;
				string RegNum;
				cout<<"Enter registration Number of the student to edit: ";
				cin>>RegNum;
				for(i=0;i<s;i++)
				{
					f=0;
					if(RegNum==stdRegNoList[i])
					{
						cout<<"Enter details of Student: ";
						cin>>regNo;
						cin.ignore('\n',' ');
						getline(cin, studentName);
						if(regNo==stdRegNoList[i])
							f++;
						else
							cout<<"Registration Number does not match the previous one.\n";
						if(isValidStudentName(studentName))
							f++;
						else
							cout<<"Name of the student is not correctly Entered\n";
						if(f==2)
							updateStudent( stdNamesList, stdRegNoList, studentName, regNo);
						else
							cout<<"Enter valid details.\n\n";			
					}
					else
						a++;
				}
				if(a==s)
					cout<<"Student with given Registion Number does not exist.\n\n";
				break;
				}
			case 8:
				{
					f=0;
					cout<<"Enter registration Number of the student to delete: ";
					cin>>regNo;
					for(i=0;i<s;i++)
					{
						a=i;
						if(regNo==stdRegNoList[i])
							deleteStudent( stdNamesList, stdRegNoList, stdCourseList, regNo);
						else
							f++;
					}
					if(f==a+1)
						cout<<"Student with given Registion Number does not exist.\n\n";
				break;
				}
			case 9:
				{
					ViewAllStudents(stdNamesList, stdRegNoList, stdCourseList, codeList, crtHrsList, semList, nameList);

					break;
				}
			case 10:
				{
					a=0;
					int b=0;
					cout<<"Enter registration Number of the student for course registration: \n";
					cin>>regNo;
					cout<<"Enter Course Code to register: ";
					cin>>courseCode;
					for(i=0;i<s;i++)
					{			
						if(regNo==stdRegNoList[i])
						{										
							f=0;
							for(int j=0;j<n;j++)
							{							
								if(courseCode==codeList[j])
								{
									int b = scan2d_array( stdCourseList,courseCode,counterList[i]);
									if(b==-1)
									{
										registerCourse( stdRegNoList, stdCourseList, codeList, regNo, courseCode);
										a++;
									}																			
									else
									cout<<"This Course is already registered against this Registration number.\n";
								}									
								else
									f++;
							}
							if(f==n)
							cout<<"Course code you entered does not exist.\n";
						}
						else
							b++;
					}
					if(b==s)
						cout<<"No student exists with this registration number.\n";	
					if(a==1)
						cout<<"\n";	
					else
						cout<<"Enter valid details.\n\n";
					break;
				}
			case 11:
				{
					a=0;
					int b=0;
					cout<<"Enter registration Number of the student for Unregistration of course: \n";
					cin>>regNo;
					cout<<"Enter Course Code to Unregister: ";
					cin>>courseCode;
					for(i=0;i<s;i++)
					{						
						if(regNo==stdRegNoList[i])
						{																								
									unRegisterCourse( stdRegNoList , stdCourseList, regNo, courseCode);
									
									a++;
						}
						else
							b++;
					}																	
					if(b==s)
						cout<<"No student exists with this registration number.";	
					if(a!=1)
						cout<<"Enter valid details.\n\n";
				break;	
				}
			case 12:
				cout<<"You have successfully logged out.\n\n";
				break;
			case 13:
				{
				if(saveCourses(  codeList, crtHrsList,  semList,  nameList ))
					cout<<"Courses are saved successfully.\n\n";
				else
					cout<<"Courses are not saved OR you have not enterd any Courses.\n\n";
				if(saveStudents( stdRegNoList, stdNamesList, stdCourseList))
					cout<<"Students are saved Successfully.\n\n";
				else
					cout<<"Students are not saved or not Added yet.\n\n ";			
				cout<<"\nProgram Exited.\n\n";
				cout<<"\t\t\tMade By ABDULLAH SALEEM";
				break;
				}		
			default:
				{
					cout << "\nYour input is invalid.\n\n";
					break;				
				}
			}
			}while(option != 12 && option != 13);
			}
				else
				{
					cout<<"Dear User, Username/password is incorrect. Enter the\n";
					cout<<"username/password again to get access to the system\n";
				}
		}while(option != 13);	
	}
	else
		cout<<"Sorry, we are unable to run the program, as user data does not exist.\n\n";
	}
	else if(option==2)
	{
	if(s==0)
		cout<<"There are no students present yet.\n";
	else
	{
		do
		{		
			cout<<"\n";
			cout << "** Welcome to University Learning Management System **\n";
			cout << "Dear User, current software is intended for authorized users only.\n";
			cout <<"Login to the system to get access.\n";
		if( StdLogin(stdRegNoList, stdNamesList))
		{	
			cout << "Enter 1 to view registered course\n";
			cout << "Enter 2 to logout of the system\n";
			cout << "Enter 3 to exit\n";
			do
			{
				cout << "---------------------\n";
				cout << "Choose option: ";
				cin >> option;
				cout << "---------------------\n";
				if(cin.peek()!='\n')
				{				
					cin.clear();
					cin.ignore(200,'\n');
					cout<<"You gave wrong input.\n\n";
					option=-1;		
				}
				switch (option)
				{
					case -1:
						break;
					case 1:
						cout<<"Student Name: ";
						cout<<stdNamesList[i]<<endl;
						cout<<"Registration No: ";
						cout<<stdRegNoList[i]<<endl;
						ViewStdCourses( stdRegNoList, stdNamesList, stdCourseList, codeList, crtHrsList, semList, nameList);
						break;
					case 2:
						cout << "You have successfully Logged out\n\n";
						break;
					case 3:
						cout << "Program Exited Successfully.\n\n";
						break;
					default:
						cout << "\nYour input is invalid.\n\n";
						break;
				}
			}while(option!=3 && option!=2);
		}
		else
			cout << "Registration number or password is invalid.\n\n";
		}
		while(option!=3);
		}}
		else
			cout << "Your input is invalid.\n\n";
	}
	return 0;
}

//*****************************************************************************************************************************************************************

// Function for checking upper case alphabet

bool ifalpha(char a)
{
	if ((a >= 'A' && a <= 'Z'))
		return true;
	else
		return false;
}

// Function for checking if a character is digit

bool ifdig(char b)
{
	if (b >= '0' && b <= '9')
		return true;
	else
		return false;
}

// Function for validation of Course Code

bool isValidcodeList(string c)
{
	bool Code = false;
	if (c.size() == 5 && ifalpha(c[0]) && ifalpha(c[1]) && ifdig(c[2]) && ifdig(c[3]) && ifdig(c[4]))
	{

		Code = true;
	}
	return Code;
}

// Function for validation of Credit Hours

bool isValidcrtHrsListours(int d)
{
	if (d > 0 && d <= 3)
		return true;
	else
		return false;
}

// Function for validation of Semester Number

bool isValidSemester(int e)
{
	if (e <= 8 && e > 0)
		return true;
	else
		return false;
}

// Function for validation of Course Name

bool isValidnameList(string f)
{
	int b, a = 0, c = 0;
	for (int i = 0; f[i] != '\0'; i++)
	{
		b = i;
		if (f[i] == ' ')
			c++;
		if( isalpha(f[i])>0)
			a++;
	}
	if (c == f.size())
		return false;
	else if(a + c==f.size())
		return true;
	else
		return false;
}

// Function for Searching Element in array

int scan_array(string arr[],string element,int size)
{
	int b=-1;
	for(int j=0;j<size;j++)
	{
		if(element==arr[j])
			b=i;			
	}
	return b;
}

// Function for Searching Element in 2d array

int scan2d_array(string arr[][20],string element,int size)
{
	int b=-1;		
			for(int k=0;k<size;k++)
				if(element==arr[i][k])
					b=k;	
	return b;
}

// Function for Adding a Course

void AddCourse(string codeList[], int crtHrsList[], int semList[], string nameList[],string courseCode ,int crdHrs ,int semester ,string courseName )
{
				codeList[n] = courseCode;
				crtHrsList[n] = crdHrs;
				semList[n] = semester;
				nameList[n] = courseName;
				n++;
				cout << "Course is added successfully\n";
}

// Function for Editing previously added Course

void EditCourse(string codeList[], int crtHrsList[], int semList[], string nameList[],string courseCode,int crdHrs,int semester,string courseName)
{
		codeList[i] = courseCode;
		crtHrsList[i] = crdHrs;
		semList[i] = semester;
		nameList[i] = courseName;
		cout << "Course has been edited successfully.\n";
}

// Function for Deleting previously added course

void DeleteCourse(string codeList[], int crtHrsList[], int semList[], string nameList[],string stdCourseList[][20],string courseCode)
{
		for (int j = i; j < n - 1; j++)
		{
				codeList[j] = codeList[j + 1];
				semList[j] = semList[j + 1];
				crtHrsList[j] = crtHrsList[j + 1];
				nameList[j] = nameList[j + 1];
		}
			n = n - 1;
		for(int j=0;j<s;j++)			
		{
			for(int k=0;k<counterList[j];k++)
			{			
			if(courseCode==stdCourseList[j][k])
			{			
				for(int b=k;b<counterList[j]-1;b++)
				{
						
					 stdCourseList[j][b] = stdCourseList[j][b+1];
				}
				counterList[j]--;
			}
		}}
		cout << "Course has been deleted sucourseCodeessfully.\n\n";	
}

// Function for Viewing all the Courses Added

void ViewCourses(string codeList[], int crtHrsList[], int semList[], string nameList[])
{
	for ( i = 0; i < n; i++)
	{
		cout << left << setw(15) << codeList[i] << setw(50) << nameList[i] << setw(15) << crtHrsList[i] << setw(15) << semList[i] << endl;
	}
	cout<<"\n\n";
}

// Function for Viewing Specific Semester Courses

void ViewSemesterCourses(string codeList[], int crtHrsList[], int semList[], string nameList[], int semester)
{	
	int	f=0;
				cout << left << setw(15) << "Course Code" << setw(50) << "Name" << setw(15) << "Credit Hours" << endl;
				for ( i = 0; i < n; i++)
				{
					if (semester == semList[i])
						cout << left << setw(15) << codeList[i] << setw(50) << nameList[i] << setw(15) << crtHrsList[i] << endl;
					else
						f++;
				}
				if (f == n)
					cout << "\nNO course exists regarding to the given semester.\n\n";
				else
					cout << "\n\n";
}

// Function for Saving Courses in a file at the end of program

bool saveCourses(string codeList[], int crtHrsList[], int semList[], string nameList[])
{
	int a=0;
	ofstream file;
	file.open("Courses.txt");
	for(int i=0;i<n;i++)
	{
		file<<codeList[i]<<",";
		file<<nameList[i]<<",";
		file<<crtHrsList[i]<<",";
		file<<semList[i]<<endl;
		a++;
	}
	file.close();	
	if(a==n && a!=0)
		return true;
	else
		return false;
}

// Function for Loading the Saved Courses from the exact same file where they were saved

bool loadCourses(string codeList[], int crtHrsList[], int semList[], string nameList[])
{
	ifstream file;
	int crdHrs, semester;
	string data;
	file.open("Courses.txt");
	while(getline(file, data))
	{
		if(data.size()>=11)
		{		
			int i=0;
			while(data[i]!=',')
			{
				codeList[n]+=data[i];
				i++;
			}
			i++;
			while(data[i]!=',')
			{
				nameList[n]+=data[i];
				i++;
			}
			i++;
			crtHrsList[n]=data[i]%48;
			i++;
			semList[n]=data[i+1]%48;		
			n++;		
		}
	}
	file.close();
	if(n!= 0)
	{
		return true;
	}
	else
		return false;
}

// Function for Loading User IDs from file

bool loadUsers(string usersList[] , string passwordsList[])
{
	string data ;
	ifstream pass;
	pass.open("Users.txt");
	while(getline(pass , data))
	{		
		if(data.size()>=6)
		{
			 i=0;
			while(data[i]!=',')
			{
				usersList[p]+=data[i];
				i++;
			}
			i++;
			while(data[i]!='\0')
			{
				passwordsList[p]+=data[i];
				i++;
			}
			p++;
		}
	}
	pass.close();
	if(p!=0)
	return true;
	else
	return false;
}

// Function for validation of User ID

bool isValidID(string usersList[] , string passwordsList[])
{
	string  Username, Password;
	int f=0;
	cout<<"\nUsername: ";
	cin>>Username;
	cout<<"Password: ";
	cin>>Password;
	for(i=0;i<p;i++)
	{
		if(Username==usersList[i])
		{
			if(Password==passwordsList[i])
				f++;
		}
	}
	if(f==1)
		return true;
	else
		return false;	
}

// Function for validation of Student Name

bool isValidStudentName(string studentName)
{
	int b, a = 0, c = 0;
	for (int i = 0; studentName[i] != '\0'; i++)
	{
		b = i;
		if (studentName[i] == ' ')
			c++;
		if( isalpha(studentName[i])>0)
			a++;
	}
	if(a>=3)
	{
	if (c == studentName.size())
		return false;
	else if(a + c==studentName.size())
		return true;
	else
		return false;}
		else
		return false;
}

// Function for validation of Student`s Registratin Number

bool isValidRegistrationNumber(string regNo)
{
	bool flag = false;
	if(regNo.size()==11)
	{
			if(regNo[0]=='2' && regNo[1]=='0' && regNo[2]=='1' && ifdig(regNo[3]))
		{
				if(regNo[4]=='-' && regNo[5]=='C' && ifalpha(regNo[6]) && regNo[7]=='-')
			{
					if( regNo[8]>'0' && regNo[8]<='9' && ifdig(regNo[9]) && ifdig(regNo[10]))
					{
						flag = true;
					}
					else if((regNo[8]=='0' && regNo[9]=='0' && regNo[10]>'0' && regNo[10]<='9'))
						{
							flag = true;
						}
						else if((regNo[8]=='0' && regNo[9]>'0' && regNo[9]<='9' && ifdig(regNo[10])))
						flag = true;
				}}}	
		return flag;
}

// Function for Adding a new Student

void addStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo)
{
	stdNamesList[s]=studentName;
	stdRegNoList[s]=regNo;
	counterList[s]=0;
	
	s++;
	cout<<"Student has been added successfully.\n\n ";
}

// Function for Editing previously present Student`s details

void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo)
{
	stdNamesList[i]=studentName;
	stdRegNoList[i]=regNo;
	cout<<"Student has been edited successfully\n\n";
}

// Function for Deleting previously present Student

void deleteStudent( string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string regNo)
{
	for(int j=i;j<s-1;j++)
	{
		stdRegNoList[j]=stdRegNoList[j+1];
		stdNamesList[j]=stdNamesList[j+1];
		counterList[j]=counterList[j+1];	
		for(int k=0;k<=20;k++)
		{
			stdCourseList[j][k]=stdCourseList[j+1][k];
		}
	}
	s--;
	cout<<"Student is deleted successfully\n\n";
}

// Function for Registering a Student against a Course

void registerCourse(string stdRegNoList[], string stdCourseList[][20], string codeList[], string regNo, string courseCode)
{
	stdCourseList[i][counterList[i]]=courseCode;
	counterList[i]++;
	cout<<"Course is registered successfully\n\n";
}

// Function for Unregistering a Student from a Course

void unRegisterCourse(string stdRegNoList[] ,string stdCourseList[][20],string regNo,string courseCode)
{
	bool found=false;
	for(int j=0;j<counterList[i];j++)
	{
		if(courseCode==stdCourseList[i][j])
	{
		found=true;
			stdCourseList[i][j]=stdCourseList[i][j+1];		
	cout<<"Course is Unregistered successfully\n\n";
	}
	}
		if(found)		
		counterList[i]--;
		else
		cout<<"This course was not registered against this student.\n\n";
}

// Function for Viewing all students` details

void ViewAllStudents(string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string codeList[], int crtHrsList[], int semList[], string nameList[])
{
	int a;
	if(s==0)
		cout<<"No Students are Registered Yet.\n\n";
	else
	{
	
	for(int i=0;i<s;i++)
	{
		cout<<"Student Name: ";
		cout<<stdNamesList[i]<<endl;
		cout<<"Registration No: ";
		cout<<stdRegNoList[i]<<endl;
		cout << left << setw(15) << "Course Code" << setw(50) << "Name" << setw(15) << "Credit Hours" << setw(15) << "Semester Number" << endl;
		a=0;
		for(int j=0;j<counterList[i];j++)
		{			
				for(int k=0;k<n;k++)
				{
					if(stdCourseList[i][j]==codeList[k])
					{
						cout << left << setw(15) << codeList[k] << setw(50) << nameList[k] << setw(15) << crtHrsList[k] << setw(15) << semList[k] << endl;
					}	
				}						
		}
		if(counterList[i]==0)
			cout<<"\n\nNo course is registered against this student.\n\n";
		else
			cout<<"\n";
		
	}}
}

// Function for saving all Students` details to the file

bool saveStudents(string stdRegNoList[], string stdNamesList[], string stdCourseList[][20])
{
	bool save=false;
	ofstream file;
	file.open("Students.txt");
	for(i=0;i<s;i++)
	{
		file<<stdRegNoList[i]<<","<<stdNamesList[i]<<endl;
		for(int j=0;j<counterList[i];j++)
		{
			if(j<counterList[i]-1)
			file<<stdCourseList[i][j]<<",";
			else
			file<<stdCourseList[i][j];
		}
		file<<endl;
		save=true;
	}
	file.close();
	return save;
}

// Function for Loading the students from the exact same file where they were saved

bool LoadStudents(string stdRegNoList[], string stdNamesList[], string stdCourseList[][20])
{
	bool load=false;
	string data;
	ifstream file;
	file.open("Students.txt");
	while(!file.eof())
	{
		data="";
		getline(file, data);
		if(data.size()>=15)
		{
		
		int j;
		i=0;
		while(data[i]!=',')
		{
			stdRegNoList[s]+=data[i];
			i++;
		}
		i++;
		while(data[i]!='\0')
		{
			stdNamesList[s]+=data[i];
			i++;
		}
		counterList[s]=0;	
		data="";
		getline(file,data);				
		if(data.size()>=5)
		{			
			for(i=0;data[i]!='\0' && data[i]!='\n';i++)
			{			
				for( j=i;j<i+5 && data[j]!=',';j++)
				{
					stdCourseList[s][counterList[s]]+=data[j];					
				}
				
				i=j;
				if(isValidcodeList(stdCourseList[s][counterList[s]]))
					counterList[s]++;
				else
					stdCourseList[s][counterList[s]]="";
			}	
		}		
		s++;
		load=true;}
	}
	file.close();
	return load;
}

// Function for validation of Student ID

bool StdLogin(string stdRegNoList[], string stdNamesList[])
{
	string regNo, pass, name;
	int a;
	cout << "Enter registration Number: ";
	cin >> regNo;
	cout << "Enter Password: ";
	cin >> pass;
	for(int j=0;j<s;j++)
	{
		if(regNo==stdRegNoList[j])
		{
			name="";
			a=stdNamesList[j].size();
			for(int k=a-3;k<a;k++)
			{
				name+=stdNamesList[j][k];
			}			
			if(pass==name)
			{
				i=j;
				return true;
			}			
		}		
	}
	return false;
}

// Function for Viewing specific student`s Courses

void ViewStdCourses(string stdNamesList[], string stdRegNoList[], string stdCourseList[][20], string codeList[], int crtHrsList[], int semList[], string nameList[])
{
		if(counterList[i]==0)
			cout << "No Courses are registered yet.\n";
		else
		{
			cout << left << setw(15) << "Course Code" << setw(50) << "Name" << setw(15) << "Credit Hours" << setw(15) << "Semester Number" << endl;
			for(int j=0;j<counterList[i];j++)
			{
				for(int k=0;k<n;k++)
				{
					if(stdCourseList[i][j]==codeList[k])
					{
						cout << left << setw(15) << codeList[k] << setw(50) << nameList[k] << setw(15) << crtHrsList[k] << setw(15) << semList[k] << endl;
					}
				}
			}
		}
		cout<<endl;
}


