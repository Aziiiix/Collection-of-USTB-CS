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
	setlocale(LC_ALL, "zh-CN");//�������Ķ���
	ifstream in("EBook\\" + bookname + ".txt");
	string line, con;
	Station.name = bookname;
	Station.page = 1;
	Station.chapter = check;

	int len = 0;
	if (in)//������
	{
		while (getline(in, line))//��������
		{
			len = line.length();
			if (len <= 20 && len > 0)//�½ڻ�ҳ��
			{
				int count = 0;
				for (int i = 0; i < len; i++)
				{
					if (isdigit(line[i]))//�ж�ȫΪ������Ϊҳ��
					{
						count++;
					}
					if (count == len)
					{
						Station.page++;
					}
					else
					{
						transform(line.begin(), line.end(), line.begin(), ::tolower);//ת��ΪСд��ĸ
						if (line.substr(0, 7) == "chapter")
							Station.chapter++;
					}
				}
			}
			else //��������
			{
				Station.content = line;
				Catelog.push_back(Station);
			}
		}
	}
	else
	{
		cout << "404 NOT FOUND �Ҳ������ı�:" << bookname << endl;
	}

}

void input_bopk()
{
	get_book("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //��1�¿�ʼ
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
	cout << "���       ����/����       ҳ��       �½�       ����" << endl;
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
	cout << "������������ҵ������������" << endl;
	getline(cin, WantFind);
	search(WantFind, Search);
	if (!Search.empty())
	{
		show(Search, WantFind);
		cout << endl << "����������鿴�Ķ�����ţ�" << endl;
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
				cout << "����Ҫ�鿴����������ݣ������������ţ��˳�������0��" << endl;
			}
		}
	}
	else
	{
		cout << "�鲻���������" << endl;
	}

}
