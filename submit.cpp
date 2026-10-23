#if defined(Hataya_Misuzu_Love) && !defined(_GLIBCXX_DEBUG)
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define el '\n'
#define pb push_back

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using str = string;

template<class T>
using vc = vector<T>;

template<class T>
using vvc = vc<vc<T>>;

using vi = vc<int>;
using vl = vc<ll>;
using vs = vc<str>;
using vb = vc<bool>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using mint = modint998244353;

const ll INF = 1e18;

const vi dx = {1, 0, -1, 0};
const vi dy = {0, 1, 0, -1};

template<class T>
using pq_max = priority_queue<T>;

template<class T>
using pq_min = priority_queue<T, vc<T>, greater<T>>;

#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = ll(a); i < ll(b); i += ll(c))

#define FOR1_R(a) for (ll i = ll(a) - 1; i >= 0; --i)
#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >= 0; --i)
#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)

#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d

#define rep(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define rrep(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) (x).begin(), (x).end()

#define len(x) ll((x).size())

#define fi first
#define se second

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define BIT(n) (1LL << (n))
#define HAS_BIT(mask, i) (((mask) >> (i)) & 1LL)
#define POPCNT(x) __builtin_popcountll(x)
#define TOPBIT(x) ((x) == 0 ? -1 : 63 - __builtin_clzll(x))
#define LOWBIT(x) ((x) == 0 ? -1 : __builtin_ctzll(x))

template<class C, class T>
ll LB(const C& c, const T& x) {
    return lower_bound(all(c), x) - c.begin();
}

template<class C, class T>
ll UB(const C& c, const T& x) {
    return upper_bound(all(c), x) - c.begin();
}

#define UNIQUE(x) \
    sort(all(x)); \
    (x).erase(unique(all(x)), (x).end())

template<class T, class U>
bool chmax(T& a, const U& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T, class U>
bool chmin(T& a, const U& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

#define YesNo(cond) cout << ((cond) ? "Yes" : "No") << el

template<class... T>
void input(T&... x) {
    (cin >> ... >> x);
}

#define INT(...) \
    int __VA_ARGS__; \
    input(__VA_ARGS__)

#define LL(...) \
    ll __VA_ARGS__; \
    input(__VA_ARGS__)

#define STR(...) \
    str __VA_ARGS__; \
    input(__VA_ARGS__)

#define VEC(type, name, size) \
    vc<type> name(size); \
    for (auto& x : name) cin >> x

template<class T>
void cout_vec(const vc<T>& v) {
    rep(i, len(v)) {
        cout << v[i] << (i + 1 == len(v) ? "" : " ");
    }
    cout << el;
}

template<class T, class F>
T bin_search(T ok, T ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        T mid = ok + (ng - ok) / 2;
        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

template<class T>
T ceil_div(T a, T b) {
    return (a + b - 1) / b;
}

template<class T>
T floor_div(T a, T b) {
    T res = a / b;
    T rem = a % b;

    if (rem != 0 && ((a < 0) ^ (b < 0))) {
        --res;
    }

    return res;
}

#ifdef Hataya_Misuzu_Love
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}

template<size_t N, class... T>
typename enable_if<(N >= sizeof...(T))>::type
print_tuple(ostream&, const tuple<T...>&) {}

template<size_t N, class... T>
typename enable_if<(N < sizeof...(T))>::type
print_tuple(ostream& os, const tuple<T...>& t) {
    if (N > 0) os << ", ";
    os << get<N>(t);
    print_tuple<N + 1>(os, t);
}

template<class... T>
ostream& operator<<(ostream& os, const tuple<T...>& t) {
    os << "(";
    print_tuple<0>(os, t);
    return os << ")";
}

template<class T>
auto operator<<(ostream& os, const T& v)
    -> typename enable_if<
        !is_same<T, str>::value,
        decltype(
            v.begin(),
            v.end(),
            decltype(v.begin() != v.end())(true),
            os
        )
    >::type {

    os << "{";

    bool first = true;

    for (const auto& x : v) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }

    return os << "}";
}

void debug_out() {
    cerr << el;
}

template<class Head, class... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H;

    if (sizeof...(T)) {
        cerr << ", ";
    }

    debug_out(T...);
}
#else
#define debug(...) ((void)0)
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <atcoder/scc>
#include <atcoder/maxflow>
#include <atcoder/math>
#include <atcoder/string>
#include <atcoder/segtree>

namespace Hatsuboshi {

/*
    This serves as proof that the library was created before the competition.
    https://atcoder.jp/contests/practice/submissions/80223181

    それはわたし達の永遠の憧れ

    夜空に輝く星のように

    大地に咲く花のように

    みんなの心を熱く震わせて

    かなしさをやさしく包み込んで

    いつも笑顔にしてくれる

    そんな素敵な人になりたくて

    わたしは「初星学園」の門をくぐりました———

    君と出会い、夢に翔ける
    */

template<class T>
struct CoordinateCompress {
    vc<T> xs;
    bool built = false;

    CoordinateCompress() {}
    CoordinateCompress(const vc<T>& v) : xs(v) { build(); }

    void add(const T& x) { xs.pb(x); built = false; }
    template<class It>
    void add(It first, It last) { xs.insert(xs.end(), first, last); built = false; }

    void build() {
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        built = true;
    }

    int get(const T& x) const { return lower_bound(all(xs), x) - xs.begin(); }
    int lower(const T& x) const { return lower_bound(all(xs), x) - xs.begin(); }
    int upper(const T& x) const { return upper_bound(all(xs), x) - xs.begin(); }
    const T& value(int i) const { return xs[i]; }
    int size() const { return (int)xs.size(); }

    vi compress(const vc<T>& v) const {
        vi res(v.size());
        rep(i, v.size()) res[i] = get(v[i]);
        return res;
    }
};

template<class T>
struct Imos2D {
    int h,w; vvc<T> a;
    Imos2D(int h,int w):h(h),w(w),a(h+1,vc<T>(w+1)){}
    void add(int r1,int c1,int r2,int c2,T x){a[r1][c1]+=x;a[r1][c2]-=x;a[r2][c1]-=x;a[r2][c2]+=x;}
    vvc<T> build(){
        for(int i=0;i<=h;++i)for(int j=1;j<=w;++j)a[i][j]+=a[i][j-1];
        for(int j=0;j<=w;++j)for(int i=1;i<=h;++i)a[i][j]+=a[i-1][j];
        vvc<T> r(h,vc<T>(w));
        for(int i=0;i<h;++i)for(int j=0;j<w;++j)r[i][j]=a[i][j];
        return r;
    }
};

template<class T>
ll inversion_number(vc<T> a) {
    vc<T> xs=a;sort(xs.begin(),xs.end());xs.erase(unique(xs.begin(),xs.end()),xs.end());
    int n=xs.size();vi bit(n+1);
    auto add=[&](int p){for(++p;p<=n;p+=p&-p)++bit[p];};
    auto sum=[&](int r){int s=0;for(;r;r-=r&-r)s+=bit[r];return s;};
    ll ans=0;
    for(int i=0;i<(int)a.size();++i){int p=lower_bound(xs.begin(),xs.end(),a[i])-xs.begin();ans+=i-sum(p+1);add(p);}
    return ans;
}

template<class T>
pair<int, vi> LIS(const vc<T>& a, bool strict = true) {
    int n = a.size();
    vc<T> tail;
    vi tail_idx, prev(n, -1);

    rep(i, n) {
        int p = strict
            ? lower_bound(all(tail), a[i]) - tail.begin()
            : upper_bound(all(tail), a[i]) - tail.begin();
        if (p == (int)tail.size()) {
            tail.pb(a[i]);
            tail_idx.pb(i);
        } else {
            tail[p] = a[i];
            tail_idx[p] = i;
        }
        if (p) prev[i] = tail_idx[p - 1];
    }

    vi idx;
    if (!tail_idx.empty()) {
        for (int v = tail_idx.back(); v != -1; v = prev[v]) idx.pb(v);
        reverse(all(idx));
    }
    return {(int)tail.size(), idx};
}

struct Mo {
    struct Query { int l, r, id; };
    int n;
    vc<Query> qs;

    Mo(int n = 0) : n(n) {}

    int add_query(int l, int r) {
        int id = (int)qs.size();
        qs.pb({l, r, id});
        return id;
    }

    template<class AddL, class AddR, class DelL, class DelR, class Answer>
    void run(AddL add_l, AddR add_r, DelL del_l, DelR del_r, Answer answer) {
        int q = (int)qs.size();
        int B = max(1, (int)(n / max(1.0, sqrt((double)max(1, q)))));
        sort(all(qs), [&](const Query& a, const Query& b) {
            int ab = a.l / B, bb = b.l / B;
            if (ab != bb) return ab < bb;
            if (ab & 1) return a.r > b.r;
            return a.r < b.r;
        });
        int l = 0, r = 0;
        for (auto qu : qs) {
            while (l > qu.l) add_l(--l);
            while (r < qu.r) add_r(r++);
            while (l < qu.l) del_l(l++);
            while (r > qu.r) del_r(--r);
            answer(qu.id);
        }
    }

    template<class Add, class Del, class Answer>
    void run(Add add, Del del, Answer answer) {
        run(add, add, del, del, answer);
    }
};

template<class Reset, class Apply, class Check>
vi parallel_binary_search(int q, int m, Reset reset, Apply apply, Check check) {
    vi lo(q, -1), hi(q, m + 1);
    while (true) {
        bool any = false;
        vvc<int> bucket(m + 1);
        rep(i, q) {
            if (hi[i] - lo[i] > 1) {
                any = true;
                int mid = (lo[i] + hi[i]) >> 1;
                if (mid <= m) bucket[mid].pb(i);
            }
        }
        if (!any) break;
        reset();
        for (int t = 0; t <= m; ++t) {
            if (t > 0) apply(t - 1);
            for (int id : bucket[t]) {
                if (check(id)) hi[id] = t;
                else lo[id] = t;
            }
        }
    }
    return hi;
}

template<class T>
struct PrefixSum2D {
    int h=0,w=0; vvc<T> s;
    PrefixSum2D() {}
    explicit PrefixSum2D(const vvc<T>& a){build(a);}
    void build(const vvc<T>& a){
        h=a.size();w=h?a[0].size():0;s.assign(h+1,vc<T>(w+1));
        for(int i=0;i<h;++i)for(int j=0;j<w;++j)s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
    }
    T sum(int r1,int c1,int r2,int c2) const {return s[r2][c2]-s[r1][c2]-s[r2][c1]+s[r1][c1];}
};

template<class Seq>
auto run_length_encode(const Seq& a) {
    using T = typename Seq::value_type;
    vc<pair<T, int>> res;
    for (const auto& x : a) {
        if (res.empty() || res.back().first != x) res.push_back({x, 1});
        else ++res.back().second;
    }
    return res;
}

template<class T>
i128 sum_all_subarray_sum(const vc<T>& a) {
    int n = (int)a.size();
    i128 ans = 0;
    rep(i, n) ans += (i128)a[i] * (i + 1) * (n - i);
    return ans;
}

template<class T>
i128 sum_all_subarray_min(const vc<T>& a) {
    int n = (int)a.size();
    vi L(n), R(n), st;
    rep(i, n) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        L[i] = st.empty() ? -1 : st.back();
        st.pb(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
        R[i] = st.empty() ? n : st.back();
        st.pb(i);
    }
    i128 ans = 0;
    rep(i, n) ans += (i128)a[i] * (i - L[i]) * (R[i] - i);
    return ans;
}

template<class T>
i128 sum_all_subarray_max(const vc<T>& a) {
    int n = (int)a.size();
    vi L(n), R(n), st;
    rep(i, n) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        L[i] = st.empty() ? -1 : st.back();
        st.pb(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
        R[i] = st.empty() ? n : st.back();
        st.pb(i);
    }
    i128 ans = 0;
    rep(i, n) ans += (i128)a[i] * (i - L[i]) * (R[i] - i);
    return ans;
}

template<class T>
i128 sum_all_subarray_range(const vc<T>& a) {
    return sum_all_subarray_max(a) - sum_all_subarray_min(a);
}

struct QuotientRange { ll left, right, quotient; };

inline vc<QuotientRange> quotient_ranges(ll n) {
    assert(n >= 0);
    vc<QuotientRange> result;
    for (ll l = 1; l <= n; ) {
        ll q = n / l, r = n / q;
        result.pb({l, r, q});
        if (r == n) break;
        l = r + 1;
    }
    return result;
}

struct SubsetSum {
    int limit;
    vc<ull> bits;
    explicit SubsetSum(int limit):limit(limit),bits(limit/64+1){assert(limit>=0);bits[0]=1;}
    void add(int weight){
        assert(weight>=0);if(weight>limit||weight==0)return;
        int shift=weight/64,offset=weight%64;
        rrep(i,shift,len(bits)){
            ull value=bits[i-shift]<<offset;
            if(offset&&i>shift)value|=bits[i-shift-1]>>(64-offset);
            bits[i]|=value;
        }
        int used=limit%64+1;if(used<64)bits.back()&=(1ULL<<used)-1;
    }
    bool test(int sum) const {assert(0<=sum&&sum<=limit);return bits[sum/64]>>(sum%64)&1;}
};

struct BoundedKnapsackItem { int weight; ll value; ll count; };

inline vc<optional<i128>> bounded_knapsack(int capacity,const vc<BoundedKnapsackItem>& items){
    assert(capacity>=0);vc<optional<i128>> dp(capacity+1);dp[0]=0;
    for(auto item:items){
        assert(item.weight>=0&&item.count>=0);
        if(item.weight==0){if(item.value>0)for(auto& x:dp)if(x)*x+=(i128)item.value*item.count;continue;}
        if(item.weight>capacity||item.count==0)continue;
        auto previous=dp;fill(all(dp),nullopt);
        rep(r,min(item.weight,capacity+1)){
            deque<pair<ll,i128>> queue;
            for(ll t=0,w=r;w<=capacity;++t,w+=item.weight){
                while(!queue.empty()&&queue.front().fi<t-item.count)queue.pop_front();
                if(previous[w]){i128 score=*previous[w]-(i128)t*item.value;
                    while(!queue.empty()&&queue.back().se<=score) queue.pop_back();
                    queue.pb({t,score});}
                if(!queue.empty())dp[w]=queue.front().se+(i128)t*item.value;
            }
        }
    }
    return dp;
}

template<class UInt = ull, int LOG = 63>
struct BinaryTrie {
    struct Node {
        int ch[2] = {-1, -1};
        int cnt = 0;
    };

    vc<Node> tr = vc<Node>(1);
    UInt lazy_xor = 0;

    int size() const { return tr[0].cnt; }
    bool empty() const { return size() == 0; }

    void xor_all(UInt x) { lazy_xor ^= x; }

    void insert(UInt x, int num = 1) {
        x ^= lazy_xor;
        int v = 0;
        tr[v].cnt += num;
        for (int b = LOG - 1; b >= 0; --b) {
            int c = (x >> b) & 1;
            if (tr[v].ch[c] == -1) {
                tr[v].ch[c] = (int)tr.size();
                tr.pb(Node{});
            }
            v = tr[v].ch[c];
            tr[v].cnt += num;
        }
    }

    int count(UInt x) const {
        x ^= lazy_xor;
        int v = 0;
        for (int b = LOG - 1; b >= 0; --b) {
            int c = (x >> b) & 1;
            v = tr[v].ch[c];
            if (v == -1 || tr[v].cnt == 0) return 0;
        }
        return tr[v].cnt;
    }

    bool erase(UInt x, int num = 1) {
        if (count(x) < num) return false;
        x ^= lazy_xor;
        int v = 0;
        tr[v].cnt -= num;
        for (int b = LOG - 1; b >= 0; --b) {
            int c = (x >> b) & 1;
            v = tr[v].ch[c];
            tr[v].cnt -= num;
        }
        return true;
    }

    UInt kth(int k) const {
        assert(0 <= k && k < size());
        int v = 0;
        UInt physical = 0;
        for (int b = LOG - 1; b >= 0; --b) {
            int z = (lazy_xor >> b) & 1;
            int left = tr[v].ch[z];
            int c0 = left == -1 ? 0 : tr[left].cnt;
            int take;
            if (k < c0) take = z;
            else k -= c0, take = z ^ 1;
            physical |= (UInt)take << b;
            v = tr[v].ch[take];
        }
        return physical ^ lazy_xor;
    }

    UInt argmin_xor(UInt x) const {
        assert(!empty());
        UInt key = x ^ lazy_xor;
        int v = 0;
        UInt physical = 0;
        for (int b = LOG - 1; b >= 0; --b) {
            int want = (key >> b) & 1;
            int to = tr[v].ch[want];
            if (to == -1 || tr[to].cnt == 0) want ^= 1;
            physical |= (UInt)want << b;
            v = tr[v].ch[want];
        }
        return physical ^ lazy_xor;
    }

    UInt argmax_xor(UInt x) const {
        assert(!empty());
        UInt key = x ^ lazy_xor;
        int v = 0;
        UInt physical = 0;
        for (int b = LOG - 1; b >= 0; --b) {
            int want = ((key >> b) & 1) ^ 1;
            int to = tr[v].ch[want];
            if (to == -1 || tr[to].cnt == 0) want ^= 1;
            physical |= (UInt)want << b;
            v = tr[v].ch[want];
        }
        return physical ^ lazy_xor;
    }

    UInt min_xor(UInt x) const { return argmin_xor(x) ^ x; }
    UInt max_xor(UInt x) const { return argmax_xor(x) ^ x; }

    int count_less(UInt x) const {
        if constexpr (LOG < numeric_limits<UInt>::digits) {
            if ((x >> LOG) != 0) return size();
        }
        int v = 0, ans = 0;
        for (int b = LOG - 1; b >= 0 && v != -1; --b) {
            int xb = (x >> b) & 1;
            int z = (lazy_xor >> b) & 1;
            if (xb) {
                int to0 = tr[v].ch[z];
                if (to0 != -1) ans += tr[to0].cnt;
                v = tr[v].ch[z ^ 1];
            } else {
                v = tr[v].ch[z];
            }
        }
        return ans;
    }
};

template<class T, class F>
struct DisjointSparseTable {
    int n = 0, lg = 0;
    vc<T> a;
    vvc<T> st;
    F op;

    DisjointSparseTable() {}
    DisjointSparseTable(const vc<T>& a, F op) : op(op) { build(a); }

    void build(const vc<T>& v) {
        a = v;
        n = (int)a.size();
        lg = 1;
        while ((1 << lg) < max(1, n)) ++lg;
        st.assign(lg, vc<T>(n));
        if (n) st[0] = a;

        FOR3(k, 1, lg) {
            int len = 1 << (k + 1);
            int half = 1 << k;
            for (int block = 0; block < n; block += len) {
                int mid = min(block + half, n);
                int r = min(block + len, n);
                if (block < mid) {
                    st[k][mid - 1] = a[mid - 1];
                    for (int i = mid - 2; i >= block; --i) st[k][i] = op(a[i], st[k][i + 1]);
                }
                if (mid < r) {
                    st[k][mid] = a[mid];
                    FOR3(i, mid + 1, r) st[k][i] = op(st[k][i - 1], a[i]);
                }
            }
        }
    }

    T prod(int l, int r) const {
        if (r - l == 1) return a[l];
        int x = l ^ (r - 1);
        int k = 31 - __builtin_clz((unsigned)x);
        return op(st[k][l], st[k][r - 1]);
    }
};

template<class S, S (*op)(S, S), S (*e)()>
struct DynamicSegTree {
    struct Node {
        int l = -1, r = -1;
        S val = e();
    };

    ll L, R;
    vc<Node> tr;
    int root = -1;

    DynamicSegTree(ll L, ll R) : L(L), R(R) { assert(L < R); }

    int new_node() {
        tr.pb(Node{});
        return (int)tr.size() - 1;
    }

    S value(int v) const { return v == -1 ? e() : tr[v].val; }

    void set_impl(int v, ll l, ll r, ll p, const S& x) {
        if (r - l == 1) {
            tr[v].val = x;
            return;
        }
        ll m = l + (r - l) / 2;
        if (p < m) {
            if (tr[v].l == -1) {
                int nv = new_node();
                tr[v].l = nv;
            }
            int to = tr[v].l;
            set_impl(to, l, m, p, x);
        } else {
            if (tr[v].r == -1) {
                int nv = new_node();
                tr[v].r = nv;
            }
            int to = tr[v].r;
            set_impl(to, m, r, p, x);
        }
        tr[v].val = op(value(tr[v].l), value(tr[v].r));
    }

    S prod_impl(int v, ll l, ll r, ll ql, ll qr) const {
        if (v == -1 || qr <= l || r <= ql) return e();
        if (ql <= l && r <= qr) return tr[v].val;
        ll m = l + (r - l) / 2;
        return op(prod_impl(tr[v].l, l, m, ql, qr), prod_impl(tr[v].r, m, r, ql, qr));
    }

    void set(ll p, const S& x) {
        assert(L <= p && p < R);
        if (root == -1) root = new_node();
        set_impl(root, L, R, p, x);
    }

    S get(ll p) const { return prod(p, p + 1); }

    S prod(ll l, ll r) const {
        assert(L <= l && l <= r && r <= R);
        return prod_impl(root, L, R, l, r);
    }

    S all_prod() const { return value(root); }
};

template<class T>
struct FenwickTree2D {
    int H, W;
    vvc<T> bit;
    FenwickTree2D(int H=0, int W=0): H(H), W(W), bit(H+1, vc<T>(W+1, T{})) {}
    void add(int y, int x, T v) {
        for (int i=y+1;i<=H;i+=i&-i) for (int j=x+1;j<=W;j+=j&-j) bit[i][j]+=v;
    }
    T sum_prefix(int y, int x) const {
        T s{};
        for (int i=y;i>0;i-=i&-i) for (int j=x;j>0;j-=j&-j) s+=bit[i][j];
        return s;
    }
    T sum(int y1, int x1, int y2, int x2) const {
        return sum_prefix(y2,x2)-sum_prefix(y1,x2)-sum_prefix(y2,x1)+sum_prefix(y1,x1);
    }
};

template<class T>
struct IntervalSet {
    map<T, T> mp;
    T total = 0;

    bool empty() const { return mp.empty(); }
    T covered_length() const { return total; }

    bool contains(T x) const {
        auto it = mp.upper_bound(x);
        if (it == mp.begin()) return false;
        --it;
        return it->first <= x && x < it->second;
    }

