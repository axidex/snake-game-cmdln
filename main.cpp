#include <iostream>
#include<conio.h>
#include <windows.h>
#include <ctime>

using namespace std;




bool gameover;
const int width = 40;
const int height = 30;
int x,y,xDot,yDot,score;
int tailX[100],tailY[100];
enum eDir{STOP = 0,LEFT,RIGHT,UP,DOWN};
eDir dir;
void Setup()
{
    gameover = false;
    dir = STOP;
    x = width/2-1;
    y = height/2-1;
    xDot = rand() % width;
    yDot = rand() % height;
    score = 0;
    
}
void Draw()
{
    Sleep(33);
    system("cls");
    for (int i = 0; i < width+1;i++)    
        cout << "#";
    cout<<endl;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0;j< width;j++)
        {
            if (j == 0|| j == width-1)
                cout << "#";
            else if (i == y && j == x)
                {
                cout << "0";
                
                }
            else if (i == yDot&& j == xDot)
                {
                cout << "D";
            
                }
            else 
            {
                bool print = false;
                for (int k = 0 ; k < score ; k++ )
                {
                    
                    if (tailX[k] == j && tailY[k] == i )
                        {
                        print = true;
                        cout << "o";
                        }
                }
                if (!print)
                cout << " ";
            }
            
        }
        cout << endl;
    }
    for (int i = 0; i < width+1;i++)    
        cout << "#";
    cout<<endl;
    cout << "Score: "<< score <<endl;
}
void Input ()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
void Logic ()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x ;
    tailY[0] = y ;
    for (int i = 1 ;i < score;i++ )
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {   
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    //if (x >width|| x < 0 || y> height || y < 0)
    //    gameover = true;
    if (x >= width - 2 )
        x = 1;
    else if (x < 1)
        x = width - 2;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1 ;
    for (int i = 0 ; i< score ; i++)
    {
        if(tailX[i] == x && tailY[i] == y  )
            gameover = true;
    }
    if (x == xDot && y == yDot)
    {
        score++;
        xDot = rand() % width;
        yDot = rand() % height;
    }
     

}
int main ()
{
    srand (time(NULL));
    Setup();
    while(!gameover)
    {
        Sleep(33);
        Draw();
        Input();
        Logic();
    }
    system("pause");
    return 0 ;
}