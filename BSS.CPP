#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<math.h>
#include<complex.h>
#include<graphics.h>
//Graphics are kept in comments as code::blocks doesn't have inbuilt graphics.h library
//To execute graphics comments must be removed from line 26,32,1112 and 1234s
fstream f;char u[20];
class log
{
    public:
	char u[20],p[20];
    log(char a[],char b[])
    {
	strcpy(u,a);
	strcpy(p,b);
    }
    log(){};
};
class udata
{
    public:
    char u[20],tno[7],name[20],add[50],pass[15],mob[11]; char des[10],fid[7];
    int time[2],price;
}user;
class chart
{   public:
    char fid[7];char des[10],arr[10];int time[2],price,stat;
    chart(char Fid[],char Des[],char Arr[], int Time[2],int Price,int Stat)
    {
    strcpy(fid,Fid); strcpy(des,Des); strcpy(arr,Arr);
    time[0]=Time[0],time[1]=Time[1],price=Price,stat=Stat;
    }
    void copy(char Fid[],char Des[],char Arr[], int Time[2],int Price,int Stat)
    {
    strcpy(fid,Fid); strcpy(des,Des); strcpy(arr,Arr);
    time[0]=Time[0],time[1]=Time[1],price=Price,stat=Stat;
    }
    chart(){};

}c;
void p2(),o1(),o2(),mainm(),signup(),getp(char *),update(),chart(class udata*);
void delsel(char[]),delt(),upsel(char[]),bin(char*),input(),showall(),exits(),tgen(class udata *);
void tup(),showsel(),bs(int),screen2(),lscreen(),screen1(),show(class udata);
void bill(),sprice(int),declarechart(),schart(),printstat(int);
int sverify(),nentry(),sos(),real(),passf(),pos(),los(),NEW(),gprice(int),stat(int),save();
float deg(float),x(float,float,float),y_txt(int ,int , double),x_txt(float ,float , float),y(float,float,double),n(float); void entry();
void city(int,int),imap(),city_xy(int , float *, float *);int city_num(const char name[] ),arrcity(int ,int arr[][11] );const char *city_name(int );
int depcity();
int main()
{   fstream f;
    class log x("bsh","xyz");
    f.open("abc.dat",ios::app|ios::binary);
    f.write((char*)&x,sizeof(class log));
    entry();
    f.close();
    declarechart();
    screen1();
    exits();
    return 0;
}

void screen1()
{
    if(pos()==1)
	lscreen();
    else
    {   b:
	clrscr();
	 if(sverify()==1)
	 { while(1)
	     switch(sos())
	    {
		case 1:showall(); break;
		case 2:tup();break;
		case 0:if(real()==1)screen1();
			else continue;
	    }
	 }
	 else
	 {
	     printf("\n\t\t\t\t!!!!!WRONG PASSWORD!!!!\n\n\t\t\t\t  !!!!TRY AGAIN!!!!\n");
	     printf("\n\n\t\tPress Esc to go back or ENTER to re-try");
	     if(getch()==13)
		goto b;
	     else screen1();

	 }

    }
}

void screen2()
{
    while(1)
    {clrscr();
	switch(NEW())
    {
	case 1:input();break;
	case 2:showsel(); break;
	case 3:update();break;
	case 4: delt();break;
	case 5:bill();break;
	case 6:schart();break;
	case 7: if(real()==1)lscreen();
		else continue;
		break;
    }
    }
}
void lscreen()
{if(los()==1)
	    {   b:
		if(passf()==1)
		{
		mainm();screen2();
		}
		else
		{
		cout<<"\n\t\t\t\t!!!!!WRONG PASSWORD!!!!\n\n\t\t\t\t  !!!!TRY AGAIN!!!!\n";
		cout<<"\n\n\t\tPress Esc to go back or ENTER to re-try";
		if(getch()==13)
		    goto b;
		else screen1();

		}
	    }
	  else signup();
}
int NEW()
{
    int opt=1;
    while(1)
    {
	clrscr();
	cout<<"BACK(press Esc)\n\n\n\n\n\n\n\t\t\t\tWELCOME TO OUR AIRLINE "<<endl;
		cout<<"\t\t\t";if(opt==1)cout<<"->";else cout<<"  "; cout<<"*To Book Ticket..."<<endl;
		cout<<"\t\t\t";if(opt==2)cout<<"->";else cout<<"  "; cout<<"*To Check your ticket...."<<endl;
		cout<<"\t\t\t";if(opt==3)cout<<"->";else cout<<"  "; cout<<"*to Modify your tickets..."<<endl;
		cout<<"\t\t\t";if(opt==4)cout<<"->";else cout<<"  "; cout<<"*To Cancel your ticket..."<<endl;
		cout<<"\t\t\t";if(opt==5)cout<<"->";else cout<<"  "; cout<<"*To Print Bill..."<<endl;
		cout<<"\t\t\t";if(opt==6)cout<<"->";else cout<<"  "; cout<<"*To Print Flight Chart..."<<endl;
		cout<<"\t\t\t";if(opt==7)cout<<"->";else cout<<"  "; cout<<"*to Log out..."<<endl;

	switch(getch())
	{
	    case 72: if(opt>1)opt--;break;
	    case 80 :if(opt<7)opt++;break;
	    case 13 :return opt;
	    case 27: if(real()==1)lscreen();
		    else continue;
		    break;
	};


    }

}

