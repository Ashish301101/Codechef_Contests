//This is my solution for 'XOR Engine' from the March Long Challenge
//Question Link: https://www.codechef.com/MARCH20B/problems/ENGXOR

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //FILE* f = fopen("C:/User/shrey/Desktop/a1.txt","W");
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <int> ar;
        int temp;
        for(int i=0;i<n;i++)
        {
            //cin>>temp;
            scanf("%d",&temp);
            ar.push_back(temp);
        }
        int p;
        int first = 0;
        int qorig = q;
        //cin>>p;
        scanf("%d",&p);
        int odd=0;
        int even=0;

        for(int i=0;i<n;i++)
        {
            int var = ar[i]^p;
            if(__builtin_popcount(var)%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        q--;
        int porig = p;
        //cout<<p<<": ";
        //cout<<even<<" "<<odd<<endl;
        printf("%d %d\n",even,odd);

        int mo = __builtin_popcount(porig)%2;
        while(q--)
        {
            //cin>>p;
            scanf("%d",&p);
            //cout<<p<<": ";
            if(__builtin_popcount(p)%2==mo)
            {
                //cout<<even<<" "<<odd<<endl;
                printf("%d %d\n",even,odd);
            }
            else
            {
                printf("%d %d\n",odd,even);
            }
        }
    }
}
