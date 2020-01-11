/*Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
I. The average score of class
II. Highest score and lowest score of class
III. Marks scored by most of the students
IV. list of students who were absent for the test.*/

#include <iostream>
using namespace std;

 class result
 {
	 int marks;
 public:
	 void getdata( );
	 
	 void minmax(int n, result obj[]);

	 void   absent(int n,result obj[]);
	 void mostprob(int n,result obj[]);
     void res();
     
     int givemarks()
     {
    	 return(this-> marks);
     }
 };

 void result:: getdata()
 {
  cout<<"enter the marks of students"<<endl;
   cin>>marks;
 }

void result:: minmax(int n, result obj[])

	{
	 		      int i;
	 		 	 int maxx=0;
	 		 	 int minn=100;
	 		 	 for(i=0;i<n;i++)
	 		 	 {  maxx= max(maxx ,obj[i].givemarks());
	 		        minn=min(minn,obj[i].givemarks());
	 		 	 }
	 		 	 cout<<"highest:"<<maxx<<endl;

	 		 	 cout<<"lowest:"<<minn<<endl;
	 		 }




void result::absent(int n,result obj[])
{   int i;
	int temp=0;
	 for(i=0;i<n;i++)
	 {if(obj[i].marks==0)
		 temp++;
	 }
	 cout<<temp<<" "<<"students are abs."<<endl;

}
void result::mostprob(int n, result obj[])
{

     int i,j,maxf=0;
    int m[n];
    for(i=0;i<n;i++)
    {
        m[i]=0;
    }

	for(i=0;i<n;i++)
	{
	    for(j=i;j<n;j++)
        {
            if(obj[i].marks==obj[j].marks)
            {
                m[i]++;
            }
        }
	}
	int k=0;
	int maxii=m[0];
	for(i=1;i<n;i++)
    {

        if(maxii<m[i])
        {
            maxii=m[i];
             k=i;
        }

    }

        cout<<k;
		//maxf=max(maxf,m[n]);
		cout<<"most prob marks are:"<<obj[k].marks<<"its fre. is"<<maxii<<endl;
}

  int main()
 {   int i,n;
     cin>>n;
	 result obj[n];
	 for (i=0;i<n;i++)
	 {
		 obj[i].getdata();

	 }
	   int avgt;
		int total=0;
		for(i=0;i<n;i++)
			  total=obj[i].givemarks() +total;
	avgt=total/n;
    cout<<avgt<<" "<<"is the average"<<endl;
	 obj[n].minmax(n,obj);
	 obj[n].absent(n,obj);

     obj[n].mostprob(n,obj);

return 0;

 }


