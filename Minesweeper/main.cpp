#include <iostream>
#include <cstdlib>
using namespace std;


int hidden(){
cout << " ";
}

int board(){
    int r,c;
    cout<<"How many rows?: ";
    cin>>r;
    cout<<"How many Columns?: ";
    cin>>c;
    int table[r][c];

    //assigns each element
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            table[i][j] = i * j;

        }

    }


    //prints the table
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            table[i][j] = rand();

            cout <<  "[";
         //hides everything
             hidden();
            cout << "]";
        }
         std::cout << '\n';
         cout << endl;
    }
int sr,sc;
cout << "Select row: ";
cin >> sr;
cout << "Select column: ";
cin >> sc;

for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
//Prints required values on input and manages board
            if (table[sr][sc] == table[i][j]){
              cout <<  "[";
             if (table[sr][sc] % 3 == 0){
                cout << "-";
            }
            if (table[sr][sc] % 3 == 1){
                cout << "1";
                //For propagation if there are no bombs next
                if (table[sr + 1][sc] % 3 == 1){
                    cout <<  "[";
                    cout << "1";
                }
                if (table[sr - 1][sc] % 3 == 1){
                    cout << "1";
                }
                 if (table[sr][sc + 1] % 3 == 1){
                    cout << "1";
                }
                 if (table[sr][sc - 1] % 3 == 1){
                    cout << "1";
                }
                else{
                    hidden();
                }
                cout << "]";
            }
            if (table[sr][sc] % 3 == 2){
                cout << "X";
            }
            cout << "]";
            }
            else{
                cout <<  "[";
             hidden();
            cout << "]";
            }
        }
         std::cout << '\n';
         cout << endl;
    }

//For check win:
for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (table[sr][sc] == table[i][j]){
             if (table[sr][sc] % 3 == 0){
                cout << "You survived";
                //New game starts with chance to go on
                board();
            }

            if (table[sr][sc] % 3 == 2){
                //For mines
                //If one is hit, game is over
                cout << "You lose";
                exit;
            }
            if (table[sr][sc] % 3 == 1){
                cout << "You survived";
                board();
            }
            }
        }
    }
}





int main()
{
    board();
//best work done so far
    return 0;
}
