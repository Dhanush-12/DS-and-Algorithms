#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // (a+b+c+d)^2 = a2+b2+c2+d2+2(ab+bc+cd+ac+ad+bd);
    // ab+bc+cd+ac+ad+bd = ((a+b+c+d)^2 - a2+b2+c2+d2)/2;
    int sum=0,square=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        square+=(arr[i]*arr[i]);
    }
    cout<<((sum*sum)-(square))/2<<endl;
}
