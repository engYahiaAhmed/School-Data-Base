/************************************************/
/* Title       : School Database                */
/* Author      : Shrooq Mahmoud & Yahia Ahmed   */
/* Release     : 1.0                            */
/* Last Update : Oct 5, 2022                    */
/************************************************/
#include"FILE_R_W_D_H.h"
void school_initiReadDataBase(stud_t* school, int classNum)
{
    int i=0,j;
    FILE* classFile;
    char buffer[200];
    switch(classNum){
        case 1:
            fopen_s(&classFile,"class_1_File.txt","r");
            break;
        case 2:
            fopen_s(&classFile,"class_2_File.txt","r");
            break;
        case 3:
            fopen_s(&classFile,"class_3_File.txt","r");
            break;
        case 4:
            fopen_s(&classFile,"class_4_File.txt","r");
            break;
        case 5:
            fopen_s(&classFile,"class_5_File.txt","r");
            break;
        case 6:
            fopen_s(&classFile,"class_6_File.txt","r");
            break;
        default:
            classFile=NULL;
            break;
    }
    if(classFile==NULL)
    {
        printf("Wrong ! \n");
        return;
    }
    fgets(buffer, 200, classFile);
    while(!feof(classFile)){
        sscanf(buffer,Student_input_format, school[i].name, &school[i].age,school[i].phoneNumber , &school[i].nOfsiblings);
        fgets(buffer, 200, classFile);
        sscanf(buffer, health_input_format, school[i].healthcare.disease, &school[i].healthcare.height, &school[i].healthcare.weight);
        school[i].siblings=malloc(sizeof(person_t) * school[i].nOfsiblings);
        for(j=0; j<school[i].nOfsiblings; j++)
        {
            fgets(buffer, 200, classFile);
            sscanf(buffer, slib_input_format, school[i].siblings[j].name, school[i].siblings[j].phone);


        }
        for(j=0; j<2; j++)
        {
            fgets(buffer, 200, classFile);
            sscanf(buffer,guard_input_format, school[i].guardian[j].name,school[i].guardian[j].guard, school[i].guardian[j].phoneNumber,school[i].guardian[j].Address);
        }
        school[i].totalgrade=0;
        for(j=0; j < Number_of_subjects; j++)
        {
            fgets(buffer, 200, classFile);
            sscanf(buffer, sub_input_format,school[i].subjects[j].name, &school[i].subjects[j].Max_grade, &school[i].subjects[j].grade);
            school[i].totalgrade+=school[i].subjects[j].grade;
            //arr[i].subjects[j].name=(char*)name_sub;
        }
        fgets(buffer, 200, classFile);
        i++;
    }
    fclose(classFile);
    studentClassCount[classNum-1]=i;
}
void school_WriteFile(stud_t* stud , int classNum)
{
    int j;
    FILE* classFile;
    switch(classNum)
    {
    case 1:
        classFile=fopen("class_1_File.txt","r+");
        break;
    case 2:
        classFile=fopen("class_2_File.txt","r+");
        break;
    case 3:
        classFile=fopen("class_3_File.txt","r+");
        break;
    case 4:
        classFile=fopen("class_4_File.txt","r+");
        break;
    case 5:
        classFile=fopen("class_5_File.txt","r+");
        break;
    case 6:
        classFile=fopen("class_6_File.txt","r+");
        break;
    default:
        classFile=NULL;
        break;
    }
    if(classFile==NULL)
    {
        printf(health_output_format, stud->healthcare.disease, stud->healthcare.height, stud->healthcare.weight);

        printf("Something went Wrong!\n");
        Sleep(10000);
        return;
    }
    fseek(classFile, 0, SEEK_END);
    fprintf_s(classFile,Student_output_format, stud->name, stud->age, stud->phoneNumber,stud->nOfsiblings);
    fseek(classFile, 0, SEEK_END);
    fprintf_s(classFile,health_output_format, stud->healthcare.disease, stud->healthcare.height, stud->healthcare.weight);
    for(j=0; j<stud->nOfsiblings; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,slib_output_format, stud->siblings[j].name, stud->siblings[j].phone);
    }
    for(j=0; j<2; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,guard_output_format, stud->guardian[j].name,stud->guardian[j].guard, stud->guardian[j].phoneNumber,stud->guardian[j].Address);
    }
    for(j=0; j < Number_of_subjects; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,sub_output_format,stud->subjects[j].name, stud->subjects[j].Max_grade, stud->subjects[j].grade);
    }
    fclose(classFile);
    studentClassCount[classNum-1]++;
}
void school_WriteStudentInSpecificFile(stud_t* stud,FILE* classFile)
{
    int j;
    if(classFile==NULL)
    {
        printf(health_output_format, stud->healthcare.disease, stud->healthcare.height, stud->healthcare.weight);

        printf("Something went Wrong!\n");
        Sleep(10000);
        return;
    }
    fseek(classFile, 0, SEEK_END);
    fprintf_s(classFile,Student_output_format, stud->name, stud->age, stud->phoneNumber,stud->nOfsiblings);
    fseek(classFile, 0, SEEK_END);
    fprintf_s(classFile,health_output_format, stud->healthcare.disease, stud->healthcare.height, stud->healthcare.weight);
    for(j=0; j<stud->nOfsiblings; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,slib_output_format, stud->siblings[j].name, stud->siblings[j].phone);
    }
    for(j=0; j<2; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,guard_output_format, stud->guardian[j].name,stud->guardian[j].guard, stud->guardian[j].phoneNumber,stud->guardian[j].Address);
    }
    for(j=0; j < Number_of_subjects; j++)
    {
        fseek(classFile, 0, SEEK_END);
        fprintf_s(classFile,sub_output_format,stud->subjects[j].name, stud->subjects[j].Max_grade, stud->subjects[j].grade);
    }
    //fclose(classFile);
    //studentClassCount[classNum-1]++;
}
void school_editStudentDataFile(int classNum,int id)
{
    FILE*file,*temp;
    int j;
    char temp_filename[30];
    char filename[30];
    char buffer[200];
    int start_delete_line=1,end_delete_line=0;
    char keep_reading=1;
    int flag=1;
    //means of user enter file name is file.txt
    //the temperary file called temp____file.txt
    switch(classNum)
    {
    case 1:
        strcpy(filename,"class_1_File.txt");
        break;
    case 2:
        strcpy(filename,"class_2_File.txt");
        break;
    case 3:
        strcpy(filename,"class_3_File.txt");
        break;
    case 4:
        strcpy(filename,"class_4_File.txt");
        break;
    case 5:
        strcpy(filename,"class_5_File.txt");
        break;
    case 6:
        strcpy(filename,"class_6_File.txt");
        break;
    default:
        file=NULL;
        break;
    }
    strcpy(temp_filename,"temp____");
    strcat(temp_filename,filename);
    for(j=0;j<id-1;j++)
    {
        start_delete_line=start_delete_line+10+school[classNum-1][j].nOfsiblings;
    }
    end_delete_line=start_delete_line+10+school[classNum-1][id-1].nOfsiblings;
////    if(start_delete_line!=0){
////       start_delete_line++;
////    }
    Sleep(5000);
    file=fopen(filename,"r");
    temp=fopen(temp_filename,"w");
    if(file==NULL || temp==NULL)
    {
        printf("Error opening file\n");
        return;
    }
    int current_line=1;
    do
    {
        fgets(buffer,200,file);
        //reach the end of file
        if(feof(file)) keep_reading=0;
        else if(current_line < start_delete_line || current_line > end_delete_line-1)
        {
            fputs(buffer,temp);
        }
        else
        {
            if(flag)
            {
                school_WriteStudentInSpecificFile(&school[classNum-1][id-1],temp);
            }
            flag=0;
        }
        current_line++;

    }while(keep_reading);

    fclose(file);
    fclose(temp);
    remove(filename);
    rename(temp_filename,filename);

}
void school_Delete_Data_File(int classNum,int id)
{
    FILE*file,*temp;
    int j;
    char temp_filename[30];
    char filename[30];
    char buffer[200];
    int start_delete_line=1,end_delete_line=0;
    //means of user enter file name is file.txt
    //the temperary file called temp____file.txt
    switch(classNum)
    {
    case 1:
        strcpy(filename,"class_1_File.txt");
        break;
    case 2:
        strcpy(filename,"class_2_File.txt");
        break;
    case 3:
        strcpy(filename,"class_3_File.txt");
        break;
    case 4:
        strcpy(filename,"class_4_File.txt");
        break;
    case 5:
        strcpy(filename,"class_5_File.txt");
        break;
    case 6:
        strcpy(filename,"class_6_File.txt");
        break;
    default:
        file=NULL;
        break;
    }
    strcpy(temp_filename,"temp____");
    strcat(temp_filename,filename);
    //school_printStud2(&school[classNum-1][id-1],0,1,0,0);
    Sleep(5000);
    for(j=0;j<id-1;j++)
    {
        start_delete_line=start_delete_line+10+school[classNum-1][j].nOfsiblings;
    }
    end_delete_line=start_delete_line+10+school[classNum-1][id-1].nOfsiblings;
////    if(start_delete_line!=0){
////       start_delete_line++;
////    }
  //  printf("start_delete_line = %d \n end_delete_line = %d\n",start_delete_line,end_delete_line);
    Sleep(5000);
    file=fopen(filename,"r");
    temp=fopen(temp_filename,"w");
    if(file==NULL || temp==NULL)
    {
        printf("Error opening file\n");
        return;
    }
    char keep_reading=1;
    int current_line=1;
    do
    {
        fgets(buffer,200,file);
        //reach the end of file
        if(feof(file)) keep_reading=0;
        else if(current_line <start_delete_line || current_line>end_delete_line-1)
        {
            fputs(buffer,temp);
        }
        current_line++;

    }while(keep_reading);

    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename,filename);

}
