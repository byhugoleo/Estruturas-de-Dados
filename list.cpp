//Implementation of a static list
#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100 // Max size of the list can be changed by any integer

struct Data  {
//Methods
    void set_Info(int info){
        this->info = info;
    }
    int get_Info() {
        return info;
    }

private:
//Data-Properties
    int info;
};

class List 
{
//Data-Properties
    Data info[MAX_SIZE];
    int cur_size;

public:
//Constructors-Destructors
    List();
    ~List();

//Methods
    void Insert(int, int); // Args (data, position in the list to insert) 
    void Erase(int); // Args (position in the list to delete)
    void push_Back(int); // Args (data)
    void push_Front(int); // Args (data)
    void pop_Back();
    void pop_Front();
    bool Search(int); // Args (data to be searched)

private: 
//Methods for internal opereations
    void shift_L(int);
    void shift_R(int);
};

//Implementation of methods
List::List() : cur_size(0) { };

List::~List() {}

void List::shift_L(int pos)
{
    for (int i = pos; i < cur_size - 1; i++)
        info[i].set_Info(info[i + 1].get_Info());
    cur_size--;
}

void List::shift_R(int pos)
{
    for(int i = cur_size; cur_size > pos; i--)
        info[i].set_Info(info[i - 1].get_Info());
    cur_size++;
}

void List::Insert(int data, int pos)
{
    if (pos < 0 or pos >= MAX_SIZE or pos > cur_size) {
        cout << "Invalid Position or Full List!!!\n\n";
        return;
    }
    shift_R(pos);
    info[pos].set_Info(data);
}

void List::Erase(int pos)
{
    if (pos < 0 or pos > cur_size) {
        cout << "Invalid Position!!!\n\n";
        return;
    }
    shift_L(pos);
    info[cur_size + 1].set_Info(0);
}

void List::push_Back(int data)
{
    if (cur_size + 1 >= MAX_SIZE) {
        cout << "Full List!!!\n\n";
        return;
    }
    info[cur_size].set_Info(data);
    cur_size++;
}

void List::push_Front(int data)
{
    Insert(data, 0);
}

void List::pop_Back()
{
    //TODO
}

void List::pop_Front()
{
    //TODO
}

int main()
{
    //TODO
}