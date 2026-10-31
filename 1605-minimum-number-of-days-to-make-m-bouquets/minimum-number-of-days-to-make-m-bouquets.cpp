class Solution {
public:
    bool isValid(int day , vector<int>arr , int m , int k){
        int b = 0; // bouquets
        int t = 0;
        for(int i = 0 ; i < arr.size() ; i++ ){
            if(arr[i] <= day){
                t++;
            }
            else t = 0;

            if(t == k){
                b++;
                t = 0;
            }
        }
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        

        int l = 0 ; 
        int maxi = *max_element(bloomDay.begin() , bloomDay.end());

        int r = maxi;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(isValid(mid , bloomDay , m , k)){
                r = mid - 1;
                ans = mid;
            }
            else{
                 l = mid + 1;
            }

           
        }
        return ans;
    }
};