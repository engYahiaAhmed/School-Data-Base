/************************************************/
/* Title       : Student Program File           */
/* Author      : Shrooq Mahmoud & Yahia Ahmed   */
/* Release     : 1.0                            */
/* Last Update : Oct 5, 2022                    */
/************************************************/
#include "student.h"
#include "FILE_R_W_D_H.h"

const char* health_input_format="(%[^,], %d, %d)\n";
const char* Student_input_format="(%[^,], %d, %[^,], %d)\n";
const char* slib_input_format="(%[^,], %[^)])\n";
const char* guard_input_format="(%[^,], %[^,], %[^,], %[^)])\n";
const char* sub_input_format="(%[^,], %d, %d)\n";
const char* slib_output_format="(%s, %s)\n";
const char* Student_output_format="(%s, %d, %s, %d)\n";
const char* health_output_format="(%s, %d, %d)\n";
const char* guard_output_format="(%s, %s, %s, %s)\n";
const char* sub_output_format="(%s, %d, %d)\n";
const char* school_arrMandatorySub[max_number_of_class][20]=
{
    {"Physics","English","Chemistry","MATH"},
    {"Economics","Psychology","Political","English II"},
    {"Biology","Speech","Zoology","Philosophy"},
    {"Algebra","Statistics","Biology","English III"},
    {"Geology","Physics","Astronomy","Ecology"},
    {"Accounting","Calculus","Algebra II","Arabic"}
};
int school_arrMandatorymaxGrade[4] = {Physics_MAxGRADE,English_MAxGRADE,Chemistry_MAxGRADE,MATH_MAxGRADE};
int school_arrElectivemaxGrade[5]  = {Geography_MAxGRADE,Geometry_MAxGRADE,History_MAxGRADE,Art_MAxGRADE,Deutsch_MAxGRADE};
int studentClassCount[max_number_of_class];
stud_t school[max_number_of_class][max_student_number];
const char* school_arrElectiveSub[max_number_of_class][20]=
{
    {"Sports","Art","Music","AlgebraI","French"},
    {"Literature","Poetry","Dance","Art II","Spanish"},
    {"Painting","Geometry","History","ArtII","Deutsch"},
    {"Media","Mechanics","LOGIC","Yoga","Deutsch II"},
    {"Economics","Calculus2","Psychology","Sports","Latin"},
    {"Geography","technology","History","Health","Social"}
};
/******************************************************************************/

int school_SearchWithName_one(char* s,int classNum,int print)
{
    int i,index=-1,numbStudent;
    numbStudent=studentClassCount[classNum-1];
    for(i=0; i<numbStudent; i++)
    {
        if(String_Compare_one(school[classNum-1][i].name,s))
        {
            index=i;
        }
    }
    if(index!=-1)
    {
        return index;
    }
    else
    {
        return -1;
    }
}
int school_SearchWithName(char* s,int classNum,int print)
{
    int i,index=0,count=0;
    for(i=0; i<studentClassCount[classNum-1]; i++)
    {
        if(String_Compare(school[classNum-1][i].name,s))
        {
            //if you want to print the name set print to 1.
            if(print==1)
            {
                printf("Name : ");
                string_print(school[classNum-1][i].name);
                printf("\t\t ID: %d",i+1);
                printf("\n");
            }
            count++;
            index=i;
        }
    }

    if(count>1)
    {
        //means their is many student with the same name.
        return -2;
    }
    else if(count==1)
    {
        //send the index of name.
        return index;
    }
    else
    {
        //means their is no one with this name.
        return -1;
    }
}
void school_printSubjects(stud_t* stud)
{
    int i;
    for(i=0; i<Number_of_subjects; i++)
    {
        color(title_color);
        printf("%d_ ",i+1);
        color(title_color);
        string_print(stud->subjects[i].name);
        printf("\n");
        color(data_color);
        printf("\t    max grade: %d \t student grade: %d\n",stud->subjects[i].Max_grade,stud->subjects[i].grade);

    }
}

void school_HealthInformation(int classNum,int id)
{
    char choice,flag=0;
    color(mainTitleColor);
    printf("\t\t\t\t \x11 Health Information: \x10\n\n");
    color(title_color);
    printf("Height: ");
    color(data_color);
    scanf("%d",&school[classNum-1][id-1].healthcare.height);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    color(title_color);
    printf("Weight: ");
    color(data_color);
    scanf("%d",&school[classNum-1][id-1].healthcare.weight);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    while(!flag)
    {
        printf("Do you have any chronic diseases: Y/N\n");
        scanf(" %c",&choice);
        fflush(stdin);
        if(choice =='n' || choice=='N')
        {
            flag=1;
        }
        else if(choice =='y' || choice=='Y')
        {
            color(title_color);
            printf("Disease Name: ");
            color(data_color);
            string_scan(school[classNum-1][id-1].healthcare.disease);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            flag=1;
        }
        else
        {
            color(0xc);
           PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            printf("Wrong Selection, Enter the right selection.\n");
            Sleep(1000);
        }
    }
}

void school_printStud(stud_t* stud,int id)
{
    color(mainTitleColor);
    printf("Name:");
    color(data_color);
    printf(" ");
    string_print(stud->name);
    printf("    \t\t");
    color(title_color);
    color(mainTitleColor);
    printf("ID :");
    color(data_color);
    printf(" ");
    printf("%d",id);
    printf("\n");
    color(mainTitleColor);
    printf("age:");
    color(data_color);
    printf(" ");
    printf("%d\t\t\t\t",stud->age);
    color(mainTitleColor);
    printf("Phone number:");
    color(data_color);
    printf(" ");
    string_print(stud->phoneNumber);
    printf("\n**********************************************************\n");
    color(mainTitleColor);
    // printf("%s \t %d \t %d\n",stud->healthcare.disease,stud->healthcare.height,stud->healthcare.weight);
    Health_Print(&stud->healthcare);
    color(data_color);
    printf("\n**********************************************************\n");
    int i;
    for(i=0; i<2; i++)
    {
        school_printGuardian(&stud->guardian[i]);
    }
    printf("**********************************************************\n");
    for(i=0; i<stud->nOfsiblings; i++)
    {
        color(mainTitleColor);
        printf("Sibling number %d Data",i+1);
        color(data_color);
        printf(":\n");
        school_printSibling(&stud->siblings[i]);
    }
    printf("**********************************************************\n");
    for(i=0; i<Number_of_subjects; i++)
    {

        color(11);
        printf("%d_ ",i+1);
        school_printSubject(&stud->subjects[i]);
    }
    color(data_color);
    printf("\n**********************************************************\n");
    color(mainTitleColor);
    printf("Max Score :");
    color(data_color);
    printf(" 300\t\t\t ");
    color(mainTitleColor);
    printf("Total Score :");
    color(data_color);
    printf(" ");
    printf("%d\n",stud->totalgrade);
    printf("**********************************************************\n");

}


