#include<stdio.h>

void printArray(int A[], int len){
        int i;
	for(i=0;i<len;i++) 
	  printf("%d ",A[i]);
	printf("\n");
}

void quickSort(int alist[], int len){
	        int pivot=alist[0];
		int i=1,j=len-1,temp;
			        
		printf("Splitting:");
		printArray(alist,len);
						
		if (len>1){		
			while(i<j){
	   		   if(alist[i]<=pivot && i<len)
				i++;
			   else{
				temp=alist[i];
	                   
			        if(alist[j]>=pivot && j>=0)
				             j--;
	                        else{
		                       alist[i]=alist[j];
		                       alist[j]=temp;
	                        }
		           }
		         }
                         alist[0]=alist[j-1];
                         alist[j-1]=pivot;		

	                 int m,n,L[j],R[len-j];

	                 for(m=0;m<j;m++)
           		       L[m]=alist[m];
            	         for(n=0;n<(len-j);n++)
                	       R[n]=alist[j+n];
               	         quickSort(L,j);
    	                 quickSort(R,len-j);

  			 int k;
  			 for(k=0;k<len;k++){
				alist[k]=L[k];
				if(k>=j){
   				     alist[k]=R[k-j];}
			}
			 printf("Merging:"); 
	 		 printArray(alist,len);
	
		}
}

void main(void){
	int alist[]={32,54,2,1,23,41,56342,123,3,33,34,5,2,87};
	int len=sizeof(alist)/sizeof(alist[0]);
	quickSort(alist,len);
				        
}
