#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int puzz[9][9];

int solve();
int checkIfZero(int *row, int *col);
int checkAll(int row, int col, int num);
int checkRow(int row, int num);
int checkCol(int col, int num);
int checkBox(int row, int col, int num);
void printPuzzle();

int main()
{
    int  i,j;
    FILE *fptr;

    fptr=fopen("Puzzle.txt","r");
//READS THE PUZZLE FROM THE .TXT FILE AND INSERTS IT INTO AN ARRAY
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            fscanf(fptr,"%d",&puzz[i][j]);
            //temp[i][j]=puzz[i][j];
        }
    }
    fclose(fptr);
    //solve(puzz);
    if(solve())
        printPuzzle();
    else
        //printPuzzle();
        printf("No solution");
    return 0;
}


int solve()
{
    int row=0,col=0,num;
    if(checkIfZero(&row,&col))
    {

        return 1;
    }


    for(num=1; num<=9; num++)
    {

        if(checkAll(row, col, num))
        {
            //printf("ok");
            puzz[row][col]=num;
            if(solve())
                return 1;
            puzz[row][col]=0;//

        }
    }

    return 0;
}
int checkIfZero(int *row, int *col)
{

    for(*row=0;*row<9;(*row)++)
    {
        for(*col=0;*col<9;(*col)++)
        {
            if(puzz[*row][*col]==0)
                return 0;
        }
    }
    return 1;
}
int checkAll(int row, int col, int num)
{
    return checkRow(row, num)&&
           checkCol(col, num)&&
           checkBox(row, col, num);
}
int checkRow(int row, int num)
{
    int col;
    for(col=0;col<9;col++)
    {
        if(puzz[row][col]==num)
            return 0;
    }
    return 1;
}
int checkCol(int col, int num)
{
    int row;
    for(row=0;row<9;row++)
    {
        if(puzz[row][col]==num)
            return 0;
    }
    return 1;
}
int checkBox(int row, int col, int num)
{
    row=row-row%3;
    col=col-col%3;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(puzz[i+row][j+col]==num)
                return 0;
        }
    }
    return 1;
}

//PRINTS THE PUZZLE INTO THE COMMAND WINDOW WITH DASHES AND PIPES
void printPuzzle()
{
    int i=0,j,k;

    for(i=0;i<9;i++)
    {
        if((i)%3==0)
           {
        for(k=0;k<31;k++)
        {
            printf("-");
        }
           }
        printf("\n");
        printf("|");
        for(j=0;j<9;j++)
        {
        printf(" %d ",puzz[i][j]);
        if((j+1)%3==0)
        {
        printf("|");
        }
        }
        printf("\n");
    }
    for(k=0;k<31;k++)
    {
        printf("-");
    }
    printf("\n");
}



