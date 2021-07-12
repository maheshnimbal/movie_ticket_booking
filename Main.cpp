#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream.h>
 
void foradmin();
void addmovie();
void deletemovie();
void Page();
void admin_login();
void WelcomePage();
void create();
void login();
void forusers();
void show(int);
class Movie
{
   public:
   int code;
   char name[100];
   int rating;
   char genre[100];
   int duration;
   float cost;
   char timings[100];
   int  seats[9][9];
   void getmovie();
   void display();
   Movie();
};
 
class user
{
    public:
    char realusername[40];
    char realpassword[40];
    int seats;
    float amount;
    user(){seats=0;amount=0;}
}u1,utemp;
 
void replace(Movie);
void ureplace(user);
void bill(user);
 
 
Movie::Movie()
{
 for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
          seats[i][j]=0;
    }
}
 
void Movie::getmovie()
{
      cout << "                     Enter the movie code: ";
      cin >> code;
      cout << "                     Enter the name of the movie: ";
      gets(name);
      cout << "                     Enter Rating: ";
      cin >> rating;
      cout << "                     Enter Genre: ";
      gets(genre);
      cout << "                     Enter Timings: ";
      gets(timings);
      cout << "                     Enter Duration (in minutes): ";
      cin >> duration;
      cout << "                     Enter per seat cost: ";
      cin>>cost;
 
}
 
void Movie::display()
{
      cout << "                     Movie code: "<<code<<endl;
      cout << "                     Name: ";
      puts(name);
      cout << "                     Rating: "<<rating<<endl;
      cout << "                     Genre: ";
      puts(genre);
      cout << "                     Timings: ";
      puts(timings);
      cout << "                     Duration: "<<duration<< "mins";
      cout<<endl;
      cout << "                     Cost per seat: "<<cost;
}
 
void bill(user u)
{
    cout << "                           ***********************                      \n";
    cout << "                           *        BILL         *                      \n";
    cout << "                           ***********************                      \n";
    cout << "                           *                     *                      \n";
    cout << "                           *                     *                      \n";
    cout << "                           *      SEATS:"<<u.seats<<"        *          \n";
    cout << "                           *                     *                      \n";
    cout << "                           *                 *                          \n";
    cout << "                           ***********************                      \n";
    cout << "                           *  TOTAL IS "<<u.amount<<"       *           \n";
    cout << "                           ***********************                      \n";
    getch();
    WelcomePage();
}
 
void show(int mcode)
{
 fstream ms;
 Movie tempm;
 int row=1;
 ms.open("MOVIES.dat",ios::in|ios::binary);
 int flag=0;
 while(ms.read((char*)&tempm,sizeof(tempm)))
 {
  if(mcode==tempm.code)
    {
       flag=1;
       break;
    }
 }
 if(flag==1)
 {
  clrscr();
  cout<<"\n\nMovie name is: ";puts(tempm.name);
  cout<<"\nRating: "<<tempm.rating;
  cout<<"\nMovie runtime: "<<tempm.duration;
  cout<<"\nPer seat price: "<<tempm.cost;
  cout<<"\nShow timings: ";puts(tempm.timings);
  cout<<"    1    2    3    4    5    6    7    8    9   \n";
  for(int i=0;i<9;i++)
  {
   cout<<row<<" ";row++;
   for(int j=0;j<9;j++)
   {
    if(tempm.seats[i][j]==1)
    {
     cout<<" [*] ";
    }
    else
    {
     cout<<" [ ] ";
    }
   }
  cout<<endl;
 }
 cout<<"                  SCREEN THIS WAY                  \n";
 cout<<"-----------------------------------------------";
 getch();
 }
 else if(flag==0)
 {cout<<"Movie not found :/";}
 getch();
 ms.close();
 cout<<endl;
}
 
void addmovie()  // function to add a movie
{
   Movie a1;
   fstream filehandler;
   filehandler.open("MOVIES.dat",ios::app|ios::binary);
   char ch = 'y';
   do{
    a1.getmovie();
    filehandler.write((char*)&a1,sizeof(a1));
    cout << "\nMovie Successfully Added!\n"<<endl;
    cout<<"Want to enter more? (y/n)"<<endl;
    cin>>ch;
    cout<<endl;
     } while(ch=='y');
   filehandler.close();
   foradmin();
}
 
