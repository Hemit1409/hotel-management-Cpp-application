#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define max 100
using namespace std;

class amount
{
public:
int q;
static int a;

static void bill(int n,int q)
{
/*cout<<"\nenter quantity : "
cin>>q;*/
a=a+n*q;
}

static void display()
{
    cout<<endl<<endl<<"total amount: rs."<<a;
    if(a>=1000)
    {
        int p;
        p=a*0.05;
        cout<<"\ndiscounted price : rs."<<p;
        a=a-p;
        cout<<endl<<endl<<"final amount: rs."<<a;
    }
}

};


class starter : public amount
{
int n;

public:
int q1=0,q2=0;
void input()
{

a:
cout<<"\n\nmenu for starter :\n";
cout<<"\n1.veg soup    : rs.50 \n2.boiled corn : rs.40";
cout<<"\n\nenter your choice : ";
cin>>n;

switch(n)
{
case 1:
cout<<"\nenter quantity : ";
cin>>q1;
bill(50,q1);
break;

case 2:
cout<<"\nenter quantity : ";
cin>>q2;
bill(40,q2);
break;

default:
    cout<<"\nenter correct choice";
    goto a;
}
}
};

class mainc : public amount
{
int n;

public:
int q3=0,q4=0;
void input()
{

b:
cout<<"\n\nmenu for maincourse :\n";
cout<<"\n1.roti   : rs.10 \n2.sabji  : rs.50";
cout<<"\n\nenter your choice : ";
cin>>n;

switch(n)
{
case 1:
cout<<"\nenter quantity : ";
cin>>q3;
bill(10,q3);
break;

case 2:
cout<<"\nenter quantity : ";
cin>>q4;
bill(50,q4);
break;

default:
    cout<<"\nenter correct choice";
    goto b;
}
}

};

class desert : public amount
{
int n;

public:
int q5=0,q6=0;
void input()
{

c:
cout<<"\n\nmenu for desert :\n";
cout<<"\n1.icecream         : rs.25 \n2.chocolate pastry  : rs.45";
cout<<"\n\nenter your choice : ";
cin>>n;

switch(n)
{
case 1:
cout<<"\nenter quantity : ";
cin>>q5;
bill(25,q5);
break;

case 2:
cout<<"\nenter quantity : ";
cin>>q6;
bill(45,q6);
break;

default:
    cout<<"\nenter correct choice";
    goto c;
}
}

};


//concept of constructor

class welcome
{
public:
welcome()
{
cout<<"         "<<"********************"<<"   welcome to BLUE LAGOON hotel   "<<"********************";
}
};

int amount::a;

//Class Customer
class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};


class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};

//Global Declarations
class Room rooms[max];
int count=0;


Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\nType AC/Non-AC (A/N) : ";
cin>>room.ac;
cout<<"\nType Comfort (S/N) : ";
cin>>room.type;
cout<<"\nType Size (B/S) : ";
cin>>room.stype;
cout<<"\nDaily Rent : ";
cin>>room.rent;
room.status=0;

cout<<"\n Room Added Successfully!";
getch();
return room;
}


void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"Room Details\n";
if(rooms[i].status==1)
{
cout<<"\nRoom is Reserved";
}
else
{
cout<<"\nRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nRoom not found";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout<<"\nRoom Number: \t"<<tempRoom.roomNumber;
cout<<"\nType AC/Non-AC (A/N) "<<tempRoom.ac;
cout<<"\nType Comfort (S/N) "<<tempRoom.type;
cout<<"\nType Size (B/S) "<<tempRoom.stype;
cout<<"\nRent: "<<tempRoom.rent;
}

//hotel management class
class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

if(count==0)
{
	cout<<"\n No Guest in Hotel !!";
}
else
{
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\n Customer First Name : "<<rooms[i].cust.name;
cout<<"\n Room Number : "<<rooms[i].roomNumber;
cout<<"\n Address (only city) : "<<rooms[i].cust.address;
cout<<"\n Phone : "<<rooms[i].cust.phone;
cout<<"\n---------------------------------------";
}
else
{
	cout<<"\n\nno guest in hotel!!!";
}
}
}
getch();
}

//hotel management reservation of room
void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
cout<<"\nEnter Room number : ";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
cout<<"\nRoom is already Booked";
getch();
return;
}

cout<<"\nEnter booking id: ";
cin>>rooms[i].cust.booking_id;

cout<<"\nEnter Customer Name (First Name): ";
cin>>rooms[i].cust.name;

cout<<"\nEnter Address (only city): ";
cin>>rooms[i].cust.address;

cout<<"\nEnter Phone: ";
cin>>rooms[i].cust.phone;

cout<<"\nEnter From Date: ";
cin>>rooms[i].cust.from_date;

cout<<"\nEnter to  Date: ";
cin>>rooms[i].cust.to_date;


cout<<"\nEnter Advance Payment: ";
cin>>rooms[i].cust.payment_advance;

rooms[i].status=1;

cout<<"\n Customer Checked-in Successfully..";
getch();
}
}


//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\nPress enter for next room";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nAll rooms are reserved";
getch();
}
}


//hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
cout<<"\nCustomer Name: "<<rooms[i].cust.name;
cout<<"\nRoom Number: "<<rooms[i].roomNumber;

cout<<"\n\nPress enter for next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nPerson not found.";
getch();
}
}


//hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
cout<<"\nEnter Number of Days:\t";
cin>>days;
billAmount=days * rooms[i].rent;

cout<<"\n\t######## CheckOut Details ########\n";
cout<<"\nCustomer Name : "<<rooms[i].cust.name;
cout<<"\nRoom Number : "<<rooms[i].roomNumber;
cout<<"\nAddress : "<<rooms[i].cust.address;
cout<<"\nPhone : "<<rooms[i].cust.phone;
cout<<"\nTotal Amount Due : "<<billAmount<<" /";
cout<<"\nAdvance Paid: "<<rooms[i].cust.payment_advance<<" /";
cout<<"\n*** Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";

rooms[i].status=0;
}
getch();
}


//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
//system("cls");
cout<<"\n### Manage Rooms ###";
cout<<"\n1. Add Room";
cout<<"\n2. Search Room";
cout<<"\n3. Back to Main Menu";
cout<<"\n\nEnter Option: ";
cin>>opt;


//switch statement
switch(opt)
{
case 1:
cout<<"\nEnter Room Number: ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nRoom Number is Present.\nPlease enter unique Number";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nEnter room number: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}while(opt!=3);
}
//using namespace std;


int main()
{
system ("color 9f");
welcome w;
int c;
starter z1;
mainc z2;
desert z3;
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];
R:
int a;
cout<<"\n\n       *********************************";
cout<<"\n       *          1.food order.        *";
cout<<"\n       *          2.room.              *";
cout<<"\n       *          3.exit.              *";
cout<<"\n       *********************************";
cout<<"\nenter choice: ";
cin>>a;

switch(a)
{
case 1:

hi:
cout<<"\n\n\nmenu:";
cout<<"\n###################################################################";
cout<<"\n#                         1.starter.                              #";
cout<<"\n#                         2.main course.                          #";
cout<<"\n#                         3.desert.                               #";
cout<<"\n#                         4.complete your order.                  #";
cout<<"\n###################################################################";
cout<<"\n\nDISCOUNT WILL BE CONSIDERED WHEN THE BILL EXCEEDS 1000 RUPEES.";
cout<<"\n\nyour choice??? : ";
cin>>c;

switch(c)
{

    case 1:
    //starter z1;
    z1.input();
    break;

    case 2:
    //mainc z2;
    z2.input();
    break;

    case 3:
    //desert z3;
    z3.input();
    break;

    case 4:
    cout<<"order completed";
    goto end;

    default:
    cout<<"enter correct code";
    goto hi;

}

goto hi;

end:

int v;
v=0;
cout<<"\n\n your order";
cout<<"\n\n   name               "<<"rate"<<" "<<"qty  "<<"amount";
if(z1.q1!=0)
{
v++;
cout<<"\n\n"<<v<<". veg soup           "<<" 50 "<<" "<<z1.q1<<"    "<<50*z1.q1;
}
if(z1.q2!=0)
{
v++;
cout<<"\n\n"<<v<<". boiled corn        "<<" 40 "<<" "<<z1.q2<<"    "<<40*z1.q2;
}
if(z2.q3!=0)
{
v++;
cout<<"\n\n"<<v<<". roti               "<<" 10 "<<" "<<z2.q3<<"    "<<10*z2.q3;
}
if(z2.q4!=0)
{
v++;
cout<<"\n\n"<<v<<". sabji              "<<" 50 "<<" "<<z2.q4<<"    "<<50*z2.q4;
}
if(z3.q5!=0)
{
v++;
cout<<"\n\n"<<v<<". ice cream          "<<" 25 "<<" "<<z3.q5<<"    "<<25*z3.q5;
}
if(z3.q6!=0)
{
v++;
cout<<"\n\n"<<v<<". chocolate pastry   "<<" 45 "<<" "<<z3.q6<<"    "<<45*z3.q6;
}
amount::display();
cout<<"\n\n*********************************************************************************************************";
break;

case 2:
/*class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];*/

//system("cls");
//system("color 9F");

do
{
//system("cls");
//cout<<"\n######## Hotel Management #########\n";
cout<<"\n\n\nmenu:";
cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n$                1. Manage Rooms                  $";
cout<<"\n$                2. Check-In Room                 $";
cout<<"\n$                3. Available Rooms               $";
cout<<"\n$                4. Search Customer               $";
cout<<"\n$                5. Check-Out Room                $";
cout<<"\n$                6. Guest Summary Report          $";
cout<<"\n$                7. Exit                          $";
cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n\nEnter Option: ";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\nRooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\nRooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Customer Name: ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\nRooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"Enter Room Number : ";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();
break;
case 7:
cout<<"\nTHANK YOU!";
break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}while(opt!=7);
break;

case 3:
    cout<<"\nTHANK YOU";
    exit(0);
    break;

default:
    cout<<"enter proper choice";
    break;
}
goto R;
cout<<"\n\n*********************************************************************************************************";
getch();
}
