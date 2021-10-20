#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
# include <cmath>

using namespace std;
void num_to_bin(long long N,char*a);
int main()
{
	string a="1";
	string b="dsf";
	b=a.substr(1,0);
	cout << b;
	// long long N;
	// cin>>N;
	// char str[33]={'\0'};
    // for (int i=0;i<32;i++){
    //     str[i]='0';
    // }
	// double t1;
    // double t2;
	// if(N>=0)str[0]='0';
	// else 
	// {
	// 	str[0]='1';
    //     t1=pow(2,32);
	// 	t2 =t1+N;
    //     N=t2;
	// }
	// num_to_bin(N,str);
	// cout<<str<<endl;
	return 0;
}
void num_to_bin(long long N,char*a)
{
	long long i=0,j,tmp;
	while(N!=0)
	{
		i++;
		a[32-i]=N%2+'0';
		N=N/2;
	}
	// for(j=0;j<i/2;j++)
	// {
	// 	tmp=a[31-j];
	// 	a[31-j]=a[32-j-i];
	// 	a[32-j-i]=tmp;
	// }
}
