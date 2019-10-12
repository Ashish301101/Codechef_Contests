    #include <iostream>
//https://www.codechef.com/LTIME76B/problems/CATFEED is the question link.
    using namespace std;


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin>>t;
        while(t--)
        {
            int n;
            int m;
            cin>>n;
            cin>>m;
            int feed[n];
            int order[m];
            for(int i = 0;i<n;i++)
            {
                feed[i] = 0;

            }
            for(int i = 0;i<m;i++)
            {
                order[i] = 0;
            }
            int x;
            for(int i = 0;i<m;i++)
            {
                cin>>order[i];
                x = order[i];
                feed[x]++;
            }

            sort(feed,feed+n);
            int small = feed[0];
            int big = feed[n-1];
            if((big+1)>small)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }

        }

    }
