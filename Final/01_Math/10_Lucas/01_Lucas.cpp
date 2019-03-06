#define P 110119
using namespace std;
typedef pair<LL ,LL> PC;
LL fac[P],inv[P],facinv[P];
//Ԥ�����С������P������������Ԫ���׳��Լ��׳˵���Ԫ
void Init_lucas(){
	fac[0]=fac[1]=inv[0]=facinv[0]=inv[1]=facinv[1]=1;
	for(int i = 2; i < P; ++i) {
        fac[i] = fac[i - 1] * i % P;
        inv[i] = inv[P % i] * (P - P / i) % P;
//ע�������ʽ������o(n)�ĸ��Ӷ����������������Ԫ
        facinv[i] = facinv[i - 1] * inv[i] % P;
    }
}
//n<=10^18,m<=10^18,p<=10^5���������
LL GetC(LL n,LL m,LL p){
    if (m>n) return 0;
    if (!n) return 1;
	LL ret=fac[n]*facinv[m]%p*facinv[n-m]%p;
    return ret;
}
/// lucas�������ʵ��,n<=10^18,m<=10^18,p<=10^5
LL Pick(LL n,LL m,LL p){
    if (!m) return 1;
    LL a[100],b[100],i=-1;
    while (n){
        a[++i]=n%p;
        n/=p;
        b[i]=m%p;
        m/=p;
    }
    LL k=i;
    LL ret=1;
    for (int i=0;i<=k;i++){
        ret*=getC(a[i],b[i],p);
        ret%=p;
    }
    return ret;
}
int main(){
	init_lucas();
	cout<<pick(5,3,P)<<endl;
	return 0;
}