void input()
{   clrscr();
fflush(stdin);
    class udata user;
cout<<"                                   Ticket Booking\n\n\n";
cout<<"                                   Enter Details:\n\n\n\n";

cout<<"                                  Name: ";gets(user.name);
cout<<"\n                          Passport No.: ";gets(user.pass);
cout<<"\n                             Phone No.: ";gets(user.mob);
cout<<"\n                               Address: ";gets(user.add);
tgen(&user); strcpy(user.u,u); chart(&user);
fstream f;
f.open("data.dat",ios::binary|ios::app);
f.write((char*)&user,sizeof(user));
f.close();
clrscr();cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tTICKET BOOKED\n\n\n\n\n\n\n\n\n\n\n\n\n\n";delay(1250) ;
mainm();screen2();

}
void signup()
{  class log a;char p[20];
  int flag[3],age,i;
  while(1)
  { fflush(stdin); flag[0]=flag[1]=flag[2]=1;clrscr();cout<<"\n\n\n\t\t____________________________________________"<<endl;
      cout<<"\t\t| Enter User name(only characters) : ";
      gets(a.u);for(i=0;a.u[i]!='\0';i++)if(isalpha(a.u[i])==0)flag[0]=0;
      cout<<"\t\t| Enter PassWord                   : ";getp(p);
      cout<<"\t\t| Re-enter PassWord                : "; getp(a.p); if(strcmp(a.p,p)!=0)flag[1]=0;
      cout<<"\t\t| Enter your age                   : "; cin>>age; if(!isdigit(age)&&age<18) flag[2]=0;

      clrscr();cout<<"\n\n\n\n\n\t\t\t___________________________________________"<<endl;
      if(flag[0]==0)cout<<"\t\t\t|    I SAID ONLY CHARACTER IN USERNAME    |"<<endl;
      if(flag[1]==0)cout<<"\t\t\t|          PASSWORD DOESN'T MATCH         |"<<endl;
      if(flag[2]==0)cout<<"\t\t\t| Too Small For this , come after "<<18-age<<" yrs   |"<<endl;
      cout<<"\t\t\t-------------------------------------------"<<endl;
      if(flag[0]==1&&flag[1]==1&&flag[2]==1) break;cout<<"\n\n\n\t\tPress Esc to go back to login page... \n\t\tPress any other key to Re-enter Details..."<<endl<<endl;
      if(getch()==27) lscreen();

  }
  fstream f;
  f.open("abc.dat",ios::binary|ios::app);
  f.write((char*)&a,sizeof(class log));        f.close();
  clrscr();cout<<"\n\n\n\n\n\t\t\tTRANSFERING TO LOGIN SCREEN \n";delay(1250); lscreen();
}
//_______________________________________________________________________________________________
void show(class udata a)
{
       cout<<"EXIT( press Esc)\n\n\n\n\n"<<endl;
   cout<<"\t\t\t Your Ticket No.:"<<a.tno<<endl;
   cout<<"\t\t\t       Your Name:"<<a.name<<endl;
   cout<<"\t\t\t   Your Passport:"<<a.pass<<endl;
   cout<<"\t\t\t   Your Mob. NO.:"<<a.mob<<endl;
   cout<<"\t\t\t    Your Address:"<<a.add<<endl;
   cout<<"\t\t\t  Your Flight Id:"<<a.fid<<endl;
   cout<<"\t\t\tYour Destination:"<<a.des<<endl;

}
void showsel()
{   class udata a;
    fstream f;int x=1;
    f.open("data.dat",ios::binary|ios::in);
    if(f.eof()){ printf("EMPTY\n\n\n\n");delay(1250);return;} clrscr();
   while(f.read((char*)&a,sizeof(a)))
	if(strcmp(a.u,u)==0)
	{
	    show(a);
	    cout<<"\n\n\n\t\t\t\tTicket "<<x<<endl; break;
	}
    while(1)
	{

		 switch(getch())
		 {
		     case 75:
				if(x>1)
				{   while(!f.seekg(-2*sizeof(a),ios::cur)&&f.read((char*)&a,sizeof(a)))
				    if(strcmp(a.u,u)==0)
					 {
					     clrscr();
					     show(a);
					     cout<<"\n\n\n\t\t\t\tTicket "<<--x<<endl;break;
					 }
				}
				else {f.seekg(0,ios::beg);
				     while(f.read((char*)&a,sizeof(a)))
				    if(strcmp(a.u,u)==0)
					 {
					     clrscr();
					     show(a);
					     cout<<"\n\n\n\t\t\t\tticket "<<x<<endl;break;
					 }
				    }


				    break;
		     case 77:
				    while(f.read((char*)&a,sizeof(a)))
				     {  if(strcmp(a.u,u)==0)
					 {
					     clrscr();
					     show(a);
					    cout<<"\n\n\n\t\t\t\tticket "<<++x<<endl;break;

					 }
				     }
				     if(f.eof())
				     {
					 clrscr();
					cout<<"\n\n\n\n\n\n\t\t\t\tALL TICKET SHOWN\n\n\n\t\t\tMOVE LEFT TO AGAIN VIEW YOUR TICKETS"<<endl<<endl<<endl;
					cout<<"\t\t\t\t      OR\n\n\n\t\t\t     PRESS ESC TO GO BACK";x=1;
				     }

				break;
		     case 27: f.close();return;
		     default: continue;
		 };

	}

}
void showall()
{   class udata a;
    fstream f;int x=1;
    clrscr();
    f.open("data.dat",ios::binary|ios::in);
    if(f==NULL||nentry()==0){ cout<<"\n\n\n\n\t\t\t\tEMPTY\n\n\n\n";}
    else
    {
    f.read((char*)&a,sizeof(a));
    cout<<"\t\t\t\tUSER===>"<<a.u;
    show(a);
    cout<<"\n\n\n\t\t\t\tpage "<<x<<"/"<<nentry()<<endl;
    while(x<nentry())
	{

		 switch(getch())
		 {
		     case 75: clrscr();
				if(x>1)
				{
				    f.seekg(-2*sizeof(class udata),ios::cur);
				    f.read((char*)&a,sizeof(a));
				    cout<<"\t\t\t\tUSER===>"<<a.u;
				    show(a);
				    x--;cout<<"\n\n\n\t\t\t\tpage "<<x<<"/"<<nentry()<<endl;
				}
				else {clrscr();f.seekg(0,ios::beg);f.read((char*)&a,sizeof(a));show(a);
				cout<<"\n\n\n\t\t\t\tpage "<<x<<"/"<<nentry()<<endl;}
				break;
		     case 77:   clrscr();
				if(x<=nentry())
				{
				    f.read((char*)&a,sizeof(a));
				      x++;
				     cout<<"\t\t\t\tUSER===>"<<a.u;
				     show(a);
				cout<<"\n\n\n\t\t\t\tpage "<<x<<"/"<<nentry()<<endl;
				}
				break;
		     case 27: f.close();return;
		     default: continue;
			 //clrscr();printf("\n\n\n\n\n\n\n\n\n\t\t\tPLEASE USE LEFT OR RIGHT ARROW TO NAVIGATE");delay(1250);break;

		 };

	}
	delay(100);clrscr();
	cout<<"\n\n\n\n\n\n\t\t\t\tALL ENTRIES SHOWN";
	}
	cout<<"\n\n\n\t\t\t           LOGGING OUT"<<endl;
	delay(1250);
}

