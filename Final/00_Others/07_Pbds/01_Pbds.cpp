/// �ɲ���
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;	///
typedef __gnu_pbds::priority_queue <int, greater<int>, pairing_heap_tag> Heap;	///
erase(iterator);	/// ���ݵ�����ɾ��Ԫ��
modify(iterator, val);	/// ���ݵ������޸�ֵ
join(other);	/// ʹ��֮����һ���ᱻ���
/// ����ͬSTL

/// �ɳ־û�ƽ����
#include <ext/rope>
using namespace __gnu_cxx;	///
/// �±��0��ʼ��������cin������cout
/// ����rope�ĵײ�ʵ�֣�insert��erase��get����logn��
reverse��O(n)�ģ����Թ�������rope����
push_back(x);	///    ��ĩβ���x
insert(pos,x);	///   ��pos����x
erase(pos,x);	///    ��pos��ʼɾ��x��
replace(pos,x);	///  ��pos��ʼ����x
substr(pos,x);	///   ��ȡpos��ʼx��
at(x)/[x];	///   ���ʵ�x��Ԫ��
rope<int>*his[maxn], his[i]=new rope<char>(*his[i-1]);	/// �ɳ־û�����
