inline NODE Vector(NODE A, NODE B);  //����AB
double cross(NODE A, NODE B, NODE P);
inline double dis2(NODE a, NODE b);
double disLine(NODE A, NODE B, NODE P);
double dot(NODE A, NODE B, NODE P);
NODE prxy(NODE A, NODE B, NODE O);
NODE Vbase(NODE A, NODE B, NODE O, int r);
int main()
{
	NODE A, B, O;
	double r;
	cin >> O.x >> O.y>>r;
	cin >> A.x >> A.y >> B.x >> B.y;
	NODE Base = Vbase(A, B, O, r);      //����base
	NODE pr = prxy(A, B, O);            //��pr
	NODE x1 = { Base.x + pr.x, Base.y + pr.y };
	NODE x2 = { pr.x - Base.x, pr.y - Base.y };
	if (disLine(A, B, O) > r)
		cout << "û�н���" << endl;
	else
		cout << x1.x << ' ' << x1.y << ' ' << x2.x << ' ' << x2.y << endl;
	return 0;
}
NODE Vbase(NODE A,NODE B,NODE O,int r)    //������base
{
	double base = sqrt(r*r - disLine(A, B, O)*disLine(A, B, O));
	NODE AB = Vector(A, B);
	NODE e = { AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B)) };
	return{ e.x*base, e.y*base };
}
NODE prxy(NODE A,NODE B,NODE O)   //���pr������, ��pr��Բ��O��ֱ��AB�Ĵ���
{
	NODE AO = Vector(A, O);
	NODE AB = Vector(A, B);
	double l = dot(A, B, O) / sqrt(dis2(A, B));
	NODE e = { AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B)) };
	NODE Apr = { e.x*l, e.y*l };
	return{ A.x + Apr.x, A.y + Apr.y };
}
double disLine(NODE A, NODE B, NODE P)   //��P��ֱ��AB�ľ���
{
	return fabs(cross(A,B,P))/sqrt(dis2(A,B));
}
double dot(NODE A, NODE B, NODE P)    //����AB,AP���ڻ�
{
	NODE AB = Vector(A, B);
	NODE AP = Vector(A, P);
	return AB.x*AP.x + AB.y*AP.y;
}
inline double dis2(NODE a, NODE b)            //��a,b�����ƽ��
{
	return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}
double cross(NODE A, NODE B, NODE P)   //����AB������AP�����
{
	NODE AB = Vector(A, B);
	NODE AP = Vector(A, P);
	return AB.x*AP.y - AB.y*AP.x;
}
inline NODE Vector(NODE A, NODE B)    //����AB
{
	return{ B.x - A.x, B.y - A.y };
}
