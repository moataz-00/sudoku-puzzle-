#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SIZE 9

int isSafe(char grid[SIZE][SIZE], int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == num)
        {
            return 0;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (grid[i][col] == num)
        {
            return 0;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(char grid[SIZE][SIZE])
{
    int row, col;
    int isFull = 1;

    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                isFull = 0;
                break;
            }
        }
        if (!isFull)
        {
            break;
        }
    }

    if (isFull)
    {
        return 1;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
            {
                return 1;
            }

            grid[row][col] = 0;
        }
    }

    return 0;
}
void print_sudoko(char arr[][9],char(*freq)[9])
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("------------------------------------\n");
    printf("  | 1  2  3  | 4  5  6  | 7  8  9  |\n");
    printf("------------------------------------\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    for(int i=0; i<9; i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

        printf("%c | ",i+'A');
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

        for(int j=0; j<9; j++)
        {
            if(freq[i][j]==0)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                printf("%d  ",arr[i][j]);

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

                printf("%d  ",arr[i][j]);

                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            if((j+1)%3==0)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

                printf("| ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            }
        }
        printf("\n");
        if((i+1)%3==0)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

            printf("------------------------------------\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
    }
}
void rules_sudoko(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    printf("\n*************************************** Rules Of sudoko ***************************************\n\n");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(yConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);

    printf("1. Babie Blue Num is Const You Cant Replace it By Any Num . \n\n");
    printf("2. You Cant Edit Num Like Any Num In Same ( Row || Colum || Square ) . \n\n");
    printf("3. You Can Edit Num By Enter Row , Colum And Value . \n\n");
    SetConsoleTextAttribute(yConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
char*freq_2d(char arr[][9])
{
    static char freq[9][9];
    char i,j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(arr[i][j]>0)
            {
                freq[i][j]=1;
            }
        }
    }
    return freq;
}
char check_out_arr(char col,char row)
{
    col=col-1;
    if(row>'Z'&&row<='z')
    {
        row=row-'a';
    }
    else if(row>='A'&&row<='Z')
    {
        row=row-'A';
    }
    if(col>8||row>8||col<0||row<0)
    {
        return 0;
    }
    return 1;
}
char check_value(char value)
{
    if(value>9||value<0)
    {
        return 0;
    }
    return 1;
}
char check_babie_blue(char col,char row,char(*freq)[9])
{
    col=col-1;
    if(row>'Z'&&row<='z')
    {
        row=row-'a';
    }
    else if(row>='A'&&row<='Z')
    {
        row=row-'A';
    }
    if (freq[row][col]==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char check_row(char (*arr)[9],int value,char row,char* index_c_r)
{
    int i;
    if(row>'Z'&&row<='z')
    {
        row=row-'a';
    }
    else if(row>='A'&&row<='Z')
    {
        row=row-'A';
    }
    for(i=0; i<9; i++)
    {
        if(arr[row][i]==value)
        {
            *index_c_r=i+1;
            return 0;
        }
    }
    return 1;
}
char check_colum(char (*arr)[9],int value,int col,char* index_c_c)
{
    int i;
    col=col-1;
    for(i=0; i<9; i++)
    {
        if(arr[i][col]==value)
        {
            *index_c_c=i;
            return 0;
        }
    }
    return 1;
}
char check_square(char(*arr)[9],char row,char col,char *row_square,char *col_square,char value)
{
    int i,j;
    col=col-1;
    if(row>'Z'&&row<='z')
    {
        row=row-'a';
    }
    else if(row>='A'&&row<='Z')
    {
        row=row-'A';
    }
    if(row<3&&col<3)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row<3&&col>=3&&col<6)
    {
        for(i=0; i<3; i++)
        {
            for(j=3; j<6; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row<3&&col>=6&&col<9)
    {
        for(i=0; i<3; i++)
        {
            for(j=6; j<9; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=3&&row<6&&col<3)
    {
        for(i=3; i<6; i++)
        {
            for(j=0; j<3; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=3&&row<6&&col>=3&&col<6)
    {
        for(i=3; i<6; i++)
        {
            for(j=3; j<6; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=3&&row<6&&col>=6&&col<9)
    {
        for(i=3; i<6; i++)
        {
            for(j=6; j<9; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=6&&row<9&&col<3)
    {
        for(i=6; i<9; i++)
        {
            for(j=0; j<3; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=6&&row<9&&col>=3&&col<6)
    {
        for(i=6; i<9; i++)
        {
            for(j=3; j<6; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    else if(row>=6&&row<9&&col>=6&&col<9)
    {
        for(i=6; i<9; i++)
        {
            for(j=6; j<9; j++)
            {
                if(arr[i][j]==value)
                {
                    *row_square=i+'A';
                    *col_square=j+1;
                    return 0;
                }
            }
        }
    }
    return 1;
}
int set(char(*arr)[9],char col,char row,char value,char(*freq)[9],char* index_c_r,char* index_c_c,char *row_square,char *col_square)
{
    char square_check=check_square(arr,row,col,row_square,col_square,value);
    char col_1=col-1,row_1;
    if(row>'Z'&&row<='z')
    {
        row_1=row-'a';
    }
    else if(row>='A'&&row<='Z')
    {
        row_1=row-'A';
    }
    if(check_babie_blue(col,row,freq)==0)
    {
        return 0;
    }
    if(check_colum(arr,value,col,index_c_c)==0||check_row(arr,value,row,index_c_r)==0)
    {
        return 0;
    }
    if(square_check==0)
    {
        return 0;
    }
    if(check_out_arr(col,row)==0)
    {
        return 0;
    }
    if(check_value(value)==0)
    {
        return 0;
    }
    arr[row_1][col_1]=value;
    return 1;
}
char check_all_arr(char (*arr)[9])
{
    int i,j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(arr[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int x,y,value;
    char mess=0,index_c_r,index_c_c,col_square,row_square;
    char arr[9][9]= { 0,4,0,  0,0,7,   6,0,0,
                      8,0,6,  0,4,0,   0,3,0,
                      0,2,7,  0,0,0,   0,0,8,

                      0,0,0,  4,8,0,   0,0,3,
                      0,9,0,  7,0,6,   0,4,0,
                      2,0,0,  0,1,3,   0,0,0,

                      4,0,0,  0,0,0,   8,1,0,
                      0,5,0,  0,3,0,   2,0,4,
                      0,0,1,  5,0,0,   0,6,0,
                    };
    char arr_c[9][9]= { 0,4,0,  0,0,7,   6,0,0,
                        8,0,6,  0,4,0,   0,3,0,
                        0,2,7,  0,0,0,   0,0,8,

                        0,0,0,  4,8,0,   0,0,3,
                        0,9,0,  7,0,6,   0,4,0,
                        2,0,0,  0,1,3,   0,0,0,

                        4,0,0,  0,0,0,   8,1,0,
                        0,5,0,  0,3,0,   2,0,4,
                        0,0,1,  5,0,0,   0,6,0,
                      };
    char (*freq)[9]=freq_2d(arr);
    char square_check;
    char done=check_all_arr(arr);
    while(1)
    {
        mess=0;
        system("cls");
        rules_sudoko();
        print_sudoko(arr,freq);
        printf("Enter Row And Colum\n");
        fflush(stdin);
        scanf("%c%d",&y,&x);
        Beep(524,600);
        printf("Enter Value\n");
        scanf("%d",&value);
        Beep(524,600);
        while(set(arr,x,y,value,freq,&index_c_r,&index_c_c,&row_square,&col_square)==0&&mess!='Q'&&mess!='q'&&mess!='S'&&mess!='s')
        {
            system("cls");
            rules_sudoko();
            if(check_out_arr(x,y)==0||check_value(value)==0)
            {
                if(check_out_arr(x,y)==0)
                {
                    system("cls");
                    rules_sudoko();
                    print_sudoko(arr,freq);
                    HANDLE pConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(pConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("<<<<<<<<<< ERROR <<<<<<<<<<\nEnter Correct Row And Colum\n");
                    SetConsoleTextAttribute(pConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("Enter Row And Colum\n");
                    Beep(724,800);
                    fflush(stdin);
                    scanf("%c%d",&y,&x);
                    Beep(524,600);
                    printf("Enter Value\n");
                    scanf("%d",&value);
                    Beep(524,600);
                }
                if(check_value(value)==0)
                {
                    system("cls");
                    rules_sudoko();
                    print_sudoko(arr,freq);
                    HANDLE pConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(pConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("<<<<<<<<<< ERROR <<<<<<<<<<\nEnter Correct value\n");
                    SetConsoleTextAttribute(pConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    printf("Enter Row And Colum\n");
                    Beep(724,800);
                    fflush(stdin);
                    scanf("%c%d",&y,&x);
                    Beep(524,600);
                    printf("Enter Value\n");
                    scanf("%d",&value);
                    Beep(524,600);
                }
            }
            else
            {
                if(check_babie_blue(x,y,freq)==0)
                {
                    Beep(724,800);
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf(">>>>>>>> You Cant Replace Babie Blue Num <<<<<<<<\n\n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                if(check_colum(arr,value,x,&index_c_c)==0)
                {
                    Beep(724,800);
                    HANDLE xConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(xConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf(">>>>>>>> There is Same Num in Row %c And Colum %d <<<<<<<<<\n\n",index_c_c+'A',x);
                    SetConsoleTextAttribute(xConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                if(check_row(arr,value,y,&index_c_r)==0)
                {
                    Beep(724,800);
                    HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(yConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf(">>>>>>>> There is Same Num in Row %c And Colum %d <<<<<<<<\n\n",(y-'a'+'A'),index_c_r);
                    SetConsoleTextAttribute(yConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                if(check_square(arr,y,x,&row_square,&col_square,value)==0)
                {
                    Beep(724,800);
                    HANDLE iConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(iConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf(">>>>>>>> There is Same Num in Square at Row %c And Colum %d <<<<<<<<\n\n",row_square,col_square);
                    SetConsoleTextAttribute(iConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                print_sudoko(arr,freq);
                printf("To Continue Enter Q Or If You Give Up Enter S To Solution\n");
                fflush(stdin);
                scanf("%c",&mess);
                Beep(524,600);
                if(mess=='Q'||mess=='q')
                {
                    break;
                }
                else if(mess=='S'||mess=='s')
                {
                    if (solveSudoku(arr_c))
                    {
                        system("cls");
                        rules_sudoko();
                        printf("Solution:\n");
                        Beep(824,1000);
                        print_sudoko(arr,freq);
                        printf("************************************************ GOOD LUCK BROO ************************************************\n");
                    }
                    else
                    {
                        printf("No solution exists.\n");
                    }
                }
            }
        }
        done=check_all_arr(arr);
        if(check_all_arr(arr_c)==1||done==1)
        {
            system("cls");
            rules_sudoko();
            print_sudoko(arr_c,freq);
            Beep(824,1000);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("\n\n\n");
            printf("      YY      YY               U        U       W               W   IIIIIIII   NN        NN\n");
            printf("       YY    YY      OOOOOO    U        U       W               W      II      NNN       NN\n");
            printf("        YY  YY      O      O   U        U       W               W      II      NNNN      NN\n");
            printf("         YYY       O        O  U        U       W       W       W      II      NN NN     NN\n");
            printf("         YYY       O        O  U        U       W      W W      W      II      NN  NN    NN\n");
            printf("         YYY       O        O  U        U       W     W   W     W      II      NN   NN   NN\n");
            printf("         YYY       O        O  U        U       W    W     W    W      II      NN    NN  NN\n");
            printf("         YYY       O        O  U        U       W   W       W   W      II      NN     NN NN\n");
            printf("         YYY       O        O  U        U       W  W         W  W      II      NN      NNNN\n");
            printf("         YYY        O      O    U      U        W W           W W      II      NN       NNN\n");
            printf("         YYY         OOOOOO      UUUUUU         WW             WW   IIIIIIII   NN        NN\n\n\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            return 0;
        }
    }
    return 0;
}

