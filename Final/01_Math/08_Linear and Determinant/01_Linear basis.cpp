int Gauss()
{
	int cnt;

	cnt = 0;	///�������Ի�Ԫ�صĸ���
    for(int i = 1; i <= n; i ++){
        for(int j = 62; j >= 0; j --){
            if((ma[i] >> j) & 1){
                if(!p[j]){
                    p[j] = ma[i];
                    break;
                }
                else{
                    ma[i] ^= p[j];
                }
            }
        }
    }
    for(int i = 0; i <= 62; i++){
    	if(p[i]){
    	    cnt ++;
    	}
    }

    return cnt;
}
