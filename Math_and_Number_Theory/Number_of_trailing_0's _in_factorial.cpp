#include<iostream>
using namespace std;
int trailingzeros(int n)
{
	int i;
	int count=0;
	for(i=5;n/i>=1;i*=5)
		count+=n/i;
	return count;
}
 int main()
 {
     int n;
     cin>>n;
     cout<<"Number of trailing zeroes in the factorial in the given number is: "<<endl;
     cout<<trailingzeros(n)<<endl;
 	 return 0;
 }
