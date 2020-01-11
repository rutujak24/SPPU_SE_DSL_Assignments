/*Implement C++ program for expression conversion as infix to 
postfix and its evaluation using stack based on given conditions:  
Operands and operator, both must be single character, Input Postfix 
expression must be in a desired format, Only '+', '-', '*' and '/ ' operators are expected*/

#include <iostream>
using namespace std;
class job
{
	string name;
	string time;
	public:
	job()
	{
		name = "";
		time = "";
	}
	void getdata();
	void putdata();
};
void job::getdata()
{
	cout<<"Enter Job Name: ";
	cin>>name;
	cout<<"Enter Duration of Job: ";
	cin>>time;
}
void job :: putdata()
{
	cout<<"Job Name: "<<name<<endl;
	cout<<"Duration of Job: "<<time;
}
class queue;
class node
{
	job data;
	node* next;
    public:
	node()
    {
		next = NULL;
    }
	friend class queue;
};
class queue
{
	node* front;
	node* rear;
	public:
	queue()
	{
		front = rear = NULL;
	}
	void push(job);
	void pop();
	bool isempty();
	job givefront();
	friend void print_data(queue);
};
void print_data(queue jobs)
{
	while(!jobs.isempty())
	{
		job j=jobs.givefront();
		j.putdata();
		jobs.pop();
		cout<<endl;
	}
}
void queue::push(job data)
{
	if(front == NULL)
	{
		rear = front = new node;
		front->data = data;
	}
	else
	{
		node* tmp = new node;
		tmp->data = data;
		rear->next = tmp;
		rear = rear ->next;
		tmp = NULL;
	}
}
void queue::pop()
{
	if(front != NULL)
	{
		node* tmp = front;
		front = front -> next;
		delete tmp;
		tmp = NULL;
	}
	else
	{
		cout<<"Underflow! "<<endl;
	}
}
bool queue::isempty()
{
	if(front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
job queue::givefront()
{
	if(front == NULL)
	{
		cout<<"Underflow!"<<endl;
	}
	return front->data;
}


int main()
{
	queue jobs;
	int t=1;
	job j;
	while(t)
	{
		cout<<"------------------------------------------------------------------------"<<endl;
		cout<<"Enter Choice:\n1.Add Job.\n2.Delete Job.\n3.Display Jobs.\n4.Exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice)
		{
		case 1:
			j.getdata();
			jobs.push(j);
			break;
		case 2:
			if(jobs.isempty() == 1)
			{
				cout<<"Queue is Empty! "<<endl;
			}
			else
			{
				jobs.pop();
				cout<<"Job Deleted"<<endl;
			}
			break;
		case 3:
			cout<<"Job List is: "<<endl;
			print_data(jobs);
			break;
		case 4:
			t=0;
			break;
		default:
			cout<<"Wrong choice! "<<endl;
		}
	}
	return 0;
}
