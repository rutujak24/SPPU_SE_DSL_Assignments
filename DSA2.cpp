#include <iostream>

using namespace std;
class str
{
    char a[20],b[20],c[20],d[20],e[20],g[20],h[30];
public:
    void getdata()
    {   cout<<"enter string a"<<endl;
       cin.getline (a,20);
        cout<<"enter string b"<<endl;
        cin.getline (b,20);
    }
    void lenght()
    {   int lenght=0,fan=0;
        while(a[lenght]!='\0')
        {
            lenght++;
        }
        cout<<"length of a is "<<lenght<<endl;
        while(b[fan]!='\0')
        {
            fan++;
        }
         cout<<"length of b is "<<fan<<endl;
    }
    void concat()
    {
        cout<<"string a is:"<<a<<endl;
        cout<<"string b is:"<<b<<endl;
        cout<<"the concatination string is :"<<a<<b<<endl;
    }
    void reversestr()
    {   int i;
        char temp='\0';
        int nel=0,fan=0;
        while(a[nel]!='\0')
         {
             nel++;
         }

        for(i=0;i<nel/2;i++)
             {   temp=a[i];
                 a[i]=a[nel-i-1];
                 a[nel-i-1]=temp;
             }

        cout<<a<<endl;
        while(b[fan]!='\0')
         {
             fan++;
         }

        for(i=0;i<fan/2;i++)
             {   temp=b[i];
                 b[i]=b[fan-i-1];
                 b[fan-i-1]=temp;
             }

        cout<<b<<endl;
 }
    void strequal()
{
    int nel=0,i,count=0;
        while(a[nel]!='\0')
         {
             nel++;
         }
         int fan=0;
        while(b[fan]!='\0')
         {
             fan++;
         }
         int mux;
         mux=nel>fan?nel:fan;
         for(i=0;i<mux;i++)
         {
             if(a[nel-1-i]==b[fan-1-i])
             {
                 count++;
             }
         }
         if(count == nel)
         {
        	 cout<<"strings are equal"<<endl;
         }
         else
         {
        	cout<<"strings are not equal"<<endl;
         }
}
    void copystr()
    {
        int i,nel=0,temp=0;
        while(a[nel]!='\0')
         {
             nel++;
         }
        for(i=0;i<nel/2;i++)
         {   temp=a[i];
              a[i]=a[nel-i-1];
              a[nel-i-1]=temp;
          }
         for (i=0;i<nel;i++)
         {
             c[i]=a[i];
         }
         cout<<"the copied string is "<<c<<endl;
    }
    void substring()
    {   int i=0;
    char temp='\0';
    int nel=0,fan=0;

   while(b[fan]!='\0')
     {
         fan++;
     }

    for(i=0;i<fan/2;i++)
         {   temp=b[i];
             b[i]=b[fan-i-1];
             b[fan-i-1]=temp;
         }


    	int j=0,flag=0,x=0;
    		    	while(a[nel]!='\0')
    		        {
    		    	    nel++;
    		        }

    		    	 while(b[fan]!='\0')
    		         {
    		           fan++;
    		         }

    		    	 for( i=0;i<nel&&flag==0;i++)
    		         {
    		    		x=i;
    		    	    if(b[0]==a[x])
    		    	    { flag=1;
    		    		  for(j=1;j<fan;j++)
    		    		  { x++;
    		    		    if(b[j]!=a[x])
    		    		    {
    		    		    	flag=0;
    		    		    }

    		    		  }
    		    		}
    		    	  }


    		        if(flag==1)
    		    	{
    		    		cout<<b<<":is subtring of:" <<a<<endl;
    		    	}
    		    	else
    		    	{
    		    		cout<<"there is no sub string"<<endl;
    		    	}


    }
    void delete1()
    {
    	int n,m;
    	cout<<"enter the index to start delete"<<endl<<"enter the no. characters to delete"<<endl;
    	cin>>m>>n;
    	int i,k,j=0,nel=0;
    	        while(a[nel]!='\0')
    	         {
    	             nel++;
    	         }
    	        for (i=0;i<nel;i++)
    	                {
    	                    d[i]=a[i];
    	                }
                      d[nel]='\0';
    	        while(d[j]!='\0')
    	        {
    	        	for(k=m;k<(m+n);k++)
    	        	{
    	        		d[k]= ' ';
    	        	}
    	            j++;

    	        }
    	        cout<<d<<endl;

    }
    void delete2()
    {
    	int i,j=0,nel=0;
        while(a[nel]!='\0')
        {
         nel++;
        }
        for (i=0;i<nel;i++)
               {
                   e[i]=a[i];
               }
        e[nel]='\0';
        char h;
        cout<<"enter the char. whose occurance is to be removed from string a"<<endl;
        cin>>h;
        while(e[j]!='\0')
        {
            if(e[j]==h)
            {
            	e[j]=' ';
            }
            j++;
        }
        cout<<e<<endl;


    }
    void palindrome()
    {
    	int i=0,nel=0,temp=0;
        while(a[nel]!='\0')
        {
         nel++;
        }

    	while(a[i]!='\0')
    	{
    		if( a[i]==a[nel-1-i])
    		{	temp++;
    		}

    		i++;
    	}
        if(temp == nel)
        {
        	cout<<a<<" : is a palindrome"<<endl;
        }
        else
        {
        	cout<<a<<" : is not a palindrome"<<endl;
        }

    }

void frequency()
{
	cout<<"enter a character to find its frequency"<<endl;
	char h;
	cin>>h;
	int temp=0,i=0;
	   while(a[i]!='\0')
	   {
	     if( a[i]==h)
	     {	temp++;
	     }
	    i++;
	   }
	   cout<<"its frequency is:"<<temp<<endl;
}
void replace()
{
	    int i=0;
	    // char temp='\0';
	    int nel=0,fan=0;

         	    	int j=0,flag=0,x=0,p=0,q=0;
	    		    	while(a[nel]!='\0')
	    		        {
	    		    	    nel++;
	    		        }

	    		    	 while(b[fan]!='\0')
	    		         {
	    		           fan++;
	    		         }

	    		    	 for( i=0;i<nel&&flag==0;i++)
	    		         {
	    		    		x=i;
	    		    	    if(b[0]==a[x])
	    		    	    { flag=1;
	    		    		  for(j=1;j<fan;j++)
	    		    		  { x++;
	    		    		    if(b[j]!=a[x])
	    		    		    {
	    		    		    	flag=0;
	    		    		    }
                                p=i;
	    		    		  }
	    		    		}
	    		    	  }


	    		        if(flag==1)
	    		    	{
	    		    		cout<<b<<":is subtring of:" <<a<<endl;
	    		    	}
	    		    	else
	    		    	{
	    		    		cout<<"there is no sub string"<<endl;
	    		    	}
	    		       cout<<"enter the substring viz to be replaced with" <<endl;
	    		     //  char g[20],h[30];
	    		       cin.getline (g,20);
	    		       int k=0,l=0,m=0,n=0;
	    		       while(g[m]!='\0')
	    		       {
	    		    	   m++;
	    		       }
	    		       for(k=0;k<p;k++)
	    		       {
	    		    	   h[k]=a[k];
	    		       }
	    		       for(k=p;k<(p+m);k++)
	    		       {
	    		    	   h[k]=g[l];
	    		    	   l++;
	    		       }
	    		      /* for(k=(p+m);k<(p+m+(nel-(p+fan)));k++)
	    		       {
	    		    	   h[k]=a[p+fan+q];
	    		    	   q++;
	    		       }
	    		       cout<<h;*/
	    		       k=(p+m);
	    		       n=(p+fan);
	    		       while(a[n] != '\0')
	    		       {
	    		    	   h[k]=a[n];
                           k++;
	    		    	   n++;
	    		       }
	    		       h[(p+m+(nel-(p+fan)))]='\0';

	    		       cout<<h<<endl;







}


};

int main()
{
 str f;
 f.getdata();
 f.lenght();
 f.concat();
 f.reversestr();
 f.strequal();
 f.copystr();
 f.substring();
 f.replace();
 f.delete1();
 f.delete2();
 f.palindrome();
 f.frequency();

    return 0;
}
