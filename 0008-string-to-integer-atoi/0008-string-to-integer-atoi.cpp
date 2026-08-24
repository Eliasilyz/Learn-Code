class Solution {
public:
   int myAtoi(string s)
    {
        int i = 0;
        char sign;
        while (s[i] == ' ')
        {
            i++;
        }
        if (isalpha(s[i]))
        {
            return 0;
        }

        if (s[i] == '+' || s[i] == '-')
        {
            sign = s[i];
            i++;
        }
        else
        {
            sign = '+';
        }

        long long int num = 0;

        long long int y = 1, y2 = -1;
        for (int i = 1; i <= 31; i++)
        {
            y *= 2;
            y2 *= 2;
        }

        while (s[i] - '0' <= 9 && s[i] - '0' >= 0)
        {
            int temp = s[i] - '0';
            if(num > y-1  && sign == '+'){
                return y - 1;
            }
            else if( num > abs(y2) && sign == '-'){
                return y2;
            }
            num = num * 10 + temp;
            i++;
        }

       if (sign == '-')
        {
            num *= -1;
        }
        if (num > y - 1)
        {
            return y - 1;
        }
        else if (num < y2)
        {
            return y2;
        }
        else
        {
            return num;
        }
    }
};