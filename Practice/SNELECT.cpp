    #include<iostream>
    #include<string>
     
    using namespace std;
     
    int main()
    {
	std::ios::sync_with_stdio(false);
    	int t;
    	cin>>t;
    	string s;
    	for (int i = 0 ;i < t ; i ++)
    	{
    		cin>>s;
    		int j = 0;
    		while (j < s.size()-1)
    		{
    			if (s[j] == 'm' && s[j+1] == 's')
    			{
    				s.erase(j+1,1);
    			}
    			else if (s[j] == 's' && s[j+1] == 'm')
    			{
    				s.erase(j,1);
    			}
    			j++;
    		}
    		int sc = 0;
    		int m = 0;
    		for (int j = 0 ; j < s.size() ; j ++)
    		{
    			if (s[j] == 's')
    			{
    				++sc;
    			}
    			else
    			{
    				++m;
    			}
    		}
    		if (sc>m){cout<<"snakes"<<endl;}
    		else if (m>sc){cout<<"mongooses"<<endl;}
    		else{cout<<"tie"<<endl;}
    	}
     
    	return 0;
    }  
