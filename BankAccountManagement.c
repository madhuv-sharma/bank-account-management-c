//Designed in Turbo C++

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>


struct acc_type
{
	int no;
	char nm[50];
	char add[100];
	float bal;     
}arr[500];

char ch;
int f=0, i=0, j, n, x=0;

void main()
{
	clrscr();
	void view();
	FILE *fp=fopen("Accounts.dat","w");
	if(fp == NULL)
    	{
        	printf("Error in creating the file\n");
        	exit(0);
    	}
	for(i=0; i<500; i++)
	{
		if(i==0)
			arr[i].no = 100;
		else
			arr[i].no = 100 + i;
		printf("Enter Name:\n");
		scanf("%s", arr[i].nm);
		printf("Enter Address:\n");
		scanf("%s", arr[i].add);
		printf("Enter Account Balance:\n");
		scanf("%f", &arr[i].bal);
		while(arr[i].bal<0)
		{
			printf("Invalid Entry! Please re-enter balance:\n");
			scanf("%f", &arr[i].bal);
		}
		fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
		i++;
		printf("Enter 'y' to Open another Account, else enter any value:\n");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch!='y')
		{
			i--;
			break;
		}
	}
	fclose(fp);
	do
	{
		printf("Enter '1' to Create a New Account\n'2' to Deposit Cash\n'3' to Withdraw Cash\n'4' to Check Balance in Account\n'5' to Display Accounts\n'6' to Exit");
		scanf("%d", &x);
		switch(x)
		{
			case 1:
				fp=freopen(fp, "C:\Users\pc\Desktop\PROGRAMMING\C\Accounts.dat", "a");
				do
				{
					printf("Enter Name:\n");
					scanf("%s", arr[i].nm);
					printf("Enter Address:\n");
					scanf("%s", arr[i].add);
					printf("Enter Account Balance:\n");
					scanf("%f", &arr[i].bal);
					while(arr[i].bal<0)
					{
						printf("Invalid Balance! Please re-enter balance:\n");
						scanf("%f", &arr[i].bal);
					}
					arr[i].no=100+i;
					printf("Your Account Number is %d.", arr[i].nm);
					fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
					printf("Enter 'y' for Another Entry\n");
					scanf("%c", &ch);
				}while(ch=='y');
				fclose(fp);
			break;
			case 2:
				fp=freopen(fp, "C:\Users\pc\Desktop\PROGRAMMING\C\Accounts.dat", "w");
				fseek(fp, 0, SEEK_SET);
				printf("Enter Account Number:");
				scanf("%d",&n);
				f=0;
				for(j=0; j<=i; j++)
				{
					if(arr[j].no==n)
					{
						printf("\nThe current balance in your account is %f\n",	arr[j].bal);
						printf("\nEnter Amount you want to deposit:\n");
						scanf("%f",&cr);
						arr[j].bal+=cr;
						printf("New balance in your Account is %f\n", arr[j].bal);
						fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
						f=1;
						break;
					}
					else
						fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
				}
				if(f==0)
					printf("No Such Account Number exists\n");
				fclose(fp);
			break;
			case 3:
				fp=freopen(fp, "C:\Users\pc\Desktop\PROGRAMMING\C\Accounts.dat", "w");
				fseek(fp, 0, SEEK_SET);
				scanf("%d",&n);
				f=0;
				for(j=0; j<=i; j++)
				{
					if(arr[j].no==n)
					{	printf("\nThe current balance in your account is %f\n",	arr[j].bal);
						printf("Enter Amount you want to withdraw:\n");
						scanf("%f",&de);
						if(arr[j].bal<de)
						{
							printf("Sorry, you can't debit more than what you currently have in your bank account. Please contact Loans dept for assistance!\n");
							break;
						}
						arr[j].bal-=de;
						printf("New balance in your Account is %f\n", arr[j].bal);
						fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
						f=1;
						break;
					}
					else
						fprintf(fp, "%d %s %s %f\n",arr[i].no, arr[i].nm, arr[i].add, arr[i].bal);
				}
				if(f==0)
					printf("No Such Account Number exists\n");
				fclose(fp);
			break;
			case 4:
				printf("Enter Account Number:\n");
				scanf("%d", &n);
				f=0;
				for(j=0; j<=i; j++)
				{
					if(arr[j].no==n)
					{
						printf("\nAccount Number\t%d\nAccount Holder's Name\t%s\nAddress\t%s\nBalance\tRs.%f\n" , arr[j].no, arr[j].nm, arr[j].add, arr[j].bal);
						f=1;
						break;
					}
				}
				if(f==0)
					printf("No Such Account Number exists\n");
			break;
			case 5:
				for(j=0; j<=i; j++)
					printf("\nAccount Number\t%d\nAccount Holder's Name\t%s\nAddress\t%s\nBalance\tRs.%f\n\n\n" , arr[j].no, arr[j].nm, arr[j].add, arr[j].bal);
			break;
			case 6:
				exit(0);
			default:
				printf("Invalid Input!");
		}
	}while(x!=6);
	getch();
}
