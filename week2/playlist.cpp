#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> arr;
    while(n--){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    int i =0;
    int j = 0;
    int k = arr.size();
    int x = *max_element(arr.begin(), arr.end());
    int max_len = 0;
    int len = 0;
    vector <int> copy(x+1,0);
    while(j<k){
        
      while(j<k && copy[arr[j]] != 1){
            copy[arr[j]] =1;
            j++;
        }
        
        len = j-i;
        max_len = max(len,max_len);
        //i = repeating index +1;
       while((j < k) && (arr[i] != arr[j])) {
    copy[arr[i]] = 0;
    i++;
}
if (j < k) {
    copy[arr[i]] = 0; // reset the actual duplicate
    i++;
}      
    }
    cout<<max_len;
    return 0;
}