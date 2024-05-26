#include <stdio.h>
#include <stdlib.h>

typedef struct Complex{
    float realpart;                                 /* 实部 */
    float imagpart;                                 /* 虚部 */
} Complex;                                          /* 定义复数抽象类型 */

void assign(Complex *A, float real, float imag);    /* 赋值 */
void add(Complex *c, Complex A, Complex B);         /* A + B */
void minus(Complex *c, Complex A, Complex B);       /* A - B */
void multiply(Complex *c, Complex A, Complex B);    /* A * B */
void divide(Complex *c, Complex A, Complex B);      /* A / B */

void assign(Complex *A, float real, float imag)
{
    A->realpart = real;                             /* 实部赋值 */
    A->imagpart = imag;                             /* 虚部赋值 */
} /* End of assign() */
void add(Complex *c, Complex A, Complex B)          /* c = A + B */
{
    c->realpart = A.realpart + B.realpart;          /* 实部相加 */
    c->imagpart = A.imagpart + B.imagpart;          /* 虚部相加 */
} /* End of add() */
void minus(Complex *c, Complex A, Complex B)        /* c = A - B */
{
    c->realpart = A.realpart - B.realpart;          /* 实部相减 */
    c->imagpart = A.imagpart - B.imagpart;          /* 虚部相减 */
} /* End of minus() */
void multiply(Complex *c, Complex A, Complex B)     /* c = A * B */
{
    c->realpart = A.realpart * B.realpart;          /* 实部相乘 */
    c->imagpart = A.imagpart * B.imagpart;          /* 虚部相乘 */
} /* End of multiply() */
void divide(Complex *c, Complex A, Complex B)       /* c = A / B */
{
    c->realpart = A.realpart / B.realpart;          /* 实部相除 */
    c->imagpart = A.imagpart / B.imagpart;          /* 虚部相除 */
} /* End of divide() */

/*
 *       ( 8 + 6i )( 4 + 3i )
 * z = -------------------------
 *      ( 8 + 6i ) + ( 4 + 3i )
 */

void main()
{
    Complex z1, z2, z3, z4, z;
    float RealPart, ImagPart;
    assign(&z1, 8.0, 6.0);
    assign(&z2, 4.0, 3.0);
    add(&z3, z1, z2);
    multiply(&z4, z1, z2);
}