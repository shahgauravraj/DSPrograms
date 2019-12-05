/* Define an EMPLOYEE structure with members Emp_name, Emp-id, Dept-name and Salary.
Read and display data of N employees. Employees may belong to different departments.
Write a function to find total salary of employees of a specified department.
Use the concept of pointer to structure and allocate the memory dynamically to EMPLOYEE instances. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
    char emp_name[20];
	int emp_id;
	char dept_name[20];
	float salary;
};

int compute_total_sal(struct employee *e,char dn[], int m);

void main()
{
	int m,i;
	struct employee *emp;
	char dname[20],choice;

	printf("Enter the number of employees:");
	scanf("%d",&m);

	emp=(struct employee *)malloc(m*sizeof(struct employee));

	/*Read employee details*/
	for(i=0;i<m;i++)
	{
		printf("Enter the details of Employee %d\n", i+1);
		printf("Enter the employee name:");
		scanf("%s",(emp+i)->emp_name);
		printf("Enter the employee ID:");
		scanf("%d",&(emp+i)->emp_id);
		printf("Enter the employee department:");
		scanf("%s",&(emp+i)->dept_name);
		printf("Enter the salary of employee:");
		scanf("%f",&(emp+i)->salary);
	}
	/* Print employee details*/
	printf("************************Employee Details*********************** \n");
	
printf("%-15s%-25s%-15s%-15s\n","ID","EMPLOYEE NAME","DEPARTMENT","SALARY");
	for(i=0;i<m;i++)	
	{
	printf("%-15d%-25s%-15s%-15g \n",(emp+i)->emp_id,(emp+i)->emp_name,(emp+i)->dept_name,(emp+i)->salary);
                                                                                   
    }
	do{
		printf("\n Enter the department for which the total salary has to be computed:");
		scanf("%s",dname);
		compute_total_sal(emp,dname,m);
		printf("\n Do you want to continue[Y/N]:");
		scanf(" %c",&choice);
	}while(choice=='Y' || choice=='y');
}

/*find total salary of employees of a specified department. */
int compute_total_sal(struct employee *e,char dn[], int m)
{
	float totalsal=0;
	int i,flag=0;

	for(i=0; i<m;i++)
		if(strcmp((e+i)->dept_name,dn)==0)
		{
            flag=1;
		    totalsal += (e+i)->salary;
        }

	if(flag==0)
		printf("\n No such department\n");
	else
        printf("\n Total salary of employees in department %s is %f",dn,totalsal);	
}