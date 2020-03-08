#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class course {
public:
	string course_name;
	vector<int>all_student_ID;
	vector<int>score;
	int delete_student(int ID);
	int adjust_score(int id,int score);
	int add_student(int id,int score);
	int show_infor();
};