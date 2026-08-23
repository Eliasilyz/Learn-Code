class Solution {
	public:
	int M = pow(10, 9) + 7;

	int numWays(string s) {
		long n = s.length();
	
		int oneCount = count(s.begin(), s.end(), '1');
		if (oneCount%3) return 0;
	
		if (oneCount == 0) 
			return (((n - 2)*(n - 1))/2)%M;
	
		oneCount = oneCount/3;
		long cnt = 0, z1 = 0, z2 = 0;
	
		for(auto c: s){
			if (c == '1') cnt++;
		
			if (cnt == oneCount) 
		    	z1++;
			else if(cnt == 2*oneCount) 
		    	z2++;
		}

		return (z1*z2)%M;
	}
};