//_______________________________________________________________________________________________
void updata(class udata *a)
{ clrscr();
   cout<<"\t\t\t\tWELCOME "<<a->u<<endl<<endl<<endl<<endl;
   cout<<"\t\t\t Your Ticket No.:"<<a->tno;cout<<endl;
   cout<<"\t\t\t       Your Name:"<<a->name;bin(a->name);cout<<endl;
   cout<<"\t\t\t   Your Passport:"<<a->pass;bin(a->pass);cout<<endl;
   cout<<"\t\t\t   Your Mob. NO.:"<<a->mob;bin(a->mob);cout<<endl;
   cout<<"\t\t\t    Your Address:"<<a->add;bin(a->add);cout<<endl;
   chart(a);
}
void upsel(char tno[])
{   class udata a;
    fstream f,t;
    f.open("data.dat",ios::binary|ios::in);t.open("temp.dat",ios::out|ios::binary);
    if(f==NULL){ cout<<"EMPTY\n\n\n\n";delay(1250);return;} clrscr();
   while(f.read((char*)&a,sizeof(a)))
   {
   if((strcmp(a.tno,tno)==0))
        {
	updata(&a);
	t.write((char*)&a,sizeof(a));
        }
    else t.write((char*)&a,sizeof(a));
   }
    f.close();t.close();
   f.open("data.dat",ios::out|ios::binary);t.open("temp.dat",ios::binary|ios::in);
   while(t.read((char*)&a,sizeof(a)))
   {
       f.write((char*)&a,sizeof(a));
   }
   f.close();t.close();
   remove("temp.dat");
}
void update()
{   class udata a;
    fstream f;int x=1;
    long pos;
    f.open("data.dat",ios::binary|ios::in);
    if(f==NULL){ cout<<"EMPTY\n\n\n\n";delay(1250);return;} clrscr();
   while(f.read((char*)&a,sizeof(a)))
	if(strcmp(a.u,u)==0)
	{
	    show(a);
	    cout<<"\n\n\n\t\t\t\tticket "<<x<<"\n\n\n\n    Press ENTER to edit this ticket or LEFT or RIGHT to view other ticket\n";
	    if(getch()==13){upsel(a.tno); update();break;}
	}

    while(1)
	{

                 switch(getch())
                 {
                     case 75:
				if(x>1)
				{   while(!f.seekg(-2*sizeof(a),ios::cur)&&f.read((char*)&a,sizeof(a)))
				    if(strcmp(a.u,u)==0)
					 {
                                             clrscr();

				    show(a);cout<<"\n\n\n\t\t\t\tticket "<<--x<<"\n\n\n\n    Press ENTER to edit this ticket or LEFT or RIGHT to view other ticket"<<endl;
					  break;
                                         }
					 if(getch()==13) {upsel(a.tno);update();}
				}
				break;
		     case 77: while(f.read((char*)&a,sizeof(a)))
				       if(strcmp(a.u,u)==0)
					 {
					     clrscr();
					     show(a);
					     cout<<"\n\n\n\t\t\t\tticket "<<++x<<"\n\n\n\n    Press ENTER to edit this ticket or LEFT or RIGHT to view other ticket"<<endl;
					    break;
					 }
					 if(getch()==13){upsel(a.tno);update();}
				break;
		     case 27: f.close();return;
		     default: continue;
		 };

	}
}
//_______________________________________________________________________________________________
void delt()
{   class udata a;
    int flag=1;
    fstream f;int x=0;
    f.open("data.dat",ios::binary|ios::in);
    if(f==NULL){ cout<<"EMPTY\n\n\n"<<endl;delay(1250);return;} clrscr();
   while(f.read((char*)&a,sizeof(a)))
       {
	if(strcmp(a.u,u)==0)
	{ flag=0;
	show(a);
	cout<<"\n\n\n\t\t\t\tticket "<<++x<<"\n\n\n\n    Press ENTER to DELETE this ticket or LEFT or RIGHT to view other ticket"<<endl;

	    if(getch()==13)
	    {
		cout<<"\n\t\t\tARE YOU SURE?(to cancel press Esc)";
		if(getch()==13)
		{delsel(a.tno); break;}

	    }
	}

      }
      if(flag==1) {cout<<"No Bookings yet.... What are you waiting for";delay(1250);return;}
    while(1)
	{

		 switch(getch())
		 {
		     case 75:
				if(x>1)
				{   while(!f.seekg(-2*sizeof(a),ios::cur)&&f.read((char*)&a,sizeof(a)))
				    if(strcmp(a.u,u)==0)
					 {
					     clrscr();

				    show(a);cout<<"\n\n\n\t\t\t\tticket "<<--x<<"\n\n\n\n    Press ENTER to DELETE this ticket or LEFT or RIGHT to view other ticket"<<endl;break;
					 }
				     if(getch()==13)
				    {
					 cout<<"\n\t\t\t\t ARE YOU SURE?(to cancel press Esc)";
					    if(getch()==13)
						{delsel(a.tno);
						cout<<"\n\n\n\n\n\n\n\t\t\t\tDELETED";delay(1250); return;}
				    }
				}
				break;
		     case 77:
				    while(f.read((char*)&a,sizeof(a)))
				       if(strcmp(a.u,u)==0)
				     {
					 clrscr();
					 show(a);
					 cout<<"\n\n\n\t\t\t\tticket "<<++x<<"\n\n\n\n    Press ENTER to DELETE this ticket or LEFT or RIGHT to view other ticket"<<endl;break;
				     }
				   if(getch()==13)
				    {
					 cout<<"\n\t\t\t\t ARE YOU SURE?(to cancel press Esc)";
					    if(getch()==13)
						{delsel(a.tno);
						cout<<"DELETED";delay(1250); return;}
				    }

				break;
		     case 27: f.close();return;
		     default: continue;
		 };

	}




}
void delsel(char tno[])
{   class udata a;
    fstream f,t;
    f.open("data.dat",ios::binary|ios::in);t.open("temp.dat",ios::out|ios::binary);
    if(f==NULL){ printf("EMPTY\n\n\n\n");delay(1250);return;} clrscr();
   while(f.read((char*)&a,sizeof(a)))
   {
   if((strcmp(a.tno,tno)==0))
	{
	continue;
	}
    else t.write((char*)&a,sizeof(a));
   }
    f.close();t.close();
   f.open("data.dat",ios::out|ios::binary);t.open("temp.dat",ios::binary|ios::in);
   while(!t.eof()&&t.read((char*)&a,sizeof(a)))
   {
       f.write((char*)&a,sizeof(a));
   }
   f.close();t.close();
   remove("temp.dat");

}
//_______________________________________________________________________________________________
void e2(char str[])
{


    int i;
	int size=strlen(str);
    char temp=str[size-1];

    for(i=size-1;i>=0;i--)
    {
	if(i==0)
	{
	    str[i]=temp;
	}
	else
	{
	    str[i]=str[i-1];
	}
    }

    puts(str);



}
void exits()
{

	char str[] ="               *******  *   *    *    *    *  *    *   ****                    "
	    ,str1[]="                  *     *   *   * *   * *  *  *  *    *                        "
	    ,str2[]="                  *     *****  *****  *  * *  * *      ***                     "
	    ,str3[]="                  *     *   *  *   *  *   **  *  *        *                    "
	    ,str4[]="                  *     *   *  *   *  *    *  *    *  ****                     ";
	 int i;        for(i=0;i<79 ;i++)
    {
       clrscr();
       cout<<"\n\n\n\n\n\n\n"<<endl;
       cout<<"==============================================================================="<<endl;
			      e2(str);e2(str1);e2(str2);e2(str3);e2(str4);
       cout<<"==============================================================================="<<endl;
       delay(35);
    }
	strcpy(str ,"    ****    ****   ****       *    *  ****   *     *  **   *  ****   ****    ");
	strcpy(str1,"    *   *  *      *          * *   *  *   *  *     *  * *  *  *     *        ");
	strcpy(str2,"    ****    ***    ***      *****  *  ****   *     *  *  * *  ***    ***     ");
	strcpy(str3,"    *   *      *      *     *   *  *  *  *   *     *  *   **  *         *    ");
	strcpy(str4,"    ****   ****   ****      *   *  *  *   *  ****  *  *    *  ****  ****     ");

    for(i=0;i<79;i++)
    {
       clrscr();
       cout<<"\n\n\n\n\n\n\n"<<endl;
       cout<<"==============================================================================="<<endl;
			      e2(str);e2(str1);e2(str2);e2(str3);e2(str4);
       cout<<"==============================================================================="<<endl;
       delay(35);
    }
}
//_______________________________________________________________________________________________
void s2()
{   clrscr();
    cout<<"BACK(press Esc)\n\n\n\n\n\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t-   VIEW DATABASE  -"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=     UPDATE       ="<<endl;
    cout<<"\t\t\t\t=      FLIGHT      ="<<endl;
    cout<<"\t\t\t\t=       TIMING     ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
}
void s1()
{

    clrscr();
    cout<<"BACK(press Esc)\n\n\n\n\n\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t=   VIEW DATABASE  ="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-     UPDATE       -"<<endl;
    cout<<"\t\t\t\t-      FLIGHT      -"<<endl;
    cout<<"\t\t\t\t-       TIMING     -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;

}
int sos()
{   int flag=1;clrscr(); s1();
    while(1)
    {
	switch(getch())
	{
	    case 72: s1();flag=1;break;
	    case 80 :s2();flag=2;break;
            case 13 :return flag;
	    case 27: return 0;
	    default: continue;
        };
    }

}
//_______________________________________________________________________________________________
void b2()
{   clrscr();
    cout<<"EXIT(press Esc)";
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\t\t\t  Do you want to save changes to this flight??\n"<<endl;
    cout<<"\t\t\t\t=========         --------"<<endl;
    cout<<"\t\t\t\t=  YES  =         -  NO  -"<<endl;
    cout<<"\t\t\t\t=========         --------"<<endl;
}
void b1()
{
    clrscr();
    cout<<"EXIT(press Esc)";
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\t\t\t  Do you want to save changes to this flight??\n"<<endl;
    cout<<"\t\t\t\t---------         ========"<<endl;
    cout<<"\t\t\t\t-  YES  -         =  NO  ="<<endl;
    cout<<"\t\t\t\t---------         ========"<<endl;

}
int save()
{
     int flag=1;clrscr(); b2();
    while(1)
    {
	switch(getch())
	{
	    case 75: b2();flag=1;break;
	    case 77 :b1();flag=2;break;
	    case 13 :return flag;
	    case 27: flag=2;break;
	    default: continue;
	};
    }

}


