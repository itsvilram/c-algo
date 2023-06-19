// Code by nighking__11
#include<bits/stdc++.h>
using namespace std;
#define I 1
#define You 2
#define MyMove 'O'
#define YourMove 'X'
#define SIDE 3
// below function to Show current board

void Print_board(vector<vector<char>>&board)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<board[i][j];
            if(j<2)
                cout<<" | ";
        }
        cout<<'\n';
        if(i<2){
            cout<<"---------";
            
        }
         cout<<'\n';
        
        
    }
}
// Start the Game by calling this function
void StartGame(vector<vector<char>>&grid)
{
    Print_board(grid);
    cout<<"Choose a number between 1 to 9 cell to Play the Game"<<'\n';

}
void WhoisWinner(int turn)
{
    if(turn==I)
    cout<<"I have won!"<<'\n';
    else
    cout<<"You have won!"<<'\n';
}
bool isrow(vector<vector<char>>board)
{
    for(int i=0; i<3; i++)
    {
        char player=board[i][0];
        if(player=='-')
            continue;
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
            return true;
    }
    return false;
}
bool iscol(vector<vector<char>>board)
{
    for(int i=0; i<3; i++)
    {
        char player=board[0][i];
        if(player=='-')
            continue;
        if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
            return true;
    }
    return false;
}
bool isdiag(vector<vector<char>>board)
{
    char firs_diag=board[0][0];
    char sec_diag=board[0][2];
    if(firs_diag!='-')
    {
        if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
            return true;
    }
    if(sec_diag!='-')
    {
        if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
            return true;
    }
    return false;  
}
bool isGameOver(vector<vector<char>>&board)
{
    if(isrow(board)==true)
        return true;
    if(iscol(board)==true)
        return true;
    if(isdiag(board)==true)
        return true;

    return false;
}
int minimax(vector<vector<char>>board, int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (isGameOver(board) == true)
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if(depth < 9)
        {
            if(isAI == true)
            {
                bestScore = -999;
                for(int i=0; i<SIDE; i++)
                {
                    for(int j=0; j<SIDE; j++)
                    {
                        if (board[i][j] == '-')
                        {
                            board[i][j] = MyMove;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = '-';
                            if(score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 999;
                for (int i = 0; i < SIDE; i++)
                {
                    for (int j = 0; j < SIDE; j++)
                    {
                        if (board[i][j] == '-')
                        {
                            board[i][j] = YourMove;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = '-';
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
// int minimax(vector<vector<char>>&board,int depth,bool is_me)
// {
//     int score=0;
//     int best_score=0;
//     if(isGameOver(board)==true)
//     {
//         if(is_me==true)
//             return -1;
//         else
//             return 1;
//     }
//     else
//     {
//     if(depth<9)
//     {
//         if(is_me==true)
//         {
//             best_score=-999;
//             for(int i=0; i<3; i++)
//             {
//                 for(int j=0; j<3; j++)
//                 {
//                     if(board[i][j]!='-')
//                         continue;
//                     board[i][j]=MyMove;
//                     score=minimax(board,depth+1, false);
//                     board[i][j]='-';
//                     if(score>best_score)
//                     {
//                         best_score=score;

//                     }
//                 }
//             }
//             return best_score;
//         }
//         else
//         {
//             best_score=999;
//             for(int i=0; i<3; i++)
//             {
//                 for(int j=0; j<3; j++)
//                 {
//                     if(board[i][j]!='-')
//                         continue;
//                     board[i][j]=YourMove;
//                     score=minimax(board,depth+1,true);
//                      board[i][j]='-';
//                     if(score<best_score)
//                     {
//                         score=best_score;
//                     }
//                 }
//             }
//             return best_score;
//         }
//     }
//     else
//     {
//         return 0;
//     }

//     }
//    return 0;
// }
pair<int,int>Optimal_Move(vector<vector<char>>board,int moves)
{
    int score=0;
    int best_score=-999;
    int row=-1;
    int col=-1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j]!='-')
                continue;
            board[i][j]=MyMove;
            score=minimax(board,moves+1,false);
            board[i][j]='-';
            if(score>best_score)
            {
                score=best_score;
                row=i;
                col=j;
            }
        }
    }
    return {row,col};
}
bool is_in_valid_move(int move,vector<int>&valid_moves)
{
    bool okay=false;
    for(int i=0; i<valid_moves.size(); i++)
    {
        if(valid_moves[i]==move)
            okay=true;
    }
    return okay;
}
void PlayingTicTacToe(int turn)
{
    vector<vector<char>>board(3,vector<char>(3,'-'));
    StartGame(board);
    int row=0;
    int col=0;
    int moves=0;
    while(isGameOver(board)==false&&moves!=9)
    {
        if(turn==I)
        {
            pair<int,int>next_move;
            next_move=Optimal_Move(board,moves);
            int r=next_move.first;
            int c=next_move.second;
            cout<<"My next Move is on "<<(r*3+c+1)<<'\n';
            board[r][c]=MyMove;
            Print_board(board);
            turn=You;
            moves++;

        }
        else
        {
            cout<<"Your next Move can be on following Positions"<<'\n';
            vector<int>valid_moves;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(board[i][j]=='-')
                    {
                        cout<<(i*3+j+1)<<' ';
                        valid_moves.push_back(i*3+j+1);
                    }
                }
            }
            cout<<'\n';
            cout<<"Choose Your Move Wisely"<<'\n';
            int move;
            cin>>move;
            while(!is_in_valid_move(move,valid_moves))
            {
                cout<<"Choose a valid a move"<<'\n';
                  cout<<"Choose Your Move Wisely"<<'\n';
                cin>>move;
            }
            move--;
            int r=move/3;
            int c=move%3;
            board[r][c]=YourMove;
            Print_board(board);
            moves++;
            turn=I;
        }   
 
    }
      if(moves==9&&isGameOver(board)==false)
        {
            cout<<"It's Draw"<<'\n';
        }
        else
        {
            if(turn==I)
                turn=You;
            else
                turn=I;
            WhoisWinner(turn);
        }
        return;
}
int main()
{
    cout<<"Tic Tac Toe Game by nightking__11"<<'\n';
    cout<<"Play With Me"<<'\n';
    vector<vector<char>>grid(3,vector<char>(3));
    int moves=0;
    for(char x='1'; x<='9'; x++)
    {
        int row=moves/3;
        int col=moves%3;
        moves++;
        grid[row][col]=x;
    }
    Print_board(grid);
    char want_play='Y';
    while(want_play=='Y'||want_play=='y')
    {

        cout<<"Do You Want Play First"<<'\n';
        char choice;
        cout<<"Please Select Y for Yes Or N for No"<<'\n';
        cin>>choice;
        if(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
        {
            cout<<"Please Select Y for Yes Or N for No"<<'\n';
            cin>>choice;
        }
        if(choice=='y'||choice=='Y')
        {
            PlayingTicTacToe(You);
        }
        else
        {   
            PlayingTicTacToe(I);
        }
        cout<<"Do You Still Want To Play?"<<'\n';
        cin>>want_play;
    }
    return 0;
}