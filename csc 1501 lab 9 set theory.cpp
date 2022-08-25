#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

//these will b e the functions to find the values
int find_union(int * set1, int m, int * set2, int n, int Result[]);
int find_intersection(int * set1, int m, int * set2, int n, int Result[]);
int find_subtraction(int * set1, int m, int * set2, int n, int Result[]);

//function to find the union of sets
int find_union(int * set1, int m, int * set2, int n, int Result[]){
int l = 0;
int i,j,found;
for(i=0; i<m; i++){
Result[i] = set1[i];
l++;
}

int e = l;

for(i=0; i<n; i++){
    found=0;
    for (j=0; j<e; j++){
        if (set2[i] == set1[j]){
            found = 1;
            break;
        }
    }
    if (found==0){
        Result[l] = set2[i];
        l++;
    }
}

return l;
}
//function to find the intersection of sets
int find_intersection(int * set1, int m, int * set2, int n, int Result[]){
int i,j,l=0;
for(i=0; i<m; i++){
for(j=0; j<n; j++){
if (set1[i] == set2[j]){
Result[l] = set1[i];
l++;
}
}
}
return l;
}
//function to find the subtraction of sets
int find_subtraction(int * set1, int m, int * set2, int n, int Result[]){
int i,j,l=0,found;
cout<<"\n\n";
for(i=0; i<m; i++){
found=0;
for(j=0; j<n; j++){
if (set1[i] == set2[j]){
found=1;
break;
}
}
if(found==0){
Result[l]=set1[i];
l++;
}
}

for(i=0; i<n; i++){
int found=0;
for(j=0; j<m; j++){

if (set2[i] == set1[j]){
found=1;
break;
}
}
if(found==0){
Result[l]=set2[i];
l++;
}

}
return l;
}

//main
int main(){
//set a
int A[6] = {1,2,3,5,8,13};
//set b
    int B[10] = {1,3,5,7,9,11,13,15,17,19};
//set c
int C[9]={1, 2, 3, 5, 7, 11, 13, 17, 19};
//for overall size
int R[50];
//for n
int length;



// (A UNION B) INTERSECTION C
cout<<"--------------------------------------";
cout<<"\nSecond Problem: ";
length = find_union(A,6,B,10,R);
length = find_intersection(R,length,C,9,R);
cout<<"\n(B UNION C) INTERSECTION A : { ";
for(int i = 0; i < length; i++){
cout<<R[i]<<" ";
}
cout<<"}"<<endl;

}
