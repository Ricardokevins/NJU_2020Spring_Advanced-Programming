#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include<iomanip>
#include"base.h"
using namespace std;



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
		printf("\t\t\t｜  3->查找学生               \n");
		printf("\t\t\t｜  4->修改学生              \n");
		printf("\t\t\t｜  5->显示（院系，班级，课程）                \n");
		printf("\t\t\t｜  6->退出系统               \n");
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
	while (opnumtemp != 6)
	{
		opnumtemp = show_menu();
		switch (opnumtemp)
		{
			case 6:cout << "再见，感谢使用，欢迎下次再来" << endl; file_out();Sleep(2000);return 0;
			case 1:insert_student(); break;
			case 2:delete_student(); break;
			case 3:search_student(); break;
			case 4:adjust_student(); break;
			case 5:display_info(); break;
		}
	}
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


int School::search_student()
{
	int flag(1);
	int temp_de_ID=0;
	int temp_de_pos=0;
	int temp_ID=0;
	while(flag==1)
	{
		system("cls");
		system("color f1");
		cout<<"输入带查询的学号,或输入-1放弃"<<endl;		
		cin>>temp_ID;
		if(temp_ID==-1)
			break;	
		for(int i(0);i<my_school.size();i++)
		{
			for(int j(0);j<my_school[i].student_list.size();j++)
			{
				if(my_school[i].student_list[j].student_ID==temp_ID)
				{
					flag=2;
					temp_de_ID=i;
					temp_de_pos=j;
					break;
				}
			}
			if(flag==2)
			{
				break;
			}
		}
		if(flag==2)
		{
			break;
		}
		else
		{
			cout<<"没有找到这个学生"<<endl;
			Sleep(2000);
		}
		
	}
	system("cls");
	system("color f1");
	if(temp_ID==-1)
		return 0;
	cout << left << setw(10) << "学号" << "|";
	cout << left << setw(20) << "名字" << "|";
	cout << left << setw(10) << "班级号" << "|";
	cout << left << setw(20) << "院系"  << endl;
	cout << left << setw(10) << my_school[temp_de_ID].student_list[temp_de_pos].student_ID << "|";
	cout << left << setw(20) << my_school[temp_de_ID].student_list[temp_de_pos].student_name << "|";
	cout << left << setw(10) << my_school[temp_de_ID].student_list[temp_de_pos].class_ID << "|";
	cout << left << setw(20) << my_school[temp_de_ID].student_list[temp_de_pos].department_name  << endl;
	cout << endl;

	cout << left << setw(30) << "课程名" << "|";
	cout << left << setw(30) << "成绩" << endl;
	for(int i(0);i< my_school[temp_de_ID].student_list[temp_de_pos].course_id.size();i++)
	{
		cout<< left << setw(20)<<my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[i]].course_name<<"|";
		cout<< left << setw(20)<<my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[i]].score[temp_de_pos]<<endl;
	}
	cout<<endl;
	cout<<"输入C继续,其他任意键返回"<<endl;
	string a;
	cin>>a;
	if(a=="C")
		search_student();
	return 0;
}

