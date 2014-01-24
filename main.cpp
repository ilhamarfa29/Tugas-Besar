#include <cstdlib>
#include <iostream>

using namespace std;

// Masih tic tac toe 3x3
 
class TicTacToe
{
      public:
             TicTacToe();      
             void initializeBoard();
             void PrintBoard();
             void getInput( char ,size_t&,size_t&);
             bool OccupySquare(size_t,size_t, char );
             char CheckForWinner(); 
             bool checkHorizontal( char );
             bool checkVertical( char );
             bool checkDiagonal( char );
             bool IsScratch();
             void printWinner(char);
             bool IsValidLocation( size_t,size_t);        
             void InitializeBoard();
             static const size_t rows = 3;
             static const size_t cols = 3;
      private:
              char board[rows][cols];
};

int main()
{
    size_t r,c;
    char winner;

    TicTacToe a;
    while(true)
    {
               a.getInput('X',r,c);
               a.PrintBoard();
               winner=a.CheckForWinner();
               if (winner!=' ')  
                  break;

               a.getInput('O',r,c);
               a.PrintBoard();
               winner=a.CheckForWinner();
               if (winner!=' ') 
                  break;
    }
    a.printWinner(winner);
    system("pause");
    return 0;
}

TicTacToe::TicTacToe()
{ 
    InitializeBoard();
}

void TicTacToe::InitializeBoard()
{
     for (int i = 0; i<rows; i++)
     {  
         for (int j = 0; j<cols; j++)
         {
             board[i][j]= ' ';
         }
     }
}

void TicTacToe::PrintBoard()
{
     int t;
     for(t=0; t<3; t++) 
     {
              cout<<" "<<board[t][0]<<" | "<< board[t][1]<<" | "<< board[t][2];  
              if(t!=2) cout<<"\n---|---|---\n";
     }
     cout<<"\n"; 
}

char TicTacToe:: CheckForWinner()
{
     if (checkHorizontal('X'))
     {
              return 'X';
     }
     if (checkVertical( 'X'))
     {
              return 'X';
     }
     if (checkDiagonal( 'X'))
     {
              return 'X';
     }
     if (checkHorizontal('O'))
     {
              return 'O';
     }
     if (checkVertical( 'O'))
     {
              return 'O';
     }
     if (checkDiagonal( 'O'))
     {
              return 'O';
     }
     if (IsScratch())
     {
              return 'T';
     }
     return ' ';
}


bool TicTacToe::checkHorizontal( char marker)
{
     int i,j,count;
     for(i=0; i<rows; i++)
     {
              count=0;
              for(j=0;j<cols;j++)
              if(board[i][j]==marker)
                       count++;
              if(count==3)
                        return true;
    }
return false;
}

bool TicTacToe::checkVertical( char marker)
{
     int i,j,count;
     for(i=0; i<rows; i++)
     {
              count=0;
              for(j=0;j<cols;j++)
                        if(board[j][i]==marker)
                                count++;
                        if(count==3)
                                return true;
    }
return false;
}

bool TicTacToe::checkDiagonal( char marker)
{
     if(board[0][0]==board[1][1] && board[1][1]==board[2][2]&& board[0][0]==marker)
          return true;
     if(board[0][2]==board[1][1] && board[1][1]==board[2][0]&& board[0][2]==marker)
          return true;
     return false;
}

bool TicTacToe::IsScratch()
{
     int i,j;
     for(i=0;i<rows;i++)
         for(j=0;j<cols;j++)
             if(board[i][j]==' ')
                return false;
     return true;
}

void TicTacToe::printWinner(char marker)
{ 
     if(marker=='T')
         cout<<"TIE GAME!\n";
     else
         cout<<"The winner is "<<marker<<"!!!\n";
}

void TicTacToe::getInput(char marker,size_t &r,size_t &c)
{
     for(;;)
     {
            cout<<"Player "<<marker<<endl;
            cout << "Enter move row(1-3): " ;
            cin >> r;
            cout << "Enter move column(1-3): " ;
            cin >> c;
            if (OccupySquare(r,c,marker) )
            {
                return ;
            }

             cout << "Invalid Move: Please Try Again\n\n";
    }
}

bool TicTacToe::IsValidLocation(size_t r,size_t c)
{
     if(r<1||r>rows||c<0||c>cols)
        return false;
     if(board[r-1][c-1]!=' ')
        return false;
     else
        return true;
}

bool TicTacToe::OccupySquare( size_t r,size_t c, char marker)
{
     if(IsValidLocation( r,c))
        {
              board[r-1][c-1]=marker;
              return true;
        }
     return false;
}
