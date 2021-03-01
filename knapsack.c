# include<stdio.h>
# include<conio.h>

void knapsack(int n, float w[], float p[], float m)
{
 float x[20], t= 0;
 int i, j;
 

 for (i=0;i<n;i++)
     x[i]=0.0;

 for (i=0;i<n;i++)
 {
 if(w[i]>m)
      break;
 else
     {
     x[i]=1.0;
     t= t+p[i];
     m=m-w[i];
     }
 }

 if(i<n)
       x[i]=m/w[i];

 t= t + (x[i]*p[i]);

 printf("Result:- \n ");
 for(i=0;i<n;i++)
        printf("%f\t",x[i]);

 printf("\nMax profit:-\n  %f", t);

}

void main()
{
 float w[20], p[20], m;
 int n, i ,j;
 float r[20], temp;


 printf ("Enter the total no. of objects:-\n  ");
 scanf ("%d", &n);

 printf ("Enter weights and profits:-\n ");
 for (i=0; i<n; i++)
 {
 scanf("%f %f", &w[i], &p[i]);
 }

 printf ("Enter capacity:-\n ");
 scanf ("%f", &m);

 for (i=0; i<n; i++)
 {
 r[i]=p[i]/w[i];
 }

 for(i=0; i<n; i++)
 {
    for(j=i+1;j< n; j++)
    {
      if(r[i]<r[j])
      {
      temp= r[j];
      r[j]= r[i];
      r[i]= temp;

     temp= w[j];
     w[j]= w[i];
     w[i]= temp;

     temp= p[j];
     p[j]= p[i];
     p[i]= temp;
     }
   }
 }

 knapsack(n, w, p, m);

}
