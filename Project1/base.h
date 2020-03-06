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
	int show_infor();
};

class student {
public:	
	student(int a,string b,string c,int d){
	student_ID = a;
	student_name = b;
	department_name = c;
	class_ID = d;
}
	int display_info();
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
	void student_file_out(string file);
	void course_file_out(string file);
	void file_out();
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
	vector<student> student_file_in(string file);
	vector<course> course_file_in(string file);
	
};



