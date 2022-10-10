#ifndef STRING_FUNC_H_
#define STRING_FUNC_H_
#include"student.h"
/***************************************** Array & string*******************************************/
void string_print(const char* str);
void string_scan(char* str );
int  String_Compare(const char* s1,const char* s2);
int  String_Compare_one(const char* s1,const char* s2);
void arr_scan(int* arr, int size);
void arr_print(int* arr, int size);
void moveToX_Y(int x,int y);
void color(int color_val);
#endif
