//This is my solution for 'Change it' from the december COokoff
//Question Link: https://www.codechef.com/COOK113B/problems/CHNGIT

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
        int ar[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        ar[n] = 999997;

        sort(ar, ar + n); /*
        for(int i=0;i<n;i++)
            cout<<ar[i]<<",";
*/
        int mcount = 1, start = -1;
        for (int i = 0; i < n; i++)
        {
            if (ar[i] != ar[i + 1])
            {

                if (mcount < i - start)
                {
                    mcount = i - start;
                }
                start = i;
                //cout<<"\n"<<ar[i]<<"!="<<ar[i+1]<<";i="<<i<<";mcount = "<<mcount<<endl;
            }
            //start++;
        }
        if (ar[0] == ar[n - 1])
            mcount = n;
        cout << n - mcount << endl;
    }
}
