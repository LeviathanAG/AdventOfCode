#include<bits/stdc++.h>
using namespace std;
void counter1(char arr[1000][1000],int n)
{
  int counter=0;
 /* if i encounter an M then i check if the pattern M M 
                                                     A    
                                                    S S OR M S
                                                            A
                                                           M S exists in the matrix and If i encounter an S i check if the pattern S S
                                                                                                                                    A
                                                                                                                                   M M OR S M
                                                                                                                                          A
                                                                                                                                         S M exists in the matrix*/
    for(int i=0;i<=n-3;i++)
    {
        for(int j=0;j<=n-3;j++)
        {//m case
            if(arr[i][j]=='M')
            {
                if((arr[i+1][j+1]=='A'&&arr[i+2][j+2]=='S')&&((arr[i][j+2]=='M'&&arr[i+2][j]=='S')||(arr[i][j+2]=='S'&&arr[i+2][j]=='M')))
                {
                    counter++;
                }

            }
            //s case
            if(arr[i][j]=='S')
            {
                if((arr[i+1][j+1]=='A'&&arr[i+2][j+2]=='M')&&((arr[i][j+2]=='S'&&arr[i+2][j]=='M')||(arr[i][j+2]=='M'&&arr[i+2][j]=='S')))
                {
                    counter++;
                }
        }
    }

    
}
cout<<counter<<endl;
}

int main()
{
    ifstream f("inputs/input5.txt");
    //storing each character in a 2d array
    char arr[1000][1000];
    int n=140;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f>>arr[i][j];
        }
    }
    f.close();
    counter1(arr,n);
    
}