    bool contains(T l, T r) const {
        if (l >= r) return true;
        auto it = mp.upper_bound(l);
        if (it == mp.begin()) return false;
        --it;
        return it->first <= l && r <= it->second;
    }

    T insert(T l, T r) {
        if (l >= r) return 0;
        T before = total;
        auto it = mp.lower_bound(l);
        if (it != mp.begin()) {
            auto pre = prev(it);
            if (pre->second >= l) it = pre;
        }
        while (it != mp.end() && it->first <= r) {
            if (it->second < l) { ++it; continue; }
            l = min(l, it->first);
            r = max(r, it->second);
            total -= it->second - it->first;
            it = mp.erase(it);
        }
        mp[l] = r;
        total += r - l;
        return total - before;
    }

    T erase(T l, T r) {
        if (l >= r) return 0;
        T before = total;
        auto it = mp.upper_bound(l);
        if (it != mp.begin()) --it;
        vc<pair<T, T>> add_back;
        while (it != mp.end()) {
            T a = it->first, b = it->second;
            if (b <= l) { ++it; continue; }
            if (r <= a) break;
            total -= b - a;
            it = mp.erase(it);
            if (a < l) add_back.pb({a, l});
            if (r < b) add_back.pb({r, b});
        }
        for (auto [a, b] : add_back) {
            mp[a] = b;
            total += b - a;
        }
        return before - total;
    }

    T mex(T x = 0) const {
        auto it = mp.upper_bound(x);
        if (it != mp.begin()) {
            auto pre = prev(it);
            if (pre->first <= x && x < pre->second) return pre->second;
        }
        return x;
    }

    vc<pair<T, T>> intervals() const {
        vc<pair<T, T>> res;
        for (auto p : mp) res.pb(p);
        return res;
    }
};

struct MexSet {
    int limit;
    vi cnt;
    set<int> missing;
    MexSet(int limit=0): limit(limit), cnt(limit+1) {
        for (int x=0;x<=limit;x++) missing.insert(x);
        missing.insert(limit + 1);
    }
    void add(ll x) {
        if (x<0 || x>limit) return;
        if (cnt[x]++==0) missing.erase((int)x);
    }
    void erase(ll x) {
        if (x<0 || x>limit) return;
        assert(cnt[x]>0);
        if (--cnt[x]==0) missing.insert((int)x);
    }
    int mex() const { return *missing.begin(); }
};

struct RollbackDSU {
    vi p;
    vc<array<int, 4>> hist;
    int components;

    RollbackDSU() {}
    RollbackDSU(int n) : p(n, -1), components(n) {}

    int leader(int v) const {
        while (p[v] >= 0) v = p[v];
        return v;
    }

    bool same(int a, int b) const {
        return leader(a) == leader(b);
    }

    int size(int v) const {
        return -p[leader(v)];
    }

    int snapshot() const {
        return (int)hist.size();
    }

    bool merge(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (a == b) {
            hist.pb({-1, 0, -1, 0});
            return false;
        }
        if (-p[a] < -p[b]) swap(a, b);
        hist.pb({a, p[a], b, p[b]});
        p[a] += p[b];
        p[b] = a;
        --components;
        return true;
    }

    void undo() {
        assert(!hist.empty());
        auto h = hist.back();
        hist.pop_back();
        if (h[0] == -1) return;
        p[h[0]] = h[1];
        p[h[2]] = h[3];
        ++components;
    }

    void rollback(int snap) {
        while ((int)hist.size() > snap) undo();
    }
};

struct OfflineDynamicConnectivity {
    using Edge = pair<int, int>;
    struct State { int cnt = 0, start = -1; };

    int n, q;
    vvc<Edge> seg;
    map<Edge, State> active;

    OfflineDynamicConnectivity(int n, int q) : n(n), q(q), seg(max(1, 4 * q)) {}

    static Edge norm(int u, int v) {
        if (u > v) swap(u, v);
        return {u, v};
    }

    void add_interval(int k, int l, int r, int a, int b, Edge e) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            seg[k].pb(e);
            return;
        }
        int m = (l + r) >> 1;
        add_interval(k << 1, l, m, a, b, e);
        add_interval(k << 1 | 1, m, r, a, b, e);
    }

    void add_interval(int l, int r, Edge e) {
        if (l < r && q > 0) add_interval(1, 0, q, l, r, e);
    }

    void link(int t, int u, int v) {
        auto e = norm(u, v);
        auto &s = active[e];
        if (s.cnt++ == 0) s.start = t;
    }

    void cut(int t, int u, int v) {
        auto e = norm(u, v);
        auto it = active.find(e);
        assert(it != active.end() && it->second.cnt > 0);
        auto &s = it->second;
        if (--s.cnt == 0) {
            add_interval(s.start, t, e);
            s.start = -1;
        }
    }

    void close_open_edges() {
        for (auto &[e, s] : active) {
            if (s.cnt > 0) {
                add_interval(s.start, q, e);
                s.cnt = 0;
                s.start = -1;
            }
        }
    }

    template<class F>
    void dfs(int k, int l, int r, RollbackDSU &uf, F &at_time) {
        int snap = uf.snapshot();
        for (auto [u, v] : seg[k]) uf.merge(u, v);
        if (r - l == 1) {
            at_time(l, uf);
        } else {
            int m = (l + r) >> 1;
            dfs(k << 1, l, m, uf, at_time);
            dfs(k << 1 | 1, m, r, uf, at_time);
        }
        uf.rollback(snap);
    }

    template<class F>
    void run(F at_time) {
        close_open_edges();
        if (q == 0) return;
        RollbackDSU uf(n);
        dfs(1, 0, q, uf, at_time);
    }
};

using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
struct OrderedMultiset {
    using P = pair<T, int>;
    tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update> st;
    int uid = 0;

    int insert(const T& x) {
        int id = uid++;
        st.insert({x, id});
        return id;
    }

    bool erase_one(const T& x) {
        auto it = st.lower_bound({x, numeric_limits<int>::min()});
        if (it == st.end() || it->fi != x) return false;
        st.erase(it);
        return true;
    }

    int count(const T& x) const {
        return order_of_key_upper(x) - order_of_key(x);
    }

    int order_of_key(const T& x) const {
        return st.order_of_key({x, numeric_limits<int>::min()});
    }

    int order_of_key_upper(const T& x) const {
        return st.order_of_key({x, numeric_limits<int>::max()});
    }

    T kth(int k) const {
        assert(0 <= k && k < (int)st.size());
        return st.find_by_order(k)->fi;
    }

    int size() const { return (int)st.size(); }
    bool empty() const { return st.empty(); }
};

template<class T = ll>
struct PersistentSegTree {
    struct Node {
        int l = -1, r = -1;
        T sum = T{};
    };

    int n = 0;
    vc<Node> tr;

    PersistentSegTree() {}
    PersistentSegTree(int n) : n(n) { tr.reserve(1); }

    int new_node(const Node& x = Node{}) {
        tr.pb(x);
        return (int)tr.size() - 1;
    }

    T node_sum(int v) const { return v == -1 ? T{} : tr[v].sum; }

    int point_add_impl(int v, int l, int r, int p, T x) {
        Node cur = (v == -1 ? Node{} : tr[v]);
        int nv = new_node(cur);
        if (r - l == 1) {
            tr[nv].sum += x;
            return nv;
        }
        int m = (l + r) >> 1;
        if (p < m) tr[nv].l = point_add_impl(cur.l, l, m, p, x);
        else tr[nv].r = point_add_impl(cur.r, m, r, p, x);
        tr[nv].sum = node_sum(tr[nv].l) + node_sum(tr[nv].r);
        return nv;
    }

    int point_set_impl(int v, int l, int r, int p, T x) {
        Node cur = (v == -1 ? Node{} : tr[v]);
        int nv = new_node(cur);
        if (r - l == 1) {
            tr[nv].sum = x;
            return nv;
        }
        int m = (l + r) >> 1;
        if (p < m) tr[nv].l = point_set_impl(cur.l, l, m, p, x);
        else tr[nv].r = point_set_impl(cur.r, m, r, p, x);
        tr[nv].sum = node_sum(tr[nv].l) + node_sum(tr[nv].r);
        return nv;
    }

    T prod_impl(int v, int l, int r, int ql, int qr) const {
        if (v == -1 || qr <= l || r <= ql) return T{};
        if (ql <= l && r <= qr) return tr[v].sum;
        int m = (l + r) >> 1;
        return prod_impl(tr[v].l, l, m, ql, qr) + prod_impl(tr[v].r, m, r, ql, qr);
    }

    int point_add(int root, int p, T x) {
        assert(0 <= p && p < n);
        return point_add_impl(root, 0, n, p, x);
    }

    int point_set(int root, int p, T x) {
        assert(0 <= p && p < n);
        return point_set_impl(root, 0, n, p, x);
    }

    T prod(int root, int l, int r) const {
        return prod_impl(root, 0, n, l, r);
    }

    T all_prod(int root) const { return node_sum(root); }

    int kth(int left_root, int right_root, T k) const {
        T total = node_sum(right_root) - node_sum(left_root);
        assert(T{} <= k && k < total);
        int l = 0, r = n, a = left_root, b = right_root;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            int al = a == -1 ? -1 : tr[a].l;
            int bl = b == -1 ? -1 : tr[b].l;
            T left_count = node_sum(bl) - node_sum(al);
            if (k < left_count) {
                a = al; b = bl; r = m;
            } else {
                k -= left_count;
                a = a == -1 ? -1 : tr[a].r;
                b = b == -1 ? -1 : tr[b].r;
                l = m;
            }
        }
        return l;
    }
};

template<class T>
struct PotentialDSU {
    vi p;
    vc<T> diff_to_parent;

    PotentialDSU() {}
    PotentialDSU(int n) : p(n, -1), diff_to_parent(n, T{}) {}

    int leader(int v) {
        if (p[v] < 0) return v;
        int par = p[v];
        int r = leader(par);
        diff_to_parent[v] += diff_to_parent[par];
        return p[v] = r;
    }

    T potential(int v) {
        leader(v);
        return diff_to_parent[v];
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    int size(int v) {
        return -p[leader(v)];
    }

    bool merge(int a, int b, T w) {
        w += potential(a);
        w -= potential(b);
        a = leader(a);
        b = leader(b);
        if (a == b) return w == T{};
        if (-p[a] < -p[b]) {
            swap(a, b);
            w = -w;
        }
        p[a] += p[b];
        p[b] = a;
        diff_to_parent[b] = w;
        return true;
    }

    T diff(int a, int b) {
        assert(same(a, b));
        return potential(b) - potential(a);
    }
};

struct SegTreeBeats {
    struct Node {
        ll sum = 0;
        ll mx1 = -LLONG_MAX, mx2 = -LLONG_MAX;
        ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
        int mxc = 0, mnc = 0;
        ll add = 0;
    };

    int n;
    vc<Node> st;

    SegTreeBeats() {}
    SegTreeBeats(const vl& a) { build(a); }

    Node merge_node(const Node& a, const Node& b) {
        Node c;
        c.sum = a.sum + b.sum;
        if (a.mx1 > b.mx1) {
            c.mx1 = a.mx1; c.mxc = a.mxc;
            c.mx2 = max(a.mx2, b.mx1);
        } else if (a.mx1 < b.mx1) {
            c.mx1 = b.mx1; c.mxc = b.mxc;
            c.mx2 = max(a.mx1, b.mx2);
        } else {
            c.mx1 = a.mx1; c.mxc = a.mxc + b.mxc;
            c.mx2 = max(a.mx2, b.mx2);
        }
        if (a.mn1 < b.mn1) {
            c.mn1 = a.mn1; c.mnc = a.mnc;
            c.mn2 = min(a.mn2, b.mn1);
        } else if (a.mn1 > b.mn1) {
            c.mn1 = b.mn1; c.mnc = b.mnc;
            c.mn2 = min(a.mn1, b.mn2);
        } else {
            c.mn1 = a.mn1; c.mnc = a.mnc + b.mnc;
            c.mn2 = min(a.mn2, b.mn2);
        }
        return c;
    }

    void build(const vl& a) {
        n = (int)a.size();
        st.assign(max(1, 4 * n), Node{});
        if (n) build(1, 0, n, a);
    }

    void build(int k, int l, int r, const vl& a) {
        if (r - l == 1) {
            ll x = a[l];
            st[k].sum = st[k].mx1 = st[k].mn1 = x;
            st[k].mx2 = -LLONG_MAX;
            st[k].mn2 = LLONG_MAX;
            st[k].mxc = st[k].mnc = 1;
            return;
        }
        int m = (l + r) >> 1;
        build(k << 1, l, m, a);
        build(k << 1 | 1, m, r, a);
        pull(k);
    }

    void pull(int k) { st[k] = merge_node(st[k << 1], st[k << 1 | 1]); }

    void apply_add(int k, ll x, int len) {
        Node &p = st[k];
        p.sum += x * len;
        p.mx1 += x;
        if (p.mx2 != -LLONG_MAX) p.mx2 += x;
        p.mn1 += x;
        if (p.mn2 != LLONG_MAX) p.mn2 += x;
        p.add += x;
    }

    void apply_chmin_node(int k, ll x) {
        Node &p = st[k];
        if (p.mx1 <= x) return;
        p.sum += (x - p.mx1) * p.mxc;
        if (p.mn1 == p.mx1) p.mn1 = x;
        else if (p.mn2 == p.mx1) p.mn2 = x;
        p.mx1 = x;
    }

    void apply_chmax_node(int k, ll x) {
        Node &p = st[k];
        if (p.mn1 >= x) return;
        p.sum += (x - p.mn1) * p.mnc;
        if (p.mx1 == p.mn1) p.mx1 = x;
        else if (p.mx2 == p.mn1) p.mx2 = x;
        p.mn1 = x;
    }

    void push(int k, int l, int r) {
        if (r - l == 1) return;
        int m = (l + r) >> 1;
        if (st[k].add != 0) {
            apply_add(k << 1, st[k].add, m - l);
            apply_add(k << 1 | 1, st[k].add, r - m);
            st[k].add = 0;
        }
        if (st[k << 1].mx1 > st[k].mx1) apply_chmin_node(k << 1, st[k].mx1);
        if (st[k << 1 | 1].mx1 > st[k].mx1) apply_chmin_node(k << 1 | 1, st[k].mx1);
        if (st[k << 1].mn1 < st[k].mn1) apply_chmax_node(k << 1, st[k].mn1);
        if (st[k << 1 | 1].mn1 < st[k].mn1) apply_chmax_node(k << 1 | 1, st[k].mn1);
    }

    void range_chmin(int a, int b, ll x) { if (a < b) range_chmin(1, 0, n, a, b, x); }
    void range_chmax(int a, int b, ll x) { if (a < b) range_chmax(1, 0, n, a, b, x); }
    void range_add(int a, int b, ll x) { if (a < b) range_add(1, 0, n, a, b, x); }
    ll range_sum(int a, int b) { return a < b ? range_sum(1, 0, n, a, b) : 0; }
    ll range_min(int a, int b) { return a < b ? range_min(1, 0, n, a, b) : LLONG_MAX; }
    ll range_max(int a, int b) { return a < b ? range_max(1, 0, n, a, b) : -LLONG_MAX; }

    void range_chmin(int k, int l, int r, int a, int b, ll x) {
        if (b <= l || r <= a || st[k].mx1 <= x) return;
        if (a <= l && r <= b && st[k].mx2 < x) { apply_chmin_node(k, x); return; }
        push(k, l, r);
        int m = (l + r) >> 1;
        range_chmin(k << 1, l, m, a, b, x);
        range_chmin(k << 1 | 1, m, r, a, b, x);
        pull(k);
    }

    void range_chmax(int k, int l, int r, int a, int b, ll x) {
        if (b <= l || r <= a || st[k].mn1 >= x) return;
        if (a <= l && r <= b && st[k].mn2 > x) { apply_chmax_node(k, x); return; }
        push(k, l, r);
        int m = (l + r) >> 1;
        range_chmax(k << 1, l, m, a, b, x);
        range_chmax(k << 1 | 1, m, r, a, b, x);
        pull(k);
    }

    void range_add(int k, int l, int r, int a, int b, ll x) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { apply_add(k, x, r - l); return; }
        push(k, l, r);
        int m = (l + r) >> 1;
        range_add(k << 1, l, m, a, b, x);
        range_add(k << 1 | 1, m, r, a, b, x);
        pull(k);
    }

    ll range_sum(int k, int l, int r, int a, int b) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return st[k].sum;
        push(k, l, r);
        int m = (l + r) >> 1;
        return range_sum(k << 1, l, m, a, b) + range_sum(k << 1 | 1, m, r, a, b);
    }

    ll range_min(int k, int l, int r, int a, int b) {
        if (b <= l || r <= a) return LLONG_MAX;
        if (a <= l && r <= b) return st[k].mn1;
        push(k, l, r);
        int m = (l + r) >> 1;
        return min(range_min(k << 1, l, m, a, b), range_min(k << 1 | 1, m, r, a, b));
    }

    ll range_max(int k, int l, int r, int a, int b) {
        if (b <= l || r <= a) return -LLONG_MAX;
        if (a <= l && r <= b) return st[k].mx1;
        push(k, l, r);
        int m = (l + r) >> 1;
        return max(range_max(k << 1, l, m, a, b), range_max(k << 1 | 1, m, r, a, b));
    }
};

template<class T, class F>
struct SparseTable {
    int n = 0, lg = 0;
    vvc<T> st;
    vi log2_floor;
    F op;

    SparseTable() {}
    SparseTable(const vc<T>& a, F op) : op(op) { build(a); }

    void build(const vc<T>& a) {
        n = (int)a.size();
        log2_floor.assign(n + 1, 0);
        FOR3(i, 2, n + 1) log2_floor[i] = log2_floor[i >> 1] + 1;
        lg = n ? log2_floor[n] + 1 : 0;
        st.assign(lg, vc<T>(n));
        if (!n) return;
        st[0] = a;
        FOR3(k, 1, lg) {
            int w = 1 << k;
            for (int i = 0; i + w <= n; ++i) {
                st[k][i] = op(st[k - 1][i], st[k - 1][i + (w >> 1)]);
            }
        }
    }

    T prod(int l, int r) const {
        int k = log2_floor[r - l];
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};

template<class S, S (*op)(S, S), S (*e)()>
struct SWAG {
    vc<pair<S,S>> front_st, back_st;
    void push(const S& x) {
        S agg = back_st.empty() ? x : op(back_st.back().second, x);
        back_st.push_back({x, agg});
    }
    void move() {
        if (!front_st.empty()) return;
        while (!back_st.empty()) {
            S x = back_st.back().first;
            back_st.pop_back();
            S agg = front_st.empty() ? x : op(x, front_st.back().second);
            front_st.push_back({x, agg});
        }
    }
    void pop() {
        move();
        assert(!front_st.empty());
        front_st.pop_back();
    }
    S prod() const {
        if (front_st.empty() && back_st.empty()) return e();
        if (front_st.empty()) return back_st.back().second;
        if (back_st.empty()) return front_st.back().second;
        return op(front_st.back().second, back_st.back().second);
    }
    int size() const { return (int)front_st.size() + (int)back_st.size(); }
    bool empty() const { return size() == 0; }
};

template<class T>
struct WaveletMatrix {
    int n = 0, lg = 0, sigma = 0;
    vc<T> vals;
    vvc<int> pref_zero;
    vi mid;

    WaveletMatrix() {}
    WaveletMatrix(const vc<T>& a) { build(a); }

    void build(const vc<T>& a) {
        n = (int)a.size();
        vals = a;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        sigma = (int)vals.size();
        lg = 1;
        while ((1LL << lg) < max(1, sigma)) ++lg;
        pref_zero.assign(lg, vi(n + 1));
        mid.assign(lg, 0);

        vi cur(n), nxt(n);
        rep(i, n) cur[i] = (int)(lower_bound(all(vals), a[i]) - vals.begin());
        for (int level = lg - 1, d = 0; level >= 0; --level, ++d) {
            rep(i, n) pref_zero[d][i + 1] = pref_zero[d][i] + (((cur[i] >> level) & 1) == 0);
            mid[d] = pref_zero[d][n];
            int p0 = 0, p1 = mid[d];
            rep(i, n) {
                if (((cur[i] >> level) & 1) == 0) nxt[p0++] = cur[i];
                else nxt[p1++] = cur[i];
            }
            cur.swap(nxt);
        }
    }

    int zero_count(int d, int l, int r) const {
        return pref_zero[d][r] - pref_zero[d][l];
    }

    T kth_smallest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n && 0 <= k && k < r - l);
        int id = 0;
        for (int level = lg - 1, d = 0; level >= 0; --level, ++d) {
            int z = zero_count(d, l, r);
            int zl = pref_zero[d][l], zr = pref_zero[d][r];
            if (k < z) {
                l = zl; r = zr;
            } else {
                k -= z;
                id |= 1 << level;
                l = mid[d] + (l - zl);
                r = mid[d] + (r - zr);
            }
        }
        return vals[id];
    }

    T kth_largest(int l, int r, int k) const {
        return kth_smallest(l, r, r - l - 1 - k);
    }

    int count_less_id(int l, int r, int upper_id) const {
        if (upper_id <= 0) return 0;
        if (upper_id >= sigma) return r - l;
        int ans = 0;
        for (int level = lg - 1, d = 0; level >= 0; --level, ++d) {
            int zl = pref_zero[d][l], zr = pref_zero[d][r];
            if ((upper_id >> level) & 1) {
                ans += zr - zl;
                l = mid[d] + (l - zl);
                r = mid[d] + (r - zr);
            } else {
                l = zl; r = zr;
            }
        }
        return ans;
    }

    int range_freq(int l, int r, const T& upper) const {
        int id = (int)(lower_bound(all(vals), upper) - vals.begin());
        return count_less_id(l, r, id);
    }

    int range_freq(int l, int r, const T& lower, const T& upper) const {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    int freq(int l, int r, const T& x) const {
        auto it = lower_bound(all(vals), x);
        if (it == vals.end() || *it != x) return 0;
        int id = (int)(it - vals.begin());
        return count_less_id(l, r, id + 1) - count_less_id(l, r, id);
    }

    optional<T> prev_value(int l, int r, const T& upper) const {
        int c = range_freq(l, r, upper);
        if (c == 0) return nullopt;
        return kth_smallest(l, r, c - 1);
    }

    optional<T> next_value(int l, int r, const T& lower) const {
        int c = range_freq(l, r, lower);
        if (c == r - l) return nullopt;
        return kth_smallest(l, r, c);
    }
};

