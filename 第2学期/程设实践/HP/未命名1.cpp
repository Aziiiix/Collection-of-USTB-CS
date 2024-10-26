#include <fstream>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

class Text      //定义文本（Text）类
{
public:
    int page;            //页码
    int chapter;         //章节
    string bookName;     //书名
    string content;      //单段内容
};

///全  局  内  容
deque <Text> text;       //定义一个Text类的双端队列，存储文本内容
Text one_Content;

void get_text(string book, int ch = 0)       //读取并保存文本内容
{
    setlocale(LC_ALL, "zh-CN");              //文本2和6有中文字符
    ifstream in("TXT\\" + book + ".txt");     //拼接路径
    string line, con;                        //存储按行读取到的内容
    one_Content.bookName = book;             //初始化对象
    one_Content.page = 1;
    one_Content.chapter = ch;
    int len = 0;
    if (in)                                  // 有该文件
    {
        while (getline(in, line))
        {
            len = line.length();
            if (len <= 20 && len > 0)        //判断是章节名或者是页码
            {
                int counts = 0;
                for (int i = 0; i < len; i++)
                    if (isdigit(line[i]))
                        counts++;
                if (counts == len)
                    one_Content.page = atoi(line.c_str()) + 1;  //是页码
                else
                {
                    transform(line.begin(), line.end(), line.begin(), ::tolower);
                    if (line.substr(0, 7) == "chapter")
                        one_Content.chapter++;                  //是章节
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
        cout << "不存在此文本：" << book << endl;
}

void input_Book()  //传入文本信息
{
    get_text("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //第一本是从第0章开始的，所以传入-1；后面的都是从第1章开始，所以不用传
    get_text("J.K. Rowling - HP 2 - Harry Potter and the Chamber of Secrets");
    get_text("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
    get_text("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
    get_text("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
    get_text("J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows");
    get_text("J.K. Rowling - Quidditch Through the Ages");
    get_text("J.K. Rowling - The Tales of Beedle the Bard");
}

void search_in_File(string info, deque<Text>& s)    //查找信息
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

void show_Info(deque<Text> s, string info)                        //显示查询结果
{
    cout << "序号       人名/地名       页码       章节       书名" << endl;
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
    string input_Info;          //用户输入
    deque<Text> search_Info;    //存储搜索到的信息
    cout << "请输入要查询的 人名/地名: " << endl;
    getline(cin, input_Info);   //获取输入
    search_in_File(input_Info, search_Info);
    if (!search_Info.empty())
    {
        show_Info(search_Info, input_Info);
        cout << endl << "请输入要显示的段落的序号: " << endl;
        while (1)
        {
            int x = 1;
            cin >> x;
            if (x == 0)
                break;
            cout << endl << search_Info[x - 1].content << endl;
            cout << endl << "若要继续显示结果，请继续输入序号，否则输入 0:" << endl;
        }
    }
    else
        cout << "无法查询到 ! ! !" << endl;
    return 0;
}
