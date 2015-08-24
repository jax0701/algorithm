#include<stdio.h>

void main(void){
   int alist[]={4,6,7,2,3,44,12,100,1,32,34,1523};
   int positionOfMax, temp, location, i;
   int length=sizeof(alist)/sizeof(alist[0]);
   int index=length-1;
   
   do{
	   positionOfMax=0;
	   for(location=1;location<=index; location++){
		   if (alist[location]>alist[positionOfMax]){
			   positionOfMax=location;
			   }
	   }
	   temp=alist[index];
	   alist[index]=alist[positionOfMax];
	   alist[positionOfMax]=temp;

           index--;
      }while(index>=0);  
   
   for(i=0; i<=(length-1);i++){
	   printf("%d ",alist[i]);} 
  } 
   