template<class T>
struct PersistentQueue {
private:
    struct Node { T value; vi up; };
    struct Version { int tail, size; };
    vc<Node> nodes;
    vc<Version> versions{{-1, 0}};
    void check(int v) const { assert(0 <= v && v < (int)versions.size()); }
public:
    int size(int v) const { check(v); return versions[v].size; }
    bool empty(int v) const { return size(v) == 0; }
    int push(int v, const T& value) {
        check(v);
        Node node{value, {versions[v].tail}};
        for (int k = 1; ; ++k) {
            int p = node.up[k - 1];
            if (p == -1 || (int)nodes[p].up.size() < k) break;
            node.up.pb(nodes[p].up[k - 1]);
        }
        nodes.pb(std::move(node));
        versions.pb({(int)nodes.size() - 1, versions[v].size + 1});
        return (int)versions.size() - 1;
    }
    int pop(int v) {
        check(v); assert(!empty(v));
        auto next = versions[v];
        if (--next.size == 0) next.tail = -1;
        versions.pb(next);
        return (int)versions.size() - 1;
    }

    T front(int v) const {
        check(v); assert(!empty(v));
        int u = versions[v].tail, distance = versions[v].size - 1;
        for (int k = 0; distance; ++k, distance >>= 1)
            if (distance & 1) u = nodes[u].up[k];
        return nodes[u].value;
    }
};

template<class S, auto op, auto e>
struct ImplicitTreap {
private:
    struct Node { S value, forward, backward; ull priority; int left=-1, right=-1, size=1; bool rev=false; };
    vc<Node> nodes;
    int root = -1;
    ull state;
    ull random_priority() {
        ull z = (state += 0x9e3779b97f4a7c15ULL);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }
    int count(int v) const { return v == -1 ? 0 : nodes[v].size; }
    S aggregate(int v, bool rev=false) const { return v == -1 ? e() : rev ? nodes[v].backward : nodes[v].forward; }
    void pull(int v) {
        auto& x = nodes[v]; x.size = count(x.left) + count(x.right) + 1;
        x.forward = op(op(aggregate(x.left), x.value), aggregate(x.right));
        x.backward = op(op(aggregate(x.right,true), x.value), aggregate(x.left,true));
    }
    void reverse_node(int v) {
        if (v == -1) return;
        auto& x = nodes[v]; swap(x.left,x.right); swap(x.forward,x.backward); x.rev ^= true;
    }
    void push(int v) {
        if (!nodes[v].rev) return;
        reverse_node(nodes[v].left); reverse_node(nodes[v].right); nodes[v].rev=false;
    }
    pii split(int v, int k) {
        if (v == -1) return {-1,-1};
        push(v);
        if (k <= count(nodes[v].left)) {
            auto [a,b] = split(nodes[v].left,k); nodes[v].left=b; pull(v); return {a,v};
        }
        auto [a,b] = split(nodes[v].right,k-count(nodes[v].left)-1);
        nodes[v].right=a; pull(v); return {v,b};
    }
    int merge(int a,int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        if (nodes[a].priority > nodes[b].priority) {
            push(a); nodes[a].right=merge(nodes[a].right,b); pull(a); return a;
        }
        push(b); nodes[b].left=merge(a,nodes[b].left); pull(b); return b;
    }
    void range(int l,int r) const { assert(0 <= l && l <= r && r <= size()); }
public:
    explicit ImplicitTreap(ull seed = chrono::steady_clock::now().time_since_epoch().count()) : state(seed) {}
    int size() const { return count(root); }
    void insert(int pos,const S& value) {
        assert(0 <= pos && pos <= size());
        auto [a,b] = split(root,pos);
        int id = len(nodes); nodes.pb({value,value,value,random_priority()});
        root=merge(merge(a,id),b);
    }
    void erase(int pos) {
        range(pos,pos+1); auto [a,b]=split(root,pos); auto [mid,c]=split(b,1);
        (void)mid; root=merge(a,c);
    }
    void set(int pos,const S& value) {
        range(pos,pos+1); auto [a,b]=split(root,pos); auto [mid,c]=split(b,1);
        nodes[mid].value=value; pull(mid); root=merge(a,merge(mid,c));
    }
    S prod(int l,int r) {
        range(l,r); auto [a,b]=split(root,l); auto [mid,c]=split(b,r-l);
        S result=aggregate(mid); root=merge(a,merge(mid,c)); return result;
    }
    void reverse(int l,int r) {
        range(l,r); auto [a,b]=split(root,l); auto [mid,c]=split(b,r-l);
        reverse_node(mid); root=merge(a,merge(mid,c));
    }
};

template<class T>
struct OfflineFenwickTree2D {
private:
    vc<pll> registered;
    vl xs;
    vc<vl> ys;
    vvc<T> bit;
public:
    explicit OfflineFenwickTree2D(const vc<pll>& points):registered(points){
        UNIQUE(registered);
        for(auto [x,y]:points) xs.pb(x);
        UNIQUE(xs);
        ys.resize(len(xs)+1);bit.resize(len(xs)+1);
        for(auto [x,y]:points)for(int i=LB(xs,x)+1;i<=len(xs);i+=i&-i)ys[i].pb(y);
        rep(i,1,len(ys)){UNIQUE(ys[i]);bit[i].assign(len(ys[i])+1,T{});}
    }
    void add(ll x,ll y,T value){
        int pos=LB(xs,x);assert(pos<len(xs)&&xs[pos]==x);
        assert(binary_search(all(registered),pll(x,y)));
        int first=pos+1;
        for(int i=first;i<=len(xs);i+=i&-i){
            int p=LB(ys[i],y);assert(p<len(ys[i])&&ys[i][p]==y);
            for(int j=p+1;j<len(bit[i]);j+=j&-j)bit[i][j]+=value;
        }
    }

    T sum_prefix(ll x,ll y) const {
        T result{};
        for(int i=LB(xs,x);i>0;i-=i&-i)for(int j=LB(ys[i],y);j>0;j-=j&-j)result+=bit[i][j];
        return result;
    }
    T sum(ll x1,ll y1,ll x2,ll y2) const {
        assert(x1<=x2&&y1<=y2);
        return sum_prefix(x2,y2)-sum_prefix(x1,y2)-sum_prefix(x2,y1)+sum_prefix(x1,y1);
    }
};

template<class T = ll>
struct Point2 {
    T x{}, y{};

    Point2() {}
    Point2(T x, T y) : x(x), y(y) {}

    Point2 operator+(const Point2& o) const { return {x + o.x, y + o.y}; }
    Point2 operator-(const Point2& o) const { return {x - o.x, y - o.y}; }
    Point2 operator*(T k) const { return {x * k, y * k}; }
    bool operator==(const Point2& o) const { return x == o.x && y == o.y; }
    bool operator!=(const Point2& o) const { return !(*this == o); }
    bool operator<(const Point2& o) const { return x != o.x ? x < o.x : y < o.y; }
};

template<class T>
i128 cross(const Point2<T>& a, const Point2<T>& b) {
    return (i128)a.x * b.y - (i128)a.y * b.x;
}

template<class T>
i128 cross(const Point2<T>& a, const Point2<T>& b, const Point2<T>& c) {
    return cross(b - a, c - a);
}

template<class T>
i128 dot(const Point2<T>& a, const Point2<T>& b) {
    return (i128)a.x * b.x + (i128)a.y * b.y;
}

template<class T>
i128 norm2(const Point2<T>& a) { return dot(a, a); }

template<class T>
int ccw(const Point2<T>& a, const Point2<T>& b, const Point2<T>& c) {
    i128 z = cross(a, b, c);
    return (z > 0) - (z < 0);
}

template<class T>
bool on_segment(const Point2<T>& a, const Point2<T>& b, const Point2<T>& p) {
    if (cross(a, b, p) != 0) return false;
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

template<class T>
bool segments_intersect(const Point2<T>& a, const Point2<T>& b,
                        const Point2<T>& c, const Point2<T>& d) {
    int ab_c = ccw(a, b, c), ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a), cd_b = ccw(c, d, b);
    if (ab_c == 0 && on_segment(a, b, c)) return true;
    if (ab_d == 0 && on_segment(a, b, d)) return true;
    if (cd_a == 0 && on_segment(c, d, a)) return true;
    if (cd_b == 0 && on_segment(c, d, b)) return true;
    return ab_c * ab_d < 0 && cd_a * cd_b < 0;
}

template<class T>
vc<Point2<T>> convex_hull(vc<Point2<T>> p, bool strict = true) {
    sort(all(p));
    p.erase(unique(all(p)), p.end());
    if (p.size() <= 1) return p;
    bool collinear = true;
    FOR3(i, 2, p.size()) if (cross(p[0], p[1], p[i]) != 0) collinear = false;
    if (collinear) {
        if (!strict) return p;
        return vc<Point2<T>>{p.front(), p.back()};
    }
    vc<Point2<T>> lo, hi;
    for (auto q : p) {
        while (lo.size() >= 2) {
            i128 z = cross(lo[lo.size() - 2], lo.back(), q);
            if (strict ? z <= 0 : z < 0) lo.pop_back();
            else break;
        }
        lo.pb(q);
    }
    for (int i = (int)p.size() - 1; i >= 0; --i) {
        auto q = p[i];
        while (hi.size() >= 2) {
            i128 z = cross(hi[hi.size() - 2], hi.back(), q);
            if (strict ? z <= 0 : z < 0) hi.pop_back();
            else break;
        }
        hi.pb(q);
    }
    lo.pop_back();
    hi.pop_back();
    lo.insert(lo.end(), all(hi));
    return lo;
}

template<class T>
i128 polygon_area2(const vc<Point2<T>>& p) {
    i128 s = 0;
    rep(i, p.size()) s += cross(p[i], p[(i + 1) % p.size()]);
    return s >= 0 ? s : -s;
}

template<class T = ll>
struct Edge {
    int from, to, id;
    T cost;
    Edge(int from, int to, T cost = T(1), int id = -1): from(from), to(to), id(id), cost(cost) {}
    operator int() const { return to; }
};
template<class T = ll>
struct Graph {
    int n, edge_count = 0;
    vvc<Edge<T>> g;
    Graph(): n(0) {}
    explicit Graph(int n): n(n), g(n) {}
    int size() const { return n; }
    auto& operator[](int v) { return g[v]; }
    const auto& operator[](int v) const { return g[v]; }
    int add_directed_edge(int u, int v, T w = T(1)) {
        int id = edge_count++;
        g[u].emplace_back(u, v, w, id);
        return id;
    }
    int add_edge(int u, int v, T w = T(1)) {
        int id = edge_count++;
        g[u].emplace_back(u, v, w, id);
        g[v].emplace_back(v, u, w, id);
        return id;
    }
};

template<class T = ll>
struct BellmanFordResult { vc<T> dist; vi parent; vb neg; T inf; bool reachable(int v) const { return dist[v] != inf; } };
template<class T>
BellmanFordResult<T> bellman_ford(const Graph<T>& g,int s,T inf=numeric_limits<T>::max()/4){
    vc<T> dist(g.n,inf); vi par(g.n,-1); vb neg(g.n,false); dist[s]=0;
    rep(i,g.n){ bool upd=false; rep(v,g.n) if(dist[v]!=inf) for(auto &e:g[v]) if(dist[e.to] > dist[v]+e.cost){ dist[e.to]=dist[v]+e.cost; par[e.to]=v; upd=true; if(i==g.n-1) neg[e.to]=true; } if(!upd) break; }
    rep(_,g.n) rep(v,g.n) if(neg[v]) for(auto &e:g[v]) neg[e.to]=true;
    return {dist,par,neg,inf};
}

struct BFSResult {
    vi dist, parent;
    bool reachable(int v) const { return dist[v] != -1; }
    vi path(int t) const {
        if (!reachable(t)) return {};
        vi p;
        while (t != -1) p.push_back(t), t = parent[t];
        reverse(p.begin(), p.end());
        return p;
    }
};
template<class G>
BFSResult bfs(const G& g, const vi& src) {
    int n = g.size();
    vi d(n, -1), par(n, -1);
    queue<int> q;
    for (int s : src) if (d[s] == -1) d[s] = 0, q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto&& e : g[v]) {
            int to = (int)e;
            if (d[to] != -1) continue;
            d[to] = d[v] + 1;
            par[to] = v;
            q.push(to);
        }
    }
    return {d, par};
}
template<class G>
BFSResult bfs(const G& g, int s) { return bfs(g, vi{s}); }

struct BipartiteResult {
    bool ok;
    vi color, odd_cycle;
    bool same_side(int u, int v) const { return color[u] != -1 && color[u] == color[v]; }
    pair<vi,vi> groups() const {
        vi a, b;
        for (int i = 0; i < (int)color.size(); ++i)
            if (color[i] == 0) a.push_back(i); else if (color[i] == 1) b.push_back(i);
        return {a,b};
    }
};
template<class G>
BipartiteResult bipartite(const G& g) {
    int n = g.size();
    vi col(n,-1), par(n,-1), dep(n);
    for (int s=0;s<n;++s) if (col[s]==-1) {
        queue<int> q; col[s]=0; q.push(s);
        while(!q.empty()) {
            int v=q.front();q.pop();
            for(auto&& e:g[v]) {
                int to=(int)e;
                if(col[to]==-1) {
                    col[to]=col[v]^1; par[to]=v; dep[to]=dep[v]+1; q.push(to);
                } else if(col[to]==col[v]) {
                    int a=v,b=to;
                    vi l,r;
                    while(dep[a]>dep[b]) l.push_back(a),a=par[a];
                    while(dep[b]>dep[a]) r.push_back(b),b=par[b];
                    while(a!=b) l.push_back(a),r.push_back(b),a=par[a],b=par[b];
                    l.push_back(a);
                    reverse(r.begin(),r.end());
                    l.insert(l.end(),r.begin(),r.end());
                    l.push_back(v);
                    return {false,col,l};
                }
            }
        }
    }
    return {true,col,{}};
}

template<class G>
vi find_directed_cycle(const G& g) {
    int n=g.size(); vi state(n),par(n,-1);
    for(int s=0;s<n;++s) if(!state[s]) {
        vc<pair<int,int>> st{{s,0}}; state[s]=1;
        while(!st.empty()) {
            int v=st.back().first, &i=st.back().second;
            if(i==(int)g[v].size()) { state[v]=2; st.pop_back(); continue; }
            int to=(int)g[v][i++];
            if(!state[to]) par[to]=v,state[to]=1,st.push_back({to,0});
            else if(state[to]==1) {
                vi p{to};
                for(int x=v;x!=to;x=par[x]) p.push_back(x);
                reverse(p.begin()+1,p.end()); p.push_back(to); return p;
            }
        }
    }
    return {};
}
template<class T>
vi find_undirected_cycle(const Graph<T>& g) {
    int n=g.size(); vi state(n),par(n,-1),pe(n,-1);
    for(int s=0;s<n;++s) if(!state[s]) {
        vc<pair<int,int>> st{{s,0}}; state[s]=1;
        while(!st.empty()) {
            int v=st.back().first, &i=st.back().second;
            if(i==(int)g[v].size()) { state[v]=2; st.pop_back(); continue; }
            auto e=g[v][i++]; if(e.id==pe[v]) continue;
            if(!state[e.to]) par[e.to]=v,pe[e.to]=e.id,state[e.to]=1,st.push_back({e.to,0});
            else if(state[e.to]==1) {
                vi p{e.to};
                for(int x=v;x!=e.to;x=par[x]) p.push_back(x);
                reverse(p.begin()+1,p.end()); p.push_back(e.to); return p;
            }
        }
    }
    return {};
}

template<class T>
struct DijkstraResult {
    vc<T> dist;
    vi parent;
    T inf;
    bool reachable(int v) const { return dist[v] != inf; }
    vi path(int t) const {
        if (!reachable(t)) return {};
        vi p;
        while (t != -1) p.push_back(t), t = parent[t];
        reverse(p.begin(), p.end());
        return p;
    }
};
template<class T>
DijkstraResult<T> dijkstra(const Graph<T>& g, int s) {
    T INF_ = numeric_limits<T>::max() / 4;
    vc<T> d(g.size(), INF_);
    vi par(g.size(), -1);
    pq_min<pair<T,int>> pq;
    d[s] = 0; pq.emplace(0, s);
    while (!pq.empty()) {
        auto [dv, v] = pq.top(); pq.pop();
        if (dv != d[v]) continue;
        for (auto& e : g[v]) {
            if (e.cost < 0) continue;
            if (d[v] > INF_ - e.cost) continue;
            T nd = d[v] + e.cost;
            if (nd >= d[e.to]) continue;
            d[e.to] = nd; par[e.to] = v;
            pq.emplace(nd, e.to);
        }
    }
    return {d, par, INF_};
}

struct FunctionalGraph {
    int n;
    vi to, component, depth_to_cycle;
    vvc<int> cycles;
    explicit FunctionalGraph(vi to):n(to.size()),to(move(to)),component(n,-1),depth_to_cycle(n,-1){ build(); }
    void build() {
        vi in(n); vvc<int> rev(n);
        for(int v=0;v<n;++v) ++in[to[v]],rev[to[v]].push_back(v);
        queue<int> q; vb removed(n);
        for(int v=0;v<n;++v) if(!in[v]) q.push(v);
        while(!q.empty()){int v=q.front();q.pop();removed[v]=1;if(--in[to[v]]==0)q.push(to[v]);}
        for(int s=0;s<n;++s) if(!removed[s]&&component[s]==-1) {
            int id=cycles.size(),v=s; vi c;
            do {component[v]=id;depth_to_cycle[v]=0;c.push_back(v);v=to[v];} while(v!=s);
            cycles.push_back(c);
        }
        for(auto& c:cycles) for(int v:c) q.push(v);
        while(!q.empty()){int v=q.front();q.pop();for(int u:rev[v])if(depth_to_cycle[u]==-1){depth_to_cycle[u]=depth_to_cycle[v]+1;component[u]=component[v];q.push(u);}}
    }
    bool on_cycle(int v) const { return depth_to_cycle[v]==0; }
    int cycle_size(int v) const { return cycles[component[v]].size(); }
};

template<class F>
vvc<int> grid_bfs(int h,int w,const vc<pair<int,int>>& src,F passable) {
    vvc<int> d(h,vi(w,-1)); queue<pair<int,int>> q;
    for(auto [r,c]:src) if(0<=r&&r<h&&0<=c&&c<w&&passable(r,c)&&d[r][c]==-1) d[r][c]=0,q.push({r,c});
    const int dr[]={1,0,-1,0},dc[]={0,1,0,-1};
    while(!q.empty()) {
        auto [r,c]=q.front();q.pop();
        for(int k=0;k<4;++k) {
            int nr=r+dr[k],nc=c+dc[k];
            if(nr<0||nr>=h||nc<0||nc>=w||!passable(nr,nc)||d[nr][nc]!=-1) continue;
            d[nr][nc]=d[r][c]+1;q.push({nr,nc});
        }
    }
    return d;
}
template<class F>
vvc<int> grid_bfs(int h,int w,pair<int,int> s,F f) {
    return grid_bfs(h,w,vc<pair<int,int>>{s},f);
}

struct LowLink {
    struct E { int to, id; };
    int n, edge_cnt = 0, timer = 0;
    vvc<E> g;
    vi ord, low;
    vi articulation;
    vi bridges;

    LowLink() {}
    LowLink(int n) : n(n), g(n), ord(n, -1), low(n, -1) {}

    int add_edge(int u, int v) {
        int id = edge_cnt++;
        g[u].pb({v, id});
        g[v].pb({u, id});
        return id;
    }

    void dfs(int v, int pe = -1) {
        struct Frame { int v, pe, next, children; bool art; };
        vc<Frame> stack;
        ord[v] = low[v] = timer++;
        stack.pb({v, pe, 0, 0, false});
        while (!stack.empty()) {
            auto& frame = stack.back();
            int current = frame.v;
            if (frame.next < len(g[current])) {
                auto [to, id] = g[current][frame.next++];
                if (id == frame.pe) continue;
                if (ord[to] == -1) {
                    ++frame.children;
                    ord[to] = low[to] = timer++;
                    stack.pb({to, id, 0, 0, false});
                } else chmin(low[current], ord[to]);
            } else {
                auto finished = frame;
                stack.pop_back();
                if (finished.art || (finished.pe == -1 && finished.children >= 2))
                    articulation.pb(current);
                if (!stack.empty()) {
                    auto& parent = stack.back();
                    chmin(low[parent.v], low[current]);
                    if (parent.pe != -1 && ord[parent.v] <= low[current]) parent.art = true;
                    if (ord[parent.v] < low[current]) bridges.pb(finished.pe);
                }
            }
        }
    }

    void build() {
        fill(all(ord), -1);
        fill(all(low), -1);
        timer = 0;
        articulation.clear(); bridges.clear();
        rep(v, n) if (ord[v] == -1) dfs(v);
    }

    vi two_edge_component_ids() const {
        vc<char> is_bridge(edge_cnt, 0);
        for (int id : bridges) is_bridge[id] = 1;
        vi comp(n, -1);
        int cid = 0;
        rep(s, n) if (comp[s] == -1) {
            queue<int> q;
            q.push(s); comp[s] = cid;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto [to, id] : g[v]) if (!is_bridge[id] && comp[to] == -1) {
                    comp[to] = cid;
                    q.push(to);
                }
            }
            ++cid;
        }
        return comp;
    }
};

template<class T = ll>
struct MSTResult { T cost{}; vi edge_ids; bool connected = false; };
template<class T>
MSTResult<T> kruskal(const Graph<T>& g) {
    struct E { T w; int u,v,id; };
    vc<E> es;
    rep(u,g.n) for (auto &e:g[u]) if (e.from < e.to) es.pb({e.cost,e.from,e.to,e.id});
    sort(all(es),[](const E& a,const E& b){ return a.w < b.w; });
    atcoder::dsu uf(g.n); MSTResult<T> res;
    for(auto &e:es) if(!uf.same(e.u,e.v)){ uf.merge(e.u,e.v); res.cost += e.w; res.edge_ids.pb(e.id); }
    res.connected = (g.n == 0 || len(res.edge_ids) == g.n - 1);
    return res;
}

struct TopologicalSortResult { bool is_dag; vi order; };
template<class G>
TopologicalSortResult topological_sort(const G& g) {
    int n=g.size(); vi in(n);
    for(int v=0;v<n;++v) for(auto&& e:g[v]) ++in[(int)e];
    pq_min<int> q;
    for(int v=0;v<n;++v) if(!in[v]) q.push(v);
    vi ord;
    while(!q.empty()) {
        int v=q.top();q.pop();ord.push_back(v);
        for(auto&& e:g[v]) if(--in[(int)e]==0) q.push((int)e);
    }
    return {(int)ord.size()==n,ord};
}

