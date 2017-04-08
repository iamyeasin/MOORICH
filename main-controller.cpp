#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
#include<stdlib.h>

#define pf printf
#define sf scanf

using namespace std;

struct student
{
    char name[5000];
    char ID[5000];
    char grade[5000];
    char sec[5000];
    struct student *next;
};


struct employee // Could conflict.
{
    char name[5000];
    char ID[5000];
    char salary[5000];
//    char sec[5000];
    struct employee *next; // SELF REFERENTIAL POINTER
};


struct result // Result board is only available for students.
{
    char name[5000]; // IN CASE OF IMERGENCY
    char ID[5000];
    char grade[5000];

    struct result *next; // SELF REFERENTIAL POINTER

};

typedef struct result rb;
typedef struct student si;
typedef struct employee ei;

si *head = (si*)malloc(sizeof(si));
si *start = head;

ei *head2 = (ei*)malloc(sizeof(ei));
ei *start2 = head2;

rb *head3 = (rb*)malloc(sizeof(rb));
rb *start3 = head3;



/**** ************************ STARTING CRUD AREA ******************** ****/
/**** ************************ CREATE READ/PRINT UPDATE DELETE ******************** ****/

///Result board AREA
void createResultBoard()
{
    int how;
    pf("\nHow many students results are there? :  ");
    sf("%d",&how);

    pf("\n\nJust put the ID && Results : \n\n");
    for(int i=0; i<how; i++)
    {
        pf("\nID: ");
        sf(" %[^\n]",&head3->ID);
        pf("Grade: ");
        sf(" %[^\n]",&head3->grade);

        head3->next = (rb*)malloc(sizeof(rb));
        if(head3->next == NULL)
        {
            pf("Sorry!Can't take,Memory Overloaded\n");
            return;
        }

        head3 = head3 ->next;
    }
    head3->next = NULL;
    pf("\n");

}

///READING RESULT BOARD
void printResultBoard()
{
    rb *st = start3;
    int sl=0;
    printf("Sl.\t\t\ID\t\t\t\t        Grade\n\n");

    if(st!= NULL)
    {
        while(st->next)
        {
            pf("%d\t\t",++sl);

            int sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->grade);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->grade[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

//        puts(st->ID);
//        puts(st->grade);
            st = st->next;
            pf("\n");
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n\n");
        }
    }

}




///Taking in EMPLOYEE informations
void takeInEmployee() //Will take input for Employee.
{
    pf("\n\nHow many person you want to input: ");
    int how;
    sf("%d",&how);
    getchar();

    for(int i=0; i<how; i++)
    {
        pf("\nEnter name for employee %d: ",i+1);
        gets(head2->name);
        pf("Enter ID for employee %d: ",i+1);
        gets(head2->ID);
        pf("Enter salary for employee %d: ",i+1);
        gets(head2->salary);

        head2->next = (ei*)malloc(sizeof(ei));
        if(head2->next == NULL)
        {
            pf("Sorry! Memory overloaded.\n");
            return;
        }
        head2 = head2->next;
    }
    head2->next = NULL;
    pf("\n");

}



///Taking in student section
void takeInStudents()
{

    pf("\nHow many student you want to input: ");
    int how;
    sf("%d",&how);
    getchar();

    for(int i=0; i<how; i++)
    {
        pf("\nEnter name for student %d: ",i+1);
        gets(head->name);
        pf("Enter ID for student %d: ",i+1);
        gets(head->ID);
        pf("Enter Section for student %d: ",i+1);
        gets(head->sec);

        head->next = (si*)malloc(sizeof(si));
        if(head->next == NULL)
        {
            pf("Sorry! Memory overloaded.\n");
            break;
            return;
        }
        head = head->next;
    }
    head->next = NULL;
    pf("\n");

}



/// Employee information output
void printEmployeeInfo()
{
    int sl=1;
    ei *st = start2;

    printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tSalary\t\t\n\n");

    while(st->next)
    {
        pf("%d\t\t",sl++);

        int sz = strlen(st->name);
        for(int i=0; i<sz; i++)
        {
            printf("%c",st->name[i]);
        }
//        printf("\t\t\t      ");

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->ID);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->ID[i]);
        }

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->salary);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->salary[i]);
        }
        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

