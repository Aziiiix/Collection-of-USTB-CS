//AZIIIIX
#include<iostream>
#include<fstream>
#include<deque>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

class HarryPotter
{
public:
	int page;
	int chapter;
	string name;
	string content;
};

deque <HarryPotter> Catelog;
HarryPotter Station;

void get_book(string bookname,int check=0)
{
	setlocale(LC_ALL, "zh-CN");//设置中文读入
	ifstream in("EBook\\" + bookname + ".txt");
	string line, con;
	Station.name = bookname;
	Station.page = 1;
	Station.chapter = check;

	int len = 0;
	if (in)//有输入
	{
		while (getline(in, line))//按行输入
		{
			len = line.length();
			if (len <= 20 && len > 0)//章节或页码
			{
				int count = 0;
				for (int i = 0; i < len; i++)
				{
					if (isdigit(line[i]))//判断全为数字则为页码
					{
						count++;
					}
					if (count == len)
					{
						Station.page++;
					}
					else
					{
						transform(line.begin(), line.end(), line.begin(), ::tolower);//转化为小写字母
						if (line.substr(0, 7) == "chapter")
							Station.chapter++;
					}
				}
			}
			else //文章内容
			{
				Station.content = line;
				Catelog.push_back(Station);
			}
		}
	}
	else
	{
		cout << "404 NOT FOUND 找不到该文本:" << bookname << endl;
	}

}

void input_bopk()
{
	get_book("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //第1章开始
	get_book("J.K. Rowling - HP 2 - Harry Potter and the Chamber of Secrets");
	get_book("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
	get_book("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
	get_book("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
	get_book("J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows");
	get_book("J.K. Rowling - Quidditch Through the Ages");
	get_book("J.K. Rowling - The Tales of Beedle the Bard");
	
}

void search(string tofind, deque<HarryPotter>& s)
{
	int All_len = Catelog.size();
	string::size_type p;
	for (int i = 0; i < All_len; i++)
	{
		p = Catelog[i].content.find(tofind);
		if (!(p == string::npos))
			s.push_back(Catelog[i]);
	}
}

void show(deque<HarryPotter>s, string tofind)
{
	cout << "序号       人名/地名       页码       章节       书名" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << "  "
			<< i + 1 << "       "
			<< tofind << "         "
			<< s[i].page << "         "
			<< s[i].chapter << "         "
			<< s[i].name << endl;
	}
}

int main()
{
	input_bopk();
	deque<HarryPotter>Search;
	string WantFind;
	cout << "请输入您想查找的人名或地名：" << endl;
	getline(cin, WantFind);
	search(WantFind, Search);
	if (!Search.empty())
	{
		show(Search, WantFind);
		cout << endl << "请输入您想查看的段落序号：" << endl;
		while (1)
		{
			int inputCheck;
			cin >> inputCheck;
			if (inputCheck == 0)
			{
				break;
			}
			else
			{
				cout << endl << Search[inputCheck - 1].content << endl;
				cout << "若需要查看其他序号内容，请继续输入序号，退出则输入0：" << endl;
			}
		}
	}
	else
	{
		cout << "查不到相关内容" << endl;
	}

}
