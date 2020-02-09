#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x1[10],x2[10],x3[20],n1,n2,n3=-1;
	double a1[10],a2[10],a3[20];
	int k;
	n1=n2=-1;
	cin >> n1;
	for(k=0; k<n1; ++k){
	    cin >> x1[k] >> a1[k];
	    //cout << "" << x1[k] << " " << a1[k] << "";
	}
	//cout << "\n";
	cin >> n2;
	for(k=0; k<n2; ++k){
	    cin >> x2[k] >> a2[k];
	    //cout << "" << x2[k] << " " << a2[k] << "";
	}
	
	int x,y;
	x=y=0;
	while(x<n1 && y<n2)
	{
		if(x1[x]==x2[y])
		{
			//cout << "" << x1[x] << " " << a1[x]+a2[y] << " ";
			if(a1[x]+a2[y] != 0){
				x3[++n3]=x1[x];
				a3[n3]= a1[x]+a2[y];
			}
			++x;
			++y;
		} 
		else if(x1[x] < x2[y])
		{
			//cout << "" << x2[y] << " " << a2[y] << " ";
			a3[++n3]=a2[y];
			x3[n3]=x2[y];
			++y;
		}
		else if(x1[x] > x2[y])
		{
			//cout << "" << x1[x] << " " << a1[x] << " ";
			x3[++n3]=x1[x];
			a3[n3]=a1[x];
			++x;
		}
	}
	while(x<n1)
	{
	    //cout << "" << x1[x] << " " << a1[x] << "  ";
	    x3[++n3]=x1[x];
        a3[n3]=a1[x];
	    ++x;
	}
	while(y<n2)
	{
	    //cout << "" << x2[y] << " " << a2[y]<< "";
        a3[++n3]=a2[y];
        x3[n3]=x2[y];
	    ++y;
	}
	k=-1;
	cout << n3+1;
	
	while(++k<=n3)
	    cout << " " << x3[k] << " " << fixed << setprecision(1) << a3[k];

	
	return 0;
}