template<class T, class Callback>
vvc<T> warshall_floyd_steps(const Graph<T>& g, Callback&& on_step,
                            T inf = numeric_limits<T>::max() / 4) {
    vvc<T> d(g.n, vc<T>(g.n, inf));
    rep(i, g.n) d[i][i] = 0;
    rep(v, g.n) for (const auto& e : g[v]) chmin(d[v][e.to], e.cost);
    rep(k, g.n) {
        rep(i, g.n) if (d[i][k] != inf)
            rep(j, g.n) if (d[k][j] != inf)
                chmin(d[i][j], d[i][k] + d[k][j]);
        on_step((int)k, as_const(d));
    }
    return d;
}

template<class T>
vvc<T> warshall_floyd(const Graph<T>& g, T inf = numeric_limits<T>::max() / 4) {
    return warshall_floyd_steps(g, [](int, const vvc<T>&) {}, inf);
}

template<class T>
DijkstraResult<T> zero_one_bfs(const Graph<T>& g, int s) {
    T INF_ = numeric_limits<T>::max() / 4;
    vc<T> d(g.size(), INF_);
    vi par(g.size(), -1);
    deque<int> q;
    d[s] = 0; q.push_front(s);
    while (!q.empty()) {
        int v = q.front(); q.pop_front();
        for (auto& e : g[v]) {
            assert(e.cost == T(0) || e.cost == T(1));
            T nd = d[v] + e.cost;
            if (nd >= d[e.to]) continue;
            d[e.to] = nd; par[e.to] = v;
            if (e.cost == T(0)) q.push_front(e.to);
            else q.push_back(e.to);
        }
    }
    return {d, par, INF_};
}

struct SCCResult {
    vvc<int> groups;
    vi id;
    vvc<int> dag;
};

template<class T>
SCCResult strongly_connected_components(const Graph<T>& g) {
    atcoder::scc_graph acl(g.size());
    rep(v, 0, g.size())
        for (const auto& e : g[v]) acl.add_edge(v, e.to);
    SCCResult res;
    res.groups = acl.scc();
    res.id.resize(g.size());
    res.dag.resize(res.groups.size());
    rep(i, 0, (int)res.groups.size())
        for (int v : res.groups[i]) res.id[v] = i;
    rep(v, 0, g.size())
        for (const auto& e : g[v])
            if (res.id[v] != res.id[e.to]) res.dag[res.id[v]].pb(res.id[e.to]);
    for (auto& edges : res.dag) {
        UNIQUE(edges);
    }
    return res;
}

struct GeneralMatching {
    int n;
    vvc<int> g;
    vi mate;
    explicit GeneralMatching(int n) : n(n), g(n), mate(n, -1) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        if (u == v) return;
        g[u].pb(v); g[v].pb(u);
    }
    int solve() {
        mate.assign(n, -1);
        vi parent(n), base(n), queue(n);
        vb used(n), blossom(n);
        auto lca = [&](int a, int b) {
            vb seen(n);
            while (true) {
                a = base[a]; seen[a] = true;
                if (mate[a] == -1) break;
                a = parent[mate[a]];
            }
            while (!seen[base[b]]) b = parent[mate[base[b]]];
            return base[b];
        };
        auto mark = [&](int v, int b, int child) {
            while (base[v] != b) {
                blossom[base[v]] = blossom[base[mate[v]]] = true;
                parent[v] = child;
                child = mate[v]; v = parent[mate[v]];
            }
        };
        auto augment = [&](int root) {
            std::iota(all(base), 0);
            fill(all(parent), -1);
            fill(all(used), false);
            int head = 0, tail = 0;
            queue[tail++] = root; used[root] = true;
            while (head < tail) {
                int v = queue[head++];
                for (int u : g[v]) {
                    if (base[v] == base[u] || mate[v] == u) continue;
                    if (u == root || (mate[u] != -1 && parent[mate[u]] != -1)) {
                        int b = lca(v, u);
                        fill(all(blossom), false);
                        mark(v, b, u); mark(u, b, v);
                        rep(i, 0, n) if (blossom[base[i]]) {
                            base[i] = b;
                            if (!used[i]) { used[i] = true; queue[tail++] = i; }
                        }
                    } else if (parent[u] == -1) {
                        parent[u] = v;
                        if (mate[u] == -1) {
                            while (u != -1) {
                                int p = parent[u], next = p == -1 ? -1 : mate[p];
                                mate[u] = p;
                                if (p != -1) mate[p] = u;
                                u = next;
                            }
                            return true;
                        }
                        int w = mate[u];
                        used[w] = true; queue[tail++] = w;
                    }
                }
            }
            return false;
        };
        int answer = 0;
        rep(v, 0, n) if (mate[v] == -1 && augment(v)) ++answer;
        return answer;
    }
};

template<class Cap = ll>
struct LowerBoundFlow {
    static_assert(std::is_same_v<Cap, int> || std::is_same_v<Cap, ll>);
    struct Edge { int from, to; Cap lower, upper; };
    struct Result { Cap flow; vc<Cap> edge_flow; };
    int n;
    vc<Edge> edges;
    explicit LowerBoundFlow(int n) : n(n) { assert(n >= 0); }
    int add_edge(int u, int v, Cap lower, Cap upper) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        assert(0 <= lower && lower <= upper);
        edges.pb({u, v, lower, upper});
        return (int)edges.size() - 1;
    }

    std::optional<Result> circulation() const { return solve(-1, -1); }

    std::optional<Result> max_flow(int s, int t) const {
        assert(0 <= s && s < n && 0 <= t && t < n && s != t);
        return solve(s, t);
    }
private:
    std::optional<Result> solve(int s, int t) const {
        i128 sum = 0;
        for (auto e : edges) sum += e.upper;
        assert(sum <= std::numeric_limits<Cap>::max());
        Cap limit = (Cap)sum;
        atcoder::mf_graph<Cap> network(n + 2);
        vc<Cap> balance(n);
        for (auto e : edges) {
            network.add_edge(e.from, e.to, e.upper - e.lower);
            balance[e.from] -= e.lower;
            balance[e.to] += e.lower;
        }
        int back = -1;
        if (s != -1) back = network.add_edge(t, s, limit);
        vi auxiliary;
        Cap demand = 0;
        rep(v, 0, n) {
            if (balance[v] > 0) {
                auxiliary.pb(network.add_edge(n, v, balance[v]));
                demand += balance[v];
            } else if (balance[v] < 0) {
                auxiliary.pb(network.add_edge(v, n + 1, -balance[v]));
            }
        }
        if (network.flow(n, n + 1, demand) != demand) return std::nullopt;
        Cap answer = 0;
        if (s != -1) {
            answer = network.get_edge(back).flow;
            network.change_edge(back, 0, 0);
            for (int id : auxiliary) network.change_edge(id, 0, 0);
            answer += network.flow(s, t, limit - answer);
        }
        Result result{answer, {}};
        rep(i, 0, (int)edges.size())
            result.edge_flow.pb(edges[i].lower + network.get_edge(i).flow);
        return result;
    }
};

template<class T>
std::optional<T> directed_mst_cost(const Graph<T>& graph, int root) {
    int n = graph.size();
    assert(0 <= root && root < n);
    vc<Edge<T>> edges;
    rep(v, 0, n)
        for (auto e : graph[v]) if (e.from != e.to) edges.pb(e);
    T answer = 0;
    while (true) {
        vc<T> incoming(n);
        vi parent(n, -1), id(n, -1), seen(n, -1);
        for (auto e : edges) if (e.from != e.to && e.to != root)
            if (parent[e.to] == -1 || e.cost < incoming[e.to]) {
                incoming[e.to] = e.cost; parent[e.to] = e.from;
            }
        rep(v, 0, n) {
            if (v != root && parent[v] == -1) return std::nullopt;
            answer += incoming[v];
        }
        int count = 0;
        rep(v, 0, n) {
            int u = v;
            while (u != root && id[u] == -1 && seen[u] != v) {
                seen[u] = v; u = parent[u];
            }
            if (u != root && id[u] == -1) {
                int w = u;
                do { id[w] = count; w = parent[w]; } while (w != u);
                ++count;
            }
        }
        if (count == 0) return answer;
        rep(v, 0, n) if (id[v] == -1) id[v] = count++;
        for (auto& e : edges) {
            T reduction = incoming[e.to];
            e.from = id[e.from]; e.to = id[e.to];
            if (e.from != e.to) e.cost -= reduction;
        }
        root = id[root]; n = count;
    }
}

inline ll steiner_tree_cost(const Graph<ll>& g, const vi& terminals,
                            ll inf = std::numeric_limits<ll>::max() / 4) {
    int n = g.size(), k = terminals.size();
    assert(0 < inf && k < 30);
    for (int v : terminals) assert(0 <= v && v < n);
    rep(v, 0, n)
        for (auto e : g[v]) assert(0 <= e.cost && e.cost < inf);
    if (k == 0) return 0;
    int count = 1 << k;
    vc<vl> dp(count, vl(n, inf));
    rep(i, 0, k) dp[1 << i][terminals[i]] = 0;
    rep(mask, 1, count) {
        for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
            int other = mask ^ sub;
            if (sub > other) continue;
            rep(v, 0, n)
                if (dp[sub][v] < inf - dp[other][v])
                    chmin(dp[mask][v], dp[sub][v] + dp[other][v]);
        }
        pq_min<pll> queue;
        rep(v, 0, n) if (dp[mask][v] < inf) queue.push({dp[mask][v], v});
        while (!queue.empty()) {
            auto [d, v] = queue.top(); queue.pop();
            if (d != dp[mask][v]) continue;
            for (auto e : g[v]) if (d < inf - e.cost && d + e.cost < dp[mask][e.to]) {
                dp[mask][e.to] = d + e.cost;
                queue.push({dp[mask][e.to], e.to});
            }
        }
    }
    return MIN(dp.back());
}

template<class T>
vi dominator_tree(const Graph<T>& g, int root) {
    int n = g.size();
    assert(0 <= root && root < n);
    vi order, number(n, -1), parent;
    vc<pii> stack;
    number[root] = 0; order.pb(root); parent.pb(0);
    stack.pb({root, 0});
    while (!stack.empty()) {
        auto& [v, next] = stack.back();
        if (next == (int)g[v].size()) { stack.pop_back(); continue; }
        int u = g[v][next++].to;
        if (number[u] != -1) continue;
        number[u] = order.size(); order.pb(u); parent.pb(number[v]);
        stack.pb({u, 0});
    }
    int count = order.size();
    vvc<int> pred(count), bucket(count);
    for (int v : order) for (auto e : g[v]) pred[number[e.to]].pb(number[v]);
    vi semi(count), label(count), ancestor(count), dom(count);
    std::iota(all(semi), 0);
    label = ancestor = semi;
    vi path;
    auto eval = [&](int v) {
        path.clear();
        int u = v;
        while (ancestor[ancestor[u]] != ancestor[u]) {
            path.pb(u); u = ancestor[u];
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            int w = *it, p = ancestor[w];
            if (semi[label[p]] < semi[label[w]]) label[w] = label[p];
            ancestor[w] = ancestor[p];
        }
        return label[v];
    };
    rrep(w, 1, count) {
        for (int v : pred[w]) chmin(semi[w], semi[eval(v)]);
        bucket[semi[w]].pb(w);
        ancestor[w] = parent[w];
        for (int v : bucket[parent[w]]) {
            int u = eval(v);
            dom[v] = semi[u] < semi[v] ? u : parent[w];
        }
        bucket[parent[w]].clear();
    }
    rep(w, 1, count) if (dom[w] != semi[w]) dom[w] = dom[dom[w]];
    vi result(n, -1);
    result[root] = root;
    rep(w, 1, count) result[order[w]] = order[dom[w]];
    return result;
}

struct EulerianTrail {
    struct Result { vi vertices, edge_ids; };
    int n;
    bool directed;
    vc<pii> edges;
    vvc<pii> g;
    vi in, out;
    explicit EulerianTrail(int n, bool directed = false)
        : n(n), directed(directed), g(n), in(n), out(n) {}
    int add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        int id = len(edges);
        edges.pb({u, v}); g[u].pb({v, id}); ++out[u]; ++in[v];
        if (!directed) { g[v].pb({u, id}); ++out[v]; ++in[u]; }
        return id;
    }

    optional<Result> trail(int start = -1) const {
        assert(start == -1 || (0 <= start && start < n));
        if (edges.empty()) return n == 0 ? Result{} : Result{{start == -1 ? 0 : start}, {}};
        int required = -1, positive = 0, negative = 0;
        rep(v, n) {
            if (directed) {
                int difference = out[v] - in[v];
                if (difference == 1) { required = v; ++positive; }
                else if (difference == -1) ++negative;
                else if (difference != 0) return nullopt;
            } else if (out[v] % 2) { if (required == -1) required = v; ++positive; }
        }
        if (directed ? !((positive == 0 && negative == 0) || (positive == 1 && negative == 1))
                     : !(positive == 0 || positive == 2)) return nullopt;
        if (start == -1) {
            start = required;
            if (start == -1) rep(v, n) if (out[v]) { start = v; break; }
        }
        if (directed && required != -1 && start != required) return nullopt;
        if (!directed && positive == 2 && out[start] % 2 == 0) return nullopt;
        if (!out[start]) return nullopt;
        vi next(n);
        vb used(len(edges));
        vc<pii> stack{{start, -1}};
        Result result;
        while (!stack.empty()) {
            int v = stack.back().fi;
            while (next[v] < len(g[v]) && used[g[v][next[v]].se]) ++next[v];
            if (next[v] == len(g[v])) {
                auto [vertex, edge] = stack.back(); stack.pop_back();
                result.vertices.pb(vertex);
                if (edge != -1) result.edge_ids.pb(edge);
            } else {
                auto [u, id] = g[v][next[v]++];
                used[id] = true; stack.pb({u, id});
            }
        }
        if (len(result.edge_ids) != len(edges)) return nullopt;
        reverse(all(result.vertices)); reverse(all(result.edge_ids));
        return result;
    }
};

template<class F>
void enumerate_triangles(int n, vc<pii> edges, F callback) {
    assert(n >= 0);
    for (auto& [u, v] : edges) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        if (u > v) swap(u, v);
    }
    UNIQUE(edges);
    vi degree(n);
    for (auto [u, v] : edges) if (u != v) { ++degree[u]; ++degree[v]; }
    vvc<int> out(n);
    for (auto [u, v] : edges) if (u != v) {
        if (pii(degree[u], u) > pii(degree[v], v)) swap(u, v);
        out[u].pb(v);
    }
    vi marked(n, -1);
    rep(u, n) {
        for (int v : out[u]) marked[v] = u;
        for (int v : out[u]) for (int w : out[v])
            if (marked[w] == u) callback((int)u, v, w);
    }
}

struct BiconnectedComponents {
    int n;
    vc<pii> edges;
    vvc<pii> g;
    vvc<int> blocks, block_edges, forest;
    vi articulation;
    explicit BiconnectedComponents(int n) : n(n), g(n) {}
    int add_edge(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v);
        int id = len(edges);
        edges.pb({u, v}); g[u].pb({v, id}); g[v].pb({u, id});
        return id;
    }
    void build() {
        blocks.clear(); block_edges.clear(); articulation.clear();
        vi order(n, -1), low(n), parent(n, -1), parent_edge(n, -1), next(n), children(n);
        vi edge_stack, marked(n, -1);
        vb is_art(n);
        int timer = 0;
        auto emit = [&](int last) {
            int block = len(blocks);
            vi vertices, ids;
            while (true) {
                int id = edge_stack.back(); edge_stack.pop_back(); ids.pb(id);
                auto [u, v] = edges[id];
                for (int w : {u, v}) if (marked[w] != block) {
                    marked[w] = block; vertices.pb(w);
                }
                if (id == last) break;
            }
            blocks.pb(move(vertices)); block_edges.pb(move(ids));
        };
        rep(root, n) if (order[root] == -1) {
            order[root] = low[root] = timer++;
            if (g[root].empty()) { blocks.pb({(int)root}); block_edges.pb({}); continue; }
            vi stack{(int)root};
            while (!stack.empty()) {
                int v = stack.back();
                if (next[v] < len(g[v])) {
                    auto [u, id] = g[v][next[v]++];
                    if (id == parent_edge[v]) continue;
                    if (order[u] == -1) {
                        parent[u] = v; parent_edge[u] = id; ++children[v];
                        edge_stack.pb(id); order[u] = low[u] = timer++; stack.pb(u);
                    } else if (order[u] < order[v]) {
                        edge_stack.pb(id); chmin(low[v], order[u]);
                    }
                } else {
                    stack.pop_back();
                    int p = parent[v];
                    if (p == -1) is_art[v] = children[v] > 1;
                    else {
                        chmin(low[p], low[v]);
                        if (low[v] >= order[p]) {
                            if (parent[p] != -1) is_art[p] = true;
                            emit(parent_edge[v]);
                        }
                    }
                }
            }
        }
        rep(v, n) if (is_art[v]) articulation.pb(v);

        forest.assign(n + len(blocks), {});
        rep(b, len(blocks)) for (int v : blocks[b]) {
            forest[v].pb(n + b); forest[n + b].pb(v);
        }
    }
};

inline vvc<int> complement_components(int n, const vc<pii>& edges) {
    assert(n >= 0);
    vvc<int> g(n), groups;
    for (auto [u, v] : edges) {
        assert(0 <= u && u < n && 0 <= v && v < n);
        if (u != v) { g[u].pb(v); g[v].pb(u); }
    }
    set<int> remaining;
    rep(v, n) remaining.insert(v);
    vi marked(n, -1);
    while (!remaining.empty()) {
        int start = *remaining.begin(); remaining.erase(remaining.begin());
        vi queue{start};
        rep(head, len(queue)) {
            int v = queue[head];
            for (int u : g[v]) marked[u] = v;
            for (auto it = remaining.begin(); it != remaining.end(); ) {
                if (marked[*it] == v) ++it;
                else { queue.pb(*it); it = remaining.erase(it); }
            }
        }
        groups.pb(move(queue));
    }
    return groups;
}

inline vi maximum_independent_set(int n,const vc<pii>& edges) {
    assert(0 <= n && n <= 46);
    vc<ull> adj(n);
    for (auto [u,v] : edges) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v);
        adj[u] |= 1ULL << v; adj[v] |= 1ULL << u;
    }
    int left=n/2,right=n-left;
    unsigned count=1U<<right;
    vc<unsigned> best(count);
    rep(mask,1,count) {
        int v=LOWBIT(mask); unsigned rest=(unsigned)mask ^ (1U<<v);
        unsigned take=best[rest & ~(unsigned)(adj[left+v]>>left)] | (1U<<v);
        best[mask]=POPCNT(take)>POPCNT(best[rest])?take:best[rest];
    }
    ull answer=best.back();
    auto search = [&](auto&& self,int v,ull selected,unsigned allowed)->void {
        if (v==left) {
            ull candidate=selected | ((ull)best[allowed]<<left);
            if (POPCNT(candidate)>POPCNT(answer)) answer=candidate;
            return;
        }
        self(self,v+1,selected,allowed);
        if (!(adj[v]&selected)) self(self,v+1,selected|(1ULL<<v),allowed & ~(unsigned)(adj[v]>>left));
    };

    answer <<= left;
    search(search,0,0,count-1);
    vi result; rep(v,n) if (answer>>v&1) result.pb(v);
    return result;
}

struct GlobalMinCutResult { i128 cost=0; vi side; };

inline GlobalMinCutResult global_min_cut(const vc<vl>& weights) {
    int n=len(weights); assert(n>=2);
    rep(i,n) { assert(len(weights[i])==n); }
    vvc<i128> a(n,vc<i128>(n));
    rep(i,n)rep(j,n) { assert(weights[i][j]>=0 && weights[i][j]==weights[j][i]); if(i!=j)a[i][j]=weights[i][j]; }
    vi active(n); iota(all(active),0);
    vvc<int> group(n);rep(i,n)group[i].pb(i);
    GlobalMinCutResult answer{(i128)1<<120,{}};
    while (len(active)>1) {
        vc<i128> weight(n);vb used(n);int previous=-1;
        rep(step,len(active)) {
            int selected=-1;
            for (int v:active) if (!used[v] && (selected==-1 || weight[v]>weight[selected])) selected=v;
            if (step+1==len(active)) {
                if (chmin(answer.cost,weight[selected])) answer.side=group[selected];
                for (int v:active) if(v!=selected && v!=previous) {
                    a[previous][v]+=a[selected][v];a[v][previous]=a[previous][v];
                }
                group[previous].insert(group[previous].end(),all(group[selected]));
                active.erase(find(all(active),selected));break;
            }
            used[selected]=true;previous=selected;
            for (int v:active) if(!used[v])weight[v]+=a[selected][v];
        }
    }
    return answer;
}

inline vl k_shortest_walks(const Graph<ll>& g,int s,int t,int k,ll inf=LLONG_MAX) {
    int n=g.size();assert(0<=s&&s<n&&0<=t&&t<n&&k>=0&&inf>0);
    rep(v,n)for(auto e:g[v])assert(0<=e.cost&&e.cost<inf);
    vl answer;if(k==0)return answer;
    vi popped(n);pq_min<pll> queue;queue.push({0,s});
    while(!queue.empty()){
        auto [d,v]=queue.top();queue.pop();if(popped[v]>=k)continue;++popped[v];
        if(v==t){answer.pb(d);if(len(answer)==k)break;}
        for(auto e:g[v])if(popped[e.to]<k && d<inf-e.cost)queue.push({d+e.cost,e.to});
    }
    return answer;
}

template<class T>
void subset_zeta(vc<T>& f) {
    int n = (int)f.size();
    for (int b = 1; b < n; b <<= 1)
        rep(mask, n) if (mask & b) f[mask] += f[mask ^ b];
}

template<class T>
void subset_mobius(vc<T>& f) {
    int n = (int)f.size();
    for (int b = 1; b < n; b <<= 1)
        rep(mask, n) if (mask & b) f[mask] -= f[mask ^ b];
}

template<class T>
void superset_zeta(vc<T>& f) {
    int n = (int)f.size();
    for (int b = 1; b < n; b <<= 1)
        rep(mask, n) if (!(mask & b)) f[mask] += f[mask ^ b];
}

