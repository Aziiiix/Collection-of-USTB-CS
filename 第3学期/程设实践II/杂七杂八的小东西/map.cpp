#include<vector> 
#include<map>
#include<iostream>
#include <algorithm>    // std::sort


using namespace std;

//打印函数可写成模板

//打印函数 printfA
void printfA(map<vector<int>, int> vec_)
{
    for (std::map<std::vector<int>, int>::iterator it = vec_.begin(); it != vec_.end(); it++)
    {
        std::cout << it->first[0] << "  " << it->first[1] << "  " << it->first[2] << "  " << it->second << std::endl;
    }
    cout << "容积 = " << vec_.size() << endl;
}

//打印函数 printfB
void printfB(multimap<string, int> vec_)
{
    for (multimap<string, int>::iterator it = vec_.begin(); it != vec_.end(); it++)
    {
        std::cout << it->first  << "  " << it->second << std::endl;
    }
    cout << "容积 = " << vec_.size() << endl;
}

int main()
{
    //声明，定义
    std::map<int, std::string> m;
    m[3] = "h1";
    m[0] = "what";
    // 构建 key-value
    m.insert(std::pair<int, std::string>(2, "love you"));

    std::cout << m[0].c_str() << std::endl;//这里数字 不是索引值了
    std::cout << m[3].c_str() << std::endl;
    std::cout << m[4].c_str() << std::endl;
    std::cout << m[2].c_str() << std::endl;   // 会产生一个新的元素，即m[2] = ""

    m[6] = string("slam2345");
    std::cout << m.size() << std::endl;       // 5
    //遍历
    for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
        std::cout << it->first << ", " << it->second.c_str() << std::endl;


    std::vector<int> pointTemp;
    std::map<std::vector<int>, int> vecA;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            pointTemp.push_back(y);
            pointTemp.push_back(x);
            pointTemp.push_back(x + y);
            //插入
            vecA.insert(std::pair<std::vector<int>, int>(pointTemp, (y * 4 + x + 1)));
            pointTemp.clear();
        }
    }
    printfA(vecA);
//***************************************************************************************************
//【注意】区分map与multimap：1、两者都会自动排序 2、multimap插入不会覆盖已有键值对（对于map若有相同key，则拒绝插入）
//<1>插入返回值 判定是否插入成功
    //带插入数据
    vector<int> pointTemp_ = { 1,2,3 }; // Insert方法不能覆盖，如果键已经存在，则插入失败【注意插入位置，是自动排序】
    int a1 = 4;
    //判定插入是否成功
    pair< map<vector<int>, int>::iterator, bool> isInsertOK;//注意这里声明
    isInsertOK = vecA.insert(pair<vector<int>, int>(pointTemp_, a1));
    cout << "插入成功？ " << isInsertOK.second << endl;
    //打印
    printfA(vecA);

//***************************************************************************************************
//<2>map对象的拷贝构造与赋值
    map<vector<int>, int> vecB(vecA); //拷贝构造
    map<vector<int>, int> vecC;
    vecC = vecA;
    vecC.swap(vecA);
//***************************************************************************************************
//<3>查找
     map<string, int> vecD;
    // 你以为按照下面初始化 vecD，他的size会是5？ 由于insert方法不能覆盖，所以我们将map 改成 multimap
    vecD.insert(pair<string, int>((string)"china", 1));
    vecD.insert(pair<string, int>((string)"china", 2));//拒绝插入
    vecD.insert(pair<string, int>((string)"china", 3));//拒绝插入
    vecD.insert(pair<string, int>((string)"english", 1));
    vecD.insert(pair<string, int>((string)"english", 2));//拒绝插入

    multimap<string, int> vecE;
    vecE.insert(make_pair((string)"china", 1));
    vecE.insert(make_pair((string)"china", 1));//允许插入
    vecE.insert(make_pair((string)"china", 3));//允许插入
    vecE.insert(make_pair((string)"china", 4));//允许插入
    vecE.insert(make_pair((string)"china", 5));//允许插入
    vecE.insert(make_pair((string)"english", 1));
    vecE.insert(make_pair((string)"english", 2));//允许插入
    vecE.insert(make_pair((string)"america", 1));
    vecE.insert(make_pair((string)"america", 2));//允许插入
    vecE.insert(make_pair((string)"america", 3));//允许插入
    cout << "multimap 初始化" << endl;
    cout << "vecE所有元素"<<endl;
    printfB(vecE);
    //查找区间
    multimap<string, int> ::iterator it1 = vecE.lower_bound("china");   //指向vecD中第一个等于键值 “china”对应的元素
    multimap<string, int> ::iterator it2 = vecE.upper_bound("china");   //指向vecD中第一个大于键值 “china”对应的元素
    cout << it1->first << " " << it1->second << endl;
    cout << it2->first << " " << it2->second << endl;
    // 等于 = lower_bound + upper_bound
    pair<multimap<string, int>::iterator, multimap<string, int>::iterator > it3    = vecE.equal_range("china");
    map<string, int>::iterator it4 = it3.first;
    map<string, int>::iterator it5 = it3.second;

    //查找key = “china”键值对的个数
    int iCount = vecE.count("china");

    //查找key = “china”对应键值对
    multimap<string, int>::iterator it6 = vecE.find("china");

//***************************************************************************************************
// <4>删除
    multimap<string, int>::iterator itBegin = vecE.begin();
    // 删除 vecE 前面三个元素 与 后面 三个元素
    // 在改善特征点匹配算法中有实践
    int index = 0;
    int vecA_size = vecE.size();
    //删除(自定义删除任何元素)
    for (multimap<string, int>::iterator it_ = vecE.begin(); it_ != vecE.end(); )
    {
        //<1>法1
        //vecE.erase(it_++);
        //<2>法2
        if ((0<=index)&&(index<=2))
        {
            it_ = vecE.erase(it_);//这样写，防止指针失效
        }

        else if (((vecA_size - 3) <= index) && (index <= (vecA_size - 1)))
        {
            it_ = vecE.erase(it_);
        }
        else
        {
            it_++;
        }
        ++index;
    }


    //删除multimap中key = "english"的 所有 元素
    vecE.erase("english");
    cout << "vecE删除key = english的 所有 元素 " << endl;
    printfB(vecE);

    //删除所有元素
    multimap<string, int>::iterator itBegin_ = vecE.begin();
    multimap<string, int>::iterator itEnd_ = vecE.end();
    vecE.erase(itBegin_, itEnd_);
    //bool isEmpty = vecE.empty();

    if (vecE.empty())
    {
        cout << "vecE已经被清空" << endl;
    }
    return 0;
}
