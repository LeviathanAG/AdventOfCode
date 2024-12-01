#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mover = 0;
    int c[10000];
    int a[10000];
    int b[10000];
    int n;

    n=1000; // Read the number of lines expected

    ifstream f("input.txt");
    

    string s;
    while (getline(f, s))
    {

        
        int spacePos = s.find(' ');

        string s1 = s.substr(0, spacePos); 
        string y = s.substr(spacePos + 1); 

        
        a[mover] = stoi(s1);
        b[mover] = stoi(y);
        mover++;
    }
    sort(a, a + n);
    sort(b, b + n);
    int counter=0;
    for(int i=0;i<n;i++)
    {
        counter=0;
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                counter++;
                
            }
            c[i]=a[i]*counter;
        }
        
    }
    int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=c[i];
            
        }
        cout<<sum<<endl;
    f.close();

    return 0;
}

// Final Answer : 18805872
