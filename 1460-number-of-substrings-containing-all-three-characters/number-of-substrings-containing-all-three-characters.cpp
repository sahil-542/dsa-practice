class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        // int l = 0, r = 0;
        // vector<int> freq(3,-1);
        // int cnt = 0;

        // for(int i = 0; i < n ; i++){
        //     freq[s[i] - 'a'] = i;

        //     if(freq[0] != -1 && freq[1] != -1 && freq[2] != -1){
        //         cnt = cnt + (1 + min({freq[0], freq[1], freq[2]}));
        //     }

        // }
        // return cnt;
        map<char,int>mp;
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp.size()==3 ){
                cnt+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }

};