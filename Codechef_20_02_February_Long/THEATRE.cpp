//This is my solution for 'Theatre' from the February Long Challenge
//Question Link: https://www.codechef.com/FEB20B/problems/THEATRE

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int tcopy = t;
    int finalp = 0;
    while(t--)
    {
        int n;
        cin>>n;
        //vector < vector < int > > ar(4,vector < int > (4,0));
        int ar[4][4];

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                ar[i][j]=0;
            }
        }

        for(int i=0;i<n;i++)
        {
            char c;
            int temp;
            cin>>c>>temp;

            //cout<<c-'A'<<","<<temp/3-1<<":"<<ar[(int)(c-'A')][(temp/3-1)]+1<<endl;

            ar[(int)(c-'A')][(temp/3-1)]++;
        }

//        for(int i=0;i<4;i++)
//        {
//            for(int j=0;j<4;j++)
//            {
//                cout<<ar[i][j]<<","<<arc[i][j]<<"\t";
//            }
//            cout<<endl;
//        }


        //Brute force cause fuck optimised code lmao
        //vector < vector < int > > arc(4, vector < int >(4,0));
        int maxprof = -401;
        for(int i1=0;i1<4;i1++)
        {
            for(int j1 = 0;j1<4;j1++)
            {
                for(int i2=0;i2<4;i2++)
                {
                    for(int j2 = 0;j2<4;j2++)
                    {
                        if(i2==i1 || j2 == j1)
                        {
                            continue;
                        }

                        for(int i3=0;i3<4;i3++)
                        {
                            for(int j3 = 0;j3<4;j3++)
                            {
                                if(i3==i2 || j2 == j3 || i3 == i1 || j3 == j1)
                                {
                                    continue;
                                }

                                for(int i4=0;i4<4;i4++)
                                {
                                    for(int j4 = 0;j4<4;j4++)
                                    {
                                        if(i3==i4 || j3 == j4 || i4 == i2 || i4 == i1 || j4 == j2 || j4 == j1)
                                        {
                                            continue;
                                        }


                                        int tprof = -400;
                                        if(ar[i1][j1]>0)
                                        {
                                            tprof+=100;
                                            tprof+=100*ar[i1][j1];

                                        }

                                        if(ar[i2][j2]>0)
                                        {
                                            tprof+=100;
                                            tprof+=75*ar[i2][j2];

                                        }

                                        if(ar[i3][j3]>0)
                                        {
                                            tprof+=100;
                                            tprof+=50*ar[i3][j3];

                                        }

                                        if(ar[i4][j4]>0)
                                        {
                                            tprof+=100;
                                            tprof+=25*ar[i4][j4];

                                        }



                                        //cout<<i1<<","<<j1<<";"<<i2<<","<<j2<<";"<<i3<<","<<j3<<";"<<i4<<","<<j4<<":"<<tprof<<endl;
                                        if(tprof>maxprof)
                                        {
                                            maxprof = tprof;
                                        }

                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        finalp+=maxprof;
        cout<<maxprof<<endl;

    }
    cout<<finalp<<endl;

}

