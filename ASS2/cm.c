#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp1=fopen("average.txt","w"),*fp2=fopen("best.txt","w"),*fp=fopen("worst.txt","w");
	fclose(fp1);fclose(fp2);fclose(fp);
	int n=0;
	system("gcc code_graphs.c -o daa");
	while(n<=100)
	{
		char command[120];
		char var[100];
		sprintf(var,"%d",n);
		sprintf(command,"./daa %s",var);
		system(command);
		n+=5;
	}
	system("gnuplot -p 'plot.txt'");
	
}
