#include<stdio.h>

void main(void){
      int alist[]={12,42,5321,3,3,12,54,7632,54321};
      int length=sizeof(alist)/sizeof(alist[0]);
      int increment,start,index,i,position,currentValue;
      
      increment=4;
      while(increment>0){
        for(start=0;start<increment;start++){
	      for(index=start; index<length; index=index+increment){
		 
		  position=index+increment;
		  if(position<length){
		    currentValue=alist[position];
		    while(position>0 && alist[position]<alist[position-increment]){
		            alist[position]=alist[position-increment];
			    alist[position-increment]=currentValue;
			    position=position-increment;
			}
		  }
	    }
        }
	increment--;
    }
      for(i=0;i<length;i++){
	      printf("%d ",alist[i]);
      }
}

