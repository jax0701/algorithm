#include<stdio.h>

void main(void){
   int alist[]={1,4,23,43,11,25,78,9,100,87};
   int passnum,j,i, temp;
   int length=sizeof(alist)/sizeof(alist[0]);
   
   for(passnum=0; passnum<=(length-1); passnum++){
	   for(i=0; i<=(length-passnum-1); i++){
		   if(alist[i]>alist[i+1]){
		       temp=alist[i];
		       alist[i]=alist[i+1];
		       alist[i+1]=temp;
		   }
	      }
   }

   for(j=0; j<length; j++){
	   printf("%d ",alist[j]);
   }
   printf("%d\n", alist);
}
