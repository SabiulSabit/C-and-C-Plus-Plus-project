#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[30];
    int cls;
    char number[12];
    double ban,eng,math;
};

struct student data[500];
int total = 0;

//Student Work Start
void showStudentProfile()
{
    printf("\nEnter Your Student ID: ");
    int id,i;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {
            printf("\n----Basic Info----\n");
            printf("\nID: %d",data[i].id);
            printf("\nName: %s",data[i].name);
            printf("\nClass: %d",data[i].cls);
            printf("\nPhone Number: %s",data[i].number);

            printf("\n----Marks----\n");
            if(data[i].ban>0  && data[i].ban <=100)
            {
                printf("\nMarks in Bangla: %lf",data[i].ban);
                printf("\nMarks in English: %lf",data[i].eng);
                printf("\nMarks in Math: %lf",data[i].math);
            }
            else
            {
                printf("\nResult Not Published Yet!!\n");
            }
            return;
        }
    }

    printf("\nNo Id Found !!! \n");
}

void showMark(){


    printf("\nEnter Student ID: ");
    int id,i;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {

            printf("\n----Marks----\n");
            if(data[i].ban>0  && data[i].ban <=100)
            {
                printf("\nMarks in Bangla: %lf",data[i].ban);
                printf("\nMarks in English: %lf",data[i].eng);
                printf("\nMarks in Math: %lf",data[i].math);
            }
            else
            {
                printf("\nResult Not Published Yet!!\n");
            }
            return;
        }
    }
    printf("\nNo Id Found !!! \n");
}
void studentMenu()
{

    printf("Press 1 Find Your Info\n");
    printf("Press 2 for show Mark sheet\n");
    int op;
    scanf("%d",&op);

    if(op==1)
    {
        showStudentProfile();
    }
    else if(op==2)
    {
        showMark();
    }

}

//Student Work End


// Teacher Work Start

void addStudent()
{

    struct student temp;

    printf("Enter Student Id: ");
    scanf("%d",&temp.id);
    printf("Enter Student Name: ");
    scanf("%s",&temp.name);
    printf("Enter Student Class: ");
    scanf("%d",&temp.cls);
    printf("Enter Student Phone Number: ");
    scanf("%s",&temp.number);

    data[total] = temp;
    total++;
    printf("\nData Insert Successfully!!!\n");
}

void viewAll()
{

    printf("\nAll Student Info: \n");
    int i;
    for(i=0; i<total; i++)
    {
        printf("ID: %d  Name: %s \n",data[i].id,data[i].name);
    }
}

void addMarks()
{

    printf("\nEnter The Student Id whoes marks you want to add: ");
    int id,i;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {

            printf("\nEnter Marks for Bangla: ");
            scanf("%lf",&data[i].ban);
            printf("\nEnter Marks for English: ");
            scanf("%lf",&data[i].eng);
            printf("\nEnter Marks for Math: ");
            scanf("%lf",&data[i].math);
            printf("\nData Insert Successfully!!!\n");
            return;
        }
    }

    printf("\nNo Id Found !!! \n");
}

void findStudent()
{

    printf("\nEnter The Student Id you want to  view: ");
    int id,i;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {
            printf("\n----Basic Info----\n");
            printf("\nID: %d",data[i].id);
            printf("\nName: %s",data[i].name);
            printf("\nClass: %d",data[i].cls);
            printf("\nPhone Number: %s",data[i].number);

            printf("\n----Marks----\n");
            printf("\nMarks in Bangla: %lf",data[i].ban);
            printf("\nMarks in English: %lf",data[i].eng);
            printf("\nMarks in Math: %lf",data[i].math);

            return;
        }
    }

    printf("\nNo Id Found !!! \n");
}
void teacherMenu()
{
    printf("Press 1 for Add Student\n");
    printf("Press 2 for View All Student\n");
    printf("Press 3 for Add Marks for a Student\n");
    printf("Press 4 for find a Student\n");
    int op;
    scanf("%d",&op);

    if(op==1)
    {
        addStudent();
    }
    else if(op==2)
    {
        viewAll();
    }
    else if(op==3)
    {
        addMarks();
    }
    else if(op==4)
    {
        findStudent();
    }

}

// Teacher Work End

//Parents Work Start
void showChildInfo(){
    printf("\nEnter Your Child ID: ");
    int id,i;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {
            printf("\n----Basic Info----\n");
            printf("\nID: %d",data[i].id);
            printf("\nName: %s",data[i].name);
            printf("\nClass: %d",data[i].cls);
            printf("\nPhone Number: %s",data[i].number);

            printf("\n----Marks----\n");
            printf("\nMarks in Bangla: %lf",data[i].ban);
            printf("\nMarks in English: %lf",data[i].eng);
            printf("\nMarks in Math: %lf",data[i].math);

            return;
        }
    }

    printf("\nNo Id Found !!! \n");

}
void compareMarks(){

    printf("\nEnter Your Child ID: ");
    int id,i,a;
    scanf("%d",&id);

    for(i=0; i<total; i++)
    {
        if(id == data[i].id)
        {
            a = data[i].cls;
            printf("\n----Your Child----\n");
            printf("\n----Basic Info----\n");
            printf("\nID: %d",data[i].id);
            printf("\nName: %s",data[i].name);
            printf("\nClass: %d",data[i].cls);
            printf("\nPhone Number: %s",data[i].number);

            printf("\n----Marks----\n");
            printf("\nMarks in Bangla: %lf",data[i].ban);
            printf("\nMarks in English: %lf",data[i].eng);
            printf("\nMarks in Math: %lf",data[i].math);

            //return;
        }
    }

    for(i=0; i<total; i++)
    {
        if(id != data[i].id && a == data[i].cls);
        {
            printf("\n----Your Child Class Mates----\n");
            printf("\n----Basic Info----\n");
            printf("\nID: %d",data[i].id);
            printf("\nName: %s",data[i].name);
            printf("\nClass: %d",data[i].cls);
            printf("\nPhone Number: %s",data[i].number);

            printf("\n----Marks----\n");
            printf("\nMarks in Bangla: %lf",data[i].ban);
            printf("\nMarks in English: %lf",data[i].eng);
            printf("\nMarks in Math: %lf",data[i].math);

          //  return;
        }
    }

    //printf("\nNo Id Found !!! \n");

}
void parentsMenu()
{
    printf("\nPress 1 for View Your Child All Information");
    printf("\nPress 2 for View Your Child Class Mate Marks");
    int op;
    scanf("%d",&op);

    if(op==1)
    {
      showChildInfo();
    }
    else if(op==2){
        compareMarks();
    }
}
//Parents Work End

void actor()
{

    printf("\nPress 1 for use as Student");
    printf("\nPress 2 for use as Teacher");
    printf("\nPress 3 for use as Parents");

    int op;
    printf("\nEnter Actor Type: ");
    scanf("%d",&op);

    if(op==1)
    {
        studentMenu();
    }
    else if(op==2)
    {
        teacherMenu();
    }
    else if(op==3)
    {
       parentsMenu();
    }
    else
    {
        printf("Wrong Input");
    }
}

int main()
{

    while(1)
    {
        actor();
    }
    return 0;
}
