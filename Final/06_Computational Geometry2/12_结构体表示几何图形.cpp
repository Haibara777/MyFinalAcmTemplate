//���㼸��(��ά)
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;


typedef double TYPE;
#define Abs(x) (((x)>0)?(x):(-(x)))
#define Sgn(x) (((x)<0)?(-1):(1))
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Epsilon 1e-8
#define Infinity 1e+10
#define PI acos(-1.0)//3.14159265358979323846
TYPE Deg2Rad(TYPE deg){return (deg * PI / 180.0);}
TYPE Rad2Deg(TYPE rad){return (rad * 180.0 / PI);}
TYPE Sin(TYPE deg){return sin(Deg2Rad(deg));}
TYPE Cos(TYPE deg){return cos(Deg2Rad(deg));}
TYPE ArcSin(TYPE val){return Rad2Deg(asin(val));}
TYPE ArcCos(TYPE val){return Rad2Deg(acos(val));}
TYPE Sqrt(TYPE val){return sqrt(val);}


//��
struct POINT
{
  TYPE x;
  TYPE y;
  POINT() : x(0), y(0) {};
  POINT(TYPE _x_, TYPE _y_) : x(_x_), y(_y_) {};
};
// ������ľ���
TYPE Distance(const POINT & a, const POINT & b)
{
  return Sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//�߶�
struct SEG
{
  POINT a; //���
  POINT b; //�յ�
  SEG() {};
  SEG(POINT _a_, POINT _b_):a(_a_),b(_b_) {};
};
//ֱ��(����ʽ)
struct LINE
{
  POINT a;
  POINT b;
  LINE() {};
  LINE(POINT _a_, POINT _b_) : a(_a_), b(_b_) {};
};
//ֱ��(һ��ʽ)
struct LINE2
{
  TYPE A,B,C;
  LINE2() {};
  LINE2(TYPE _A_, TYPE _B_, TYPE _C_) : A(_A_), B(_B_), C(_C_) {};
};


//����ʽ��һ��ʽ
LINE2 Line2line(const LINE & L) // y=kx+c k=y/x
{
  LINE2 L2;
  L2.A = L.b.y - L.a.y;
  L2.B = L.a.x - L.b.x;
  L2.C = L.b.x * L.a.y - L.a.x * L.b.y;
  return L2;
}


// ���÷���ֱ�� Ax + By + C =0 ��ϵ��
void Coefficient(const LINE & L, TYPE & A, TYPE & B, TYPE & C)
{
  A = L.b.y - L.a.y;
  B = L.a.x - L.b.x;
  C = L.b.x * L.a.y - L.a.x * L.b.y;
}
void Coefficient(const POINT & p,const TYPE a,TYPE & A,TYPE & B,TYPE & C)
{
  A = Cos(a);
  B = Sin(a);
  C = - (p.y * B + p.x * A);
}
/�е�(ֵ���㣬ֱ��)
bool IsEqual(TYPE a, TYPE b)
{
  return (Abs(a - b) <Epsilon);
}
bool IsEqual(const POINT & a, const POINT & b)
{
  return (IsEqual(a.x, b.x) && IsEqual(a.y, b.y));
}
bool IsEqual(const LINE & A, const LINE & B)
{
  TYPE A1, B1, C1;
  TYPE A2, B2, C2;
  Coefficient(A, A1, B1, C1);
  Coefficient(B, A2, B2, C2);
  return IsEqual(A1 * B2, A2 * B1) && IsEqual(A1 * C2, A2 * C1) && IsEqual(B1 * C2, B2 * C1);
}
// ����
struct RECT
{
  POINT a; // ���µ�
  POINT b; // ���ϵ�
  RECT() {};
  RECT(const POINT & _a_, const POINT & _b_) { a = _a_; b = _b_; }
};


//���λ���׼
RECT Stdrect(const RECT & q)
{
  TYPE t;
  RECT p=q;
  if(p.a.x > p.b.x) swap(p.a.x , p.b.x);
  if(p.a.y > p.b.y) swap(p.a.y , p.b.y);
  return p;
}


//�����±귵�ؾ��εı�
SEG Edge(const RECT & rect, int idx)
{
  SEG edge;
  while (idx < 0) idx += 4;
  switch (idx % 4)
  {
  case 0: //�±�
    edge.a = rect.a;
    edge.b = POINT(rect.b.x, rect.a.y);
    break;
  case 1: //�ұ�
    edge.a = POINT(rect.b.x, rect.a.y);
    edge.b = rect.b;
    break;
  case 2: //�ϱ�
    edge.a = rect.b;
    edge.b = POINT(rect.a.x, rect.b.y);
    break;
  case 3: //���
    edge.a = POINT(rect.a.x, rect.b.y);
    edge.b = rect.a;
    break;
  default:
    break;
  }
  return edge;
}


//���ε����
TYPE Area(const RECT & rect)
{
  return (rect.b.x - rect.a.x) * (rect.b.y - rect.a.y);
}


//�������εĹ������
TYPE CommonArea(const RECT & A, const RECT & B)
{
  TYPE area = 0.0;
  POINT LL(Max(A.a.x, B.a.x), Max(A.a.y, B.a.y));
  POINT UR(Min(A.b.x, B.b.x), Min(A.b.y, B.b.y));
  if( (LL.x <= UR.x) && (LL.y <= UR.y) )
  {
    area = Area(RECT(LL, UR));
  }
  return area;
}
//�ж�Բ�Ƿ��ھ�����(����������)
bool IsInCircle(const CIRCLE & circle, const RECT & rect)
{
  return (circle.x - circle.r > rect.a.x) &&
    (circle.x + circle.r < rect.b.x) &&
    (circle.y - circle.r > rect.a.y) &&
    (circle.y + circle.r < rect.b.y);
}


//�жϾ����Ƿ���Բ��(����������)
bool IsInRect(const CIRCLE & circle, const RECT & rect)
{
  POINT c,d;
  c.x=rect.a.x; c.y=rect.b.y;
  d.x=rect.b.x; d.y=rect.a.y;
  return (Distance( Center(circle) , rect.a ) < circle.r) &&
    (Distance( Center(circle) , rect.b ) < circle.r) &&
    (Distance( Center(circle) , c ) < circle.r) &&
    (Distance( Center(circle) , d ) < circle.r);
}


//�жϾ����Ƿ���Բ����(����������)
bool Isoutside(const CIRCLE & circle, const RECT & rect)
{
  POINT c,d;
  c.x=rect.a.x; c.y=rect.b.y;
  d.x=rect.b.x; d.y=rect.a.y;
  return (Distance( Center(circle) , rect.a ) > circle.r) &&
    (Distance( Center(circle) , rect.b ) > circle.r) &&
    (Distance( Center(circle) , c ) > circle.r) &&
    (Distance( Center(circle) , d ) > circle.r) &&
    (rect.a.x > circle.x || circle.x > rect.b.x || rect.a.y > circle.y || circle.y > rect.b.y) ||
    ((circle.x - circle.r > rect.b.x) ||
    (circle.x + circle.r < rect.a.x) ||
    (circle.y - circle.r > rect.b.y) ||
    (circle.y + circle.r < rect.a.y));
}