//        puts(st->ID);
//        puts(st->grade);
        st = st->next;
        pf("\n");
        for(int i=0; i<112; i++)
        {
            pf("-");
        }
        pf("\n\n");
    }

}



///Student INFO OUT
void printStudentInfo()
{
    int sl=1;
    si *st = start;

    printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tSection\t\t\n\n");

    while(st->next)
    {
        pf("%d\t\t",sl++);

        int sz = strlen(st->name);
        for(int i=0; i<sz; i++)
        {
            printf("%c",st->name[i]);
        }
//        printf("\t\t\t      ");

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->ID);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->ID[i]);
        }

        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

        sz = strlen(st->sec);
        for(int i=0; i<sz; i++)
        {
            pf("%c",st->sec[i]);
        }
        for(int i=0; i<abs(40-sz); i++)
        {
            pf(" ");
        }

//        puts(st->ID);
//        puts(st->grade);
        st = st->next;
        pf("\n"); // Will print the line divider
        for(int i=0; i<111; i++)
        {
            pf("-");
        }
        pf("\n\n");
    }


}



/// WILL delete a node APC
void deleteStudentInfo(si *prev,si *cur)
{

    if(prev == NULL && cur == start) // means first node
    {
        si *temp = start;
        start = start->next;
//        cout << temp->name << endl;
//        cout << start->name << endl;
        free(temp); // RELASING the first node
    }
    else if(cur == NULL && prev != NULL) //Means LAST node
    {
        prev->next = NULL;
        free(cur);
    }
    else if(prev != NULL && cur != NULL) // MEANS one of the middle node.
    {
        prev->next = cur->next;
        free(cur);
    }
}




///Deleting EMPLOYEE INFO
void deleteEmployeeInfo(ei *prev,ei *cur)
{

    if(prev == NULL && cur == start2) // means first node
    {
        ei *temp = start2;
        start2 = start2->next;
//        cout << temp->name << endl;
//        cout << start->name << endl;
        free(temp); // RELASING the first node
    }
    else if(cur == NULL && prev != NULL) //Means LAST node
    {
        prev->next = NULL;
        free(cur);
    }
    else if(prev != NULL && cur != NULL) // MEANS one of the middle node.
    {
        prev->next = cur->next;
        free(cur);
    }


}


/// COVERUP STUDENT INFORMATION UPDATE SECTIION
void updateStudentInfo(si *cur)
{
    //recieve cur node add & scanf the newvalue
    if(cur != NULL)
    {
        char ID[5000];
        char sec[5000];
        char name[5000];
        pf("Enter the student name to update: ");
        sf(" %[^\n]",&name);
        strcpy(cur->name,name);

        pf("Enter ID to update: ");
        sf(" %[^\n]",&ID);
        strcpy(cur->ID,ID);

        pf("Enter the section to update: ");
        sf(" %[^\n]",&sec);
        strcpy(cur->sec,sec);

        pf("Your information is updated successfully.\n");
    }
    else if(cur == NULL)
    {
        pf("There is some problem with locating the address. Information Can't be updated.Catch it!"); // IN CASE APC faults
    }

}



/// COVERUP STUDENT INFORMATION UPDATE SECTIION
void updateEmployeeInfo(ei *cur)
{
    //recieve cur node add & scanf the newvalue
    if(cur != NULL)
    {
        char ID[5000];
        char salary[5000];
        char name[5000];
        pf("Enter the employee name to update: ");
        sf(" %[^\n]",&name);
        strcpy(cur->name,name);

        pf("Enter ID to update: ");
        sf(" %[^\n]",&ID);
        strcpy(cur->ID,ID);

        pf("Enter the Salary to update: ");
        sf(" %[^\n]",&salary);
        strcpy(cur->salary,salary);

        pf("Your information is updated successfully.\n");
    }
    else if(cur == NULL)
    {
        pf("There is some problem with locating the address. Information Can't be updated.Catch it!"); // IN CASE APC faults
    }

}


/**** ************************ENDING CRUD AREA ******************** ****/



/**** ************************STARTING SEARCH AREA ******************** ****/

