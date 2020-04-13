#include <stdio.h>
#include<string.h>

struct product
{

    char name[100];
    int id;
    int price;
    char discription[100];
    int discount;
    int total_price;
};

struct product p[100];
int index=0;

int menu()
{

    printf("Press 1 to Show All product\n");
    printf("press 2 to Add Product\n");
    printf("Press 3 to Delete Product\n");
    printf("Press 4 to Search a product\n");
    printf("Press 5 to count all  product\n");
    printf("Press 10 to Exit\n");
}

int showallproduct()
{
    int i=0;
    FILE *fp;
    fp=fopen("showallproduct.txt","w");
    if(index==0)
    {
        printf("No Data\n");
    }
    else
    {
        for(i=0; i<index; i++)
        {
            fprintf(fp,"Name: %s\n",p[i].name);
            fprintf(fp,"ID: %d\n",p[i].id);
            fprintf(fp,"product Price: %d\n",p[index].price);
            fprintf(fp,"Description: %s\n",p[i].discription);
            fprintf(fp,"discount: %d\n",p[index].discount);
            fprintf(fp,"Total Balance: %d\n",p[index].total_price);


        }
    }
    return 0;
}
int addproduct()
{
    int i=0,j;
    int flag =0;

    printf("Please Enter The Product name: \n");
    fflush(stdin);
    gets(p[index].name);
    while(p[index].name[i] != '\0')
    {
        if(p[index].name[0]>=97 && p[index].name[0]<=122)
        {
            p[index].name[0]=p[index].name[0]-32;
        }
        i++;
    }
    printf("Please Enter The product id: \n");
    scanf("%d",&p[index].id);
    int q=0;
    while(p[index].id%10!=0)
    {

        q++;
        if(q-1<9 || q-1>9)
        {
            printf("Please Enter The product id: \n");
            scanf("%d",&p[index].id);
            break;
        }
    }


    printf("Please Enter The product Price:\n");
    scanf("%d",&p[index].price);

    printf("Please Enter Description: \n");
    fflush(stdin);
    gets(p[index].discription);
    printf("Please Enter The the discount:");
    scanf("%d",&p[index].discount);

    p[index].total_price=(p[index]. price-p[index].discount);

    index++;

    return 0;
}

int deleteproduct()
{
    int i,j,n;
    int a;

    printf("Please Enter The Product Code Which You Want To Delete: \n");
    scanf("%d",&a);

    for(i=0; i<index; i++)
    {
        if(p[i].id==a)
        {
            for(j=i; j<index; i++,j++)
            {
                p[i]=p[i+1];

            }
            index--;
        }
    }
    return 0;
}

int  search()
{
    int a,i;

    printf("Please Enter The product ID you want to search:\n");
    scanf("%d",&a);

    for(i=0; i<index; i++)
    {
        if(p[i].id==a)
        {
            printf("Name: %s\n",p[i].name);
            printf("ID: %d\n",p[i].id);
            printf("product Price: %d\n",p[index].price);
            printf("Description: %s\n",p[i].discription);
            printf("discount: %d\n",p[index].discount);
            printf("Total Balance: %d\n",p[index].total_price);
        }
    }

    return 0;
}

int countproduct()
{
    int n,i;

    FILE *fp;

    fp=fopen("Count.txt","w");
    fprintf(fp,"Total Product: %d \n",index);
    fclose(fp);
    return 0;
}

int main()
{
    printf("!!!!!!!! search()!!!Welcome!!!!!!!\n");
    int n;
    while(1)
    {
        menu();

        printf("Please Enter your choice: \n");
        scanf("%d",&n);

        if(n==1)
        {
            showallproduct();
        }
        if(n==2)
        {
            addproduct();
        }
        if(n==3)
        {
            deleteproduct();
        }
        if(n==4)
        {
            search();
        }
        if(n==5)
        {
            countproduct();
        }

        if(n==10)
        {
            printf("\nGood Bye\n");
            break;
        }

    }
    return 0;
}
