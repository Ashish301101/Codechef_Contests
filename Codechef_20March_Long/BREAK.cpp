//This is my solution for 'BREAK' from the March Long Challenge
//Question Link: https://www.codechef.com/MARCH20B/problems/BREAK

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s;
    cin >> t >> s;

    while (t--)
    {
        // 1 1 2
        //2 2 3
        int brk = 0;
        fflush(stdin);
        fflush(stdout);
        int n;
        cin >> n;
        vector<long long> a;
        vector<long long> b;
        long long temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        if (n == 1 && a[0] < b[0])
        {
            cout << "YES" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int possible = false;

        long long last_copy = -1;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == a[0])
            {
                last_copy = a[0];
            }
            if (b[i] > a[0])
            {
                possible = 1;
                k = i + 1;
                break;
            }
        }
        if (!possible)
        {
            cout << "NO" << endl;
            continue;
        }
        brk = 0;

        for (int i = 1; i < n; i++)
        {
            if (k >= n)
            {
                possible = 0;
                brk = 1;
                break;
            }
            possible = 0;
            if (a[i] == last_copy || a[i] == a[0])
            {
                //find larger elemnent
                if (k >= n)
                {
                    possible = 0;
                    brk = 1;
                    break;
                }
                for (int j = k; j < n; j++)
                {
                    possible = 0;
                    if (b[j] > a[i])
                    {
                        k = j + 1;
                        possible = 1;
                        break;
                    }
                }
            }
            else
            { //finding copy
                for (int j = 0; j < n; j++)
                {
                    possible = 0;
                    if (b[j] == a[i])
                    {
                        //k = j+1;
                        possible = 1;
                        last_copy = a[i];
                        break;
                    }
                }
                if (!possible)
                {
                    brk = 1;
                    break;
                }
                //finding greater
                else
                {
                    if (k >= n)
                    {
                        possible = 0;
                        brk = 1;
                        break;
                    }
                    for (int j = k; j < n; j++)
                    {
                        possible = 0;
                        if (b[j] > a[i])
                        {
                            k = j + 1;
                            possible = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (b[n - 1] <= a[n - 1])
        {
            brk = 1;
        }
        if (brk)
        {
            cout << "NO" << endl;
            continue;
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
