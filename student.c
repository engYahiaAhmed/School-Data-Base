#include"Student.h"
void moveToX_Y(int x,int y)
{
    COORD coord= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void color(int color_val)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,color_val);
}
void string_print(char* str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    //printf("\n");
    //puts(str);
}
void string_scan(char* str )
{
    int i=0;
    scanf(" %c",&str[i]);
    while(str[i]!='\n')
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}
void arr_scan(int* arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        scanf(" %d",&arr[i]);
    }
}
void arr_print(int* arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
/**************************************Auxiliary functions****************************************/
void school_subjectsList(){
    printf("List of Possible School Subjects: \n");
    printf("1-Physics \t 2-MATH \t 3-Geography\n");
    printf("4-English \t 5-Chemistry \t 6-Geometry\n");
    printf("7-History \t 8-Art \t 9-Deutsch\n");
}
void school_printSibling(person_t* sibling)
{
    printf("name: ");
    string_print(sibling->name);
    printf(" \t ");
    printf("Phone number: ");
    string_print(sibling->phone);
    printf(" \t \n\n");
}
void school_scanSibling(person_t* sibling)
{
    printf("name: ");
    string_scan(sibling->name);
    printf("Phone number: ");
    string_scan(sibling->phone);
}
void school_printGuardian(guard_t* guardian)
{
    printf("Student ");
    string_print(guardian->guard);
    printf(" Data: \n");
    printf("name: ");
    string_print(guardian->name);
    printf(" \t ");
    printf("Phone number: ");
    string_print(guardian->phoneNumber);
    printf(" \t ");
    printf("The Address: ");
    string_print(guardian->Address);
    printf(" \t \n\n");
}
void school_scanGuardian(guard_t* guardian)
{
    printf("Phone number: ");
    string_scan(guardian->phoneNumber);
    printf("name: ");
    string_scan(guardian->name);
    fflush(stdin);
    printf("The Address: ");
    string_scan(guardian->Address);
    printf("The guardian : ");
    string_scan(guardian->guard);
}
void school_printSubjects(stud_t* stud)
{
    int i;
    for(i=0; i<Number_of_subjects; i++)
    {
        printf("%d_ ",i+1);
        string_print(stud->subjects[i].name);
        printf("\n");
        printf("\t    max grade: %d \t student grade: %d \n",stud->subjects[i].Max_grade,stud->subjects[i].grade);
    }
}
void school_printSubject(subj_t* sub)
{
    string_print(sub->name);
    printf("\n");
    printf("\t    max grade: %d \t student grade: %d \n",sub->Max_grade, sub->grade);
}
int school_scanSubject(subj_t * sub)
{

    int subjec_id,grade,scanDone=1;
    printf("Enter Subject number: ");
    scanf("%d",&subjec_id);
    switch(subjec_id)
    {
    case 1:
        sub->name="Physics";
        sub->Max_grade=Physics_MAxGRADE;
        printf("Physics max grade: %d \n",Physics_MAxGRADE);
        printf("Enter Physics Student grade: ");
        scanf("%d",&grade);
        while(grade<0||grade>Physics_MAxGRADE)
        {
            printf("Enter a valid Physics Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 2:
        sub->name="MATH";
        sub->Max_grade=MATH_MAxGRADE;
        printf("Math max grade: %d \n",MATH_MAxGRADE);
        printf("Enter Math Student grade: ");
        scanf("%d",&grade);
        while(grade<0||grade>MATH_MAxGRADE)
        {
            printf("Enter a valid MATH Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 3:
        sub->name="Geography";
        sub->Max_grade=Geography_MAxGRADE;
        printf("Geography max grade: %d \n",Geography_MAxGRADE);
        printf("Enter Geography Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>Geography_MAxGRADE)
        {
            printf("Enter a valid Geography Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 4:
        sub->name="English";
        sub->Max_grade=English_MAxGRADE;
        printf("English max grade: %d \n",English_MAxGRADE);
        printf("Enter English Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>English_MAxGRADE)
        {
            printf("Enter a valid English Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 5:
        sub->name="Chemistry";
        sub->Max_grade=Chemistry_MAxGRADE;
        printf("Chemistry max grade: %d \n",Chemistry_MAxGRADE);
        printf("Enter Chemistry Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>Chemistry_MAxGRADE)
        {
            printf("Enter a valid Chemistry Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 6:
        sub->name="Geometry";
        sub->Max_grade=Geometry_MAxGRADE;
        printf("Geometry max grade: %d \n",Geometry_MAxGRADE);
        printf("Enter Geometry Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>Geometry_MAxGRADE)
        {
            printf("Enter a valid Geometry Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 7:
        sub->name="History";
        sub->Max_grade=History_MAxGRADE;
        printf("History max grade: %d \n",History_MAxGRADE);
        printf("Enter History Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>History_MAxGRADE)
        {
            printf("Enter a valid History Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 8:
        sub->name="Art";
        sub->Max_grade=Art_MAxGRADE;
        printf("Art max grade: %d \n",Art_MAxGRADE);
        printf("Enter Art Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>Art_MAxGRADE)
        {
            printf("Enter a valid Art Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    case 9:
        sub->name="Deutsch";
        sub->Max_grade=Geometry_MAxGRADE;
        printf("Deutsch max grade: %d \n",Deutsch_MAxGRADE);
        printf("Enter Deutsch Student grade: ");
        scanf("%d",&grade);
        while(grade<0 || grade>Deutsch_MAxGRADE)
        {
            printf("Enter a valid Deutsch Student grade: ");
            scanf("%d",&grade);
        }
        sub->grade=grade;
        break;
    default :
        printf("Wrong Selection!\n");
        scanDone=0;
        break;
    }
    return scanDone;
}
/****************************************************************************************************/
void school_addStud(stud_t* arr_students)
{
    studentCount++;
    int nOfsiblings;
    printf("Enter Student number %d : \n",studentCount);
    printf("name: ");
    string_scan(arr_students[studentCount-1].name);
    printf("age: ");
    scanf("%d",&arr_students[studentCount-1].age);
    printf("Phone number: ");
    string_scan(arr_students[studentCount-1].phoneNumber);
    system("cls");
    Sleep(1000);
    for(int i=0; i<2; i++)
    {
        printf("Enter Student guardian number %d Data:  \n",i+1);
        school_scanGuardian(&arr_students[studentCount-1].guardian[i]);
    }
    system("cls");
    Sleep(1000);
    printf("How many siblings: ");
    scanf("%d",&nOfsiblings);
    arr_students[studentCount-1].nOfsiblings=nOfsiblings;
    arr_students[studentCount-1].siblings=malloc(nOfsiblings*sizeof(person_t));
    for(int i=0; i<nOfsiblings; i++)
    {
        printf("Enter Student sibling number %d Data:  \n",i+1);
        school_scanSibling(&arr_students[studentCount-1].siblings[i]);

    }
    system("cls");
    Sleep(1000);
    school_subjectsList();
    int i;
    for(i=0; i<Number_of_subjects; i++)
    {
        printf("Subject number %d : \n",i+1);
        school_scanSubject(&arr_students[studentCount-1].subjects[i]);
    }
}
void school_printStud(stud_t* arr_students,int id)
{

    printf("Student number ID number : %d\n",id);
    printf("name: %s\n",arr_students[id-1].name);
    printf("age: %d\n",arr_students[id-1].age);
    printf("Phone number: ");
    string_print(arr_students[id-1].phoneNumber);
    printf("\n**********************************************************\n");
    for(int i=0; i<2; i++)
    {
        school_printGuardian(&arr_students[id-1].guardian[i]);
    }
    for(int i=0; i<arr_students[id-1].nOfsiblings; i++)
    {
        printf("Sibling number %d Data: \n",i+1);
        school_printSibling(&arr_students[id-1].siblings[i]);
    }
    int i;
    for(i=0; i<Number_of_subjects; i++)
    {
        printf("%d_ ",i+1);
        school_printSubject(&arr_students[id-1].subjects[i]);
    }

}
void school_EditStudWithID(stud_t* arr_students,int id)
{
    int choice,choice2,i;
    school_printStud(arr_students,id);
//print the data of student
    printf(">>Choose Which part will be edited: \n");
    printf("1_ student data \n");
    printf("2_ siblings data \n");
    printf("3_ subjects data \n");
    printf("4_ guardian data \n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    system("cls");
    Sleep(500);
    switch(choice)
    {
    case 1:
        printf("Student ID: %d\n",id);
        printf("1-name: ");
        string_print(arr_students[id-1].name);
        printf("\n2-Phone number: ");
        string_print(arr_students[id-1].phoneNumber);
        printf("\n3-age: %d\n",arr_students[id-1].age);
        printf("\n**********************************************************\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        school_callStud(9);
        Sleep(2000);
        system("cls");
        Sleep(500);
        color(7);
        switch(choice)
        {
        case 1:
            printf("name: ");
            string_scan(arr_students[id-1].name);
            break;
        case 2:
            printf("Phone number: ");
            string_scan(arr_students[id-1].phoneNumber);
            break;
        case 3:
            printf("age: ");
            scanf("%d",&arr_students[id-1].age);
            break;
        default:
            printf("Wrong choice!\n");
            break;
        }
        break;
    case 2:
        printf("Student ID: %d\n",id);
        printf("1-name: ");
        string_print(arr_students[id-1].name);
        printf("\n");
        for(i=0; i<arr_students[id-1].nOfsiblings; i++)
        {
            printf(">>Sibling number %d data : \n",i+1);
            school_printSibling(&arr_students[id-1].siblings[i]);
        }
        printf("Enter sibling number to edit: ");
        scanf("%d",&choice);
        school_callStud(9);
        Sleep(2000);
        color(7);
        system("cls");
        Sleep(500);
        school_printSibling(&arr_students[id-1].siblings[choice-1]);
        printf("1_Nmae : \n");
        printf("2_Phone Number : \n");
        printf("3_Replace sibling : \n");
        printf("Enter your choice: ");
        scanf("%d",&choice2);

        switch(choice2)
        {
        case 1:
            printf("name: ");
            string_scan(arr_students[id-1].siblings[choice-1].name);
            break;
        case 2:
            printf("Phone number: ");
            string_scan(arr_students[id-1].siblings[choice-1].phone);
            break;
        case 3:
            printf("Replace sibling: \n");
            school_scanSibling(&arr_students[id-1].siblings[choice-1]);
            break;
        default:
            printf("Wrong choice!\n");
            break;
        }
        break;
    case 3:
        school_printSubjects(&arr_students[id-1]);
        printf("Enter Subject number to edit: ");
        scanf("%d",&choice);
        school_printSubject(&arr_students[id-1].subjects[choice-1]);
        printf("\n");
        printf("1_Replace Subject with another subject : \n");
        printf("2_Edit Subject Grade   : \n");
        printf("Enter your choice: ");
        scanf("%d",&choice2);
        school_callStud(21);
        color(7);
        switch(choice2)
        {
        case 1:
            system("cls");
            Sleep(500);
            school_subjectsList();
            school_scanSubject(&arr_students[id-1].subjects[choice-1]);
            break;
        case 2:
            printf("Grade: ");
            scanf("%d",&arr_students[id-1].subjects[choice-1].grade);
            break;
        default:
            printf("Wrong choice!\n");
            break;
        }
        break;
    case 4:
        for(int i=0; i<2; i++)
        {
            printf("Guardian number %d Data: \n",i+1);
            school_printGuardian(&arr_students[id-1].guardian[i]);
        }
        printf("Enter Guardian number to edit: ");
        scanf("%d",&choice);
        school_callStud(9);
        color(7);
        system("cls");
        Sleep(500);
        school_printGuardian(&arr_students[id-1].guardian[choice-1]);
        printf("1_Nmae : \n");
        printf("2_Phone Number : \n");
        printf("3_Address : \n");
        printf("4_Replace Guardian : \n");
        printf("Enter your choice: ");
        scanf("%d",&choice2);
        school_callStud(8);
        color(7);
        switch(choice2)
        {
        case 1:
            printf("\nname: ");
            string_scan(arr_students[id-1].guardian[choice-1].name);

            break;
        case 2:
            printf("\nPhone number: ");
            string_scan(arr_students[id-1].guardian[choice-1].phoneNumber);
            break;
        case 3:
            printf("\nAddress: ");
            string_scan(arr_students[id-1].guardian[choice-1].Address);
            break;
        case 4:
            printf("\nNew guardian: \n");
            school_scanGuardian(&arr_students[id-1].guardian[choice-1]);
            break;
        default:
            printf("\nWrong choice!\n");
            break;
        }


    }
//choose which part will be edited (with switch case)
//print after editing.
//yehia
}
void school_callStud(int line){
    int i,j,c=5,col=8;
    moveToX_Y(0,line);
    for(i=0; i<20; i++)
    {
        if(i%4==0)
        {
            col++;
            color(col);
        }
        printf(",");
        Sleep(120);
    }
    for(j=20; j>=0; j--)
    {
        moveToX_Y(j,line);
        printf("  ");
        Sleep(120);
    }
    col=8;
    moveToX_Y(0,line);
    for(i=0; i<5; i++)
    {
        printf(",");
        Sleep(120);
    }
    while(c>0)
    {
        moveToX_Y(4,line);
        color(10);
        for(i=5; i<22+c; i++)
        {
            if(i%4==0)
            {
                col++;
                color(col);
            }
            printf(",");
            Sleep(160);
        }
        for(j=21+c; j>=5; j--)
        {
            moveToX_Y(j,line);
            printf("  ");
            Sleep(160);
        }
        col=5+c;
        c--;
    }
    moveToX_Y(4,line);
    for(i=5; i<20; i++)
    {
        if(i%4==0)
        {
            col++;
            color(col);
        }
        printf(",");
        Sleep(160);
    }
//     printf("To call with Name Enter 1 ");
//    printf("To call with ID Enter 2 ");
//    printf("student phone number");
    //yehia
}
