/**
- ����ÿ��ѯ�ʵĵ㣬���Ұ���dfs��Ϊ�ؼ�������
- ����1����ѹ��ջ���У���ʼ��������
- ö�ٵ���һ����u������u��ջ����v�Ĺ�������lca
- ����ջ��ջ���·��ĵ�Ϊw����ջ��ֻ��1�����ֱ������һ��������w�����ȴ���lca�Ͱ�v��w��һ���ߣ����ҵ���v���ظ��˲�������͵���һ��
- ��lca���ǵ�ǰ��v����ô�Ͱ�lca��v���ߣ���v��������lca��Ϊջ��Ԫ�أ�ע�������������˼�����ջ��û�����lca��ô��ѹ�룩���������κβ���
- ����uѹ��ջ��
- �ص�3����ö���¸��㣬ֱ��ö���������е�
- ��ջ��v��ջ���·��ĵ�Ϊw���ߣ����Ұ�v��������ô��ֱ��ջ��ֻ��һ����
- ջ��ʣ�µĵ���������ĸ���
*/
const int maxn = "Edit";
vector<int> vtree[maxn];
void build(vector<int>& vec)
{
    sort(vec.begin(), vec.end(), [&](int x, int y) { return dfn[x] < dfn[y]; });
    static int s[maxn];
    int top = 0;
    s[top] = 0;
    vtree[0].clear();
    for (auto& u : vec){
        int vlca = lca(u, s[top]);
        vtree[u].clear();
        if (vlca == s[top])
            s[++top] = u;
        else{
            while (top && dep[s[top - 1]] >= dep[vlca]){
                vtree[s[top - 1]].push_back(s[top]);
                top--;
            }
            if (s[top] != vlca){
                vtree[vlca].clear();
                vtree[vlca].push_back(s[top--]);
                s[++top] = vlca;
            }
            s[++top] = u;
        }
    }
    for (int i = 0; i < top; ++i) vtree[s[i]].push_back(s[i + 1]);
}
