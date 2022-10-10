#ifndef STUDNET_H_
#define STUDNET_H_
#include <stdio.h>
#include <stdlib.h>
#include<mmstream.h>
#include <windows.h>
#include"STRING_FUNC_H_.h"
#define max_student_number      20
#define max_number_of_class      6
#define Physics_MAxGRADE        60
#define Geography_MAxGRADE      30
#define English_MAxGRADE        60
#define Chemistry_MAxGRADE      60
#define Geometry_MAxGRADE       30
#define History_MAxGRADE        30
#define Art_MAxGRADE            30
#define Deutsch_MAxGRADE        30
#define MATH_MAxGRADE           60
#define Number_of_subjects      6
#define   mainTitleColor1       29
#define   mainTitleColor        47
#define   title_color           0xa
#define   data_color            0xe
#define max_student_number       20
#define color1                  10
#define color2                  14
#define color3                  3
#define background              15
extern const char* health_input_format;
extern const char* Student_input_format;
extern const char* slib_input_format;
extern const char* guard_input_format;
extern const char* sub_input_format;
extern const char* slib_output_format;
extern const char* Student_output_format;
extern const char* health_output_format;
extern const char* guard_output_format;
extern const char* sub_output_format;

typedef struct
{
    int height;
    int weight;
    char disease[30];
}health_t;
typedef struct
{
    char name[30];
    char Address[30];
    char guard[12];
    char phoneNumber[12];
}guard_t;
typedef struct
{
    char name[30];
    int Max_grade;
    int grade;

} subj_t;

typedef struct
{
    char name[30];
    char phone[12];
} person_t;

typedef struct
{
    int age;
    int nOfsiblings;
    int totalgrade;
    person_t* siblings;
    health_t healthcare;
    char name[30];
    char phoneNumber[12];
    subj_t subjects[Number_of_subjects];
    guard_t guardian[2];

} stud_t;
/*****************************************Array******************************************************/
extern const char* school_arrMandatorySub[max_number_of_class][20];
extern const char* school_arrElectiveSub[max_number_of_class][20];

extern int school_arrMandatorymaxGrade[4];
extern int school_arrElectivemaxGrade[5];

extern int studentClassCount[max_number_of_class];
extern stud_t school[max_number_of_class][max_student_number];
/****************************************auxiliary functions***************************************/
void school_printSibling (person_t*  sibling);
void school_scanSibling  (person_t*  sibling);
void school_printGuardian(guard_t*   guardian);
void school_scanGuardian (guard_t*   guardian);
void school_printSubjects(stud_t*    stud);
void school_printSubject (subj_t*    sub);
void school_scanMandatorySub(subj_t *   sub,int id,int index);
int school_scanElectiveSub(subj_t * sub,int classNum,int lastSubID);
void school_subjectsList (int classNum);
void school_printAllSchoolStudents(stud_t* school);
int school_SearchWithName(char* s,int classNum,int print);
/*********************************************School************************************************/
/****************************************Auxiliary functions***************************************/

/***************************************************************/
void school_subjectsList();
int school_scanElectiveSub(subj_t * sub,int classNum,int lastSubID);
void school_scanSibling(person_t* sibling);
void school_scanMandatorySub(subj_t * sub,int classNum,int index);
void school_scanGuardian(guard_t* guardian);
/**********************print****************************/
void Health_Print(health_t* h);
void school_printSibling(person_t* sibling);
void school_printGuardian(guard_t* guardian);
void school_printSubjects(stud_t* stud);
void school_printSubject(subj_t* sub);
/*******************************************************/
void school_addStud();
void school_printStud(stud_t* arr_students,int id);
void school_EditStudWithID(int id,int classNum);
void school_PersonalInformation(int classNum);
void school_SubjectInformation(int classNum);
void school_HealthInformation(int classNum,int id);
void class_AllPrint(int classNum,int print);
void school_AllPrint();
void school_printStud2(stud_t* s,int Gaurdflag,int Siblingsflag,int Subjectflag,int Healthflag);
void school_DeleteStudent();
void Student_ShiftList(stud_t* class1,int classNum,int id);
void Student_DeleteWithID(stud_t* class1,int classNum,int id);
void Student_DeleteWithName(stud_t* class1,int classNum,char* name);

void school_callStud(int line);
void school_studentCalling(stud_t* stud,int id);
void school_swithchCasePrintStudent();
void school_swithchCaseEditStudent();
void school_swithchCaseCallStudent();
void school_DataBase();
//void school_initiReadDataBase();//Read File
//void school_WriteFile(stud_t* stud , int classNum);//Write File
void school_editSubjectInformation(stud_t* stud);
void school_editMandatorySubject(stud_t *s);
void school_editElectiveSubject(stud_t*s);
//void school_initiReadDataBase(stud_t* class1,int classNum);
//void school_Delete_Data_File(int classNum,int ID);
/******************************************************/
int max_student_Mandatory(int subnum,int classNum,int* grade);
void Class_Max_MandSub(int classNum);
int max_student_Elective(char*s,int classNum,int* grade);
void Class_Max_ElectiveSub(int classNum);
void school_maxsubject();
void school_classStudScoreInOrder();
void Print_Certificate(int student,int classNum);
void school_allCertificate();
void school_specificClass();
void school_oneStudent();
void school_certification();
void printPattern(char character);
#endif // STUDNET_H_

