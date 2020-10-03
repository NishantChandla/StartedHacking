#include<iostream>
using namespace std;

int Index = 0 ;

void insert ( int *A , int data ){
	Index++;
	int i = Index;
	A[i] = data;

	while ( data > A[i/2] && i > 1){
		A[i] = A[i/2];
		i = i/2;
	}
	A[i] = data;
}

void swap ( int *a , int * b ){
	int temp;
	temp = *a;
	*a = *b ;
	*b = temp;
}

int Delete ( int *A ){

	int x , i = 1;
	x = A[1];
	A[i] = A[Index];
	Index--;
	A[Index+1] = x;

	while( 2*i < Index ){

		if ( A[i] > A[2*i] && A[i] > A[2*i+1]){
			break;
		}
		if ( A[2*i] < A[2*i+1] ){
			 swap(A[i],A[2*i+1]);
		} else {
			 swap(A[i],A[2*i]);
		}
			
		i = 2*i;
	}
	return x;
}

void display ( int A[] ){
	int i;
	for ( i = 1 ; i < 8 ; i++ ){
		cout<<A[i]<<"\t";
	}
	cout<<"\n";
}

int main(){
	int A[] = {0, 12, 10 , 15, 14, 8, 9, 11 };
	int i = 0 ;

	for ( i = 1 ; i <= 7 ; i++  ){
		insert(&A[0] , A[i]);
	}
	display(A);

	for ( i = 1 ; i <= 7 ; i++  ){
		cout<<Delete(&A[0])<<"\n";
	}

	
	display(A);

	return 0;
}