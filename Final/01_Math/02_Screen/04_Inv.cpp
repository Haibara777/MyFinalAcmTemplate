void Init_inv(int inv[],int n,int M)//��ȷ��MΪ����
{
    if(M<=n)
        n = M-1;
    inv[0] = 0;
    inv[1] = 1;
    for(int i = 2; i < n; i ++){
        inv[i] = (M-1LL*M/i*inv[M%i]%M)%M;
    }
}
