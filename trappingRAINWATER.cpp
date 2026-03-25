#include<iostream>
#include<vector>
using namespace std;

int Findtotal(vector<int> &arr){
    int n = arr.size();
    int lmax = 0, rmax = 0;
    int total = 0;
    int l = 0, r = n - 1;

    while(l < r){
        if(arr[l] <= arr[r]){
            if(lmax > arr[l]){
                total += lmax - arr[l];
            } else {
                lmax = arr[l];
            }
            l++;   // move pointer
        } else {
            if(rmax > arr[r]){
                total += rmax - arr[r];
            } else {
                rmax = arr[r];
            }
            r--;   // move pointer
        }
    }
    return total;
}

int main(){
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int result = Findtotal(arr);

    cout << "Total trapped water: " << result << endl;

    return 0;
}