/*************************************Print**********************************/
void school_printSibling(person_t* sibling)
{
    color(title_color);
    printf("name: ");
    color(data_color);
    string_print(sibling->name);
    printf(" \t ");
    color(title_color);
    printf("Phone number: ");
    color(data_color);
    string_print(sibling->phone);
    printf(" \t \n\n");
}
void school_printGuardian(guard_t* guardian)
{

    color(data_color);
    printf("Student ");
    color(mainTitleColor);
    string_print(guardian->guard);
    color(data_color);
    printf(" Data:");
    color(title_color);
    printf("\nname: ");
    color(data_color);
    string_print(guardian->name);
    printf(" \t ");
    color(title_color);
    printf("Phone number: ");
    color(data_color);
    string_print(guardian->phoneNumber);
    printf(" \t ");
    color(title_color);
    printf("The Address: ");
    color(data_color);
    string_print(guardian->Address);
    printf(" \t \n\n");
}
void Health_Print(health_t* h)
{
    color(mainTitleColor);
    printf("Height:");
    color(data_color);
    printf(" ");
    printf("%d",h->height);
    color(mainTitleColor);
    printf("\t\tWeight:");
    color(data_color);
    printf(" ");
    printf("%d",h->weight);
    color(mainTitleColor);
    printf("\t\tDisease:");
    color(data_color);
    printf(" ");
    string_print(h->disease);
}
void school_printSubject(subj_t* sub)
{
    color(15);
    string_print(sub->name);
    printf("\n");
    color(title_color);
    printf("\t    max grade: ");
    color(data_color);
    printf("%d \t ",sub->Max_grade);
    color(title_color);
    printf("student grade: ");
    color(data_color);
    printf("%d \n", sub->grade);
}
void school_PersonalInformation(int classNum)
{
    int nOfsiblings;
    color(data_color);
    printf("\n\t\t\t\t \x11 Class %d \x10\n\n",classNum);
    printf("\t\t\t   ");
    color(mainTitleColor1);
    printf("Enter Student number %d Data: \n",studentClassCount[classNum-1]+1);
    color(title_color);
    printf("Name: ");
    color(data_color);
    string_scan(school[classNum-1][studentClassCount[classNum-1]].name);
    color(title_color);
    printf("Age: ");
    color(data_color);
    scanf("%d",&school[classNum-1][studentClassCount[classNum-1]].age);
    color(title_color);
    printf("Phone number: ");
    color(data_color);
    string_scan(school[classNum-1][studentClassCount[classNum-1]].phoneNumber);
    printf("\n\t\t==============================================================\n");
//    Sleep(1000);
//    system("cls");

    int i;
    for(i=0; i<2; i++)
    {
        color(mainTitleColor1);
        printf("\t\t\t   Enter Student guardian number %d Data:  \n\n",i+1);
        school_scanGuardian(&school[classNum-1][studentClassCount[classNum-1]].guardian[i]);
    }
    Sleep(400);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    system("cls");
    printf("\n\t\t==============================================================\n");

    printf("\t\t\t     ");
    color(mainTitleColor1);
    printf("Student Siblings Data:  ");
    color(data_color);
    printf("\n");
    color(mainTitleColor);
    printf("\nHow many siblings:");
    color(data_color);
    printf(" ");
    scanf("%d",&nOfsiblings);
    fflush(stdin);
    Sleep(200);
    if(nOfsiblings > 10 || nOfsiblings==0)
    {
        color(0xc);
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        school[classNum-1][studentClassCount[classNum-1]].nOfsiblings=0;
        system("cls");
        printf("\n\n\n\t\t\t\t>>The max number of student should not exceeded ten!");
        Sleep(1000);
        system("cls");

        return;
    }

    school[classNum-1][studentClassCount[classNum-1]].nOfsiblings=nOfsiblings;
    school[classNum-1][studentClassCount[classNum-1]].siblings=malloc(nOfsiblings*sizeof(person_t));

    for(i=0; i<nOfsiblings; i++)
    {
        printf("\n\t\t\t  ");
        color(mainTitleColor1);
        printf("Enter Student sibling number %d Data:",i+1);
        color(title_color);
        printf(" \n");
        school_scanSibling(&school[classNum-1][studentClassCount[classNum-1]].siblings[i]);
    }
    Sleep(100);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    system("cls");

}
void school_SubjectInformation(int classNum)
{
    int lastSubID=0,subjec_id,i;
    system("cls");
    color(data_color);
    printf("\t\t\t\t \x11 Subject Information: \x10\n\n");
    color(title_color);
    printf("\n");
    Sleep(500);
    for(i=0; i<4; i++)
    {
        school_scanMandatorySub(&school[classNum-1][studentClassCount[classNum-1]].subjects[i],classNum,i);
        school[classNum-1][studentClassCount[classNum-1]].totalgrade+=school[classNum-1][studentClassCount[classNum-1]].subjects[i].grade;
    }
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    school_subjectsList(classNum);
    for(i=4; i<Number_of_subjects; i++)
    {
        color(mainTitleColor);
        printf("\t\t\t\tSubject number %d : \n",i+1);
        subjec_id=school_scanElectiveSub(&school[classNum-1][studentClassCount[classNum-1]].subjects[i],classNum,lastSubID);
        school[classNum-1][studentClassCount[classNum-1]].totalgrade+=school[classNum-1][studentClassCount[classNum-1]].subjects[i].grade;
//       printf("%d\n",school[classNum-1][studentClassCount[classNum-1]].totalgrade);
        lastSubID=subjec_id;
    }
}
void school_subjectsList(int classNum)
{
    color(mainTitleColor);
    printf("\t\t\t\tList of Possible School Subjects: \n");

    color(15);

    switch(classNum)
    {
    case 1:

        printf("1-Sports \t 2-Art \t 3-Music\n");
        printf("4-AlgebraI\t 5-French\n\n");
        break;
    case 2:
        printf("1-Literature \t 2-Poetry \t 3-Dance\n");
        printf("4-Art II      \t 5-Spanish\n\n");
        break;
    case 3:
        printf("1-Painting \t 2-Geometry \t 3-History\n");
        printf("4-Art II    \t 5-Deutsch\n\n");
        break;
    case 4:
        printf("1-Media \t 2-Mechanics \t 3-LOGIC\n");
        printf("4-Yoga   \t 5-Deutsch II\n\n");
        break;
    case 5:
        printf("1-Economics \t 2-Ancient History \t 3-Psychology\n");
        printf("4-Sports        \t 5-Latin\n\n");
        break;
    case 6:
        printf("1-Geography \t 2-technology \t 3-History\n");
        printf("4-Health     \t 5-Social \n\n");
        break;
    }

}

//to print any section, set its value when you call the function.
void school_printStud2(stud_t* s,int Gaurdflag,int Siblingsflag,int Subjectflag,int Healthflag)
{
    color(title_color);
    printf("\tName: ");
    color(data_color);
    string_print(s->name);
    printf("\n");
    color(title_color);
    printf("age: ");
    color(data_color);
    printf("%d ",s->age);
    color(title_color);
    printf("\t\t\t\tPhone: ");
    color(data_color);
    string_print(s->phoneNumber);
    printf("\n**********************************************************\n");
    if(Gaurdflag)
    {
        color(mainTitleColor);
        printf("\t\t\t\x11 GAURDIAN INFORMATION \x10");
        color(data_color);
        printf("\n");
        int i;
        for(i=0; i<2; i++)
        {
            school_printGuardian(&s->guardian[i]);
        }
        printf("**********************************************************\n");
    }

    if(Siblingsflag)
    {
        printf("\t\t        \t");
        color(mainTitleColor);
        printf("\x11 SIBLINGS INFORMATION \x10");
        color(data_color);
        printf("\n");
        int i;
        for(i=0; i<s->nOfsiblings; i++)
        {
            color(title_color);
            printf("Sibling number %d Data:",i+1);
            color(data_color);
            printf("\n");
            school_printSibling(&s->siblings[i]);
            color(data_color);
        }
        printf("**********************************************************\n");
    }
    if(Subjectflag)
    {
        color(mainTitleColor);
        printf("\t\t\x11SUBJECT INFORMATION\x10");
        color(data_color);
        printf("\n");
        int i;
        for(i=0; i<Number_of_subjects; i++)
        {

            color(11);
            printf("%d_ ",i+1);
            school_printSubject(&s->subjects[i]);
        }
        printf("\nTotal Grade: ");
        printf("%d\n",s->totalgrade);
        printf("**********************************************************\n");
    }

    if(Healthflag)
    {
        color(mainTitleColor);
        printf("\t\t\x11HEALTH INFORMATION\x10\n");
        Health_Print(&s->healthcare);
        printf("\n**********************************************************\n");
    }
}

/**********************************************************************************/

