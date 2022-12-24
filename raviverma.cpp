#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int	
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
const int mod=998244353;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mset(a , b) memset(a , b , sizeof(a))
#define mp make_pair
#define ff            first
#define ss            second
#define nl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#include<bits/debug.h>
#else
#define dbg(x)
#endif
typedef set <int> si;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef multiset <int> msi;
typedef vector <string> vs;
typedef pair <int,int> pii;
typedef vector <char> vch;
typedef vector <pair <int,int>> vpi;
const int inf =1e18;
const double PI=2*acosl(0);
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.ff << ' ' << x.ss;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, deque<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, deque<T>& a) {for(auto &x : a) out << x << ' '; return out;};
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
template <class T> T expo(T base , T exp , T m){T res = 1;base = base % m;while (exp > 0){if (exp & 1)res = (res*base) % m;exp = exp>>1;base = (base*base) % m;}return res;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
void solve()
{
	map<string,double>M;
	vector<string> v = {"TOI","Hindu","ET","BM","HT"};
	M["TOI"]=26;
	M["Hindu"]=20.5;
	M["ET"]=34;
	M["BM"]=10.5;
	M["HT"]=18;
	int n;
	cin>>n;
	set<vector<int>> ansset;
	auto helper = [&](auto && helper,int ind ,double sum_rem, vector<int> taken_ind)->void
	{
		if(ind==5)
		{

			ansset.insert(taken_ind);
			return;
		}
		double cur = M[v[ind]];
		if(cur<=sum_rem)
		{
			taken_ind.pb(ind);
			helper(helper,ind+1,sum_rem-cur,taken_ind);
			taken_ind.ppb();
		}
		helper(helper,ind+1,sum_rem,taken_ind);

	};
	vector<int> vv;
	helper(helper,0,n,vv);
	dbg(ansset);
	int flag = 0 ;
	for(auto it : ansset)
	{
		vector<int>& t = it;
		if(sz(t)>1)
		{
			dbg(t);
			if(flag>0)
			{
				cout<<",";
			}
			cout<<"{";
			for(int i = 0 ;i<sz(t);i++) 
			{
				cout<<'"'<<v[t[i]]<<'"';
				if(sz(t)-1!=i)cout<<",";
			}
			cout<<"}";
			flag=1;
		}
	}
}	
int main()
{
ios
int test_case=1;
for(int _=1;_<=test_case;_++)
{
  auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
}
return 0;
}