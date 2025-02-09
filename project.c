// Employee Data Management System

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee{
    int empid;
    int age;
    char firstname[20];
    char lastname[20];
    char gender;
    char designation[50];
    char dept[50];
}empdata;

void write (FILE *fptr,empdata *arr,int n);
void delete (FILE *fptr);
void display (FILE *fptr);
void search (FILE *fptr);
void modify (FILE *fptr);
void listprof (FILE *fptr);
void list55 (FILE *fptr);
void listmale (FILE *fptr);
void listfemale (FILE *fptr);
void listdept(FILE *fptr);
void listdesg(FILE *fptr);

int n=1,opt=0;
int main()
{
    FILE *fptr;
    printf("\nEmployee Management System\n\n");
    while(1) {
        printf("Enter an option: \n");
        printf("1. Create A New Record\n2. Add A New record\n3. Delete A Record\n");
        printf("4. Search For A Record\n5. Modify A Record\n6. List\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&opt);
        printf("\n");
        if(opt == 6)
        {
            printf("06. List All Professors \n07. List All Employees Older Than 55\n08. List All Male employees\n09. List All Female Employees\n10. List All Employees Of A Department\n11. List A Designation\n12. List All Records\n");
            printf("\nEnter Your Choice: ");
            scanf("%d",&opt);
            printf("\n");
        }
        else if(opt == 1)
        {
            printf("Enter The Number Of Records: ");
            scanf("%d",&n);
            printf("\n");
        }
        empdata arr[n];
        switch(opt)
        {    
            case 1: // Create a New Record
                fptr = fopen("EmpData.txt","w");
                write(fptr,arr,n);
                fclose(fptr);
                break;
            case 2: // Add a New Record
                fptr = fopen("EmpData.txt","a");
                write(fptr,arr,n);
                break;
            case 3: // Delete a Record
                fptr = fopen("EmpData.txt","r");
                delete(fptr);
                break;
            case 4: // Search for a Record
                fptr = fopen("EmpData.txt","r");
                search(fptr);
                break;
            case 5: // Modify a Record
                fptr = fopen("EmpData.txt","r");
                modify(fptr);
                break;
            case 6: // List all Professors
                fptr = fopen("EmpData.txt","r");
                listprof(fptr);
                break;
            case 7: // List older than 55
                fptr = fopen("EmpData.txt","r");
                list55(fptr);
                break;
            case 8: // List all Male
                fptr = fopen("EmpData.txt","r");
                listmale(fptr);
                break;    
            case 9: // List all female
                fptr = fopen("EmpData.txt","r");
                listfemale(fptr);
                break;    
            case 10: // List a Department
                fptr = fopen("EmpData.txt","r");
                listdept(fptr);
                break;
            case 11: // List a Desigation
                fptr = fopen("EmpData.txt","r");
                listdesg(fptr);
                break;
            case 12: // List all
                fptr = fopen("EmpData.txt","r");
                display(fptr);
                break;      
            default:
                printf("Choose the correct option.\n");
        }
    }
    return 0;
}

void write(FILE *fptr,empdata *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter Employee ID : ");
        scanf("%d",&arr[i].empid); 
        printf("Enter Employee First Name : ");
        scanf(" %[^\n]%*c",&arr[i].firstname);
        printf("Enter Employee Last Name : ");
        scanf(" %[^\n]%*c",&arr[i].lastname);
        printf("Enter Employee Age : ");
        scanf("%d",&arr[i].age);
        printf("Enter Employee Gender (M/F): ");
        scanf(" %c",&arr[i].gender);
        printf("Enter Employee Department : ");
        scanf(" %[^\n]%*c",&arr[i].dept);
        printf("Enter Employee Designation : ");
        scanf(" %[^\n]%*c",&arr[i].designation);
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fptr,"%-6d\t%s %-8s\t%-3d\t%-6c\t%-10s\t%-10s\t\n",arr[i].empid,arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
    }
}

void delete(FILE *fptr)
{
    FILE *temp;
    temp = fopen("empdata_temp.txt","w");
    int i=0,n=0,key;
    empdata arr[100];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("Enter the Emp ID you want to delete: ");
    scanf("%d",&key);
    
    for(i=0;i<n;i++)
    {
        if (arr[i].empid == key)
            continue;
        else
        {
        fprintf(temp,"%-6d\t%s %-8s\t%-3d\t%-6c\t%-10s\t%-10s\t\n",arr[i].empid,arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
        }
    }
    fclose(fptr);
    fclose(temp);
    remove("EmpData.txt");
    rename("empdata_temp.txt","EmpData.txt");

}

void display(FILE *fptr)
{
    char ch = fgetc(fptr);
    printf("Emp ID\tName         \tAge\tGender\tDepartment\tDesignation\n\n");
    while (ch != EOF)
    {
        printf("%c",ch);
        ch = fgetc(fptr);
        if(ch == '\n') printf("\n");
    }
    printf("\n");
    fclose(fptr);
}

void search(FILE *fptr)
{
    int i=0,n=0,found = 0,empid;
    empdata arr[100];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("Enter Employee ID: ");
    scanf("%d",&empid);
    
    for(i=0;i<n;i++)
    {
        if(arr[i].empid == empid)
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            found = 1;
            break;
        }
    }
    if(!found)
    {
        printf("\nEmployee not found.\n\n");
    }
    fclose(fptr);
}

