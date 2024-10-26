//code by Aziiii
#include<iostream>
#include<iomanip>
using namespace std;
struct Student
{
	int num;
	char name[10];
	int score;
} ;
void output_message(Student stu)
{
	cout << setw(10) << stu.num << setw(10) << stu.name << setw(10) << stu.score << endl;
}
void output_title()
{
	cout << setw(10) << "Number" << setw(10) << "Name" << setw(10) << "Score\n";
}
int main()
{
	int n;
	cout << "The number of student:" << endl;
	cin >> n;

	Student* stuarray = new Student[n];
	//建立动态结构体数组 
	for (int i = 0; i < n; i++)
	{
		cin >> stuarray[i].num >> stuarray[i].name >> stuarray[i].score;
	}
	//输入学生数据 
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += stuarray[i].score;
	}
	//累加总成绩 

	cout << "\nAll students:\n";
	output_title();
	
	for (int i = 0; i < n; i++)
	{
		output_message(stuarray[i]);
	}
	double average=sum/n;
	cout<<"average="<<average<<endl;
	//输出显示全部学生的信息和全班平均分
	
	for(int i=0;i<n;i++)
	{
		if(stuarray[i].score<60)
		{
			cout<<"Fail students:"<<endl;
	        output_title();
	        break;
		}
		else continue;
	 } 
	for(int i=0;i<n;i++)
	{
		if(stuarray[i].score<60)
		{
			output_message(stuarray[i]);
			continue;
		}
		else continue;
	 } 
	 //输出不及格学生信息 
	
	int max_symbol=0;//设置最高分下标 
	int max=stuarray[0].score;
	for(int i=0;i<n;i++)
	{
		if(max<stuarray[i].score)
		{
			max=stuarray[i].score;
			max_symbol=i;
		}
		else continue;
	}
	cout<<"max_score student:"<<endl;
	output_title();
	output_message(stuarray[max_symbol]);
	//查找最高分并输出 
	
	int min_symbol;
	int min=stuarray[0].score;
	for(int j=0;j<n;j++)
	{
		if(min>stuarray[j].score)
		{
			min=stuarray[j].score;
			min_symbol=j;
		}
	}
	cout<<"min_score student:"<<endl;
	output_title();
	output_message(stuarray[min_symbol]);
	//查找最低分并输出
	
	delete[]stuarray;
	stuarray=0;
	return 0;
}
