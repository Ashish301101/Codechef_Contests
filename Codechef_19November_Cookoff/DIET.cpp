//this is for the question https://www.codechef.com/COOK112B/problems/DIET

#include <iostream>
//#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        bool hasenough = true;
        int broken = -1;
        int x;
        int stored = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            stored += x;
            if (stored < k && broken == -1)
            {
                hasenough = false;
                broken = i + 1;
            }
            stored -= k;
        }

        if (hasenough)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO " << broken << endl;
        }
    }
}