void ctime(int a[2])
{
    printf("%02d:%02d",a[0],a[1]);
    while(1)
    {

	switch(getch())
	{
	    case 72: if(a[0]==24){a[0]=1;} else a[0]++;printf("\b\b\b\b\b%02d:%02d",a[0],a[1]);break;
	    case 80: if(a[0]==1){a[0]=24;} else a[0]--;printf("\b\b\b\b\b%02d:%02d",a[0],a[1]);break;
	    case 13: while(1)
		    {   int flag=0;
                        switch(getch())
                        {
                            case 72: if(a[1]==59)a[1]=0; else a[1]++;printf("\b\b%02d",a[1]); break;
			    case 80: if(a[1]==0)a[1]=59; else a[1]--;printf("\b\b%02d",a[1]); break;
			    case 13: return;
			    case 27: flag=1;break;
			    default: continue;
                        }
			if(flag==1)break;
                    }break;
	    case 27: return;
	    default: continue;
	}
    }

}
void tup()
{
    class chart c;
int ans=1;fstream f;

int flag=0;
while(flag==0)
{f.open("chart.dat",ios::binary|ios::in);
f.seekg(0,ios::beg);
clrscr();int i=1;
printf("\n\n\n\n\n\n\n    Flight id  |  Departure City  | Arrival Place |   Time   | Price |   Status\n\n");
while(!f.eof()&&f.read((char*)&c,sizeof(class chart)))
{
if(ans==i)printf("->");else printf("  ");printf("     %s  |%18s|%15s|   %02d:%02d  |",c.fid,c.des,c.arr,c.time[0],c.time[1]);sprice(c.price);printf(" |");printstat(c.stat);printf("\n\n");
i++;
}
f.close();
switch(getch())
	{
	    case 72 : if(ans>1)ans--;break;
	    case 80 : if(ans<5)ans++;break;
	    case 13 : flag=1;f.close();break;
	    case 27 : return;
	    default: continue;
	};
}
clrscr(); int a;
f.open("chart.dat",ios::binary|ios::in);
f.seekg((ans-1)*sizeof(class chart),ios::beg);
f.read((char*)&c,sizeof(class chart));
printf("\n\n\n\n\n\n\n    Flight id  |  Departure City  | Arrival Place |   Time   | Price |   Status\n\n");
  printf("       %s  |%18s|%15s|   %02d:%02d  | ",c.fid,c.des,c.arr,c.time[0],c.time[1]);sprice(c.price);printf("|");printstat(c.stat);
printf("\r       %s",c.fid);bin(c.fid);a=strlen(c.des);
printf("  |%18s",c.des);bin(c.des);bs(18-a+strlen(c.des));printf("%18s",c.des);a=strlen(c.arr);
printf("|%15s",c.arr);bin(c.arr);bs(15-a+strlen(c.arr));printf("%15s",c.arr);
printf("|   ");ctime(c.time);
printf("  | ");c.price=gprice(c.price);bs(6);printf("%6d|",c.price);printstat(c.stat);c.stat=stat(c.stat);
f.close();
if(save()==1)
{
class chart l;
    fstream t;
    f.open("chart.dat",ios::binary|ios::in);f.seekg(0);t.open("temp.dat",ios::out|ios::binary);
   while(f.read((char*)&l,sizeof(l)))
   {
    if(f.tellg()==(ans)*sizeof(class chart))
	{
	t.write((char*)&c,sizeof(c));
	}
    else t.write((char*)&l,sizeof(l));
   }
    f.close();t.close();
   f.open("chart.dat",ios::binary|ios::out);t.open("temp.dat",ios::binary|ios::in);
   while(t.read((char*)&l,sizeof(l)))
   {
       f.write((char*)&l,sizeof(l));
   }
   f.close();t.close();
   remove("temp.dat");
}
else tup();
}
//_______________________________________________________________________________________________
void r2()
{   clrscr();
    cout<<"EXIT(press Esc)";
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t  Do you want to log out??\n"<<endl;
    cout<<"\t\t\t\t=========         --------"<<endl;
    cout<<"\t\t\t\t=  YES  =         -  NO  -"<<endl;
    cout<<"\t\t\t\t=========         --------"<<endl;
}
void r1()
{
    clrscr();
    cout<<"EXIT(press Esc)";
    cout<<"\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t  Do you want to log out??\n"<<endl;
    cout<<"\t\t\t\t---------         ========"<<endl;
    cout<<"\t\t\t\t-  YES  -         =  NO  ="<<endl;
    cout<<"\t\t\t\t---------         ========"<<endl;

}
int real()
{
     int flag=1;clrscr(); r2();
    while(1)
    {
	switch(getch())
	{
	    case 75: r2();flag=1;break;
	    case 77 :r1();flag=2;break;
	    case 13 :return flag;
	    case 27: flag=2;break;
	    default: continue;
	};
    }

}
//_______________________________________________________________________________________________
void p2()
{   clrscr();
    cout<<"EXIT(press Esc)\n\n\n\n\n\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t-       CLIENT     -"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t=       STAFF      ="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
}
void p1()
{
    clrscr();
    cout<<"EXIT(press Esc)\n\n\n\n\n\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t=       CLIENT     ="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t-       STAFF      -"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;

}
int pos()
{   int flag=1;clrscr(); p1();
    while(1)
    {
	switch(getch())
	{
	    case 72: p1();flag=1;break;
	    case 80 :p2();flag=2;break;
	    case 13 :return flag;
	    case 27: exits();
			exit(0);
	    default: continue;
	};
    }

}
//_______________________________________________________________________________________________
void o2()
{   clrscr();
    cout<<"BACK(press Esc)\n\n\n\n\n\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t-      log in      -"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t=      sign up     ="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
}
void o1()
{

    clrscr();
    cout<<"BACK(press Esc)\n\n\n\n\n\t\t\t\t===================="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t=      log in      ="<<endl;
    cout<<"\t\t\t\t=                  ="<<endl;
    cout<<"\t\t\t\t===================="<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t-      sign up     -"<<endl;
    cout<<"\t\t\t\t-                  -"<<endl;
    cout<<"\t\t\t\t--------------------"<<endl;

}


