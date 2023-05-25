#include <graphics.h>
#include <fstream.h>
#include <iostream.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <dos.h>
struct uaccount /*Record structure for account details*/
{
 char username[20],mobile[10],email[30],password[10];
};
 char pick[11][20]={"Chennai Airport","Koyambedu","Velachery","Chennai Central","Chennai Egmore","Anna Nagar","T.Nagar","Adyar","OMR","Kodambakkam","Vadapalani"};
 char drop[17][20]={"Thiruvanmiyur","Poonamallee","Marina","MRC Nagar","Nanganallur","Ashok Nagar","Saidapet","Royapettah","Mount Road","R.A.Puram","K.K.Nagar","Puducherry","Coimbatore","Madurai","Cochin","Trichy","Tirupati"};
struct ride /*Record structure for ride details*/
{
 char orig[30],dest[30];
 int dist,fare;
};
void CALCULATE(ride,int); /*Prototypes of all the functions*/
void MODIFY(void);
void CREATE(void);
void RIDE(ride,int);
void DISPACCOUNT(char[]);
void DELETEA(void);
void DELETER(void);
void DISPLAY(char[]);
void DISPUSER(void);
void LOGIN(void);
void CALCULATE(ride r,int ch) /*Function to calculate the fare
 of the ride*/
{
 int flag=0;
 fstream x;
 void RIDE(ride,int);
 for(int i=0;i<11;i++)
 for(int j=0;j<17;j++)
 if((strcmpi(r.orig,pick[i])==0)&&(strcmpi(r.dest,drop[j])==0))
 {
x.open("Ride.dat",ios::out||ios::binary); /*Binary file to store ride
details*/
 if(ch==1)
r.fare=10+(r.dist*7);
else if(ch==2)
r.fare=15+(r.dist*10);
else if(ch==3)
r.fare=7+(r.dist*5);
else if(ch==4)
r.fare=20+(r.dist*10);
else if(ch==5)
r.fare=2500;
else if(ch==6)
r.fare=2000;
else if(ch==7)
r.fare=r.dist*2;
else if(ch==8)
r.fare=r.dist*5;
else if(ch==9)
r.fare=50+(r.dist*20);
flag=1;
 }
 if(flag==0)
 {
 cout<<"\nOops!No rides available according to your request. Sorry for the inconvenience!\n";
 return; }
 else
 {
x.write((char*)&r,sizeof(r));
clrscr();
cleardevice();
setcolor(3);
settextstyle(3,0,3);
outtextxy(300,150,"FETCHING YOUR RIDE....");
for(i=1;i<=3;i++)
{
 setcolor(2);
 setlinestyle(0,0,3);
 for(j=1;j<=360;j++)
 {
 arc(300,250,0,j,30);
 delay(0.01);
 }
 setcolor(0);
 setlinestyle(0,0,3);
 for(j=1;j<=360;j++)
 {
 arc(300,250,0,j,30);
 delay(0.01);
 }
}
RIDE(r,ch); /*Invoking function RIDE to display
to display ride details*/
 }
 x.close();
 getch();
 return;
}
void MODIFY() /*Function to modify account details*/
{
 clrscr();
 cleardevice();
 int ch,c=0,flag=0;
 char uname[20],mno[10],mail[20],pass[10],npass[10];
 fstream x("accounts.dat",ios::in||ios::out||ios::binary); /*Binary file to store
account details*/
 uaccount a;
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(4);
 settextstyle(7,0,4);
 outtextxy(300,120,"EDIT ACCOUNT");
 settextstyle(6,0,2);
 setcolor(2);
 outtextxy(100,200,"1.EDIT USERNAME");
 outtextxy(150,250,"2.EDIT MOBILE NUMBER");
 outtextxy(120,300,"3.EDIT E-MAIL ID");
 outtextxy(110,350,"4.EDIT PASSWORD");
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter the required choice:";
 cin>>ch;
 cout<<"\nEnter existing password\n";
 gets(pass);
 while(!x.eof())
 {
 x.read((char*)&a,sizeof(a));
 c++;
 if(strcmp(pass,a.password)==0)
 {
 if(ch==1)
 {
cout<<"\nEnter new username\n";
gets(uname);
strcpy(a.username,uname);
x.seekp((c-1)*sizeof(a),ios::beg);
x.write((char*)&a,sizeof(a));
cout<<"\nUsername updated!!!";flag=1;break;
 }
 else if(ch==2)
 {
cout<<"\nEnter new mobile no.\n";
gets(mno);
strcpy(a.mobile,mno);
x.seekp((c-1)*sizeof(a),ios::beg);
x.write((char*)&a,sizeof(a));
cout<<"\nMobile number updated!!!";flag=1;break;
 }
 else if(ch==3)
 {
cout<<"\nEnter new e-mail ID\n";
gets(mail);
strcpy(a.email,mail);
x.seekp((c-1)*sizeof(a),ios::beg);
x.write((char*)&a,sizeof(a));
cout<<"\nE-mail updated!!!";flag=1;break;
 }
 else if(ch==4)
 {
cout<<"\nEnter new password\n";
gets(npass);
strcpy(a.password,npass);
x.seekp((c-1)*sizeof(a),ios::beg);
x.write((char*)&a,sizeof(a));
cout<<"\nPassword updated!!!";flag=1;break;
 }
 }
 }
 x.close();
 if(flag==0)
 cout<<"\nRecord not found\n";
 getch();
 return;
}
void CREATE() /*Function to create a new
account*/
{
 clrscr();
 cleardevice();
 uaccount a;
 char ch,cpassword[10];
 fstream x("accounts.dat",ios::out|ios::binary); /*Binary file to store user
accounts*/
 setbkcolor(0);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(10);
 settextstyle(7,0,4);
 outtextxy(300,120,"NEW ACCOUNT");
 do
 {
 cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter the details\n";
 cout<<"Username: ";
 gets(a.username);
 cout<<"\nMobile Number: ";
 gets(a.mobile);
 cout<<"\nEmail ID: ";
 gets(a.email);
 cout<<"\nPassword(min. 8 characters): ";
 gets(a.password);
 cout<<"\nConfirm Password: ";
 gets(cpassword);
 while(strcmp(a.password,cpassword)!=0)
 {
 cout<<"\nWrong Password! Re-enter correct password\n";
 gets(cpassword);
 }
 if(strcmp(a.password,cpassword)==0)
 {
 cout<<"\n\n\n\t\tACCOUNT CREATED SUCCESSFULLY!!!";
 x.write((char*)&a,sizeof(a));
 }
 cout<<"\nAny more records?y/n";
 cin>>ch;
}while(ch=='y'||ch=='Y');
x.close();
getch();
return;
}
void RIDE(ride r,int ch) /*Function to display ride details*/
{
 clrscr();
 char c;
 cleardevice();
 fstream y("Temp3.dat",ios::out||ios::binary); /*Binary file to store details of
cancelled rides*/
 int pc;
 randomize();
 setcolor(1);
 settextstyle(5,0,7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(3);
 settextstyle(7,0,4);
 outtextxy(300,120,"RIDE DETAILS");
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nPICKUP LOCATION: "<<r.orig;
 cout<<"\nDROP LOCATION: "<<r.dest;
 cout<<"\nDISTANCE: "<<r.dist<<" km";
 cout<<"\nFARE: "<<r.fare<<" INR";
 cout<<"\t\tVEHICLE: ";
 if(ch==1)
 cout<<"Tata Tiago";
 else if(ch==2)
 cout<<"Hyundai Verna";
 else if(ch==3)
 cout<<"TVS King";
 else if(ch==4)
 cout<<"Maruti Suzuki Ertiga";
 else if(ch==5)
 cout<<"Airbus Eurocopter H175";
 else if(ch==6)
 cout<<"Jeep Grand Cherokee";
 else if(ch==7)
 cout<<"Mach City iBike";
 else if(ch==8)
 cout<<"MG Hector";
 else if(ch==9)
 cout<<"Jaguar XE";
 cout<<"\n\t\tVEHICLE NUMBER: "<<random(9000)+1000;
 cout<<"\n\n\n\tPAYMENTS TO BE MADE AFTER REACHING\nDESTINATION USING ANY ONE OF THESE\n";
 cout<<"1.Cash\n";
 cout<<"2.Credit/Debit cards\n";
 cout<<"3.Net Banking\n";
 cout<<"4.CosmoWallet\n";
 cout<<"5.Google Pay\n";
 cout<<"6.Amazon Pay\n";
 cout<<"7.Paytm\n";
 cout<<"8.PhonePe";
 cout<<"\nDo you want to cancel the ride?(y/n): ";
 cin>>c;
 if(c=='y'||c=='Y')
 {
 y.write((char*)&r,sizeof(r));
 remove("Temp3.dat");
 cout<<"\n\t\t\t\tRIDE CANCELLED!!!";
 }
 y.close();
 getch();
 return;
}
void DISPACCOUNT(char name[20]) /*Function to display account
details*/
{
 clrscr();
 cleardevice();
 uaccount a;
 fstream x("accounts.dat",ios::in||ios::binary);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(3);
 settextstyle(7,0,4);
 outtextxy(300,120,"ACCOUNT DETAILS");
 cout<<"\n\n\n\n\n\n\n\n\n";
 while(!x.eof())
 {
 x.read((char*)&a,sizeof(a));
 if(strcmp(name,a.username)==0)
 {
 cout<<"USERNAME: "<<a.username;
 cout<<"\nMOBILE NUMBER: "<<a.mobile;
 cout<<"\nE-MAIL ID: "<<a.email;
 cout<<"\nPASSWORD: "<<a.password;
 break;
 }
 }
 x.close();
 getch();
 return;
}
void DELETEA() /*Function to delete all accounts*/
{
 uaccount a;
 fstream x("accounts.dat",ios::in||ios::binary);
 fstream y("Temp.dat",ios::out||ios::binary); /*Temporary binary file*/
 while(!x.eof())
 {
 x.read((char*)&a,sizeof(a));
 y.write((char*)&a,sizeof(a));
 }
 x.close();
 y.close();
 remove("Temp.dat");
}
void DELETER() /*Function to delete all ride details*/
{
 ride r;
 fstream z("Ride.dat",ios::in||ios::binary);
 fstream w("Temp2.dat",ios::out||ios::binary);
 while(!z.eof())
 {
 z.read((char*)&r,sizeof(r));
 w.write((char*)&r,sizeof(r));
 }
 z.close();
 w.close();
 remove("Temp2.dat");
}
void DISPLAY(char name[]) /*Function to display user menu*/
{
 label:
 clrscr();
 cleardevice();
 int ch;
 uaccount a;
 fstream x("accounts.dat",ios::in||ios::binary);
 setcolor(1);
 setlinestyle(0,0,3); /*Drawing moving border*/
 for(int i=7;i<=600;i++)
 {
 line(7,7,i,7);
 delay(1);
 }
 line(7,7,600,7);
 for(i=7;i<=400;i++)
 {
 line(600,7,600,i);
 delay(1);
 }
 line(600,7,600,400);
 for(i=600;i>=7;i--)
 {
 line(600,400,i,400);
 delay(1);
 }
 line(600,400,7,400);
 for(i=400;i>=7;i--)
 {
 line(7,400,7,i);
 delay(1);
 }
 line(7,400,7,7);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(3);
 settextstyle(7,0,4);
 outtextxy(300,120,"WELCOME");
 cout<<"\n\n\n";
 settextstyle(6,0,2);
 setcolor(2);
 outtextxy(100,200,"1.BOOK A RIDE");
 outtextxy(130,250,"2.EDIT MY ACCOUNT");
 outtextxy(160,300,"3.DISPLAY ACCOUNT DETAILS");
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter the required choice(enter 0 to go to main menu):";
 cin>>ch;
 if(ch==0)
 {
 getch();
 return;
 }
 if(ch==1)
 {
 DISPUSER(); /*Invoking function DISPUSER to book a ride*/
 goto label;
 }
 else if(ch==2)
 {
 MODIFY(); /*Invoking function MODIFY to modify account details*/
 goto label;
 }
 else if(ch==3)
 {
 DISPACCOUNT(name); /*Invoking function DISPACCOUNT to display
account details*/
 goto label;
 }
}
void DISPUSER() /*Function to book a ride*/
{
 clrscr();
 cleardevice();
 int ch;
 ride r;
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(3);
 settextstyle(7,0,4);
 outtextxy(300,120,"BOOK A RIDE");
 cout<<"\n\n\n\n\n\n\n\n\n1.Velocity Nano : Small fares for short rides";
 cout<<"\n2.Velocity Pro : Sedan and SUV rides at reasonable rates";
 cout<<"\n3.Velocity Auto : Auto rides at sensible prices";
 cout<<"\n4.Velocity Van : Share your ride and reduce pollution";
 cout<<"\n5.Velocity Air : Highly punctual air services of the first of its kind";
 cout<<"\n6.Velocity Rental : Want to be your own driver? We've got cars for rent";
 cout<<"\n7.Velocity Pedal : Seeking that last mile connectivity? Bicycles come to the rescue";
 cout<<"\n8.Velocity Tour : Outstation trips in spacious SUVs";
 cout<<"\n9.Velocity Elite : Chaffeur services in luxurious limousines";
 cout<<"\n\t\t\LIST OF PICKUP AND DROP LOCATIONS\n";
 cout<<"\n\tPICKUP\t\t\tDROP\n";
 cout<<"\n\tChennai Airport\t\tThiruvanmiyur\n\tKoyambedu\t\tPoonamallee\n\tVelachery\t\tMarina\n\tChennai Central\t\tMRC Nagar\n\tChennai Egmore\t\tNanganallur\n\tAnna Nagar\t\tAshok Nagar\n\tT.Nagar\t\t\tSaidapet\n\tAdyar\t\t\tRoyapettah\n\tOMR\t\t\tMount Road\n\tKodambakkam\t\tR.A.Puram\n\tVadapalani\t\tK.K.Nagar\n";
 cout<<"Outstation destinations: Puducherry,Coimbatore,Madurai,Cochin,Trichy,Tirupati\n";
 cout<<"NOTE: Fare for requested drop area is same irrespective of drop location within the area";
 cout<<"\nEnter your choice\n";
 cin>>ch;
 cout<<"\nEnter pickup location\n";
 gets(r.orig);
 cout<<"\nEnter drop location\n";
 gets(r.dest);
 cout<<"\nEnter the distance\n";
 cin>>r.dist;;
 cout<<"\nFare: ";
 CALCULATE(r,ch); /*Invoking CALCULATE to calculate fare*/
 getch();
 return;
}
void LOGIN() /*Function to login into account*/
{
 clrscr();
 cleardevice();
 int flag=0;char c;
 setbkcolor(0);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(3);
 settextstyle(7,0,4);
 outtextxy(300,120,"USER LOGIN");
 uaccount a;
 char uname[20],pass[20];
 cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter username: ";
 gets(uname);
 cout<<"\nEnter password: ";
 gets(pass);
 fstream x("accounts.dat",ios::in|ios::binary);
 while(!x.eof())
 {
 x.read((char*)&a,sizeof(a));
 if(strcmp(uname,a.username)==0&&strcmp(pass,a.password)==0)
 {
 DISPLAY(uname); /*Invoking function DISPLAY to display user menu*/
 flag=1;break;
 }
 }
 x.close();
 if(flag==0)
 {
 cout<<"\nYou haven't registered yet. Do you want to register?(y/n)\n";
 cin>>c;
 if(c=='y'||c=='Y')
 CREATE(); /*Invoking function CREATE to create new account*/
 }
 getch();
 return;
}
void main()
{
 home:
 /* Initialising graphics */
 int gdriver = DETECT, gmode, errorcode;
 int style;
 int ch;
 /* initialize graphics mode */
 initgraph(&gdriver, &gmode, "");
 /* read result of initialization */
 errorcode = graphresult();
 if (errorcode != grOk) /* an error occurred */
 {
 printf("Graphics error: %s\n", grapherrormsg(errorcode));
 printf("Press any key to halt:");
 getch();
 exit(1); /* return with error code */
 }
settextjustify(CENTER_TEXT, CENTER_TEXT);
/* select the text style */
 setcolor(1);
 setlinestyle(0,0,3);
 for(int i=7;i<=600;i++)

{
 line(7,7,i,7);
 delay(1);

}
 line(7,7,600,7);
 for(i=7;i<=400;i++)

{
 line(600,7,600,i);
 delay(1);

}
 line(600,7,600,400);
 for(i=600;i>=7;i--
)

{
 line(600,400,i,400);
 delay(1);

}
 line(600,400,7,400);
 for(i=400;i>=7;i--
)

{
 line(7,400,7,i);
 delay(1);
 }
 line(7,400,7,7);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(300,50,"Velocity Cabs");
 setcolor(7);
 settextstyle(7,0,4);
 outtextxy(300,120,"WELCOME");
 settextstyle(6,0,2);
 setcolor(2);
 outtextxy(130,200,"1.ABOUT Velocity Cabs");
 outtextxy(110,250,"2.USER LOGIN");
 outtextxy(170,300,"3.CREATE NEW ACCOUNT");
 outtextxy(100,350,"4.FAQs");
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter the required choice(enter 0 to exit):";
 cin>>ch;
 cleardevice();
 if(ch==0)
 exit(0);
 if(ch==1)
 {
 clrscr();
 cleardevice();
 setcolor(6);
 settextstyle(3,0,7);
 outtextxy(190,100,"ABOUT");
 settextstyle(5,0,7);
 outtextxy(470,95,"Velocity Cabs");
 cout<<"\n\n\n\n\n\n\n\n\n\nVelocity Cabs is one of the leading cab services of India, which provides hassle-free, cheap, punctual and fast rides to various destinations. It employs customer-friendly and reliable drivers for a smooth and relaxing travel experience. It is the first cab company in India to introduce air taxi services to select destinations for both VIPs and the common people, which proves as a great advantage over traffic congested city roads.\n\nFounded: 2015\n\nAwards: TaxiBuff Taxi Of The Year(2019,2018,2017,2015)\n\nFounder and CEO: Aravind Ramachandran";
 getch();
 goto home;
 }
 else if(ch==3)
 {
 CREATE();
 goto home;
 }
 else if(ch==2)
 {
 LOGIN();
 goto home;
 }
 else if(ch==4)
 {
 clrscr();
 cleardevice();
 setbkcolor(0);
 setcolor(4);
 settextstyle(5, 0, 7);
 outtextxy(170,20," Velocity Cabs");
 setcolor(7);
 cout<<"\n\n\n\n\n1.How do I book a cab?\n";
 cout<<"To book a cab, first login using your account username and password. If you do not have";
 cout<<"an account yet, register yourself to create a new account and then proceed.\n";
 cout<<"2.How far in advance should I book my cab?\n";
 cout<<"We strongly recommend that you make your reservation atleast 15 minutes in advance. The";
 cout<<"more time you allow us to plan for your pickup, the better we will be able to make sure";
 cout<<"that all your needs are taken care of.\n";
 cout<<"3.If I have a return pickup, how can I book it?\n";
 cout<<"It must be separately booked.\n";
 cout<<"4.Besides the fare, is there any tax fee? How about tips or gratitude?\n";
 cout<<"Absolutely not! No other hidden charges, no taxes, no waiting charges, no any other additional";
 cout<<"fees besides the quoted fare. Tips are optional. You can tip if you like the driver.\n";
 cout<<"5.Does my cab stop en route?\n";
 cout<<"Except for Velocity Van car-pooling cabs, other cabs are direct, from door to door. Your cab driver\n";
 cout<<"will only stop in case of emergency.\n";
 cout<<"6.Are the prices per person?\n";
 cout<<"Prices shown ARE ALWAYS CALCULATED DEPENDING ON THE DISTANCE OF YOUR TRIP and not per person.\n";
 cout<<"7.What is your cancellation policy?\n";
 cout<<"All cancellations may be made at any time with no consequences or cancellation charges by";
 cout<<"calling our toll-free number 7192 2960 or sending us an email to info@velocitycabs.com.\n";
 getch();
 goto home;
 }
else if(ch==5)
{
 DELETEA(); /*Invoking functions DELETEA and DELETER to delete all
account and ride details*/
 DELETER();
}
/* clean up */
 getch();
 closegraph(); /*Closing graphics*/
}