#include <iostream>
#include <vector>
using namespace std;
int main(){
   string s;
   cin>>s;
   
   int n = s.length();

   int prevmax = 1;
   int count = 1 ;

   for(int i = 1;i<n;i++){
    if(s[i]==s[i-1]){
    count+=1;
    prevmax = max(count,prevmax);
    }

    else 
    {  
        count = 1;
    }
    
   }

  cout<<prevmax;
}