#include<iostream>
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
char d=3;
cout<<"         "<<d<<d<<d<<d<<d<<d<<"   welcome to OOPC hotel   "<<d<<d<<d<<d<<d<<d;
}
};

int amount::a;

int main()
{
welcome w;
int c;
starter z1;
mainc z2;
desert z3;
char e=1,f=4;
hi:
cout<<"\n\nmenu : 1.starter 2.main course 3.desert 4.complete your order.";
cout<<"\nyour choice??? : ";
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

cout<<"\n\n your order";
cout<<"\n\n   name               "<<"rate"<<" "<<"qty  "<<"amount";
cout<<"\n\n1. veg soup           "<<" 50 "<<" "<<z1.q1<<"    "<<50*z1.q1;
cout<<"\n2. boiled corn        "<<" 40 "<<" "<<z1.q2<<"    "<<40*z1.q2;
cout<<"\n3. roti               "<<" 10 "<<" "<<z2.q3<<"    "<<10*z2.q3;
cout<<"\n4. sabji              "<<" 50 "<<" "<<z2.q4<<"    "<<50*z2.q4;
cout<<"\n5. ice cream          "<<" 25 "<<" "<<z3.q5<<"    "<<25*z3.q5;
cout<<"\n6. chocolate pastry   "<<" 45 "<<" "<<z3.q6<<"    "<<45*z3.q6;
amount::display();

cout<<"\n\n\n\t\t"<<e<<e<<e<<e<<e<<e<<" thank you. visit again. "<<e<<e<<e<<e<<e<<e<<"\n\n\n";
int i;
for(i=1;i<80;i++)
{
    cout<<f;
}
cout<<"\n\nprepared by : Hemit Rana\n\n";
return 0;

}
