#include <iostream>
using namespace std;
class Nod
{
    public:
    int value;
    Nod *next;
    Nod(int value)
    {
        this->value=value;
        this->next=NULL;
    }
};
class List
{
    public:
    Nod *first=NULL;
    Nod *last=NULL;
    void push_back(int value)
    {
        if (first==NULL)
        {
            first=new Nod(value);
            last=first;
        }
        else
        {
            last->next=new Nod(value);
            last=last->next;
        }
    }
    void print()
    {
        Nod *head;
        for (head=first;head!=NULL;head=head->next)
            cout<<head->value<<" ";
    }
    void push_front(int value)
    {
        if (first==NULL)
            push_back(value);
        else
        {
            Nod *aux=new Nod(value);
            aux->next=first;
            first=aux;
        }
    }
    void pop_back()
    {
        if (first==NULL)
            return;
        else if (first->next==NULL)
        {
            delete first;
            first=NULL;
        }
        else
        {
            Nod *head;
            for (head=first;head->next->next!=NULL;head=head->next)
                continue;
            delete last;
            head->next=NULL;
            last=head;
        }
    }
    void pop_front()
    {
        if (first==NULL || first->next==NULL)
            pop_back();
        else
        {
            Nod *aux=first->next;
            delete first;
            first=aux;
        }
    }
};
int main()
{
    List x;
    x.push_back(4);
    x.push_back(6);
    x.push_front(8);
    x.push_front(1);
    x.pop_back();
    x.pop_front();
    x.print();
}