template<class T>
void superset_mobius(vc<T>& f) {
    int n = (int)f.size();
    for (int b = 1; b < n; b <<= 1)
        rep(mask, n) if (!(mask & b)) f[mask] -= f[mask ^ b];
}

template<class T>
vc<T> or_convolution(vc<T> a, vc<T> b) {
    assert(a.size() == b.size());
    subset_zeta(a); subset_zeta(b);
    rep(i, len(a)) a[i] *= b[i];
    subset_mobius(a);
    return a;
}

template<class T>
vc<T> and_convolution(vc<T> a, vc<T> b) {
    assert(a.size() == b.size());
    superset_zeta(a); superset_zeta(b);
    rep(i, len(a)) a[i] *= b[i];
    superset_mobius(a);
    return a;
}

template<class T>
void xor_fwt(vc<T>& a, bool inverse = false) {
    int n = (int)a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) rep(j, len) {
            T x = a[i + j], y = a[i + j + len];
            a[i + j] = x + y;
            a[i + j + len] = x - y;
        }
    }
    if (inverse) for (auto &x : a) x /= n;
}

template<class T>
vc<T> xor_convolution(vc<T> a, vc<T> b) {
    assert(a.size() == b.size());
    xor_fwt(a); xor_fwt(b);
    rep(i, len(a)) a[i] *= b[i];
    xor_fwt(a, true);
    return a;
}

inline pll crt(ll r1,ll m1,ll r2,ll m2){ ll g=std::gcd(m1,m2); if((r2-r1)%g) return {0,0}; ll a=m1/g,b=m2/g; auto eg=[&](auto self,ll x,ll y)->pll{ if(!y) return {1,0}; auto [u,v]=self(self,y,x%y); return {v,u-(x/y)*v}; }; auto [x,y]=eg(eg,a,b); ll mod=a*m2; i128 k=(i128)(r2-r1)/g*x%b; ll r=(ll)(((i128)r1+(i128)m1*k)%mod); if(r<0) r+=mod; return {r,mod}; }
inline pll crt(const vl& r,const vl& m){ pll cur={0,1}; rep(i,len(r)){ cur=crt(cur.fi,cur.se,r[i],m[i]); if(cur.se==0) return cur; } return cur; }

template<class T> vc<T> divisors(T n){ vc<T> r; for(T i=1;i<=n/i;++i) if(n%i==0){ r.pb(i); if(i!=n/i) r.pb(n/i); } sort(all(r)); return r; }

struct Eratosthenes { int n; vi min_factor,primes; explicit Eratosthenes(int n):n(n),min_factor(n+1){ FOR3(i,2,n+1) if(!min_factor[i]){ min_factor[i]=i; primes.pb(i); if((ll)i*i<=n) for(ll j=(ll)i*i;j<=n;j+=i) if(!min_factor[j]) min_factor[j]=i; } } bool is_prime(int x) const { return x>=2 && min_factor[x]==x; } vc<pii> factorize(int x) const { vc<pii> r; while(x>1){ int p=min_factor[x],e=0; while(x%p==0) x/=p,++e; r.pb({p,e}); } return r; } };

template<class T> T extgcd(T a,T b,T& x,T& y){ if(b==0){ x=(a>=0?1:-1); y=0; return a>=0?a:-a; } T x1,y1,g=extgcd(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g; }

template<class Mint = mint>
struct FormalPowerSeries : vc<Mint> {
    using FPS = FormalPowerSeries;
    using Base = vc<Mint>;
    using Base::Base;

    FormalPowerSeries() = default;
    FormalPowerSeries(const vc<Mint>& v) : vc<Mint>(v) {}
    FormalPowerSeries(vc<Mint>&& v) : vc<Mint>(move(v)) {}

    void shrink() {
        while (!this->empty() && this->back() == Mint(0)) this->pop_back();
    }

    FPS pre(int n) const {
        n = min(n, (int)this->size());
        return FPS(this->begin(), this->begin() + n);
    }

    FPS rev(int n = -1) const {
        FPS r = *this;
        if (n != -1) r.resize(n);
        reverse(all(r));
        return r;
    }

    Mint eval(Mint x) const {
        Mint r = 0;
        rrep(i, (int)this->size()) r = r * x + (*this)[i];
        return r;
    }

    FPS& operator+=(const FPS& r) {
        if (this->size() < r.size()) this->resize(r.size());
        rep(i, (int)r.size()) (*this)[i] += r[i];
        return *this;
    }
    FPS& operator-=(const FPS& r) {
        if (this->size() < r.size()) this->resize(r.size());
        rep(i, (int)r.size()) (*this)[i] -= r[i];
        return *this;
    }
    FPS& operator+=(Mint x) {
        if (this->empty()) this->resize(1);
        (*this)[0] += x;
        return *this;
    }
    FPS& operator-=(Mint x) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= x;
        return *this;
    }
    FPS& operator*=(Mint x) {
        for (auto& a : *this) a *= x;
        return *this;
    }
    FPS& operator/=(Mint x) {
        return *this *= x.inv();
    }
    FPS& operator*=(const FPS& r) {
        vc<Mint> a(this->begin(), this->end());
        vc<Mint> b(r.begin(), r.end());
        *this = FPS(atcoder::convolution(a, b));
        return *this;
    }

    FPS operator-() const {
        FPS r = *this;
        for (auto& x : r) x = -x;
        return r;
    }

    friend FPS operator+(FPS l, const FPS& r) { return l += r; }
    friend FPS operator-(FPS l, const FPS& r) { return l -= r; }
    friend FPS operator*(FPS l, const FPS& r) { return l *= r; }
    friend FPS operator+(FPS l, Mint r) { return l += r; }
    friend FPS operator-(FPS l, Mint r) { return l -= r; }
    friend FPS operator*(FPS l, Mint r) { return l *= r; }
    friend FPS operator*(Mint l, FPS r) { return r *= l; }
    friend FPS operator/(FPS l, Mint r) { return l /= r; }

    FPS diff() const {
        if (this->size() <= 1) return {};
        FPS r(this->size() - 1);
        rep(i, 1, (int)this->size()) r[i - 1] = (*this)[i] * i;
        return r;
    }

    FPS integral() const {
        FPS r(this->size() + 1);
        static vc<Mint> invs{Mint(0), Mint(1)};
        int n = (int)this->size();
        assert(n < Mint::mod());
        if ((int)invs.size() <= n) {
            int old = invs.size();
            invs.resize(n + 1);
            rep(i, max(2, old), n + 1) {
                invs[i] = -invs[Mint::mod() % i] * (Mint::mod() / i);
            }
        }
        rep(i, n) r[i + 1] = (*this)[i] * invs[i + 1];
        return r;
    }

    FPS inv(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        assert(deg >= 0);
        if (deg == 0) return {};
        assert(!this->empty() && (*this)[0] != Mint(0));
        FPS g{(*this)[0].inv()};
        for (int m = 1; m < deg; m <<= 1) {
            int n = min(m << 1, deg);
            FPS f = this->pre(n);
            FPS t = (f * g).pre(n);
            t.resize(n);
            for (auto& x : t) x = -x;
            t[0] += Mint(2);
            g = (g * t).pre(n);
        }
        g.resize(deg);
        return g;
    }

    FPS log(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        assert(deg >= 0);
        if (deg == 0) return {};
        assert(!this->empty() && (*this)[0] == Mint(1));
        FPS r = (this->diff() * this->inv(deg)).pre(max(0, deg - 1)).integral();
        r.resize(deg);
        return r;
    }

    FPS exp(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        assert(deg >= 0);
        if (deg == 0) return {};
        assert(this->empty() || (*this)[0] == Mint(0));
        FPS g{Mint(1)};
        for (int m = 1; m < deg; m <<= 1) {
            int n = min(m << 1, deg);
            FPS q = this->pre(n);
            q.resize(n);
            FPS lg = g.log(n);
            q -= lg;
            q[0] += Mint(1);
            g = (g * q).pre(n);
        }
        g.resize(deg);
        return g;
    }

    FPS pow(ll k, int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        assert(k >= 0 && deg >= 0);
        FPS zero(deg, Mint(0));
        if (deg == 0) return {};
        if (k == 0) {
            zero[0] = 1;
            return zero;
        }
        int n = this->size();
        int p = 0;
        while (p < n && (*this)[p] == Mint(0)) ++p;
        if (p == n) return zero;
        if ((ll)p * k >= deg) return zero;

        Mint c = (*this)[p];
        int need = deg - (int)((ll)p * k);
        FPS f(this->begin() + p, this->end());
        f /= c;
        f.resize(need);
        FPS g = (f.log(need) * Mint(k)).exp(need);
        g *= c.pow(k);

        FPS r(deg, Mint(0));
        int sh = (int)((ll)p * k);
        rep(i, min(need, (int)g.size())) r[i + sh] = g[i];
        return r;
    }

private:
    static optional<Mint> sqrt_mod(Mint a) {
        ll p = Mint::mod();
        ll x = a.val();
        if (x == 0) return Mint(0);
        if (p == 2) return Mint(x);
        if (atcoder::pow_mod(x, (p - 1) / 2, p) != 1) return nullopt;
        if (p % 4 == 3) return Mint(atcoder::pow_mod(x, (p + 1) / 4, p));

        ll q = p - 1, s = 0;
        while ((q & 1) == 0) q >>= 1, ++s;
        ll z = 2;
        while (atcoder::pow_mod(z, (p - 1) / 2, p) != p - 1) ++z;

        ll c = atcoder::pow_mod(z, q, p);
        ll r = atcoder::pow_mod(x, (q + 1) / 2, p);
        ll t = atcoder::pow_mod(x, q, p);
        ll m = s;

        while (t != 1) {
            ll i = 1;
            ll tt = (__int128)t * t % p;
            while (tt != 1) {
                tt = (__int128)tt * tt % p;
                ++i;
                if (i == m) return nullopt;
            }
            ll b = atcoder::pow_mod(c, 1LL << (m - i - 1), p);
            r = (__int128)r * b % p;
            ll bb = (__int128)b * b % p;
            t = (__int128)t * bb % p;
            c = bb;
            m = i;
        }
        return Mint(r);
    }

public:

    optional<FPS> sqrt(int deg = -1) const {
        if (deg == -1) deg = (int)this->size();
        assert(deg >= 0);
        if (deg == 0) return FPS{};

        int n = this->size();
        int p = 0;
        while (p < min(n, deg) && (*this)[p] == Mint(0)) ++p;
        if (p == min(n, deg)) return FPS(deg, Mint(0));
        if (p & 1) return nullopt;

        int shift = p / 2;
        if (shift >= deg) return FPS(deg, Mint(0));
        int need = deg - shift;
        FPS f(this->begin() + p, this->end());
        f.resize(need);

        auto c0 = sqrt_mod(f[0]);
        if (!c0) return nullopt;
        FPS g{*c0};
        Mint inv2 = Mint(2).inv();
        for (int m = 1; m < need; m <<= 1) {
            int nn = min(m << 1, need);
            FPS q = (f.pre(nn) * g.inv(nn)).pre(nn);
            g.resize(nn);
            rep(i, nn) g[i] = (g[i] + q[i]) * inv2;
        }
        g.resize(need);

        FPS r(deg, Mint(0));
        rep(i, min(need, (int)g.size())) if (i + shift < deg) r[i + shift] = g[i];
        return r;
    }

    pair<FPS, FPS> divmod(FPS g) const {
        FPS f = *this;
        f.shrink(); g.shrink();
        assert(!g.empty());
        if (f.size() < g.size()) return {FPS{}, f};
        int n = f.size(), m = g.size();
        int qn = n - m + 1;
        FPS q = (f.rev().pre(qn) * g.rev().inv(qn)).pre(qn).rev();
        FPS r = f - q * g;
        if ((int)r.size() >= m) r.resize(m - 1);
        r.shrink(); q.shrink();
        return {q, r};
    }

    FPS& operator/=(const FPS& g) { return *this = divmod(g).fi; }
    FPS& operator%=(const FPS& g) { return *this = divmod(g).se; }
    friend FPS operator/(FPS f, const FPS& g) { return f /= g; }
    friend FPS operator%(FPS f, const FPS& g) { return f %= g; }

    FPS taylor_shift(Mint c) const {
        int n = this->size();
        if (n == 0) return {};
        assert(n < Mint::mod());
        vc<Mint> fact(n), ifact(n);
        fact[0] = 1;
        rep(i, 1, n) fact[i] = fact[i - 1] * i;
        ifact[n - 1] = fact[n - 1].inv();
        rrep(i, 1, n) ifact[i - 1] = ifact[i] * i;

        FPS a(n), b(n);
        rep(i, n) a[n - 1 - i] = (*this)[i] * fact[i];
        Mint pw = 1;
        rep(i, n) {
            b[i] = pw * ifact[i];
            pw *= c;
        }
        FPS d = a * b;
        FPS r(n);
        rep(i, n) r[i] = d[n - 1 - i] * ifact[i];
        return r;
    }
};

using FPS = FormalPowerSeries<mint>;

template<class Mint = mint>
Mint bostan_mori(FormalPowerSeries<Mint> p, FormalPowerSeries<Mint> q, ll n) {
    using Poly = FormalPowerSeries<Mint>;
    assert(n >= 0);
    p.shrink(); q.shrink();
    assert(!q.empty() && q[0] != Mint(0));
    Mint polynomial_part = 0;
    if (p.size() >= q.size()) {
        auto [d, r] = p.divmod(q);
        if (n < (ll)d.size()) polynomial_part = d[(int)n];
        p = move(r);
    }

    while (n > 0) {
        Poly qm = q;
        rep(i, 1, (int)qm.size(), 2) qm[i] = -qm[i];
        Poly s = p * qm;
        Poly t = q * qm;
        Poly np, nq;
        np.reserve((s.size() + 1) / 2);
        nq.reserve((t.size() + 1) / 2);
        for (int i = (n & 1); i < (int)s.size(); i += 2) np.pb(s[i]);
        for (int i = 0; i < (int)t.size(); i += 2) nq.pb(t[i]);
        p = move(np);
        q = move(nq);
        n >>= 1;
    }
    return polynomial_part + (p.empty() ? Mint(0) : p[0]) / q[0];
}

template<class Mint = mint>
vc<Mint> berlekamp_massey(const vc<Mint>& s) {
    vc<Mint> C{Mint(1)}, B{Mint(1)};
    int L = 0, m = 1;
    Mint b = 1;

    rep(n, (int)s.size()) {
        Mint d = s[n];
        rep(i, 1, L + 1) d += C[i] * s[n - i];
        if (d == Mint(0)) {
            ++m;
            continue;
        }
        vc<Mint> T = C;
        Mint coef = d / b;
        if ((int)C.size() < (int)B.size() + m) C.resize(B.size() + m);
        rep(i, (int)B.size()) C[i + m] -= coef * B[i];
        if (2 * L <= n) {
            L = n + 1 - L;
            B = move(T);
            b = d;
            m = 1;
        } else {
            ++m;
        }
    }
    C.resize(L + 1);
    C.erase(C.begin());
    for (auto& x : C) x = -x;
    return C;
}

template<class Mint = mint>
Mint linear_recurrence_kth(const vc<Mint>& init, const vc<Mint>& c, ll n) {
    using Poly = FormalPowerSeries<Mint>;
    int k = c.size();
    assert(k > 0 && (int)init.size() >= k && n >= 0);
    if (n < (ll)init.size()) return init[n];

    Poly q(k + 1);
    q[0] = 1;
    rep(i, k) q[i + 1] = -c[i];

    Poly a(init.begin(), init.begin() + k);
    Poly p = (a * q).pre(k);
    return bostan_mori<Mint>(p, q, n);
}

template<class Mint = mint>
Mint kitamasa(const vc<Mint>& init, const vc<Mint>& c, ll n) {
    int k = c.size();
    assert(k > 0 && (int)init.size() >= k && n >= 0);
    if (n < k) return init[n];

    auto combine = [&](const vc<Mint>& a, const vc<Mint>& b) {
        vc<Mint> t(2 * k - 1);
        rep(i, k) rep(j, k) t[i + j] += a[i] * b[j];
        rrep(d, k, 2 * k - 1) {
            Mint v = t[d];
            if (v == Mint(0)) continue;
            rep(j, 1, k + 1) t[d - j] += v * c[j - 1];
        }
        t.resize(k);
        return t;
    };

    vc<Mint> res(k), x(k);
    res[0] = 1;
    if (k == 1) x[0] = c[0];
    else x[1] = 1;

    while (n) {
        if (n & 1) res = combine(res, x);
        x = combine(x, x);
        n >>= 1;
    }
    Mint ans = 0;
    rep(i, k) ans += res[i] * init[i];
    return ans;
}

template<class Mint = mint>
Mint guess_linear_recurrence_kth(const vc<Mint>& s, ll n) {
    assert(!s.empty() && n >= 0);
    if (n < (ll)s.size()) return s[n];
    vc<Mint> c = berlekamp_massey<Mint>(s);
    assert(!c.empty());
    vc<Mint> init(c.size());
    rep(i, (int)c.size()) init[i] = s[i];
    return linear_recurrence_kth<Mint>(init, c, n);
}

template<class T>
struct Matrix {
    int h = 0, w = 0;
    vvc<T> a;

    Matrix() {}
    Matrix(int h, int w, T val = T{}) : h(h), w(w), a(h, vc<T>(w, val)) {}
    Matrix(const vvc<T>& a) : h(a.size()), w(a.empty() ? 0 : a[0].size()), a(a) {}

    vc<T>& operator[](int i) { return a[i]; }
    const vc<T>& operator[](int i) const { return a[i]; }

    static Matrix identity(int n) {
        Matrix I(n, n);
        rep(i, n) I[i][i] = T(1);
        return I;
    }

    Matrix& operator+=(const Matrix& o) {
        assert(h == o.h && w == o.w);
        rep(i, h) rep(j, w) a[i][j] += o[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& o) {
        assert(h == o.h && w == o.w);
        rep(i, h) rep(j, w) a[i][j] -= o[i][j];
        return *this;
    }
    Matrix& operator*=(const Matrix& o) { return *this = (*this) * o; }

    friend Matrix operator+(Matrix x, const Matrix& y) { return x += y; }
    friend Matrix operator-(Matrix x, const Matrix& y) { return x -= y; }

    friend Matrix operator*(const Matrix& x, const Matrix& y) {
        assert(x.w == y.h);
        Matrix z(x.h, y.w);
        rep(i, x.h) rep(k, x.w) if (x[i][k] != T{}) rep(j, y.w) {
            z[i][j] += x[i][k] * y[k][j];
        }
        return z;
    }

    Matrix pow(ll e) const {
        assert(h == w && e >= 0);
        Matrix x = *this, r = identity(h);
        while (e) {
            if (e & 1) r *= x;
            x *= x;
            e >>= 1;
        }
        return r;
    }

    vc<T> operator*(const vc<T>& v) const {
        assert(w == (int)v.size());
        vc<T> res(h, T{});
        rep(i, h) rep(j, w) res[i] += a[i][j] * v[j];
        return res;
    }
};

inline ull mod_mul_u64(ull a,ull b,ull mod){ return (u128)a*b%mod; }
inline ull mod_pow_u64(ull a,ull n,ull mod){ ull r=1; while(n){ if(n&1) r=mod_mul_u64(r,a,mod); a=mod_mul_u64(a,a,mod); n>>=1; } return r; }
inline bool is_prime_u64(ull n){ if(n<2) return false; for(ull p:{2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}){ if(n%p==0) return n==p; } ull d=n-1,s=0; while(!(d&1)) d>>=1,++s; for(ull a:{2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}){ if(a%n==0) continue; ull x=mod_pow_u64(a%n,d,n); if(x==1||x==n-1) continue; bool comp=true; FOR1(s-1){ x=mod_mul_u64(x,x,n); if(x==n-1){ comp=false; break; } } if(comp) return false; } return true; }

namespace factor64 {
    using u64 = ull;
    using u128_ = u128;

    u64 mod_mul(u64 a, u64 b, u64 mod) {
        return (u128_)a * b % mod;
    }

    u64 mod_pow(u64 a, u64 e, u64 mod) {
        u64 r = 1;
        while (e) {
            if (e & 1) r = mod_mul(r, a, mod);
            a = mod_mul(a, a, mod);
            e >>= 1;
        }
        return r;
    }

    bool is_prime(u64 n) {
        if (n < 2) return false;
        for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
            if (n % p == 0) return n == p;
        }
        u64 d = n - 1, s = 0;
        while ((d & 1) == 0) d >>= 1, ++s;

        for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
            if (a % n == 0) continue;
            u64 x = mod_pow(a % n, d, n);
            if (x == 1 || x == n - 1) continue;
            bool comp = true;
            rep(r, s - 1) {
                x = mod_mul(x, x, n);
                if (x == n - 1) { comp = false; break; }
            }
            if (comp) return false;
        }
        return true;
    }

    u64 pollard(u64 n) {
        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        while (true) {
            u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
            u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
            u64 y = x, d = 1;
            auto f = [&](u64 v) { return (u64)(((u128_)mod_mul(v, v, n) + c) % n); };
            while (d == 1) {
                x = f(x);
                y = f(f(y));
                u64 diff = x > y ? x - y : y - x;
                d = std::gcd(diff, n);
            }
            if (d != n) return d;
        }
    }

    void factor_rec(u64 n, vc<u64>& out) {
        if (n == 1) return;
        if (is_prime(n)) {
            out.pb(n);
            return;
        }
        u64 d = pollard(n);
        factor_rec(d, out);
        factor_rec(n / d, out);
    }

    vc<u64> factorize(u64 n) {
        vc<u64> f;
        factor_rec(n, f);
        sort(all(f));
        return f;
    }

    map<u64,int> factor_count(u64 n) {
        map<u64,int> mp;
        for (u64 p : factorize(n)) ++mp[p];
        return mp;
    }
}

template<class Mint = mint>
struct PolynomialProductTree {
    using Poly = FormalPowerSeries<Mint>;
    int n = 0, sz = 1;
    vc<Mint> xs;
    vc<Poly> prod;

    PolynomialProductTree() {}
    PolynomialProductTree(const vc<Mint>& xs) { build(xs); }

    void build(const vc<Mint>& p) {
        xs = p;
        n = xs.size();
        sz = 1;
        while (sz < n) sz <<= 1;
        prod.assign(sz << 1, Poly{Mint(1)});
        rep(i, n) prod[sz + i] = Poly{-xs[i], Mint(1)};
        rrep(i, 1, sz) prod[i] = prod[i << 1] * prod[i << 1 | 1];
    }

