class Solution {
public:
    int minimumRefill(vector<int>& p, int ca, int cb) {
        int a=ca;
        int b=cb;
        
        int i=0,j=p.size()-1;
        int cnt=0;
        while(i<=j){
            // cout<<a<<" "<<b<<" "<<cnt<<endl;
            if(i==j){
                if(a>=b){
                    if(p[i]>a){
                        cnt++;
                        a=ca-p[i];
                    }else a-=p[i];
                }else {
                    if(p[j]>b){
                        cnt++;
                       b=cb-p[j];
                    }else b-=p[j];
                }
                break;
            }
            if(p[i]>a){
                cnt++;
                a=ca-p[i];
            }else a-=p[i];
            
            if(p[j]>b){
                cnt++;
                b=cb-p[j];
            }else b-=p[j];
            i++,j--;
        }
        return cnt;
    }
};