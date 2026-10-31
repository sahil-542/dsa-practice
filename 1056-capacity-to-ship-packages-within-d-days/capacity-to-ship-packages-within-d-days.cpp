class Solution {
public:
    int maxCapacity(vector<int>& weights, int capacity){
        int days = 1;
        int currentLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currentLoad + weights[i] > capacity) {
                days++;
                currentLoad = weights[i];
            } else {
                currentLoad += weights[i];
            }
        }
        return days;
    }
     
     int findsum(vector<int> &weights){
            int sum = 0;
            for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }
        return sum;
     }
    bool isValid(int mid,vector<int>&weights,int days){
        int cumsum=0;
        int cnt=1;
        for(int x:weights){
            if(cumsum+x<=mid){
                
                cumsum+=x;
            }else{
                cnt++;
                cumsum=x;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int  low = *max_element(weights.begin(), weights.end());
        int high = findsum(weights);
        int ans = -1;

        while(low <= high){
            int mid = (low + (high - low) / 2);

           // if(maxCapacity(weights,mid) <= days){
            if(isValid(mid,weights,days)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};