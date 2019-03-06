/// �������Ż�
const int N = 550;
const int M = N / 32 + 1;   /// ������ѹλ

int ma[N][M];
int b[M];               /// ���� ne ����
int ne[N];
int n, m;
int tot;

inline void set1(int v[],int x){v[x>>5]|=1<<(x&31);}    /// �ȼ��� v[x] = 1
inline void flip(int v[],int x){v[x>>5]^=1<<(x&31);}	///  �����ж�����λ��λȡ��

bool Find(int x)
{
    /// printf("%d %d\n", x, tot);
    for(int i = 0; i <= tot; i ++){    /// һ���� 0 ��ʼ
    	while(true){
            int t;
            int q;

            /// printf("%d %d %d %d\n", x, i, ma[x][i], b[i]);
	        t = ma[x][i] & b[i];
	        if(!t){
                break;
	        }
	        q = i << 5 | __builtin_ctz(t);	/// o ĩβ 0 �ĸ�����x = 0 ʱ���δ����
	        /// printf("%d %d\n", o, y);
	        flip(b, q);
	        if(!ne[q] || Find(ne[q])){
	            ne[q] = x;
                return true;
	        }
   		}
   	}

    return false;
}

int Match()
{
    int ans;

    ans = 0;
    memset(ne, 0, sizeof(ne));
    for(int i = 1; i <= n; i ++){   /// ����һ��
        for(int j = 1; j <= m/*(n???)*/; j ++){ 	/// ��˼��
            set1(b, j);
        }
        if(Find(i)){
            ans ++;
        }
    }

    return ans;
}

int main()
{
    int ncase;

    scanf("%d", &ncase);
    while(ncase --){
        memset(ma, 0, sizeof(ma));
        scanf("%d%d", &m, &n);
        tot = m >> 5;   /// ѹλ���С�� 32
        for(int i = 1; i <= m; i ++){
            int t;

            scanf("%d", &t);
            for(int j = 0; j < t; j ++){
                int x;

                scanf("%d", &x);
                set1(ma[x], i);
                /// ma[x][i] = 1;
            }
        }
    }

    return 0;
}