int los()
{   int flag=1;clrscr(); o1();
    while(1)
    {
	switch(getch())
	{
	    case 72: o1();flag=1;break;
	    case 80 :o2();flag=2;break;
	    case 13 :return flag;
	    case 27: screen1();break;
	    default: continue;
	};
    }

}
//_______________________________________________________________________________________________
int nentry()
{   class udata a;
    fstream f;int x=0;
    f.open("data.dat",ios::binary|ios::in);
    while(f.read((char*)&a,sizeof(a))&&!f.eof())
    {
	x++;
    }
    f.close();
    return x;                                           // MISC
}                                                         //  FUNCTIONS
void getp(char *pass)
{   char ch;int i=0;
    while(1)
    {
	ch=getch();
	if(ch==13){pass[i]='\0'; break;}
	else if(ch==8&&i>0){cout<<"\b \b";i--;}
	else if(ch!=8){
	cout<<" \b*";
	pass[i++]=ch;
    }}
    printf("\n");
}
void bin(char *pass)
{   char ch;int i=strlen(pass);
    while(1)
    {
	ch=getch();
	if(ch==13){pass[i]='\0'; break;}
	else if(ch==8&&i>0){cout<<"\b \b";i--;}
	else if(ch!=8){
	cout<<ch;
	pass[i++]=ch;
    }}

}
void mainm()
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\t\t\ttransfering to main menu....\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
delay(1500);
}
void chart(class udata *user)
{
 int gdriver = DETECT, gmode, errorcode;
   //initialize graphics and local variables
   initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      return; // terminate with an error code
   }
fstream f;
int arr[11][11];
for(int a=0;a<11;a++) for(int b=0;b<11;b++) arr[a][b]=0;
class chart c;
f.open("chart.dat",ios::binary|ios::in);
f.seekg(0);
while(f.read((char*)&c,sizeof(class chart)))
{
  arr[city_num(c.des)][city_num(c.arr)]=1;
}
f.close();
f.open("chart.dat",ios::binary|ios::in);
f.seekg(0);
int arrival,depart;
depart=depcity();
arrival=arrcity(depart,arr);
while(f.read((char*)&c,sizeof(class chart)))
{
  if((strcmpi(c.arr,city_name(arrival))==0)&&(strcmpi(c.des,city_name(depart))==0))
   break;
}
f.close();
closegraph();
cout<<"\n\n\n\n\n\n\n    Flight id  |  Departure City  | Arrival Place |   Time   | Price |   Status"<<endl<<endl;
	cout<<"  ";printf("     %s  |       %s      |       %6s  |   %02d:%02d  | ",c.fid,c.des,c.arr,c.time[0],c.time[1]);sprice(c.price);printf("|");printstat(c.stat);printf("\n\n");
getch();
 strcpy(user->des,c.arr);strcpy(user->fid,c.fid); user->price=c.price;
}

