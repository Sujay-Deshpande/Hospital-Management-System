/*Hospital Management System
This project is based on the management of Data of hospital with their all operation so that the can give reports and other data in given time*/
//Including Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
//Defining Structres
struct node
{
    char *name[100];
    int age;
    char *address[100];
    long int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
};
struct data_stored
{
    int id;
    struct node *point;
    struct data_stored *next;
};
//Global Variable declaration
int call = 0, clinic = 0;
int registration = 100;
struct node *start = NULL;
struct data_stored *deletion = NULL;
//Function Defination
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *start);
void admin_pass();
void res_login();
void medical_login();
void welcome();
void recesption();
void table();
void welcome1();
void receipt();
void entry();
void medicalEntry();
void exit1();
void print_Line();
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//Execution Started
int main()
{
    system("cls");
    system("color B");
    Sleep(1850);
    welcome();
    gotoxy(30, 24);
    for (int j = 0; j <= 100; j++)
    {
        Sleep(5);
        printf("\xDB");
    }
    gotoxy(65, 27);
    printf("Press any key to continue ....");
    getch();
    welcome1();
    return 0;
}//Execution Ended
// Reseptionist Login
void res_login()
{
    char password[21] = "ssc";
    char enter_pass[21], pass1, w = '*', user[20];
    int again, i = 0;
    system("cls");
    welcome();
    gotoxy(58, 14);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Recesption Login: \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    gotoxy(54, 17);
    // After completion
    printf("Enter password:");
    while (pass1 != 13)
    {
        pass1 = getch();
        if (pass1 != 13 && pass1 != 8)
        {
            printf("%c", w);
            enter_pass[i] = pass1;
            i++;
        }
    }
    enter_pass[i] = '\0';
    if (strcmp(password, enter_pass) == 0)
    {
        printf("\nEntered successfully!");
        Sleep(5);
        recesption();
    }
    else
    {
        printf("\nTry again!");
        getch();
        welcome1();
    }
}

