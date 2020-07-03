//This is my solution for 'Guessing Game' from the June Long Challenge
//Question Link: https://www.codechef.com/JUNE20B/problems/GUESSG

#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> ar;

long long removed_length(long long a, long long b)
{
    long long ans = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (a >= ar[i].second && b >= ar[i].second)
        {
            continue;
        }
        else if (a <= ar[i].second && b >= ar[i].second && a >= ar[i].first)
        {
            ans += ar[i].second - a;
        }
        else if (a >= ar[i].first && b <= ar[i].second)
        {
            ans += b - a;
        }
        else if (a < ar[i].first && b > ar[i].first)
        {
            if (b >= ar[i].second)
            {
                ans += ar[i].second - ar[i].first;
            }
            else
            {
                ans += b - ar[i].first;
            }
        }
        else if (a <= ar[i].first && b <= ar[i].first)
        {
            continue;
        }
    }
    return ans;
}

void fixar()
{
    sort(ar.begin(), ar.end());
    for (int i = 0; i < ar.size() - 1; i++)
    {
        if (ar[i].second + 1 >= ar[i + 1].first)
        {
            while (ar[i].second > ar[i + 1].second && i < ar.size() - 1)
            {
                ar.erase(ar.begin() + i + 1);
                //i++;
            }
            if (ar[i].second <= ar[i + 1].second && ar[i].second >= ar[i + 1].first)
            {
                long long temp = ar[i + 1].second;
                ar[i].second = temp;
                ar.erase(ar.begin() + i + 1);
            }
        }
    }
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i].second + 1 == ar[i + 1].first)
        {
            ar[i].second = ar[i + 1].second;
            ar.erase(ar.begin() + i + 1);
        }
    }
}

long long findmid1(long long st, long long n)
{
    long long rem = removed_length(st, n);
    long long dist = (n - rem - st) / 2;
    long long mid = st;
    for (long i = 0; i < ar.size() && dist > 0; i++)
    {
        if (mid >= ar[i].second)
        {
            continue;
        }
        if (dist + mid < ar[i].first)
        {
            mid += dist;
            dist = 0;
        }
        else
        {
            if (dist + mid <= ar[i].second)
            {
                dist -= (-mid + ar[i].first);
                mid = ar[i].second;
            }
            else
            {
                dist -= (-mid + ar[i].first);
                mid = ar[i].second;
            }
        }
    }
    mid += dist;
    return mid;
}

void append(long long a, long long b)
{

    ar.push_back(make_pair(a, b));
    sort(ar.begin(), ar.end());
    fixar();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    char resp = ' ';
    //double remrec = n;
    ar.push_back(make_pair(0, 0));
    ar.push_back(make_pair(n + 1, n + 1));
    while (resp != 'E')
    {
        fixar();
        long long mid1 = findmid1(0, n);
        ///debug
        /*
        cout<<"blocked regions: ";
        for(int i=0;i<ar.size();i++)
        {
            cout<<"<"<<ar[i].first<<", "<<ar[i].second<<"> ";
        }
        cout<<endl<<"guess: ";
        */
        cout << mid1 << endl;
        if (mid1 == 0)
        {
            mid1++;
        }
        cin >> resp;
        if (resp == 'G' && mid1 == 1)
        {
            ar.push_back(make_pair(0, 1));
            sort(ar.begin(), ar.end());
            fixar();
            continue;
        }
        if (resp == 'L' && mid1 == n)
        {
            ar.push_back(make_pair(n, n));
            sort(ar.begin(), ar.end());
            fixar();
            continue;
        }
        //number is lesser than given guess
        if (resp == 'L')
        {
            fixar();
            long long mid2 = findmid1(mid1, n);
            if (mid2 == 0)
            {
                mid2++;
            }
            cout << mid2 << endl;
            cin >> resp;

            if (resp == 'G' && mid2 == 1)
            {
                ar.push_back(make_pair(0, 1));
                sort(ar.begin(), ar.end());
                fixar();
                continue;
            }
            if (resp == 'L' && mid2 == n)
            {
                ar.push_back(make_pair(n, n));
                sort(ar.begin(), ar.end());
                fixar();
                continue;
            }

            if (resp == 'L')
            {
                append(mid2, n);
                sort(ar.begin(), ar.end());
                fixar();
            }
            else if (resp == 'G')
            {
                append(mid1, mid2);
                sort(ar.begin(), ar.end());
                fixar();
            }
            else if (resp == 'E')
            {
                return 0;
            }
        }
        else if (resp == 'G')
        {
            long long mid2 = findmid1(0, mid1);
            if (mid2 == 0)
            {
                mid2++;
            }
            cout << mid2 << endl;
            cin >> resp;

            if (resp == 'G' && mid2 == 1)
            {
                ar.push_back(make_pair(0, 1));
                sort(ar.begin(), ar.end());
                fixar();
                continue;
            }
            if (resp == 'L' && mid2 == n)
            {
                ar.push_back(make_pair(n, n));
                sort(ar.begin(), ar.end());
                fixar();
                continue;
            }

            if (resp == 'L')
            {
                append(mid2, mid1);
                sort(ar.begin(), ar.end());
                fixar();
            }
            else if (resp == 'G')
            {
                append(0, mid2);
                sort(ar.begin(), ar.end());
                fixar();
            }
            else if (resp == 'E')
            {
                return 0;
            }
        }
        else if (resp == 'E')
        {
            return 0;
        }
    }
    //so this took me 2 whole days, but I think I've gotten the logic. even if I don't get AC I know my logic is correct. (implementation is prolly shit)
}