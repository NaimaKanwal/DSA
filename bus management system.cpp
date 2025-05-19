#include<string.h>
#include<conio.h>
#include <iostream>
#include <fstream>
using namespace std;
class node
{
	public:
    char name[30],gender[10],email[50],clas[30];
    char cname[30],cgender[10],cemail[50],cclas[30];
    char bsna[100],src[50],dest[50];
    int age,cage,n,adult,child,nott,ptno;
    char mobno[20];
    char idno[30],cidno[30];
    char x[10];
    int bstt,bsno;
       int dd, mm, yy; 
    char source[20],destination[20],date[20],data[100];
    float fare,cfare,insurance,total,km,arr,dept;
    char adname[50],adpass[50];
	node *next;

};

class travel
{
	public:
    int bstt,bsno;
    char bsna[100],src[50],dest[50];
    float km,arr,dept;
};
 travel obj;
node *head=NULL,*headd=NULL,*p,*r,*last=NULL,*lastt=NULL,*q=NULL,*s=NULL;
int n,m,i;

void book();
void display1();
node* insert();
node* insertbussbw();
void read();
void write();
void writedatabase();
void writesorteddb();
void sortbus();
void readsorteddb();
void readdatabase();
void busdatabase();
void insertbus();
void displaybus();
void specialbusdisplay();
void busselect();
void payout();
void payoutread();
void payoutwrite();
void displaysearchbusticket();
int count1=0;int count2=0;int count3=0;int count4=0;
void login();

int found=0;
int ch,x,c=' ',choice1,choice2;
char str1[20],str2[20],str3[20],str4[20];
char str5[]="admin",str6[]="admin",str7[20],str8[20];
char choice3[]="y",choice4[10],choice5[10];
char adname[50],adpass[50];char input[255];
int status1;


