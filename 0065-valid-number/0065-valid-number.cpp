class Solution {
public:
    bool isNumber(string s) {
        if(s == ".")return false;
        int sign = 0, e = 0, d = 0, n = 0;
        bool f = true;
        int ind = -1;
        for(auto i : s){
            ind++;
            if(i == '+' || i == '-'){
                sign++;
                if(d > 0 && e == 0)return false;
                if(e == 0 && n >= 1)return false;
                if(sign == 1){
                    if(e == 0){

                    }
                    else if(ind != 0 && (s[ind - 1] == 'e' || s[ind - 1] == 'E')){
                        
                    }else{
                        return false;
                    }
                }
                else if(sign == 2){
                    if(n >= 1 && e == 1){

                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else if(i == '.'){
                d++;
                if(e > 0 || d > 1)return false;
            }else if(i >= '0' && i <= '9'){
                n++;
                continue;
            }else if(i == 'e' || i == 'E'){
                e++;
                if(e == 1 && n >= 1){
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(s.length() == 1 && n == 0)return false;
        if(n == 0 && d > 0)return false;
        if(s[s.length() - 1] == 'e' || s[s.length() - 1] == 'E')return false;
        if(s.length() > 1 && (s[s.length() - 1] == '+' || s[s.length() - 1] == '-'))return false;
        return true;
    }
};