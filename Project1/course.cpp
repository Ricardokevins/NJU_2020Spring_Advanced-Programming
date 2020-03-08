#include"course.h"

int course::delete_student(int ID)
{
	all_student_ID.erase(all_student_ID.begin()+ID);
	score.erase(score.begin()+ID);
	return 1;				
}

int course::add_student(int ID,int scores)
{
	all_student_ID.push_back(ID);
	score.push_back(scores);
	return 1;				
}

int course::adjust_score(int id,int scores)
{
	score[id]=scores;
	return 0;
}

int course::show_infor()
{
	cout<<course_name<<endl;
	for(int j(0);j<all_student_ID.size();j++)
	{
		cout<<all_student_ID[j]<<" "<<score[j]<<endl;
	}
}