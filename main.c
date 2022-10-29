#include <stdio.h>
#include <stdlib.h>





int main()
{

    int N=101;
    int matA[N][N]; // tape matrix
    int matB[N];    // vector column
    int B[N];       // helping vector B
    int N1 = N-1;
    int y, a[N],  matRes[N]; // helping vector A, result, y...

    int i = 0;
    FILE *f;
    int flag = 1;
    char name[25];

   // system("chcp 1251"); // for win version
    printf( "Enter A file name\n");
    printf( "  : ");
    scanf("%s",name);
    if ((f = fopen(name,"r"))==NULL)
       {printf("  .");
	    system("PAUSE");
	    return 0;}
	int n,m,j;
	int **x = NULL;
    fscanf(f,"%d%d",&n,&m);
	x = (int **) malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	   x[i] = (int*)malloc(sizeof(int)*m);
	for(i=0;i<n;i++)
       for (j=0;j<m;j++)
          fscanf(f,"%d",&x[i][j]);
    fclose(f);
    printf(" : \n");
    for(i=0;i<n;i++){
      for (j=0;j<m;j++)
          {   matA[i][j] = x[i][j];
              printf("%3d", x[i][j]);}
      printf("\n"); }
//    system("PAUSE");

    free(x);
    printf("Show matA");
    for(i=0;i<n;i++){
      for (j=0;j<m;j++)
          {
              printf("%3d", matA[i][j]);}
               printf("\n");

              }
    printf( "Enter B file name\n");
    printf( "  : ");
    scanf("%s",name);
    if ((f = fopen(name,"r"))==NULL)
       {printf("  .");
	   // system("PAUSE");
	    return 0;}

	int *xb = NULL;
    fscanf(f,"%d",&n);
	xb = (int *) malloc(sizeof(int)*n);
	 for (j=0;j<m;j++)
          fscanf(f,"%d",&xb[j]);
    fclose(f);
    printf(" : \n");
    for(i=0;i<n;i++){
               matB[i] = xb[i];
              printf("%3d\n", xb[i]);}

//    system("PAUSE");

    free(xb);
    printf("Show matB");
    for (j=0;j<m;j++)
          {
              printf("%3d\n", matB[j]);}

    /*---------------------matrix math---------------------*/


    y = matA[0][0];
    a[0] = -matA[0][1]/y;

    for (int i=1; i<N1;i++)
    {
        y = matA[i][i] + matA[i][i-1]*a[i-1];
        a[i] = -matA[i][i+1]/y;
        B[i] = (matB[i]-matA[i][i-1]*B[i-1])/y;
    }

    matRes[N1] = (matB[N1]-matA[N1][N1-1]*B[N1-1])/(matA[N1][N1]+matA[N1][N1-1]*a[N1-1]);

    for (int i=N1-1;i>=0;i--)
    {
        matRes[i] = a[i]*matRes[i+1]+B[i];
    }
    printf("Output resulting matrix matRes:\n");
    for (j=0;j<m;j++)
          {
              printf("%3d\n", matRes[j]);}

    printf( "Element X40 = %d\n",matRes[40]);
    printf( "Element X60 = %d\n",matRes[60]);
    printf( "Element X88 = %d\n",matRes[88]);
    
    return 0;
}
