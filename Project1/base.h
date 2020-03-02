#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class student;

class course {
public:
	string course_name;
	vector<student>all_student;
	vector<int>score;
};

class student {
public:	
	student(int a,string b,string c,int d);
private:
	int student_ID;
	string student_name;
	string department_name;
	int class_ID;
	vector<int>course_id;
};

class School {
public:
	vector<student> student_list;
	vector<course>course_list;
	int insert_student();
	int search_student();

};
