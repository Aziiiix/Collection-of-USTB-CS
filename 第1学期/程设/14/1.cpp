#include<iostream>
using namespace std;
class Point    	//����Point��Ķ���
{
public:           	//���к�����Ա
	void InitP(float xx = 0, float yy = 0) { X = xx; Y = yy; }
	void Move(float xOff, float yOff) { X += xOff; Y += yOff; }
	float GetX() { return X; }
	float GetY() { return Y; }
protected:	        	//˽�����ݳ�Ա
	float X, Y;
};
class Rectangle : public Point	//��������������
{
public:	        	//�������к�����Ա
	void InitR(float x, float y, float w, float h)
	{
		X = x;
		Y = y; 	//���ʻ���˽�����ݳ�Ա
		W = w;
		H = h;
	}
	float GetH() { return H; }
	float GetW() { return W; }
private:	         	//����˽�����ݳ�Ա
	float W, H;
};
int main()
{
	Rectangle   rect;
	rect.InitR(1, 2, 3, 4);
	cout << rect.GetX() << endl;
	cout << rect.GetY() << endl;
	return 0;
}