void school_addStud()
{
    int classNum;
    color(mainTitleColor);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    if(classNum<=0||classNum>max_number_of_class)
    {
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        Sleep(1000);
        return;
    }
    school_PersonalInformation(classNum);
    Sleep(500);
    system("cls");
    school_HealthInformation(classNum,studentClassCount[classNum-1]+1);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    Sleep(500);
    school_SubjectInformation(classNum);
    Sleep(500);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    school_WriteFile(&school[classNum-1][studentClassCount[classNum-1]],classNum);
    studentClassCount[classNum-1]++;
}
void school_AllPrint()
{
    int choice,flag=0,classNum,choice1,i,selectionFlag;
    color(title_color);
    printf("1.Print Specific Class.\n");
    printf("2.Print All School.\n");
    color(0xf);
    printf("\n>>Enter your choice: ");
    color(data_color);
    scanf("%d",&choice);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    fflush(stdin);
    switch(choice)
    {
    case 1:
        while(!flag)
        {
            color(0xf);
            printf("Enter Number of class: ");
            color(data_color);
            scanf("%d",&classNum);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            if(classNum>0 && classNum<=max_number_of_class)
            {
                class_AllPrint(classNum,1);
                flag=1;
            }
            else
            {
                PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                color(0xc);
                printf("Not Found, To continue press 1, To exit press 0:  ");
                system("cls");
                Sleep(1000);
                color(data_color);
                scanf("%d",&choice1);
                fflush(stdin);
                if(choice1==1)
                {
                    flag=0;
                }
                else
                {
                    flag=1;
                }
            }
        }

        break;

    case 2:
        selectionFlag=1;
        for(i=0; i<max_number_of_class; i++)
        {
            if(studentClassCount[i]!=0)
            {
                class_AllPrint(i+1,selectionFlag);

                selectionFlag=0;
            }
        }
        break;
    }
}
void class_AllPrint(int classNum,int print)
{
    int i,studentNum,choice1=1,choice;
    studentNum=studentClassCount[classNum-1];
    static char flags[4]= {0};
    if(print)
    {
        system("cls");
        for(i=0; i<4; i++)
        {
            flags[i]=0;
        }
        while(choice1)
        {
            printf("1.Print Guardian Information.\n");
            printf("2.Print Siblings Information.\n");
            printf("3.Print Subject Information.\n");
            printf("4.Print Health Information.\n");
            color(0xf);
            printf("\n>>Enter your choice: ");
            color(data_color);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            scanf("%d",&choice);
            fflush(stdin);
            if(choice>0&&choice<4)
            {
                flags[choice-1]=1;
            }
            color(0xf);
            printf("To print more information press 1, To exit press 0: ");
            color(data_color);
            scanf("%d",&choice1);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            fflush(stdin);
        }
        Sleep(100);
        system("cls");
    }
    color(data_color);
    printf("\n\t\t\t    \x11 ");
    color(mainTitleColor1);
    printf(" Class %d",classNum);
    color(data_color);
    printf(" \x10");
    printf("\n\n\t\t  *********************************");
    for(i=0; i<studentNum; i++)
    {
        color(data_color);
        printf("\n\t\t  *********************************\n");
        printf("\t\t\t  ");
        color(mainTitleColor);
        printf("\x11 %s \x10",school[classNum-1][i].name);
        color(data_color);
        printf("\n\n\t\t  *********************************\n");
        color(title_color);
        printf("Student ID : ");
        color(data_color);
        printf("%d\t\t\t",i+1);
        school_printStud2(&school[classNum-1][i],flags[0],flags[1],flags[2],flags[3]);
    }
}


void Student_ShiftList(stud_t* class1,int classNum,int id)
{
    int i;
    int studentNum=studentClassCount[classNum-1];
    school_Delete_Data_File(classNum,id);
    for(i=id-1; i<studentNum-1; i++)
    {
        class1[i]=class1[i+1];
    }

    studentClassCount[classNum-1]--;
}
/*************************************Scan**************************************/
void school_scanSibling(person_t* sibling)
{
    color(title_color);
    printf("Name: ");
    color(data_color);
    string_scan(sibling->name);
    color(title_color);
    printf("Phone number: ");
    color(data_color);
    string_scan(sibling->phone);
}
void school_scanGuardian(guard_t* guardian)
{
    color(title_color);
    printf("Name: ");
    color(data_color);
    string_scan(guardian->name);
    color(title_color);
    printf("Phone number: ");
    color(data_color);
    string_scan(guardian->phoneNumber);
    color(title_color);
    printf("The Address: ");
    color(data_color);
    string_scan(guardian->Address);
    color(title_color);
    printf("Relation : ");
    color(data_color);
    string_scan(guardian->guard);
}
void school_scanMandatorySub(subj_t * sub,int classNum,int index)
{
    int grade;
    color(mainTitleColor1);
    printf("\t\t\t\tSubject number %d :\n\t\t\t\t",index+1);
    strcpy(sub->name,school_arrMandatorySub[classNum-1][index]);
    sub->Max_grade=school_arrMandatorymaxGrade[index];
    color(mainTitleColor);
    string_print(school_arrMandatorySub[classNum-1][index]);
    color(title_color);
    printf(" max grade:");
    color(data_color);
    printf(" %d \n",school_arrMandatorymaxGrade[index]);
    color(title_color);
    printf("Enter Student grade: ");
    color(data_color);
    scanf("%d",&grade);
    while(grade<0 ||grade>school_arrMandatorymaxGrade[index])
    {
        color(mainTitleColor);
        printf("\t\t\t\tEnter a valid Student grade:\n");
        color(title_color);
        printf("Enter Student grade: ");
        color(data_color);
        scanf("%d",&grade);
    }
    sub->grade=grade;
}
int school_scanElectiveSub(subj_t * sub,int classNum,int lastSubID)
{
    int subjec_id,grade;
    color(title_color);
    printf("Enter Subject number: ");
    color(data_color);
    scanf("%d",&subjec_id);
    while(subjec_id >5 || subjec_id <1 || subjec_id==lastSubID)
    {
        color(mainTitleColor);
        printf("\t\t\t\tEnter a valid Selection :");
        color(title_color);
        printf("\nEnter Subject number: ");
        color(data_color);
        scanf("%d",&subjec_id);
    }
    strcpy(sub->name, school_arrElectiveSub[classNum-1][subjec_id-1]);
    sub->Max_grade=school_arrElectivemaxGrade[subjec_id-1];
    printf("\t\t\t\t");
    color(mainTitleColor);
    string_print(school_arrElectiveSub[classNum-1][subjec_id-1]);
    color(title_color);
    printf(" max grade:");
    color(15);
    printf("%d \n",school_arrElectivemaxGrade[subjec_id-1]);
    color(title_color);
    printf("Enter Student grade: ");
    color(data_color);
    scanf("%d",&grade);
    while(grade<0 ||grade>school_arrElectivemaxGrade[subjec_id-1])
    {
        color(mainTitleColor);
        printf("\t\t\t\tEnter a valid %s grade:",school_arrElectiveSub[classNum-1][subjec_id-1]);
        color(title_color);
        printf("\nEnter Student grade: ");
        color(data_color);
        scanf("%d",&grade);
    }
    sub->grade=grade;
    return subjec_id;
}

