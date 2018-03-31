#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int t,t1,t2,t3;
int max(int x,int y){
    if(y>x)//1
        return y;//1
    return x;
}

void left_diagonal(char** m,int n){
    int i,j,l1=1,ma,l2=1,curlen=1,start,kk;t3+=3;
	t3+=2;
    for(i=0;i<n;i++){
	    t3+=2;
        l1=1;l2=1;t3+=3;
        curlen=1;
		t3+=2;
        for(j=0;j<n-1 && i+j<n-1;j++){
		    t3+=2;
		    t3+=3;
            if(m[i+j][n-j-1]>=m[i+j+1][n-j-2])
            {
                t3++;
                l1++;
            }
            else
            {
                t3++;
                l1=1;
            }
		    t3+=3;
            if(m[i+j][n-j-1]<=m[i+j+1][n-j-2])
            {
                t3++;
                l2++;
            }
            else
            {
                t3++;
                l2=1;
            }
            ma=max(l1,l2);t3+=4;
		    t3+=1;
            if(ma>curlen){
                curlen=ma;t3++;
                start=j-ma+2;t3++;
            }
        }
        if(i==n-1)
        {
            printf("(%d,%d)%c\n",n-1,n-1,m[n-1][n-1]);
            
        }
        else
        {
            for(kk=0;kk<curlen;kk++){
                printf("(%d,%d)%c ",i+start+kk,n-start-kk-1,m[i+start+kk][n-start-kk-1]);
                if(kk!=curlen-1){
                    if(m[i+start+kk][n-start-kk-1]>m[i+start+kk+1][n-start-kk-2])
                    {
                        printf(" > ");
                    }
                    else if(m[i+start+kk][n-start-kk-1]<m[i+start+kk+1][n-start-kk-2])
                    {
                        printf(" < ");
                    }
                    else
                    {
                        printf(" = ");
                    }
                }
            }
            printf("\n");
        }
    }

	t3+2;
    for(i=1;i<n;i++){
        l1=1;l2=1;t3+=3;
        curlen=1;
	    t3+=2;
        for(j=0;j<n-1 && i+j<n-1;j++){
		    t3+=2;
		    t3+=3;
            if(m[j][n-j-1-i]>=m[j+1][n-j-2-i])
            {
                t3++;
                l1++;
            }
            else
            {
                t3++;
                l1=1;
            }
		    t3+=3;
            if(m[j][n-j-1-i]<=m[j+1][n-j-2-i])
            {
                t3++;
                l2++;
            }
            else
            {
                t3++;
                l2=1;
            }
            ma=max(l1,l2);t3+=4;
	        t3+1;
            if(ma>curlen){
                curlen=ma;t3++;
                start=j-ma+2;t3++;
            }
        }
        if(i==n-1)
        {
            printf("(0,0)%c\n",m[0][0]);
        }
        else
        {
            for(kk=0;kk<curlen;kk++){
                printf("(%d,%d)%c ",start+kk,n-start-kk-1-i,m[start+kk][n-start-kk-1-i]);
                if(kk!=curlen-1){
                    if(m[start+kk][n-start-kk-1-i]>m[start+kk+1][n-start-kk-2-i])
                    {
                        printf(" > ");
                    }
                    else if(m[start+kk][n-start-kk-1-i]<m[start+kk+1][n-start-kk-2-i])
                    {
                        printf(" < ");
                    }
                    else
                    {
                        printf(" = ");
                    }
                }
            }
            printf("\n");
        }
    }
}

