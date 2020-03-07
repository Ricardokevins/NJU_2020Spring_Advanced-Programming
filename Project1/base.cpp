#include<iostream>
#include<vector>

#include <fstream>
#include <sstream>
#include <Windows.h>
#include<iomanip>
#include"base.h"
using namespace std;

int course::show_infor()
{
	cout<<course_name<<endl;
	for(int j(0);j<all_student_ID.size();j++)
	{
		cout<<all_student_ID[j]<<" "<<score[j]<<endl;
	}
}

int School::show_menu()
{
	while (1)
	{
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t＋==============================＋\n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t｜  1->增加学生                 \n");
		printf("\t\t\t｜  2->删除学生               \n");
		printf("\t\t\t｜  2->查找学生               \n");
		printf("\t\t\t｜  2->修改学生              \n");
		printf("\t\t\t｜  2->显示学生               \n");
		printf("\t\t\t｜  6->显示学生               \n");
		printf("\t\t\t｜  请输入选项[]                  \n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t＋==============================＋\n");
		rewind(stdin);
		string temp;
		cin >> temp;
		rewind(stdin);
		int res;
		stringstream ss;
		ss << temp;
		ss >> res;
		if (res>6||res<1)
		{
			cout << "输入错误,请重新输入" << endl;
			Sleep(1000);
		}
		else
		{
			return res;
		}
	}
}

int School::my_run()
{
	int opnumtemp;
	opnumtemp = 100;
	file_in();
	while (opnumtemp != 3)
	{
		opnumtemp = show_menu();
		switch (opnumtemp)
		{
			case 6:cout << "再见，感谢使用，欢迎下次再来" << endl; file_out();Sleep(2000);return 0;
			case 1:insert_student(); break;
			case 2:delete_student(); break;
		}
	}
	return 0;
}

int student::display_info()
{
	cout<<"ID："<<student_ID<<" 姓名："<<student_name<<" class："<<class_ID<<" 院系："<<department_name<<endl;
	return 0;
}

vector<course> School::course_file_in(string path)
{
	fstream infile;
	path+="/course.txt";
    infile.open(path.c_str());
	vector<course>result;
	if (infile.fail())
	{	
		cout << "缺失依赖性关键文件，重新创建中" << endl;
		infile.open(path.c_str(), std::ios::out | std::ios::app);
		Sleep(2000);
		return result;
	}
	int read_flag=0;
	vector<int>temp_ID;
	vector<int>temp_score;
	string temp_course_name;
	for (; !infile.eof(); )
	{	
		string temp;
		infile>>temp;
		if(temp=="")
			break;
		//cout<<"temp"<<temp<<endl;
		if(read_flag==0&&temp=="begin")
		{
			read_flag=1;
			continue;
		}
		if(read_flag==1)
		{
			temp_course_name=temp;
			read_flag=2;
			continue;
		}
		if(temp=="end")
		{
			course a;
			a.course_name=temp_course_name;
			temp_course_name="";
			a.all_student_ID=temp_ID;
			temp_ID.clear();
			a.score=temp_score;
			temp_score.clear();
			read_flag=0;
			result.push_back(a);
			continue;
		}
		if(read_flag==2)
		{
			int hh;
			stringstream ss;
			ss<<temp;
			ss>>hh;
			temp_ID.push_back(hh);
			read_flag=3;
			continue;
		}
		if(read_flag==3)
		{
			int hh;
			stringstream ss;
			ss<<temp;
			ss>>hh;
			temp_score.push_back(hh);
			read_flag=2;
			continue;
		}
	}
	
	
	return result;
}