void login(){
	  r=headd;
            i=0;
            cout<<"\n Enter Name:\t";
            cin>>str1;
            cout<<"\n Enter  Password:\t";
                    while (i<=9)
                    {
                    str2[i]=getch();
                    if(str2[i]==13)
                    break;
                    else
					cout<<"*";
                    i++; }
                    str2[i]='\0';
            for(i=1;r!=NULL;i++)
            { if((strcmp(r->adname,str1)==0)&&(strcmp(r->adpass,str2)==0))
                {
                strcpy(adname,r->adname);
                strcpy(adpass,r->adpass);
                found=1;
                }
           r=r->next;
            }
}
void book()
{    char choice3[]="y",choice4[10],choice5[10];
	read();
int valid;
	char dateStr[10];
    node *p;
	int i=0,choice;
	p=last;
	if(last==NULL)	{i=1;
	last=new node;
	last->next=NULL;
	cout<<"\n\tSource:\t\t";      
    cin>>last->source;
    cout<<"\n\tDestination:\t\t";    
    cin>>last->destination;
     int dd, mm, yy; 
            cout<<"\n\n\tEnter the Date of travel(dd/mm/yyyy):\t\t";
            cin>>dd>>mm>>yy;
    system("CLS");
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"\n\tTotal Number of passenger:\t\t";
    cin>>last->n;
    cout<<"\n\tAdult:\t";
    cin>>last->adult;
    last->child=(last->n)-(last->adult);
    cout<<"\n\tChild:\t"<<last->child;
    cout<<"\n----------------------------------------------------------------------------\n";
	cout<<"                             ADULT Details                   "                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
    for(; i<=(last->adult);i++)
    {
        cout<<"\n\tEnter the Passenger Name:\t";
        cin>>last->name;
        do{
            cout<<"\n\tAge:\t\t";
            cin>>last->age;
            if((last->age)<18){
              cout<<"\n\t\tInvalid AGE ....!!!!!!!\n";
            }
        }while((last->age)<18);
        cout<<"\n\tGender(M/F):\t\t";
        cin>>last->gender;

        do{
        cout<<"\n\tMobile No:\t\t";
        cin>>last->mobno;
        if(strlen(last->mobno)!=10){
            cout<<"\n\t\tInvalid MOBILE NO ....!!!!!!!\n" ;
        }
        }while(strlen(last->mobno)!=10);

        cout<<"\n\tEmail id:\t\t";
        cin>>last->email;
        do{
        cout<<"\n\tIdentification no:\t\t";
        cin>>last->idno;
        if(strlen(last->idno)!=13){
        cout<<"\n\t\tInvalid ID NO ....!!!!!!!\n" ;
        }
    }while(strlen(last->idno)!=13);

    }
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                             CHILD Details                   "                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
	i=0;
	for(;i<(last->child);i++)
    {
        cout<<"\n\tChild Name:\t";
        cin>>last->cname;
         do{
            cout<<"\n\tAge:\t\t";
            cin>>last->cage;
            if((last->cage)>18){
              cout<<"\n\t\tInvalid AGE ....!!!!!!!\n";
            }   }while((last->cage)>18);
        cout<<"\n\tGender(M/F):\t\t";
        cin>>last->cgender;
         do{
        cout<<"\n\tIdentification no :\t\t";
        cin>>last->cidno;
        if(strlen(last->cidno)!=13){
        cout<<"\n\t\tInvalid ID NO ....!!!!!!!\n";
        }
    }while(strlen(last->cidno)!=13);
       
    }
	p=last;
	head=last;
	}
    else{
	p=last;
	p->next=new node;
	p=p->next;
	last=p;
	cout<<"\n\tSource:\t\t";      //source of travel
    cin>>p->source;
    cout<<"\n\tDestination:\t\t"; 
	cin>>p->destination;    //destination of travel
            cout<<"\n\n\tEnter the Date of travel(dd/mm/yyyy):\t\t";
            cin>>p->dd>>p->mm>>p->yy;
        
    system("CLS");
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"\n\tTotal Number of passenger:\t\t";
    cin>>p->n;
    cout<<"\n\tAdult:\t";
    cin>>p->adult;
    p->child=(p->n)-(p->adult);
    cout<<"\n\tChild:\t"<<p->child;
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                             ADULT Details                   "                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
    for(i=0;i<(p->adult);i++)
    {
        cout<<"\n\tEnter the Passenger Name:\t";
        cin>>p->name;
       do{
            cout<<"\n\tAge:\t\t";
            cin>>p->age;
            if((p->age)<18){
              cout<<"\n\t\tInvalid AGE ....!!!!!!!\n" ;
            } }while((p->age)<18);
        cout<<"\n\tGender(M/F):\t\t";
        cin>>p->gender;
        do{
        cout<<"\n\tMobile No:\t\t";
        cin>>p->mobno;
        if(strlen(p->mobno)!=10){
            cout<<"\n\t\tInvalid MOBILE NO ....!!!!!!!\n" ;
        }
        }while(strlen(p->mobno)!=10);
        cout<<"\n\tEmail id:\t\t";
        cin>>p->email;
        do{
        cout<<"\n\tCNIC no:\t\t";
        cin>>p->idno;
        if(strlen(p->idno)!=13){
        cout<<"\n\t\tInvalid ID NO ....!!!!!!!\n" ;
        }
    }while(strlen(p->idno)!=10);
    }
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                             CHILD Details                   "                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
	for(i=0;i<(p->child);i++)
    {
        cout<<"\n\tChild Name:\t";
        cin>>p->cname;
         do{
            cout<<"\n\tAge:\t\t";
            cin>>p->cage;
            if((p->cage)>18){
              cout<<"\n\t\tInvalid AGE ....!!!!!!!\n" ;
            }
        }while((p->cage)>18);
        cout<<"\n\tGender(M/F):\t\t";
        cin>>p->cgender;
          do{
        cout<<"\n\tCNIC no:\t\t";
        cin>>p->cidno;
        if(strlen(p->cidno)!=13){
        cout<<"\n\t\tInvalid ID NO ....!!!!!!!\n" ;
        }
    }while(strlen(p->cidno)!=10);

    }
	p->next=NULL;
	}
cout<<"\n----------------------------------------------------------------------------\n";
	cout<<"\n\n\n1. CONFIRM BOOKING \t2. EDIT TICKET \t3. CANCEL BOOKING\n \t Choice:\t";
	cout<<"\n----------------------------------------------------------------------------\n";
	cin>>choice;
	switch(choice)
	{
	    case 1:write();
                break;
        case 2:
		display1();
                cout<<"\n---------------------------------------";
                cout<<"\nDo You Want to edit the ticket (y/n):";
                cin>>choice5;
               if((strcmp(choice3,choice5))==0)
               {
                   book();
               }
               else
               {
                   break;
               }
                break;
        case 3: exit(0);
            break;
	}	}