void schart()
{
    fstream f;
    clrscr();
    f.open("chart.dat",ios::binary|ios::in);
    cout<<"\n\n\n\n\n\n\n    Flight id  |  Departure City  | Arrival Place |   Time   | Price |   Status"<<endl<<endl;
    while(f&&f.read((char*)&c,sizeof(class chart)))
    {
    printf("       %s  |       %s      |       %6s  |   %02d:%02d  | ",c.fid,c.des,c.arr,c.time[0],c.time[1]);sprice(c.price);printf("|");printstat(c.stat);printf("\n\n");
    }
    f.close();
    system("pause");
}
void declarechart()
{
    fstream f;
    f.open("chart.dat",ios::binary|ios::in);
if(f==NULL)
{   f.open("chart.dat",ios::binary|ios::out);
	int time[]={7,0};
    class chart c("AA-001","DELHI","MUMBAI",time,3500,1);
    f.write((char*)&c,sizeof(class chart));
    time[0]=time[1]=7;
    c.copy("AA-002","DELHI","JAIPUR",time,1500,1);
    f.write((char*)&c,sizeof(class chart));
	time[0]=11,time[1]=0;
    c.copy("AA-003","DELHI","GOA",time,5500,1);
    f.write((char*)&c,sizeof(class chart));
	time[0]=13,time[1]=0;
    c.copy("AA-004","DELHI","HYD",time,13500,1);
    f.write((char*)&c,sizeof(class chart));
	time[0]=15,time[1]=0;
    c.copy("AA-005","DELHI","LUCKNOW",time,15500,1);
    f.write((char*)&c,sizeof(class chart));
}
else return;
f.close();
}
int sverify()
{
    clrscr();
    char pass[50],user[50];fflush(stdin);
    cout<<"\n\n\n\n\n \t\t\t\tenter username : ";gets(user);
    cout<<"\n \t\t\t\tenter password : ";
    getp(pass);
	if((strcmp("bsh",user)==0)&&(strcmp("1202",pass)==0)){return 1;}
	else{return 0;}
}
int passf()
{   clrscr();fflush(stdin);
    char pass[20],user[20];
    cout<<"\n\n\n\n\n \t\t\t\tenter username : ";gets(user);
    cout<<"\n\n \t\t\t\tenter password : ";
    getp(pass);
    fstream f;
    f.open("abc.dat",ios::in|ios::binary);class log a;
    f.seekg(0);
    while(f.read((char*)&a,sizeof(a))&&!f.eof())
    {

	if((strcmp(a.u,user)==0)&&(strcmp(a.p,pass)==0)){strcpy(u,user);return 1;}

    }
    f.close();
    return 0;

}
void tgen(class udata *a)
{   int i;class udata x;
    fstream f; f.open("data.dat",ios::binary|ios::in);
    for(i=0;i<6;i++)
    {
	a->tno[i]=48+ rand()%10 ;
    }
    a->tno[i]='\0';
    while(f.read((char*)&x,sizeof(x)))
    {
    if(strcmp(x.tno,a->tno)==0) tgen(a);
    }
    return;

}
void bs(int a)
{
    for(a;a>0;a--)cout<<"\b";
}
void sp(int a)
{
    for(a;a>0;a--) cout<<" ";
}
void printstat(int a)
{
    switch (a)
    {
	case 1: cout<<"  ON-TIME";break;
        case 2: cout<<"  DELAYED";break;
        case 3: cout<<"CANCELLED";break;
    }
}
int stat(int a)
{   int z=a;
    while(1)
    {

        switch(getch())
        {
            case 72: if(a==1)a=3; else a--; bs(9); printstat(a); break;
	    case 80: if(a==3)a=1; else a++; bs(9); printstat(a);break;
            case 13: return a;
            case 27: return z;
            default: continue;
        }

    }

}
void sprice(int a)
{
    int k=a,i=0; char x[]="     ";
    do
    {
        x[4-i]=(char)(48+k%10);
        k/=10;
        i++;


    }
    while(k!=0);
    x[5]='\0';
    printf("%6s",x);
}
int gprice(int a)
{   char ch;
    int k=a,i=0; char p[]="     ";
    do
    {
        p[4-i]=(char)(48+k%10);
        k/=10;
	i++;
    }
    while(k!=0);
    p[5]='\0';
    printf("%6s",p);
    k=6;
    while(1)
    {
	ch=getch();
	if(ch==13&&k==6)return a;
        if(ch==13){p[i]='\0'; break;}
        else if(ch==8&&k>1){printf("\b \b");if(i>0)i--;k--;}
        else if(ch!=8){
	printf("%c",ch);
        p[i++]=ch;
    }}

    a=0;
    for(i=0;i<strlen(p);i++)
    {
        a+=(int)(p[i]) -48;
	a*=10;
    }
    a=a/10;
    return a;
}

//_______________________________________________________________________________________________
void bill()
{
    fstream f;int total=0;class udata a;
    f.open("data.dat",ios::binary|ios::in);
    clrscr();
    cout<<"\n\n\n\n\n\n\t____________________________________________________________"<<endl;
    cout<<"\t|                                                          |"<<endl;
    cout<<"\t|                        BSS AIRLINES                      |"<<endl;
    cout<<"\t|                                                          |"<<endl;
    cout<<"\t|                      TICKET   INVOICE                    |"<<endl;
    cout<<"\t|                                                          |"<<endl;
    if(f!=NULL)
    while(!f.eof()&&f.read((char*)&a,sizeof(a)))
    {
        if(strcmp(a.u,u)==0)
	{
                printf("\t|           Ticket to %7s :         Rs.   %6d       |\n",a.des,a.price);
                cout<<"\t|                                                          |"<<endl;
            total+=a.price;
	}
    }
    float tax= total*5/100;
                printf("\t|       Processing Fees(5%%)   =         Rs.%9.2f       |\n",tax);
                cout<<"\t|                                                          |"<<endl;
		printf("\t|              total price    =         Rs.%9.2f       |\n",total+tax);
                cout<<"\t|                                                          |"<<endl;
                cout<<"\t------------------------------------------------------------"<<endl;
    system("pause");
    f.close();
}
//_______________________________________________________________________________________________
float deg(float r)
{return M_PI*r/180;
}
float n(float a)
{ if(a>=478) a-=478;
	return a;
}
float x(float a,float b, float t= 1 )
{      t=deg(t);
	b=478-b;
	return (a*cos(t))+(b*sin(t)); }
float y(int a,int b, double t=1 )
{      t=deg(t);
	b=478-b;
	  return 470+a*sin(t)-b*cos(t); }