vector<student> School::student_file_in(string path)
{
    fstream infile;
	path+="/student.txt";
    infile.open(path.c_str());
	vector<student>result;
	if (infile.fail())
	{	
		cout << "缺失依赖性关键文件，重新创建中" << endl;
		infile.open(path.c_str(), std::ios::out | std::ios::app);
		Sleep(2000);
		return result;
	}
	for (; !infile.eof(); )
	{	
		string temp;
		infile >> temp;
		stringstream ss;
		ss<<temp;
		int temp_ID;
		ss>>temp_ID;
		infile >> temp;
		stringstream ss2;
		ss2<<temp;
		int temp_class_ID;
		ss2>>temp_class_ID;
		string temp_student_name;
		string temp_department_name;
		infile >>temp_student_name;
		infile >>temp_department_name;
		student a=student(temp_ID,temp_student_name,temp_department_name,temp_class_ID);
		result.push_back(a);
	}
	result.pop_back();
	//cout<<"result"<<result.size()<<endl;	
	return result;
}

int School::file_in()
{
	fstream infile;
	string filesite = "cache/init.txt";
	rewind(stdin);
	infile.open(filesite.c_str());
	if (infile.fail())
	{	
		cout << "缺失依赖性关键文件，重新创建中" << endl;
		infile.open(filesite.c_str(), std::ios::out | std::ios::app);
		Sleep(2000);
		return 0;
	}
	for (; !infile.eof(); )
	{	
		string temp_name;
		infile >> temp_name;
		department temp2;
		temp2.department_name = temp_name;
		my_school.push_back(temp2);
	}
	my_school.pop_back();
	for (int i(0); i < my_school.size(); i++)
	{
		string file_path = "cache/" + my_school[i].department_name;
		my_school[i].student_list=student_file_in(file_path);	
		my_school[i].course_list=course_file_in(file_path);
	}
	for(int i(0);i<my_school.size();i++)
	{
		for(int j(0);j<my_school[i].course_list.size();j++)
		{
			for(int l(0);l<my_school[i].course_list[j].all_student_ID.size();l++)
			{
				my_school[i].student_list[my_school[i].course_list[j].all_student_ID[l]].course_id.push_back(j);
			}
		}
	}
	return 1;
}

int School::file_out()
{
	fstream myoperate;
	for(int i(0);i<my_school.size();i++)
	{
		my_school[i].file_out();
	}
	return 0;
}

int School::insert_student()
{
	//while (1)
	//{
		string temp_name;
		int temp_ID;
		int temp_class_ID;
		string temp_department_name;


		system("cls");
		system("color f1");
		cout << "输入学生姓名" << endl;
		cin >> temp_name;
		cout << "输入学生学号" << endl;
		cin >> temp_ID;
		cout << "输入班级编号" << endl;
		cin >> temp_class_ID;
		cout << "输入学生院系" << endl;
		cin >> temp_department_name;
		int department_code(-1);
		for (int i(0); i < my_school.size(); i++)
		{
			if (my_school[i].department_name == temp_department_name)
			{
				department_code = i;
				break;
			}
		}
		if (department_code == -1)
		{
			cout << "the department " << temp_department_name << " does not exists" << endl;
			return 0;
		}
		else
		{
			student temp(temp_ID, temp_name, temp_department_name, temp_class_ID);
			my_school[department_code].student_list.push_back(temp);		
			return 1;
		}
	//}
	return 1;
}

int School::delete_student()
{
	system("cls");
	int temp_ID;
	system("color f1");
	cout << "输入学生学号" << endl;
	cin >> temp_ID;
	for(int i(0);i<my_school.size();i++)
	{
		for(int j(0);j<my_school[i].student_list.size();j++)
		{
			if(my_school[i].student_list[j].student_ID==temp_ID)
			{
				for(int k(0);k<my_school[i].student_list[j].course_id.size();k++)
				{
					my_school[i].course_list[my_school[i].student_list[j].course_id[k]].all_student_ID.erase(my_school[i].course_list[my_school[i].student_list[j].course_id[k]].all_student_ID.begin()+j);
					my_school[i].course_list[my_school[i].student_list[j].course_id[k]].score.erase(my_school[i].course_list[my_school[i].student_list[j].course_id[k]].score.begin()+j);
				}
				my_school[i].student_list.erase(my_school[i].student_list.begin()+j);
				cout<<"find the Student and delete"<<endl;
				Sleep(2000);
				return 1;
			}
		}
	}
	cout<<"mo match result and return in 2 second"<<endl;
	Sleep(2000);
	return 0;
}

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
	