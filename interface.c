/************************************************/
/* Title       : School Database                */
/* Author      : Shrooq Mahmoud & Yahia Ahmed   */
/* Release     : 1.0                            */
/* Last Update : Oct 5, 2022                    */
/************************************************/
#include "student.h"
#include"interface.h"
int height = 5;
// Number of character width in each line
int width = (2 * 5) - 1;

// Function to find the absolute value
// of a number D
int abs(int d)
{
    return d < 0 ? -1 * d : d;
}

// Function to print the pattern of 'S'
void printS()
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height; j++)
        {
            moveToX_Y(j,i);
            if (i == 0 || i == height / 2|| i == height - 1)
                printf("s");
            else if (i < height / 2&& j == 0)
                printf("ss");
            else if (i > height / 2&& j == height - 1)
                printf("ss");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printC()
{
    int i, j,flag=1;
    for (i = 0; i < height; i++)
    {
        flag=1;
        for (j =10; j < (height - 1)+10; j++)
        {
            moveToX_Y(j,i);
            if(flag)
            {
                printf("cc");
                flag=0;
            }
            if (i == 0 || i == height - 1)
                printf("ccc");
            else
                continue;
        }
        printf("\n");
    }
}


void printH()
{
    int i, j,flag;
    for (i = 0; i < height; i++)
    {
        flag=1;
        for (j = 20; j < height+20; j++)
        {
            moveToX_Y(j,i);
            if(flag)
            {
                printf("h");
                flag=0;
            }
            if ((j == height-1+20)|| (i == (height)/ 2))
                printf("h");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printO()
{
    int i, j, space = (height / 3);
    int width = height / 2 + height / 5 + space + space;
    for (i = 0; i < height; i++)
    {
        for (j = 29; j <= width+29; j++)
        {
            moveToX_Y(j,i);
            if (j == width - abs(space)+29|| j == abs(space)+29)
                printf("O");
            else if ((i == 0|| i == height - 1)&& j > abs(space)+29&& j < width - abs(space)+29)
                printf("O");
            else
                printf(" ");
        }
        if (space != 0&& i < height / 2)
        {
            space--;
        }
        else if (i >= (height / 2 + height / 5))
            space--;
        printf("\n");
    }
}
void printO1()
{
    int i, j, space = (height / 3);
    int width = height / 2 + height / 5 + space + space;
    for (i = 0; i < height; i++)
    {
        for (j = 37; j <= width+37; j++)
        {
            moveToX_Y(j,i);
            if (j == width - abs(space)+37|| j == abs(space)+37)
                printf("O");
            else if ((i == 0|| i == height - 1)&& j > abs(space)+37&& j < width - abs(space)+37)
                printf("O");
            else
                printf(" ");
        }
        if (space != 0&& i < height / 2)
        {
            space--;
        }
        else if (i >= (height / 2 + height / 5))
            space--;
        printf("\n");
    }
}

// Function to print the pattern of 'L'
void printL()
{
    int i, j,flag;
    for (i = 0; i < height; i++)
        {
            flag=1;
        for (j = 47; j <= height+47; j++)
            {
            moveToX_Y(j,i);
            if(flag)
            {
                printf("L");
                flag=0;
            }
            if (i == height - 1)
                printf("L");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printD()
{
    int i, j,flag;
    for (i = 7; i < height+7; i++)
        {
            flag=1;
        for (j = 0; j < height; j++)
            {
            moveToX_Y(j,i);
            if(flag)
            {
                printf("d");
                flag=0;
            }
            if ((i == 7 || i == height - 1+7)&& j < height - 1)
                printf("d");
            else if (j == height - 1 && i != 7&& i != height+7 - 1)
                printf("d");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print the pattern of 'A'
void printA()
{
    int n = width / 2, i, j;
    for (i = 7; i < height+7; i++)
        {
        for (j = 7; j <= width+7; j++)
        {
            moveToX_Y(j,i);
            if (j == n+7 || j == (width - n)+7|| (i == height+8 / 2 && j > n+7&& j < (width - n)+7))
                printf("a");
            else
                printf(" ");
        }
        printf("\n");
        n--;
    }
}

// Function to print the pattern of 'T'
void printT()
{
    int i, j;
    for (i = 7; i < height+7; i++)
    {
        for (j = 20; j < height+20; j++)
        {
            moveToX_Y(j,i);
            if (i == 7)
                printf("t");
            else if (j == (height / 2)+20)
                printf("tt");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printA1()
{
    int n = width / 2, i, j;
    for (i = 7; i < height+7; i++)
        {
        for (j = 27; j <= width+27; j++)
        {
            moveToX_Y(j,i);
            if (j == n+27 || j == (width - n)+27|| (i == height+8 / 2 && j > n+27&& j < (width - n)+27))
                printf("a");
            else
                printf(" ");
        }
        printf("\n");
        n--;
    }
}

// Function to print the pattern of 'B'
void printB()
{
    int i, j,flag=1;
    for (i = 7; i < height+7; i++)
        {
        flag=1;
        for (j = 45; j < width+45; j++)
        {
            moveToX_Y(j,i);
            if(flag)
            {
                printf("B");
                flag=0;
            }
            if ((i == 7 || i == height+7 - 1 || i == (height / 2)+7)&& j < (width+45 - 2))
                printf("B");
            else if (j == (width+45 - 2)&& !(i == 7 || i == height+7 - 1|| i == (height / 2)+7))
                printf("B");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void printA2()
{
    int n = width / 2, i, j;
    for (i = 7; i < height+7; i++)
        {
        for (j = 55; j <= width+55; j++)
        {
            moveToX_Y(j,i);
            if (j == n+55 || j == (width - n)+55|| (i == height+8 / 2 && j > n+55&& j < (width - n)+55))
                printf("a");
            else
                printf(" ");
        }
        printf("\n");
        n--;
    }
}

// Function to print the pattern of 'S'
void printS1()
{
    int i, j;
    for (i = 7; i < height+7; i++)
    {
        for (j = 67; j < height+67; j++)
        {
            moveToX_Y(j,i);
            if (i == 7 || i == (height / 2)+7|| i == height - 1+7)
                printf("s");
            else if (i < (height / 2)+7&& j == 67)
                printf("ss");
            else if (i > (height / 2)+7&& j == height - 1+67)
                printf("ss");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print the pattern of 'E'
void printE()
{
    int i, j,flag=1;
    for (i = 7; i < height+7; i++)
        {
            flag=1;
        for (j = 76; j < height+76; j++)
            {
                moveToX_Y(j,i);
                if(flag)
                {
                   printf("E");
                   flag=0;
                }
            if ((i == 7 || i == height - 1+7)|| (i == (height / 2)+7&& j <= (height / 2)+76))
                printf("E");
            else
                continue;
        }
        printf("\n");
    }
}


// Function print the pattern of the
// alphabets from A to Z
void printPattern(char character)
{
    switch (character)
    {
    case 'S':
        printS();
        printC();
        printH();
        printO();
        printO1();
        printL();
        printD();
        printA();
        printT();
        printA1();
        printB();
        printA2();
        printS1();
        printE();
        break;
    }
}


