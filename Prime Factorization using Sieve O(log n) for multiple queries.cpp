/*
To calculate to smallest prime factor for every number we will use the sieve of eratosthenes. 
In original Sieve, every time we mark a number as not-prime,we store the corresponding smallest prime factor for that number 

Now, after we are done with precalculating the smallest prime factor for every number we will divide our number n 
(whose prime factorization is to be calculated) by its corresponding smallest prime factor till n becomes 1. 

pre-computation allowed for precomputing spf[]

ex:

n=20
uska smallest prime factor spf = 2

//jab tak n 1 nahi hota tab tak while()
20/2=10
10/2=5
5/5=1   5 khud hi prime hai


20 --> 10 --> 5 --> 1
    2      2     5
    
prime factorization of 20 => {2,2,5}

*/

#include "bits/stdc++.h"
using namespace std;

#define MAXN   100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)

//sieve ke andar abhi har index pe i ka smallest prime factor bharo
void primefactor(int n)
{
	int spf[100]={0};
	
	for(int i=2;i<=n;i++)
	{
		//ab jo bhi prime numbers hoge unka spf vo number khud hi hoga jaise 5 ka 5 2 ka 2
		spf[i]=i;
	}
	
	//ab upar humne initialize kiya hai. ab dekhenge ki kya koi number uninitialized hai
	for(int i=2;i<=n;i++)
	{
		if(spf[i]==i)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				//matlab unmarked hai kyuki agar vo already marked hai to matlab uska spf already aa chuka hai
				if(spf[j]==j)
				{
					spf[j]=i;
				}
			}
		}
	}
	
	//ab spf[] precompute ho chuka hai, ab while() ki baari
	while(n!=1)
	{
		cout<<spf[n]<<" ";
		n=n/spf[n];  //us number ke spf se divide karte jaao.	
	}	
	
}

 
// driver program for above function
int main()
{
	int n;
	cout<<"\n number => ";
	cin>>n;
    cout << "\nprime factorization for \n\n";
    primefactor(n);
 
    return 0;
}
