#include"base.h"
#include<iostream>
using namespace std;

int main()
{
	School b;
	//b.file_in();
	//vector<course>c=b.course_file_in("cache/¼ÆËã»úÏµ");

	//test of file_in system
	
	b.file_in();
	for(int i(0);i<b.my_school.size();i++)
	{
		cout<<b.my_school[i].department_name<<endl;
	}

	for(int i(0);i<b.my_school[0].student_list.size();i++)
	{
		b.my_school[0].student_list[i].display_info();
	}
	for(int i(0);i<b.my_school[0].course_list.size();i++)
	{
		b.my_school[0].course_list[i].show_infor();
	}

	b.insert_student();
	int a;
	cin>>a;
	return 0;
}