void recesption()
{
    int option;
    system("cls");
    welcome();
    if (clinic == 0)
    {
        gotoxy(50, 10);
        printf("Doctor is not present in the clinic");
    }
    else
    {
        gotoxy(60, 10);
        printf("Doctor is present in the clinic");
    }
    gotoxy(60, 13);
    for (int j = 0; j <= 8; j++)
    {
        printf("\xDB");
    }
    printf(" WELCOME TO SSC HOSPITAL!");
    for (int j = 0; j <= 8; j++)
    {
        printf("\xDB");
    }
    gotoxy(40, 20);
    printf("1. Add A Patient");
    gotoxy(40, 22);
    printf("2. Refresh The Page");
    gotoxy(40, 24);
    printf("3. Logout");
    gotoxy(70, 30);
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        start = insert(start);
        getchar();
        system("cls");
    case 2:
        recesption();
        break;
    case 3:
        welcome1();
        break;
    default:
        printf("Please Eneter Valid choice!!");
    }
}
void welcome1()
{
    int i;
    system("cls");
    gotoxy(53, 9);
    Sleep(50);
    printf("\xB3 \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome to SSC Hospital \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \xB3");
    gotoxy(70, 12);
    printf("Login:");
    gotoxy(54, 17);
    printf("1.Admin");
    gotoxy(54, 19);
    printf("2.Receptionist");
    gotoxy(54, 21);
    printf("3.Medical Reception");
    gotoxy(54, 23);
    printf("4.Exit");
    gotoxy(54, 26);
    printf("Choose anyone option from above:\t");
    scanf("%d", &i);
    gotoxy(35, 34);
    for (int j = 0; j <= 100; j++)
    {
        Sleep(5);
        printf("\xDB");
    }
    switch (i)
    {
    case 1:
        admin_pass();
        break;
    case 2:
        res_login();
        break;
    case 3:
        medical_login();
        break;
    case 4:
        exit1();
        savefile();
        break;
    }
}
void welcome()
{
    printf("\t\t\t* * * *   * * * *   * * * *           *     *   * * * *  * * * *  * * * *   * * * * *   * * * * *    *      *            \n");
    printf("\t\t\t*         *         *                 *     *   *     *  *        *     *       *           *       * *     *      \n");
    printf("\t\t\t* * * *   * * * *   *                 * * * *   *     *  * * * *  * * * *       *           *      * * *    *       \n");
    printf("\t\t\t      *         *   *                 *     *   *     *        *  *             *           *     *     *   *      \n");
    printf("\t\t\t* * * *   * * * *   * * * *           *     *   * * * *  * * * *  *         * * * * *       *    *       *  * * * *       \n");
}
// Admin Login
void admin_pass()
{
    char password[21] = "gpp";
    char enter_pass[21], pass1, w = '*';
    int again, i = 0;
    system("cls");
    welcome();
    gotoxy(60, 21);
    printf("\xB3 \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome, Doctor! \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \xB3");
    gotoxy(50, 24);
    printf("Enter password:");
    while (pass1 != 13)
    {
        pass1 = getch();
        if (pass1 != 13 && pass1 != 8)
        {
            printf("%c", w);
            enter_pass[i] = pass1;
            i++;
        }
    }
    enter_pass[i] = '\0';
    if (strcmp(password, enter_pass) == 0)
    {
        printf("\nEntered successfully!");
        entry();
    }
    else
    {
        gotoxy(92, 19);
        printf("Try again!");
        getch();
        welcome1();
    }
}
//FOR ADMIN
void entry()
{
    int op;
    FILE *f2;
    char c;
    system("cls");
    welcome();
    gotoxy(60, 10);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Admin \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    gotoxy(60, 14);
    printf("Options:\t");
    gotoxy(61, 16);
    printf("1.GIVE RECEIPT\n");
    gotoxy(61, 18);
    printf("2.DISPLAY ALL APPOINTMENTS\n");
    gotoxy(61, 20);
    printf("3.GIVE MEDICINES");
    gotoxy(61, 22);
    printf("4.");
    if (clinic == 0)
        printf("START ");
    else
        printf("CLOSE ");
    printf("CLINIC");
    gotoxy(61, 24);
    printf("5.LOGOUT");
    gotoxy(61, 30);
    printf("Select Options: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        start = delete (start);
        gotoxy(80, 10);
        getch();
        entry();
        break;
    case 2:
        display(start);
        getchar();
        system("cls");
        break;
    case 3:
        if (start == NULL)
        {
            printf("No pattient Available!!");
            getch();
            entry();
        }
        printf("Enter a Medicines:\n");
        f2 = fopen("medical", "w");
        while ((c = getchar()) != EOF)
            putc(c, f2);
        fclose(f2);
        entry();
        break;
    case 4:
        if (clinic == 0)
            clinic = 1;
        else
            clinic = 0;

        entry();
        break;
    case 5:
        welcome1();
        entry();
        break;
    default:
        entry();
        break;
    }
}
void savefile()
{
    FILE *fpointer = fopen("Hospital", "w");
    if (!fpointer)
    {
        printf("\n Error in opening file!");
        return;
    }
    struct node *ptr;
    ptr = deletion;
    while (ptr)
    {
        fprintf(fpointer, "%-6d", ptr->reg);
        fprintf(fpointer, "%-15s", ptr->name);
        fprintf(fpointer, "%-15s", ptr->bloodgroup);
        fprintf(fpointer, "%-15s", ptr->phone);
        fprintf(fpointer, "\n");
        ptr = ptr->next;
    }
    fclose(fpointer);
}

