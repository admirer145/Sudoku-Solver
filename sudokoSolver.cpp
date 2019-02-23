#include<bits/stdc++.h>
using namespace std;

int arr[9][9];

bool issafe(int arr[][9], int i,int j, int val)
{
    // Row
    for(int k=0;k<9;k++)
        if(arr[i][k]==val && k!=j)
            return false;

    // Column
    for(int k=0;k<9;k++)
        if(arr[k][j]==val && k!=i)
            return false;

    // BLOCK 3*3
    int x=(i/3)*3;
    int y=(j/3)*3;
    for(int l=x;l<x+3;l++)
        for(int m=y;m<y+3;m++)
            if(arr[l][m]==val && l!=i && m!=j)
                return false;

    return true;
}

// Printing the Sudoku
void print()
{
        cout<<endl;
        for(int j=0;j<13;j++)
            cout<<"- ";
        cout<<endl;
        for(int i=0;i<9;i++)
        {
	        for(int j=0;j<9;j++)
	        {
	            if(j%3==0)
	                cout<<"| ";
	            cout<<arr[i][j]<<" ";
	        }
            cout<<"|"<<endl;
            if((i+1)%3==0)
            {
                for(int j=0;j<13;j++)
                    cout<<"- ";
            }
            cout<<endl;
        }
}

bool solve(int arr[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    arr[i][j]=k;
                    if(issafe(arr,i,j,k) && solve(arr))
                        return true;
                    else
                        arr[i][j]=0;// backtrack
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // INPUT 0 for empty cell
    cout<<"Enter grid[9*9]:\n";
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>arr[i][j];

    if(solve(arr))
        print();
    else
        cout<<"Please enter correct sudoku .."<<endl;
    system("pause");
	return 0;
}
