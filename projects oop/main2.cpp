#include <iostream>
#include <string>
// #include <conio.h>
#include <stdio.h>
#include <cstdio> 

using namespace std;

class Employee
{
protected:
    string name;
    int id;
    double salary;
    float NumberOfDaysAttendance;
    float  WorkingHoursMonth;
    int WorkingHoursDay;
    int WorkingHoursRate;
    float overtime_hours;
    int overtime;
public:
    Employee():name("unkwon"),id(0)
    {
    }
    Employee(string n,int id):name(n),id(id)
    {
    }
    virtual void informtion()
    {
        cout<<"name: "<< name<<"\t"<<"id: "<<id<<endl;
        cout<<"Number Of Days Attendance: "<<NumberOfDaysAttendance<<" day"<<endl;
        cout<<"over time hours: "<<overtime_hours<<" hours"<<endl;
        cout<<"salary: "<<salary<<" eg"<<endl;
    }
    double get_salary()
    {
        return salary;
    }
    float get_NumberOfDaysAttendance()
    {
        return NumberOfDaysAttendance;
    }
    void kwonNumberOfDaysAttendance()
    {
        if (1 <=id && id <= 30)
        {
           NumberOfDaysAttendance = id;
        }
        else if(31 <=id && id <= 900)
        {
           NumberOfDaysAttendance = id/30;
        }
    }
    ~Employee()
    {
    }
};


class Engineer:public Employee
{
private:
    string specialty;
    int Experience;
    string skils;
public:
    Engineer(string n,int id):Employee(n,id)
    {
    }
    void specialtyOfEngineer()
    {
        if (1 <=id && id <= 100)
        {
            specialty ="softwore Engineer";
        }
        else if (101 <=id && id <= 200)
        {
            specialty ="computer Engineer";
        }
        else if (201 <=id && id <= 300)
        {
            specialty ="communications Engineer";
        }
    }
    void informtion()
    {
       Employee::informtion();
       cout<<"specialty: "<<specialty<<endl;
    }
    double get_salary()
    {
        WorkingHoursDay = 8;
        WorkingHoursRate = 60;
        overtime_hours= id/WorkingHoursDay;
        overtime = WorkingHoursRate*3/2*overtime_hours;
        if (1 <=id && id <= 100)
        {
           Experience = 1;
        }
        else if (101 <=id && id <= 200)
        {
            Experience = 2;
        }
        else if (201 <=id && id <= 300)
        {
            Experience = 3;
        }
        salary = (NumberOfDaysAttendance*WorkingHoursDay*WorkingHoursRate*Experience)+overtime;
        if (WorkingHoursMonth>300)
            salary+=500;
        return salary;
    }
    friend class Manager;
    ~Engineer()
    {
    }
};


class Marketer:public Employee
{
private:
    float Goss_sales;
    float Commission_Rate;
public:
    void set_Goss_sales(float gs)
    {
        Goss_sales = gs;
    }
    void set_Commission_Rate(float cr)
    {
        Commission_Rate = cr;
    }
    Marketer():Employee("unknown",0)
    {
            Goss_sales = 0;
            Commission_Rate = 0;
    }
    Marketer(string n,int id):Employee(n,id)
    {
        
    }
    double get_salary()
    {
        WorkingHoursDay = 6;
        WorkingHoursRate = 30;
        overtime_hours= id/WorkingHoursRate;
        overtime = WorkingHoursRate*3/2*overtime_hours;
        salary = (NumberOfDaysAttendance*WorkingHoursDay*WorkingHoursRate)+overtime;
        if (WorkingHoursMonth>300)
            salary+=200;
        if (Goss_sales*Commission_Rate != 0)
            salary +=Goss_sales*Commission_Rate;
        return salary;
    }
    void informtion()
    {
       Employee::informtion();
       cout<<"specialty: Marketer"<<endl;
    }
    friend class Manager;
    ~Marketer()
    {

    }
};


class Factor:public Employee
{
private:
   
public:
    Factor(string n,int id):Employee(n,id)
    {
    }
    void informtion()
    {
       Employee::informtion();
    }
    double get_salary()
    {
        WorkingHoursDay = 12;
        WorkingHoursRate = 5;
        overtime_hours= id/WorkingHoursDay;
        overtime = WorkingHoursRate*3/2*overtime_hours;
        salary = (NumberOfDaysAttendance*WorkingHoursDay*WorkingHoursRate)+overtime;
        if (WorkingHoursMonth>480)
        {
            salary+=200;
        }
        
        return salary;
    }
    friend class Manager;
    ~Factor()
    {
}
};


class Manager
{
private:
   string name;
public:
    Manager():name("unkwon")
    {

    }
    Manager(string n):name(n)
    {

    }
    void set_id_emp_promotion(Engineer &En2)
    {
        cout<<"The employee has been promoted "<<En2.name<<endl;
        En2.salary += 1000;
        cout<<"and increase salary to "<<En2.salary<<endl;
    }
    void set_id_emp_promotion(Marketer &M2)
    {
        cout<<"The employee has been promoted "<<M2.name<<endl;
        M2.salary += 1000;
        cout<<"and increase salary to "<<M2.salary<<endl;
    }
    void set_id_emp_promotion(Factor &F2)
    {
        cout<<"The employee has been promoted "<<F2.name<<endl;
        F2.salary += 1000;
        cout<<"and increase salary to "<<F2.salary<<endl;
    }
    friend class Engineer;
    ~Manager()
    {

    }

};




