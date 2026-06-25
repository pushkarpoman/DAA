#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    double fractionVal(vector<int>&val, vector<int>&wt,int capacity){
        int n = val.size();
        vector<pair<int, int>> arr(n);
        for(int i=0 ;i<n;i++){
            arr[i] = {val[i], wt[i]}; // value by weigth;
        }
        
        auto lambda =[](pair<int, int>&p1, pair<int,int>&p2){
            return (1.0 * p1.first/p1.second) >(1.0 * p2.first/p2.second);
        };
        
        sort(arr.begin(),arr.end(), lambda);
        
        double res = 0.0;
        for(int i=0 ;i<n ;i++){
            if(arr[i].second <= capacity){
                res += arr[i].first;
                capacity -= arr[i].second;
            }else{
                res += (1.0 * arr[i].first/arr[i].second) * capacity;
                break; // break as we got the ans
            }
        }
        return res;
    }
};

int main(){
    
    cout<<"Enter total Number of weight or Values: "<<endl;
    int n;
    cin>>n;
    vector<int> wt(n), val(n);
    cout<<"Enter the total capacity : ";
    int capacity; 
    cin>> capacity;
    cout<<"Enter values for the Weight:"<<endl;
    for(int i =0;i<n;i++){
        cin>>wt[i];
    }
    
    cout<<"Enter values for the val:"<<endl;
    for(int i =0;i<n;i++){
        cin>>val[i];
    }
    
    Solution obj; //cerate object of the class Soluton
    
    double maxProfit = obj.fractionVal(val, wt, capacity);
    
    cout<<"Max Profit is : "<<maxProfit;
    return 0;
}