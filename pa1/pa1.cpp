#include <iostream>
#include <cmath>
using namespace std;
int checkBound(int i, int size);

int main()
{
    int size;
    int row;
    int col;
    int test;
    
    cout << "Please give an odd number between 3 and 15 for the size of the Magic Square."<<endl;
    cin >> size;
    bool check (false);
    //while loop check if size is in bound
    while (check == false)
    {
        //check if size is in bound
        if (size < 3 || size > 15)
        {
            cout<<"Input is outside of the bound, please try again."<<endl;
            cin>> size;
        }
        //check if size is odd
        else if(size % 2 == 0)
        {
            cout<<"Size must be an odd number, please try again."<<endl;
            cin>> size;
        }
        //if size is in bound and odd
        else
        {
            check = true;
        }
    }
    
    //make the magic square
    int ms[size][size];
    
    //fill up with 0's, so it's "empty"
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            ms[i][j] = 0;
        }
    }
    
    //start from the top mid
    row = 0;
    col = size/2;
    
    for (int i = 1; i <= pow(size,2); i ++)
    {
        if ( ms[row][col] == 0) //if the spot is empty 
        {
            ms[row][col] = i;
            row --;
            col ++;
            row = checkBound(row, size);
            col = checkBound(col, size);
        }
        else
        {
            row ++;
            row = checkBound(row, size);
            
            row ++;
            row = checkBound(row, size);
            
            col --;
            col = checkBound(col, size);
            
            ms[row][col] = i;
            row --;
            col ++;
            
            row = checkBound(row, size);
            col = checkBound(col, size);
        }
    }
   
    
    
    cout << "Magic Square #1 is:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            cout<<ms[i][j] << "  ";
        }
        cout << "\n";
    }
    
    int sums[size];
    int sum;
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += ms[i][j];
        }
        sums[i]= sum;
    }
    
    cout << "Checking the sums of every row: ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
}

int checkBound(int i, int size)
{
    if (i < 0)
    {
        i = size - 1;
    }
            
    if (i > (size - 1))
    {
        i = 0;
    }
    
    return i;
}

