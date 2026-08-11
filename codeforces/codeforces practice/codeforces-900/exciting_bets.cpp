#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        long long a, b;
        cin >> a >> b;
       long long d=abs(a-b);
       if(d==0){
        cout<<0<<" "<<0<<endl;
       }
       else{
        long long steps1=a%d;
        long long steps2=d-(a%d);
        cout<<d<<" "<<min(steps1,steps2)<<endl;
       }

    }
   
    
    return 0;
}