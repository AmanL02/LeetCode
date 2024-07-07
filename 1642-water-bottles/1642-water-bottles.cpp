class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange){
            return numBottles;
        }
        int ans=0;
        int temp=0;
        int temp2=0;
        while((numBottles+temp2)>=numExchange){
            ans+=numBottles;
            temp=(numBottles+temp2)/numExchange;
            temp2=(numBottles+temp2)%numExchange;
            numBottles=temp;
        }
        return ans+temp;
    }
};