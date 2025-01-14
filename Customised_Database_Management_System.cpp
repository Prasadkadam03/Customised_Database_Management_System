// Customised Database Management System

#include<iostream>
#include<string>

using namespace std;

class node
{
    private:
        static int Counter;

    public:
        int Rno;
        string Name;
        string City;
        int Marks;

        node *next;

        node(string B, string C, int D)
        {
            Rno = Counter;
            Counter++;

            Name = B;
            City = C;
            Marks = D;
            next = NULL;
        }
};

int node::Counter = 1;

class DBMS
{
    private:
        node *first;

    public:
        DBMS()
        {
            first = NULL;
            cout<<"DBMS initailised succesfully..."<<"\n";
            cout<<"Student Table gets created succesfully..."<<"\n";
        }

        // Destructor
        // Free all the nodes of the table
        ~DBMS()
        {
            node *temp = NULL;

            while(first != NULL)
            {
                temp = first;
                first = first->next;
                delete temp;
            }
        }

        // InsertLast
        // insert into table student values(1,'Amit','Pune',89);
        void InsertIntoTable(string Name, string City, int Marks)
        {
            node *newn = new node(Name,City,Marks);

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                node *temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }
            cout<<"One record gets inserted succesfully..."<<"\n";
        }

        // Display
        // select * from student
        void SelectStarFrom()
        {
            cout<<"Data from the student table is : "<<"\n";

            node *temp = first;

            cout<<"--------------------------------------------------------------"<<"\n";
            while(temp != NULL)
            {
                cout<<temp->Rno<<"\t"<<temp->Name<<"\t"<<temp->City<<"\t"<<temp->Marks<<"\n";
                temp = temp->next;
            }
            cout<<"--------------------------------------------------------------"<<"\n";
        }

        // select * from student where city = '_____';
        void SelectStarFromWhereCity(string str)
        {
            cout<<"Data from the student table where city is : "<<str<<"\n";

            node *temp = first;

            cout<<"--------------------------------------------------------------"<<"\n";
            while(temp != NULL)
            {
                if(str == temp->City)
                {
                    cout<<temp->Rno<<"\t"<<temp->Name<<"\t"<<temp->City<<"\t"<<temp->Marks<<"\n";
                }
                temp = temp->next;
            }
            cout<<"--------------------------------------------------------------"<<"\n";
        }

        //select Count(Marks) from student;
        void SelectCount()
        {
            node *temp = first;
            int iCnt = 0;

            while(temp != NULL)
            {
                temp = temp->next;
                iCnt++;
            }

            cout<<"Number of records in the table : "<<iCnt<<"\n";
        }

        //select Sum(Marks) from student;
        void SelectSum()
        {
            node *temp = first;
            int iSum = 0;

            while(temp != NULL)
            {
                iSum = iSum + temp->Marks;
                temp = temp->next;
            }

            cout<<"Summation of Marks column is : "<<iSum<<"\n";
        }

        //select Avg(Marks) from student;
        void SelectAvg()
        {
            node *temp = first;
            int iSum = 0;
            int iCnt = 0;

            while(temp != NULL)
            {
                iSum = iSum + temp->Marks;
                temp = temp->next;
                iCnt++;
            }

            cout<<"Average of Marks column is : "<<(float)((float)iSum/(float)iCnt)<<"\n";
        }

        //select Max(Marks) from student;
        void SelectMax()
        {
            node *temp = first;
            int iMax = 0;

            if(temp != NULL)
            {
                iMax = temp->Marks;
            }

            while(temp != NULL)
            {
                if(temp->Marks > iMax)
                {
                    iMax = temp->Marks;
                }
                temp = temp->next;
            }

            cout<<"Maximum of Marks column is : "<<iMax<<"\n";
        }

        //select Min(Marks) from student;
        void SelectMin()
        {
            node *temp = first;
            int iMin = 0;

            if(temp != NULL)
            {
                iMin = temp->Marks;
            }

            while(temp != NULL)
            {
                if(temp->Marks < iMin)
                {
                    iMin = temp->Marks;
                }
                temp = temp->next;
            }

            cout<<"Minimum of Marks column is : "<<iMin<<"\n";
        }

        //select * from student where name = "_____";
        void SelectStarFromName(string str)
        {
            node *temp = first;

            cout<<"Information of all students with the name : "<<str<<"\n";

            while(temp != NULL)
            {
                if(str == temp->Name)
                {
                    cout<<temp->Rno<<"\t"<<temp->Name<<"\t"<<temp->City<<"\t"<<temp->Marks<<"\n";
                }
                temp = temp->next;
            }
        }

        //update student set City = "____" where Rno = ____;
        void UpdateCity(int no, string str)
        {
            node *temp = first;

            while(temp != NULL)
            {
                if(temp->Rno == no)
                {
                    temp->City = str;
                    break;
                }
                temp = temp->next;
            }

            cout<<"Record gets updated..."<<"\n";
        }

        //11 : delete from student where Rno = ___;
        void DeleteFrom(int no)
        {
            node *temp = first;
            node *target = NULL;

            // If LL is empty
            if(temp == NULL)
            {
                return;
            }

            // if first node is the targated node
            if(temp->Rno == no)
            {
                first = first->next;
                delete temp;
                return;
            }

            while(temp->next != NULL)
            {
                if(temp->next->Rno == no)
                {
                    target = temp->next;
                    temp->next = temp->next->next;
                    delete target;
                    break;
                }
                temp = temp->next;
            }
        }
};

int main()
{
    DBMS obj;

    obj.InsertIntoTable("Amit","Pune",89);
    obj.InsertIntoTable("Pooja","Mumbai",95);
    obj.InsertIntoTable("Gauri","Pune",90);
    obj.InsertIntoTable("Amit","Nagar",81);
    obj.InsertIntoTable("Rahul","Satara",80);
    obj.InsertIntoTable("Neha","Pune",78);

    obj.SelectStarFrom();

    obj.SelectStarFromWhereCity("Pune");

    obj.SelectCount();

    obj.SelectSum();

    obj.SelectAvg();

    obj.SelectMax();

    obj.SelectMin();

    obj.SelectStarFromName("Amit");

    obj.UpdateCity(3,"Nashik");

    obj.SelectStarFrom();

    obj.DeleteFrom(5);

    obj.SelectStarFrom();

    obj.InsertIntoTable("Rukmini","Kolhapur",77);

    obj.SelectStarFrom();

    return 0;
}

/*
Supported Queries

1 : insert into student values('Amit','Pune',78);
2 : select * from student;
3 : slect *  from student where City = '_____';
4 : select Count(Marks) from student;
5 : select Sum(Marks) from student;
6 : select Avg(Marks) from student;
7 : select Max(Marks) from student;
8 : select Min(Marks) from student;
9 : select * from student where name = "_____";
10 : update student set City = "____" where Rno = ____;
11 : delete from student where Rno = ___;

*/
