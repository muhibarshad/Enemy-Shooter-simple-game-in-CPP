//This code is written by Muhib Arshad

//Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include<ctime>

//Global Varaibles
using namespace std;
const int row = 20;
const int col = 100;

//Grid Making
void grid(char board[][col], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
    for (int i = 1; i < col - 1; i++)
    {
        board[0][i] = '_';
    }
    for (int i = 0; i < col; i++)
    {
        board[row - 1][i] = '-';
    }
    for (int i = 1; i < row - 1; i++)
    {
        board[i][0] = '|';
    }
    for (int i = 1; i < row - 1; i++)
    {
        board[i][col - 1] = '|';
    }

    //Emoji Palcement
    board[row - 2][col / 2] = 1;

    //Eneiemes Placement
    for (int i = 3; i < 8; i++)
    {
        for (int j = 20; j < 80; j++)
        {
            if (j % 2 == 0)
                board[i][j] = '&';
            else
                board[i][j] = ' ';
        }
    }

}

//Display the board
void display(char board[][col], int row, int score)
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        cout << "\t";
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    //Giving Score
    cout << "Your Score is:" << score << endl;
}

//Shooting bullet
int shoot(char board[][col], int row, int &rowPos, int &colPos)
{
    //Check left right there is no | and _ 
    if (board[rowPos - 2][colPos] != '&' && board[rowPos - 2][colPos] != '_')
    {
        //shooting bullet reaches at the enemy by swaping with the space ' '
        board[rowPos - 1][colPos] = '*';
        int temp;
        temp = board[rowPos - 1][colPos];
        board[rowPos - 1][colPos] = board[rowPos - 2][colPos];
        board[rowPos - 2][colPos] = temp;
        rowPos--;
        board[rowPos][colPos] = ' ';

        return rowPos;
    }

    //If it reaches the & and_ return 0
    if (board[rowPos - 2][colPos] == '&' || board[rowPos - 2][colPos] == '_')
    {
        
        return 0;
    }
}

//Move Left 
void moveleft(char board[][col], int row, int &colPos)
{
    if (colPos != 1)
    {
        if (board[row - 2][colPos] != '|')
        {
            int temp = board[row - 2][colPos];
            board[row - 2][colPos] = board[row - 2][colPos - 1];
            board[row - 2][colPos - 1] = temp;
            colPos--;
        }
    }
}

//Move right
void moveright(char board[][col], int row, int &colPos)
{
    if (colPos != col - 2)
    {
        if (board[row - 2][colPos] != '|')
        {
            int temp = board[row - 2][colPos];
            board[row - 2][colPos] = board[row - 2][colPos + 1];
            board[row - 2][colPos + 1] = temp;
            colPos++;
        }
    }
}

//Main exectuation
void shooting_game(char board[][col], int row)
{
    //local variables
    int rowPos = row - 2;
    int colPos = col / 2;
    char ch;
    int score = 0;
    bool flag = false;
    grid(board, row);
    display(board, row, score);

    //space lines
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }

    //Do while
    do
    {
        //input
        cout << "\t\t\t Enter s to shoot:" << endl;
        ch = getch();
        cout << "\a";
        ch = tolower(ch);
        switch (ch)
        {
        case 's':
        {
            int x = row - 2;
            while (x != 0)
            {
                //shooting flag 
                x = shoot(board, row, rowPos, colPos);
                //clear screen
                system("cls");
                //display again
                display(board, row, score);
                //if x=0 stop viewing the bullet and disapper it
                if (x == 0)
                {
                    if (board[rowPos - 2][colPos] != '_')
                    {
                        board[rowPos - 2][colPos] = ' ';
                        score++;
                    }
                        
                    board[rowPos - 1][colPos] = ' ';
                    
                }
            }
            system("cls");
            display(board, row, score);
            rowPos = row - 2;
            break;
        }
        case 'q':
        {
            cout << "Quiting................" << endl;
            flag = true;
            break;
        }
        case 'a':
        {
            moveleft(board, row, colPos);
            system("cls");
            display(board, row, score);
            break;
        }
        case 'd':
        {
            moveright(board, row, colPos);
            system("cls");
            display(board, row, score);
            break;
        }
        default:
        {
            cout << "You don't enter the valid key:" << endl;
            break;
        }
        }
    } while (flag == false);
}//main
int main()
{
    //board
    char board[row][col];
    shooting_game(board, row);
    return 0;
}