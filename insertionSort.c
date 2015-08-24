#include<stdio.h>

void main(void){
	int alist[]={4,3,21,3,12,345,23,65,8,23,4,8};
	int index, currentValue, position, i;
	int length=sizeof(alist)/sizeof(alist[0]);
	
	for(index=1;index<length;index++){
	   currentValue= alist[index];
	   position=index;
	   while(position>0 && alist[position-1]>currentValue){
			   alist[position]=alist[position-1];
			   alist[position-1]=currentValue;
			   position=position-1;
		   }
	  }
	
	for(i=0;i<length;i++){
		printf("%d ",alist[i]);
	}
}