void school_swithchCasePrintStudent()
{
    int choice,choice1,id,searchCase,classNum,flag=1,index;
    char name [30];
    color(mainTitleColor1);
    printf(">> Enter Student Class Number:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    system("cls");
    Sleep(100);
    color(data_color);
    printf("\x4 1 > To search with name : \n");
    printf("\x4 2 > To search with ID : \n");
    printf("\x4 3 > To get back : \n\n");
    color(15);
    printf(">> Enter your choice: ");
    color(data_color);
    scanf("%d",&choice);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    fflush(stdin);
    color(title_color);
    fflush(stdin);
    Sleep(200);
    system("cls");
    color(data_color);
    printf("\t\t\t\t \x11 Class %d \x10\n\n",classNum);
    switch(choice)
    {
    case 1:
        while(flag)
        {
            flag=0;
            printf(">> Enter student name: ");
            string_scan(name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            searchCase=school_SearchWithName(name,classNum,0);
            if(searchCase>=0)
            {
                school_printStud(&school[classNum-1][searchCase],searchCase+1);
            }
            else if(-2==searchCase)
            {

                color(15);
                printf("\x11 There are a number of students with the same name...\n\n");
                color(10);
                printf(" \x4 To print the list with ID, Enter >>> 1 \n");
                printf(" \x4 To re-enter the whole name, Enter >>> 2 \n");
                printf(" \x4 To get back, Enter any other numbers \n");
                color(7);
                printf("  >>Enter your choice: ");
                scanf("%d",&choice);
                PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                if(choice==1)
                {
                    Sleep(100);
                    system("cls");
                    color(7);
                    school_SearchWithName(name,classNum,1);
                    printf("\n>> Enter student ID To print its data: ");
                    scanf("%d",&id);
                    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                    school_printStud(&school[classNum-1][id-1],id);
                }
                else if(choice==2)
                {
                    printf("Name: ");
                    string_scan(name);
                    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                    index=school_SearchWithName_one(name,classNum,0);

                    if(index>=0)
                    {
                        school_printStud(&school[classNum-1][index],index+1);
                    }
                    else
                    {
                        printf("Wrong Name, To continue press 1, to exit press 0: ");
                        scanf("%d",&choice1);
                        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                        fflush(stdin);
                        if(choice1==1)
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                }
            }
            else if(-1==searchCase)
            {
                 color(0xc);
                 PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                 printf("\n\nStudent Not Found!\n");
                 Sleep(1000);
            }
        }
        break;
    case 2:
        printf("\n>> Enter student ID To print its data: ");
        scanf("%d",&id);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        printf("\n");
        school_printStud(&school[classNum-1][id-1],id);
        break;
    case 3:
        break;
    default:
        Sleep(100);
        color(0xc);
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        printf("Wrong Choice!");
        Sleep(1000);
        break;
    }
}

void Student_DeleteWithName(stud_t* class1,int classNum,char* name)
{
    int index=-1,flag=1,choice,id;
    char name1[30];
    index=school_SearchWithName(name,classNum,0);
    //  printf("index: %d\n",index);
    while(flag)
    {
        if(index>=0)
        {
            Student_ShiftList(class1,classNum,index+1);
            return;
        }
        else if(index==-2)
        {
            color(15);
            printf("\x11 There are a number of students with the same name...\n\n");
            color(10);
            printf(" \x4 To print the list with ID, Enter >>> 1 \n");
            printf(" \x4 To re-enter the whole name, Enter >>> 2 \n");
            printf(" \x4 To get back, Enter any other numbers \n");
            color(7);
            printf("  >>Enter your choice: ");
            scanf("%d",&choice);
            if(choice==1)
            {
                Sleep(100);
                system("cls");
                color(7);
                school_SearchWithName(name,classNum,1);
                printf("\n>> Enter student ID To Delete its data: ");
                scanf("%d",&id);
                Student_ShiftList(class1,classNum,id);
                return;
            }
            else if(choice==2)
            {
                printf("Name: ");
                string_scan(name1);
                index=school_SearchWithName_one(name1,classNum,0);

                if(index>=0)
                {
                    Student_ShiftList(class1,classNum,index+1);
                    return ;
                }
                else
                {
                    printf("Wrong Name, To continue press 1, to exit press 0: ");
                    scanf("%d",&flag);
                    fflush(stdin);

                }
            }
        }
        else if(index==-1)
        {
            printf("Please enter the correct name.\n");
            string_scan(name1);
        }
        index=school_SearchWithName(name1,classNum,0);
    }
}
void Student_DeleteWithID(stud_t* class1,int classNum,int id)
{
    Student_ShiftList(&class1[classNum-1],classNum,id);
}
void school_DeleteStudent()
{

    int choice,flag=1,choice1=1;
    char name[30];
    int id;
    int classNum;
    color(10);
    printf("Enter Student number class: ");
    color(data_color);
    scanf("%d",&classNum);
    flag=(classNum<=max_number_of_class && classNum>0)?1:0;
    if(!flag)
    {
        // PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("Not Found.\n");
    }
    while(flag==1)
    {
        color(title_color);
        printf("1.Delete with Name of Student.\n");
        printf("2.Delete with Id of Student.\n");
        color(data_color);
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
        case 1:
            color(title_color);
            printf("Name of Student: ");
            color(data_color);
            string_scan(name);
            Student_DeleteWithName(school[classNum-1],classNum,name);
            color(0xc);
            printf("Delete Done.\n");
            flag=0;
            break;
        case 2:
            while(choice1)
            {
                color(title_color);
                printf("ID is: ");
                color(data_color);
                scanf("%d",&id);
                fflush(stdin);
                if(id<=studentClassCount[classNum-1])
                {
                    Student_DeleteWithID(school[classNum-1],classNum,id);
                    choice1=0;
                    flag=0;
                }
                else
                {
                    // PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                    color(0xc);
                    printf("Wrong ID, To continue Press 1, To Exit Press 0: \n");
                    color(data_color);
                    scanf("%d",&choice1);
                    fflush(stdin);
                    flag=0;
                }
            }
            break;
        default:
            // PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            color(0xc);
            printf("Wrong Selection, To continue Press 1, To Exit Press 0: ");
            color(data_color);
            scanf("%d",&flag);
            break;
        }
    }
}
/*****************************************************************************/
void school_EditStudWithID(int id,int classNum)
{
    int choice,choice2,i,subID,flag=1;
    char* subName;
    // school_printStud(arr_students,id);
    //print the data of student
    color(mainTitleColor);
    printf(">>Choose Which part will be edited:");
    printf(" \n");
    color(data_color);
    printf("1_ student data \n");
    printf("2_ siblings data \n");
    printf("3_ subjects data \n");
    printf("4_ guardians data \n");
    printf("5_ Health Information \n");
    printf("6_ To get back\n\n");
    color(15);
    printf("Enter your choice: ");
    color(data_color);
    scanf("%d",&choice);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    fflush(stdin);
    system("cls");
    Sleep(500);
    if(choice!=6)
    {

        color(data_color);
        printf("\t\t\t\t      \x11 Class %d \x10 \n\n\t",classNum);
        printf("     ");
        color(mainTitleColor);
        printf("Name:");
        color(data_color);
        printf(" ");
        string_print(school[classNum-1][id-1].name);
        printf("\t\t\t\t\t");
        color(mainTitleColor);
        printf("ID:");
        color(data_color);
        printf(" ");
        printf("%d\n\n",id);
    }
    switch(choice)
    {
    case 1:
        color(title_color);
        printf("Student ID: ");
        color(data_color);
        printf("%d\n",id);
        color(title_color);
        printf("1-name: ");
        color(data_color);
        string_print(school[classNum-1][id-1].name);
        color(title_color);
        printf("\n2-Phone number: ");
        color(data_color);
        string_print(school[classNum-1][id-1].phoneNumber);
        color(title_color);
        printf("\n3-age: ");
        color(data_color);
        printf("%d\n",school[classNum-1][id-1].age);
        printf("\n\t\t******************************************************\n");
        color(title_color);
        printf("Enter your choice: ");
        color(data_color);
        scanf("%d",&choice);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        system("cls");
        Sleep(500);
        switch(choice)
        {
        case 1:
            color(title_color);
            printf("name: ");
            color(data_color);
            string_scan(school[classNum-1][id-1].name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 2:
            color(title_color);
            printf("Phone number: ");
            color(data_color);
            string_scan(school[classNum-1][id-1].phoneNumber);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 3:
            color(title_color);
            printf("age: ");
            color(data_color);
            scanf("%d",&school[classNum-1][id-1].age);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        default:
            color(0xc);
            PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            printf("\n\n\n\n\t\t\t\tWrong selection!\n");
            break;
        }
        break;
    case 2:
        for(i=0; i<school[classNum-1][id-1].nOfsiblings; i++)
        {
            color(mainTitleColor);
            printf(">>Sibling number %d data :",i+1);
            printf("\n");
            school_printSibling(&school[classNum-1][id-1].siblings[i]);
        }
        color(title_color);
        printf("Enter a sibling number to edit: ");
        color(data_color);
        scanf("%d",&choice);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        system("cls");
        Sleep(500);
        school_printSibling(&school[classNum-1][id-1].siblings[choice-1]);
        color(title_color);
        printf("1_Name : \n");
        printf("2_Phone Number : \n");
        printf("3_Replace sibling : \n\n");
        printf(">>Enter your choice: ");
        color(data_color);
        scanf("%d",&choice2);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        fflush(stdin);
        switch(choice2)
        {
        case 1:
            color(title_color);
            printf("Name: ");
            color(data_color);
            string_scan(school[classNum-1][id-1].siblings[choice-1].name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 2:
            color(title_color);
            printf("Phone Number: ");
            color(data_color);
            string_scan(school[classNum-1][id-1].siblings[choice-1].phone);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 3:
            color(title_color);
            printf("Replace sibling: \n");
            color(data_color);
            school_scanSibling(&school[classNum-1][id-1].siblings[choice-1]);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        default:
            color(0xc);
            PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            printf("\n\n\n\n\t\t\t\tWrong selection!\n");
            break;
        }
        break;
    case 3:
        while(flag)
        {
            flag=0;
            color(title_color);
            school_printSubjects(&school[classNum-1][id-1]);
            //  school_editSubjectInformation(&school[classNum-1][id-1]);
            printf("Enter Subject number to edit: ");
            color(data_color);
            scanf("%d",&choice);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            if(choice>=5 && choice<=6)
            {

                printf("\t\t\t\t \x11 Elective Subject Edit \x10 \n\n");
                school_printSubject(&school[classNum-1][id-1].subjects[choice-1]);
                printf("1_Replace Elective Subject with another subject : \n");
                printf("2_Edit Elective Subject Grade : \n");
                printf("Enter your choice: ");
                color(data_color);
                scanf("%d",&choice2);
                PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            }
            else if(choice>=1 && choice<=4)
            {
                printf("\t\t\t\t \x11 Mandatory Subject Edit \x10 \n\n");
                choice2=2;
            }
            else
            {
                printf("Wrong Selection..press any number to continue , press 0 to exit.\n");
                color(0x15);
                printf("Enter your choice: ");
                color(data_color);
                scanf("%d",&flag);
                PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                fflush(stdin);
                choice2=0;
            }
        }
        color(7);
        switch(choice2)
        {
        case 1:
            system("cls");
            Sleep(500);
            printf("Total Sub = %d \n",school[classNum-1][id-1].totalgrade);
            school_subjectsList(classNum);
            subName=(choice == 5) ? school[classNum-1][id-1].subjects[5].name:school[classNum-1][id-1].subjects[4].name;
            printf("\n");
            for(i=0; i<5; i++)
            {
                if(String_Compare_one(school_arrElectiveSub[classNum-1][i],subName))
                {
                    break;
                }
            }
            school[classNum-1][id-1].totalgrade -=school[classNum-1][id-1].subjects[choice-1].grade;
            subID=school_scanElectiveSub(&school[classNum-1][id-1].subjects[choice-1],classNum,i+1);
            school[classNum-1][id-1].totalgrade +=school[classNum-1][id-1].subjects[subID-1].grade;
            break;
        case 2:
            printf("Grade: ");
            scanf("%d",&school[classNum-1][id-1].subjects[choice-1].grade);
            break;
        default:
            color(0xc);
            PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            printf("\n\n\n\n\t\t\t\tWrong selection!\n");
            break;
        }
        break;
    case 4:
        for(i=0; i<2; i++)
        {
            printf("Guardian number %d Data: \n",i+1);
            school_printGuardian(&school[classNum-1][id-1].guardian[i]);
        }
        printf("Enter Guardian number to edit: ");
        scanf("%d",&choice);
        color(title_color);
        system("cls");
        Sleep(500);
        school_printGuardian(&school[classNum-1][id-1].guardian[choice-1]);
        printf("1_Name : \n");
        printf("2_Phone Number : \n");
        printf("3_Address : \n");
        printf("4_Replace Guardian : \n");
        printf("5_To get back: \n");
        printf("Enter your choice: ");
        scanf("%d",&choice2);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        switch(choice2)
        {
        case 1:
            printf("\nName: ");
            string_scan(school[classNum-1][id-1].guardian[choice-1].name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 2:
            printf("\nPhone Number: ");
            string_scan(school[classNum-1][id-1].guardian[choice-1].phoneNumber);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 3:
            printf("\nAddress: ");
            string_scan(school[classNum-1][id-1].guardian[choice-1].Address);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 4:
            printf("\nNew guardian: \n");
            school_scanGuardian(&school[classNum-1][id-1].guardian[choice-1]);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            break;
        case 5:
            break;
        default:
            color(0xc);
            PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            printf("\n\n\n\n\t\t\t\tWrong selection!\n");
            break;
        }
        break;
    case 5:
        school_HealthInformation(classNum,id);

        break;
    case 6:
        break;
    default:
        printf("\nWrong choice!\n");
        break;

    }
    school_editStudentDataFile(classNum,id);
}

int school_EditStudWithName(char* name,int classNum)
{
    int searchCase,id,choice;
    searchCase = school_SearchWithName(name, classNum,0);

    if(searchCase>=0)
    {
        school_EditStudWithID(searchCase+1,classNum);

    }
    else if(-2==searchCase)
    {
        color(15);
        printf("\x11 There are a number of students with the same name...\n\n");
        color(10);
        printf(" \x4 To print the list with ID, Enter >>> 1 \n");
        printf(" \x4 To re-enter the whole name, Enter >>> 2 \n");
        printf(" \x4 To get back, Enter any other numbers \n");
        color(7);
        printf("  >>Enter your choice: ");
        scanf("%d",&choice);
        if(1==choice)
        {
            Sleep(100);
            system("cls");
            color(7);
            school_SearchWithName(name,classNum,1);
            Sleep(100);
            printf("Enter student ID:");
            scanf("%d",&id);
            system("cls");
            Sleep(100);
            school_EditStudWithID(id,classNum);
        }
        else if(2==choice)
        {
            return 0;//To re-enter the whole name
        }
    }
    else if(-1==searchCase)
    {
        color(0xc);
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        printf("\n\n\n\n\t\t\t\tStudent Not Found!\n");
        Sleep(1000);
    }
    return 1;

}
void school_swithchCaseEditStudent()
{
    int choice,id,classNum, flag=1;
    char name [30];
    color(mainTitleColor1);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);

    if(classNum<=0||classNum>max_number_of_class)
    {
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        Sleep(1000);
         system("cls");
        return;
    }
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    printf("\x4 1 > Edit by name: \n");
    printf("\x4 2 > Edit by ID : \n");
    printf("\x4 3 > To get back : \n");
    color(7);
    printf(">> Enter your choice: ");
    color(10);
    scanf("%d",&choice);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    fflush(stdin);
    system("cls");
    switch(choice)
    {
    case 1:
        while(flag)
        {
            flag=0;
            color(mainTitleColor);
            printf(">> Enter student name:");
            color(data_color);
            printf(" ");
            string_scan(name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            if(!school_EditStudWithName(name,classNum))
            {
                Sleep(200);
                system("cls");
                flag=1;
            }
        }
        break;
    case 2:
        printf(">> Enter student ID: ");
        scanf("%d",&id);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        school_EditStudWithID(id,classNum);
        break;
    case 3:
        Sleep(1000);
        break;
    default:
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
		Sleep(1000);
        system("cls");

        break;
    }
}
void school_swithchCaseCallStudent()
{
    int choice,id,classNum,searchCase,flag=1,choice1;
    char name [30];
    color(mainTitleColor);
    printf("Enter Student number class");
    color(data_color);
    printf(": ");
    scanf("%d",&classNum);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    fflush(stdin);
    if(classNum==0||classNum>max_number_of_class)
    {
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        Sleep(1000);
        return;
    }
    color(data_color);
    printf("\x4 1 > Find by name: \n");
    printf("\x4 2 > Find by ID : \n");
    printf("\x4 3 > To get back : \n");
    color(0xf);
    printf(">> Enter your choice: ");
    color(10);
    scanf("%d",&choice);
    fflush(stdin);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    Sleep(200);
    system("cls");
    switch(choice)
    {
    case 1:
        while(flag)
        {
            flag=0;
            printf(">> Enter student name: ");
            color(data_color);
            string_scan(name);
            PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
            searchCase=school_SearchWithName(name,classNum,0);
            if(searchCase>=0)
            {
                school_studentCalling(&school[classNum-1][searchCase],searchCase+1);
            }
            else if(searchCase==-2)
            {
                color(15);
                printf("\x11 There are a number of students with the same name...\n\n");
                color(10);
                printf(" \x4 To print the list with ID, Enter >>> 1 \n");
                printf(" \x4 To re-enter the whole name, Enter >>> 2 \n");
                printf(" \x4 To get back, Enter any other numbers \n");
                color(0xf);
                printf(">>Enter your choice: ");
                scanf("%d",&choice);
                PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                if(choice==1)
                {
                    Sleep(100);
                    system("cls");
                    color(title_color);
                    school_SearchWithName(name,classNum,1);
                    printf("\n>> Enter student ID to call: ");
                    color(data_color);
                    scanf("%d",&id);
                    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                    school_studentCalling(&school[classNum-1][id-1],id);
                }
                else if(choice==2)
                {
                    color(title_color);
                    printf("Name: ");
                    color(data_color);
                    string_scan(name);
                    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                    searchCase=school_SearchWithName_one(name,classNum,0);
                    if(searchCase>=0)
                    {
                        school_studentCalling(&school[classNum-1][searchCase],searchCase+1);
                    }
                    else
                    {
                        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                        color(0xc);
                        printf("Wrong Name, To continue press 1, to exit press 0: ");
                        scanf("%d",&choice1);
                        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
                        fflush(stdin);
                        if(choice1==1)
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                }
            }
            else if(searchCase==-1)
            {
                PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                color(0xc);
                printf("\n\nStudent Not Found!\n");
                Sleep(1000);
            }
        }
        break;
    case 2:
        color(title_color);
        printf("\n>> Enter student ID To call: ");
        color(data_color);
        scanf("%d",&id);
        school_studentCalling(&school[classNum-1][id-1],id);
        break;
    case 3:
        break;
    default:
        printf("Wrong Choice!");
        break;
    }
}
void school_studentCalling(stud_t* stud,int id)
{
    int choice,i;
    color(title_color);
    printf("\x4 Student ID : ");
    color(data_color);
    printf("%d",id);
    color(title_color);
    printf("\t Student name : ");
    color(data_color);
    string_print(stud->name);
    color(title_color);
    printf("\n-------------------------------------------------------------------------\n\n");
    printf("1_Call student\n");
    printf("2_Call Guardian\n");
    printf("3_Call Sibling\n");
    color(7);
    printf(">> Enter your choice: ");
    color(10);
    scanf("%d",&choice);
    fflush(stdin);
    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
    Sleep(200);
    system("cls");
    switch(choice)
    {
    case 1:
        color(mainTitleColor);
        printf("\t\t\t\t \x11 Call Student \x10 \n");
        color(title_color);
        printf("------------------------------------------------------------\n\n");
        color(title_color);
        printf("Name: ");
        color(data_color);
        string_print(stud->name);
        color(title_color);
        printf("\t\tPhone Number: ");
        color(data_color);
        string_print(stud->phoneNumber);
        printf("\n\n");
        school_callStud(7);
        color(data_color);
        printf("\nThere is no answer!\n");
        color(15);
        printf("Enter any number To get back\n");
        color(data_color);
        scanf("%d",&choice);
        fflush(stdin);
        break;
    case 2:
        color(mainTitleColor);
        printf("\t\t\t \x11 Call Guardian \x10");
        color(data_color);
        printf("\n-----------------------------------------------------------------------\n\n");
        for(i=0; i<2; i++)
        {
            color(title_color);
            printf("\x4 Guardian number %d data: \n",i+1);
            school_printGuardian(&stud->guardian[i]);
        }
        color(title_color);
        printf("Which Guardian you wanna call 1 or 2 : ");
        color(data_color);
        scanf("%d",&choice);
        fflush(stdin);
        //    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        Sleep(200);
        system("cls");
        color(mainTitleColor);
        printf("\t\t\t\t \x11 Call Guardian \x10 \n\n");
        printf("---------------------------------------------------------------------------\n\n");
        color(title_color);
        printf("\n\t\t\x11 Calling ");
        string_print(stud->guardian[choice-1].guard);
        printf("\x10 \n");
        string_print(stud->guardian[choice-1].guard);
        color(title_color);
        printf(" Name: ");
        color(data_color);
        string_print(stud->guardian[choice-1].name);
        color(title_color);
        printf("  \t   Phone Number: ");
        color(data_color);
        string_print(stud->guardian[choice-1].phoneNumber);
        printf("\n");
        school_callStud(8);
        color(data_color);
        printf("\nThere is no answer!\n");
        color(15);
        printf("Enter any number To get back\n");
        scanf("%d",&choice);
        fflush(stdin);
        break;
    case 3:
        color(mainTitleColor);
        printf("\t\t\t\t \x11 Call Sibling \x10 \n");
        printf("-------------------------------------------------------------------------\n\n");
        for(i=0; i<stud->nOfsiblings; i++)
        {
            color(title_color);
            printf("\x4 Sibling number %d data: \n",i+1);
            school_printSibling(&stud->siblings[i]);
        }
        color(title_color);
        printf("Enter number of Sibling you wanna call : ");
        scanf("%d",&choice);
        fflush(stdin);
        Sleep(200);
        system("cls");
        color(mainTitleColor);
        printf("\t\t\t \x11 Call Sibling \x10 \n\n");
        printf("----------------------------------------------------------------------\n\n");
        color(title_color);
        printf(" name: ");
        color(data_color);
        string_print(stud->siblings[choice-1].name);
        color(title_color);
        printf("  \t   Phone Number: ");
        color(data_color);
        string_print(stud->siblings[choice-1].phone);
        printf("\n");
        school_callStud(7);
        color(data_color);
        printf("\nThere is no answer!\n");
        color(15);
        printf("Enter any number To get back\n");
        scanf("%d",&choice);
        fflush(stdin);
        break;
    default:
        PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        color(0xc);
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
		Sleep(1000);
        break;
    }
}
void school_callStud(int line)
{
    int i,j,c=2,col=8,flag=1;
    color(15);
    printf(">>Press any number to cancel the call");
    moveToX_Y(0,line);
   PlaySound(TEXT("ring.wav"),NULL,SND_ASYNC);
    for(i=0; i<20; i++)
    {
        if(kbhit())
        {
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
        }

        if(i%4==0)
        {
            col++;
            color(col);
        }
        printf(",");
        Sleep(120);
    }
     if(!flag){
        PlaySound(NULL, NULL, 0);
        return;
    }
    for(j=20; j>=0; j--)
    {
        if(kbhit())
        {
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
        }

        moveToX_Y(j,line);
        printf("  ");
        Sleep(120);
    }
    col=8;
    if(!flag){
        PlaySound(NULL, NULL, 0);
        return;
    }
    moveToX_Y(0,line);
    for(i=0; i<5; i++)
    {
        if(kbhit())
        {
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
        }
        printf(",");
        Sleep(120);
    }
    if(!flag){
        PlaySound(NULL, NULL, 0);
        return;
    }

    while(c>0)
    {
        if(kbhit()){
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
        }
       PlaySound(TEXT("ring.wav"),NULL,SND_ASYNC);
        moveToX_Y(4,line);
        color(10);
        for(i=5; i<22+c; i++)
        {
            if(kbhit()){
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
            }
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
            if(kbhit()){
                PlaySound(NULL, NULL, 0);
            flag=0;
            break;
           }
            moveToX_Y(j,line);
            printf("  ");
            Sleep(160);
        }
        if(!flag){
            PlaySound(NULL, NULL, 0);
            break;
        }
        col=5+c;
        c--;
    }
    moveToX_Y(4,line);
    for(i=5; i<20; i++)
    {
        if(kbhit())
        {
            PlaySound(NULL, NULL, 0);
            flag=0;
            break;
        }
        if(i%4==0)
        {
            col++;
            color(col);
        }
        printf(",");
        Sleep(160);
    }
}

/**********************************************shrooq***************************/
int max_student_Mandatory(int subnum,int classNum,int* grade)
{
    int i,max=0,index=-1;
    int studentnum=studentClassCount[classNum-1];
    for(i=0; i<studentnum; i++)
    {
        if(school[classNum-1][i].subjects[subnum].grade>max)
        {
            max=school[classNum-1][i].subjects[subnum].grade;
            index=i;
            *grade=max;
        }
    }
    return index;
}

void Class_Max_MandSub(int classNum)
{
    int choice,flag=1,index,i,check,grade;
    color(title_color);
    printf("Select Subject from list:\n");
    for(i=0; i<4; i++)
    {
        printf("%d.",i+1);
        string_print(school_arrMandatorySub[classNum-1][i]);
        printf("\n");
    }
    while(flag)
    {
        printf("your selection: ");
        color(data_color);
        scanf("%d",&choice);
        fflush(stdin);
        check=(choice>0 && choice<=4)?1:0;
        switch(check)
        {
        case 1:
            printf("choice: %d\n",choice);
            index=max_student_Mandatory(choice-1,classNum,&grade);
            printf("Name: ");
            string_print(school[classNum-1][index].name);
            printf("\t\tID: %d\n",index+1);
            printf("Grade of Subject: %d",grade);
            printf("\t\tTotal Grade: %d\n",school[classNum-1][index].totalgrade);
            printf("press 0 to exit, press 1 to stay: ");
            scanf("%d",&flag);
            fflush(stdin);

            break;
        case 0:
            printf("Wrong Selection.\n");
            printf("press 0 to exit, press 1 to continue: ");
            scanf("%d",&flag);
            fflush(stdin);
            break;
        }
    }
}

int max_student_Elective(char*s,int classNum,int* grade)
{
    int i,j,index=-1,studentnum,max=0;
    char name[30];
    strcpy(name,s);
    studentnum=studentClassCount[classNum-1];
    for(j=0; j<studentnum; j++)
    {
        for(i=4; i<6; i++)
        {
            if(String_Compare_one(name,school[classNum-1][j].subjects[i].name)==1)
            {
                if(school[classNum-1][j].subjects[i].grade>max)
                {
                    max=school[classNum-1][j].subjects[i].grade;
                    index=j;
                    *grade=max;
                }
            }
        }
    }
    return index;
}

void Class_Max_ElectiveSub(int classNum)
{
    int choice,flag=1,index,check,i,grade=0;
    char name[30];
    printf("Select Subject from list:\n");
    for(i=0; i<5; i++)
    {
        printf("%d.",i+1);
        string_print(school_arrElectiveSub[classNum-1][i]);
        printf("\n");
    }
    while(flag)
    {
        printf("your selection: ");
        scanf("%d",&choice);
        fflush(stdin);
        check=(choice>0 && choice<=5)?1:0;
        switch(check)
        {
        case 1:
            strcpy(name,school_arrElectiveSub[classNum-1][choice-1]);
            index=max_student_Elective(name,classNum,&grade);
            //  flag=(index==-1)?0:1;
            if(index==-1)
            {
                color(0xc);
                printf("Not Selected.\n");
                flag=0;
                Sleep(500);
                break;
            }
            color(title_color);
            printf("Name: ");
            color(data_color);
            string_print(school[classNum-1][index].name);
            color(title_color);
            printf("\t\tID: ");
            color(data_color);
            printf("%d\n",index+1);
            color(title_color);
            printf("Grade of Subject: ");
            color(data_color);
            printf("%d",grade);
            color(title_color);
            printf("\t\tTotal Grade: ");
            color(data_color);
            printf("%d\n",school[classNum-1][index].totalgrade);
            color(title_color);
            printf("press 0 to exit, press 1 to stay: ");
            color(data_color);
            scanf("%d",&flag);
            fflush(stdin);
            break;
        case 0:
            //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            color(0xc);
            printf("Wrong Selection.\n");
            printf("press 0 to exit, press 1 to continue: ");
            color(data_color);
            scanf("%d",&flag);
            fflush(stdin);
            break;
        }
    }
}


void school_maxsubject()
{
    int choice,flag=1,classNum;
    color(mainTitleColor);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);
    if(classNum==0||classNum>max_number_of_class)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        Sleep(1000);
        return;
    }
    while(flag)
    {
        flag=0;
        color(title_color);
        printf("1.Select Mandatory Subject.\n");
        printf("2.Select Elective Subject.\n");
        color(data_color);
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            Class_Max_MandSub(classNum);
            break;
        case 2:
            Class_Max_ElectiveSub(classNum);
            break;
        default:
            //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            color(0xc);
            printf("Wrong Selection.\n");
            printf("To continue press 1, To exit Press 0: ");
            color(data_color);
            scanf("%d",&flag);
            fflush(stdin);
        }
    }
}
void school_classStudScoreInOrder()
{
    int i,j,max=0, max1=0,flag=0,classNum,studentclass,maxindex=-1;
    color(mainTitleColor);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);
    if(classNum==0||classNum>max_number_of_class)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        Sleep(1000);
        return;
    }
    studentclass=studentClassCount[classNum-1];
    int* maxarr=calloc(sizeof(int),studentclass);
    for(i=0; i<studentclass; i++)
    {
        if(school[classNum-1][i].totalgrade>max)
        {
            max=school[classNum-1][i].totalgrade;
            maxindex=i;
        }
    }
    maxarr[0]=maxindex;
    max1=max;
    max=0;
    for(j=1; j<studentclass; j++)
    {
        for(i=0; i<studentclass; i++)
        {
            if(school[classNum-1][i].totalgrade>max && school[classNum-1][i].totalgrade<max1)
            {
                max=school[classNum-1][i].totalgrade;
                maxindex=i;
            }
        }
        maxarr[j]=maxindex;
        max1=max;
        max=0;
        maxindex=0;
    }

    while(!flag)
    {
        for(i=0; i<studentclass; i++)
        {
            school_printStud(&school[classNum-1][maxarr[i]],i+1);
        }
        printf("Enter any number to back: ");
        color(data_color);
        scanf("%d",&flag);
        fflush(stdin);
    }

}
void Print_Certificate(int student,int classNum)
{
    int i;
    printf("+===============================================+\n");
    printf("|");
    color(color1);
    printf(" Name: ");
    color(color2);
    string_print(school[classNum][student].name);
    color(color1);
    printf("\t\tTotalGrade: ");
    color(color2);
    printf("%d",school[classNum][student].totalgrade);
    color(0x0E);
    printf(" |");
    printf("\n");
    printf("+===============================================+\n");
    printf("|");
    color(color1);
    printf(" Subject Name:\t\tMaxGrade:\tGrade:\t");
    color(14);
    printf("|\n");
    printf("|-----------------------------------------------|\n");
    for(i=0; i<6; i++)
    {
        color(14);
        printf("|");
        color(30);
        string_print(school[classNum][student].subjects[i].name);
        color(0xD);
        printf("            \t%2d",school[classNum][student].subjects[i].Max_grade);
        color(15);
        printf("\t\t%d\t",school[classNum][student].subjects[i].grade);
        color(14);
        printf("|\n");
    }
    color(14);
    printf("+===============================================+\n");
}

void school_allCertificate()
{
    int i,j,studentNum;
    for(i=0; i<max_number_of_class; i++)
    {
        studentNum=studentClassCount[i];
        color(data_color);
        printf("\t\t     \x11 Class %d \x10\n\n",i+1);
        for(j=0; j<studentNum; j++)
        {
            Print_Certificate(j,i);
        }
    }
}
void school_specificClass()
{
    int classNum,i;
    color(mainTitleColor);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);
    if(classNum==0||classNum>max_number_of_class)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        Sleep(1000);
        return;
    }
    int studentNum=studentClassCount[classNum-1];
    printf("\t\t     \x11 Class %d \x10\n\n",classNum);
    for(i=0; i<studentNum; i++)
    {
        Print_Certificate(i,classNum-1);
    }
}

