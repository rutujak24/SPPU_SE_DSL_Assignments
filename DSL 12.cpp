//============================================================================
// Name        : sort.cpp
// Author      : anuja
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<ctime>
using namespace std;
#define max 10
class sort
{
	float* num;
	int n;
public:
	sort()
{
		cout<<"no of students"<<endl;
		cin>>n;
		num=new float[n];
}
	void input();
	void output();
	void bubble();
	void insertion();
	void selection();
	void shell();
};
void sort::input()
{
	cout<<"enter percentage";
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
}
void sort::output()
{
	cout<<"sorted array is:"<<"   ";
	for(int i=0;i<n;i++)
		{
			cout<<num[i]<<"  ";
		}
	cout<<endl;
}
void sort::bubble()
{
	int temp;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j<n-1;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
}
void sort::selection()
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(num[i]>num[j])
			{
				swap(num[i],num[j]);
			}
		}
	}
}
void sort::insertion()
{
	int temp;
	for(int i=1;i<n;i++)
	{
		temp=num[i];
		int j=i-1;
		while(num[j]>temp && j>=0)
		{
			num[j+1]=num[j];
			num[j]=temp;
			j=j-1;

		}
		num[j+1]=temp;
	}
}
void sort::shell()
{
	int j;
	for(int gap=n/2;gap>0;gap=gap/2)
	{
		for(int i=gap;i<n;i++)
		{
			int temp=num[i];
			for( j=i;j>=gap && num[j-gap]>temp;j=j-gap)
			{
				num[j]=num[j-gap];

			}
			num[j]=temp;
		}
	}
}


int main()
{
	int k=1;
	sort s;
	s.input();



	int choice;
	do
	{
		cout<<"1 for bubble"<<endl<<"2 for selection"<<endl<<"3 for insertion"<<endl<<"4 for shell"<<endl;
		cout<<"enter choice";
		cin>>choice;
		int time=clock();
		switch(choice)
		{
		case 1:s.bubble();
		       cout<<endl<<clock()-time<<endl;
		       s.output();
		       break;
		case 2: s.selection();
		       cout<<endl<<clock()-time<<endl;
		        s.output();
				break;
		case 3: s.insertion();
		       cout<<endl<<clock()-time<<endl;
		        s.output();
		        break;
		case 4:s.shell();
		       cout<<endl<<clock()-time<<endl;
		       s.output();
		       break;

		}
	}while(choice<=4);

    return 0;
}
