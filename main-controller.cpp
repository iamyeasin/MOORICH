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


typedef struct student si;

si *head = (si*)malloc(sizeof(si));
si *start = head;


void takeIn()
{
    pf("How many person you want to input: ");
    int how;
    sf("%d",&how);
    getchar();

    for(int i=0; i<how; i++)
    {
        pf("Enter name: ");
        gets(head->name);
        pf("Enter ID: ");
        gets(head->ID);
        pf("Enter Section: ");
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

}


void printStudentInfo()
{
    int sl=1;
    si *st = start;
    printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tGrade\t\t\n\n");

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
        for(int i=0; i<112; i++)
        {
            pf("-");
        }
        pf("\n");
    }

}



void SearchBy(char *name)
{
    int len = strlen(name);
//    for(int i=0; i<len; i++) pf("%c",s[i]);
    int sl = 1,flag=0;
    si *st = start;
    printf("Sl.\t\tName\t\t\t\t        ID\t\t        \t\tGrade\t\t\n\n"); // Printing style is same

    while(st->next)
    {
        if(((strcmp(st->name,name)) == 0) || ((strcmp(st->ID,name)) == 0))
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
    }

    if(!flag)pf("Sorry! No records Found\n");

}



int main()
{
    pf("****************HI, I am CONTROLLER .Enter number to run operations.****************\n\n");
    pf("1.  Students\n");
    pf("2.  Employees\n");
    pf("3.  Results\n");
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
            pf("4. Back\n");

            int cmds;
            while(scanf("%d",&cmds))
            {
                if(cmds == 1)
                {
                    /*Create a new node for student and store information in it*/
                    //. rest of the statement
                    takeIn();
                }
                else if(cmds == 2)
                {
                    /*use view function to view student data*/
                    //GLB

                }
                else if(cmds == 3)
                {
                    //First search the node. then use delete function
                    //break;
                    printStudentInfo();
                }
                else if(cmds == 4)
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
            }

        }

        else if(cmd == 2)
        {
            printf("1. Add new Employee Information\n");
            pf("2. Delete Employee information\n");
            pf("3. View all Employees\n");
            pf("4. Back\n");

            int cmds;
            sf("%d",&cmds);

            if(cmds == 1)
            {
                /*Create a new node for student and store information in it*/
                //. rest of the statement
                takeIn();
            }
            else if(cmds == 2)
            {
                /*use view function to view student data*/
                //GLB

            }
            else if(cmds == 3)
            {
                //First search the node. then use delete function
                printStudentInfo();
            }
            else if(cmds == 4)
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

        }
        else if(cmd == 3)
        {
            /*Use viewAll function*/

            break;
        }
        else if(cmd == 4)
        {
            /*Search by name*/
            pf("1. Search by name\n");
            pf("2. Search by ID\n");

            int src;
            sf("%d",&src);

            if(src == 1)
            {
                /*Use search function send parameter 1*/
                char searchName[256];

                pf("Enter name: ");
                scanf("\n"); // Will eat the garbage newline pressed by enter
                gets(searchName);
                SearchBy(searchName); // Will show the matching list
                pf("Want to make another Operation?\n");

            }
            else if(src == 2)
            {
                //send parameter.

                char searchID[256];
                pf("Enter ID: ");
                sf("\n");
                gets(searchID); // ID is string too... I can send ID . It'll show the same list
                SearchBy(searchID);
                pf("Want to make another Operation?\n");

            }

        }

        else if(cmd == 5)
        {
            /*Show allView function*/
            printStudentInfo();
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
        pf("3.  Results\n");
        pf("4.  Search\n");
        pf("5.  Output all data base.\n");
        pf("6.  User Manual\n");
        pf("0.  exit\n\n");
        pf("Operation: ");


    }


    return 0;
}