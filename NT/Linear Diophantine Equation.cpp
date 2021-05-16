A Linear Diophantine Equation is an equaltion of the general form
ax + by = c
5x + 3y = 24

The generate cases :
we need to take care of the case where a=b=0

There are 2 subcase:
1. c=0 then there are infinite solutions
2.c!=0 the solution is 0

To find the solution of LDA we need to know about Extended euclidean algho.
 
Extended euclidean alghorithm can be used to find the solution of the form ax+by=gcd(a,b)
  
so to find the solution of ax + by = c first we need to find the solution of ax + by=gcd(a,b)
  
if x0,y0 is the solution of the equation ax+by=g
then the solution of the equation of ax+by=c will be x=x0*(c/g) and y=y0*(c/g)
  
so ax0 + by0 = g  as x0 and y0 is the solution
   a*(x0*c/g)+b*(y0*c/g)=g*c/g  multiplying by c/g in both side
   a*(x0*c/g)+b*(y0*c/g)=c
   so x=x0*c/g 
   y=y0*c/g as the solution of the equation ax+by=c
      
   ax0 + by0 =g always have integer solution
   