/// Searching information by student
si* SearchByStudent(char *name,int ret) // Ret 2 returns prev add,1 ret cur add and 0 prints the info
{
    int len = strlen(name);
//    for(int i=0; i<len; i++) pf("%c",s[i]);
    int sl = 1,flag=0;
    si *st = start;

    if(ret == 2)
    {
        while(st->next->next)
        {
            if((((strcmp(st->next->name,name)) == 0) || ((strcmp(st->next->ID,name)) == 0 )))
            {
                return st;
            }
            st=st->next;
        }
        return NULL;
    }

    if(ret)printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tSection\t\t\n\n"); // Printing style is same

    while(st->next)
    {
        if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 1)
        {
            pf("%d\t\t",sl++);

            int sz = strlen(st->name);
            for(int i=0; i<sz; i++)
            {
                printf("%c",st->name[i]);
            }
//        printf("\t\t\t      ");

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");

            }

            sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->sec);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->sec[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

//        puts(st->ID);
//        puts(st->grade);
            st = st->next;
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n");
            flag = 1;
        }
        else if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 0)
        {
            flag = 1;
            return st;
        }

        st= st->next;
    }

    if(!flag)
    {
        pf("Sorry! No records Found\n");
        return NULL;
    }

}


///Search for EMPLOYEE -> TO AVOID CONFLICT




ei* SearchByEmployee(char *name,int ret) ///Ret 1 for printing the results , 2 for PREV, 0 for current add
{
    int len = strlen(name);
//    for(int i=0; i<len; i++) pf("%c",s[i]);
    int sl = 1,flag=0;
    ei *st = start2;

    if(ret == 2) // Will return PREV ADD,
    {
        while(st->next->next)
        {
            if((((strcmp(st->next->name,name)) == 0) || ((strcmp(st->next->ID,name)) == 0 )))
            {
                return st;
            }
            st=st->next;
        }
        return NULL;
    }

    if(ret)printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\Salary\t\t\n\n"); // Printing style is same

    while(st->next)
    {
        if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 1)
        {
            pf("%d\t\t",sl++);

            int sz = strlen(st->name);
            for(int i=0; i<sz; i++)
            {
                printf("%c",st->name[i]);
            }
//        printf("\t\t\t      ");

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");

            }

            sz = strlen(st->ID);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->ID[i]);
            }

            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

            sz = strlen(st->salary);
            for(int i=0; i<sz; i++)
            {
                pf("%c",st->salary[i]);
            }
            for(int i=0; i<abs(40-sz); i++)
            {
                pf(" ");
            }

//        puts(st->ID);
//        puts(st->grade);
            st = st->next;
            for(int i=0; i<112; i++)
            {
                pf("-");
            }
            pf("\n");
            flag = 1;
        }
        else if((((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0 ))&& ret == 0)
        {
            flag = 1;
            return st;
        }

        st= st->next;
    }

    if(!flag)
    {
        pf("Sorry! No records Found\n");
        return NULL;
    }

}

/**** ************************ ENDING SEARCH AREA ******************** ****/





/**** ************************STARTING MAIN CONTROLLER AREA ******************** ****/ /*USER WILL BE CONTROLLER*/