void deletemovie()  // function to delete a movie
{
   Movie a2;
   fstream fio;
   fio.open("MOVIES.dat",ios::in|ios::binary);  // already existing file
   fstream file;
   file.open("temp.dat",ios::out|ios::binary);  // making a temp file
   int moviecode;
   char found='f',confirm='n';
   cout << "Enter the code of the movie to be deleted: ";
   cin >> moviecode;
   while(fio.read((char*)&a2,sizeof(a2)))
   {
      if(moviecode==a2.code)  // validation through moviecode
      {
     found='t';
     cout << "Are you sure you want to delete this movie?(y/n): ";
     cin >> confirm;
     if(confirm=='n')
     {
        file.write((char*)&a2,sizeof(a2));
     }
     else{;}
      }
      else
      {
     file.write((char*)&a2,sizeof(a2));
      }
 
   }
   if(found=='f')
   {
     cout << "Record not found!!\n";
   }
   file.close();
   fio.close();
   remove("MOVIES.dat");  // old file is removed
   rename("temp.dat","MOVIES.dat"); // temp file is renamed
   foradmin();
}
 
void Page()
{       cout<<"*******************************************************************************\n";
cout<<"*                              ALL MOVIES AT ONE PLACE                        *\n";
cout<<"*******************************************************************************\n";
}
 
void foradmin()
{
    clrscr();
    int choice;
    cout << "*************************************************************************\n";
    cout << "      *                            WELCOME ADMIN                        *\n";
    cout << "*************************************************************************\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                   1. Add Movie                                  *\n";
    cout << "      *                   2. Delete Movie                               *\n";
    cout << "      *                   3. Display Movies                             *\n";
    cout << "      *                   4. Exit                                       *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "*************************************************************************\n";
    cout << "                         Enter Choice: ";
    cin >> choice;
    switch(choice)
    {
       case 1:
      clrscr();
      addmovie();
      break;
       case 2:
      clrscr();
      deletemovie();
      break;
       case 3:
      clrscr();
      Movie m1;
      fstream manhandler;
      manhandler.open("MOVIES.dat",ios::in|ios::binary);
      while(manhandler.read((char*)&m1,sizeof(m1)))
        {
        m1.display();
        }
      manhandler.close();
      getch();
      foradmin();
       break;
       case 4:
      clrscr();
       WelcomePage();
      break;
       default: ;
    }
}
 
void admin_login()
{
  int c=0;
  char admin[40],password[8],pass[8]="12345678";
  cout << "Enter Admin Username: ";
  gets(admin);
  cout << "Enter 8-Digit Admin Password: ";
  for(int i=0;i<8;i++)
  {
     password[i]=getch();
     cout << "*";
  }
  for(int j=0;j<8;j++)
  {
     if(password[j]==pass[j])
     c+=1;
  }
  if (strcmp(admin,"admin")==0 && c==8)
  {
      cout << "\nWelcome Admin!";
      foradmin();
  }
  else
  {
      cout <<"\nThis is ur pass: ";
      puts(password);
      cout << "\nGoodBye Fraud!" ;
  }
 
}
void replace(Movie r2)
{
    Movie r1;
    fstream f1;
    fstream f2;
    f1.open("MOVIES.dat",ios::in|ios::binary);
    f2.open("temp.dat",ios::out|ios::binary);
    while(f1.read((char*)&r1,sizeof(r1)))
    {
    if(r1.code==r2.code)
    {
        f2.write((char*)&r2,sizeof(r2));
    }
    else
    {
        f2.write((char*)&r1,sizeof(r1));
    }
    }
    f1.close();
    f2.close();
    remove("MOVIES.dat");
    rename("temp.dat","MOVIES.dat");
}
 
