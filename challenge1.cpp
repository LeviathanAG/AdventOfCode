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
    if (!f.is_open())
    {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string s;
    while (getline(f, s))
    {

        // Locating space separating the two numbers
        int spacePos = s.find(' ');

        string s1 = s.substr(0, spacePos); // First number
        string y = s.substr(spacePos + 1); // Second number

        // Convert strings to integers
        a[mover] = stoi(s1);
        b[mover] = stoi(y);
        mover++;
    }
    sort(a, a + n);
    sort(b, b + n);
    for(int i=0;i<n;i++)
    {
        c[i] = abs(a[i] - b[i]);
        
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=c[i];
    }
    cout<<sum<<endl;
    f.close();

    return 0;
}

// Final Answer : 3714264
