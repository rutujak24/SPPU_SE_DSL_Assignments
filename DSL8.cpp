/*Implement C++ program for expression conversion as infix to postfix 
and its evaluation using stack based on given conditions:  Operands and
 operator, both must be single character, Input Postfix expression must be in a desired 
 format, Only '+', '-', '*' and '/ ' operators are expected*/
 
 
#include <iostream>
using namespace std;
#include<string>
class stack;
class node
{
	char ch;
	int num;
	node* prev;
	public:
	node()
	{
		ch='\n';
		num =0;
		prev = NULL;
	}
	friend class stack;
};
class stack
{
	node* top;
	public:
	stack()
	{
		top = NULL;
	}
	void push(char);
	void push(int);
	void pop();
	char givetop();
	int givetopnum();
	bool isempty();
	friend bool precedence(char a,char b);
};
char stack::givetop()
{
	return top->ch;
}
int stack::givetopnum()
{
	return top->num;
}
void stack::push(int n)
{
	if(top == NULL)
	{
		top=new node;
		top->num=n;
	}
	else
	{
		node* tmp = new node;
		tmp->num=n;
		tmp->prev=top;
		top = tmp;
		tmp=NULL;
	}

}
void stack::push(char ch)
{
	if(top == NULL)
	{
		top=new node;
		top->ch=ch;
	}
	else
	{
		node* tmp = new node;
		tmp->ch=ch;
		tmp->prev=top;
		top = tmp;
		tmp=NULL;
	}
}
void stack::pop()
{
	if(top==NULL)
	{
		cout<<"stack is Empty! ";
	}
	else if(top->prev == NULL)
	{
		delete top;
		top=NULL;
	}
	else
	{
		node* tmp;
		tmp=top;
		top=top->prev;
		tmp->prev=NULL;
		delete tmp;
		tmp=NULL;
	}
}
bool stack::isempty()
{
	if(top==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool precedence(char a,char b)
{
	char arr[4];
	arr[0] = '-';
	arr[1] = '+';
	arr[2] = '*';
	arr[3] = '/';
	int i=0,j=0;
	int t=0;
	while(t != 3)
	{
		if(a == arr[t])
		{
			i=t;
		}
		if(b == arr[t])
		{
			j=t;
		}
		t++;
	}
	return (i<j);

}
int main()
{
	stack s;
	stack s_new;
	string str;
	cout<<"Enter equation: "<<endl;
	cin>>str;
	int j=0;
	string arr;
	for(int i=0;i<str.length();i++)
	{
		switch(str[i])
		{
		case '(':s.push(str[i]);
		break;
		case ')':
		while(s.givetop() != '(')
		{
			arr[j++] = s.givetop();
			s.pop();
		}
		s.pop();
		break;
		case '+':
		case '-':
		case '*':
		case '/':
		while(!s.isempty() && s.givetop() != '(' && precedence(str[i],s.givetop()))
		{
			arr[j++] = s.givetop();
			s.pop();
		}
		s.push(str[i]);
		break;
		default:
		arr[j++]=str[i];
		}
	}
	while(!s.isempty())
	{
		arr[j++] = s.givetop();
		s.pop();
	}
	for(int k=0;k<j;k++)
	{
		cout<<arr[k];
	}
	cout<<endl;
		int x=0,y=0;
		for(int i=0;i<str.length();i++)
		{
			switch(arr[i])
			{
			case 'a':
				int var;
				cout<<"Enter value of a: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'b':
				cout<<"Enter value of b: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'c':
				cout<<"Enter value of c: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'd':
				cout<<"Enter value of d: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'e':
				cout<<"Enter value of e: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'f':
				cout<<"Enter value of : ";
				cin>>var;
				s_new.push(var);
				break;
			case 'g':
				cout<<"Enter value of g: ";
				cin>>var;
				s_new.push(var);
				break;
			case 'h':
				cout<<"Enter value of h: ";
				cin>>var;
				s_new.push(var);
				break;
			case '+': y=s_new.givetopnum();
			s_new.pop();
			x=s_new.givetopnum();
			s_new.pop();
			s_new.push((x+y));
			break;
			case '-': y=s_new.givetopnum();
			s_new.pop();
			x=s_new.givetopnum();
			s_new.pop();
			s_new.push((x-y));
			break;
			case '*': y=s_new.givetopnum();
			s_new.pop();
			x=s_new.givetopnum();
			s_new.pop();
			s_new.push((x*y));
			break;
			case '/': y=s_new.givetopnum();
			s_new.pop();
			x=s_new.givetopnum();
			s_new.pop();
			s_new.push((x/y));
			break;
			default:{}
			}
		}
		cout<<s_new.givetopnum()<<endl;

	return 0;
}
