class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        int low_len = to_string(low).size();
        int high_len = to_string(high).size();
        vector<int>ans;
        for(int len=low_len;len<=high_len;len++){
            for(int i=0;i+len<=9;i++){
                int num = stoi(digits.substr(i, len));
                if(num>=low && high>=num){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};