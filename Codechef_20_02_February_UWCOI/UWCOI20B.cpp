//This is my solution for 'Button Pairs' from the February UWCOI contest
//Question Link: https://www.codechef.com/UWCOI20/problems/UWCOI20B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ar;

        long odd = 0;
        long even = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }
        cout << (odd * even) << endl;
    }
}
