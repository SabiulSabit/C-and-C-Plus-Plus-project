#include<stdio.h>

struct Joining_Date
{
    int day,month,year;
};

struct Employee
{
    int id;
    char name[30];
    char designation[20];
    float salary;
    char number[12];
    struct Joining_Date jd;
};

struct Employee data[500];

int count=0;

int compare(char str1[], char str2[]);

int menu()
{
    printf("\nWhat you want to do????\n");
    printf("\nEnter 1 to Add new employee\nEnter 2 to Search an employee by id \nEnter 3 to Update employee info\nEnter 4 to Delete employee\nEnter 5 to Display average salary\nEnter 6 to Search employee ids after a given joining date\nEnter 7 to Search employee ids having maximum salary\nEnter 8 to Search total no of employees by designation\nEnter 9 to Search employee ids having the given name\nEnter -1 to exit\n\n");
    int ch;
    printf("\nPlease Enter Your choice:");
    scanf("%d",&ch);
    printf("\n");
    return ch;
}

void  add_employee()
{
    struct Employee temp;
    printf("Enter Employee id :\n");
    scanf("%d",&temp.id);
    // check id
    int i;
    int f=0;
    for(i=0; i<count; i++)
    {
        if(data[i].id==temp.id)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("ID duplicate found.\n\n");
        return;
    }

    printf("Enter Employee name:\n");
    scanf("%s",&temp.name);
    printf("Enter Designation/Rank:\n");
    scanf("%s",&temp.designation);
    printf("Enter Salary:\n");
    scanf("%f",&temp.salary);
    printf("Enter Phone no:\n");
    scanf("%s",&temp.number);
    // check number
    f=0;
    for(i=0; i<count; i++)
    {
        if(compare(temp.number,data[i].number)==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("Phone no duplicate found.\n");
        return;
    }
    ///////
    printf("Enter Joining Date(dd-mm-yyyy):\n");
    scanf("%d-%d-%d",&temp.jd.day,&temp.jd.month,&temp.jd.year);
    data[count]=temp;
    count++;
}

int search_id(int emp_id)
{
    int f=0,i,index;
    for(i=0; i<count; i++)
    {
        if(data[i].id==emp_id)
        {
            index=i;
            f=1;
            break;
        }
    }
    if(f==0)
    {
        printf("Not Found\n");
        return -1;
    }
    else
    {
        printf("Employee id : %d\nName : %s\nDesignation/Rank : %s\nSalary : %f\nPhone no : %s\nJoining date : %d/%d/%d\n",data[index].id,data[index].name,data[index].designation,data[index].salary,data[index].number,data[index].jd.day,data[index].jd.month,data[index].jd.year);
        return index;
    }
}

void update_info(int emp_id)
{
    if(search_id(emp_id)==-1)
    {
        printf("Not exists.\n");
    }
    else
    {
        int index=search_id(emp_id);
        struct Employee temp;
        printf("Enter Employee id :\n");
        scanf("%d",&temp.id);
        // check id
        int i;
        int f=0;
        for(i=0; i<count; i++)
        {
            if(i==index)
                continue;
            if(data[i].id==temp.id)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            printf("ID duplicate found.\n\n");
            return;
        }
        printf("Enter Employee name:\n");
        scanf("%s",&temp.name);
        printf("Enter Designation/Rank:\n");
        scanf("%s",&temp.designation);
        printf("Enter Salary:\n");
        scanf("%f",&temp.salary);
        printf("Enter Phone no:\n");
        scanf("%s",&temp.number);
        // check number
        f=0;
        for(i=0; i<count; i++)
        {
            if(i==index)
                continue;
            if(compare(temp.number,data[i].number)==0)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            printf("Phone no duplicate found.\n\n");
            return;
        }
        ///////
        printf("Enter Joining Date:\n");
        scanf("%d %d %d",&temp.jd.day,&temp.jd.month,&temp.jd.year);
        data[index]=temp;
        printf("Updated successfully.\n");
    }
}

void delete_employee(int emp_id)
{
    int index=search_id(emp_id),i;
    if(index!=-1)
    {
        for(i=index; i<count; i++)
        {
            data[i]=data[i+1];
        }
        count--;
    }
}

double display_avg_sal()
{
    float avg=0;
    int i;
    for(i=0; i<count; i++)
    {
        avg=avg+data[i].salary;
    }

    avg=(avg)/(float)count;
    double ans=avg;
    return ans;
}

void search_join_date(int day, int month, int year)
{
    int i;
    for(i=0; i<count; i++)
    {
        if(data[i].jd.year>year)
        {
            printf("Employee id : %d\n Name : %s\nDesignation/Rank : %s\nSalary : %f\nPhone no : %s\nJoining date : %d/%d/%d\n",data[i].id,data[i].name,data[i].designation,data[i].salary,data[i].number,data[i].jd.day,data[i].jd.month,data[i].jd.year);
        }
        else if(data[i].jd.year==year)
        {
            if(data[i].jd.month>month)
            {
                printf("Employee id : %d\n Name : %s\nDesignation/Rank : %s\nSalary : %f\nPhone no : %s\nJoining date : %d/%d/%d\n",data[i].id,data[i].name,data[i].designation,data[i].salary,data[i].number,data[i].jd.day,data[i].jd.month,data[i].jd.year);

            }
            else if(data[i].jd.month==month)
            {
                if(data[i].jd.day>=day)
                {
                    printf("Employee id : %d\n Name : %s\nDesignation/Rank : %s\nSalary : %f\nPhone no : %s\nJoining date : %d/%d/%d\n",data[i].id,data[i].name,data[i].designation,data[i].salary,data[i].number,data[i].jd.day,data[i].jd.month,data[i].jd.year);

                }
            }
        }
    }
}

double max_sal()
{
    int i,index=-1;
    if(count==0)
        return 0;
    float max=data[0].salary;
    for(i=0; i<count; i++)
    {
        if(data[i].salary>max)
        {
            index=i;
            max=data[i].salary;
        }
    }
    printf("The ID is:%d\n",data[index].id);
    return max;
}

int count_rank(char string[])
{
    int c=0;
    int i;
    for(i=0; i<count; i++)
    {
        if(compare(data[i].designation,string)==0)
            c++;
    }
    return c;
}

void search_name(char name[])
{
    int i;
    for(i=0; i<count; i++)
    {
        if(!compare(data[i].name,name))
        {
            printf("Id : %d\n",data[i].id);
        }
    }
}

int main()
{
    printf("\n\n\n\tWELCOME To The Best Employee Software\n\n");
    while(1)
    {
        int t=menu();
        if(t==-1)
        {
            printf("\nThanks For Using our Software\n\t!!!!!!\n\t\tGood Bye\n");
            break;
        }
        else if(t==1)
        {
            add_employee();
        }
        else if(t==2)
        {
            int c;
            printf("\nPLease Enter The ID you want search:");
            scanf("%d",&c);
            search_id(c);
        }
        else if(t==3)
        {
            int c;
            printf("\nPlease Enter the ID Which you want to update:");
            scanf("%d",&c);
            update_info(c);
        }
        else if(t==4)
        {
            int c;
            scanf("%d",&c);
            printf("\nPlease Enter the ID Which you want to delete:");
            delete_employee(c);
        }
        else if(t==5)
        {
            printf("\nThe Average salary is: %f\n",display_avg_sal());
        }
        else if(t==6)
        {
            int d,m,y;
            printf("\nPlease Enter the Date(dd-mm-yyyy):");
            scanf("%d-%d-%d",&d,&m,&y);
            search_join_date(d,m,y);
        }
        else if(t==7)
        {
            printf("\nMax salary : %f\n",max_sal());
        }
        else if(t==8)
        {
            char str[20];
            printf("\nPlease Enter the Rank you want to count: ");
            scanf("%s",str);
            if(count_rank(str)!=0)
            {
                printf("There are %d people who are %s.\n",count_rank(str),str);
            }
            else if(count_rank(str)>0)
            {
                printf("There is %d people who is %s.\n",count_rank(str),str);
            }
            else if(count_rank(str)==0)
            {
                printf("\nThere is NO ID found Who is %s.",str);
            }
        }
        else if(t==9)
        {
            char st[20];
            printf("\nPLease Enter The Name You want to Search: ");
            scanf("%s",st);
            search_name(st);
        }
    }
}

int compare(char str1[], char str2[])
{
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' || str2[i] == '\0')
            break;
        i++;
    }
    return str1[i] - str2[i];
}
