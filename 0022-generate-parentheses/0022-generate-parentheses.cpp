class Solution {
public:
      void valid(int n,vector<string>& ans,string s , int copen ,int cclose ){
       
        if(copen == n && cclose == n){
            ans.push_back(s);
            return;
        }

        if(copen < n){
            valid(n,ans,s+'(',copen+1,cclose);
        }
        if(cclose < copen){
            valid(n,ans,s+')',copen,cclose+1);
        }


      }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        int copen = 0;
        int cclose = 0;
        valid(n,ans,s,copen,cclose);
        return ans;
    }
};