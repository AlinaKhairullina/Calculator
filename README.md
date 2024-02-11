# Calculator 
***
**A logical calculator that introduces operations &&, ||, ! , brackets and all integers.**
---
**The calculator consists of two programs : translator and calculator itself**
---
* The translator which changes the original entered expression into a postfix expression.
*     Example: 2 || 4 && 1 --> 4 1 && 2 ||
  File "translator.c" changes original expression into a postfix expression.
  To run "translator.c" you need the file using Makefile from catalog "src".
  
* Calculator, which calculates the value of an expression using postfix notation.
*     Example: 4 1 && 2 || --> Answer 1
   File "calculator.c" calculates the value.
---
* In "lib" you can see the file "translator.h" with names of functions used in translator.c.
* In "src" you can see the file "trans.c" with functions used in translator.c.