int School::adjust_student()
{
	int flag(1);
	int temp_de_ID=0;
	int temp_de_pos=0;
	int temp_ID=0;
	int search_r(1);
	while(search_r)
	{
		while(flag==1)
		{
			system("cls");
			system("color f1");
			cout<<"输入带查询的学号,或输入-1放弃"<<endl;		
			cin>>temp_ID;
			if(temp_ID==-1)
			break;	
			for(int i(0);i<my_school.size();i++)
			{
				for(int j(0);j<my_school[i].student_list.size();j++)
				{
					if(my_school[i].student_list[j].student_ID==temp_ID)
					{
						flag=2;
						temp_de_ID=i;
						temp_de_pos=j;
						break;
					}
				}
				if(flag==2)
				{
					break;
				}
			}
			if(flag==2)
			{
				break;
			}
			else
			{
				cout<<"没有找到这个学生"<<endl;
				Sleep(2000);
			}
		
		}
		system("cls");
		system("color f1");
		if(temp_ID==-1)
			return 0;
		cout << left << setw(10) << "学号" << "|";
		cout << left << setw(20) << "名字" << "|";
		cout << left << setw(10) << "班级号" << "|";
		cout << left << setw(20) << "院系"  << endl;
		cout << left << setw(10) << my_school[temp_de_ID].student_list[temp_de_pos].student_ID << "|";
		cout << left << setw(20) << my_school[temp_de_ID].student_list[temp_de_pos].student_name << "|";
		cout << left << setw(10) << my_school[temp_de_ID].student_list[temp_de_pos].class_ID << "|";
		cout << left << setw(20) << my_school[temp_de_ID].student_list[temp_de_pos].department_name  << endl;
		cout << endl;

		cout << left << setw(35) << "课程名" << "|";
		cout << left << setw(35) << "成绩" << endl;
		for(int i(0);i< my_school[temp_de_ID].student_list[temp_de_pos].course_id.size();i++)
		{
			cout<< left << setw(35)<<my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[i]].course_name<<"|";
			cout<< left << setw(35)<<my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[i]].score[temp_de_pos]<<endl;
		}
		cout<<endl;
		cout<<"输入C继续,任意键返回"<<endl;
		string a;
		cin>>a;
		if(a!="C")
		{
			return 0;
		}
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t＋==============================＋\n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t｜  1->修改学号                 \n");
		printf("\t\t\t｜  2->修改名字               \n");
		printf("\t\t\t｜  2->修改班级               \n");
		printf("\t\t\t｜  2->修改课程相关           \n");
		printf("\t\t\t｜  2->转系               \n");
		printf("\t\t\t｜  6->不改了算了               \n");
		printf("\t\t\t｜  请输入选项[]                  \n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t＋==============================＋\n");
		rewind(stdin);
		string temp;
		cin>>temp;
		rewind(stdin);
		int res;
		stringstream ss;
		ss << temp;
		ss >> res;
		if(res==1)
		{
			int temp2;
			cout<<"请输入"<<endl;
			cin>>temp2;
			for(int i(0);i<my_school[temp_de_ID].student_list.size();i++)
			{
				if(my_school[temp_de_ID].student_list[i].student_ID==temp2&&i!=temp_de_pos)
				{
					cout<<"这个学号已经被占用，返回中"<<endl;
					Sleep(2000);
					return 0;
				}
			}
			my_school[temp_de_ID].student_list[temp_de_pos].student_ID=temp2;
			cout<<"修改成功"<<endl;
			Sleep(2000);
			return 0;
		}
		if(res==2)
		{
			string temp2;
			cout<<"请输入"<<endl;
			cin>>temp2;
			my_school[temp_de_ID].student_list[temp_de_pos].student_name=temp2;
			cout<<"修改成功"<<endl;
			Sleep(2000);
			return 0;
		}
		if(res==3)
		{
			int temp2;
			cout<<"请输入"<<endl;
			cin>>temp2;
			my_school[temp_de_ID].student_list[temp_de_pos].class_ID=temp2;
			cout<<"修改成功"<<endl;
			Sleep(2000);
			return 0;
		}
		if(res==4)
		{
			system("cls");
			system("color f1");
			printf("\n\n\t\t\t＋==============================＋\n");
			printf("\t\t\t｜                              \n");
			printf("\t\t\t｜  1->加课                 \n");
			printf("\t\t\t｜  2->退课               \n");
			printf("\t\t\t｜  2->改成绩               \n");
			printf("\t\t\t｜  6->不改了算了               \n");
			printf("\t\t\t｜  请输入选项[]                  \n");
			printf("\t\t\t｜                              \n");
			printf("\t\t\t＋==============================＋\n");
			string temp3;
			cin>>temp3;
			rewind(stdin);
			int res2;
			stringstream sss;
			sss << temp3;
			sss >> res2;
			if(res2==1)
			{
				string course_name;
				cout<<"输入想要处理的对应课程的名字"<<endl;
				cin>>course_name;		
				int find_flag=0;
				int find_pos=0;		
				for(int i(0);i< my_school[temp_de_ID].course_list.size();i++)
				{
					if(my_school[temp_de_ID].course_list[i].course_name==course_name)
					{
						find_flag=1;
						find_pos=i;
						break;
					}
				}
				if(find_flag)
				{					
					int temp_score=0;
					cout<<"添加初始成绩"<<endl;
					cin>>temp_score;
					if(temp_score>100||temp_score<0)
					{
						cout<<"输入不合法，返回"<<endl;
						Sleep(2000);
						return 0;
					}
					my_school[temp_de_ID].course_list[find_pos].add_student(temp_de_pos,temp_score);
					my_school[temp_de_ID].student_list[temp_de_pos].add_course(find_pos);
					cout<<"处理成功，返回中"<<endl;
					Sleep(2000);
					return 0;
				}
				else
				{
					cout<<"本院系没有这个课程，返回上一级"<<endl;
					Sleep(2000);
					return 0;
				}
			}
			if(res2==2)
			{
				string course_name;
				cout<<"输入想要处理的对应课程的名字"<<endl;
				cin>>course_name;		
				int find_flag=0;
				int find_pos=0;	
				for(int j(0);j<my_school[temp_de_ID].student_list[temp_de_pos].course_id.size();j++)
				{
					if(my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[j]].course_name==course_name)
					{
						find_flag=1;
						find_pos=my_school[temp_de_ID].student_list[temp_de_pos].course_id[j];
						my_school[temp_de_ID].student_list[temp_de_pos].delete_course(find_pos);
						break;
					}
					
				}
				if(find_flag)
				{
					my_school[temp_de_ID].course_list[find_pos].delete_student(temp_de_pos);
					cout<<"处理成功，返回中"<<endl;
					Sleep(2000);
					return 0;
				}
				else
				{
					cout<<"这个学生就没选这个课程，返回上一级"<<endl;
					Sleep(2000);
					return 0;
				}
			}
			if(res2==3)
			{
				string course_name;
				cout<<"输入想要处理的对应课程的名字"<<endl;
				cin>>course_name;		
				int find_flag=0;
				int find_pos=0;	
				for(int j(0);j<my_school[temp_de_ID].student_list[temp_de_pos].course_id.size();j++)
				{
					if(my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[j]].course_name==course_name)
					{
						find_flag=1;
						find_pos=my_school[temp_de_ID].student_list[temp_de_pos].course_id[j];
						break;
					}
					
				}
				if(find_flag)
				{
					cout<<"输入新的分数（注：0-100）"<<endl;
					int new_score;
					cin>>new_score;
					if(new_score<0||new_score>100)
					{
						cout<<"输入成绩并不合法，退出"<<endl;
						Sleep(2000);
						return 0;
					}
					my_school[temp_de_ID].course_list[find_pos].adjust_score(temp_de_pos,new_score);
					cout<<"处理成功，返回中"<<endl;
					Sleep(2000);
					return 0;
				}
				else
				{
					cout<<"这个学生就没选这个课程，返回上一级"<<endl;
					Sleep(2000);
					return 0;
				}
			}
			cout<<"返回中"<<endl;
			Sleep(2000);
			return 0;

		}
		if(res==5)
		{
			cout<<"输入待转的系"<<endl;
			string de_name;
			cin>>de_name;
			//Todo:
			int depart_num(-1);
			for(int i(0);i<my_school.size();i++)
			{
				if(my_school[i].department_name==de_name)
				{
					depart_num=i;
					break;
				}
			}
			if(depart_num==-1)
			{
				cout<<"没有这个系"<<endl;
				Sleep(2000);
				return 0;
			}
			if(depart_num==temp_de_ID)
			{
				cout<<"不允许转自己系"<<endl;
				Sleep(2000);
				return 0;
			}
			for(int i(0);i<my_school[temp_de_ID].student_list[temp_de_pos].course_id.size();i++)
			{
				my_school[temp_de_ID].course_list[my_school[temp_de_ID].student_list[temp_de_pos].course_id[i]].delete_student(temp_de_pos);
				my_school[temp_de_ID].student_list[temp_de_pos].delete_course(i);
			}
			student cache_a=student(my_school[temp_de_ID].student_list[temp_de_pos]);
			my_school[temp_de_ID].student_list.erase(my_school[temp_de_ID].student_list.begin()+temp_de_pos);
			my_school[depart_num].student_list.push_back(cache_a);
			cout<<"转系完成"<<endl;
			Sleep(2000);
			return 0;

		}
	}
}

