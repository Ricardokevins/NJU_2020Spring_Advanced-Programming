#include"student.h"

int student::delete_course(int id)
{
	course_id.erase(course_id.begin()+id);
	return 1;
}

int student::add_course(int id)
{
	course_id.push_back(id);
	return 1;
}

int student::display_info()
{
	cout<<"ID："<<student_ID<<" 姓名："<<student_name<<" class："<<class_ID<<" 院系："<<department_name<<endl;
	return 0;
}