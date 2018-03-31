#include <stdio.h>
#include <stdlib.h>
int main()
{
	    FILE *fp1=fopen("average_row.txt","w"),*fp2=fopen("average_diagonal.txt","w"),*fp=fopen("average.txt","w");
	    fclose(fp1);fclose(fp2);fclose(fp);
	    fp1=fopen("best_row.txt","w"),fp2=fopen("best_diagonal.txt","w"),fp=fopen("best.txt","w");
	    fclose(fp1);fclose(fp2);fclose(fp);
	    fp1=fopen("worst_row.txt","w"),fp2=fopen("worst_diagonal.txt","w"),fp=fopen("worst.txt","w");
	    fclose(fp1);fclose(fp2);fclose(fp);
	int n=2;
	while((n<=10))
	{
		system("gcc c.c -o daa");
		char command[120];
		char var[100];
		sprintf(var,"%d",n);
		sprintf(command,"./daa %s",var);
		system(command);
		n+=1;
	}
	system("gnuplot -p 'row_plot.txt'");
	//system("gnuplot -p 'left_diagonal_plot.txt'");
	system("gnuplot -p 'diagonal_plot.txt'");
	system("gnuplot -p 'total_plot.txt'");
}
