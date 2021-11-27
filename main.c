#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define eps 0.0001

unsigned int method_select(void);
double wq(double x);
void print_result (double a,double b,unsigned int n,double I);
double left_rectangle(double a,double b,unsigned int n);
double right_rectangle(double a,double b,unsigned int n);
double trap(double a,double b,unsigned int n);
double simpson(double a,double b,unsigned int n);



int main()
{

   unsigned int num_of_method;
   double const a = 0;
   double const b = 1;
   unsigned int n =10000;
   double I;
   double I1, I2;
   unsigned int N;




  num_of_method =  method_select();

  if  (num_of_method == 1){
    I = left_rectangle(a,b,n);
    print_result(a,b,n,I);

  N = 0;
       do{
           N = N + 2;
           I1 = left_rectangle(a, b, N);
           I2 = left_rectangle(a, b, N+2);
        }while(  fabs(I2-I1) > eps );

        printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);
  }

    else if( num_of_method == 2 ){
        I=right_rectangle(a, b, n);
        print_result(a,b,n,I);


               do{
           N = N + 2;
           I1 = right_rectangle(a, b, N);
           I2 = right_rectangle(a, b, N+2);

    }while(  fabs(I2-I1) > eps );

   printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);


  }

      else if( num_of_method == 3 ){
          I=trap(a,b,n);
          print_result(a,b,n,I);

               do{
           N = N + 2;
           I1 = trap(a, b, N);
           I2 = trap(a, b, N+2);


           printf("\n\nN=%u, I1(N)=%.8lf\n", N, I1);

      }while(  fabs(I2-I1) > eps );
      }

      else if( num_of_method == 4 ){
          I=simpson(a, b, n);
          print_result(a,b,n,I);


               do{
           N = N + 2;
           I1 = simpson(a, b, N);
           I2 = simpson(a, b, N+2);


           printf("\n\nN=%u,  I1(N)=%.8lf\n", N, I1);

          }while(  fabs(I2-I1) > eps );

         }
  }

unsigned int method_select(void)
{
    unsigned int temp;

    printf("\n\n Choose your method:\n1 - left \n2 - right \n3 - trap \n4 - Simpson\n>");
    scanf("%u", &temp);

    while(  temp < 1  ||   temp > 4 ){
        printf("\n!!!!Invalid data. Method: 1, 2, 3 or 4: ");
        scanf("%u", &temp);
    }

    switch(temp){
      case 1:
             printf("\nYou chose method of LEFT RECTANGLE");
             break;

      case 2:
             printf("\nYou chose method of RIGHT RECTANGLE");
             break;

      case 3:

             printf("\nYou chose method of TRAPEZOID");
             break;

      case 4:
             printf("\nYou chose method of SIMPSON");
             break;
    }


    return temp;
}


double wq(double x)
{
    double y;

    y = x*exp(pow(x,2));

    return y;
}

double left_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int p;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (p = 0;  p <= n-1;  p++ ){
      sum = sum + (wq(x)/2 *4);
      x = x + h;
    }

   return sum * h;
}


double right_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int t;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (t = 0;  t <= n-1;  t++ ){
      sum = sum + (wq(x)/2 );
      x = x + h;
    }

   return sum * h;
}




double trap(double a, double b, unsigned int n)
{
    double h;
    unsigned int w;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for (w = 0;  w <= n-1;  w++ ){
      sum = sum + (wq(x) *4);
      x = x + h;
    }

   return sum * h;
}


double simpson(double a, double b, unsigned int n)
{
    double h;
    unsigned int s;
    double x;
    double I = 0;

    h = ( b - a ) / n;
    x = a + h;

    while (x < b){
        I +=4*wq(x);
         x +=h;
         if (x > b)
         {

         I+=2*wq(x);
         x += h;
         }
    }


   return I * h;
}


void print_result(double a, double b, unsigned int n, double I)
{
    system("cls");
    printf("\n***********************");
    printf("\n*       Results       *");
    printf("\n***********************\n");

    printf("a=%.2lf  b=%.2lf   n=%u    I = %.8lf", a, b, n, I);


}


