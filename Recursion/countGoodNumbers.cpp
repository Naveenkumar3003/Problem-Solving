class Solution {
public:
    const long long MOD = 1000000007LL;
    //Recursion
    // long long helper(long long index,long long n){
    //     if(index==n) return 1;
    //     long long choices;
    //     if(index%2==0) choices=5;
    //     else choices=4;
    //     return (choices*helper(index+1,n))%MOD;
    // }
    // int countGoodNumbers(long long n) {
    //     return helper(0,n);
    // }

    //Optimal
    long long power(long long base, long long exp){
        long long res=1;
        while(exp>0){
            if(exp%2==1)
                res=(res*base)%MOD;
            base=(base*base)%MOD;
            exp/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        long long evenways=power(5,even);
        long long oddways=power(4,odd);

        return (evenways*oddways)%MOD;
    }
};
