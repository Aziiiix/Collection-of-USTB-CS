#include<iostream>
using  namespace  std;

struct  Node {
    int  data;
    Node* next;
};

class  List {
protected:
    Node* node;
public:
    List()
    {
        node = new Node;
        node->data = 0;
        node->next = NULL;
    }
    virtual void Insert(int num)
    {
        Node* station = new Node;
        station->data = num;
        station->next = node->next;
        node->next = station;
    }
    virtual void Delete(int num)
    {
        for (Node* ser = node; ser != 0;)
        {
            if (ser->next == 0)return;
            if ((ser->next)->data == num)
            {
                Node* station = ser->next;
                ser->next = (ser->next)->next;
                delete station;
                continue;
            }
            ser = ser->next;
        }
    }
    void  Print()
    {
        if (node->next == 0)
            return;
        Node* n = node->next;
        for (; n != 0; n = n->next)
            cout << n->data << "  ";
        cout << endl;
    }
};

class  Set : public  List {
public:
    Set(){}
    void Insert(int num)
    {
        for (Node* n = node->next; n != 0; n=n->next)
        {
            if (n->data == num)return;
        }
        Node* station = new Node;
        station->data = num;
        station->next = node->next;
        node->next = station;
    }
};

int  main()
{
    List* p, list1;
    Set  set1;
    p = &list1;
    char  opt;
    while (cin >> opt) {
        if (opt == '?')  break;
        int  num;
        cin >> num;
        if (opt == 'i') {
            p->Insert(num);
        }
        else  if (opt == 'd') {
            p->Delete(num);
        }
    }
    p->Print();

    p = &set1;
    while (cin >> opt) {
        if (opt == '?')  break;
        int  num;
        cin >> num;
        if (opt == 'i') {
            p->Insert(num);
        }
        else  if (opt == 'd') {
            p->Delete(num);
        }
    }
    p->Print();
    return  0;
}
