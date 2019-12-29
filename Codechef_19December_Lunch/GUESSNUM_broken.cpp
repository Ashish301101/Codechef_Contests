//This is my solution for 'Guess The Number' from the december Lunchtime
//Question Link: https://www.codechef.com/LTIME79B/problems/GUESSNUM

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
        int a, m;
        cin >> a >> m;
        int start = (m / (a + 1));
        int finish = (m - 1) / a;
        if (finish < start)
        {
            swap(start, finish);
        }
        int counter = 0;
        vector<int> ar;
        for (int i = start; i <= finish; i++)
        {
            int div = 2;
            for (int j = i; j >= 1;)
            {
                //cout<<m<<" = "<<a<<"*"<<i<<" + "<<j<<endl;
                if (m == a * i + j)
                {
                    //cout<<"ye"<<endl;
                    counter++;
                    ar.push_back(i);
                    break;
                }
                if (j == 1)
                {
                    break;
                }

                if (j % div == 0)
                {
                    j /= div;
                }
                else
                {
                    div++;
                }
            }
        }
        cout << counter << endl;
        for (int i = 0; i < ar.size(); i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
}
