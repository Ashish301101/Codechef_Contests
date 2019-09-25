#include <iostream>
using namespace std;

//this question is from https://www.codechef.com/COOK110B/problems/MATCHES

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short t;
    cin>>t;
    while(t--)
    {
        int a;
        int b;
        int sum;
        cin>>a;
        cin>>b;
        sum = a+b;
        //int sumcopy = sum;
        int sticks = 0;
        while(sum>0)
        {
            int current = sum%10;
            sum/=10;
            switch(current)
            {
            case 1:
                sticks+=2;
                break;
            case 2:
                sticks+=5;
                break;
            case 3:
                sticks+=5;
                break;
            case 4:
                sticks+=4;
                break;
            case 5:
                sticks+=5;
                break;
            case 6:
                sticks+=6;
                break;
            case 7:
                sticks+=3;
                break;
            case 8:
                sticks+=7;
                break;
            case 9:
                sticks+=6;
                break;
            case 0:
                sticks+=6;
                break;
            }
        }
        cout<<sticks<<endl;
    }

}
