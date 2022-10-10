#ifndef FILE_R_W_D_H
#define FILE_R_W_D_H
#include"student.h"
void school_initiReadDataBase(stud_t* school, int classNum);
void school_WriteFile(stud_t* stud , int classNum);
void school_Delete_Data_File(int classNum,int id);
void school_WriteStudentInSpecificFile(stud_t* stud,FILE* classFile);
void school_editStudentDataFile(int classNum,int id);
#endif