void listprof(FILE *fptr)
{
    int i=0,n=0,count=0;
    char req1[] = "Prof",req2[] = "Professor";
    empdata arr[100];

    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("List Of Professor(s):\n\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(arr[i].designation,req1) == 0 || strcmp(arr[i].designation,req2) == 0)
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found: %d\n\n",count);   
    fclose(fptr);
}

void list55(FILE *fptr)
{
    int i=0,n=0,count=0;
    empdata arr[100];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("List Of Employee(s) Above 55 Years: \n");
    for(i=0;i<n;i++)
    {
        if(arr[i].age >=55)
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found: %d\n\n",count);   
    fclose(fptr);
}

void listmale(FILE *fptr)
{
    int i=0,n=0,count=0;
    empdata arr[100];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("List Of Male Professor(s): \n");
    for(i=0;i<n;i++)
    {
        if(arr[i].gender == 'M' || arr[i].gender == 'm')
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found: %d\n\n",count);
    fclose(fptr);
}

void listfemale(FILE *fptr)
{
    int i=0,n=0,count=0;
    empdata arr[100];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i].gender == 'F' || arr[i].gender == 'f')
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found: %d\n\n",count);    
    fclose(fptr);
}

void modify(FILE *fptr)
{
    empdata arr[100];
    int i=0,n=0,key,opt1=0,newage=0,flag = 0;
    char newname[30];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("Enter The Employee ID To Modify: ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i].empid == key)
        {
            flag = 1;
            printf("\nOld Record\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            printf("Enter The Option To Modify: ");
            printf("\n1.Name\n2.Age\n3.Department\n4.Designation\nYour option: "); fflush(stdin);
            scanf("%d",&opt1);
            switch(opt1)
            {
                case 1:
                    printf("Enter New First Name: "); fflush(stdin);
                    scanf(" %[^\n]%*c",newname);
                    strcpy(arr[i].firstname,newname);
                    printf("Enter New Last Name: "); fflush(stdin);
                    scanf(" %[^\n]%*c",newname);
                    strcpy(arr[i].lastname,newname);
                    break;
                case 2:
                    printf("Enter New Age: "); fflush(stdin);
                    scanf("%d",&newage);
                    arr[i].age = newage;
                    break;
                case 3:
                    printf("Enter New Department: "); fflush(stdin);
                    scanf(" %[^\n]%*c",newname);
                    strcpy(arr[i].dept,newname);
                    break;
                case 4:
                    printf("Enter New Designation: "); fflush(stdin);
                    scanf(" %[^\n]%*c",newname);
                    strcpy(arr[i].designation,newname);
                    break;
                default: 
                    printf("Choose the correct option");
                    exit(1);
            }
        }
        if (flag == 1) break;
    }
    if(flag == 0)
    {
        printf("Employee Not Found\n\n");
        exit(1);
    }
    FILE *temp;
    temp = fopen("empdata_temp.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(temp,"%-6d\t%s %-8s\t%-3d\t%-6c\t%-10s\t%-10s\t\n",arr[i].empid,arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
    }
    fclose(fptr);
    fclose(temp);
    remove("EmpData.txt");
    rename("empdata_temp.txt","EmpData.txt");
    printf("\nRecord Modified\n\n");
}

void listdept(FILE *fptr)
{
    empdata arr[100];
    int i = 0,n = 0,count = 0;
    char dept[20];
    while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    {
        i++,n++;
    }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("Enter the Department: "); fflush(stdin);
    scanf(" %[^\n]%*c",dept);

    for(i=0;i<n;i++)
    {
        if (strcmp(arr[i].dept,dept) == 0)
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found for %s Department: %d\n\n",dept,count);
    fclose(fptr);
}

void listdesg(FILE *fptr)
{
    empdata arr[100];
    int i = 0,n = 0,count = 0;
    char desg[30];
    char line[500];

    while (fgets(line, sizeof(line), fptr) != NULL && n < 100)
    {
        if (sscanf(line, "%d %19s %19s %d %c %19s %s", &arr[i].empid, arr[i].firstname, arr[i].lastname, &arr[i].age, &arr[i].gender, arr[i].dept, &arr[i].designation) == 7)
        {
            i++,n++;
        }
    }
    // while (fscanf(fptr,"%d %s %s %d %c %s %[^\n]",&arr[i].empid,arr[i].firstname,arr[i].lastname,&arr[i].age,&arr[i].gender,arr[i].dept,arr[i].designation) == 7)
    // {
    //     i++,n++;
    // }
    if (feof(fptr))
    {
        // Reached end of file, no errors
    }
    else if (ferror(fptr))
    {
        // Error while reading file, handle error
        printf("Error reading input file\n");
        exit(1);
    }
    else
    {
        // Malformed input file, handle error
        printf("Malformed input file\n");
        exit(1);
    }
    printf("Enter the Designation: ");
    scanf(" %[^\n]%*c",desg);

    for(i=0;i<n;i++)
    {
        if (strcmp(desg,arr[i].designation) == 0)
        {
            printf("\nName: %s %s\nAge: %d %c\nDept: %s\nDesgn: %s\n\n",arr[i].firstname,arr[i].lastname,arr[i].age,arr[i].gender,arr[i].dept,arr[i].designation);
            count++;
        }
    }
    printf("\nNumber of Records found for %s: %d\n\n",desg,count);
    fclose(fptr);
}

