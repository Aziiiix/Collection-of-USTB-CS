#include<vector> 
#include<map>
#include<iostream>
#include <algorithm>    // std::sort


using namespace std;

//��ӡ������д��ģ��

//��ӡ���� printfA
void printfA(map<vector<int>, int> vec_)
{
    for (std::map<std::vector<int>, int>::iterator it = vec_.begin(); it != vec_.end(); it++)
    {
        std::cout << it->first[0] << "  " << it->first[1] << "  " << it->first[2] << "  " << it->second << std::endl;
    }
    cout << "�ݻ� = " << vec_.size() << endl;
}

//��ӡ���� printfB
void printfB(multimap<string, int> vec_)
{
    for (multimap<string, int>::iterator it = vec_.begin(); it != vec_.end(); it++)
    {
        std::cout << it->first  << "  " << it->second << std::endl;
    }
    cout << "�ݻ� = " << vec_.size() << endl;
}

int main()
{
    //����������
    std::map<int, std::string> m;
    m[3] = "h1";
    m[0] = "what";
    // ���� key-value
    m.insert(std::pair<int, std::string>(2, "love you"));

    std::cout << m[0].c_str() << std::endl;//�������� ��������ֵ��
    std::cout << m[3].c_str() << std::endl;
    std::cout << m[4].c_str() << std::endl;
    std::cout << m[2].c_str() << std::endl;   // �����һ���µ�Ԫ�أ���m[2] = ""

    m[6] = string("slam2345");
    std::cout << m.size() << std::endl;       // 5
    //����
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
            //����
            vecA.insert(std::pair<std::vector<int>, int>(pointTemp, (y * 4 + x + 1)));
            pointTemp.clear();
        }
    }
    printfA(vecA);
//***************************************************************************************************
//��ע�⡿����map��multimap��1�����߶����Զ����� 2��multimap���벻�Ḳ�����м�ֵ�ԣ�����map������ͬkey����ܾ����룩
//<1>���뷵��ֵ �ж��Ƿ����ɹ�
    //����������
    vector<int> pointTemp_ = { 1,2,3 }; // Insert�������ܸ��ǣ�������Ѿ����ڣ������ʧ�ܡ�ע�����λ�ã����Զ�����
    int a1 = 4;
    //�ж������Ƿ�ɹ�
    pair< map<vector<int>, int>::iterator, bool> isInsertOK;//ע����������
    isInsertOK = vecA.insert(pair<vector<int>, int>(pointTemp_, a1));
    cout << "����ɹ��� " << isInsertOK.second << endl;
    //��ӡ
    printfA(vecA);

//***************************************************************************************************
//<2>map����Ŀ��������븳ֵ
    map<vector<int>, int> vecB(vecA); //��������
    map<vector<int>, int> vecC;
    vecC = vecA;
    vecC.swap(vecA);
//***************************************************************************************************
//<3>����
     map<string, int> vecD;
    // ����Ϊ���������ʼ�� vecD������size����5�� ����insert�������ܸ��ǣ��������ǽ�map �ĳ� multimap
    vecD.insert(pair<string, int>((string)"china", 1));
    vecD.insert(pair<string, int>((string)"china", 2));//�ܾ�����
    vecD.insert(pair<string, int>((string)"china", 3));//�ܾ�����
    vecD.insert(pair<string, int>((string)"english", 1));
    vecD.insert(pair<string, int>((string)"english", 2));//�ܾ�����

    multimap<string, int> vecE;
    vecE.insert(make_pair((string)"china", 1));
    vecE.insert(make_pair((string)"china", 1));//�������
    vecE.insert(make_pair((string)"china", 3));//�������
    vecE.insert(make_pair((string)"china", 4));//�������
    vecE.insert(make_pair((string)"china", 5));//�������
    vecE.insert(make_pair((string)"english", 1));
    vecE.insert(make_pair((string)"english", 2));//�������
    vecE.insert(make_pair((string)"america", 1));
    vecE.insert(make_pair((string)"america", 2));//�������
    vecE.insert(make_pair((string)"america", 3));//�������
    cout << "multimap ��ʼ��" << endl;
    cout << "vecE����Ԫ��"<<endl;
    printfB(vecE);
    //��������
    multimap<string, int> ::iterator it1 = vecE.lower_bound("china");   //ָ��vecD�е�һ�����ڼ�ֵ ��china����Ӧ��Ԫ��
    multimap<string, int> ::iterator it2 = vecE.upper_bound("china");   //ָ��vecD�е�һ�����ڼ�ֵ ��china����Ӧ��Ԫ��
    cout << it1->first << " " << it1->second << endl;
    cout << it2->first << " " << it2->second << endl;
    // ���� = lower_bound + upper_bound
    pair<multimap<string, int>::iterator, multimap<string, int>::iterator > it3    = vecE.equal_range("china");
    map<string, int>::iterator it4 = it3.first;
    map<string, int>::iterator it5 = it3.second;

    //����key = ��china����ֵ�Եĸ���
    int iCount = vecE.count("china");

    //����key = ��china����Ӧ��ֵ��
    multimap<string, int>::iterator it6 = vecE.find("china");

//***************************************************************************************************
// <4>ɾ��
    multimap<string, int>::iterator itBegin = vecE.begin();
    // ɾ�� vecE ǰ������Ԫ�� �� ���� ����Ԫ��
    // �ڸ���������ƥ���㷨����ʵ��
    int index = 0;
    int vecA_size = vecE.size();
    //ɾ��(�Զ���ɾ���κ�Ԫ��)
    for (multimap<string, int>::iterator it_ = vecE.begin(); it_ != vecE.end(); )
    {
        //<1>��1
        //vecE.erase(it_++);
        //<2>��2
        if ((0<=index)&&(index<=2))
        {
            it_ = vecE.erase(it_);//����д����ָֹ��ʧЧ
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


    //ɾ��multimap��key = "english"�� ���� Ԫ��
    vecE.erase("english");
    cout << "vecEɾ��key = english�� ���� Ԫ�� " << endl;
    printfB(vecE);

    //ɾ������Ԫ��
    multimap<string, int>::iterator itBegin_ = vecE.begin();
    multimap<string, int>::iterator itEnd_ = vecE.end();
    vecE.erase(itBegin_, itEnd_);
    //bool isEmpty = vecE.empty();

    if (vecE.empty())
    {
        cout << "vecE�Ѿ������" << endl;
    }
    return 0;
}
