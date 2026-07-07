class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        string str1 = "";
        while(n!=0){
            int rem = n%10;
            if(rem!=0){
                str1 += to_string(rem);
            }
            sum += rem;
            n = n/10;
        }
        reverse(str1.begin(), str1.end());
        for(auto& c:str1){
            num = num*10 + (c-'0');
        }
        return num*sum;
    }
};