void display1()
{
    int i;
	p=head;
	if(p==NULL)
	{
	cout<<"list is empty";
	}
	else
	{
	for(i=0;p!=NULL;i++)
	{
	cout<<"\n\tSource:\t\t";      //source of travel
    cout<<p->source;
    cout<<"\n\tDestination:\t\t";     //destination of travel
    cout<<p->destination;
    cout<<"\n\tEnter the Date of travel(dd/mm/yyyy):\t\t";
    cout<<p->dd<<" "<<p->mm<<" "<<p->yy;
	cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"\n\tTotal Number of passenger:\t\t";
    cout<<p->n;
    cout<<"\n\tAdult:\t";
    cout<<p->adult;
    cout<<"\n\tChild:\t";
	cout<<p->child;
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                             ADULT Details                   "                   ;
    cout<<"\n----------------------------------------------------------------------------\n";
        cout<<"\n\t Passenger Name:\t";
        cout<<p->name;
        cout<<"\n\tAge:\t\t";
        cout<<p->age;
        cout<<"\n\tGender(M/F):\t\t";
        cout<<p->gender;
        cout<<"\n\tMobile No:\t\t";
        cout<<p->mobno;
        cout<<"\n\tEmail id:\t\t";
        cout<<p->email;
        cout<<"\n\tIdentification no:\t\t";
        cout<<p->idno;

    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                             CHILD Details                   "                   ;
    cout<<"\n----------------------------------------------------------------------------\n";
        cout<<"\n\tChild Name:\t"<<p->cname;
        cout<<"\n\tAge:\t\t"<<p->cage;
        cout<<"\n\tGender(M/F):\t\t"<<p->cgender;
        cout<<"\n\tIdentification no :"<<p->cidno;
	p=p->next;
	}}}

void write()
	{
	FILE *ne=fopen("Ticket_booking.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
	printf("\n\t DATA IS BEING SAVED IN DATABASE\n");
	for(i=0;temp!=NULL;i++)
	{
	fprintf(ne,"%s\n",temp->source,"%s\n",temp->destination,"%s\n",temp->date,"%d\n",temp->n,"%d\n",temp->adult,"%d\n",temp->child,"%s\n",temp->name,"%d\n",temp->age,"%s\n",temp->gender,"%s\n",temp->mobno);
  fprintf(ne,"%s\n",temp->email,"%s\n",temp->idno,"%s\n",temp->clas,"%s\n",temp->cname,"%d\n",temp->cage,"%s\n",temp->cgender,"%s\n",temp->cidno,"%s\n",temp->cclas);
	temp=temp->next;
	}//for
	printf("\n\t----- DONE ----- DATA SAVED SUCCESSFULLY\n");
	}//else
	fclose(ne);
	}

void read()
	{
	int i,filempty=0;
	FILE *infile=fopen("Ticket_booking.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=new node;
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	cout<<"\nFile empty\n";
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"%s\n",p->source,"%s\n",p->destination,"%s\n",p->date,"%d\n",&p->n,"%d\n",&p->adult,"%d\n",&p->child,"%s\n",p->name,"%d\n",&p->age,"%d\n"),
    fscanf(infile,"%s\n",p->gender,"%s\n",p->mobno,"%s\n",p->email,"%s\n",p->idno,"%s\n",p->clas,"%s\n",p->cname,"%d\n",&p->cage,"%s\n",p->cgender,"%s\n",p->cidno,"%s\n",p->cclas))
	{
	if(feof(infile))
	{
	break;
	}
	p->next=new node;
	p=p->next;
	last=p;
	p->next=NULL;
	}}
	}