void school_oneStudent()
{
    int choice,flag=1,id,classNum,searchCase,choice1;
    char name[30];
    color(mainTitleColor);
    printf("Enter Student number class:");
    color(data_color);
    printf(" ");
    scanf("%d",&classNum);
    fflush(stdin);
    if(classNum==0||classNum>max_number_of_class)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
        //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        Sleep(1000);
        return;
    }
    printf("1.Enter Student Name.\n");
    printf("2.Enter ID.\n");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
    case 1:
        while(flag)
        {
            flag=0;
            printf(">> Enter student name: ");
            string_scan(name);
            searchCase=school_SearchWithName(name,classNum,0);
            if(searchCase>=0)
            {
                Print_Certificate(searchCase,classNum-1);
            }
            else if(-2==searchCase)
            {

                color(15);
                printf("\x11 There are a number of students with the same name...\n\n");
                color(10);
                printf(" \x4 To print the list with ID, Enter >>> 1 \n");
                printf(" \x4 To re-enter the whole name, Enter >>> 2 \n");
                printf(" \x4 To get back, Enter any other numbers \n");
                color(7);
                printf("  >>Enter your choice: ");
                scanf("%d",&choice);
                if(choice==1)
                {
                    Sleep(100);
                    system("cls");
                    color(7);
                    school_SearchWithName(name,classNum,1);
                    printf("\n>> Enter student ID To print its data: ");
                    scanf("%d",&id);
                    color(data_color);
                    printf("\t\t     \x11 Class %d \x10\n\n",id);
                    Print_Certificate(id-1,classNum-1);
                }
                else if(choice==2)
                {
                    printf("Name: ");
                    string_scan(name);
                    int index=school_SearchWithName_one(name,classNum,0);

                    if(index>=0)
                    {
                        color(data_color);
                        printf("\t\t     \x11 Class %d \x10\n\n",index+1);
                        Print_Certificate(index,classNum-1);
                    }
                    else
                    {
                        //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                        printf("Wrong Name, To continue press 1, to exit press 0: ");
                        color(data_color);
                        scanf("%d",&choice1);
                        fflush(stdin);
                        if(choice1==1)
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                        }
                    }
                }
            }
            else if(-1==searchCase)
            {
                //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
                printf("\n\nStudent Not Found!\n");
            }
        }
        break;
    case 2:
        color(title_color);
        printf("\n>> Enter student ID To print its data: ");
        color(data_color);
        scanf("%d",&id);
        printf("\n");
        color(data_color);
        printf("\t\t     \x11 Class %d \x10\n\n",id);
        Print_Certificate(id-1,classNum-1);
        break;
    default:
        printf("Wrong Choice!");
        //PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
        break;
    }
}