int School::display_info()
{
	while(1)
	{
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t＋==============================＋\n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t｜  1->查看院系                 \n");
		printf("\t\t\t｜  2->查看班级               \n");
		printf("\t\t\t｜  3->查看课程               \n");
		printf("\t\t\t｜  4->不看了           \n");
		printf("\t\t\t｜  请输入选项[]                  \n");
		printf("\t\t\t｜                              \n");
		printf("\t\t\t＋==============================＋\n");
		rewind(stdin);
		string temp;
		cin>>temp;
		rewind(stdin);
		int res;
		stringstream ss;
		ss << temp;
		ss >> res;
		if(res==1)
		{
			system("cls");
			system("color f1");
			cout<<"输入带查询的院系名字,或输入-1放弃"<<endl;
			string temp;
			cin>>temp;
			if(temp=="-1")
				return 0;
			for(int i(0);i<my_school.size();i++)
			{
				if(my_school[i].department_name==temp)
				{
					system("cls");
					system("color f1");
					cout << left << setw(10) << "系名" << "|";
					cout << left << setw(20) << temp << "|";
					cout << left << setw(10) << "学生数" << "|";
					cout << left << setw(20) <<  my_school[i].student_list.size() <<  "|";
					cout << left << setw(10) << "课程数" << "|";
					cout << left << setw(20) <<  my_school[i].course_list.size() << endl;
					cout<<"输入S查看学生列表，输入C查看课程列表，输入其他退出"<<endl;
					string temp2;
					cin>>temp2;
					if(temp2=="S")
					{
						system("cls");
						system("color f1");
						cout << left << setw(20) <<"Student list"<<endl;
						cout << left << setw(10) << "学号" << "|";
						cout << left << setw(20) << "名字" << "|";
						cout << left << setw(10) << "班级号" << endl;
						for(int j(0);j<my_school[i].student_list.size();j++)
						{
							cout << left << setw(10) << my_school[i].student_list[j].student_ID << "|";
							cout << left << setw(20) << my_school[i].student_list[j].student_name << "|";
							cout << left << setw(10) << my_school[i].student_list[j].class_ID << endl;
						}
						string temp3;
						cout<<"输入任意退出"<<endl;
						cin>>temp3;
						return 1;
					}
					else
					{
						if(temp2=="C")
						{
							system("cls");
							system("color f1");
							cout << left << setw(20) <<"Course List"<<endl;
							cout << left << setw(30) << "课程名" << "|";
							cout << left << setw(10) << "人数" << "|";
							cout << left << setw(30) << "平均分" <<endl;
							for(int j(0);j<my_school[i].course_list.size();j++)
							{
								cout << left << setw(30) << my_school[i].course_list[j].course_name<< "|";
								cout << left << setw(10) << my_school[i].course_list[j].all_student_ID.size() << "|";
								int total_score=0;
								for(int l(0);l<my_school[i].course_list[j].score.size();l++)
								{
									total_score+=my_school[i].course_list[j].score[l];
								}
								double average=total_score*1.0/my_school[i].course_list[j].all_student_ID.size();
								cout << left << setw(30) << average << endl;
							}
							rewind(stdin);
							string temp3;
							cout<<"输入任意退出"<<endl;
							cin>>temp3;
							return 1;
						}
						else
						{
							return 0;
						}
						
					}
					
				}
			}
			cout<<"没有这个系，返回上一级"<<endl;
			Sleep(2000);
			return 0;
		}

		if(res==2)
		{
			system("cls");
			system("color f1");
			
			cout<<"输入院系（指定院系才能选择班级）,或输入-1放弃"<<endl;
			string temp;
			cin>>temp;
			if(temp=="-1")
				return 0;
			for(int i(0);i<my_school.size();i++)
			{
				if(my_school[i].department_name==temp)
				{
					system("cls");
					system("color f1");		
					cout<<"输入班级的编号,或输入-1放弃"<<endl;
					int temp2;
					cin>>temp2;
					if(temp2==-1)
						return 0;
					system("cls");
					system("color f1");
					cout << left << setw(20) <<"Student list"<<endl;
					cout << left << setw(10) << "学号" << "|";
					cout << left << setw(20) << "名字" << "|";
					cout << left << setw(10) << "班级号" << endl;
					for(int j(0);j<my_school[i].student_list.size();j++)
					{
						if(my_school[i].student_list[j].class_ID==temp2)
						{
							cout << left << setw(10) << my_school[i].student_list[j].student_ID << "|";
							cout << left << setw(20) << my_school[i].student_list[j].student_name << "|";
							cout << left << setw(10) << my_school[i].student_list[j].class_ID << endl;
						}
					}
					string temp3;
					cout<<"输入任意退出"<<endl;
					cin>>temp3;
					return 1;

				}
			}
			cout<<"没有这个系，返回上一级"<<endl;
			Sleep(2000);
			return 0;
		}

		if(res==3)
		{
			system("cls");
			system("color f1");
			
			cout<<"输入院系（指定院系才能选择课程）,或输入-1放弃"<<endl;
			string temp;
			cin>>temp;
			if(temp=="-1")
				return 0;
			for(int i(0);i<my_school.size();i++)
			{
				if(my_school[i].department_name==temp)
				{
					system("cls");
					system("color f1");		
					cout<<"输入课程的名字,或输入-1放弃"<<endl;
					string temp2;
					cin>>temp2;
					if(temp2=="-1")
						return 0;
					system("cls");
					system("color f1");
					for(int j(0);j<my_school[i].course_list.size();j++)
					{
						if(my_school[i].course_list[j].course_name==temp2)
						{
							cout << left << setw(20) <<"Student list of this course"<<endl;
							cout << left << setw(10) << "学号" << "|";
							cout << left << setw(20) << "名字" << "|";
							cout << left << setw(10) << "班级号" << "|";
							cout << left << setw(20) << "成绩"<< endl;		
							for(int l(0);l<my_school[i].course_list[j].all_student_ID.size();l++)
							{
								cout << left << setw(10) << my_school[i].student_list[my_school[i].course_list[j].all_student_ID[l]].student_ID << "|";
								cout << left << setw(20) << my_school[i].student_list[my_school[i].course_list[j].all_student_ID[l]].student_name << "|";
								cout << left << setw(10) <<  my_school[i].student_list[my_school[i].course_list[j].all_student_ID[l]].class_ID<< "|";
								cout << left << setw(20) << my_school[i].course_list[j].score[l] << endl;
							}
						}
						string temp3;
						cout<<"输入任意退出"<<endl;
						cin>>temp3;
						return 1;
					}
					cout<<"没有这个课，返回上一级"<<endl;
					Sleep(2000);
					return 0;
				}
			}
			cout<<"没有这个系，返回上一级"<<endl;
			Sleep(2000);
			return 0;
		}

		if(res==4)
		{
			return 0;
		}

		else
		{
			return 0;
		}
		
	}
}
