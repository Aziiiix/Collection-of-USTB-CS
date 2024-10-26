#include <fstream>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

class Text      
{
public:
    int page;            
    int chapter;         
    string bookName;     
    string content;      
};

deque <Text> text;      
Text one_Content;

void get_text(string book, int x = 0)       //��ȡ�������ı�����
{
    setlocale(LC_ALL, "zh-CN");              //�ı�2��6�������ַ�
    ifstream in("TXT\\" + book + ".txt");     //ƴ��·��
    string line, con;                        //�洢���ж�ȡ��������
    one_Content.bookName = book;             //��ʼ������
    one_Content.page = 1;
    one_Content.chapter = x;
    int len = 0;
    if (in)                                  // �и��ļ�
    {
        while (getline(in, line))
        {
            len = line.length();
            if (len <= 20 && len > 0)        //�ж����½���������ҳ��
            {
                int counts = 0;
                for (int i = 0; i < len; i++)
                {
                    if (isdigit(line[i]))
                        counts++;
                if (counts == len)
                    one_Content.page++;
                else
                {
                    transform(line.begin(), line.end(), line.begin(), ::tolower);//ת��Сд
                    if (line.substr(0, 7) == "chapter")
                        one_Content.chapter++;                  //���½�
                }
            }
            }
            else
            {
                one_Content.content = line;
                text.push_back(one_Content);
            }
        }
    }
    else
        cout << "�����ڴ��ı���" << book << endl;
}

void input_Book()  //�����ı���Ϣ
{
    get_text("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //��һ�����ô�
    get_text("J.K. Rowling - HP 2 - Harry Potter and the Chamber of Secrets");
    get_text("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
    get_text("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
    get_text("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
    get_text("J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows");
    get_text("J.K. Rowling - Quidditch Through the Ages");
    get_text("J.K. Rowling - The Tales of Beedle the Bard");
}

void search(string info, deque<Text>& s)    //������Ϣ
{
    int all_len = text.size();
    string::size_type p;
    for (int i = 0; i < all_len; i++)
    {
        p = text[i].content.find(info);
        if (!(p == string::npos))
            s.push_back(text[i]);
    }
}

void show(deque<Text> s, string info)                        //��ʾ��ѯ���
{
    cout << "���       ����/����       ҳ��       �½�       ����" << endl;
    for (int i = 0; i < s.size(); i++)
        cout << "  "
        << i + 1 << "       "
        << info << "         "
        << s[i].page << "         "
        << s[i].chapter << "         "
        << s[i].bookName << endl;
}

int main()
{
    input_Book();
    string input;      
    deque<Text> search_Info;
    cout << "������Ҫ��ѯ�� ����/����: " << endl;
    getline(cin, input);   //��ȡָ������
    search(input, search_Info);
    if (!search_Info.empty())
    {
        show(search_Info, input);
        cout << endl << "��������Ҫ��ʾ�Ķ�������: " << endl;
        while (1)
        {
            int x = 1;
            cin >> x;
            if (x == 0)
                break;
            cout << endl << search_Info[x - 1].content << endl;
            cout << endl << "��Ҫ������ʾ����������������ţ��������� 0:" << endl;
        }
    }
    else
        cout << "�޷���ѯ�� ! ! !" << endl;
    return 0;
}

