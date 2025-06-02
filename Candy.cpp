class Solution {
public:
    int candy(vector<int>& ratings) {

        /* logic
        int arr[n] = candy
        i = 1
        if(r[i]==r[i-1]){
            candy[i]=1
        }
        if(r[i]>r[i-1])
        candy[i-1]=1
        candy[i]= 2
        else
        candy[i-1]=2
        candy[i]=1

        */
        int cnt = 0;
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++) 
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            cnt += candies[i - 1];
        }
        return cnt + candies[n - 1];

    }
};