#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int INF_SET = -1;
int solutions(double a, double b, double c, double &x1, double &x2);

int main(){
    printf("# Enter a, b, c: ");
    double a = 0,
           b = 0,
           c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    double x1 = 0,
           x2 = 0;
    int INT_SET = -1;

    switch(solutions(a, b, c, x1, x2)){
        case 0:       printf("No roots\n");
                      break;
        case 1:       printf("One solution: x = %lg\n", x1);
                      break;
        case 2:       printf("Two solutions: x1 = %lg\n               x2 = %lg\n", x1, x2);
                      break;
        case INF_SET: printf("Any roots\n");
                      break;
        default:   printf("ERROR\nSomething went wrong\n");
                      break;
    }
    return 0;
}

int solutions(double a, double b, double c, double &x1, double &x2){

    if(a == 0){
        if(b == 0){
            return (c == 0)? INF_SET : 0;
        }
        else{
            x1 = -c / b;
            return 1;
        }
    }
    else{
        double D = b*b - 4*a*c;
        if(D == 0){
            x1 = x2 = -b / (2*a);
            return 1;
        }
        else if(D < 0){
            return 0;
        }
        else{
            x1 = (-b + sqrt(D)) /(2*a);
            x2 = (-b - sqrt(D)) /(2*a);
            return 2;
        }
    }

    return 0;
}