struct node *insert(struct node *start)
{
    system("cls");
    welcome();
    int val2, val6, pri;
    long signed int val4;
    char val1, val3, val5;
    struct node *ptr, *p;
    char *name[100];
    char *address[100];
    ptr = (struct node *)malloc(sizeof(struct node));
    gotoxy(60, 9);
    printf("\xB3 \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Registration form \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  \xB3");
    gotoxy(50, 12);
    printf("Enter patient Name:");
    scanf(" %s", ptr->name);
    gotoxy(50, 14);
    printf("Enter the patient's age:");
    scanf("%d", &val2);
    gotoxy(50, 16);
    printf("Enter Home address:");
    scanf(" %s", ptr->address);
    gotoxy(50, 18);
    printf("Enter phone number:");
    scanf("%d", &val4);
    gotoxy(50, 20);
    printf("Enter the blood group of Patient:");
    scanf(" %s", ptr->bloodgroup);
    gotoxy(50, 22);
    table();
    scanf("%d", &pri);
    ptr->age = val2;
    ptr->phone = val4;
    ptr->priority = pri;
    ptr->reg = ++registration;
    if ((start == NULL) || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}

struct node *delete(struct node *start)
{
    system("cls");
    struct node *ptr;
    struct data_stored *newStore, *joining;
    if (start == NULL)
    {
        gotoxy(41, 10);
        printf("\n NO PATIENT RECORD");
        return NULL;
    }
    else
    {
        ptr = start;
        joining = deletion;
        receipt();
        newStore = (struct data_stored *)malloc(sizeof(struct data_stored));
        newStore->id = ptr->reg;
        newStore->point = ptr;
        newStore->next = NULL;
        if (deletion == NULL)
            deletion = newStore;
        else
        {
            while (joining->next != NULL)
                joining = joining->next;
            joining->next = newStore;
        }
        start = start->next;
        free(ptr);
    }
    return start;
}
void display(struct node *start)
{
    system("cls");
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        gotoxy(41, 10);
        printf("THERE IS NO PATIENT");
    }
    else
    {
        gotoxy(41, 4);
        printf("\nPriority wise appointments are:\n\n");
        while (ptr != NULL)
        {
            printf("Reg. No.: %d\n", ptr->reg);
            printf("The name of patient is:%s\n", ptr->name);
            printf("The age of patient is:%d\n", ptr->age);
            printf("The address of patient is : %s\n", ptr->address);
            printf("Phone Number:%d\n", ptr->phone);
            printf("The blood group of patient is:%s\n", ptr->bloodgroup);
            printf("---------------------------------------------------\n");
            ptr = ptr->next;
        }
    }
    printf("Enter Any Key TO GO Main Menu..");
    getch();
    entry();
}
void table()
{
    gotoxy(30, 24);
    printf("Please Refer this Table for your disease!");
    gotoxy(23, 25);
    printf("1.Heart attack");
    gotoxy(23, 26);
    printf("2.Severe wound/Bleeding");
    gotoxy(23, 27);
    printf("3.Cancer");
    gotoxy(23, 28);
    printf("4.Accident");
    gotoxy(23, 29);
    printf("5.Chest pain");
    gotoxy(23, 30);
    printf("6.Fracture");
    gotoxy(23, 31);
    printf("7.Diabetes Checkup");
    gotoxy(23, 32);
    printf("8.Infection");
    gotoxy(23, 33);
    printf("9.Viral Fever or cough and cold");
    gotoxy(23, 34);
    printf("10.Common Cold/Head ache or other Consultation");
    gotoxy(23, 35);
    printf("Enter your Choise: ");
}
void exit1()
{
    char name[] = " CREATED BY ";
    int z = strlen(name);
    system("cls");
    gotoxy(61, 2);
    printf("\xB3");
    for (int j = 0; j <= 8; j++)
    {
        Sleep(30);
        printf("\xDB");
    }
    for (int j = 0; j <= z; j++)
    {
        Sleep(50);
        printf(" %c", name[j]);
    }
    for (int j = 0; j <= 8; j++)
    {
        Sleep(30);
        printf("\xDB");
    }
    printf("\xB3");
    gotoxy(80, 4);
    printf("Members:");
    gotoxy(62, 9);
    printf("1.2106044 - Deshpande Sujay Hemantkumar");
    gotoxy(62, 10);
    printf("2.2106076 - Jadhav Sanyog Sandip");
    gotoxy(62, 11);
    printf("3.2106096 - Kate Chandrashekhar Gajanan");
    gotoxy(65, 15);
    printf("For exit press any key !!");
    Beep(750, 800);
    getch();
    exit(0);
}

