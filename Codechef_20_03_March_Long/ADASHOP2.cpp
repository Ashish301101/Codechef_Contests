//This is my solution for 'Ada Bishop 2' from the March Long Challenge
//Question Link: https://www.codechef.com/MARCH20B/problems/ADASHOP2

#include <bits/stdc++.h>

using namespace std;

void printstuff()
{
    //cout<<"25"<<endl;
    int x = 1, y = 1;
    //cout<<"1 1"<<endl;
    for (int i = 2; i < 5; i++)
    {
        x = i, y = i;
        cout << x << " " << y << endl;
        cout << 1 << " " << 2 * i - 1 << endl;
        cout << 2 * i - 1 << " " << 1 << endl;
        cout << x << " " << y << endl;
    }
    for (int i = 5; i < 8; i++)
    {
        x = i, y = i;
        cout << x << " " << y << endl;
        cout << 2 * i - 8 << " " << 8 << endl;
        cout << 8 << " " << 2 * i - 8 << endl;
        cout << x << " " << y << endl;
    }
    cout << "8 8" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        int x = X, y = Y;
        if (x == 1 && y == 1)
        {
            cout << "25" << endl;
            printstuff();
        }
        else
        {
            if (x == y)
            {
                cout << 26 << endl;
                cout << "1 1" << endl;
                printstuff();
            }
            else
            {
                cout << 27 << endl;
                cout << (x + y) / 2 << " " << (x + y) / 2 << endl;
                cout << "1 1" << endl;
                printstuff();
            }
        }
    }
}
