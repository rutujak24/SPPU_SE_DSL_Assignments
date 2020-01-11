/*Write a C++ program to realize polynomial equation using circular link list and perform following operation
To input &output polynomials 
Evaluates a polynomial at given value of x 
Add two polynomials. */


#include<iostream>
using namespace std;
class node
{
	int degree,coe;
	node*next;
	public:
		node(int d,int c)
		{
			next=NULL;
			degree=d;
			coe=c;
		}
		friend class cll;
};
class cll
{
	node*head;
	public:
		cll()
		{
			head=NULL;
		}
		void create();
		void show(); 
		void add(cll);
};
void cll::create()
{
	node*p;
	int d,c,n;
	cout<<"enter total terms in polynomial"<<endl;
	cin>>n;
	cout<<"enter degree and coe"<<endl;
	cin>>d>>c;
	head=new node(d,c);
	p=head;
	head->next=head;
	for(int i=1;i<n;i++)
	{
		
	cout<<"enter degree and coe"<<endl;
	cin>>d>>c;
		p->next=new node(d,c);
		p=p->next;
		p->next=head;
	}
}
void cll::show()
{
	node*p=head;
	do
	{
		cout<<p->coe<<"x^"<<p->degree;
		p=p->next;
		if(p!=head)
		{
			cout<<"  "<<"+"<<" ";
		}
	}while(p!=head);
}
void cll::add(cll obj1)
{
	node*r,*t;int i=0;
	node*p=head;
	node*q=obj1.head;
if(p->degree==q->degree)
{
		r=new node(p->degree,p->coe+q->coe);
		t=r;
		p=p->next;
		q=q->next;
		t->next=r;
		while(p!=head && q!=obj1.head)
		{
	
				if(p->degree==q->degree)
				{
					t->next=new node(p->degree,p->coe+q->coe);
					p=p->next;
					q=q->next;
					t=t->next;
					t->next=r;
				}
				else
				{
						if(p->degree>q->degree)	
						{
							t->next=new node(p->degree,p->coe);
							p=p->next;
							t=t->next;
							t->next=r;
						}
						else
						{
							t->next=new node(q->degree,q->coe);
							q=q->next;
							t=t->next;
							t->next=r;
						}
				}
		}
    
  if(p!=head)
	{
		while(p!=head)
		{
			t->next=new node(p->degree,p->coe);
			p=p->next;
			t=t->next;
			t->next=r;
		}
	}
  if(q!=obj1.head)
	{
		
		while(q!=obj1.head)
		{
			t->next=new node(q->degree,q->coe);
			q=q->next;
			t=t->next;
			t->next=r;
		}
	}
	
}
else
{
	if(p->degree>q->degree)	
	{
		r=new node(p->degree,p->coe);
		t=r;
		p=p->next;
		t->next=r;
		while(p!=head)
		{
			if(p->degree==q->degree)
			{
				t->next=new node(p->degree,p->coe+q->coe);
				p=p->next;
				q=q->next;
				t=t->next;
				t->next=r;
			}
			else
			{
						if(p->degree>q->degree)	
						{
							t->next=new node(p->degree,p->coe);
							p=p->next;
							t=t->next;
							t->next=r;
						}
						else
						{
							t->next=new node(q->degree,q->coe);
							q=q->next;
							t=t->next;
							t->next=r;
							if(q==obj1.head)
							{
								break;
							}
						}
			}
					
		}
		while(p!=head)
		{
			t->next=new node(p->degree,p->coe);
			p=p->next;
			t=t->next;
			t->next=r;
		}
		while(q!=obj1.head)
		{
			t->next=new node(q->degree,q->coe);
			q=q->next;
			t=t->next;
			t->next=r;
		}
		do
		{
			i++;
			q=q->next;
		}while(q!=obj1.head);
		if(i==1)
		{
			t->next=new node(q->degree,q->coe);
			t=t->next;
				t->next=r;
						}				
				
	}
	else
	{
		r=new node(q->degree,q->coe);
		t=r;
		q=q->next;
		t->next=r;
		while(q!=obj1.head)
		{
			if(p->degree==q->degree)
			{
				t->next=new node(p->degree,p->coe+q->coe);
				p=p->next;
				q=q->next;
				t=t->next;
				t->next=r;
			}
			else
			{
						if(p->degree>q->degree)	
						{
							t->next=new node(p->degree,p->coe);
							p=p->next;
							t=t->next;
							t->next=r;
								if(p==head)
							{
								break;
							}
						}
						else
						{
							t->next=new node(q->degree,q->coe);
							q=q->next;
							t=t->next;
							t->next=r;
						}
			}
					
			
		}
		while(p!=head)
		{
			t->next=new node(p->degree,p->coe);
			p=p->next;
			t=t->next;
			t->next=r;
		}
		while(q!=obj1.head)
		{
			t->next=new node(q->degree,q->coe);
			q=q->next;
			t=t->next;
			t->next=r;
		}
		do
		{
			i++;
			p=p->next;
		}while(p!=head);
		if(i==1)
		{
			t->next=new node(p->degree,p->coe);
			t=t->next;
				t->next=r;
						}				
				
		
	}
}

node*u=r;
	do
	{
		cout<<u->coe<<"x^"<<u->degree;
		u=u->next;
		if(u!=r)
		{
			cout<<"+";
		}
	}while(u!=r);
}
int main()
{
	cll obj,obj1;
	obj.create();
	obj1.create();
	obj.show();
	cout<<endl;
	obj1.show();
	cout<<endl;
	obj.add(obj1);
}

