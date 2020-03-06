#pragma once

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class student;
class School;
class course {
public:
	string course_name;
	vector<int>all_student_ID;
	vector<int>score;
};

class student {
public:	
	friend School;
	student(int a,string b,string c,int d);
	int display_infor();
private:
	int student_ID;
	string student_name;
	string department_name;
	int class_ID;
	vector<int>course_id;
};

class department {
public:
	string department_name;
	vector<student> student_list;
	vector<course>course_list;
};

class School {
public:
	vector<department>my_school;
	int insert_student();
	int delete_student();
	int search_student();
	int adjust_student();
	int file_out();
	int file_in();
	int show_menu();
	int my_run();
};