int main(int argc, char const *argv[])
{
    string name_emp,name_manag;
    int id,password,ch;

   
   do 
   {
    cout<<"1) Employee"<<endl;
    cout<<"2) Manager"<<endl;
    cout<<"3) Exit"<<endl;
    cout<<"choice Employee : ";cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"Enter name for Employee: ";cin>>name_emp;
                cout<<"Enter id for Employee: ";cin>>id;
                Employee *Employee_ptr;
                if (1 <= id && id <= 300)
                {
                    Engineer En1(name_emp,id);
                    Employee_ptr = &En1;
                    En1.kwonNumberOfDaysAttendance();
                    En1.specialtyOfEngineer();
                    En1.get_salary();
                    Employee_ptr->informtion();
                }
                else if (301 <=id && id <= 400)
                {
                    Marketer M1(name_emp,id);
                    Employee_ptr = &M1;
                    M1.kwonNumberOfDaysAttendance();
                    M1.get_salary();
                    M1.set_Goss_sales(2);
                    M1.set_Commission_Rate(250);
                    Employee_ptr->informtion();
                }
                else if (401 <=id && id <= 900)
                {
                    Factor F1(name_emp,id);
                    Employee_ptr = &F1; 
                    F1.kwonNumberOfDaysAttendance();
                    F1.get_salary();
                    Employee_ptr->informtion();
                }
                else
                    cout<<"Error name and id incorrect"<<endl;
            break;
         }
         case 2:
         {
            char input1[1000];
            cout<<"Enter name for Manager: ";cin>>name_emp;
            Manager M1(name_manag);
            while(1)
                    {
                        char input[1000];
                        int i,totChar=0;
                        cout<<"enter your password: ";
                        gets(input);
                        for(i=0; input[i] != '\0'; i++){
                            if(input[i]!=' ')
                            {
                                totChar++;
                            }
                        }
                        if(totChar==11)
                        {
                            cout<<"password is True"<<endl;
                            break;
                        }
                    else if(totChar > 10)
                        {
                            cout<<"password must be less 11 number or letter,plese try agin"<<endl;
                            while(totChar!=11 && totChar > 11)
                            {
                                char input1[1000];
                                totChar=0;
                                cout<<"enter your password: ";
                                gets(input1);
                                for(int i=0; input1[i] != '\0'; i++)
                                    {
                                    if(input1[i]!=' ')
                                        totChar++;
                                    }
                            }
                        }
                        else
                        {
                            
                            while(totChar!=11&&  totChar < 11)
                            {
                                    cout<<"password too less,plase try agin"<<endl;
                                char input2[1000];
                                totChar=0;
                                cout<<"enter your password: ";
                                gets(input2);
                                for(int i=0; input2[i] != '\0'; i++)
                                    {
                                    if(input2[i]!=' ')
                                        totChar++;
                                    }
                            }
                        }
                        getch();
                        }

            string name_emp_promotion;
            int ch1,id_emp_promotion;
            
            do {
                cout<<"1) promotion Employee"<<endl;
                cout<<"2) Exit"<<endl;
                cout<<"Enter choice: ";
                cin>>ch1;
                switch(ch1) {
                    case 1: {
                        cout<<"Enter name of Employee: ";cin>>name_emp_promotion;
                        cout<<"Enter id of Employee: ";cin>>id_emp_promotion;
                        if (1 <=id_emp_promotion && id_emp_promotion <= 300)
                            {
                                Engineer En2(name_emp_promotion,id_emp_promotion);
                                M1.set_id_emp_promotion(En2);
                            }
                            else if (301 <=id_emp_promotion && id_emp_promotion <= 400)
                            {
                                Marketer M2(name_emp_promotion,id_emp_promotion);
                                M1.set_id_emp_promotion(M2);
                            }
                            else if (401 <=id_emp_promotion && id_emp_promotion <= 900)
                            {
                                Factor F2(name_emp_promotion,id_emp_promotion);
                                M1.set_id_emp_promotion(F2);
                            }
                            else 
                                cout<<"name or id not right..."<<endl;
                        cout<<"done!"<<endl;
                        cout<<"The employee has been upraded to next level and edit 1000eg to him salary"<<endl;
                        break;
                    }
                    case 2: {
                        cout<<"Exit"<<endl;
                        break;
                    }
                    default: {
                        cout<<"Invalid Choice"<<endl;
                    }
                }
            }
            while(ch1!=2);
            break;
         }
         case 3:
         {
            cout<<"The program Exit"<<endl;
            break;
         }
         default:
            cout<<"Invalid Choice"<<endl;
       }
    }
   while(ch!=3);  
        
    return 0;
}
