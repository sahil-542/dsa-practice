class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();

    //   int hash[256] ;

    //   for(int i = 0; i < 256; i++){
    //     hash[i] = -1;
    //   } 

    //   int l =  0, r = 0, maxlen = 0;

    //   while( r < n) {
    //     //inside map
    //     int len = 0;
    //     if(hash[s[r]] != -1){
    //         if(hash[s[r]] >= l){
    //             l = hash[s[r]] + 1;
    //         }
    //     }
    //       len = r - l + 1; 
    //       maxlen = max(maxlen, len);
    //       hash[s[r]] = r;
    //       r++;
    //   }
    //   return maxlen;

        int l=0,r=0,maxlen = 0;
        unordered_map<char,int>mp;
        while(r < n){
            if(mp.find(s[r]) != mp.end()){
                //agr phle se hai toh check krenge ki present char ka index left se aage hai toh left ko direct r ke aage point krenge
                if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                }
            }
            mp[s[r]] = r;
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};