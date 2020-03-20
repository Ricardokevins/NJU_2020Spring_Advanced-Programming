#pragma once
#include"course.h"
#include"student.h"
#include"department.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;


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
	int display_info();
	vector<student> student_file_in(string file);
	vector<course> course_file_in(string file);
	
};