void medical_login()
{
    char password[21] = "Medical";
    char enter_pass[21], pass1, w = '*';
    int again, i = 0;
    system("cls");
    welcome();
    gotoxy(53, 12);
    printf("Welcome!");
    gotoxy(60, 14);
    printf("Enter password:");
    while (pass1 != 13)
    {
        pass1 = getch();
        if (pass1 != 13 && pass1 != 8)
        {
            printf("%c", w);
            enter_pass[i] = pass1;
            i++;
        }
    }
    enter_pass[i] = '\0';
    if (strcmp(password, enter_pass) == 0)
    {
        printf("\nEntered successfully!");
        getch();
        medicalEntry();
    }
    else
    {
        gotoxy(92, 19);
        printf("Try again!");
        getch();
        medical_login();
    }
}
void medicalEntry()
{
    system("cls");
    welcome();
    char c;
    int ch;
    gotoxy(60, 15);
    printf("1.Take Reception");
    gotoxy(60, 17);
    printf("2.Refresh The Page");
    gotoxy(60, 19);
    printf("3.Logout");
    gotoxy(70, 23);
    printf("Choose: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        if (clinic == 1 && start != NULL)
        {
            printf("---------------------------------------------------\n");
            printf("Reg. No.: %d", start->reg);
            printf("\nPatient Name: %s", start->name);
            printf("\nMedicines:\n");
            FILE *f2;
            f2 = fopen("medical", "r");
            while ((c = getc(f2)) != EOF)
                printf("%c", c);
            fclose(f2);
            printf("---------------------------------------------------\n");
        }
        else
            printf("Docator has not assigned any medicines!!");
        getch();
        medicalEntry();
        break;
    case 2:
        medicalEntry();
    case 3:
        welcome1();
    default:
        break;
    }
    getch();
}
void receipt()
{
    char c;
    welcome();
    gotoxy(60, 10);
    printf("Receipt");
    gotoxy(20, 11);
    print_Line();
    gotoxy(40, 13);
    printf("Registration No.: %d", start->reg);
    gotoxy(40, 14);
    printf("Name: %s", start->name);
    gotoxy(40, 15);
    printf("Age: %d", start->age);
    gotoxy(40, 16);
    printf("Address: %d", start->address);
    gotoxy(40, 17);
    printf("Phone No.: %d", start->phone);
    gotoxy(40, 18);
    printf("Blood Group: %s", start->bloodgroup);
    gotoxy(40, 19);
    printf("Disease: ");
    switch (start->priority)
    {
    case 1:
        printf("Heart attack");
        break;
    case 2:
        printf("Severe wound/Bleeding");
        break;
    case 3:
        printf("Cancer");
        break;
    case 4:
        printf("Accident");
        break;
    case 5:
        printf("Chest pain");
        break;
    case 6:
        printf("Fracture");
        break;
    case 7:
        printf("Diabetes Checkup");
        break;
    case 8:
        printf("Infection");
        break;
    case 9:
        printf("Viral Fever or cough and cold");
        break;
    case 10:
        printf("Common Cold/Head ache or other Consultation");
        break;
    }
    gotoxy(20, 22);
    print_Line();
    gotoxy(20, 24);
    printf("Take Medicines On Time!!");
    gotoxy(20, 25);
    print_Line();
    gotoxy(80, 29);
    printf("Get Well Soon!!");
}
void print_Line()
{
    for (int j = 0; j <= 50; j++)
    {
        printf("- ");
    }
}