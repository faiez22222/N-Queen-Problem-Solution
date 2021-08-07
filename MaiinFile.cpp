#include<bits/stdc++.h>
#include <windows.h>

using namespace std;
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
bool canPlace(int arr[9][9],int i,int j,int n,int number);
bool solve(int arr[9][9],int i,int j,int n);

bool canPlace(char arr[][100],int i,int j,int n)
{
    // cheking rows and column conflicts
    for(int k=0;k<n;k++)
    {
       if(arr[k][j]=='Q' or arr[i][k]=='Q')
       {
         return false;
       }
    }
    //Checking Diogonals conflicts
    int k=j;
    int l=i;
    while(k!=n) 
    {
      if(arr[l][k]=='Q') return false;
      k++;
      l++;
    }
    k=j;
    l=i;
    while(l>=0)
    {
      if(arr[l][k]=='Q') return false;
      l--;
      k--;
    }
    k=j;
    l=i;
    while(k>=0)
    {
      if(arr[l][k]=='Q') return false;
      k--;
      l++;
    }
    k=j;
    l=i;
    while(l>=0)
    {
      if(arr[l][k]=='Q') return false;
      l--;
      k++;
    }
    return true;
}
bool solve(char arr[][100],int i,int j,int n)
{
   // Base case
    if(i==n)
    {
       // Print the final matrix
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<n;j++) 
         {
            if(arr[i][j]=='Q') 
            {
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // change the color of the queen from default (white) to green.
               cout<<arr[i][j]<<" ";
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);// set the color as default ie white
               
            }
            else cout<<arr[i][j]<<" ";
         }
         cout<<endl;
       }
       return true;
    }
    //Main answer finding

    // Filling the Queens 
    for(int j=0;j<n;j++)
    {
       if(canPlace(arr,i,j,n) == true)
       {
          // Assume that the number is the correct option
          arr[i][j]='Q';
          bool couldWeSolve=solve(arr,i+1,0,n);
          if(couldWeSolve == true)
          {
             return true;
          }
       } 
       
       arr[i][j]='0'; // when any Queen is not compatible then place zero at that cell
    }
    // when any Queen is not placed then 
    return false;
}
int main()
{
	cout<<"Please Enter The Value Of Number Of Queens"<<"\n";
    int n; cin>>n;
    char arr[100][100];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        arr[i][j]='0';
    solve(arr,0,0,n);
    
}
