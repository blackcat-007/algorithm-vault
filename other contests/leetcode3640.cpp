#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>nums(6);
nums[0]=-533;
nums[1]=224;
nums[2]=-324;
nums[3]=251;
nums[4]=231;
nums[5]=479;
   int increasingcounter=0;
        int decreasingcounter=0;
        bool increasing=false;
        bool decreasing=false;
        int sum=0;
        int maxsum=INT_MIN;
        int k;
        int i=1;
        while(i<nums.size()){
         if(nums[i]>nums[i-1]){
            if(!increasing){
                increasingcounter+=1;
                if(increasingcounter==2){
                k=i;
            }
            if(increasingcounter==1)sum+=nums[i-1];
            }
            
            //if(sum==0)sum+=nums[i-1];
            increasing=true;
            decreasing=false;
            if(increasingcounter<=2)sum+=nums[i];
         }
         else if(nums[i]<nums[i-1]){
            if(!decreasing){
                decreasingcounter+=1;
            }
            increasing=false;
            decreasing=true;
            if(decreasingcounter<=1 )sum+=nums[i];
         }
         else{
            if(increasingcounter==2 && decreasingcounter==1)maxsum=max(sum,maxsum);
            increasing=false;
            decreasing=false;
            increasingcounter=0;
            decreasingcounter=0;
            sum=0;
            
            i++;
            continue;
         }
         if(increasingcounter==2 && decreasingcounter==1)maxsum=max(sum,maxsum);
         else if(increasingcounter<decreasingcounter || decreasingcounter>1){
            //maxsum=max(sum,maxsum);
            if(decreasingcounter>1){
                 i=k;
                
                // continue;
            }
          // i++;
            increasing=false;
            decreasing=false;
            increasingcounter=0;
            decreasingcounter=0;
            sum=0;
            
           //continue;
         }
         if(decreasingcounter>1){
                 
             continue;
            }
          i++;

        }
        cout<<maxsum<<endl;
       
}