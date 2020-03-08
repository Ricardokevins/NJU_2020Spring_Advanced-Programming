#pragma once
#include"course.h"
#include"student.h"
#include<string>
#include<vector>
#include<iostream>
#include <fstream>
#include <sstream>
#include<iomanip>
#include <Windows.h>

using namespace std;
class department {
public:
	string department_name;
	vector<student> student_list;
	vector<course>course_list;
	void student_file_out(string file);
	void course_file_out(string file);
	void file_out();
};