void school_certification()
{
    int choice,flag=1;
    color(mainTitleColor);
    printf("\t\t\t\t\x11 Certification\x10");
    color(title_color);
    printf("\n\n1.Print All School.\n");
    printf("2.Print Specific Class Student.\n");
    printf("3.Print One Student.\n");
    while(flag)
    {
        printf("Enter Your Selection: ");
        color(data_color);
        scanf("%d",&choice);
        //    PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        fflush(stdin);
        switch(choice)
        {
        case 1:
            school_allCertificate();
            break;
        case 2:
            school_specificClass();
            break;
        case 3:
            school_oneStudent();
            break;
        default:
            printf("Wrong Selection.\n");
            //    PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            break;
        }
        printf("To continue press 1, To exit Press 0: ");
        scanf("%d",&flag);
        fflush(stdin);
    }
}

/**************************************************************************************/
void school_DataBase()
{
    int choice,esc;
    //PlaySound(TEXT("opening.wav"),NULL,SND_ASYNC);
    for(int i=0; i<max_number_of_class; i++)
    {
        school_initiReadDataBase(school[i],i+1);
    }
    char character = 'S';
    color(11);
    printPattern(character);
    Sleep(2000);
    system("cls");
    while(1)
    {

        color(data_color);
        printf("\t\t\t      \x11 ********************* \x10");
        color(0xf);
        printf("\n\t\t\t\t\x4 1 >Add Student:  \n");
        printf("\t\t\t\t\x4 2 >Edit student: \n");
        printf("\t\t\t\t\x4 3 >Print student: \n");
        printf("\t\t\t\t\x4 4 >Call student: \n");
        printf("\t\t\t\t\x4 5 >Print All School: \n");
        printf("\t\t\t\t\x4 6 >Delete Student: \n");
        printf("\t\t\t\t\x4 7 >Print students score in order: \n");
        printf("\t\t\t\t\x4 8 >highest score in a subject: \n");
        printf("\t\t\t\t\x4 9 >Student Certification: \n");
        color(data_color);
        printf("\t\t\t      \x11 ********************* \x10\n");
        color(title_color);
        printf(">> Enter your choice:");
        color(data_color);
        printf(" ");
        scanf("%d",&choice);
        fflush(stdin);
        Sleep(200);
        PlaySound(TEXT("InsertingEnd.wav"),NULL,SND_ASYNC);
        system("cls");
        switch(choice)
        {
        case 1:
            color(data_color);
            printf("\t\t\t\t \x11 Add Student \x10 \n\n");
            school_addStud();
            break;
        case 2:
            school_swithchCaseEditStudent();
            break;
        case 3:
            school_swithchCasePrintStudent();
            color(title_color);
            printf("\nPress any number to exit\n");
            color(data_color);
            scanf("%d",&esc);
            fflush(stdin);
            break;
        case 4:
            color(data_color);
            printf("\t\t\t\t \x11 Call Student \x10 \n\n");
            school_swithchCaseCallStudent();
            break;
        case 5:
            school_AllPrint();
            color(title_color);
            printf("\nPress any number to exit\n");
            color(data_color);
            scanf("%d",&esc);
            fflush(stdin);
            break;
        case 6:
            school_DeleteStudent();
            break;
        case 7:
            school_classStudScoreInOrder();
            break;
        case 8:
            school_maxsubject();
            break;
        case 9:
            school_certification();
            break;
        default:
            PlaySound(TEXT("Windows Background.wav"),NULL,SND_ASYNC);
            color(0xc);
            Sleep(1500);
            printf("\n\n\n\n\n\n\t\t\t\t\t Wrong Selection!\n");
            break;
        }
        system("cls");
        Sleep(500);
    }
}
