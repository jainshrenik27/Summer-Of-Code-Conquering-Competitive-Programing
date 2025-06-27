#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector <int> arr(n);

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }

    int i = 0;
    int j = 1;
    int count = 0;
    while(j<n){
        int prod = 2;
        while((j< n )&& (j -i)<=k && prod*arr[j] > prod/2*arr[j-1]){
            j++;
        }
        if ( j == i+k+1 ){count+=1; 
        i++;}

        else {
            i=j;
            j++;
        }
    }
    cout<<count<<"\n";
    }
    return 0;
}