    vc<Mint> evaluate(const Poly& f) const {
        vc<Mint> ans(n);
        if (n == 0) return ans;
        vc<Poly> rem(sz << 1);
        rem[1] = f % prod[1];
        for (int v = 1; v < sz; ++v) {
            rem[v << 1] = rem[v] % prod[v << 1];
            rem[v << 1 | 1] = rem[v] % prod[v << 1 | 1];
        }
        rep(i, n) ans[i] = rem[sz + i].empty() ? Mint(0) : rem[sz + i][0];
        return ans;
    }

    Poly interpolate(const vc<Mint>& ys) const {
        assert((int)ys.size() == n);
        if (n == 0) return {};
        Poly der = prod[1].diff();
        vc<Mint> den = evaluate(der);
        vc<Poly> val(sz << 1);
        rep(i, n) {
            assert(den[i] != Mint(0));
            val[sz + i] = Poly{ys[i] / den[i]};
        }
        rep(i, n, sz) val[sz + i] = Poly{Mint(0)};
        rrep(v, 1, sz) {
            val[v] = val[v << 1] * prod[v << 1 | 1]
                   + val[v << 1 | 1] * prod[v << 1];
        }
        val[1].resize(n);
        return val[1];
    }
};

template<class Mint = mint>
vc<Mint> multipoint_evaluation(const FormalPowerSeries<Mint>& f, const vc<Mint>& xs) {
    return PolynomialProductTree<Mint>(xs).evaluate(f);
}

template<class Mint = mint>
FormalPowerSeries<Mint> polynomial_interpolation(const vc<Mint>& xs, const vc<Mint>& ys) {
    return PolynomialProductTree<Mint>(xs).interpolate(ys);
}

template<class Mint = mint>
struct Combination {
    vc<Mint> fact{Mint(1)}, inv_fact{Mint(1)};

    explicit Combination(int n = 0) { extend(n); }

    void extend(int n) {
        assert(0 <= n && n < Mint::mod());
        int old = (int)fact.size();
        if (n < old) return;
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        rep(i, old, (n) + 1) fact[i] = fact[i - 1] * i;
        inv_fact[n] = fact[n].inv();
        rrep(i, old, n + 1) inv_fact[i - 1] = inv_fact[i] * i;
    }

    Mint C(int n, int r) {
        if (n < 0 || r < 0 || r > n) return Mint(0);
        extend(n);
        return fact[n] * inv_fact[r] * inv_fact[n - r];
    }
    Mint P(int n, int r) {
        if (n < 0 || r < 0 || r > n) return Mint(0);
        extend(n);
        return fact[n] * inv_fact[n - r];
    }

    Mint H(int n, int r) {
        if (n < 0 || r < 0) return Mint(0);
        if (r == 0) return Mint(1);
        if (n == 0) return Mint(0);
        assert((ll)n + r - 1 < Mint::mod());
        return C(n + r - 1, r);
    }

    Mint nCr(int n, int r) { return C(n, r); }
    Mint nPr(int n, int r) { return P(n, r); }
    Mint nHr(int n, int r) { return H(n, r); }
};

template<class Mint>
Mint k_subset_containing_count(int N, int K, int r, Combination<Mint>& comb) {
    if (r < 0 || r > K || K > N) return 0;
    return comb.nCr(N - r, K - r);
}

template<class T, class Mint>
Mint sum_all_k_subset_sum(const vc<T>& a, int K, Combination<Mint>& comb) {
    int N = (int)a.size();
    if (K <= 0 || K > N) return 0;
    Mint sum = 0;
    for (const auto& v : a) sum += v;
    return comb.nCr(N - 1, K - 1) * sum;
}

template<class T, class Mint>
Mint sum_all_k_subset_pair_product(const vc<T>& a, int K, Combination<Mint>& comb) {
    int N = (int)a.size();
    if (K < 2 || K > N) return 0;
    Mint sum = 0, sq = 0;
    for (const auto& v : a) {
        Mint x = v;
        sum += x;
        sq += x * x;
    }
    return comb.nCr(N - 2, K - 2) * (sum * sum - sq) / 2;
}

template<class T, class Mint>
Mint sum_all_k_subset_square_sum(const vc<T>& a, int K, Combination<Mint>& comb) {
    int N = (int)a.size();
    if (K <= 0 || K > N) return 0;
    Mint sum = 0, sq = 0;
    for (const auto& v : a) {
        Mint x = v;
        sum += x;
        sq += x * x;
    }
    Mint ans = comb.nCr(N - 1, K - 1) * sq;
    if (K >= 2) ans += comb.nCr(N - 2, K - 2) * (sum * sum - sq);
    return ans;
}

template<int B = 63>
struct XorBasis {
    ull basis[B]{};
    int rk = 0;

    bool insert(ull x) {
        for (int b = B - 1; b >= 0; --b) if ((x >> b) & 1ULL) {
            if (!basis[b]) {
                basis[b] = x;
                ++rk;
                return true;
            }
            x ^= basis[b];
        }
        return false;
    }

    bool contains(ull x) const {
        for (int b = B - 1; b >= 0; --b) if ((x >> b) & 1ULL) {
            if (!basis[b]) return false;
            x ^= basis[b];
        }
        return true;
    }

    ull max_xor(ull x = 0) const {
        for (int b = B - 1; b >= 0; --b) chmax(x, x ^ basis[b]);
        return x;
    }

    ull min_xor(ull x = 0) const {
        for (int b = B - 1; b >= 0; --b) chmin(x, x ^ basis[b]);
        return x;
    }

    int rank() const { return rk; }

    vc<ull> reduced_vectors() const {
        ull b[B];
        rep(i, B) b[i] = basis[i];
        rep(i, B) if (b[i]) {
            rep(j, i) if ((b[i] >> j) & 1ULL) b[i] ^= b[j];
        }
        vc<ull> v;
        rep(i, B) if (b[i]) v.pb(b[i]);
        return v;
    }

    ull kth_smallest(ull k) const {
        auto v = reduced_vectors();
        assert(v.size() < 64 && k < (1ULL << v.size()));
        ull x = 0;
        rep(i, v.size()) if ((k >> i) & 1ULL) x ^= v[i];
        return x;
    }
};

template<class T>
vc<T> subset_convolution(const vc<T>& a, const vc<T>& b) {
    assert(a.size() == b.size() && !a.empty());
    size_t size = a.size();
    assert((size & (size - 1)) == 0 && size <= (size_t)INT_MAX);
    int count = (int)size, k = LOWBIT(count);
    vvc<T> f(k + 1, vc<T>(count, T(0))), g = f;
    rep(s, 0, count) {
        int rank = POPCNT(s);
        f[rank][s] = a[s]; g[rank][s] = b[s];
    }
    for (int bit = 1; bit < count; bit <<= 1)
        rep(s, 0, count) if (s & bit)
            rep(r, 0, (k) + 1) {
                f[r][s] += f[r][s ^ bit]; g[r][s] += g[r][s ^ bit];
            }
    vc<T> result(count, T(0)), h(count);
    rep(r, 0, (k) + 1) {
        fill(all(h), T(0));
        rep(s, 0, count)
            rep(j, 0, (r) + 1) h[s] += f[j][s] * g[r - j][s];
        for (int bit = 1; bit < count; bit <<= 1)
            rep(s, 0, count) if (s & bit) h[s] -= h[s ^ bit];
        rep(s, 0, count) if (POPCNT(s) == r) result[s] = h[s];
    }
    return result;
}

inline std::optional<ll> discrete_log(ll a, ll b, ll m) {
    assert(m >= 1);
    if (m == 1) return 0;
    a %= m; if (a < 0) a += m;
    b %= m; if (b < 0) b += m;
    auto mul = [](ll x, ll y, ll mod) { return (ll)((i128)x * y % mod); };
    auto power = [&](ll x, ll exponent, ll mod) {
        ll r = 1 % mod;
        while (exponent) {
            if (exponent & 1) r = mul(r, x, mod);
            x = mul(x, x, mod); exponent >>= 1;
        }
        return r;
    };
    ll prefix = 0, product = 1;
    while (true) {
        if (b == product) return prefix;
        ll divisor = std::gcd(a, m);
        if (divisor == 1) break;
        if (b % divisor) return std::nullopt;
        b /= divisor; m /= divisor;
        product = mul(product, a / divisor, m);
        ++prefix;
    }
    b = mul(b, atcoder::inv_mod(product, m), m);
    a %= m;
    ll width = (ll)std::sqrt((long double)m);
    while ((i128)width * width < m) ++width;
    while (width > 1 && (i128)(width - 1) * (width - 1) >= m) --width;
    std::map<ll, ll> baby;
    ll value = 1;
    for (ll j = 0; j < width; ++j) {
        baby.emplace(value, j);
        value = mul(value, a, m);
    }
    ll step = atcoder::inv_mod(power(a, width, m), m);
    value = b;
    for (ll i = 0; i <= width; ++i) {
        auto it = baby.find(value);
        if (it != baby.end()) {
            i128 exponent = (i128)i * width + it->second + prefix;
            assert(exponent <= std::numeric_limits<ll>::max());
            return (ll)exponent;
        }
        value = mul(value, step, m);
    }
    return std::nullopt;
}

template<class Field>
Field determinant(vvc<Field> a) {
    int n = a.size();
    for (const auto& row : a) assert((int)row.size() == n);
    Field result = 1;
    rep(col, 0, n) {
        int pivot = col;
        while (pivot < n && a[pivot][col] == Field(0)) ++pivot;
        if (pivot == n) return Field(0);
        if (pivot != col) { std::swap(a[pivot], a[col]); result = -result; }
        Field value = a[col][col];
        result *= value;
        Field inverse = Field(1) / value;
        rep(row, col + 1, n) {
            Field factor = a[row][col] * inverse;
            rep(j, col + 1, n) a[row][j] -= factor * a[col][j];
        }
    }
    return result;
}

template<class Field, class T>
Field spanning_tree_sum(const Graph<T>& g, int root = 0) {
    int n = g.size();
    assert(0 <= root && root < n);
    vvc<Field> minor(n - 1, vc<Field>(n - 1, Field(0)));
    auto index = [&](int v) { return v < root ? v : v - 1; };
    rep(u, 0, n) for (auto e : g[u]) {
        if (u == e.to || e.to == root) continue;
        int row = index(e.to);
        minor[row][row] += Field(e.cost);
        if (u != root) minor[row][index(u)] -= Field(e.cost);
    }
    return determinant(std::move(minor));
}

inline optional<ll> mod_sqrt(ll a, ll p) {
    assert(p >= 2 && is_prime_u64(p));
    a %= p;
    if (a < 0) a += p;
    if (a == 0 || p == 2) return a;
    if (mod_pow_u64(a, (p - 1) / 2, p) != 1) return nullopt;
    ull x;
    if (p % 4 == 3) x = mod_pow_u64(a, p / 4 + 1, p);
    else {
        ull q = p - 1;
        int s = LOWBIT(q);
        q >>= s;
        ull z = 2;
        while (mod_pow_u64(z, (p - 1) / 2, p) == 1) ++z;
        ull c = mod_pow_u64(z, q, p);
        x = mod_pow_u64(a, (q + 1) / 2, p);
        ull t = mod_pow_u64(a, q, p);
        while (t != 1) {
            int i = 0;
            ull v = t;
            while (v != 1) { v = mod_mul_u64(v, v, p); ++i; }
            ull b = c;
            rep(j, s - i - 1) b = mod_mul_u64(b, b, p);
            x = mod_mul_u64(x, b, p);
            c = mod_mul_u64(b, b, p);
            t = mod_mul_u64(t, c, p);
            s = i;
        }
    }
    return min((ll)x, p - (ll)x);
}

namespace tetration_detail {

inline ll capped(ll a, ull h, ll limit) {
    if (limit == 0) return 0;
    if (h == 0) return min(1LL, limit);
    if (a == 0) return h % 2 == 0 ? min(1LL, limit) : 0;
    if (a == 1 || limit == 1) return 1;
    ll exponent = 0, value = 1;
    while (value < limit) {
        value = (ll)min((i128)limit, (i128)value * a);
        ++exponent;
    }
    ll e = capped(a, h - 1, exponent);
    if (e == exponent) return limit;
    value = 1;
    rep(i, e) value = (ll)min((i128)limit, (i128)value * a);
    return value;
}
}

inline ll tetration_mod(ll a, ull h, ll m) {
    assert(a >= 0 && m >= 1);
    if (m == 1) return 0;
    if (h == 0) return 1;
    if (a == 0) return h % 2 == 0 ? 1 : 0;
    if (a == 1) return 1;
    ll phi = m;
    for (auto [p, exponent] : factor64::factor_count(m)) phi = phi / p * (p - 1);
    ull exponent = tetration_mod(a, h - 1, phi);
    if (tetration_detail::capped(a, h - 1, phi) == phi) exponent += (ull)phi;
    return (ll)mod_pow_u64(a % m, exponent, m);
}

inline ll prime_count(ll n) {
    assert(n >= 0);
    if (n < 2) return 0;
    ll root = (ll)sqrt((long double)n);
    while ((i128)(root + 1) * (root + 1) <= n) ++root;
    while ((i128)root * root > n) --root;
    vl values, count;
    for (auto [l, r, q] : quotient_ranges(n)) { values.pb(q); count.pb(q - 1); }
    auto index = [&](ll x) -> ll { return x <= root ? len(values) - x : n / x - 1; };
    rep(p, 2, root + 1) {
        ll before = count[index(p - 1)];
        if (count[index(p)] == before) continue;
        rep(i, len(values)) {
            ll v = values[i];
            if ((i128)p * p > v) break;
            count[i] -= count[index(v / p)] - before;
        }
    }
    return count[0];
}

struct ArithmeticSieve {
    vi primes, min_factor, phi, mu;
    explicit ArithmeticSieve(int n) : min_factor(n + 1), phi(n + 1), mu(n + 1) {
        assert(n >= 0);
        if (n >= 1) phi[1] = mu[1] = 1;
        rep(v, 2, n + 1LL) {
            if (min_factor[v] == 0) {
                min_factor[v] = v; primes.pb(v); phi[v] = v - 1; mu[v] = -1;
            }
            for (int p : primes) {
                ll next = v * p;
                if (next > n) break;
                min_factor[next] = p;
                if (v % p == 0) { phi[next] = phi[v] * p; break; }
                phi[next] = phi[v] * (p - 1); mu[next] = -mu[v];
            }
        }
    }
};

template<class T>
vc<T> divisor_zeta(const vc<T>& a) {
    assert(!a.empty() && a[0] == T(0));
    vc<T> result(a.size(), T(0));
    rep(d, 1, len(a)) for (ll m = d; m < len(a); m += d) result[m] += a[d];
    return result;
}
template<class T>
vc<T> divisor_mobius(vc<T> a) {
    assert(!a.empty() && a[0] == T(0));
    rep(d, 1, len(a)) for (ll m = 2 * d; m < len(a); m += d) a[m] -= a[d];
    return a;
}
template<class T>
vc<T> multiple_zeta(const vc<T>& a) {
    assert(!a.empty() && a[0] == T(0));
    vc<T> result(a.size(), T(0));
    rep(d, 1, len(a)) for (ll m = d; m < len(a); m += d) result[d] += a[m];
    return result;
}
template<class T>
vc<T> multiple_mobius(vc<T> a) {
    assert(!a.empty() && a[0] == T(0));
    rrep(d, 1, len(a)) for (ll m = 2 * d; m < len(a); m += d) a[d] -= a[m];
    return a;
}

template<class T>
vc<T> gcd_convolution(const vc<T>& a, const vc<T>& b) {
    assert(a.size() == b.size());
    auto x = multiple_zeta(a), y = multiple_zeta(b);
    rep(i, len(x)) x[i] *= y[i];
    return multiple_mobius(move(x));
}

template<class T>
vc<T> lcm_convolution(const vc<T>& a, const vc<T>& b) {
    assert(a.size() == b.size());
    auto x = divisor_zeta(a), y = divisor_zeta(b);
    rep(i, len(x)) x[i] *= y[i];
    return divisor_mobius(move(x));
}

inline ull integer_kth_root(ull n, int k) {
    assert(k >= 1);
    if (n <= 1 || k == 1) return n;
    if (k >= 64) return 1;
    auto fits = [&](ull base) {
        ull value = 1;
        rep(i, k) {
            if (base && value > n / base) return false;
            value *= base;
        }
        return true;
    };
    ull low = 0, high = min(n, 1ULL << ((64 + k - 1) / k));
    while (low < high) {
        ull mid = low + (high - low) / 2 + (high - low) % 2;
        if (fits(mid)) low = mid;
        else high = mid - 1;
    }
    return low;
}

template<class Field>
struct LinearSystemResult {
    int rank;
    vc<Field> particular;
    vvc<Field> nullspace;
};

template<class Field>
optional<LinearSystemResult<Field>> solve_linear_system(vvc<Field> a,vc<Field> b,int variables=-1) {
    int h=len(a),w=variables;
    if(w==-1)w=h?len(a[0]):0;
    assert(w>=0 && len(b)==h);
    rep(i,h){assert(len(a[i])==w);a[i].pb(b[i]);}
    vi pivot;int rank=0;
    rep(col,w){
        int row=rank;while(row<h && a[row][col]==Field(0))++row;
        if(row==h)continue;
        swap(a[row],a[rank]);Field inverse=Field(1)/a[rank][col];
        rep(j,col,w+1)a[rank][j]*=inverse;
        rep(i,h)if(i!=rank){Field factor=a[i][col];rep(j,col,w+1)a[i][j]-=factor*a[rank][j];}
        pivot.pb(col);++rank;
    }
    rep(i,rank,h)if(a[i][w]!=Field(0))return nullopt;
    LinearSystemResult<Field> result{rank,vc<Field>(w,Field(0)),{}};
    vb is_pivot(w);rep(i,rank){is_pivot[pivot[i]]=true;result.particular[pivot[i]]=a[i][w];}
    rep(free,w)if(!is_pivot[free]){
        vc<Field> basis(w,Field(0));basis[free]=1;
        rep(i,rank) basis[pivot[i]]=-a[i][free];
        result.nullspace.pb(move(basis));
    }
    return result;
}

inline ull primitive_root_prime(ull p) {
    assert(is_prime_u64(p));
    if(p==2)return 1;
    auto factors=factor64::factor_count(p-1);
    for(ull g=2;g<p;++g){
        bool ok=true;
        for(auto [q,exponent]:factors)if(mod_pow_u64(g,(p-1)/q,p)==1){ok=false;break;}
        if(ok)return g;
    }
    assert(false);return 0;
}

template<class Mint>
Mint lagrange_consecutive(const vc<Mint>& y,Mint x) {
    int n=len(y);assert(n<=Mint::mod());
    if(n==0)return Mint(0);
    if(x.val()<n)return y[x.val()];
    Combination<Mint> comb(n-1);
    vc<Mint> prefix(n+1,Mint(1)),suffix(n+1,Mint(1));
    rep(i,n)prefix[i+1]=prefix[i]*(x-Mint(i));
    rrep(i,n)suffix[i]=suffix[i+1]*(x-Mint(i));
    Mint result=0;
    rep(i,n){Mint term=y[i]*prefix[i]*suffix[i+1]*comb.inv_fact[i]*comb.inv_fact[n-1-i];
        if((n-1-i)&1)result-=term;else result+=term;}
    return result;
}

struct SummatoryArithmetic {
private:
    vc<i128> phi_prefix;
    vl mu_prefix;
    map<ll,i128> phi_memo;
    map<ll,ll> mu_memo;
public:
    explicit SummatoryArithmetic(int cutoff=1000000):phi_prefix(cutoff+1),mu_prefix(cutoff+1){
        assert(cutoff>=1);ArithmeticSieve sieve(cutoff);
        rep(i,1,cutoff+1){phi_prefix[i]=phi_prefix[i-1]+sieve.phi[i];mu_prefix[i]=mu_prefix[i-1]+sieve.mu[i];}
    }
    i128 phi_sum(ll n){
        assert(n>=0);if(n<len(phi_prefix))return phi_prefix[n];
        auto it=phi_memo.find(n);if(it!=phi_memo.end())return it->second;
        i128 result=(i128)n*((i128)n+1)/2;
        for(ll l=2;l<=n;){ll q=n/l,r=n/q;result-=(i128)(r-l+1)*phi_sum(q);if(r==n)break;l=r+1;}
        return phi_memo[n]=result;
    }
    ll mu_sum(ll n){
        assert(n>=0);if(n<len(mu_prefix))return mu_prefix[n];
        auto it=mu_memo.find(n);if(it!=mu_memo.end())return it->second;
        i128 result=1;
        for(ll l=2;l<=n;){ll q=n/l,r=n/q;result-=(i128)(r-l+1)*mu_sum(q);if(r==n)break;l=r+1;}
        assert(LLONG_MIN<=result&&result<=LLONG_MAX);return mu_memo[n]=(ll)result;
    }
};

struct LineContainer {
    struct Line {
        mutable ll k, m, p;
        bool operator<(const Line& o) const { return k < o.k; }
        bool operator<(ll x) const { return p < x; }
    };

    multiset<Line, less<>> st;
    static constexpr ll INF_X = LLONG_MAX;

    static ll div_floor(ll a, ll b) {
        ll q = a / b, r = a % b;
        if (r && ((r > 0) != (b > 0))) --q;
        return q;
    }

