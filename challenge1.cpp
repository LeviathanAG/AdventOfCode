#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mover = 0;
    int c[10000];
    int a[10000];
    int b[10000];
    int n;

    n = 1000; //1000 lines given

    ifstream f("input.txt");

    string s;
    while (getline(f, s))
    {

        //locating space separating the two numbers
        int spacePos = s.find(' ');

        string s1 = s.substr(0, spacePos); //storing first number in the array cell
        string y = s.substr(spacePos + 1); //second number

        //converting str to int
        a[mover] = stoi(s1);
        b[mover] = stoi(y);
        mover++;
    }
    sort(a, a + n);
    sort(b, b + n); //sorting the arrays
    for (int i = 0; i < n; i++) //new array contains distance
    {
        c[i] = abs(a[i] - b[i]);
    } 
    int sum = 0;
    for (int i = 0; i < n; i++) //taking sum of the array
    {
        sum += c[i];
    }
    cout << sum << endl;
    f.close();

    return 0;
}

// Final Answer : 3714264
