bool PointOnSeg(point p, line l)
{
    return
        sgn((l.s - p) ^ (l.e-p)) == 0 &&
        sgn((p.x - l.s.x) * (p.x - l.e.x)) <= 0 &&
        sgn((p.y - l.s.y) * (p.y - l.e.y)) <= 0;
}
//�е��Ƿ����߶���,�����˵�
int dot_online_in(point p,line l){
	return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}

//�е��Ƿ����߶���,�������˵�
int dot_online_ex(point p,line l){
	return dot_online_in(p,l)&&(!zero(p.x-l.a.x)||!zero(p.y-l.a.y))&&(!zero(p.x-l.b.x)||!zero(p.y-l.b.y));
}

//���������߶�ͬ��,�����߶��Ϸ���0
int same_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}

//���������߶����,�����߶��Ϸ���0
int opposite_side(point p1,point p2,line l){
	return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}


