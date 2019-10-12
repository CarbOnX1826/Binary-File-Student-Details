//Binary File : Student Details
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
 class student
{
     char name[20];
     int rno,m1,m2,m3,tot;
     public :

	  void input();
	  void display();
	   int retrno();

};
 void student::input()
   {
    cout<<"* Enter Student Name : ";
    gets(name);
    cout<<"* Enter Students Rollno. : ";
    cin>>rno;
    cout<<"* Enter Marks of the 1st Subject : ";
    cin>>m1;
    cout<<"* Enter Marks of the 2nd Subject : ";
    cin>>m2;
    cout<<"* Enter Marks of the 3rd Subject : ";
    cin>>m3;
    tot=m1+m2+m3;
   }
 void student::display()
   {
    cout<<"\n * Student Name :"<<name;
    cout<<"\n * Rollno.  :"<<rno;
    cout<<"\n * Marks Obtained in 3 Subjects :"<<m1<<","<<m2<<","<<m3;
    cout<<"\n * Total Marks out of 300 :"<<tot<<"/300";
   }
  int student::retrno()
   {
     return(rno);
   }
   void WRITE()
   {
       ofstream f("stud.dat",ios::binary|ios::app);
       student S;
       char ch;
       do
      {
	S.input();
	f.write((char*)&S,sizeof(S));
	cout<<"\n Enter 'Y' or 'y' to add records : ";
	cin>>ch;
       }
	while(ch=='Y'||ch=='y');
	f.close();
   }
   void READ()
   {
       ifstream f("stud.dat",ios::binary|ios::in);
       student S;
       if(!f)
      {
	cout<<"\n File Doesn't Exist!!! ";
	getch();
	return;
      }
      int ctr=0;
      while(f.read((char*)&S,sizeof(S)))
      {
	 cout<<"\n Record :"<<++ctr;
	 S.display();
	 getch();
      }
      f.close();
   }
   void MODIFY()
   {
     fstream f("stud.dat",ios::in|ios::out|ios::binary);
     student S;
     int studno;
     cout<<"\n Enter the Student No. to be modified : ";
     cin>>studno;
     int rec_count=0;
     char found = 'N';
     while(f.read((char*)&S,sizeof(student)))
    {
      if(S.retrno()==studno)
     {
       cout<<"\n Enter the New Information " ;
       S.input();
       f.seekg(rec_count*sizeof(student),ios::beg);
       f.write((char*)&S,sizeof(student));
       found='Y';
       break;
     }
      rec_count++;
    }
      if(found=='Y')
	 cout<<"\n Record Updated";
      else
	 cout<<"\n Record Not Found";
	 f.close();
   }
    void main()
   {
     int ch;
     do
    {
       clrscr();
       cout<<"\n\n\n**------MENU------**";
       cout<<"\n 1. Create or Append Record";
       cout<<"\n 2. Display all Records";
       cout<<"\n 3. Modification of the Record";
       cout<<"\n 4. Exit";
       cout<<"\n Enter your Choice : ";
       cin>>ch;
       switch(ch)
       {
	   case 1: WRITE();
		    break;
	   case 2: READ();
		    break;
	   case 3: MODIFY();
		    break;
	   case 4: exit(0);
	  default: cout<<" WRONG CHOICE!!!";
		    break;
	   }
		   cout<<"\n Press any key to continue";
	   getch();
       } while(1);
    }
