#ifndef STUDENT_H_
#define STUDENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"Student.h"
#define Physics_MAxGRADE        60
#define Geography_MAxGRADE      30
#define English_MAxGRADE        60
#define Chemistry_MAxGRADE      60
#define Geometry_MAxGRADE       30
#define History_MAxGRADE        30
#define Art_MAxGRADE            30
#define Deutsch_MAxGRADE        30
#define MATH_MAxGRADE           60
#define Number_of_subjects       6

int studentCount;
typedef struct
{
    char name[30];
    char Address[30];
    char guard[12];
    char phoneNumber[12];
}guard_t;
typedef struct
{
    char* name;
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
    person_t* siblings;
    char name[30];
    char phoneNumber[12];
    subj_t subjects[Number_of_subjects];
    guard_t guardian[2];
} stud_t;
/***************************************** Array & string*******************************************/
/****************************************auxiliary functions***************************************/
void string_print(char* str);
void string_scan(char* str );
void arr_scan(int* arr, int size);
void arr_print(int* arr, int size);
void moveToX_Y(int x,int y);
void color(int color_val);
/*********************************************School************************************************/
/****************************************Auxiliary functions***************************************/
void school_printSibling (person_t*  sibling);
void school_scanSibling  (person_t*  sibling);
void school_printGuardian(guard_t*   guardian);
void school_scanGuardian (guard_t*   guardian);
void school_printSubjects(stud_t*    stud);
void school_printSubject (subj_t*    sub);
int school_scanSubject   (subj_t *   sub);
void school_subjectsList ();
/******************************************Project Functions**************************************/
void school_addStud  (stud_t*   arr_students);
void school_printStud(stud_t* arr_students,int id);
void school_callStud(int line);
//int school _SearchStudWithName(stud* arr_students,int size,char* name){
//
////with name(return id),with id
////array of school, size,(linear search).
////return only the index and if not exist return -1;
////shrooq
//}
/*
void school_Studprint(stud_t* arr_students,int id){
    //yehia
}*/
/*
void school_EditStudWithID(stud_t* arr_students,int id)
{

//choose which part will be edited (with switch case)
//print after editing.
//yehia
}
*/
/*
void school_EditStudWithName(stud* arr_students,int* name){
    int index=school_SearchStudWithName(arr_students,name);
    school_EditStudWithID(arr_students,index);
    //yehia
}*/
//void school_DeleteStudWithID(stud* arr_students,int id,int size){
//    //call function to shift to array of school.
//    //shrooq
//}
//void school_DeleteStudWithName(stud* arr_students,int* name){
//    //shrooq
//}
////void school_printAllStudent(stud* arr_students,int size){
////    //shrooq
////}
/*
void school_callStud(){
 for(i=0; i<20; i++)
        {
            printf(",");
            Sleep(120);
        }
        for(j=20; j>=0; j--)
        {
            moveToX_Y(j,1);
            printf("  ");
            Sleep(120);
        }
        moveToX_Y(0,1);
        for(i=0; i<5; i++)
        {
            printf(",");
            Sleep(120);
        }
    while(c>0)
    {
        moveToX_Y(4,1);
        color(10);
        for(i=5; i<22+c; i++)
        {
            if(i%4==0){
                col++;
               color(col);
            }
            printf(",");
            Sleep(160);
        }
        for(j=21+c; j>=5; j--)
        {
            moveToX_Y(j,1);
            printf("  ");
            Sleep(160);
        }
    col=5+c;
    c--;
    }
    moveToX_Y(4,1);
    for(i=5; i<20; i++)
    {
        if(i%4==0){
            col++;
            color(col);
        }
        printf(",");
        Sleep(160);
    }
    printf("To call with Name Enter 1 ");
    printf("To call with ID Enter 2 ");
    printf("student phone number");
    printf(".....");
    //yehia
}
*/
//int school_StudWithHighestSubjectGrade(stud* arr_students,int size,int* subjectName);
////shrooq
/*
int school_StudWithHighestScore(stud* arr_students,int size);
//yehia
*/
#endif /* STUDENT_H_*/
