const int N = 1e6+7;
int pri[N];
int phi[N];
void init_phi(int n)
{
    memset(phi,0,sizeof(phi));
    int len = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(phi[i] == 0)
            phi[i] = i-1,pri[len++] = i;
        for(int j = 0; j<len && (k=i*pri[j])<=n; j++)
            if(i%pri[j])
                phi[k]=phi[i]*phi[pri[j]];
            else{
                phi[k]=phi[i]*pri[j];
                break;
            }
    }
}

LL phi(LL x)//�������ֵС��0������Υ�棬����int������ʱ������
{
    if(x<2)return x;
    LL ans = x;
    for(int i = 2,q = sqrt(x)+1; i < q; i++){
        if(x%i==0){
            ans-=ans/i;
            while(x%i==0)x/=i;
            q = sqrt(x)+1;
        }
    }
    if(x!=1)
        ans-=ans/x;
    return ans;
}