int main()
{
    pf("****************HI, I am CONTROLLER .Enter number to run operations.****************\n\n");
    pf("1.  Students\n");
    pf("2.  Employees\n");
    pf("3.  ResultBoard\n");
    pf("4.  Search\n");
    pf("5.  Output all data base.\n");
    pf("6.  User Manual\n");
    pf("0.  exit\n\n");

    pf("OPERATION: ");
    int cmd;

    while(sf("%d",&cmd))
    {
        if(!cmd)
        {
            pf("Process Terminated\n");
            break;
        }

        /*JUMP:
        {
            scanf("%d",&cmd);
            if(!cmd)break;
        }*/

        puts("");

        if(cmd == 1)
        {
            printf("1. Add new student Information\n");
            pf("2. Delete student information\n");
            pf("3. View all students\n");
            pf("4. Update Student Infomrtion.\n");
            pf("5. Back\n\n");

            int cmds,x=0;
            while(scanf("%d",&cmds))
            {
                if(cmds == 1)
                {
                    /*Create a new node for student and store information in it*/
                    //. rest of the statement
                    takeInStudents();
                }
                else if(cmds == 2)
                {
                    /*First search the node. then use delete function*/
                    //GLB
                    pf("Want to delete student? let's find out\nEnter the name or ID:  ");
                    char s[5000];

                    sf(" %[^\n]",&s);
                    si *DEL = SearchByStudent(s,0);
                    if(DEL == NULL)
                    {
                        pf("Run another Operation\n");
                        continue;
                    }


                    pf("\n%s %s %s\n",DEL->name,DEL->ID,DEL->sec);

                    pf("\nIs this is the person you want to delete? \n1. Yes\n2. No\n\n");
                    int n;
                    sf("%d",&n);


                    if(n==1)
                    {
                        si *c = SearchByStudent(s,2); // FIX HERE
                        deleteStudentInfo(c,DEL);

                    }
                    else if(n=2)
                    {
                        continue;
                    }

                }
                else if(cmds == 3)
                {
                    //First search the node. then use delete function
                    //break;
                    printStudentInfo();
                    x=1;
                }
                else if(cmds == 4)
                {
                    //call upadate funct && search the current node
                    // as a parameter to the updateStudentInfo func  send the searched current value.
                    char sarc[5000];

                    pf("To update Student information, First you've to find out the desired information: ");
                    pf("\nEnter Name or ID : ");
                    sf(" %[^\n]",&sarc);

                    si *cur =  SearchByStudent(sarc,0); // 0 returns the current value
                    if(cur == NULL)
                    {
                        pf("No NODE FOUND!");
                        continue;
                    }

                    pf("%s %s %s\n",cur->name,cur->ID,cur->sec);


                    pf("\n\nIs it the information you want to update?\n1. Yes\n2. No\n");
                    int n;
                    scanf("%d",&n);

                    if(n==1)
                    {
                        updateStudentInfo(cur);
                    }
                    else
                    {
                        pf("Please try another operation.\n\n");
                        continue;
                    }
                }
                else if(cmds == 5)
                {
                    //Go back to the menu
                    // goto JUMP;
                    printf("Make another operation: \n");
                    break;
                }
                else
                {
                    printf("Sorry! not recognizable. Try again.\n");
                }

                if(!x)
                {
                    pf("\n");
                    printf("1. Add new student Information\n");
                    pf("2. Delete student information\n");
                    pf("3. View all students\n");
                    pf("4. Update Student Infomrtion.\n");
                    pf("5. Back\n\n");
                }

                x =0;
            }


        }

        else if(cmd == 2)
        {
            printf("1. Add new Employee Information\n");
            pf("2. Delete Employee information\n");
            pf("3. View all Employee\n");
            pf("4. Update Employee Information\n" );
            pf("5. Back\n");

            int cmds,x=0;
            while(sf("%d",&cmds))
            {
                if(cmds == 1)
                {
                    /*Create a new node for student and store information in it*/
                    //. rest of the statement
                    takeInEmployee();
                }
                else if(cmds == 2)
                {
                    //First search the node. then use delete function
                    //GLB

                    pf("Want to delete Employee information? let's find out\nEnter the name or ID:  ");
                    char s[5000];

                    sf(" %[^\n]",&s);
                    ei *DEL = SearchByEmployee(s,0);
                    if(DEL == NULL)
                    {
                        pf("Run another Operation\n");
                        continue;
                    }
                    pf("\n%s %s %s\n",DEL->name,DEL->ID,DEL->salary);

                    pf("\nIs this is the information you want to delete? \n1. Yes\n2. No\n\n");
                    int n;
                    sf("%d",&n);


                    if(n==1)
                    {
                        ei *c = SearchByEmployee(s,2);
                        deleteEmployeeInfo(c,DEL);
                    }
                    else if(n=2)
                    {
                        pf("\nPlease try again!\n");
                        continue;
                    }

                    if(!x)
                    {
                        printf("1. Add new Employee Information\n");
                        pf("2. Delete Employee information\n");
                        pf("3. View all Employee\n");
                        pf("4. Update Employee Information.\n");
                        pf("5. Back\n");
                    }



                }
                else if(cmds == 3)
                {
                    //Use printEmployeeInfo function to view
                    printEmployeeInfo();
                    x=1;
                }
                else if(cmds == 4)
                {
                    //call upadate funct && search the current node
                    // as a parameter to the updateEmployeeInfo func  send the searched current value.
                    char sarc[5000];

                    pf("To update Employee information, First you've to find out the desired information: ");
                    pf("\nEnter Name or ID : ");
                    sf(" %[^\n]",&sarc);

                    ei *cur =  SearchByEmployee(sarc,0); // 0 returns the current value
                    if(cur == NULL)
                    {
                        pf("No NODE FOUND!");
                        continue;
                    }


                    //NEED A FIX here. When name will be more than one word.
                    pf("%s %s %s\n",cur->name,cur->ID,cur->salary);


                    pf("\n\nIs it the information you want to update?\n1. Yes\n2. No\n");
                    int n;
                    scanf("%d",&n);

                    if(n==1)
                    {
                        //calling the function
                        updateEmployeeInfo(cur);
                    }
                    else
                    {
                        pf("Please try another operation.\n\n");
                        continue;
                    }


                }
                else if(cmds == 5)
                {
                    //Go back to the menu
                    // goto JUMP;
                    printf("Make another operation: \n");
                    break;
                }
                else
                {
                    printf("Sorry! not recognizable. Try again.\n");
                }

                pf("\n");
                printf("1. Add new Employee Information\n");
                pf("2. Delete Employee information\n");
                pf("3. View all Employee\n");
                pf("4. Update Employee Infomrtion.\n");
                pf("5. Back\n");

            }

        }
        else if(cmd == 3)
        {
            /*Use Result function*/


            //Result board 1 for creating a result list.
            //Clearing the result board for 3
            //printing the result board for 2

            pf("1. Creating A result list\n");
            pf("2. Printing the recent result list\n");
            pf("3. Clearing the previous result list\n");
            pf("4. back\n");

            int x,ff=0;
            while(sf("%d",&x))
            {
                ff = 1; // FLAGING THE SUBMENU PRINTS
                if(x==1)
                {
                    createResultBoard();
                }
                else if(x == 2)
                {
                    printResultBoard();
                }
                else if(x == 3)
                {
                    start3 = head3;
                    pf("Result Board Cleared Successfully.\n");
                }
                else if(x == 4)
                {
                    break;
                }

                if(ff)
                {
                    pf("1. Creating A result list\n");
                    pf("2. Printing the recent result list\n");
                    pf("3. Clearing the previous result list\n");
                    pf("4. back\n");
                }
            }

        }
        else if(cmd == 4)
        {
            /*Search by name*/
            pf("1. Search by name\n");
            pf("2. Search by ID\n");
            pf("3. Back");

            int src,ff=0;
            while(sf("%d",&src))
            {
                ff=1; // Flagging the source
                if(src == 1)
                {
                    /*Use search function send parameter 1*/
                    char searchName[256];

                    pf("Enter name: ");
                    scanf("\n"); // Will eat the garbage newline pressed by enter
                    gets(searchName);
                    SearchByStudent(searchName,1); // Will show the matching list
                    pf("Want to make another Operation?\n");

                }
                else if(src == 2)
                {
                    //send parameter.

                    char searchID[256];
                    pf("Enter ID: ");
                    sf("\n");
                    gets(searchID); // ID is string too... I can send ID . It'll show the same list
                    SearchByStudent(searchID,1);
                    pf("Want to make another Operation?\n");

                }
                else if(src == 3)
                {
                    break;
                }

                if(ff)
                {
                    pf("1. Search by name\n");
                    pf("2. Search by ID\n");
                    pf("3. Back");
                }
            }

        }

        else if(cmd == 5)
        {
            /*Show allView function*/
            pf("All available Students DATABASES: \n");
            printStudentInfo();
            pf("\n\n");
            pf("All available Employee DATABASES: \n");
            printEmployeeInfo();
        }
        else if(cmd == 6)
        {
            pf("Welcome to the user manual. Every time the menu appears to the Screen just put the serial number\n");
            pf("to execute the operation.Simply Do as the command line tells you to do based on your operation it will\n");
            pf("make you feel comfortable to use this. Thank you\n");
        }
        else if(cmd == 0)
            break;
        else
        {
            pf("Sorry! Not recognizable.Try again");
        }

        puts("");
        pf("1.  Students\n");
        pf("2.  Employees\n");
        pf("3.  Result Board\n");
        pf("4.  Search\n");
        pf("5.  Output all data base.\n");
        pf("6.  User Manual\n");
        pf("0.  exit\n\n");
        pf("Operation: ");


    }


    return 0;
}