void busdatabase()
{                
  do{
      system("CLS");
      cout<<"\n--------------------------------------------------------\n";
      cout<<"                        MENU                      ";
      cout<<"\n--------------------------------------------------------\n\n";
      cout<<"\t1. Add Bus \n";
      cout<<"\t2. Insert Bus at specific location\n";
      cout<<"\t3. Display the Bus \n";
      cout<<"\t0. EXIT\n";
      cout<<"\n--------------------------------------------------------\n";
      cout<<"Choice:\t";
      cin>>choice2;
      switch(choice2)
                {
                    case 1: system("CLS");
                            insertbus();
                       cout<<"\n\t\tPress Any Key to Continue ....!!!!!!!\n" ;
                            getch();
                            break;
                    case 2: system("CLS");
                            displaybus();
                            insertbussbw();
                     cout<<"\n\t\tPress Any Key to Continue ....!!!!!!!\n" ;
                            getch();
                            break;
                    case 3: system("CLS");
                            specialbusdisplay();
                             cout<<"\n\n\n0. MAIN MENU\t\t\t";
                             cout<<"1. SUB MENU\n\n";
                             cout<<"Choice:\t";
                            cin>>choice2;
                            break;
                    case 4:
					break;        
                }
                }while(choice2!=0);
}

void insertbus()
{  
 do{
    readdatabase();

    found=0;
    p=head;
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus   No|| Source || Destination ||    Bus   name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n   ";
     cout<<"\t";
    cin>>(obj.bsno)>>obj.src>>obj.dest>>obj.bsna>>obj.km>>obj.arr>>obj.dept>>obj.bstt;
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->bsno==obj.bsno)
                            {
      cout<<p->bsno<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
                            found=1;
                             cout<<"\n\t\t Oopps  !!!  Bus Already Present ....\n" ;
                            }
                            p=p->next;

                            }}while(found==1);
    node *p;
	int i=0;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=new node;
	last->next=NULL;
	last->bsno=obj.bsno;
    strcpy(last->src,obj.src);
    strcpy(last->dest,obj.dest);
    strcpy(last->bsna,obj.bsna);
    last->km=obj.km;
    last->arr=obj.arr;
    last->dept=obj.dept;
    last->bstt=obj.bstt;
	p=last;
	head=last;
	}//if
else{i=0;
	p=last;
	p->next=new node;
	p=p->next;
	last=p;
    p->bsno=obj.bsno;
    strcpy(p->src,obj.src);
    strcpy(p->dest,obj.dest);
    strcpy(p->bsna,obj.bsna);
    p->km=obj.km;
    p->arr=obj.arr;
    p->dept=obj.dept;
    p->bstt=obj.bstt;
	p->next=NULL;
	}//i for
   writedatabase();
   cout<<"\n\n\t\tBus Added Successfully ....!!!!!!!\n\n";
  }
void specialbusdisplay()
{
     do{
                system("CLS");
                 cout<<"\n--------------------------------------------------------\n";
                 cout<<"                    DISPLAY MENU                      ";
                 cout<<"\n--------------------------------------------------------\n\n";
                 cout<<"\t1. Unsorted BUSES \n";
                 cout<<"\t0. EXIT\n";
                 cout<<"\n--------------------------------------------------------\n";
                 cout<<"Choice:\t";
                cin>>choice2;
                switch(choice2)
                {
                    case 1: system("CLS");
                            readdatabase();
                             p=head;
                            if(p==NULL)
                            {
                             cout<<"list is empty";
                            }
                            else
                                {
                             cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
                             cout<<"Bus No|| Source || Destination ||    Bus name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
                             cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n   ";
                            for(i=0;p!=NULL;i++)
                            {
                             cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
                             p=p->next;
                            }}
                             cout<<"\n\n\n0. MAIN MENU\t\t\t";
                             cout<<"1. SUB MENU\n\n";
                             cout<<"Choice:\t";
                            cin>>choice2;
                            break;
                }
                }while(choice2!=0);

}
void displaybus()
{
    readdatabase();
	p=head;
	if(p==NULL)
	{
	 cout<<"list is empty";
	}
	else
{
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus No|| Source || Destination ||    Bus name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n   ";
    for(i=0;p!=NULL;i++)
	{
     cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
    p=p->next;
	}}}

