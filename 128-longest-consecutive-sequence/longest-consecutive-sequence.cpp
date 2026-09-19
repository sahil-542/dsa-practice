class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=0;
        int flag=0,ma=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]-1==ma){
                flag++;
                ma=arr[i];
            }
            else if(arr[i]!=ma){
                flag=1;
                ma=arr[i];
            }
            res=max(res,flag);
        }
        return res;
    }
};