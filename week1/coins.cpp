#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
  
    while(t--){
    
    long long n,k;
    cin>>n>>k;

    if(n%2!=0){
        if(k%2==0)
        cout<<"NO"<<endl;

        else 
        cout<<"YES"<<endl;
    }

    else
    cout<<"YES"<<endl;
   
        
    
    }
   
}