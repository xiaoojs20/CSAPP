/* 
 * CS:APP Data Lab 
 * xiaojinsong 2020010563
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x>>(n<<3))&0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask = ~(((1<<31)>>n)<<1);
  return (x>>n) & mask; 
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int by_2, by_4, by_8, by_16, by_32;
  int add;
  by_2 = 0x55 | (0x55<<8); //0x5555
	by_2 = by_2 | (by_2<<16); //0x55555555
	by_4 = 0x33 | (0x33<<8);
	by_4 = by_4 | (by_4<<16);
	by_8 = 0x0F | (0x0F<<8);
	by_8 = by_8 | (by_8<<16);
	by_16 = 0xFF | (0xFF<<16);
	by_32 = 0xFF | (0xFF<<8);
  add = (x&by_2) + ((x>>1)&by_2);
  add = (add&by_4) + ((add>>2)&by_4);
  add = (add&by_8) + ((add>>4)&by_8);
  add = (add&by_16) + ((add>>8)&by_16);
  add = (add&by_32) + ((add>>16)&by_32);
  // printf("%d\n%d\n%d\n%d\n%d\n",by_2,by_4,by_8,by_16,by_32);
  // printf("a new term \n%d\n", add);  
  return add;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int signOR = ((x | (~x+1)) >> 31) & 0x01;
  return ~signOR & 0x01;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int minusOne = ~1+1;
  int highBitNotSame = (x>>(n+minusOne)) ^ (x>>31);
  return !highBitNotSame;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int minusOne = ~1+1;
  int offset = (0x01<<n)+minusOne;
  int sign = x>>31;
  offset &= sign;
  // printf("%d\n", (x+offset)>>n);
  return (x+offset)>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  int notNeg = !(x>>31);
  int isZero = !x;
  // printf("notNeg: %d\nisZero: %d\nisPositive: %d\n", notNeg, isZero, (notNeg ^ isZero));
  return notNeg ^ isZero;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int z = y + (~x+1);
  int sign = !(z>>31); // sign should be 1, when z >= 0.
  int xNeg = (x>>31)& 0x01;
  int yNeg = (y>>31)& 0x01;
  int notSame = xNeg ^ yNeg;
  sign = (~notSame & sign) | (notSame & xNeg);
  // printf("same: %d\t",!notSame);
  // printf("isLessOrEqual: %d\n",sign);
  return sign;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int shift=0;
  // shift = ((!!(x>>16))<<31>>31)&16;
  // // printf("%d\n",shift);
  // shift += ((!!(x>>(8+shift)))<<31>>31)&8;
  // // printf("%d\n",shift);
  // shift += ((!!(x>>(4+shift)))<<31>>31)&4;
  // // printf("%d\n",shift);
  // shift += ((!!(x>>(2+shift)))<<31>>31)&2;
  // // printf("%d\n",shift);
  // shift += ((!!(x>>(1+shift)))<<31>>31)&1;
  // // printf("%d\n",shift);

  shift = ((!!(x>>16))<<4);
  // printf("%d\n",shift);
  shift += ((!!(x>>(8+shift)))<<3);
  // printf("%d\n",shift);
  shift += ((!!(x>>(4+shift)))<<2);
  // printf("%d\n",shift);
  shift += ((!!(x>>(2+shift)))<<1);
  // printf("%d\n",shift);
  shift += ((!!(x>>(1+shift))));
  return shift;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int expMask = 0x7F800000;
  int fracMask = 0xFF800000;
  int expAllOne = uf & expMask;
  int fracZero = uf | fracMask;
 
  if(expAllOne == expMask && !(fracZero == fracMask))//NaN
    return uf;
  else 
    return uf^0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int tempx=x, absx=x, discarded=0;
  int sign=0;
  int exp=0, frac=0;
  int sigOne=1<<31;
  if(x==0)
    return 0;
  else if(x==(1<<31))
    return 0xCF000000;
  else if(x<0){
    absx=-x;
    tempx=-x;
    sign=sigOne;
  }
  // printf("tempx: %d\n",tempx);
  while((tempx&sigOne)==0){
    exp+=1;
    tempx<<=1;
  }
  exp=31-exp;
  // printf("exp-bias: %d\n",exp);
  frac=absx-(1<<exp);
  // printf("frac: %d\n",frac);
  if(exp<=23){
    frac=frac<<(23-exp);
  }
  else{
    frac=frac>>(exp-23);
    discarded=tempx&0xFF;
    if(discarded>0x80 || ((discarded==0x80) && (frac&1))){
      frac+=1;
    }
  }
  exp=(exp+127)<<23;
  // printf("sign: %d\nexp: %d\nfrac: %d\nfloat: %d\n",sign,exp,frac,sign+exp+frac);
  return sign+exp+frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int sign = uf&0x80000000;
  int exp = uf&0x7F800000;
  int frac = uf&0x007FFFFF;
  int expAllZero = (exp == 0);
  int expAllOne = (exp == 0x7F800000);
  int twiceExpAllOne = (exp == 0x7F000000);
  if(expAllOne) ///Nan or Inf
    return uf;
  if(!expAllZero){ //normalized
    if(twiceExpAllOne)
      return sign+0x7F800000;
    else
      return uf+0x00800000;
  }
  //denormalized
  frac<<=1;
  return sign+exp+frac;
}


// int main(){
//   printf("xiaojs20\n");
//   // float_twice(5);
//   // float_i2f(5);
//   // float_i2f(-5);
//   /*1084227584
// -1063256064*/
// /*sign: 0
// exp: 1082130432
// frac: 2097152
// float: 1084227584
// sign: -2147483648
// exp: 1082130432
// frac: 2097152
// float: -1063256064*/
//   return 0;
// }