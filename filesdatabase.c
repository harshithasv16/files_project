#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input();
void search();
void copy();
void delet();
void display1(char name[],int,int);
void new_user();
void existing_user();
void display2();

FILE *fp1,*fp2;
char username[10],password[10],dob[10];
char fname[]={"store.txt"};
char cname[]={"copy.txt"};
int login=0;

struct student
{
 int usn;
 char name[25];
 int marks;
};
struct student stu[100];
int n;

int main()
{
    int rpt=1,ch;
    int uch;

	printf("WELCOME TO OUR MINI-PROJECT\n");
	printf("\n");
	printf("Enter your choice\n");
	printf("1.Existing user\n");
	printf("===============\n");
	printf("2.New user\n");
	printf("==========\n");
	scanf("%d",&uch);

	switch(uch)
	{
		case 1:
                printf("you choose existing user option\n");
                existing_user();
                break;

		case 2:
                printf("you choose new user option\n");
                new_user();
                break;

		default :
                printf("Invalid Choice\n");

	}

        while(rpt==1)
        {
                if(login!=1)
                {
                        printf("sorry pleae try again\n");
                        //delay(5000);
                        //Sleep(5000);
                        exit(0);
                }

                printf("Enter ur choice\n");
                printf("1.INPUT\n");
                printf("2.SEARCH\n");
                printf("3.DELETE\n");
                printf("4.DISPLAY\n");
                printf("5.EXIT\n");
                scanf("%d",&ch);
                printf("please wait.....\n");
                //delay(800);
                //Sleep(800);

            switch(ch)
            {

                case 1:  //system("cls");
                        printf("You choose to input the data.....\n");
                        printf("\n");
                        printf("please insert....\n\n");

                        input();
                        break;

                case 2: // clrscr();
                        printf("You choose to search .....\n");
                        printf("\n");
                        printf("please insert....\n\n");

                        search();
                        break;

                case 3:  //clrscr();
                        printf("You choose to delete the data.....\n");
                        printf("\n");
                        printf("please insert....\n\n");

                        delet();
                        break;

                case 4:
                        display2();
                        break;

                case 5:  //clrscr();
                        printf("You choose to exit.....\n");
                        printf("\n");
                        printf("Thank you....\n\n");
                        exit(0);
                        break;

                default: //clrscr();
                        printf("You entered an invalid entry......\n\n");
            }

                printf("\n Do You want to continue(1/0).....???\n") ;
                scanf("%d",&rpt);
                //clrscr();
        }

return 0;
}

void input()
{
	int i;

	printf("Enter the number of students details\n");
	scanf("%d",&n);
	printf("Enter %d student details\n",n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d usn:\t",i+1);
		fflush(stdin);
		scanf("%d",&stu[i].usn);
		fflush(stdin);
		printf("Enter the %d name:\t",i+1);
		scanf("%s",stu[i].name);
		fflush(stdin);
		printf("Enter the %d MARKS:\t",i+1);
		scanf("%d",&stu[i].marks);

	}

	copy();//Copying all the input to the file "store.txt"

}

void search()
{
	char key[15],name[15];
	int usn,marks,i;

	printf("\n\nEnter a name to be searched\n\n");
	scanf("%s",key);
	fp1=fopen(fname,"r");//store.txt
	if(fp1==NULL)
	{

            printf("Error in opening the file");
	}

	while(fscanf(fp1,"%s\t%d\t%d\n",name,&usn,&marks)!=EOF)
	{
            if(strcmp(key,name)==0)
            {
                i=1;
                printf("Search is sucessful\n");
                display1(name,usn,marks);
            }
	}

        if(i!=1)
        printf("Search not successful");
        fclose(fp1);

}

void copy()
{
	int i;
	fp1=fopen(fname,"a+");//store.txt
	if(fp1==NULL)
	{
        printf("Error in opening the file");
        exit(0);
	}

	for(i=0;i<n;i++)
	{
        fprintf(fp1,"%s\t%d\t%d\n",stu[i].name,stu[i].usn,stu[i].marks);
	}

	fclose(fp1);
}

void delet()
{
	char key[15],name[15];
	int usn,marks,flag,count=0;

    printf("\n\nEnter a name to be deleted\n\n");
	scanf("%s",key);

	fp1=fopen(fname,"r");//store.txt
	if(fp1==NULL)
	{
        printf("Error in opening the file");
        exit(0);
	}

	fp2=fopen(cname,"w");//copy.txt
	if(fp2==NULL)
	{
        printf("Error in opening the file");
	}

	while(fscanf(fp1,"%s\t%d\t%d\n",name,&usn,&marks)!=EOF)
	{
	    if(strcmp(key,name)==0)
        {
            printf("Search is sucessful\n");
            display1(name,usn,marks);
            flag=1;
        }

	   else if(strcmp(key,name)!=0)
        {
            fprintf(fp2,"%s\t%d\t%d\n",name,usn,marks);

        }

	}

	if(flag!=1)
	printf("Search not successful");
	fclose(fp1);
	fclose(fp2);

    if(remove("store.txt"))
        perror("file not removed");

	if(rename(cname,fname)==0)
	   printf(" Done\n");
    else
        perror("Renaming Not done");

    display2();

}

void display2()
{
        char name[15];
        int usn,marks,count=0;
        fp1=fopen(fname,"r");//strore.txt
        if(fp1==NULL)
        {
            printf("Error in opening the file\n");
            exit(0);
        }

        printf("The data base is......\n");
        printf("\tSTUDENT DETAILS\n");
        printf("\t===============\n");
        printf("\tNAME\tUSN\tMARKS\n");

    while(fscanf(fp1,"%s\t%d\t%d\n",name,&usn,&marks)!=EOF)
	{
        display1(name,usn,marks);
        count++;
	}

	printf("The total number of students are : %d\n\n",count);

}

void display1(char name[15],int usn,int marks)
{

    printf("\t%s\t%d\t\%d\n",name,usn,marks);

}

void new_user()
{
    int flag=0;
    char password2[10];

    printf("Create your user name and password\n");
	printf("Enter your user-name\n");
	scanf("%s",username);
	printf("Enter your date of birth (01012017)\n");
	scanf("%s",dob);

	do
    {
		printf("Enter your password\n");
		scanf("%s",password);
		printf("re-enter your password\n");
		scanf("%s",password2);

		if(strcmp(password2,password)!=0)
		{
			flag++;
			printf("both the passwords r not correct\n");
		}
		else
		flag=0;
	}while(flag==1);


	fp1=fopen("loginfile.txt","a+");
	if(fp1==NULL)
	{
		printf("Error in opening the file\n");
		exit(0);
	}

	fprintf(fp1,"%s\t%s\t%s\n",username,password,dob);
	printf("you have successfully created your account\n");
	fclose(fp1);

	existing_user();

}

void existing_user()
{
	char urname[10],pword[10];

    printf("please wait.....\n");
	printf("Enter your user name CASE SENSITIVE\n");
	scanf("%s",urname);
	printf("Enter your password CASE SENSITIVE\n");
	scanf("%s",pword);

	fp2=fopen("loginfile.txt","r");

	if(fp2==NULL)
	{
		printf("Error in opening the file\n");
		exit(0);
	}

	while(fscanf(fp2,"%s\t%s\t%s\n",username,password,dob)!=EOF)
	{
		if(strcmp(urname,username)==0&&strcmp(pword,password)==0)
		{
			login=1;
			printf("welcome\n");
		}
	}

}
