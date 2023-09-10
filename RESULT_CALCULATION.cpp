
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class node
{

    char name[100];
    string registration_number;
    double CAT1,CAT2,FAT,F_CAT_sc,F_FAT_sc,total,CGPA;
    string grade;
    node *next;

    public:
    node *create(node *);
    void insert(node *);
    void display(node *);
    void rec_rev(node *);
    void delete1(node *);
    void result(node *);
};


node *node ::create(node *head)
{
    head= new node;
    head->next=NULL;
    return head;
}

//insert function
void node:: insert(node *head)
{
    static int P;
    node *temp,*curr;
    temp =new node;
  
    cout<<"\nEnter name: ";
    cin>>temp->name;
    cout<<"\nEnter registration_number: ";
    cin>>temp->registration_number;
    
    cout<<"\nEnter the marks of CAT1(20) :";
    cin>>temp->CAT1;
    cout<<"\nEnter the marks of CAT2(20) :";
    cin>>temp->CAT2;
    cout<<"\nEnter the marks of FAT(80) :";
    cin>>temp->FAT;
    if(temp->CAT1>20||temp->CAT2>20||temp->FAT>80)
    {
      cout<<endl<<"Please check marks of CAT1,CAT2 or FAT - marks should not exceed 20,20,80 respectively"<<endl;
      cout<<"Enter marks again:"<<endl;
      cin>>temp->CAT1>>temp->CAT2>>temp->FAT;
      cout<<endl;
    }

  
    temp->next=NULL;
    curr=head;
    int ch1;
    cout<<endl<<"1.Insert the data at_first \t 2.Insert the data  after a registration NO. \t 3.Insert the data at_last\n";
    cin>>ch1;
    if(ch1==1)
    {   
        P++;
        if(curr->next==NULL)
        curr->next=temp;
        else
        temp->next=curr->next;
        curr->next=temp;
        cout<<endl<<"Data of the student is added successfully"<<endl;
    }

    if(ch1==3)
    {
        P++;
        if(curr->next==NULL)
        curr->next=temp;
    else
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
    curr->next=temp;

    cout<<endl<<"Data of the student is added successfully"<<endl;
    }
    if(ch1==2)
    {
        if(curr->next==NULL)
        curr->next=temp;
        else if(P!=0)
        {
            string reg;
            cout<<"Enter registration NO. after which you want to add data"<<endl;
            cin>>reg;
            while(curr->registration_number!=reg)
            {
                curr=curr->next;
            }
        temp->next=curr->next;
        curr->next=temp;

        }

        else
        {
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
        curr->next=temp;
        }

        cout<<endl<<"Data of the student is added successfully"<<endl;
    }
    cout<<endl;
}


//display function
void node::display(node *head)
{
    node *curr;
    curr=head->next;

    int ch;

    cout<<endl<<"Enter choice"<<endl<<"1.Normal display(given marks) \t 2.Result display(final marks & grades)"<<endl;
    cin>>ch;


    if(curr==NULL)
        cout<<"Nothing to display as there is no record of the student found "<<endl;
    else
    {
        switch(ch)
        {
            case 1:
                {
                    cout<<"\n********saved data********\n\n";

                    cout<<left<<setw(17)<<"NAME"<<left<<setw(17)<<"registration_number"
                        <<left<<setw(17)<<"CAT1(20)"<<left<<setw(17)<<"CAT2(20)"<<left<<setw(17)<<"FAT(80)"<<endl;
                    while(curr!=NULL)
                {
                cout<<left<<setw(17)<<curr->name<<left<<setw(17)<<curr->registration_number
                <<left<<setw(17)<<curr->CAT1
                <<left<<setw(17)<<curr->CAT2<<left<<setw(17)<<curr->FAT<<endl;
                curr=curr->next;
                }
                }
            break;

            case 2:
            {
                cout<<"\n********saved data********\n\n";

                cout<<left<<setw(17)<<"NAME"<<left<<setw(17)<<"registration_number"
                    <<left<<setw(17)<<"FINAL CAT(40)"
                    <<left<<setw(17)<<"FINAL FAT(60)"<<left<<setw(17)<<"total(100)"
                    <<left<<setw(17)<<"CGPA"<<left<<setw(17)<<"Grades"<<endl;
              while(curr!=NULL)
                {
                cout<<left<<setw(17)<<curr->name<<left<<setw(17)<<curr->registration_number
                <<left<<setw(17)<<curr->F_CAT_sc
                <<left<<setw(17)<<curr->F_FAT_sc<<left<<setw(17)<<curr->total
                <<left<<setw(17)<<curr->CGPA<<left<<setw(17)<<curr->grade<<endl;
                curr=curr->next;
                }
            }

            break;

       }

    }
    cout<<endl;
}





//delete function
void node::delete1(node *head)
{
    string nm;
    if(head->next==NULL)
        cout<<"Nothing to delete as there is no record to be deleted"<<endl;
    else
    {
        cout<<endl<<"Enter name whom you want to delete data: ";
        cin>>nm;
        node *curr,*temp;
        curr=head;
        while(curr->next->name!=nm)
        {
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=temp->next;

        cout<<endl<<temp->name<<"'s data is deleted"<<endl<<endl;
        delete temp;

    }

}


//calculating result //
void node ::result(node *head1)
{
    node *curr;
    curr=head1;
    while(curr->next!=NULL)
    {
        curr=curr->next;

        curr->F_CAT_sc=(curr->CAT1+curr->CAT2);
       
        curr->F_FAT_sc=curr->FAT*60/80;
        curr->total=curr->F_CAT_sc+curr->F_FAT_sc;
        curr->CGPA=curr->total/10;
        
        if(curr->CGPA<=10&&curr->CGPA>=9)
            curr->grade="O";
        else if(curr->CGPA<=8.9&&curr->CGPA>=8)
            curr->grade="A+";
        else if(curr->CGPA<=7.9&&curr->CGPA>=7)
            curr->grade="A";
        else if(curr->CGPA<=7.9&&curr->CGPA>=6)
            curr->grade="B+";
        else if(curr->CGPA<=6.9&&curr->CGPA>=5)
            curr->grade="B";
        else if(curr->CGPA<=4.9&&curr->CGPA>=4)
            curr->grade="P(pass)";
        else curr->grade="F(fail)";


    }
    cout<<endl<<"congrats result is calculated"<<endl;
    cout<<endl;
    display(head1);
}

//main function
int main()
{
    int ch;
    node obj;
    node *head;
    head=obj.create(head);
   cout<<endl<<endl;
    cout<<"                                                          STUDENT GRADE CALCULATOR SYSTEM           \n";

    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while(1)
    {
        cout<<"1. Insert record of student \t 2.Calculate result of Student \t 3. Display the result of student\t  4.Delete the record of student\t 5.exit\t"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
    switch(ch)
        {
            case 1:
            obj.insert(head);
            break;

            case 2:
            obj.result(head);
            break;

            case 3:
            obj.display(head);
            break;




            case 4:
            obj.delete1(head);
            break;

            case 5:
            exit(0);
            break;
            
        }
    }

return 0;
}
