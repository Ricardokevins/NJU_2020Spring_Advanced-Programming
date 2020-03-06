#include<iostream>
#include<vector>

#include <fstream>
#include <sstream>
#include <Windows.h>
#include<iomanip>
#include"base.h"
using namespace std;

student::student(int a, string b, string c, int d)
{
	student_ID = a;
	student_name = b;
	department_name = c;
	class_ID = d;
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
	while (opnumtemp != 3)
	{
		opnumtemp = show_menu();
		switch (opnumtemp)
		{
		case 6:cout << "再见，感谢使用，欢迎下次再来" << endl; break;
		case 1:insert_student(); break;
		case 2:delete_student(); break;
		}
	}
	return 0;
}

vector<student> School::student_file_in(string path)
{
    fstream infile;
    infile.open(path);
}

int School::file_in()
{
	fstream infile;
	string filesite = "cache/init.txt";
	rewind(stdin);
	infile.open(filesite);
	if (infile.fail())
	{	
		cout << "缺失依赖性关键文件，重新创建中" << endl;
		infile.open("cache/init.txt", std::ios::out | std::ios::app);
		Sleep(2000);
		return 0;
	}
	for (int j(1); !infile.eof(); )
	{	
		string temp_name;
		infile >> temp_name;
		department temp2;
		temp2.department_name = temp_name;
		my_school.push_back(temp2);
	}
	for (int i(0); i < my_school.size(); i++)
	{
		string file_path = "cache/" + my_school[i].department_name;
		
	}
	return 1;
}

int School::file_out()
{
	fstream myoperate;
	myoperate.open("cache/init.txt", ofstream::out);
	if (myoperate.fail())
	{
		cout << "文件导出失败!!!" << endl;
		Sleep(2000);
		return 0;
	}
	
	for (int i(0); i < my_school.size(); i++)
	{
		string department_name;
		department_name = my_school[i].department_name;
		myoperate << department_name << endl;
	}
	myoperate.close();
	cout << "文件导出成功,返回上一级" << endl;
	Sleep(2000);
	
	return 0;
}

int School::insert_student()
{
	while (1)
	{
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
		}
	}
	return 1;
}

int School::delete_student()
{
	return 0;
}
