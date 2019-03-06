/*
�������p���׸�ԭ�������Ӷ�ԼΪp*log^2(p)/phi(p-1)
ǰ78494������(1~1000000)���У�ԭ����ƽ��ֵԼΪ4.88�����Ժ���Ϊ������
��˸��Ӷ�ֻ��log^2(p)
*/
#define N 1000000
int top=0;
long long st[40];
void init(long long m){
    top=0;
    memset(st,0,sizeof st);
    for (long long i=2;i<=sqrt(m)+1;i++){
        if (m%i==0){
            st[top++]=i;
            while (m%i==0) m/=i;
        }
    }
    if (m>1) st[top++]=m;
}
long long solve(long long p){
    init(p-1);
    for (long long g=1;g<=p-1;g++){
        bool bb=true;
        for (int j=0;j<top;j++){
            long long mod=power(g,(p-1)/st[j],p);	/// ������
            if (mod==1) {
                bb=false;
                break;
            }
        }
        if (bb){
            return g;
        }
    }
}
int main(){
    long long p;
    cin>>p;
    cout<<solve(p)<<endl;
    return 0;
}