void right_diagonal(char** m,int n){
    int i,j,l1=1,ma,l2=1,curlen=1,start,kk;t2+=3;
	t2+=2;
    for(i=0;i<n;i++){
	    t2+=2;
        l1=1;l2=1;t2+=3;
        curlen=1;
	    t2+=2;
        for(j=0;j<n-1 && i+j<n-1;j++){
		t2+=2;
		t2+=3;
            if(m[i+j][j]>=m[i+j+1][j+1])
            {
                t2++;
                l1++;
            }
            else
            {
                t2++;
                l1=1;//1
            }
		    t2+=3;
            if(m[i+j][j]<=m[i+j+1][j+1])//3
            {
                t2++;
                l2++;
            }
            else
            {
                t2++;
                l2=1;//1
            }
            ma=max(l1,l2);t2+=4;
	        t2+=1;
            if(ma>curlen){//1
                curlen=ma;t2++;
                start=j-ma+2;t2++;
            }
        }
        if(i==n-1)//1
        {
            printf("(%d,0)%c\n",n-1,m[n-1][0]);//2
        }
        else
        {
            for(kk=0;kk<curlen ;kk++){//2*n
                printf("(%d,%d)%c ",i+start+kk,kk+start,m[i+start+kk][kk+start]);//3
                if(kk!=curlen-1 ){//1
                    if(m[i+start+kk][kk+start]>m[i+start+kk+1][kk+start+1])//3
                    {
                        
                        printf(" > ");//1
                    }
                    else if(m[i+start+kk][kk+start]<m[i+start+kk+1][kk+start+1] )
                    {
                        
                        printf(" < ");//1
                    }
                    else
                    {
                        
                        printf(" = ");
                    }
                }
            }
            printf("\n");
        }
    }
	t2+=2;
    for(i=1;i<n;i++){
        l1=1;l2=1;t2+=2;
        curlen=1;t2+=1;
	    t2+=2;
        for(j=0;j<n-1 && i+j<n-1;j++){
		t2+=2;
		t2+=3;
            if(m[j][j+i]>=m[j+1][i+j+1])//3
            {
                t2++;
                l1++;//1
            }
            else
            {
                t2++;
                l1=1;
            }
		    t2+=3;
            if(m[j][j+i]<=m[j+1][i+j+1])//3
            {
                t2++;
                l2++;
            }
            else
            {
                t2++;
                l2=1;//1
            }
            ma=max(l1,l2);t2+=4;
		    t2+=1;
            if(ma>curlen){//1
                curlen=ma;t2++;
                start=j-ma+2;t2++;
            }
        }
        if(i==n-1 )//1
        {
            printf("(0,%d)%c\n",n-1,m[0][n-1]);
        }
     
        else
        {
            for(kk=0;kk<curlen;kk++){
                printf("(%d,%d)%c ",start+kk,i+kk+start,m[start+kk][i+kk+start]);
                if(kk!=curlen-1){//1
                    if(m[start+kk][i+kk+start]>m[start+kk+1][i+kk+start+1])//3
                    {
                        printf(" > ");
                    }
                    else if(m[start+kk][i+kk+start]<m[start+kk+1][i+kk+start+1])//3
                    {
                        printf(" < ");
                    }
                    else
                    {
                        printf(" = ");
                    }
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}
void Row_Max(char** m,int n){
    int i,j,l1=1,ma,l2=1,curlen=1,start;t1+=3;//5
    t1+=2;
    for(i=0;i<n;i++){//2*(n+1)
	t1+=2;
        l1=1;l2=1;t1+=3;
        curlen=1;//5
	t1+=2;
        for(j=0;j<n-1;j++){//n*2*n
		t1+=2;
		t1+=3;
            if(m[i][j]>=m[i][j+1])//12*(n-1)*n
            {
                l1++;
                t1++;
            }
            else
            {
                l1=1;t1++;
            }
	 	t1+=3;
            if(m[i][j]<=m[i][j+1] )
            {
                l2++;t1++;
            }
            else
            {
                l2=1;t1++;
            }
            ma=max(l1,l2);t1+=4;
		t1+=1;
            if(ma>curlen){//(n-1)*n
                curlen=ma;t1++;//3*n//(n-1)*n
                start=j-ma+2;t1++;
            }
        }
        int kk;
        for(kk=0;kk<curlen ;kk++){
            printf("(%d,%d)%c ",i,kk+start,m[i][kk+start]);
            if(kk!=curlen-1 ){
                if(m[i][kk+start]>m[i][kk+start+1])
                {
                    printf(" > ");
                    //t++;
                }
                else if(m[i][kk+start]<m[i][kk+start+1])//3
                {
                    printf(" < ");//t++;
                }
                else
                {
                    printf(" = ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
   
}
int main(int argc, char **argv)
{
    srand(time(0));
    char **m;
    char s[5];
    //FILE *fp1=fopen("average_row.txt","a"),*fp2=fopen("average_diagonal.txt","a"),*fp=fopen("average.txt","a");

    int n,i,j,x=0;
    //n=atoi(argv[1]);
    printf("Enter size of matrix N=");
    scanf("%d",&n);
    m=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
        m[i]=(char*)malloc(n*sizeof(char));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //m[i][j]='a' +rand()%26;
            //printf("%d",i*3+j);
            scanf("%s",s);
            m[i][j]=s[0];
        }

    }   
    //t=0,t1=0,t2=0,t3=0;
    printf("\nRows\n");
    Row_Max(m,n);
    printf("\nDiagonals from right to left\n");
    right_diagonal(m,n);
    printf("Diagonals from left to right\n");
    left_diagonal(m,n);
    // fprintf(fp1,"%d\t%d\n",n,t1);
    // fprintf(fp2,"%d\t%d\n",n,t2+t3);
    // //fprintf(fp3,"%d\t%d\n",n,t3);
    // fprintf(fp,"%d\t%d\n",n,t1+t2+t3);
    // fclose(fp1);
    // fclose(fp2);

    // fclose(fp);
    // fp1=fopen("best_row.txt","a"),fp2=fopen("best_diagonal.txt","a"),fp=fopen("best.txt","a");
    //  for(i=0;i<n;i++){
	//     x=0;
    //     for(j=0;j<n;j++){
    //         m[i][j]='a' + x%2;
    //         x++;
    //     }

    // }   
    // t=0,t1=0,t2=0,t3=0;
    // Row_Max(m,n);
    // right_diagonal(m,n);
    // left_diagonal(m,n);
    // fprintf(fp1,"%d\t%d\n",n,t1);
    // fprintf(fp2,"%d\t%d\n",n,t2+t3);
    // fprintf(fp,"%d\t%d\n",n,t1+t2+t3);
    // fclose(fp1);
    // fclose(fp2);
    // fclose(fp);
    // fp1=fopen("worst_row.txt","a"),fp2=fopen("worst_diagonal.txt","a"),fp=fopen("worst.txt","a");
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         m[i][j]='a';
    //     }

    // }   
    // t=0,t1=0,t2=0,t3=0;
    // Row_Max(m,n);
    // right_diagonal(m,n);
    // left_diagonal(m,n);
    // fprintf(fp1,"%d\t%d\n",n,t1);
    // fprintf(fp2,"%d\t%d\n",n,t2+t3);
    // fprintf(fp,"%d\t%d\n",n,t1+t2+t3);
    // fclose(fp1);
    // fclose(fp2);
    // fclose(fp);
    return 0;
}
