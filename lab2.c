/*Define an EMPLOYEE structure with members Emp_name, Emp-id,
Dept-name and Salary. Read and display data of N employees.
Employees may belong to different departments. Write a function to
find total salary of employees of a specified department. Use the
concept of pointer to structure and allocate the memory dynamically to
EMPLOYEE instances */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct emp{
    char name[50];
    int id;
    char dept[50];
    int salary;
};

void salary(struct emp *ptr, char dept[50],int n ){
    int total=0;
    for(int i=0;i<n;i++){
        if(strcmp((ptr+i)->dept,dept)==0){
            total+=((ptr+i)->salary);
        }
    }
    printf("The total salary of %s department is: %d",dept,total);

}
void main(){
    int n;
    printf("Enter the number of employees:");
    scanf("%d",&n);
    struct emp *ptr= (struct emp*)malloc(n*sizeof(struct emp));
    for(int i=0;i<n;i++){
        printf("Enter details of employee %d:\n",(i+1));
        printf("Name:");
        scanf("%s",(ptr+i)->name);
        printf("Id number:");
        scanf("%d",&(ptr+i)->id);
        printf("Department:");
        scanf(" %s",(ptr+i)->dept);
        printf("salary:");        
        scanf("%d",&(ptr+i)->salary);
        printf("\n");
    }

    for(int i=0;i<n;i++){
        printf("Employee %d \n",(i+1));
        printf("Name: %s\n",(ptr+i)->name);
        printf("Id:%d\n",(ptr+i)->id);
        printf("Dept:%s\n",(ptr+i)->dept);
        printf("Salary:%d\n",(ptr+i)->salary);
        printf("\n");
    }

    char dept[50];
    printf("Enter the dept to calculate total salary:");
    scanf("%s",dept);
    salary(ptr, dept,n);
}