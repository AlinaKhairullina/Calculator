# Calculator 
***
**A logical calculator that introduces operations &&, ||, ! , brackets and all integers.**
----------
**The calculator consists of two programs : translator and calculator itself**
---
* The translator which changes the original entered expression into a postfix expression.
*     Example : 2 || 4 && 1 --> 4 1 && 2 ||
  File "main1.c" changes original expression into a postfix expression.
  To run main1.c you need the file using Makefile from catalog "src".
  
* Calculator, which calculates the value of an expression using postfix notation.
   File main2.c calculates the value.
  
