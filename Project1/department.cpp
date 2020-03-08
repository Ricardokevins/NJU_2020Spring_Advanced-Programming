#include"department.h"

void department::file_out()
{
	string file_path="cache/"+department_name;
	student_file_out(file_path);
	course_file_out(file_path);
}

void department::student_file_out(string file)
{
	string file_path=file+"/student.txt";
	fstream myoperate;
	myoperate.open(file_path.c_str(), ofstream::out);
	if (myoperate.fail())
	{
		cout << "文件导出失败!!!" << endl;
		Sleep(2000);
		return;
	}
	//cout<<student_list.size()<<endl;
	for(int i(0);i<student_list.size();i++)
	{
		myoperate << student_list[i].student_ID << " ";
		//cout<<student_list[i].student_ID << endl;
		myoperate << student_list[i].class_ID << " ";
		myoperate << student_list[i].student_name << " ";
		myoperate << student_list[i].department_name << " ";
		myoperate <<endl;
	}
	return;
}

void department::course_file_out(string file)
{
	string file_path=file+"/course.txt";
	fstream myoperate;
	myoperate.open(file_path.c_str(), ofstream::out);
	if (myoperate.fail())
	{
		cout << "文件导出失败!!!" << endl;
		Sleep(2000);
		return;
	}
	for(int i(0);i<course_list.size();i++)
	{
		myoperate << "begin"<<endl;
		myoperate << course_list[i].course_name << endl;
		//cout<<"size "<<course_list[i].all_student_ID.size()<<endl;
		for(int j(0);j<course_list[i].all_student_ID.size();j++)
		{
			myoperate << course_list[i].all_student_ID[j]<<" "<<course_list[i].score[j]<<endl;
		}
		myoperate <<"end"<<endl;
	}
	return;
}
	