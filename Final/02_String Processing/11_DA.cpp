const int N = int(2e5)+10;
int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
// ���ڱȽϵ�һ�ؼ�����ڶ��ؼ���,
// �Ƚ�����ĵط���,Ԥ�����ʱ��,r[n]=0(С��ǰ����ֹ����ַ�)

int wa[N],wb[N],ws[N],wv[N];
int rank[N],height[N];
void DA(int *r,int *sa,int n,int m){ //�˴�N�������NҪ��1��Ϊ�˹���ӵ�һ���ַ������ڱ���CMPʱԽ��
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i; //Ԥ������Ϊ1
    for(j=1,p=1;p<n;j*=2,m=p) //ͨ���Ѿ�����ĳ���J��SA������2*J��SA
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i; // ���⴦��û�еڶ��ؼ��ֵ�
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; //���ó���J�ģ����ڶ��ؼ�������
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];  //�������򲿷�
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  //������������x[],ע���ж���ͬ��
    }
}

void calheight(int *r,int *sa,int n){ // �˴�NΪʵ�ʳ���
    int i,j,k=0;        // height[]�ĺϷ���ΧΪ 1-N, ����0�ǽ�β������ַ�
    for(i=1;i<=n;i++) rank[sa[i]]=i;  // ����SA��RANK
    for(i=0;i<n; height[rank[i++]] = k ) // ���壺h[i] = height[ rank[i] ]
    for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++); //���� h[i] >= h[i-1]-1 ���Ż�����height����
}

char str[N];
int sa[N];
int main(){
    char str[N];
    scanf("%s",str);
    int n = strlen(str);
    str[n]=0;

    da(str,sa,n+1,128);  //ע�����ִ˴�Ϊn+1,��Ϊ�����һ����β�ַ���������Ƚ�
    calheight(str,sa,n);
}
