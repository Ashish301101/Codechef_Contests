//This is my solution for 'Binary XOR' from the december Long challenge
//Question Link: https://www.codechef.com/DEC19B/problems/BINXOR/

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007

long long f[100001];

long long pow(long long a, long long b, long long MOD)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > MOD)
                x %= MOD;
        }
        y = (y * y);
        if (y > MOD)
            y %= MOD;
        b /= 2;
    }
    return x % MOD;
}

/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, long long MOD)
{
    return pow(n, MOD - 2, MOD);
}

long long C(long long n, long long r, long long MOD)
{

    return (f[n] * ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD)) % MOD;
}

void create_magic_answer()
{
    f[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        f[i] = (f[i - 1] * i) % INF;
    }
}

int main()
{
    create_magic_answer();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long answer = 0;
        char A[n + 1], B[n + 1];
        cin >> A;
        cin >> B;
        long long a = 0, b = 0;
        for (long long i = 0; i < n; i++)
        {
            if (A[i] == '1')
                a++;
            if (B[i] == '1')
                b++;
        }
        // cout<<a<<","<<b<<endl;

        if (a + b > n)
        {
            a = n - a;
            b = n - b;
            long long diff = a > b ? (a - b) : (b - a);
            for (long long i = diff; i <= a + b; i += 2)
            {
                /*cout<<"n! is "<<facto(n)<<endl;
                    cout<<"n-i! is "<<facto(n-i)<<endl;
                    cout<<"i! is "<<facto(i)<<endl;
                    */
                answer += C(n, i, INF);
                // cout << "answer " << answer << endl;
                //answer+=facto(n,i);
                //answer+=Combination[n][i];
                //cout<<facto(n,i)<<"factorial"<<endl;
                //cout<<answer<<" @ i= "<<i<<endl;
                answer %= INF;
            }
        }
        else
        {
            long long diff = a > b ? (a - b) : (b - a);
            for (long long i = diff; i <= a + b; i += 2)
            {
                answer += C(n, i, INF);

                // cout << "answer " << answer << endl;
                //answer+=Combination[n][i];
                //answer+=facto(n,i);
                //cout<<facto(n,i)<<"factorial"<<endl;
                //cout<<answer<<" @ i= "<<i<<endl;
                answer %= INF;
            }
        }
        cout << answer << endl;
    }
}