    bool isect(multiset<Line, less<>>::iterator x, multiset<Line, less<>>::iterator y) {
        if (y == st.end()) { x->p = INF_X; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? INF_X : -INF_X;
        else x->p = div_floor(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }

    void add_max(ll k, ll m) {
        auto z = st.insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = st.erase(z);
        if (x != st.begin() && isect(--x, y)) isect(x, y = st.erase(y));
        while ((y = x) != st.begin() && (--x)->p >= y->p) isect(x, st.erase(y));
    }

    ll query_max(ll x) const {
        assert(!st.empty());
        auto l = *st.lower_bound(x);
        return l.k * x + l.m;
    }
};

template<bool MIN_QUERY = true>
struct CHT {
    LineContainer lc;
    void add(ll a, ll b) {
        if constexpr (MIN_QUERY) lc.add_max(-a, -b);
        else lc.add_max(a, b);
    }
    ll query(ll x) const {
        ll v = lc.query_max(x);
        if constexpr (MIN_QUERY) return -v;
        else return v;
    }
};

struct LiChaoTree {
    struct Line {
        ll a = 0, b = (ll)4e18;
        Line() {}
        Line(ll a, ll b) : a(a), b(b) {}
        i128 eval(ll x) const { return (i128)a * x + b; }
    };

    vl xs;
    vc<Line> seg;
    vc<char> has;
    int n;

    LiChaoTree() {}
    LiChaoTree(vl x) { init(move(x)); }

    void init(vl x) {
        xs = move(x);
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        n = (int)xs.size();
        seg.assign(max(1, 4 * n), Line{});
        has.assign(max(1, 4 * n), 0);
    }

    void add_line(ll a, ll b) {
        if (n) add_line(1, 0, n, Line(a, b));
    }

    void add_line(int k, int l, int r, Line nw) {
        if (!has[k]) { seg[k] = nw; has[k] = 1; return; }
        int m = (l + r) >> 1;
        ll xl = xs[l], xm = xs[m], xr = xs[r - 1];
        Line lo = seg[k], hi = nw;
        if (lo.eval(xm) > hi.eval(xm)) swap(lo, hi);
        seg[k] = lo;
        if (r - l == 1) return;
        if (hi.eval(xl) < lo.eval(xl)) add_line(k << 1, l, m, hi);
        else if (hi.eval(xr) < lo.eval(xr)) add_line(k << 1 | 1, m, r, hi);
    }

    void add_segment(ll a, ll b, ll xl, ll xr) {
        int l = (int)(lower_bound(all(xs), xl) - xs.begin());
        int r = (int)(lower_bound(all(xs), xr) - xs.begin());
        if (l < r) add_segment(1, 0, n, l, r, Line(a, b));
    }

    void add_segment(int k, int l, int r, int a, int b, Line ln) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { add_line(k, l, r, ln); return; }
        int m = (l + r) >> 1;
        add_segment(k << 1, l, m, a, b, ln);
        add_segment(k << 1 | 1, m, r, a, b, ln);
    }

    i128 query128(ll x) const {
        int p = (int)(lower_bound(all(xs), x) - xs.begin());
        assert(p < n && xs[p] == x);
        i128 ans = ((i128)1 << 120);
        int k = 1, l = 0, r = n;
        while (true) {
            if (has[k]) ans = min(ans, seg[k].eval(x));
            if (r - l == 1) break;
            int m = (l + r) >> 1;
            if (p < m) { k <<= 1; r = m; }
            else { k = k << 1 | 1; l = m; }
        }
        return ans;
    }

    ll query(ll x) const {
        i128 v = query128(x);
        if (v == ((i128)1 << 120)) {
            return LLONG_MAX;
        }
        assert(v >= LLONG_MIN && v <= LLONG_MAX);
        return (ll)v;
    }

};

struct SlopeTrick {
    ll min_f = 0;
    ll add_l = 0, add_r = 0;
    pq_max<ll> L;
    pq_min<ll> R;

    ll top_L() const { return L.empty() ? -LLONG_MAX / 4 : L.top() + add_l; }
    ll top_R() const { return R.empty() ? LLONG_MAX / 4 : R.top() + add_r; }

    void push_L(ll x) { L.push(x - add_l); }
    void push_R(ll x) { R.push(x - add_r); }

    void add_const(ll a) { min_f += a; }

    void add_a_minus_x(ll a) {
        if (!R.empty() && top_R() < a) {
            ll x = top_R(); R.pop();
            min_f += a - x;
            push_R(a);
            push_L(x);
        } else {
            push_L(a);
        }
    }

    void add_x_minus_a(ll a) {
        if (!L.empty() && top_L() > a) {
            ll x = top_L(); L.pop();
            min_f += x - a;
            push_L(a);
            push_R(x);
        } else {
            push_R(a);
        }
    }

    void add_abs(ll a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }

    void shift(ll a, ll b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }

    void shift(ll a) { shift(a, a); }

    void clear_right() { while (!R.empty()) R.pop(); }

    void clear_left() { while (!L.empty()) L.pop(); }

    pair<ll, ll> argmin_range() const {
        return {top_L(), top_R()};
    }

    ll get_min() const { return min_f; }
};

template<class F>
vi smawk(int rows, int cols, F cost) {
    assert(rows >= 0 && cols >= 0 && (rows == 0 || cols > 0));
    vi answer(rows, -1), rs(rows), cs(cols);
    std::iota(all(rs), 0); std::iota(all(cs), 0);
    auto solve = [&](auto&& self, const vi& r, const vi& c) -> void {
        if (r.empty()) return;
        vi reduced;
        for (int column : c) {
            while (!reduced.empty()) {
                int row = r[reduced.size() - 1];
                if (!(cost(row, column) < cost(row, reduced.back()))) break;
                reduced.pop_back();
            }
            if (reduced.size() < r.size()) reduced.pb(column);
        }
        vi odd;
        rep(i, 1, len(r), 2) odd.pb(r[i]);
        self(self, odd, reduced);
        int start = 0;
        rep(i, 0, len(r), 2) {
            int end = (int)reduced.size() - 1;
            if (i + 1 < (int)r.size()) {
                end = start;
                while (reduced[end] != answer[r[i + 1]]) ++end;
            }
            int best = start;
            rep(j, start + 1, (end) + 1)
                if (cost(r[i], reduced[j]) < cost(r[i], reduced[best])) best = j;
            answer[r[i]] = reduced[best];
            start = end;
        }
    };
    solve(solve, rs, cs);
    return answer;
}

struct AssignmentResult {
    i128 cost = 0;
    vi column;
    vc<i128> row_potential, column_potential;
};

inline optional<AssignmentResult> minimum_assignment(const vc<vl>& cost) {
    int rows = len(cost), cols = rows ? len(cost[0]) : 0;
    for (const auto& row : cost) assert(len(row) == cols);
    if (rows > cols) return nullopt;
    vc<i128> u(rows + 1), v(cols + 1);
    vi matched(cols + 1), previous(cols + 1);
    const i128 inf = (i128)1 << 120;
    rep(i, 1, rows + 1) {
        matched[0] = i;
        int column = 0;
        vc<i128> distance(cols + 1, inf);
        vb used(cols + 1);
        do {
            used[column] = true;
            int row = matched[column], next = -1;
            i128 delta = inf;
            rep(j, 1, cols + 1) if (!used[j]) {
                i128 reduced = (i128)cost[row - 1][j - 1] - u[row] - v[j];
                if (chmin(distance[j], reduced)) previous[j] = column;
                if (chmin(delta, distance[j])) next = j;
            }
            rep(j, cols + 1) {
                if (used[j]) { u[matched[j]] += delta; v[j] -= delta; }
                else distance[j] -= delta;
            }
            column = next;
        } while (matched[column] != 0);
        do {
            int next = previous[column];
            matched[column] = matched[next]; column = next;
        } while (column != 0);
    }
    AssignmentResult result;
    result.column.assign(rows, -1);
    rep(j, 1, cols + 1) if (matched[j]) result.column[matched[j] - 1] = j - 1;
    rep(i, rows) result.cost += cost[i][result.column[i]];
    result.row_potential.assign(u.begin() + 1, u.end());
    result.column_potential.assign(v.begin() + 1, v.end());
    return result;
}

inline vc<i128> min_plus_convolution_convex(const vl& a,const vl& b) {
    if(a.empty()||b.empty())return {};
    rep(j,1,len(b)-1)assert((i128)b[j]-b[j-1]<=(i128)b[j+1]-b[j]);
    int rows=len(a)+len(b)-1,cols=len(a);

    const i128 slope=(i128)1<<80;
    auto value=[&](int row,int col)->i128 {
        int j=row-col;
        i128 bv=j<0?(i128)b[0]+slope*(-(i128)j):j>=len(b)?(i128)b.back()+slope*(j-len(b)+1):b[j];
        return (i128)a[col]+bv;
    };
    auto argmin=smawk(rows,cols,value);
    vc<i128> result(rows);rep(i,rows)result[i]=value(i,argmin[i]);return result;
}

template<int SIGMA = 26, char BASE = 'a'>
struct AhoCorasick {
    struct Node {
        array<int, SIGMA> next;
        int link = 0;
        int out = 0;
        Node() { next.fill(-1); }
    };

    vc<Node> t = vc<Node>(1);
    vi terminal;
    vi bfs_order;

    int add(const str& s) {
        int v = 0;
        for (char c : s) {
            int x = c - BASE;
            assert(0 <= x && x < SIGMA);
            if (t[v].next[x] == -1) {
                t[v].next[x] = (int)t.size();
                t.emplace_back();
            }
            v = t[v].next[x];
        }
        ++t[v].out;
        terminal.pb(v);
        return (int)terminal.size() - 1;
    }

    void build() {
        queue<int> q;
        bfs_order.clear();
        rep(c, SIGMA) {
            int u = t[0].next[c];
            if (u == -1) t[0].next[c] = 0;
            else {
                t[u].link = 0;
                q.push(u);
            }
        }
        bfs_order.pb(0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            bfs_order.pb(v);
            t[v].out += t[t[v].link].out;
            rep(c, SIGMA) {
                int u = t[v].next[c];
                if (u == -1) t[v].next[c] = t[t[v].link].next[c];
                else {
                    t[u].link = t[t[v].link].next[c];
                    q.push(u);
                }
            }
        }
    }

    int move(int state, char c) const {
        return t[state].next[c - BASE];
    }

    ll count_matches(const str& s) const {
        int v = 0;
        ll ans = 0;
        for (char c : s) {
            v = move(v, c);
            ans += t[v].out;
        }
        return ans;
    }

    vl count_each(const str& s) const {
        vl cnt(t.size());
        int v = 0;
        for (char c : s) {
            v = move(v, c);
            ++cnt[v];
        }
        for (int i = (int)bfs_order.size() - 1; i > 0; --i) {
            int x = bfs_order[i];
            cnt[t[x].link] += cnt[x];
        }
        vl ans(terminal.size());
        rep(i, len(terminal)) ans[i] = cnt[terminal[i]];
        return ans;
    }
};

struct Manacher {
    int n;
    str s;
    vi odd, even;

    Manacher() {}
    Manacher(const str& s) { build(s); }

    void build(const str& x) {
        s = x; n = (int)s.size();
        odd.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 1 : min(odd[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            odd[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
        even.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 0 : min(even[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
            even[i] = k--;
            if (i + k > r) l = i - k - 1, r = i + k;
        }
    }

    bool is_palindrome(int l, int r) const {
        int len = r - l;
        if (len <= 1) return true;
        if (len & 1) {
            int c = (l + r - 1) >> 1;
            return odd[c] >= len / 2 + 1;
        } else {
            int c = (l + r) >> 1;
            return even[c] >= len / 2;
        }
    }

    int longest_length() const {
        int ans = 0;
        rep(i, n) {
            chmax(ans, 2 * odd[i] - 1);
            chmax(ans, 2 * even[i]);
        }
        return ans;
    }
};

vi prefix_function(const str& s) {
    int n = s.size();
    vi pi(n);
    FOR3(i, 1, n) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vi kmp_find_all(const str& text, const str& pattern) {
    vi ans;
    if (pattern.empty()) {
        rep(i, text.size() + 1) ans.pb(i);
        return ans;
    }
    auto pi = prefix_function(pattern);
    int j = 0;
    rep(i, text.size()) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) ++j;
        if (j == (int)pattern.size()) {
            ans.pb(i - (int)pattern.size() + 1);
            j = pi[j - 1];
        }
    }
    return ans;
}

struct RollingHash {
    using u64 = ull;
    using u128_ = u128;
    static constexpr u64 MOD = (1ULL << 61) - 1;
    static constexpr u64 BASE = 1000003ULL;

    vc<u64> h{0}, p{1};

    RollingHash() {}
    RollingHash(const str& s) { build(s); }

    static u64 mod_add(u64 a, u64 b) {
        u64 c = a + b;
        if (c >= MOD) c -= MOD;
        return c;
    }
    static u64 mod_sub(u64 a, u64 b) { return a >= b ? a - b : a + MOD - b; }
    static u64 mod_mul(u64 a, u64 b) {
        u128_ t = (u128_)a * b;
        u64 x = (u64)(t >> 61) + (u64)(t & MOD);
        if (x >= MOD) x -= MOD;
        return x;
    }

    void build(const str& s) {
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        rep(i, n) {
            p[i + 1] = mod_mul(p[i], BASE);
            h[i + 1] = mod_add(mod_mul(h[i], BASE), (unsigned char)s[i] + 1);
        }
    }

    u64 get(int l, int r) const {
        assert(0 <= l && l <= r && r <= size());
        return mod_sub(h[r], mod_mul(h[l], p[r - l]));
    }

    int size() const { return (int)h.size() - 1; }

    static u64 concat(u64 left_hash, u64 right_hash, int right_len, const vc<u64>& powers) {
        return mod_add(mod_mul(left_hash, powers[right_len]), right_hash);
    }

    int lcp(int l1, int r1, const RollingHash& other, int l2, int r2) const {
        assert(0 <= l1 && l1 <= r1 && r1 <= size());
        assert(0 <= l2 && l2 <= r2 && r2 <= other.size());
        int ok = 0, ng = min(r1 - l1, r2 - l2) + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) >> 1;
            if (get(l1, l1 + mid) == other.get(l2, l2 + mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
};

template<class Seq>
vi z_algorithm(const Seq& s){ int n=(int)len(s); vi z(n); if(!n) return z; z[0]=n; int l=0,r=0; for(int i=1;i<n;++i){ if(i<r) z[i]=min(r-i,z[i-l]); while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i]; if(r<i+z[i]) l=i,r=i+z[i]; } return z; }

namespace suffix_array_detail {
inline int minimum(int a, int b) { return std::min(a, b); }
inline int identity() { return std::numeric_limits<int>::max(); }
}

struct SuffixArray {
    str text;
    vi sa, rank, lcp;
    atcoder::segtree<int, suffix_array_detail::minimum,
                    suffix_array_detail::identity> rmq;

    explicit SuffixArray(const str& s) : text(s) {
        vi bytes;
        for (unsigned char c : text) bytes.pb(c);
        sa = atcoder::suffix_array(bytes, 255);
        rank.resize(text.size());
        rep(i, 0, (int)sa.size()) rank[sa[i]] = i;
        if (!text.empty()) lcp = atcoder::lcp_array(bytes, sa);
        rmq = decltype(rmq)(lcp);
    }

    int lcp_suffix(int i, int j) const {
        int n = (int)text.size();
        assert(0 <= i && i <= n && 0 <= j && j <= n);
        if (i == j) return n - i;
        if (i == n || j == n) return 0;
        int a = rank[i], b = rank[j];
        if (a > b) std::swap(a, b);
        return rmq.prod(a, b);
    }

    pii equal_range(const str& pattern) const {
        auto compare = [&](int pos) {
            int k = 0;
            while (k < (int)pattern.size() && pos + k < (int)text.size()) {
                unsigned char a = text[pos + k], b = pattern[k];
                if (a != b) return a < b ? -1 : 1;
                ++k;
            }
            return k == (int)pattern.size() ? 0 : -1;
        };
        auto bound = [&](bool upper) {
            int l = 0, r = (int)sa.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                int c = compare(sa[m]);
                if (c < 0 || (upper && c == 0)) l = m + 1;
                else r = m;
            }
            return l;
        };
        return {bound(false), bound(true)};
    }
};

struct PalindromicTree {
    struct Node {
        int length, link, first_end;
        std::map<unsigned char, int> next;
        ll suffix_hits = 0;
    };
    vc<Node> nodes;
    str text;
    int last = 1;
    PalindromicTree() : nodes{{-1, 0, -1, {}, 0}, {0, 0, -1, {}, 0}} {}
    explicit PalindromicTree(const str& s) : PalindromicTree() {
        for (unsigned char c : s) add(c);
    }

    int add(unsigned char c) {
        int pos = text.size();
        text.pb((char)c);
        auto suffix = [&](int v) {
            while (true) {
                int i = pos - 1 - nodes[v].length;
                if (i >= 0 && (unsigned char)text[i] == c) return v;
                v = nodes[v].link;
            }
        };
        int p = suffix(last);
        auto it = nodes[p].next.find(c);
        if (it != nodes[p].next.end()) last = it->second;
        else {
            int id = nodes.size();
            int length = nodes[p].length + 2;
            int link = length == 1 ? 1 : nodes[suffix(nodes[p].link)].next.at(c);
            nodes.pb({length, link, pos, {}, 0});
            nodes[p].next[c] = id;
            last = id;
        }
        ++nodes[last].suffix_hits;
        return last;
    }
    int distinct_count() const { return (int)nodes.size() - 2; }

    vl occurrence_counts() const {
        vl count(nodes.size());
        rep(v, 2, (int)nodes.size()) count[v] = nodes[v].suffix_hits;
        rrep(v, 2, len(nodes)) count[nodes[v].link] += count[v];
        count[0] = count[1] = 0;
        return count;
    }
};

inline vc<pii> lyndon_factorization(const str& s) {
    vc<pii> result;
    int n = len(s), i = 0;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && (unsigned char)s[k] <= (unsigned char)s[j]) {
            k = (unsigned char)s[k] < (unsigned char)s[j] ? i : k + 1;
            ++j;
        }
        int length = j - k;
        while (i <= k) { result.pb({i, i + length}); i += length; }
    }
    return result;
}

inline int minimum_rotation(const str& s) {
    ll n = len(s), i = 0, j = 1, k = 0;
    if (n == 0) return 0;
    while (i < n && j < n && k < n) {
        unsigned char a = s[(i + k) % n], b = s[(j + k) % n];
        if (a == b) { ++k; continue; }
        if (a > b) { i += k + 1; if (i <= j) i = j + 1; }
        else { j += k + 1; if (j <= i) j = i + 1; }
        k = 0;
    }
    return (int)min(i, j);
}

struct SuffixAutomaton {
    struct State { int length=0, link=-1, first_end=-1; map<unsigned char,int> next; ll hits=0; };
    vc<State> states{State{}};
    int last=0, size=0;
    SuffixAutomaton()=default;
    explicit SuffixAutomaton(const str& s) { for(unsigned char c:s) add(c); }
    void add(unsigned char c) {
        int cur=len(states),p=last;
        State current;current.length=states[last].length+1;current.first_end=size++;current.hits=1;
        states.pb(move(current));
        while(p!=-1 && !states[p].next.count(c)){states[p].next[c]=cur;p=states[p].link;}
        if(p==-1)states[cur].link=0;
        else {
            int q=states[p].next.at(c);
            if(states[p].length+1==states[q].length)states[cur].link=q;
            else {
                int clone=len(states);State copy=states[q];copy.length=states[p].length+1;copy.hits=0;
                states.pb(move(copy));
                while(p!=-1){auto it=states[p].next.find(c);if(it==states[p].next.end()||it->second!=q)break;
                    it->second=clone;p=states[p].link;}
                states[q].link=states[cur].link=clone;
            }
        }
        last=cur;
    }

    int find(const str& pattern) const {
        int v=0;for(unsigned char c:pattern){auto it=states[v].next.find(c);if(it==states[v].next.end())return -1;v=it->second;}return v;
    }
    ll distinct_substrings() const {
        ll result=0;rep(v,1,len(states))result+=states[v].length-states[states[v].link].length;return result;
    }

    vl occurrence_counts() const {
        vi frequency(size+1),order(len(states));vl count(len(states));
        for(const auto& s:states)++frequency[s.length];
        rep(i,1,len(frequency))frequency[i]+=frequency[i-1];
        rep(v,len(states)){order[--frequency[states[v].length]]=v;count[v]=states[v].hits;}
        rrep(i,1,len(order)){int v=order[i];count[states[v].link]+=count[v];}
        count[0]=(ll)size+1;return count;
    }

    optional<str> kth_substring(ull k) const {
        if(k==0)return nullopt;
        vi order(len(states));iota(all(order),0);
        sort(all(order),[&](int a,int b){return states[a].length>states[b].length;});
        vc<ull> dp(len(states));
        for(int v:order)for(auto [c,u]:states[v].next)dp[v]+=1+dp[u];
        if(k>dp[0])return nullopt;
        str result;int v=0;
        while(true)for(auto [c,u]:states[v].next){
            if(k>1+dp[u]){k-=1+dp[u];continue;}
            result+=(char)c;if(--k==0)return result;v=u;break;
        }
    }
};

namespace edit_distance_detail {
template<class Sequence>
int solve(const Sequence& a,const Sequence& b){
    if(a.size()<b.size())return solve(b,a);
    vi dp(len(b)+1);iota(all(dp),0);
    rep(i,len(a)){int diagonal=dp[0];dp[0]=i+1;
        rep(j,len(b)){int old=dp[j+1];dp[j+1]=min({dp[j]+1,old+1,diagonal+(a[i]!=b[j])});diagonal=old;}}
    return dp.back();
}
}

template<class T>
int edit_distance(const vc<T>& a,const vc<T>& b){return edit_distance_detail::solve(a,b);}
inline int edit_distance(const str& a,const str& b){return edit_distance_detail::solve(a,b);}

template<class T>
vc<T> longest_common_subsequence(const vc<T>& a,const vc<T>& b){
    int n=len(a),m=len(b);vvc<int> dp(n+1,vi(m+1));
    rep(i,n)rep(j,m)dp[i+1][j+1]=a[i]==b[j]?dp[i][j]+1:max(dp[i][j+1],dp[i+1][j]);
    vc<T> result;int i=n,j=m;
    while(i&&j){if(a[i-1]==b[j-1]){result.pb(a[--i]);--j;}
        else if(dp[i-1][j]>=dp[i][j-1])--i;else --j;}
    reverse(all(result));return result;
}

namespace lcs_detail {
template<class Sequence>
int length(const Sequence& a,const Sequence& b){
    if(a.size()<b.size())return length(b,a);
    vi dp(len(b)+1);
    for(const auto& x:a){int diagonal=0;rep(j,len(b)){int old=dp[j+1];
        dp[j+1]=x==b[j]?diagonal+1:max(dp[j],dp[j+1]);diagonal=old;}}
    return dp.back();
}
}

template<class T>
int lcs_length(const vc<T>& a,const vc<T>& b){return lcs_detail::length(a,b);}
inline str longest_common_subsequence(const str& a,const str& b){auto result=longest_common_subsequence(vc<char>(all(a)),vc<char>(all(b)));return str(all(result));}
inline int lcs_length(const str& a,const str& b){return lcs_detail::length(a,b);}

template<class T>
struct CartesianTree {
    int n = 0, root = -1;
    vi parent, left, right;

