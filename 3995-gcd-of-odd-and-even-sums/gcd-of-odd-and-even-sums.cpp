class Solution {
public:
    int gcd(int x, int y){
        while(x!=y){
            if(x>y){
                x = x - y;
            }else if(x<y){
                y = y-x;
            }
        }
        return x;
    }
    int gcdOfOddEvenSums(int n) {
        int even_sum = n*(n+1);
        int odd_sum = n*n;
        return gcd(even_sum, odd_sum);
    }
};