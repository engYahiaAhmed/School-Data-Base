#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"Student.h"
int main()
{
    stud_t school[20];
    char name[30];
    int id,choice ,choice2;
    school_addStud(school);
    system("cls");
    Sleep(1000);
    while(1){
        school_EditStudWithID(school ,1);
        system("cls");
        Sleep(1000);
        school_printStud(school,1);
        Sleep(1000);
        system("cls");

    }
//    printf("4_Call Student: \n");
//    printf("1_search by student name: \n");
//    printf("2_search by student ID: \n");
//    printf("Enter Your choice: \n");
//    scanf("%d",&choice);
//    switch(choice){
//        case 1:
//            printf("Enter student Name: ");
//            string_scan(name);
//            break;
//        case 2:
//            printf("Enter student ID: ");
//            scanf("%d",&id);
//            printf("Student name: ");
//            string_print(school[id-1].name);
//            printf("\n");
//            printf("1_Call student\n");
//            printf("2_Call Guardian\n");
//            printf("3_Call Sibling\n");
//            printf("Enter Your choice: ");
//            scanf("%d",&choice2);
//            system("cls");
//            switch(choice2){
//                case 1:
//                    printf(">>call Student: ");
//                    printf("-------------\n");
//                    printf(">>Student name: ");
//                    string_print(school[id-1].name);
//                    printf("\t >>Student nPhone Number: ");
//                    string_print(school[id-1].phoneNumber);
//                    printf("\n");
//                    school_callStud(8);
//                    break;
//
//
//            }
//
//
//
//    }
    return 0;
}
