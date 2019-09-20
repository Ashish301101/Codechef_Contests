#include <iostream>

using namespace std;
/*
question link: https://www.codechef.com/SEPT19B/problems/FIBEASY
logic: firstly you can't store the fibonacci series in any data type as it grows very fast
however since we only have to store the last digit of the fibonacci series, we only have to calculate
the last digit. we can delete the rest of the digits in the first place. for example when you have 9+9 you
get 18 but you only need to store 8.
I also noticed that you the last digit starts repeating after the first sixty digits. This makes it much easier for us.
I'm also pre-calculating the series upto 60 to save time.

it is also obvious that you need the 2^r th element.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int d2[61];
        d2[0] = 0;
        d2[1] = 1;
        for(int i = 2;i<61;i++)
        {
            d2[i] = d2[i-1] + d2[i-2];
            d2[i]%=10;
            //cout<<d2[i];
        }

    while(t--)
    {
        unsigned long long n;
        cin>>n;
        unsigned long long l = n;
        unsigned long long required_index = 0;
        unsigned long long r = 1;
        while(l/2>0)
        {
            r*=2;
            l/=2;
        }
        //cout << "r is " <<r;
        required_index = r-1;
        required_index%=60;
       // cout<<required_index;
        cout<<d2[required_index]<<endl;
    }

    return 0;

}
