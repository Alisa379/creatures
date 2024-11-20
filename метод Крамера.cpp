// Метод Крамера для трёх неизвестных
#include <iostream>
using std::cout, std::cin;
int main() {
	float x1, x2, x3, a[3][3], b[3], D, DX1, DX2, DX3;
	cout<<"a00x1+a01x2+a02x3=b0\na10x1+a11x2+a12x3=b1\na20x1+a21x2+a22x3=b2\nInput the coefficients a\nWARNING!!!ENTER COEFFICIENTS BY COLUMNS!!!";
	for (int i=0;i<3;i++) {
		for (int j=0;j<3;j++)
		cin>>a[i][j];
	}
	for (int i=0;i<3;i++) {
		for (int j=0;j<3;j++)
		cout<<"a"<<i<<j<<"="<<a[i][j]<<"\n";
	}
    cout<<"Input coefficients b";
    for (int i=0;i<3;i++) {
    	cin>>b[i];
	}
    cout<<"Press \"Enter\" to get the result\n";
	system("pause");
	cin.get();
	D=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1] - (a[0][2]*a[1][1]*a[2][0]+a[0][1]*a[1][0]*a[2][2]+a[0][0]*a[2][1]*a[1][2]);
	DX1=b[0]*a[1][1]*a[2][2]+b[1]*a[2][0]*a[1][2]+b[2]*a[1][0]*a[2][1]-b[2]*a[1][1]*a[2][0]-b[0]*a[2][1]*a[1][2]-b[1]*a[1][0]*a[2][2];
	DX2=a[0][0]*b[1]*a[2][2]+a[0][1]*b[2]*a[2][0]+a[0][2]*b[0]*a[2][1]-a[0][2]*b[1]*a[2][0]-a[0][1]*b[0]*a[2][2]-a[0][0]*b[2]*a[2][1];
	DX3=a[0][0]*a[1][1]*b[2]+a[0][1]*a[1][2]*b[0]+a[0][2]*a[1][0]*b[1]-a[0][2]*a[1][1]*b[0]-a[0][1]*a[1][0]*b[2]-a[0][0]*a[1][2]*b[1];
	x1=DX1/D;
	x2=DX2/D;
	x3=DX3/D;
	cout<<"x1 = "<<x1<<"\n"<<"x2 = "<<x2<<"\n"<<"x3 = "<<x3<<"\n";
	cout<<"D = "<<D<<"\n";
	cout<<"DX1 = "<<DX1<<"\n";
	cout<<"DX2 = "<<DX2<<"\n";
	cout<<"DX3 = "<<DX3<<"\n";
}