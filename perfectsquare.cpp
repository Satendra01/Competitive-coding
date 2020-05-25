 #include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        if(num==2 or num==3)
            return false;
        int arr[num+1];
        memset(arr,0,sizeof(arr));
        for(int i=2;i<=num;i++)
        {
            for(int j=2*i;j<=num;j+=i)
            {
                arr[j]=1;
            }
        }
        vector<int>primes;
        for(int i=2;i<=num;i++)
        {
            if(arr[i]==0)
            primes.push_back(i);
        }
        int ctr=0;
        int countprimearr[num+1];
         memset(countprimearr,0,sizeof(countprimearr));
        int temp=num;
        for(int i=0;i<primes.size();i++)
        {
            
                while(num%primes[i]==0 && num!=1)
                {
                  num/=primes[i];
                    countprimearr[primes[i]]+=1;
                }
            
        }
        // cout<<sizeof(countprimearr)/sizeof(int);
       for(int i=2;i<temp+1;i++)
       {
          // cout<<countprimearr[i]<<endl;
           if(countprimearr[i]%2==1)
               return false;
       }
        return true;
    }
int main()
{
    cout<<isPerfectSquare(14);
    return 0;
}