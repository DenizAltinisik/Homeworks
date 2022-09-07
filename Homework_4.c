#include <stdio.h>
FILE *fp;
FILE *fpa;
int main(){
int selection;
do{
printf("\033[0;31m");
printf("Select an operation...\n");
printf("\033[0m");
printf("0 -> Enter the coefficients. \n");
printf("1 -> Draw the graph.\n");
printf("2 -> Print the graph into a .txt file. \n");
printf("3 -> Exit. \n");
printf("\n");
printf("Choice: ");

scanf("%d",&selection);

if(selection==0){
int a,b,c;
fp=fopen("coefficients.txt","w");
if(fp==NULL){				// warn user if file does not exist
printf("File does not exist!");
}
printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n");
printf("a: ");
scanf("%d",&a);
fprintf(fp,"%d\n",a);
printf("b: ");
scanf("%d",&b);
fprintf(fp,"%d\n",b);
printf("c: ");
scanf("%d",&c);
fprintf(fp,"%d",c);
fclose(fp);
printf("coefficients.txt file has been created.\n");
}



if(selection==1){
printf("Coefficients has been read from coefficients.txt file.\n");
int x,y,i,ellibes=55;
int a1,b1,c1;
int x1,y1;

fp=fopen("coefficients.txt","r");
fscanf(fp,"%d",&a1);
fscanf(fp,"%d",&b1);
fscanf(fp,"%d",&c1);

fclose(fp);

printf("Printing the graph of ");
printf("\033[0;33m");
printf("x=%d*(y*y) + %d*y + %d",a1,b1,c1);
printf("\033[0m");
printf("\n\n\n");
for(int b=0;b<111;b++){		// "b" loop for showing y letter
	printf(" ");
	if(b==55){
	printf("y");
	}
}
printf("\n");

for(i=0;i<111;i++){		// "i" loop for y axis upper arrow
	printf(" ");
	if(i==55){
	printf("^");
	}
}
printf("\n");
for(y=15;y>=(-15);y--){   // our coordinate system
	if(y!=0){
	for(x=-55;x<=55;x++){
	     if(x!=(a1*y*y + b1*y + c1)){
		printf(" ");
		
		if(y==-1){
			if(x==-50){
			printf("\033[0;36m");
			printf("%d",x);
			printf("\033[0m");
			}
			if(x==-40 || x==-30 || x==-20 || x==-10){
			printf("\033[0;36m");
			printf("\b\b\b%d",x);
			printf("\033[0m");
			}
			if(x==0){
		
			printf("\033[0;36m");
			printf("\b\b\b\b%d",x);
			printf("\033[0m");
				
			}
			if(x==10 ||x==20 || x==30 ||x==40 ||x==50){
			printf("\033[0;36m");
			printf("\b\b%d",x);
			printf("\033[0m");
			}
		}
		if(x==0 && y!=0){
		 	
			if(x<=(a1*y*y + b1*y + c1)){
			printf("|");
			}
			else if(a1>=0){ 
			printf("\b|");	
		 	}
		 	else printf("|");
		 		
				
				
				if(y==15 || y==10 || y==-5){          // y axis numbers
				printf("\033[0;36m");
				printf("\b\b\b%d",y);
				printf("\033[0m");
				printf("|");
				}
				if(y==-10 || y==-15){
				printf("\033[0;36m");
				printf("\b\b\b\b%d",y);			// y axis numbers
				printf("\033[0m");
				printf("|");
				}
				if(y==5){					// y axis numbers
				printf("\033[0;36m");
				printf("\b\b%d",y);
				printf("\033[0m");
				printf("|");
				}
			
			
		}	
	  	
	  }
	  	
	  else if(x>0){
	  
	  printf("\033[0;33m");	
	  printf("#");
	  printf("\033[0m");
	  }
	  else if(x==0 ){ 
	  /*
	  printf("\b");
	  printf("\033[0;36m");
	  printf("%d",y);
	  printf("\033[0m");
	 */
	  printf("\033[0;33m");	
	  printf(" #");
	  printf("\033[0m");
	  }
	  else if(y==-1){
	  	
	  		if(a1<0){
		  	printf("\b");
		  	}
		  	printf("\033[0;33m");
		  	printf("\b\b#");
		  	printf("\033[0m");
		  	printf("   ");
		  	
		 
	  }
	  else{ 
	  	if(a1<0){
	  	printf("\b");
	  	}
	  printf("\033[0;33m");
	  printf(" #");	
	  printf("\033[0m");
	  }
	}
	
   
   }
   
   	
	printf("\n");
	if(y==1){
		printf("<");
		for(int x_line=-55;x_line<=55;x_line++){
		   if(x_line!=(c1)){
			printf("-");
			}
		   else{ 
		   printf("\033[0;33m");
		   printf("#");
		   printf("\033[0m");
		   }	
		}
		printf("> x");	
	
	}
	

}

 }
 
if(selection==2){  // write to graph
fpa=fopen("graph.txt","w");
	int x,y,i;
int a1,b1,c1;
int x1,y1;

fp=fopen("coefficients.txt","r");
fscanf(fp,"%d",&a1);
fscanf(fp,"%d",&b1);
fscanf(fp,"%d",&c1);

fclose(fp);
printf("Coefficients has been read from coefficients.txt file.\n");
printf("The graph of ");
printf("\033[0;33m");
printf("x=%d*(y*y) + %d*y + %d",a1,b1,c1);
printf("\033[0m");
printf(" has been written to graph.txt file.");
printf("\n\n\n");

fprintf(fpa,"\n\n");

for(i=0;i<111;i++){		// "i" loop for y axis upper arrow
	fprintf(fpa," ");
	if(i==55){
	fprintf(fpa,"^");
	}
}
fprintf(fpa,"\n");
for(y=15;y>=(-15);y--){   // our coordinate system
	if(y!=0){
	for(x=-55;x<=55;x++){
	     if(x!=(a1*y*y + b1*y + c1)){
		fprintf(fpa," ");
		
		
		if(x==0 && y!=0){
		 	
			if(x<(a1*y*y + b1*y + c1)){
			fprintf(fpa,"|");
			}
			else if(a1>=0){ 
			fprintf(fpa,"|");	
		 	}
		 	else fprintf(fpa,"|");
			
			
		}	
	  	
	  }
	  
	  else if(x>0){
	  	
	  fprintf(fpa,"#");
	  
	  }
	  else if(y==-1){
	  	x=x+1;
	  
	  fprintf(fpa," #");
	  
	  
	  }
	  else{ 
	  	x=x+1;
	  
	  fprintf(fpa," #");	
	  
	  }
	}
   
   }
   
   	
	fprintf(fpa,"\n");
	if(y==1){
		fprintf(fpa,"<");
		for(int x_line=-55;x_line<=55;x_line++){
		   if(x_line!=(c1)){
			fprintf(fpa,"-");
			}
		   else{ 
		   
		   fprintf(fpa,"#");
		   
		   }	
		}
		fprintf(fpa,"> x");	
	
	}
	

}



fclose(fpa);
 
 } 
}
while(selection!=3);


return 0;
}
