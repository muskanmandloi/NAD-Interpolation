
#include<iostream>
#include<bits/stdc++.h>	
  
using namespace std;

int factorial(int n){
	int fact=1;
	while(n){

		fact=fact*n;
		n--;
	}
	return fact;
}

int main(){
       float x[10],y[10],p[10],diff[10];
       float X,f,f2=0,u,h;
       int i, j=1,n,k=1;
       cout<<"Enter the number of observations: ";
       cin>>n;
       cout<<"\nEnter the values of xi's and f(xi's)\n";
       for(i=1; i<=n; i++){
	 		cout<<"x["<<i<<"]: ";
	   		cin>>x[i];
	 		cout<<"f["<<i<<"]: ";
	   		cin>>y[i];
       }
	 
       cout<<"\nx[i's]\tf[i's]\n";
       for(i=1; i<=n; i++){
	  	 	cout<<x[i]<<"\t"<<y[i]<<"\n";
       }
       cout<<"\nEnter the value of x at which";
        
       cin>>X;
       int m=n;
	   h=x[2]-x[1];
       u=(X-x[1])/h;

       
	   f=y[1];		
	   cout<<fixed<<setprecision(2);
	   cout<<"Forward Difference table for the given set of points is\n";      
	   do{
	   	   cout<<"diff.("<<j++<<") f(x)\n";
		   for(i=1; i<n; i++){
	      	 p[i]=( ( y[i+1]-y[i] ) );
	      	 cout<<p[i]<<"\n";

	      	 

	      	 y[i]=p[i];					
		   }
		   diff[k++]=p[1];	   	 
		   n--;
	       cout<<"\n";
       }while(n!=1);
	   
	   float df=u;
	   float l=1;
	   for(int i=1; i<m; i++ ){
	   	   if(i>1)
		   	df=df/factorial(i);
		   
		   f2=f2+(df*diff[i]);
		   for(int j=0; j<=i; j++){
		   	  l=l*(u-j);
		   } 
		   df=l;	
	   }						
       f=f+f2;
	   cout<<"\nf("<<X<<") = "<<f;
    return 0;
}