void entry()
{
   clrscr();  // request auto detection
   int gdriver = DETECT, gmode, errorcode;
   int mx, my;


   // initialize graphics and local variables
   initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");

   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      return; // terminate with an error code
   }
   char str[]="BSS  AIRLINES";
   mx = getmaxx();
   my = getmaxy();
   setcolor(WHITE);

   double t=0;
   for(int a=0,b=0;a!=638;b++,a++)
   {
   cleardevice();
   //airplane code begin
   line(x(5 ,470  ,t)+a,y(5 ,470  ,t)-b,x(25 ,470  ,t)+a,y(25 ,470  ,t)-b);
   line(x(55 ,470  ,t)+a,y(55 ,470  ,t)-b,x(120 ,470  ,t)+a,y(120 ,470  ,t)-b);
   line(x(0 ,460 ,t)+a,y(0 ,460  ,t)-b,x(0 ,435  ,t)+a,y(0 ,435  ,t)-b);
   line(x(5 ,470  ,t)+a,y(5 ,470 ,t)-b,x(0 ,467  ,t)+a,y(  0 ,467  ,t)-b);
   line(x(0 ,435  ,t)+a,y(0 ,435  ,t)-b,x(5 ,435  ,t)+a,y(5 ,435  ,t)-b);
   line(x(10 ,440  ,t)+a,y(10 ,440  ,t)-b,x(5 ,435  ,t)+a,y(5 ,435  ,t)-b);
   line(x(10 ,440  ,t)+a,y(10 ,440  ,t)-b,x(20 ,450  ,t)+a,y(20 ,450  ,t)-b);
   line(x(20 ,450  ,t)+a,y(20 ,450  ,t)-b,x(120 ,450  ,t)+a,y(120 ,450  ,t)-b);
   arc(x(120 ,460  ,t)+a,y(120 ,460  ,t)-b,270-t,90-t,10);
   line(x(30 ,450  ,t)+a,y(30 ,450  ,t)-b,x(18 ,445  ,t)+a,y(18 ,445  ,t)-b);
   line(x(18 ,445  ,t)+a,y(18 ,445  ,t)-b,x(23 ,440  ,t)+a,y(23 ,440  ,t)-b);
   line(x(70 ,450  ,t)+a,y(70 ,450  ,t)-b,x(23 ,440  ,t)+a,y(23 ,440  ,t)-b);
   line(x(35 ,465  ,t)+a,y(35 ,465  ,t)-b,x(3 ,480  ,t)+a,y(3 ,480  ,t)-b);
   line(x(3  ,480  ,t)+a,y(3  ,480  ,t)-b,x(10,484  ,t)+a,y(10,484  ,t)-b);
   line(x(70 ,465  ,t)+a,y(70 ,465  ,t)-b,x(10,484  ,t)+a,y(10,484  ,t)-b);
   line(x(35 ,465  ,t)+a,y(35 ,465  ,t)-b,x(70 ,465  ,t)+a,y(70 ,465  ,t)-b);
   line(x(3 ,458,t)+a,y(3 ,458  ,t)-b,x(20 ,458  ,t)+a,y(20 ,458  ,t)-b);
   line(x(-10 ,468,t)+a,y(-10 ,468  ,t)-b,x(3 ,458  ,t)+a,y(3  ,458  ,t)-b);
   line(x(-5 ,468,t)+a,y(-5 ,468  ,t)-b,x(20 ,458  ,t)+a,y(20 ,458  ,t)-b);
   line(x(-10 ,468,t)+a,y(-10 ,468  ,t)-b,x(-5 ,468  ,t)+a,y(-5  ,468  ,t)-b);
   circle(x(40 ,480  ,t)+a,y(40 ,480  ,t)-b,5);
   circle(x(40 ,480  ,t)+a,y(40 ,480  ,t)-b,3);
   line(x(40,485,t)+a,y(40,485,t)-b,x(30,485,t)+a,y(30,485,t)-b);
   line(x(30,485,t)+a,y(30,485,t)-b,x(25,480,t)+a,y(25,480,t)-b);
   circle(x(30 ,458,t)+a,y(30 ,458  ,t)-b,3);
   circle(x(38 ,458,t)+a,y(38 ,458  ,t)-b,3);
   circle(x(46 ,458,t)+a,y(46 ,458  ,t)-b,3);
   circle(x(54 ,458,t)+a,y(54 ,458  ,t)-b,3);
   circle(x(62 ,458,t)+a,y(62 ,458  ,t)-b,3);
   circle(x(70 ,458,t)+a,y(70 ,458  ,t)-b,3);
   circle(x(78 ,458,t)+a,y(78 ,458  ,t)-b,3);
   circle(x(86 ,458,t)+a,y(86 ,458  ,t)-b,3);
   circle(x(94 ,458,t)+a,y(94 ,458  ,t)-b,3);
   line(x(115,460,t)+a,y(115,460,t)-b,x(127,460,t)+a,y(127,460,t)-b);
   line(x(115,453,t)+a,y(115,453,t)-b,x(120,453,t)+a,y(120,453,t)-b);
   line(x(115,460,t)+a,y(115,460,t)-b,x(115,453,t)+a,y(116,453,t)-b);
   arc(x(120,460,t)+a,y(120,460,t)-b,0-t,90-t,7);
   line(x(105 ,455,t)+a,y(105 ,455  ,t)-b,x(110 ,455,t)+a,y(110 ,455 ,t)-b);
   line(x(105 ,465,t)+a,y(105 ,465  ,t)-b,x(110 ,465,t)+a,y(110 ,465 ,t)-b);
   line(x(110 ,465,t)+a,y(110 ,465  ,t)-b,x(110 ,455,t)+a,y(110 ,455 ,t)-b);
   line(x(105 ,455,t)+a,y(105 ,455  ,t)-b,x(105 ,465,t)+a,y(105 ,465 ,t)-b);
   //airplane code ends
   //roadwaay code begin
   line(0 ,my,mx ,my );
   line(0 ,my-1,mx ,my-1 );

   for(int i=0;i<16;i++)
   {

   line(10+40*i,my-1,10+40*i,my-30);
   line(9+40*i,my-1,9+40*i,my-30);
   line(10+40*i,my-30,15+40*i,my-35);
   line(9+40*i,my-30,14+40*i,my-35);

   setcolor(YELLOW);
   circle(15+40*i,my-35,a%5);
   circle(15+40*i,my-35,a%4);
   setcolor(WHITE);

   }
   //roadway code ends
     //name banner code begin
    settextjustify(1,1);
    settextstyle(3,0,8);
    outtextxy(mx/2,my/2,str);


   if(a<100) {b--;t-=0.04;}
   else  t=t-0.08;

   delay(8);
   }
   closegraph();
 }
float x_txt(float a,float b, float t= 1 )// conversion of rectangular coordinate to polar coordinate
{       return (a*cos(t))+(b*sin(t)); }
float y_txt(int a,int b, double t=1 )
{       return  -a*sin(t)+b*cos(t); }

void city_xy(int n, float *x, float *y)
{
switch(n)
{
case 0:*x=225,*y=280;//Mumbai
	break;
case 1:*x=229,*y=233;//Ahmedabad
	break;
case 2:*x=255,*y=344;//Goa
	break;
case 3:*x=288,*y=171;//Jaipur
	break;
case 4:*x=304,*y=396;//Bengaluru
	break;
case 5:*x=308,*y=129;//Delhi
	break;
case 6:*x=319,*y=319;//Hyderabad
	break;
case 7:*x=354,*y=399;//Chennai
	break;
case 8:*x=372,*y=171;//Lucknow
	break;
case 9:*x=479,*y=225;//Kolkata
	break;
case 10:*x=550,*y=160;//Guwahati
	break;
}
}
int city_num(const char name[])
{
	if(strcmpi("Mumbai",name)==0) return 0;
	else if(strcmpi("Ahmedabad",name)==0) return 1;
	else if(strcmpi("Goa",name)==0) return 2;
	else if(strcmpi("Jaipur",name)==0) return 3;
	else if(strcmpi("Bengaluru",name)==0) return 4;
	else if(strcmpi("Delhi",name)==0) return 5;
	else if(strcmpi("Hyderabad",name)==0) return 6;
	else if(strcmpi("Chennai",name)==0) return 7;
	else if(strcmpi("Lucknow",name)==0) return 8;
	else if(strcmpi("Kolkata",name)==0) return 9;
	else if(strcmpi("Guwahati",name)==0) return 10;
	else return NULL;
}

