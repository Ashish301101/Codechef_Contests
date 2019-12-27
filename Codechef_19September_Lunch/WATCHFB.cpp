// Qustion link:https://www.codechef.com/LTIME76B/problems/WATCHFB

#include <iostream>

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
            cin>>n;
            int scoreA =0;
            int scoreB=0;
            while(n--)
            {
                int info;
                int a;
                int b;
                cin>>info>>a>>b;

                if(info == 1 || a==b)
                {
                    scoreA = a;
                    scoreB = b;
                    cout<<"YES"<<endl;
                }
                else
                {
                   // int scoremin;
                    //scoreA<scoreB?scoremin = scoreA:scoremin = scoreB;
                    if(scoreA<scoreB)
                    {
                        if(a<b)
                        {
                            if(a<scoreB&&a>=scoreA)
                            {
                                cout<<"YES"<<endl;
                                scoreA = a;
                                scoreB = b;

                            }
                            else
                                cout<<"NO"<<endl;
                        }
                        else
                        {
                            if(b<scoreB&&b>=scoreA)
                            {
                                cout<<"YES"<<endl;
                                scoreA = b;
                                scoreB = a;
                            }
                            else
                                cout<<"NO"<<endl;
                        }
                    }
                    else if(scoreA>scoreB)
                    {
                        if(a<b)
                        {
                            if(a<scoreA&&a>=scoreB)
                            {
                                cout<<"YES"<<endl;
                                scoreB = a;
                                scoreA = b;
                            }
                            else
                                cout<<"NO"<<endl;
                        }
                        else
                        {
                            if(b<scoreA&&b>=scoreB)
                            {
                                cout<<"YES"<<endl;
                                scoreB = b;
                                scoreA = a;
                            }
                            else
                                cout<<"NO"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"NO"<<endl;
                    }



                }

            }

        }

    }
