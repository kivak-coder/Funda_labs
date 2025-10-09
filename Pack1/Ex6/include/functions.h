typedef enum ReturnCode {
    NULL_POINTER,
    OK
} ReturnCode;

double FuncA(double x);
double FuncB(double x);
double FuncC(double x);
double FuncD(double x);
ReturnCode trapezoidMethod(double eps, double a, double b, double * res, double (*func)(double));
