/************************************************/
/* Title       : School Database                */
/* Author      : Shrooq Mahmoud & Yahia Ahmed   */
/* Release     : 1.0                            */
/* Last Update : Oct 5, 2022                    */
/************************************************/
#include"STRING_FUNC_H_.h"
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
int String_Compare_one(const char* s1,const char* s2)
{
    int i;
    char ss1,ss2;
    for(i=0; s1[i] || s2[i]; i++)
    {
        ss1=(s1[i]>='A' && s1[i]<='Z')?s1[i]+' ':s1[i];
        ss2=(s2[i]>='A' && s2[i]<='Z')?s2[i]+' ':s2[i];
        if(ss1!=ss2)
        {
            return 0;
        }
    }
    return 1;
}
int String_Compare(const char* s1,const char* s2)
{
    int i;
    char ss1,ss2;
    for(i=0; s1[i]&& s2[i]; i++)
    {
        ss1=(s1[i]>='A' && s1[i]<='Z')?s1[i]+' ':s1[i];
        ss2=(s2[i]>='A' && s2[i]<='Z')?s2[i]+' ':s2[i];
        if(ss1!=ss2)
        {
            return 0;
        }
    }
    return 1;
}
void string_print(const char* str)
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
        scanf("%d",&arr[i]);
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
