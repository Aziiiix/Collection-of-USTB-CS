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

void get_text(string book, int x = 0)       //读取并保存文本内容
{
    setlocale(LC_ALL, "zh-CN");              //文本2和6有中文字符
    ifstream in("TXT\\" + book + ".txt");     //拼接路径
    string line, con;                        //存储按行读取到的内容
    one_Content.bookName = book;             //初始化对象
    one_Content.page = 1;
    one_Content.chapter = x;
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
                {
                    if (isdigit(line[i]))
                        counts++;
                if (counts == len)
                    one_Content.page++;
                else
                {
                    transform(line.begin(), line.end(), line.begin(), ::tolower);//转换小写
                    if (line.substr(0, 7) == "chapter")
                        one_Content.chapter++;                  //是章节
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
        cout << "不存在此文本：" << book << endl;
}

void input_Book()  //传入文本信息
{
    get_text("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //第一本不用传
    get_text("J.K. Rowling - HP 2 - Harry Potter and the Chamber of Secrets");
    get_text("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
    get_text("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
    get_text("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
    get_text("J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows");
    get_text("J.K. Rowling - Quidditch Through the Ages");
    get_text("J.K. Rowling - The Tales of Beedle the Bard");
}

void search(string info, deque<Text>& s)    //查找信息
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

void show(deque<Text> s, string info)                        //显示查询结果
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
    string input;      
    deque<Text> search_Info;
    cout << "请输入要查询的 人名/地名: " << endl;
    getline(cin, input);   //获取指定输入
    search(input, search_Info);
    if (!search_Info.empty())
    {
        show(search_Info, input);
        cout << endl << "请输入需要显示的段落的序号: " << endl;
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

