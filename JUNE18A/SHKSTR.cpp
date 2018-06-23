#include "bits/stdc++.h"
	using namespace std;
 
typedef long long ll;
 
 
struct trieNode{
	trieNode *node[26];
	bool end;
	trieNode(){
		for(int i = 0 ; i < 26 ; i++) node[i] = nullptr;
		end = false;
	}
};
 
class Trie{
public:
	trieNode *root , *temp;
	ll ans;
	Trie(){
		root = new trieNode;
		ans = 0;
	}
	void add(string s){
		temp = root;
		for(auto &c : s){
			if(temp->node[c - 'a'] == nullptr){
				temp->node[c - 'a'] = new trieNode;
			}
			temp = temp->node[c - 'a'];
		}
		temp->end = true;
	}
 
	void find(trieNode* head , string &s){
		if(head->end) return;
		for(int i = 0 ; i < 26 ; i++){
			if(head->node[i] != nullptr){
				s += (char)(i + 'a');
				find(head->node[i] , s);
				break;
			}
		}
	}
 
	string query(string s){
		temp = root;
		string ss;
		for(auto &c : s){
			if(temp->node[c - 'a'] == nullptr) {break;}
			temp = temp->node[c - 'a'];
			ss += c;
		}
		find(temp , ss);
		return ss;
	}
};
 
 
struct query{
	ll idx , R;
	string s;
	query(){
		idx = R = 0;
		s = "";
	} 
};
 
 
int main(){
	ios::sync_with_stdio(false);
	#ifdef ABHI
		freopen("input.txt" , "r" , stdin);
	#endif
	int n;
	cin>>n;
	vector <string> Str(n , "");
	Trie T;
	for(int i = 0 ; i < n ; i++){
		cin>>Str[i];
	}
	ll qq;
	cin>>qq;
	vector <query> q(qq);
	for(int i = 0 ; i < qq ; i++){
		cin>>q[i].R>>q[i].s;
		q[i].idx = i;
	}
	sort(q.begin(), q.end(),[&](query &a , query &b){
		return a.R < b.R;
	});
	//REMOVE TO DEBUG
	/*for(auto a : q){
		cout<<a.idx <<" "<<a.R<<" "<<a.s<<endl;
	}*/
	vector <string> res(qq,"");
	ll added = 0;
	for(int i = 0 ; i < qq ; i++){
		while(added < q[i].R and added < n){
			T.add(Str[added++]);
		}
		res[q[i].idx] = T.query(q[i].s);
	}
	for(auto &c : res){
		cout<<c<<endl;
	}
	#ifdef ABHI
		cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
	#endif
	return 0;
}  
