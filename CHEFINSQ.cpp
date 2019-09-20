/*
Question: https://www.codechef.com/SEPT19B/problems/CHEFINSQ
*/


#include <iostream>
#include<algorithm>//for sorting directly with sort function
using namespace std;
long long Combination[52][52];
 
void create_Pascals_Triangle()
{
    Combination[0][0] = 1;
    for(int i = 0;i<51;i++)
    {
        Combination[i][0] = 1;
        for(int j = 1;j<=i;j++)
        {
            Combination[i][j] = Combination[i-1][j]+Combination[i-1][j-1];
        }
    }
    //return ans; 
}
 
 
int main()
{
	//these two lines are basically to take in input faster
    ios_base::sync_with_stdio(false);//from what I understood this prevents syncing c++ standard streams with standard c streams before any i/p is taken
    cin.tie(NULL);//this flushes the cout output before taking in input from cin
 
 
    create_Pascals_Triangle();
    short t;//using short because I was getting a memory limit error
    cin>>t;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        short ar[n];
 
        for(int i = 0;i<n;i++)
        {
            cin>>ar[i];
        }
 
        sort(ar,ar+n);//this uses introsort which is a hybrid of quicksort, heapsort and insertion sort
        //this has a time complexity of NlogN 
 
        long long answer = 0;
        //int required_number = ar[k-1];
        int starting_index = 0;
        int ending_index = 0;
        for(int i = (k-1);i>=0;i--)
        {
           if(ar[i]==ar[k-1])
           {
                starting_index = i;
           }
           else
           {
               break;
           }
 
        }
 
        for(int i = k-1;i<n;i++)
        {
           if(ar[i]==ar[k-1])
           {
                ending_index = i;
           }
           else
           {
               break;
           }
 
        }
 
        int p = ending_index - starting_index+1;
        int r = k-starting_index;
 
        answer = Combination[p][r];
        //cout<<"P is "<<p<<"r is"<<r<<endl;
        //cout<<factorial(p)<<" is p fac"<<factorial(p-r)<<" is p-r fac"<<factorial(r)<<" is r fac"<<endl;
        cout<<answer<<endl;
 
    }
 
}