#include <iostream>
#include <cmath>
using namespace std;
int checkBound(int i, int size);
const int maxSize = 15;

int main()
{
    
    int size = 0;
    string sizeStr;
    int row;
    int col;
    //make the magic squares
    int ms[maxSize][maxSize];
    int ms2[maxSize][maxSize];
    int ms3[maxSize][maxSize];
    int ms4[maxSize][maxSize];
    
    cout << "Please give an odd number between 3 and 15 for the size of the Magic Square."<<endl;
    cin >> size;
    
    //while loop check if size is in bound
    bool check (false);
    while (check == false)
    {
        
        //check if size is in bound
        if (size < 3 || size > 15)
        {
            cout <<"Input is outside of the bound, please try again."<<endl;
            cin >> size;
        }
        //check if size is odd
        else if(size % 2 == 0)
        {
            cout <<"Size must be an odd number, please try again."<<endl;
            cin >> size;
        }
        //if size is in bound and odd
        else
        {
            check = true;
        }
    }
    
    
    
    //fill up with 0's, so it's "empty"
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            ms[i][j] = 0;
        }
    }

    cout << ms[9][10];
    
    //start from the top mid
    row = 0;
    col = size/2;
    
    for (int i = 1; i <= pow(size,2); i ++)
    {
        if ( ms[row][col] == 0) //if the spot is empty 
        {
            ms[row][col] = i;
            row --; //use up 1 right one, the Siamese method to calculate
            col ++;
            row = checkBound(row, size); //use checkBound to check the positons if still in the array
            col = checkBound(col, size); 
        }
        else //if the spot is not empty
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
   
    //out put Magic Square #1
    cout << "Magic Square #1 is:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            cout<<ms[i][j] << "\t";
        }
        cout << "\n";
    }
    
    int sums[size];
    int sum;
    
    //row calculation
    for (int r = 0; r < size; r++)
    {
        sum = 0;
        for (int c = 0; c < size; c++)
        {
            sum += ms[r][c];
        }
        sums[r]= sum;
    }
    
    cout << "Checking the sums of every row:      ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //column calculation
    for (int c = 0; c < size; c++)
    {
        sum = 0;
        for (int r = 0; r < size; r++)
        {
            sum += ms[r][c];
        }
        sums[c]= sum;
    }
    
    cout << "Checking the sums of every column:   ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //diagnoal calculation
    cout << "Checking the sums of every diagnoal: ";
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ms[i][i];
    }
    cout << sum << " ";
    
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        int j = size - 1 - i;
            sum += ms[i][j];
        
    }
    cout << sum << endl;
    
    //start magic square #2
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ms2[size - 1 - j][i] = ms[i][j];
        }
    }
    //out put Magic Square #2
    cout << "Magic Square #2 is:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            cout<<ms2[i][j] << "\t";
        }
        cout << "\n";
    }
    
    //row calculation
    for (int r = 0; r < size; r++)
    {
        sum = 0;
        for (int c = 0; c < size; c++)
        {
            sum += ms2[r][c];
        }
        sums[r]= sum;
    }
    cout << "Checking the sums of every row:      ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //column calculation
    for (int c = 0; c < size; c++)
    {
        sum = 0;
        for (int r = 0; r < size; r++)
        {
            sum += ms2[r][c];
        }
        sums[c]= sum;
    }
    
    cout << "Checking the sums of every column:   ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //diagnoal calculation
    cout << "Checking the sums of every diagnoal: ";
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ms2[i][i];
    }
    cout << sum << " ";
    
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        int j = size - 1 - i;
            sum += ms2[i][j];
        
    }
    cout << sum << endl;
    
    //magic square #3
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ms3[size - 1 - j][i] = ms2[i][j];
        }
    }
    //out put Magic Square #3
    cout << "Magic Square #3 is:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            cout<<ms3[i][j] << "\t";
        }
        cout << "\n";
    }
    
    //row calculation
    for (int r = 0; r < size; r++)
    {
        sum = 0;
        for (int c = 0; c < size; c++)
        {
            sum += ms3[r][c];
        }
        sums[r]= sum;
    }
    cout << "Checking the sums of every row:      ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //column calculation
    for (int c = 0; c < size; c++)
    {
        sum = 0;
        for (int r = 0; r < size; r++)
        {
            sum += ms3[r][c];
        }
        sums[c]= sum;
    }
    
    cout << "Checking the sums of every column:   ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //diagnoal calculation
    cout << "Checking the sums of every diagnoal: ";
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ms3[i][i];
    }
    cout << sum << " ";
    
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        int j = size - 1 - i;
            sum += ms3[i][j];
        
    }
    cout << sum << endl;
    
    //magic square #4
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ms4[size - 1 - j][i] = ms3[i][j];
        }
    }
    //out put Magic Square #4
    cout << "Magic Square #4 is:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            cout<<ms4[i][j] << "\t";
        }
        cout << "\n";
    }
    
    //row calculation
    for (int r = 0; r < size; r++)
    {
        sum = 0;
        for (int c = 0; c < size; c++)
        {
            sum += ms4[r][c];
        }
        sums[r]= sum;
    }
    cout << "Checking the sums of every row:      ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //column calculation
    for (int c = 0; c < size; c++)
    {
        sum = 0;
        for (int r = 0; r < size; r++)
        {
            sum += ms4[r][c];
        }
        sums[c]= sum;
    }
    
    cout << "Checking the sums of every column:   ";
    for (int i = 0; i < size; i++)
    {
        cout << sums [i] << " ";
    }
    cout << "\n";
    
    //diagnoal calculation
    cout << "Checking the sums of every diagnoal: ";
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ms4[i][i];
    }
    cout << sum << " ";
    
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        int j = size - 1 - i;
            sum += ms4[i][j];
        
    }
    cout << sum << endl;
    
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



