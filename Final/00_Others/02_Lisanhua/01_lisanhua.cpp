vector<int> id;

int Getid(int x)	/// 1 ��ʼ���
{
    return lower_bound(id.begin(), id.end(), x) - id.begin() + 1;
}

void G()
{
    sort(id.begin(), id.end());
    id.erase(unique(id.begin(), id.end()), id.end());
}