void writedatabase()
	{
FILE *ne=fopen("Sorted_BUS_database.txt","w");
	int i;
	node *temp;
	temp=head;
	if(temp==NULL)
	{
	     cout<<"Empty File";
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
	fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->bsno),temp->src,temp->dest,temp->bsna,temp->km,temp->arr,temp->dept,(temp->bstt));
   temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}
void readdatabase()
	{
	int i,filempty=0;
	FILE *infile=fopen("Sorted_BUS_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=new node;
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	cout<<"File empty";
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
    while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(p->bsno),p->src,p->dest,p->bsna,&(p->km),&(p->arr),&(p->dept),&(p->bstt)))
{
	if(feof(infile))
	{
	break;
	}
	p->next=new node;
	p=p->next;
	last=p;
	p->next=NULL;}}}
node* insertbussbw()
{
    readdatabase();
    int i,loc;
    int tno,ttt;
    char tna[100],src[50],dest[50];
    float arr,dept,km;
     cout<<"\nEnter the position:";
    cin>>loc;
   do{
        readdatabase();
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus   No || Source || Destination || Bus   name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n   ";
     cout<<"\t";
    cin>>(tno)>>src>>dest>>tna>>km>>arr>>dept>>ttt;
    found=0;
    p=head;
    for(i=1;p!=NULL;i++)
                            {
                            if(p->bsno==tno)
                            {
     cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
                            found=1;
                             cout<<"\n\t\t Oopps  !!!  Bus Already Present ....\n" ;
                            }
                            p=p->next;

                            }}while(found==1);

    p=head;
	q=head;
    p=new node;
    p->bsno=tno;
    strcpy(p->src,src);
    strcpy(p->dest,dest);
    strcpy(p->bsna,tna);
    p->km=km;
    p->arr=arr;
    p->dept=dept;
    p->bstt=ttt;
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        writedatabase();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
    writedatabase();
    cout<<"\n\n\t\tBus Added Successfully ....!!!!!!!\n\n";

    return(head);
}

void sortbus()
	{
	int k;
	readdatabase();
	int temp;
	node *i,*j;
	for(i=head;i!=NULL;i=i->next)
	{
        for(j=i->next;j!=NULL;j=j->next)
        {
            if((i->bsno)>(j->bsno))			//write integer variable only in place of data
            {
                obj.bsno=i->bsno;
                obj.km=i->km;
                obj.arr=i->arr;
                obj.dept=i->dept;
                obj.bstt=i->bstt;

                i->bsno=j->bsno;
                i->km=j->km;
                i->arr=j->arr;
                i->dept=j->dept;
                i->bstt=j->bstt;

                j->bsno=obj.bsno;
                j->km=obj.km;
                j->arr=obj.arr;
                j->dept=obj.dept;
                j->bstt=obj.bstt;

                strcpy(obj.src,i->src);
                strcpy(i->src,j->src);
                strcpy(j->src,obj.src);
                strcpy(obj.dest,i->dest);
                strcpy(i->dest,j->dest);
                strcpy(j->dest,obj.dest);
                strcpy(obj.bsna,i->bsna);
                strcpy(i->bsna,j->bsna);
                strcpy(j->bsna,obj.bsna);

             }}

	writesorteddb();
	}}//void sort

void writesorteddb()
{
	FILE *ne=fopen("Bus_database.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	cout<<"Empty File";
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->bsno),temp->src,temp->dest,temp->bsna,temp->km,temp->arr,temp->dept,(temp->bstt));
   temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}

void readsorteddb()
	{
	int i,filempty=0;
	FILE *infile=fopen("Bud_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=new node;
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	cout<<"File empty";
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(p->bsno),p->src,p->dest,p->bsna,&(p->km),&(p->arr),&(p->dept),&(p->bstt)))
{
	if(feof(infile))
	{
	break;
	}
	p->next=new node;
	p=p->next;
	last=p;
	p->next=NULL;
}}}

void displaysortedbus()
{
	readsorteddb();
	int i;
	p=head;
	if(p==NULL)
	{
	 cout<<"list is empty";
	}
	else
		{
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus No|| Source || Destination ||    Bus name    || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n   ";
	for(i=0;p!=NULL;i++)
	{
     cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
	p=p->next;
}}}