const char *city_name(int n)
{
switch(n)
{
case 0:return "Mumbai";
case 1:return "Ahmedabad";
case 2:return "Goa";
case 3:return "Jaipur";
case 4:return "Bengaluru";
case 5:return "Delhi";
case 6:return "Hyderabad";
case 7:return "Chennai";
case 8:return "Lucknow";
case 9:return "Kolkata";
case 10:return "Guwahati";
};
return NULL;
}
int arrcity(int d,int arr[11][11])
{
   cleardevice();
   imap();
	    float x1=0,y1=0;  city_xy(d,&x1,&y1);
   cout<<"SELECT ARRIVAL CITY USING\n LEFT/RIGHT ARROW KEYS\n PRESS ENTER TO SELECT";
   for(int i=0;i<11;i++)if(arr[d][i]==1)
			{float x2=0,y2=0; city_xy(i,&x2,&y2);
			       setcolor(CYAN);
			       line(x1,y1,x2,y2);
			       line(x1+1,y1+1,x2,y2);setcolor(WHITE);
			       float t=-(y2-y1)/(x2-x1);
			       if(x2<x1) t=M_PI+atan(t);
			       else t=atan(t);

			       line(x2+x_txt(-9,9,t),y2+y_txt(-9,9,t),x2,y2);
			       line(x2+x_txt(-9,-9,t),y2+y_txt(-9,-9,t),x2,y2);
			       city(i,0);
			 }
int a=0;while(arr[d][a]!=1)a++;
for(int k=0;i<11;i++)
	if(arr[d][k]==1)city(k,0);
	city(a,1);
city(d,0);
while(1)
{

switch(getch())
{
case 75:if(a>0) a--;
	else    a=10;
	while(arr[d][a]!=1)
	{if(a==0) a=11;
	a--;}
	for(int j=0;j<11;j++)
	if(arr[d][j]==1)city(j,0);
	city(a,1);
	break;
case 77:if(a<10)    a++;
	else	    a=0;
	while(arr[d][a%11]!=1)a++;
	a%=11;
	for(int i=0;i<11;i++)
	if(arr[d][i]==1)city(i,0);
	city(a,1);
	break;
case 13: return a;
case 27: exit(0);
}
}

}
int depcity()
{
cleardevice();
imap();
cout<<"SELECT DEPARTURE CITY USING\n LEFT/RIGHT ARROW KEYS\n PRESS ENTER TO SELECT";
settextstyle(2,0,4);
int a=0;
for(int i=0;i<11;i++)
	{if(i==a) city(i,1);
	 else     city(i,0);
	}
while(1)
{

switch(getch())
{
case 75:if(a>0) a--;
	else    a=10;
	for(int i=0;i<11;i++)
	{if(i==a) city(i,1);
	 else     city(i,0);
	}
	break;
case 77:if(a<10) a++;
	else     a=0;
	for(int j=0;j<11;j++)
	{if(j==a) city(j,1);
	 else     city(j,0);
	}
	break;
case 13: return a;
case 27: exit(0);
}
}
}
void city(int n,int value)
{

settextstyle(2,0,4);
setfillstyle(1,CYAN);
if(value==1)
setfillstyle(1,RED);
switch(n)
{
case 0:fillellipse(225,280,3,3);outtextxy(229,270,"Mumbai");    //Mumbai
	break;
case 1:fillellipse(229,233,3,3);outtextxy(232,223,"Ahmedabad"); //Ahmedabad
	break;
case 2:fillellipse(255,344,3,3);outtextxy(259,334,"Goa");       //Goa
	break;
case 3:fillellipse(288,171,3,3);outtextxy(292,161,"Jaipur");    //Jaipur
	break;
case 4:fillellipse(304,396,3,3);outtextxy(308,385,"Bengaluru"); //Bengaluru
	break;
case 5:fillellipse(308,129,3,3);outtextxy(312,119,"Delhi");     //Delhi
	break;
case 6:fillellipse(319,319,3,3);outtextxy(323,309,"Hyderabad"); //Hyderabad
	break;
case 7:fillellipse(354,399,3,3);outtextxy(358,399,"Chennai");   //Chennai
	break;
case 8:fillellipse(372,171,3,3);outtextxy(376,161,"Lucknow");   //Lucknow
	break;
case 9:fillellipse(479,225,3,3);outtextxy(483,215,"Kolkata");    //Kolkata
	break;
case 10:fillellipse(550,160,3,3);outtextxy(554,150,"Guwahati");  //Guwahati
	break;
}
}
void imap()
{
   int a[]={251,20,257,11,260,9,275,3,277,2,299,4,305,8,305,18,316,29,341,16,353,18,357,29,361,36,346,52,348,57,353,60,353,66,345,69,343,73,343,80,341,88,346,89,349,90,351,95,357,97,361,105,368,104,377,109,371,118,368,129,372,131,385,141,419,147,425,143,433,147,441,153,458,156,469,159,490,160,494,147,491,130,502,120,513,125,509,136,511,148,514,153,526,153,532,155,547,151,553,149,553,135,543,135,543,129,540,122,548,123,551,121,576,107,583,110,586,102,596,106,607,114,602,123,614,123,
613,141,617,145,622,152,611,148,604,153,602,168,598,183,591,188,585,186,582,199,579,211,578,217,569,217,565,201,556,208,550,203,549,192,548,190,554,187,560,172,529,175,512,171,513,164,507,162,500,157,499,163,496,164,492,171,498,174,487,182,493,195,490,213,494,232,496,236,487,238,479,234,463,248,456,269,454,274,438,278,405,318,402,327,391,329,385,339,368,339,359,345,359,361,354,377,354,396,355,412,340,436,328,436,327,447,318,464,310,477,299,474,286,441,273,412,270,408,262,357,
244,329,242,311,235,299,225,285,224,255,221,245,218,240,217,254,214,259,197,267,187,269,179,269,171,263,162,256,157,245,155,240,156,236,150,228,169,226,181,221,170,219,150,209,144,208,138,201,144,196,153,192,161,190,173,195,187,195,196,195,192,179,185,174,191,166,180,157,187,152,195,144,200,144,203,141,208,147,207,153,213,156,220,154,220,148,232,144,235,136,246,130,252,122,257,113,270,106,273,102,273,94,288,87,285,84,276,80,270,75,267,71,265,57,263,55,263,52,273,39,268,34,266,29,
266,28,258,24,251,20
};
setcolor(8);
drawpoly(188,a);
setcolor(WHITE);
}
