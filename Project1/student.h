#pragma once

#include<string>
#include<vector>
#include<iostream>
using namespace std;
class student {
public:	
	student(int a,string b,string c,int d){
	student_ID = a;
	student_name = b;
	department_name = c;
	class_ID = d;
}
	int add_course(int id);
	int delete_course(int id);
	int display_info();
	int student_ID;
	string student_name;
	string department_name;
	int class_ID;
	vector<int>course_id;
};