void deletebus()
{   node *p,*q;
	readsorteddb();
	int loc,i;
	 cout<<"\nEnter the location to delete:\t";
	cin>>loc;
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writesorteddb();
        displaysortedbus();
    	delete p;
        cout<<head;
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writesorteddb();
    displaysortedbus();
    delete p;
    n=n-1;
	}
	else
	{
	 cout<<"\nSorry,The list is empty";
	}}
void busselect()
{   char temp1[50],temp2[50];
    system("CLS");
    read();
    int i,found=0;
	p=head;
	if(p==NULL)
	{
	 cout<<"File is Empty:";
	}
	else
	{
	for(i=0;p!=NULL;i++)
	{
     cout<<"\n\tSource:\t\t";      //source of travel
     cout<<p->source;
    strcpy(temp1,p->source);
     cout<<"\n\tDestination:\t\t";     //destination of travel
     cout<<p->destination;
    strcpy(temp2,p->destination);
    break;
	}
    }
    readsorteddb();
    p=head;
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus   No || Source || Destination || Bus   name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n   ";
    for(i=1;p!=NULL;i++)
    {
    if((strcmp(p->src,temp1)==0)&&(strcmp(p->dest,temp2)==0))
    {
      cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
      found=1;
    }
    p=p->next;
    }
    if(!found)
    {
     cout<<"\n\t Oops !!!! No BUS found\n\n";
    }

}
void payout()
{   int ptno,ch;
    float pkm,fare,cfare,afare,tfare;
    char choice3[]="y",choice[10],a[]="SL",b[]="3AC",c[]="2AC";
    FILE *as;
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
   do{
     cout<<"\nSelect the Bus No:";
    cin>>ptno;
    struct node *p;
    p=head;
    p=new node;
    p->ptno=ptno;
    head=p;
    payoutwrite();
                            readdatabase();
                            found=0;
                            p=head;
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->bsno==ptno)
                            {
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus   No || Source || Destination || Bus   name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n   ";
     cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
                        pkm=p->km;
                            found=1;
                            }
                            p=p->next;
                            }if(!found)
                            {
                             cout<<"\n\t\t Enter Valid Bus no ....\n" ;
                            found=3;
                            }}while(found==3);

	int temp3,temp4;
	char temp5[10],temp6[10];
    read();
    int i,found=0;
	p=head;
	if(p==NULL)
	{
	 cout<<"File is Empty:";
	}
	else
	{

	for(i=0;p!=NULL;i++)
	{
     cout<<"\n\tAdult:\t\t";      //source of travel
     cout<<p->adult;
    temp3=p->adult;
    cout<<"\n\tChild:\t\t";     //destination of travel
    cout<<p->child;
    temp4=p->child;
    strcpy(temp5,p->clas);
     strcpy(temp6,p->cclas);
    if(strcmp(temp6,a)==0)
    { cfare=(pkm*temp4*33); }
    if(strcmp(temp5,a)==0){
            afare=(pkm*temp3*45);
    }
    if(strcmp(temp6,b)==0)
    { cfare=(pkm*temp4*33);  }
    if(strcmp(temp5,b)==0){
   afare=(pkm*temp3);
    }

 if(strcmp(temp6,c)==0)
    { cfare=(pkm*temp4*45);   }
    if(strcmp(temp5,c)==0){
   afare=(pkm*temp3);
    }
      fare=cfare+afare;
     cout<<"\n\tChild fare:"<<cfare<<"\t\t";
     cout<<"\n\tAdult fare:"<<afare<<"\t\t";
     cout<<"\n\tTemporary fare:"<<fare<<"\t\t";
     cout<<"\n------------------------------------------------------------------------\n";
    cout<<"\n\tWant to take insurance(y/n)\n\t Rs 1/Km for child\n\t Rs 2/Km for adult: ";
   cin>>choice;
   if(strcmp(choice3,choice)==0)
   {
       tfare=(1*pkm*temp4)+(temp3*pkm*2)+fare;
         cout<<"\n\tTotal fare:"<<tfare<<"\t\t";
   }else{tfare=fare;
     cout<<"\n\tTotal fare:"<<tfare<<"\t\t";}
     cout<<"\n------------------------------------------------------------------------\n";
	 cout<<"\t1. Pay Now \t\t2. Cancel & EXIT\n";
     cout<<"\n------------------------------------------------------------------------\n";
	 cout<<"\tChoice:";
	cin>>ch;
 switch(ch)
 {
     case 1:
            cout<<"\n Bus_no:"<<ptno<<"\n Child_Fare:"<<cfare<<"\n Adult_Fare:"<<afare<<"\n Total_fare(Without_Ins):"<<fare<<"\n Total_fare(With_Ins):"<<tfare<<"\n ";
             as=fopen("Booking_reciept.txt","w");
            fprintf(as,"\n Bus_no:%d\n Child_Fare:%.2f\n Adult_Fare:%.2f\n Total_fare(Without_Ins):%.2f\n Total_fare(With_Ins):%.2f\n ",ptno,cfare,afare,fare,tfare);
            fclose(as);
                  cout<<"\n------------------------------------------------------------------------\n";
                  cout<<"\t\tPayment Successfully Done\n";
                  cout<<"\n------------------------------------------------------------------------\n";

        break;
    case 2: exit(0);
    break;
 }
 break;}}}
