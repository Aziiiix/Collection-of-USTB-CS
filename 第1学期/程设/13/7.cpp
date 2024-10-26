#include<iostream>
using namespace std;
class Rational
{
	public:
		Rational()
		{
			mol=0;den=0;
		}
		Rational(int x,int y)
		{
			mol=x;den=y;
		}
		Rational Add(Rational A)
		{
			Rational stat;
			stat.mol=mol*A.den+den*A.mol;
			stat.den=den*A.den;
			return stat; 
		}
		Rational Sub(Rational A)
		{
			Rational stat;
			stat.mol=mol*A.den-den*A.mol;
			stat.den=den*A.den;
			return stat; 
		}
		Rational Mul(Rational A)
		{
			Rational stat;
			stat.mol=mol*A.mol;
			stat.den=den*A.den;
			return stat;
		}
		Rational Div(Rational A)
		{
			Rational stat;
			stat.mol=mol*A.den;
			stat.den=den*A.mol;
			return stat; 
		}
		void print()
		{
			cout<<mol<<"/"<<den<<endl;
		}
		void floatprint()
		{
			cout<<(float)mol/(float)den<<endl;
		}
	private:
		int mol;//·Ö×Ó 
		int den;//·ÖÄ¸ 
};
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	Rational A(a,b);
	Rational B(c,d);
	(A.Add(B)).print();
	(A.Sub(B)).floatprint();
	(A.Mul(B)).print();
	(A.Div(B)).floatprint();
	return 0;
}

