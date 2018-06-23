    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t,g,i,q;
        long n;
        cin >> t;
        for (int k = 0; k < t; ++k)
        {
            cin >> g;
            for (int j = 0; j < g; ++j)
            {
                cin >> i >> n >> q;
                if(n%2==0)
                    cout << n/2 << endl;
                else if(q==i)
                    cout << n/2 << endl;
                else
                    cout << (n/2)+1 << endl;
            }
        }
        return 0;
    }  