void ureplace(user u2)
{
    fstream f1;
    fstream f2;
    f1.open("users.txt",ios::in|ios::binary);
    f2.open("tempu.txt",ios::out|ios::binary);
    while(f1.read((char*)&u1,sizeof(u1)))
    {
    if(strcmp(u1.realusername,u2.realusername)==0)
    {
        f2.write((char*)&u2,sizeof(u2));
    }
    else
    {
        f2.write((char*)&u1,sizeof(u1));
    }
    }
    f1.close();
    f2.close();
    remove("users.txt");
    rename("tempu.txt","users.txt");
}
void forusers()
{
    clrscr();
    int choice;
    cout << "*************************************************************************\n";
    cout << "      *                            WELCOME USER                         *\n";
    cout << "*************************************************************************\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                     1. View Movies                              *\n";
    cout << "      *                     2. Book Movies                              *\n";
    cout << "      *                     3. Home Page                                *\n";
    cout << "      *                     4. Bill                                     *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "*************************************************************************\n";
    cout << "                         Enter Choice: ";
    cin >> choice;
    switch(choice)
    {
       case 1:
            clrscr();
            Movie m1;
            fstream manhandler;
            manhandler.open("MOVIES.dat",ios::in|ios::binary);
            while(manhandler.read((char*)&m1,sizeof(m1)))
         {
            m1.display();
 
         }
         manhandler.close();
         getch();
         forusers();break;
 
       case 2:
        clrscr();
        Page();
        int mcode;
        Movie m2;
        fstream handler;
        handler.open("MOVIES.dat",ios::in|ios::binary);
        while(handler.read((char*)&m2,sizeof(m2)))
        {
             m2.display();
        }
        cout<<endl;
        handler.close();
        char choice='y';
        do{ 
             cout<<"Enter Movie Code of Movie to be booked:";
             cin>>mcode;
             handler.open("MOVIES.dat",ios::in|ios::binary);
             int flag=0;
            while(handler.read((char*)&m2,sizeof(m2)))
            {
                if( mcode == m2.code)
                {
                  flag=1;
                  break;
                }
            }
         if(flag==1)
        {
          clrscr();
          show(mcode);
          Page();
          int x,y; int count;
         cout<<"\nEnter number of seats to be booked: ";
         cin>>count;utemp.seats=count;utemp.amount=count*m2.cost;
         while(count--)
         {
           cout<<"Enter row and column number of seat(rowXcolumn) :";
           cin>>x>>y;
           m2.seats[x-1][y-1]=1;
         }
         cout<<"Your Movie has been successfully booked!!!";
         handler.close();
         replace(m2);
         ureplace(utemp);
         choice='n';
         clrscr();
         show(mcode);
         getch();
         clrscr();
         bill(utemp);
        }
         if(flag!=1)
         { cout<<"Want to try again ? (y/n)";
         cin>>choice;
         cout<<endl;
         }
 
       } while(choice=='y');
         clrscr();
         forusers();
         break;
 
    case 3:
    clrscr();
    WelcomePage();
    break;
    
    case 4:
        clrscr();
        bill(utemp);
        break;
 
    default: break;
  }
 
}
void login()
{
    int temp = 0;
    char ans='y';
    char username[40], password[40];
    do
    {
       cout << "Enter Username: ";
       gets(username);
       cout << "Enter Password: ";
       gets(password);
       ifstream filehandler;
       filehandler.open("users.txt",ios::in|ios::binary);
       while(filehandler.read((char*)&u1,sizeof(u1))&&temp==0)
       {
        if(strcmp(u1.realpassword,password)==0 && strcmp(u1.realusername,username)==0)
        {
           cout << "Login Successful!";
           temp=1;
           break;
        }
      }
      filehandler.close();
      if(temp==1)
      {
      utemp=u1;    
      ans='f';
      }
      else
      {
     cout << "Invalid Password or username!\nDo you want to try again?(y/n): ";cin>>ans;
      }
   }while(ans=='y');
   if(ans=='f')forusers();
   else if(ans=='n')WelcomePage();
}
void create()
{
    fstream f1;
    f1.open("users.txt",ios::in|ios::binary);
    char username[40];
    char password[40];
    int rep=1;
    do{
        cout << "Enter Desired Username: ";
        gets(username);
        cout << "Enter Desired Password: ";
        gets(password);
        int flag=1;
        while(f1.read((char*)&u1,sizeof(u1)) && flag==1)
        {
            if(strcmp(username,u1.realusername)==0)
        {
                flag=0;break;
            }
        }
        f1.close();
        if(flag==0)
        {
            cout<<"\nUsername already taken, please choose another one";
            getch();
            clrscr();
        }
        else if(flag==1)
        {
            strcpy(u1.realpassword,password);
            strcpy(u1.realusername,username);
            u1.seats=0;u1.amount=0;
            f1.open("users.txt",ios::app|ios::binary);
            f1.write((char*)&u1,sizeof(u1));
            rep=0;
            cout<<"\nAccount succesfully created!!!";getch();
            f1.close();
        }
    }while(rep==1);
    WelcomePage();
}
void WelcomePage()
{
    clrscr();
    int choise;
    cout << "*************************************************************************\n";
    cout << "      *                        WELCOME TO PVR CINEMAS                   *\n";
    cout << "*************************************************************************\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                   1. Login                                      *\n";
    cout << "      *                   2. Create Account                             *\n";
    cout << "      *                   3. Exit                                       *\n";
    cout << "      *                   4. Admin                                      *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "      *                                                                 *\n";
    cout << "*************************************************************************\n";
    cout << "                          Enter Choice: ";
    cin >> choise;
    switch(choise)
    {
    case 1:
        clrscr();
        login();
        break;
    case 2:
        clrscr();
        create();
        break;
    case 3:
        exit(0);
    case 4:
        admin_login();
        break;
    default:
        break;
    }
}
void main()
{   clrscr();
    WelcomePage();
    getchar();
}
