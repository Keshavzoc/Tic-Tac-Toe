#include<iostream>
using namespace std;
// board
void drawBoard(char board[3][3]){
    cout<<"--------------\n";
    for (int i = 0; i < 3; i++)
    { 
        for (int j = 0; j < 3; j++)
        {
            cout<<board[i][j]<<" | ";
            
        } 
        cout<<"\n--------------\n";
        
    }
    
}

// checkwin function
bool checkwin(char board[3][3], char player){
     for (int i = 0; i <3; i++)
     {
        if (board[i][0]== player && board[i][1]==player && board[i][2]== player)
        {
          return true;
        }
         if (board[0][i]== player && board[1][i]==player && board[2][i]== player)
        {
          return true;
        }
     }
         if (board[0][0]== player && board[1][1]==player && board[2][2]== player)
        {
          return true;
        }
         if (board[0][2]== player && board[1][1]==player && board[2][0]== player)
        {
          return true;
        }
         return false;
     
}


int main(){
    // Taking row and column from the user:
    char board[3][3] = {{ ' ', ' ', ' '},
                     { ' ', ' ', ' '},
                     { ' ', ' ', ' '} };
char player = 'X';
int row , col;
int turn;
cout<<"Welcome To Tic Tac Toe Game:"<<endl;

// outer loop 
for( turn = 0; turn < 9; turn++)
{
    drawBoard(board);

   while (true){
    cout<<"player "<<player<<endl;
    cout<<"Enter the rows (0-2): ";
    cin>>row;
    cout<<"Enter the column (0-2: ): ";
    cin>>col;
    if (board[row][col]!=' ' || row<0 || row>2 || col<0 || col>2)
    {
        cout<<"Invalid Move: Try again.\n";
    } else{
        break;
    }
    
   }
   // Make row and col
   board[row][col] = player;

   // check for win
   if (checkwin(board,player))
   {
    drawBoard(board);
    cout<<"Player "<<player<<" wins\n";
      break;
   } 
   player = (player == 'X')? 'O' : 'X';
   
  }     

  // End the game;

  drawBoard(board);
  if (turn==9 && !checkwin(board, 'X' && !checkwin(board, 'O')))
  {
   cout<<"It's Draw.\n";

  }
  return 0;

}