void payoutread()
	{
	int i,filempty=0;
	FILE *ppy=fopen("Booking.txt","r");
	p=head;
	fseek(ppy,0,SEEK_END);
	if(p==NULL)
	{
	p=new node;
	head=p;
	}
	int len=(int)ftell(ppy);
	if(len<=0)
	{
	filempty=1;
	cout<<"\t\tFile empty";
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(ppy);
	while(fscanf(ppy,"\n%d",&p->ptno))
	{
	if(feof(ppy))
	{
	break;
	}
	p->next=new node;
	p=p->next;
	last=p;
	p->next=NULL;
	}
	}
	fclose(ppy);
	}

void payoutwrite()
	{
	FILE *py=fopen("Booking.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	cout<<"list is empty";
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
	fprintf(py,"\n%d",temp->ptno);
	temp=temp->next;
	}//for
	}//else
	fclose(py);
	}
static int p1 = 0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}
bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{
  cout<<"Enter bus no: ";
  cin>>bus[p1].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p1].driver;
  cout<<"\nArrival time: ";
  cin>>bus[p1].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p1].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p1].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p1].to;
  bus[p1].empty();
  p++;
}
void a::allotment(){
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p1;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p1)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p1)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }
void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p1].seat[i][j], "Empty");
    }
  }
}
void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p1;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p1)
{
  vline('*');
  cout<<"Bus no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p1)
    cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
void a::avail()
{
  for(int n=0;n<p1;n++)
  {
    vline('*');
    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t" <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}
void displaysearchbusticket()

{   payoutread();
int ptno;
    p=head;
    ptno=p->ptno;
  i=0,found=0;

    readsorteddb();
    p=head;
     cout<<"\n\n\tBooked Bus is ....\n" ;
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Bus   No || Source || Destination || Bus   name || Distance(KM) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||";
     cout<<"\n---------------------------------------------------------------------------------------------------------------------\n   ";
    for(i=1;p!=NULL;i++)
    {
    if(p->bsno==ptno)
    {
     cout<<(p->bsno)<<"\t "<<p->src<<"\t "<<p->dest<<"\t\t "<<p->bsna<<"\t\t "<<p->km<<"\t\t "<<p->arr<<"\t\t "<<p->dept<<"\t\t "<<(p->bstt)<<"\n";
    found=1;
    }
    p=p->next;
    }
}

int main()
{
    FILE *infile;
do{
	cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                     Welcome to Bus Reservation System"                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"\tLog in as:\n";
    cout<<" \n\t\t 1. ADMIN \n\n\t\t 2. PASSANGER \n\n\t\t 0. EXIT";
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"                                                            "                    ;
    cout<<"\n----------------------------------------------------------------------------\n";
    cout<<"\n\tChoice:\t\t";
    cin>>ch;
    a:
    switch(ch)
    {
        case 1:
        cout<<"\n----------------------------------------------------------------------------\n";
        cout<<"                     Welcome ADMIN"                    ;
        cout<<"\n----------------------------------------------------------------------------\n";
          	login();
            if((found)==1 || ((strcmp(str5,str1)==0) &&( strcmp(str6,str2)==0) ))
            {
        do
        {    system("CLS");
             cout<<"\n---------------------------------------------\n";
             cout<<"                   Menu                      ";
             cout<<"\n---------------------------------------------\n";
             cout<<"\n\t1. Book ticket\n\t2. Display Booked ticket\n\t3. Manage Bus Systems\n\t0. Exit\n\t";
             cout<<"Choice:\t";
             cin>>choice1;
                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1:
                        system("CLS");
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"                     Ticket Booking"                    ;
                        cout<<"\n----------------------------------------------------------------------------\n";
						int w;
						  
						  cout<<"\t1.Add bus\n\t";
						  cout<<"2.Reservation\n\t";
						  cout<<"3.Exit";
						  cout<<"\n\tEnter your choice:-> ";
						  cin>>w;
						  switch(w)
						  {
						    case 1: 
							 bus[p1].install();
							 cout<<"\nPress enter to continue";
							 getch();
						    break;
						    case 2:  
							bus[p1].allotment();
							cout<<"\nPress enter to continue";
							getch();
						    break;
						    case 3:
						    cout<<"\nPress enter to continue";
						    getch();
						    break;
						  }
                        break;
                case 2:
                	int f;
                        system("CLS");
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"                             Booked ticket"                    ;
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"\t1.Show\n\t";
						cout<<"2.Buses Available. \n\t";
						cout<<"3.Exit";
						cout<<"\n\tEnter your choice:-> ";
						  cin>>f;
						  switch(f)
						  {
						case 1:  
						bus[0].show();
						cout<<"\nPress enter to continue";
						getch();
						break;
						case 2: 
						bus[0].avail();
						cout<<"\nPress enter to continue";
						getch();
						break;
						case 3:
							break;
						cout<<"\nPress enter to continue";
						getch();
                        break;
                    	}
                break;
                case 3:
                        system("CLS");
                        busdatabase();
                }
        cout<<"\n----------------------------------------------------------------------------\n";
        cout<<"\n\tWant to Continue[Main Menu] (y/n):\t";
        cin>>choice4;
        }while((strcmp(choice3,choice4))==0);

        }else
        {
        system("CLS");
        cout<<"\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n";
        }
        break;
    case 2: do
        {    system("CLS");
             cout<<"\n---------------------------------------------\n";
             cout<<"                 USER Menu                      ";
             cout<<"\n---------------------------------------------\n";
             cout<<"\n\t1. Book ticket\n\t2. Display Booked ticket\n\t3. available buses\n\t4. Cancel ticket\n\t0. EXIT \n\n\t";
             cout<<"Choice:\t";
             cin>>choice1;
                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1:
                        system("CLS");
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"                     Ticket Booking"                    ;
                        cout<<"\n----------------------------------------------------------------------------\n";
                        book();
                        busselect();
                        payout();
                        break;
                case 2:
                        system("CLS");
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"                             Booked ticket"                    ;
                        cout<<"\n----------------------------------------------------------------------------\n";
                        display1();
                        displaysearchbusticket();
   						infile=fopen("Booking_reciept.txt","r");
                        cout<<"\n----------------------------------------------------------------------------\n";
                        cout<<"                              FARE DETAILS"                    ;
                        cout<<"\n----------------------------------------------------------------------------\n";
					    do
					      {
					        status1 = fscanf(infile, "%s", &input);
                        cout<<input;
					     }while(status1 != -1);
                          printf("\n----------------------------------------------------------------------------\n");
					  	 fclose(infile);
                        break;
                case 3: system("CLS");
                            specialbusdisplay();
                             cout<<"\n\n\n0. MAIN MENU\t\t\t";
                             cout<<"1. SUB MENU\n\n";
                             cout<<"Choice:\t";
                            cin>>choice2;
                            break;
                case 4:
                        system("CLS");
                        cout<<"Your ticket has been canceled";
                        break;
                }
        cout<<"\n----------------------------------------------------------------------------\n";
        cout<<"\n\tWant to Continue[Main Menu] (y/n):\t";
        cin>>choice4;
        }while((strcmp(choice3,choice4))==0);
        break;
    case 0: exit(0);
    }
    goto a;}	while(!found==1);
}