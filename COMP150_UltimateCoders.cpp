#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<iomanip>
#include<fstream>                                                  //include directive
#define max 20
using namespace std;

class employee{
    public:
        char empname[40];
        char empcode[5];
        char designation[20];
        int age;
        int experience;
        char emp[max],tempemp[max],sortemp[max],sortemp1[max];
           //The following varaibles are subparts of employee variable
           employee()
           {
strcpy(empname,"no emp");
           }
           void exit();
           void build();
           void view();
           void show();
           void edit();
           void add();
           void sort();
           void deletee();
           void options();
           };

void employee::exit(){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
options();
        }
void employee::build()
{
    system("cls");
    int ch;
    cout<<"enter 1 for name,emp id,designation"<<"\n";
       cout<<"enter 2 for name,emp id"<<"\n";
       cout<<"enter 3 for name,emp id,experience"<<"\n";
       cout<<"enter 4 for name,emp id,age"<<"\n";
        cout<<"enter 5 for all"<<"\n";
        cin>>ch;
        system("cls");
            FILE *file;
            file= fopen("empdata.txt", "r");

        switch(ch){
        case 1:
            cout<<"\n\t **************Table*************\n";
            cout<<"\n----------------------------------------------------------------------------";
            cout<<"\n     NAME                CODE               DESIGNATION    \n";

            cout<<"----------------------------------------------------------------------------"<<endl;
              while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                     {
                   cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode<<"\t\t"<<setw(15)<<designation;
                     }
                   break;
                   case 2:
                        cout<<"\n\t **************Table*************\n";
            cout<<"\n-----------------------------------------";
            cout<<"\n NAME                   CODE           \n";
            cout<<"-----------------------------------------"<<endl;
              while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                     {
                        cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode;
                     }
                        break;
                        case 3:
                              cout<<"\n\t **************Table*************\n";
            cout<<"\n----------------------------------------------------------------------";
            cout<<"\n NAME                  CODE                       EXPERIENCE(YEARS)   \n";
            cout<<"----------------------------------------------------------------------"<<endl;
              while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                     {
                             cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode<<"\t\t"<<setw(15)<<experience;
                     }
                             break;
                        case 4:

                     cout<<"\n\t **************Table*************\n";
            cout<<"\n------------------------------------------------------------------------";
            cout<<"\n NAME                  CODE                         Age    \n";
            cout<<"------------------------------------------------------------------------"<<endl;
              while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
              {
                             cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode<<"\t\t"<<setw(15)<<age;
                     }
                             break;
                        case 5:
                            cout<<"\n\t **************Table*************\n";
            cout<<"\n-------------------------------------------------------------------------------------------------------------------";
            cout<<"\n NAME                   CODE              DESIGNATION                  EXPERIENCE(YEARS)                 AGE\n";
            cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
              while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                     {
                             cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode<<"\t\t"<<setw(15)<<designation<<"\t\t"<<setw(15)<<experience<<"\t\t"<<setw(15)<<age;
                     }
                             break;
                        default:
                            exit();
                            break;
        }fclose(file);
        exit();
}
        void employee:: view()
        {
            system("cls");
            FILE *file;
            file= fopen("empdata.txt","r");
            cout<<"\n\t **************Table*************\n";
            cout<<"\n-----------------------------------------------------------------------------------------------------------------";
            cout<<"\n NAME                    CODE             DESIGNATION                  EXPERIENCE(YEARS)                AGE\n";

            cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
            while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)

                cout<<"\n"<<left<<setw(15)<<empname<<"\t\t"<<setw(15)<<empcode<<"\t\t"<<setw(15)<<designation<<"\t\t"<<setw(15)<<experience<<"\t\t"<<setw(15)<<age; //%S MEANS A STRING ARGUMENT AND %D INT ARGMENT
            fclose(file);
            exit();
        }

