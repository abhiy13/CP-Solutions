    #include <iostream>
    #include <string>
     
    using namespace std;
     
    int main()
    {
    	std::ios::sync_with_stdio(false);
     
    	int t;
    	cin >> t;
    	while(t--)
    	{
    	     string str;
    		cin >> str;
    		bool count = false;
    		for(int i=2; i<(str.length()); ++i)
    		{
    			if( (str[i-2]=='0') && (str[i-1]=='1') && (str[i]=='0') )
    			{
    				count = true;
    				break;
    			}
    			if( (str[i-2]=='1') && (str[i-1]=='0') && (str[i]=='1') )
    			{
    				count = true;
    				break;
    			}
    		}
     
    		if(count)
    			cout << "Good\n";
    		else
    			cout << "Bad\n";
    	}
     
    	return 0;
    }  