    CartesianTree() {}
    CartesianTree(const vc<T>& a) { build(a); }

    void build(const vc<T>& a) {
        n = a.size();
        parent.assign(n, -1);
        left.assign(n, -1);
        right.assign(n, -1);
        vi st;
        rep(i, n) {
            int last = -1;
            while (!st.empty() && a[i] < a[st.back()]) {
                last = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                parent[i] = st.back();
                right[st.back()] = i;
            }
            if (last != -1) {
                parent[last] = i;
                left[i] = last;
            }
            st.pb(i);
        }
        root = n ? st.front() : -1;
    }
};

struct CentroidDecomposition {
    int n;
    vvc<int> g;
    vi sz, parent, level;
    vb dead;
    vvc<pair<int,int>> path;
    vi work_parent, seen;
    int stamp = 0;

    CentroidDecomposition() {}
    CentroidDecomposition(int n) : n(n), g(n), sz(n), parent(n, -1), level(n, -1), dead(n, false), path(n), work_parent(n), seen(n, 0) {}

    void add_edge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    int find_centroid(int entry) {
        ++stamp;
        vi order;
        work_parent[entry] = -1;
        seen[entry] = stamp;
        vi st = {entry};
        while (!st.empty()) {
            int v = st.back(); st.pop_back();
            order.pb(v);
            for (int to : g[v]) if (!dead[to] && seen[to] != stamp) {
                seen[to] = stamp;
                work_parent[to] = v;
                st.pb(to);
            }
        }
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int v = order[i];
            sz[v] = 1;
            for (int to : g[v]) if (!dead[to] && seen[to] == stamp && work_parent[to] == v) sz[v] += sz[to];
        }
        int total = order.size();
        for (int v : order) {
            int mx = total - sz[v];
            for (int to : g[v]) if (!dead[to] && seen[to] == stamp && work_parent[to] == v) chmax(mx, sz[to]);
            if (mx * 2 <= total) return v;
        }
        return entry;
    }

    void add_path_info(int start, int p, int c) {
        vc<tuple<int,int,int>> st = {{start, p, 1}};
        while (!st.empty()) {
            auto [v, par, d] = st.back(); st.pop_back();
            path[v].pb({c, d});
            for (int to : g[v]) if (to != par && !dead[to]) st.pb({to, v, d + 1});
        }
    }

    int decompose(int entry, int p, int lv) {
        int c = find_centroid(entry);
        parent[c] = p;
        level[c] = lv;
        path[c].pb({c, 0});
        dead[c] = true;
        for (int to : g[c]) if (!dead[to]) add_path_info(to, c, c);
        for (int to : g[c]) if (!dead[to]) decompose(to, c, lv + 1);
        return c;
    }

    int build(int root = 0) {
        fill(all(dead), false);
        fill(all(parent), -1);
        fill(all(level), -1);
        for (auto& v : path) v.clear();
        if ((int)work_parent.size() != n) work_parent.assign(n, 0);
        if ((int)seen.size() != n) seen.assign(n, 0);
        fill(all(seen), 0);
        stamp = 0;
        return decompose(root, -1, 0);
    }
};

struct Doubling {
    int n, LOG;
    vvc<int> up;

    Doubling() {}
    Doubling(const vi& nxt, int log = 61) { build(nxt, log); }

    void build(const vi& nxt, int log = 61) {
        n = (int)nxt.size(); LOG = log;
        up.assign(LOG, vi(n));
        up[0] = nxt;
        rep(k, 1, LOG) rep(v, n) up[k][v] = up[k - 1][up[k - 1][v]];
    }

    int jump(int v, ull k) const {
        rep(b, LOG) if ((k >> b) & 1ULL) v = up[b][v];
        return v;
    }
};

template<class T, class Op>
struct DoublingMonoid {
    int n, LOG;
    vvc<int> up;
    vvc<T> dat;
    T e;
    Op op;

    DoublingMonoid(const vi& nxt, const vc<T>& val, T e, Op op, int log = 61)
        : n((int)nxt.size()), LOG(log), e(e), op(op) {
        up.assign(LOG, vi(n));
        dat.assign(LOG, vc<T>(n, e));
        up[0] = nxt;
        dat[0] = val;
        rep(k, 1, LOG) rep(v, n) {
            dat[k][v] = op(dat[k - 1][v], dat[k - 1][up[k - 1][v]]);
            up[k][v] = up[k - 1][up[k - 1][v]];
        }
    }

    pair<int, T> query(int v, ull k) const {
        T res = e;
        rep(b, LOG) if ((k >> b) & 1ULL) {
            res = op(res, dat[b][v]);
            v = up[b][v];
        }
        return {v, res};
    }
};

struct DSUOnTree {
    int n;
    vvc<int> g;
    vi parent, sz, heavy, tin, tout, euler;

    DSUOnTree() {}
    DSUOnTree(int n) : n(n), g(n) {}

    void add_edge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void build_order(int root) {
        parent.assign(n, -2);
        sz.assign(n, 1);
        heavy.assign(n, -1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        euler.clear(); euler.reserve(n);

        parent[root] = -1;
        vi st = {root};
        while (!st.empty()) {
            int v = st.back(); st.pop_back();
            tin[v] = euler.size();
            euler.pb(v);
            for (int i = (int)g[v].size() - 1; i >= 0; --i) {
                int to = g[v][i];
                if (parent[to] != -2) continue;
                parent[to] = v;
                st.pb(to);
            }
        }
        for (int i = (int)euler.size() - 1; i >= 0; --i) {
            int v = euler[i], best = 0;
            for (int to : g[v]) if (parent[to] == v) {
                sz[v] += sz[to];
                if (sz[to] > best) best = sz[to], heavy[v] = to;
            }
            tout[v] = tin[v] + sz[v];
        }
    }

    template<class Add, class Erase, class Answer>
    void run(Add add, Erase erase, Answer answer, int root = 0) {
        build_order(root);

        enum Type { CALL, ADD_SUBTREE, ADD_VERTEX, ANSWER, CLEAR_SUBTREE };
        struct Event { Type type; int v; bool keep; };
        vc<Event> st;
        st.pb({CALL, root, false});

        while (!st.empty()) {
            Event ev = st.back(); st.pop_back();
            int v = ev.v;
            if (ev.type == ADD_SUBTREE) {
                FOR3(i, tin[v], tout[v]) add(euler[i]);
            } else if (ev.type == ADD_VERTEX) {
                add(v);
            } else if (ev.type == ANSWER) {
                answer(v);
            } else if (ev.type == CLEAR_SUBTREE) {
                FOR3(i, tin[v], tout[v]) erase(euler[i]);
            } else {
                if (!ev.keep) st.pb({CLEAR_SUBTREE, v, false});
                st.pb({ANSWER, v, false});
                st.pb({ADD_VERTEX, v, false});

                vi light;
                for (int to : g[v]) if (parent[to] == v && to != heavy[v]) light.pb(to);
                for (int i = (int)light.size() - 1; i >= 0; --i) st.pb({ADD_SUBTREE, light[i], false});
                if (heavy[v] != -1) st.pb({CALL, heavy[v], true});
                for (int i = (int)light.size() - 1; i >= 0; --i) st.pb({CALL, light[i], false});
            }
        }
    }
};

struct HeavyLightDecomposition {
    struct PathSegment {
        int l, r;
        bool rev;
    };

    int n;
    vvc<int> g;
    vi parent, depth, heavy, head, in, out, rev, sz;

    HeavyLightDecomposition() {}
    HeavyLightDecomposition(int n) : n(n), g(n) {}

    void add_edge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void build(int root = 0) {
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        sz.assign(n, 1);
        vi order = {root};
        rep(i, n) {
            if (i >= len(order)) break;
            int v = order[i];
            for (int to : g[v]) if (to != parent[v]) {
                parent[to] = v;
                depth[to] = depth[v] + 1;
                order.pb(to);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int v = order[i], best = 0;
            for (int to : g[v]) if (parent[to] == v) {
                sz[v] += sz[to];
                if (sz[to] > best) best = sz[to], heavy[v] = to;
            }
        }

        head.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
        rev.assign(n, 0);
        int timer = 0;
        vc<pair<int, int>> st = {{root, root}};
        while (!st.empty()) {
            auto [start, h] = st.back(); st.pop_back();
            for (int v = start; v != -1; v = heavy[v]) {
                head[v] = h;
                in[v] = timer;
                rev[timer++] = v;
                for (int to : g[v]) {
                    if (parent[to] == v && to != heavy[v]) st.pb({to, to});
                }
            }
        }
        rep(v, n) out[v] = in[v] + sz[v];
    }

    bool is_ancestor(int u, int v) const {
        return in[u] <= in[v] && in[v] < out[u];
    }

    int lca(int a, int b) const {
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]]) a = parent[head[a]];
            else b = parent[head[b]];
        }
        return depth[a] < depth[b] ? a : b;
    }

    int dist(int a, int b) const {
        int c = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }

    pair<int, int> subtree_range(int v, bool edge = false) const {
        return {in[v] + (edge ? 1 : 0), out[v]};
    }

    vc<PathSegment> path_segments(int u, int v, bool edge = false) const {
        vc<PathSegment> left, right;
        while (head[u] != head[v]) {
            if (depth[head[u]] >= depth[head[v]]) {
                left.pb({in[head[u]], in[u] + 1, true});
                u = parent[head[u]];
            } else {
                right.pb({in[head[v]], in[v] + 1, false});
                v = parent[head[v]];
            }
        }
        if (depth[u] >= depth[v]) {
            int l = in[v] + (edge ? 1 : 0), r = in[u] + 1;
            if (l < r) left.pb({l, r, true});
        } else {
            int l = in[u] + (edge ? 1 : 0), r = in[v] + 1;
            if (l < r) right.pb({l, r, false});
        }
        reverse(all(right));
        left.insert(left.end(), all(right));
        return left;
    }
};

struct LCA {
    int n = 0, lg = 0, root = 0;
    vvc<pair<int,ll>> g;
    vvc<int> up;
    vi depth;
    vl dist_root;

    LCA() {}
    LCA(int n) : n(n), g(n) {}

    void add_edge(int u, int v, ll w = 1) {
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    void build(int r = 0) {
        root = r;
        lg = 1;
        while ((1LL << lg) <= max(1, n)) ++lg;
        up.assign(lg, vi(n, -1));
        depth.assign(n, 0);
        dist_root.assign(n, 0);

        vi order = {root};
        up[0][root] = root;
        rep(i, n) {
            if (i >= len(order)) break;
            int v = order[i];
            for (auto [to, w] : g[v]) if (to != up[0][v]) {
                up[0][to] = v;
                depth[to] = depth[v] + 1;
                dist_root[to] = dist_root[v] + w;
                order.pb(to);
            }
        }
        FOR3(k, 1, lg) rep(v, n) up[k][v] = up[k - 1][up[k - 1][v]];
    }

    int kth_ancestor(int v, ll k) const {
        if (k > depth[v]) return -1;
        rep(b, lg) if ((k >> b) & 1LL) v = up[b][v];
        return v;
    }

    int lca(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = kth_ancestor(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = lg - 1; k >= 0; --k) if (up[k][a] != up[k][b]) {
            a = up[k][a];
            b = up[k][b];
        }
        return up[0][a];
    }

    int dist_edges(int a, int b) const {
        int c = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }

    ll distance(int a, int b) const {
        int c = lca(a, b);
        return dist_root[a] + dist_root[b] - 2 * dist_root[c];
    }

    int jump(int u, int v, int k) const {
        int c = lca(u, v);
        int du = depth[u] - depth[c];
        int dv = depth[v] - depth[c];
        if (k <= du) return kth_ancestor(u, k);
        return kth_ancestor(v, du + dv - k);
    }

    bool on_path(int x, int u, int v) const {
        return dist_edges(u, x) + dist_edges(x, v) == dist_edges(u, v);
    }
};

template<class DP, class Merge, class PutEdge, class PutVertex>
struct Rerooting {
    int n;
    vvc<int> g;
    DP e;
    Merge merge;
    PutEdge put_edge;
    PutVertex put_vertex;

    Rerooting(int n, DP e, Merge merge, PutEdge put_edge, PutVertex put_vertex)
        : n(n), g(n), e(e), merge(merge), put_edge(put_edge), put_vertex(put_vertex) {}

    void add_edge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    vc<DP> build(int root = 0) {
        vi par(n, -1), order;
        order.reserve(n);
        order.pb(root);
        rep(i, n) {
            if (i >= len(order)) break;
            int v = order[i];
            for (int to : g[v]) if (to != par[v]) {
                par[to] = v;
                order.pb(to);
            }
        }

        vc<DP> down(n, e), up(n, e), ans(n, e);
        for (int oi = n - 1; oi >= 0; --oi) {
            int v = order[oi];
            DP acc = e;
            for (int to : g[v]) if (par[to] == v) {
                acc = merge(acc, put_edge(down[to], to, v));
            }
            down[v] = put_vertex(acc, v);
        }

        for (int v : order) {
            int m = (int)g[v].size();
            vc<DP> contrib(m, e), pref(m + 1, e), suf(m + 1, e);
            rep(i, m) {
                int to = g[v][i];
                if (to == par[v]) contrib[i] = up[v];
                else contrib[i] = put_edge(down[to], to, v);
                pref[i + 1] = merge(pref[i], contrib[i]);
            }
            for (int i = m - 1; i >= 0; --i) suf[i] = merge(contrib[i], suf[i + 1]);
            ans[v] = put_vertex(pref[m], v);
            rep(i, m) {
                int to = g[v][i];
                if (par[to] != v) continue;
                DP without = merge(pref[i], suf[i + 1]);
                up[to] = put_edge(put_vertex(without, v), v, to);
            }
        }
        return ans;
    }
};

template<class T = ll>
struct TreeDiameterResult { T diameter{}; int s=-1,t=-1; vi path; };
template<class T>
TreeDiameterResult<T> tree_diameter(const Graph<T>& g){
    auto far=[&](int s){ vc<T>d(g.n,T(-1)); vi p(g.n,-1),st={s}; d[s]=0; while(len(st)){ int v=st.back(); st.pop_back(); for(auto&e:g[v]) if(e.to!=p[v]){ p[e.to]=v; d[e.to]=d[v]+e.cost; st.pb(e.to); }} int x=s; rep(i,g.n) if(d[x]<d[i]) x=i; return tuple<int,vc<T>,vi>(x,d,p); };
    if(g.n==0) return {};
    auto [s,_,p0]=far(0); auto [t,d,p]=far(s); vi path; for(int v=t;v!=-1;v=p[v]){ path.pb(v); if(v==s) break; } reverse(all(path)); return {d[t],s,t,path};
}

struct VirtualTreeResult {
    vi vertices;
    vc<pii> edges;
    int root = -1;
};

inline VirtualTreeResult build_virtual_tree(const HeavyLightDecomposition& hld, vi vs) {
    VirtualTreeResult res;
    if (vs.empty()) return res;
    sort(all(vs), [&](int a, int b) { return hld.in[a] < hld.in[b]; });
    int m = (int)vs.size();
    vi add;
    rep(i, m - 1) add.pb(hld.lca(vs[i], vs[i + 1]));
    vs.insert(vs.end(), all(add));
    sort(all(vs), [&](int a, int b) { return hld.in[a] < hld.in[b]; });
    vs.erase(unique(all(vs)), vs.end());
    res.vertices = vs;
    res.root = vs[0];

    vi st;
    for (int v : vs) {
        while (!st.empty() && !hld.is_ancestor(st.back(), v)) st.pop_back();
        if (!st.empty()) res.edges.pb({st.back(), v});
        st.pb(v);
    }
    return res;
}

template<class S, auto op, auto e>
struct LinkCutTree {
private:
    struct Node { int ch[2] = {-1, -1}, parent = -1; bool rev = false; S value, forward, backward; };
    vc<Node> nodes;
    void check(int v) const { assert(0 <= v && v < len(nodes)); }
    bool auxiliary_root(int v) const {
        int p = nodes[v].parent;
        return p == -1 || (nodes[p].ch[0] != v && nodes[p].ch[1] != v);
    }
    S aggregate(int v, bool reverse) const {
        if (v == -1) return e();
        return reverse ? nodes[v].backward : nodes[v].forward;
    }
    void pull(int v) {
        auto& x = nodes[v];
        x.forward = op(op(aggregate(x.ch[0], false), x.value), aggregate(x.ch[1], false));
        x.backward = op(op(aggregate(x.ch[1], true), x.value), aggregate(x.ch[0], true));
    }
    void reverse_node(int v) {
        if (v == -1) return;
        swap(nodes[v].ch[0], nodes[v].ch[1]);
        swap(nodes[v].forward, nodes[v].backward); nodes[v].rev ^= true;
    }
    void push(int v) {
        if (!nodes[v].rev) return;
        reverse_node(nodes[v].ch[0]); reverse_node(nodes[v].ch[1]); nodes[v].rev = false;
    }
    void rotate(int v) {
        int p = nodes[v].parent, g = nodes[p].parent;
        int side = nodes[p].ch[1] == v, middle = nodes[v].ch[side ^ 1];
        if (!auxiliary_root(p)) nodes[g].ch[nodes[g].ch[1] == p] = v;
        nodes[v].parent = g;
        nodes[p].ch[side] = middle;
        if (middle != -1) nodes[middle].parent = p;
        nodes[v].ch[side ^ 1] = p; nodes[p].parent = v;
        pull(p); pull(v);
    }
    void splay(int v) {
        vi stack{v};
        for (int u = v; !auxiliary_root(u); ) { u = nodes[u].parent; stack.pb(u); }
        rrep(i, len(stack)) push(stack[i]);
        while (!auxiliary_root(v)) {
            int p = nodes[v].parent, g = nodes[p].parent;
            if (!auxiliary_root(p)) {
                bool same = (nodes[p].ch[1] == v) == (nodes[g].ch[1] == p);
                rotate(same ? p : v);
            }
            rotate(v);
        }
    }
    void access(int v) {
        int last = -1;
        for (int u = v; u != -1; u = nodes[u].parent) {
            splay(u); nodes[u].ch[1] = last;
            if (last != -1) nodes[last].parent = u;
            pull(u); last = u;
        }
        splay(v);
    }
public:
    explicit LinkCutTree(const vc<S>& values) {
        for (const S& value : values) nodes.pb({{-1,-1}, -1, false, value, value, value});
    }
    explicit LinkCutTree(int n) : LinkCutTree(vc<S>(n, e())) {}
    void make_root(int v) { check(v); access(v); reverse_node(v); }
    int find_root(int v) {
        check(v); access(v); push(v);
        while (nodes[v].ch[0] != -1) { v = nodes[v].ch[0]; push(v); }
        splay(v); return v;
    }
    bool connected(int u, int v) { check(u); check(v); return find_root(u) == find_root(v); }

    bool link(int u, int v) {
        check(u); check(v); make_root(u);
        if (find_root(v) == u) return false;
        nodes[u].parent = v; return true;
    }

    bool cut(int u, int v) {
        check(u); check(v); make_root(u); access(v);
        if (nodes[v].ch[0] != u || nodes[u].ch[1] != -1) return false;
        nodes[v].ch[0] = -1; nodes[u].parent = -1; pull(v); return true;
    }
    void set(int v, const S& value) { check(v); access(v); nodes[v].value = value; pull(v); }
    S get(int v) { check(v); access(v); return nodes[v].value; }
    S path_prod(int u, int v) {
        check(u); check(v); assert(connected(u, v));
        make_root(u); access(v); return nodes[v].forward;
    }
};

inline vi prufer_encode(int n,const vc<pii>& edges) {
    assert(n>=2&&len(edges)==n-1);
    vvc<int> g(n);vi degree(n);atcoder::dsu uf(n);
    for(auto [u,v]:edges){assert(0<=u&&u<n&&0<=v&&v<n&&!uf.same(u,v));uf.merge(u,v);
        g[u].pb(v);g[v].pb(u);++degree[u];++degree[v];}
    pq_min<int> leaves;rep(v,n)if(degree[v]==1)leaves.push(v);
    vi result;rep(i,n-2){int v=leaves.top();leaves.pop();int parent=-1;
        for(int u:g[v])if(degree[u]){parent=u;break;}
        result.pb(parent);degree[v]=0;if(--degree[parent]==1)leaves.push(parent);}
    return result;
}

inline vc<pii> prufer_decode(const vi& code) {
    int n=len(code)+2;vi degree(n,1);for(int v:code){assert(0<=v&&v<n);++degree[v];}
    pq_min<int> leaves;rep(v,n)if(degree[v]==1)leaves.push(v);
    vc<pii> result;for(int v:code){int u=leaves.top();leaves.pop();result.pb({u,v});if(--degree[v]==1)leaves.push(v);}
    int u=leaves.top();leaves.pop();result.pb({u,leaves.top()});return result;
}

struct AxisAlignedRectangle { ll left, bottom, right, top; };

inline i128 rectangle_union_area(const vc<AxisAlignedRectangle>& rectangles) {
    struct Event { ll x, low, high; int delta; };
    vc<Event> events;
    vl ys;
    for (auto r : rectangles) {
        assert(r.left <= r.right && r.bottom <= r.top);
        if (r.left == r.right || r.bottom == r.top) continue;
        events.pb({r.left, r.bottom, r.top, 1});
        events.pb({r.right, r.bottom, r.top, -1});
        ys.pb(r.bottom); ys.pb(r.top);
    }
    if (events.empty()) return 0;
    UNIQUE(ys);
    sort(all(events), [](auto a, auto b) { return a.x < b.x; });
    int n = (int)ys.size() - 1;
    vi cover(4 * n);
    vc<i128> length(4 * n);
    auto update = [&](auto&& self, int v, int l, int r, int a, int b, int delta) -> void {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) cover[v] += delta;
        else {
            int m = (l + r) / 2;
            self(self, 2 * v, l, m, a, b, delta);
            self(self, 2 * v + 1, m, r, a, b, delta);
        }
        if (cover[v] > 0) length[v] = (i128)ys[r] - ys[l];
        else length[v] = r - l == 1 ? 0 : length[2 * v] + length[2 * v + 1];
    };
    i128 area = 0;
    ll previous = events.front().x;
    for (auto e : events) {
        area += ((i128)e.x - previous) * length[1];
        int a = LB(ys, e.low);
        int b = LB(ys, e.high);
        update(update, 1, 0, n, a, b, e.delta);
        previous = e.x;
    }
    return area;
}

} // namespace Hatsuboshi

void solve(){}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