void employee::sort()
{
    system("cls");
    ifstream inflow;
    inflow.open("empdata.txt");
    int num = 0;
    string by_Line;
    while(getline(inflow, by_Line))
    {
        num++;
    }
    inflow.close();
    ifstream inflow2;
    inflow2.open("empdata.txt");
    string arr[num];
        for(int i = 0; i<num; i++)
        {
            getline(inflow2,by_Line);
            arr[i] = by_Line;
        }
        int i, j;
        string lock;
        for(i=1;i<num;i++)
        {
            lock = arr[i];
            j = i - 1;
            while(j>=0&&arr[j]>lock)
            {
                arr[j+1] = arr[j];
                j=j-1;
            }
            arr[j+1] = lock;
        }

    ofstream offflow;
    offflow.open("empdata2.txt", ofstream::out);

    for(int k = 0; k < num; k++)
    {
        offflow << arr[k] <<endl;
    }

    offflow.close();
    inflow2.close();

    remove("empdata.txt");

    rename("empdata2.txt", "empdata.txt");

cout<<"Data sorted successfully";
exit();

}
        void employee:: show(){ //Displays all details according to Employee's id
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("empdata.txt", "r");
           while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                if(strcmp(checkId,empcode)==0){
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<empname;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<empcode;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge(YEARS): "<<age;
                    cout<<"\n---------------------";

                    cout<<"\nExperience(YEARS): "<<experience;
                    cout<<"\n---------------------";
                }
            fclose(file);
            exit();
        }

      void employee::edit(){ //edits the details of employee
            system("cls");
            char checkId[5];
            cout<<"\nEnter employee ID: ";
            cin>>checkId;
            char newDesignation[10];
            char newname[20];
            int newexperience;
            cout<<"\n----------------------------";
            cout<<"\nEnter new FullName(without space): ";
            cin>>newname;
            int newAge;
            cout<<"------------------------------";
            cout<<"\nEnter new age(YEARS): ";
            cin>>newAge;
             cout<<"----------------------------";
            cout<<"\nEnter new experience(YEARS): ";
            cin>>newexperience;
             cout<<"----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            FILE *file, *tempfile;
            file= fopen("empdata.txt", "r");
            tempfile= fopen("temp.txt", "w");
           while(fscanf(file, "%s %s %s %d %d %d", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                if(strcmp(checkId, empcode)==0)
                    fprintf(tempfile, "%s %s %s %d %d  \n", newname, empcode, newDesignation, newAge,  newexperience );
                else
                    fprintf(tempfile, "%s %s %s %d %d  \n", empname, empcode, designation, age,  experience );
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("empdata.txt");
            int isRenamed= rename("temp.txt", "empdata.txt");
            cout<<"updated";
           exit();
        }

        void employee::add(){ //adding records
            system("cls");
            cout<<"\n Enter FullName of Employee[without space]: ";
            cin>>empname;
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>empcode;
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n Enter Employee Age(YEARS): ";
            cin>>age;
            cout<<"\n Enter Employee Experience(YEARS): ";
            cin>>experience;
            fflush(stdin);
                FILE  *file;
                file= fopen("empdata.txt","a");
                fprintf(file, "%s %s %s %d %d \n", empname, empcode, designation, age, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";

            exit();
        }

        void employee:: deletee(){ //removing records
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("empdata.txt", "r");
                tempfile= fopen("temp.txt", "w");
         while(fscanf(file, "%s %s %s %d %d ", &empname[0], &empcode[0] , &designation[0], &age,  &experience)!= EOF)
                    if(strcmp(checkId, empcode)!=0)
                        fprintf(tempfile, "%s %s %s %d %d  \n", empname, empcode, designation, age, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("empdata.txt");
                int isRenamed= rename("temp.txt", "empdata.txt");
                cout<<"\nRemoved Successfully\n";
                exit();
            }
            else
                deletee();
        }
    void employee::options(){ //menu
  system("cls");
   cout<<"          ";
   cout<<"\n*****  Employees Management System ***** ";
   cout<<"\n         *****  Main Menu ***** ";
   cout<<endl;                                       //Main Menu
   cout<<"             ";
   cout<<"\n\t\t Press  1---->Built The Employee Table ";
   cout<<"\n\t\t Press  2---->List The Employee Table  ";
   cout<<"\n\t\t Press  3---->Insert New Entry        ";
   cout<<"\n\t\t Press  4---->Delete An Entry         ";
   cout<<"\n\t\t Press  5---->Edit An Entry           ";
   cout<<"\n\t\t Press  6---->Search a record          ";
   cout<<"\n\t\t Press  7---->Sort record          ";
   cout<<"\n\t\t Press  8---------->Quit Program              ";
   cout<<"             ";
   cout<<"\n\n \t\t Select Your Option Please ====> ";
                int choice;
                cin>>choice;

                switch (choice)
                {
                    case 1:
                        build();
                        break;
                    case 2:
                        view();
                        break;
                    case 3:
                        add();
                        break;
                    case 4:
                        deletee();
                        break;
                    case 5:
                        edit();
                        break;
                    case 6:
                      show();
                        break;
                    case 7:
                        sort();
                        break;
                    default:
                        exit();
                        break;
             }  }



int main(){
    // Call the options function
    employee e;
    e.options();
    return 0;
}


/*<<<<<<<<<<<<<<<<< Drive Data >>>>>>>>>>>>>>>>>

>>Press 1 to Built The Employee Table
Now select the option out of 1,2,3,4 or 5 according to your intrest of how you want the table to be arranged

>>Press 2 to List The Employee Table

                        <<<<<Testing data 1:>>>>>
>>Press 3 to Insert New Entry
    FullName: SteveJobs
    Employee ID: 3301
    Designation: Technician
    Employee Age: 45
    Employee Experience: 15

>>Press 4 to Delete An Entry
    Enter Employee Id To Remove: 3301
Press y(lowercase) to confirm removing. <<Input 'y'>>
Else Enter anything except y(lowercase)

>>Press 5 to Edit An Entry
    Enter employee ID: 3301
    Enter new FullName(without space): SteveLewis
    Enter new age: 42
    Enter new experience: 12
    Enter new designation: Chairman

>>Press 6 to Search a record
Enter Employee ID: 3301 (kindly note that this record would not be found because it is already deleted in the Delete An Entry section.)
>>press 7 to do sorting
>>press 8 to quit program

                            <<<<<Testing data 2:>>>>>
>>Press 3 to Insert New Entry
    FullName: BarryLewis
    Employee ID: 3266
    Designation: Chairman
    Employee Age: 35
    Employee Experience: 10

>>Press 4 to Delete An Entry
    Enter Employee Id To Remove: 3266
Press y(lowercase) to confirm removing. <<Input 'y'>>
Else Enter anything except y(lowercase)

>>Press 5 to Edit An Entry
    Enter employee ID: 3266
    Enter new FullName(without space): BarryJobs
    Enter new age: 50
    Enter new experience: 19
    Enter new designation: President

>>Press 6 to Search a record
Enter Employee ID: 3266 (kindly note that this record would not be found because it is already deleted in the Delete An Entry section.)
>>press 7 to do sorting
>>press 8 to quit program

                            <<<<<Testing data 3:>>>>>
>>Press 3 to Insert New Entry
    FullName: LunaAdams
    Employee ID: 3299
    Designation: President
    Employee Age: 50
    Employee Experience: 21

>>Press 4 to Delete An Entry
    Enter Employee Id To Remove: 3299
Press y(lowercase) to confirm removing. <<Input 'y'>>
Else Enter anything except y(lowercase)

>>Press 5 to Edit An Entry
    Enter employee ID: 3299
    Enter new FullName(without space): LunaJames
    Enter new age: 35
    Enter new experience: 10
    Enter new designation: Technician

>>Press 6 to Search a record
Enter Employee ID: 3299 (kindly note that this record would not be found because it is already deleted in the Delete An Entry section.)

>>press 7 to do sorting
>>press 8 to quit program
*/