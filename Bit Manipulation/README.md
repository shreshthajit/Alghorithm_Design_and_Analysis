 # Bit manipulation
***
## [Bit manipulation](https://drive.google.com/file/d/1qMRk6YeAsqsNigk0xWLxlckKuTexcEUS/view)
 ## set1.
 -----------
 ### 1. How to set a bit in the number ‘num’ :
 


If we want to set a bit at nth position in number ‘num’ ,it can be done using ‘OR’ operator( | ). 

First we left shift ‘1’ to n position via (1<<n)
Then, use ‘OR’ operator to set bit at that position.’OR’ operator is used because it will set the bit even if the bit is unset previously in binary representation of number ‘num’.
 ```
  

 #include<iostream>
using namespace std;
// num is the number and pos is the position
// at which we want to set the bit.
void set(int & num,int pos)
{
	// First step is shift '1', second
	// step is bitwise OR
	num |= (1 << pos);
}
int main()
{
	int num = 4, pos = 1;
	set(num, pos);
	cout << (int)(num) << endl;
	return 0;
}
We have passed the parameter by ‘call by reference’ to make permanent changes in the number.
```

### 2.How to unset/clear a bit at n’th position in the number ‘num’ : 
Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.

First we left shift ‘1’ to n position via (1<<n) than we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position position.
```
#include <iostream>
using namespace std;
// First step is to get a number that has all 1's except the given position.
void unset(int &num,int pos)
{
	//Second step is to bitwise and this number with given number
	num &= (~(1 << pos));
}
int main()
{
	int num = 7;
	int pos = 1;
	unset(num, pos);
	cout << num << endl;
	return 0;
}

```
### 3.Toggling a bit at nth position :
Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.We will be using ‘XOR’ operator
here which is this ‘^’. The reason behind ‘XOR’ operator is because of its properties. 

Properties of ‘XOR’ operator:

1^1 = 0

0^0 = 0

1^0 = 1

0^1 = 1

If two bits are different then ‘XOR’ operator returns a set bit(1) else it returns an unset bit(0).
```
#include <iostream>
using namespace std;
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num,int pos)
{
	num ^= (1 << pos);
}
int main()
{
	int num = 4;
	int pos = 1;
	toggle(num, pos);
	cout << num << endl;
	return 0;
}
```
### 4. Checking if bit at nth position is set or unset:

It is quite easily doable using ‘AND’ operator.
Left shift ‘1’ to given position and then ‘AND'(‘&’).
```
#include <iostream>
using namespace std;

bool at_position(int num,int pos)
{
	bool bit = num & (1<<pos);
	return bit;
}

int main()
{
	int num = 5;
	int pos = 0;
	bool bit = at_position(num, pos);
	cout << bit << endl;
	return 0;
}

Observe that we have first left shifted ‘1’ and then used ‘AND’ operator to get bit at that position. So if there is ‘1’ at position ‘pos’ in ‘num’, then after ‘AND’ our variable ‘bit’ will store ‘1’ else if there is ‘0’ at position ‘pos’ in the number ‘num’ than after ‘AND’ our variable bit will store ‘0’.
```
### 5.Inverting every bit of a number/1’s complement: 

If we want to invert every bit of a number i.e change bit ‘0’ to ‘1’ and bit ‘1’ to ‘0’.We can do this with the help of ‘~’ operator. For example : if number is num=00101100 (binary representation) so ‘~num’ will be ‘11010011’.
```
#include <iostream>
using namespace std;
int main()
{
	int num = 4;

	// Inverting every bit of number num
	cout << (~num);
	return 0;
}
```
### 6.Two’s complement of the number: 
2’s complement of a number is 1’s complement + 1.
So formally we can have 2’s complement by finding 1s complement and adding 1 to the result i.e (~num+1) or what else we can do is using ‘-‘ operator.
```
#include <iostream>
using namespace std;
int main()
{
	int num = 4;
	int twos_complement = -num;
	cout << "This is two's complement " << twos_complement << endl;
	cout << "This is also two's complement " << (~num+1) << endl;
	return 0;
}
```
### 7.Stripping off the lowest set bit :
In many situations we want to strip off the lowest set bit for example in Binary Indexed tree data structure, counting number of set bit in a number.
We do something like this: 
``X = X & (X-1)``
But how does it even work ?
Let us see this by taking an example, let X = 1100.
(X-1)  inverts all the bits till it encounter lowest set ‘1’ and it also invert that lowest set ‘1’.
X-1 becomes 1011. After ‘ANDing’ X with X-1 we get lowest set bit stripped.
```
#include <iostream>
using namespace std;
void strip_last_set_bit(int &num)
{
	num = num & (num-1);
}
int main()
{
	int num = 7;
	strip_last_set_bit(num);
	cout << num << endl;
	return 0;
}
```
### 8.Getting lowest set bit of a number:
This is done by using expression ‘X &(-X)’Let us see this by taking an example:Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ and 2’s complement will be (~X+1 or -X) i.e  ‘11010100’.So if we ‘AND’ original number ‘X’ with its two’s complement which is ‘-X’, we get lowest set bit. 
 ```
   00101100
&  11010100

   00000100
   
#include <iostream>
using namespace std;
int lowest_set_bit(int num)
{
	int ret = num & (-num);
	return ret;
}
int main()
{
	int num = 10;
	int ans = lowest_set_bit(num);
	cout << ans << endl;
	return 0;
}

```

### 9.Division by 2 and Multiplication by 2 are very frequently that too in loops in Competitive Programming so 
## using Bitwise operators can help in speeding up the code.

Divide by 2 using right shift operator:

00001100 >> 1 (00001100 is 12)
------------
00000110 (00000110 is 6)

```
#include <iostream>
using namespace std;
int main()
{
	int num = 12;
	int ans = num>>1;
	cout << ans << endl;
	return 0;
}
```

### 10.Multiply by 2 using left shift operator:
00001100 << 1 (00001100 is 12)
------------
00011000 (00000110 is 24)

```
#include <iostream>
using namespace std;
int main()
{
	int num = 12;
	int ans = num<<1;
	cout << ans << endl;
	return 0;
}

```
---------------------
# set2
------
We have considered below facts in this article:

* 0 based indexing of bits from right to left.

*  Setting i-th bit means, turning i-th bit to 1

* Clearing i-th bit means, turning i-th bit to 0

### 1) Clear all bits from LSB to ith bit 

mask = ~((1 << i+1 ) - 1);

x &= mask;

Logic: To clear all bits from LSB to i-th bit, we have to AND x with mask having LSB to i-th bit 0. To obtain such mask, first left shift
1 i times. Now if we minus 1 from that, all the bits from 0 to i-1 become 1 and remaining bits become 0. Now we can simply take complement
of mask to get all first i bits to 0 and remaining to 1. 
Example- 
x = 29 (00011101) and we want to clear LSB to 3rd bit, total 4 bits 

mask -> 1 << 4 -> 16(00010000) 

mask -> 16 – 1 -> 15(00001111) 

mask -> ~mask -> 11110000 

x & mask -> 16 (00010000)

### Clearing all bits from MSB to i-th bit 
 
mask = (1 << i) - 1;

x &= mask;
###  Divide by 2:

x >>= 1;
Logic: When we do arithmetic right shift, every bit is shifted to right and blank position is substituted with sign bit of number,
0 in case of positive and 1 in case of negative number. Since every bit is a power of 2, with each shift we are reducing the value of 
each bit by factor of 2 which is equivalent to division of x by 2. 
Example- 

x = 18(00010010) 

x >> 1 = 9 (00001001)

### Multiplying by 2 

Logic: When we do arithmetic left shift, every bit is shifted to left and blank position is substituted with 0.Since every bit 
is a power of 2, with each shift we are increasing the value of each bit by a factor of 2 which is equivalent to multiplication of x by 2. 
Example.

x = 18(00010010) 

x << 1 = 36 (00100100)


x <<= 1;


5) Upper case English alphabet to lower case 
 
ch |= ' ';

Logic: The bit representation of upper case and lower case English alphabets are – 
 

A -> 01000001          a -> 01100001

B -> 01000010          b -> 01100010

C -> 01000011          c -> 01100011
  .                               
  .
  .                               
  .
Z -> 01011010          z -> 01111010

As we can see if we set 5th bit of upper case characters, it will be converted into lower case character.We have to prepare a mask having
5th bit 1 and other 0 (00100000). This mask is bit representation of space character (‘ ‘). The character ‘ch’ then ORed with mask.
Example- 
ch = ‘A’ (01000001) 

mask = ‘ ‘ (00100000) 

ch | mask = ‘a’ (01100001) 

### Lower case English alphabet to upper case 
 

ch &= '_’ ;

### Logic: The bit representation of upper case and lower case English alphabets are – 
 

A -> 01000001                a -> 01100001

B -> 01000010                b -> 01100010

C -> 01000011                c -> 01100011

.                               
.
.                               
.
Z -> 01011010                z -> 01111010

As we can see if we clear 5th bit of lower case characters, it will be converted into upper case character. We have to prepare a 
mask having 5th bit 0 and other 1 (10111111). This mask is bit representation of underscore character (‘_‘). The character ‘ch’ then AND with mask. 
Example- 
ch = ‘a’ (01100001) 

mask = ‘_ ‘ (11011111) 

ch & mask = ‘A’ (01000001) 

### Count set bits in integer 
```
int countSetBits(int x)
{
	int count = 0;
	while (x)
	{
		x &= (x-1);
		count++;
	}
	return count;
}
```
### Find log base 2 of 32 bit integer 
```
int log2(int x)
{
	int res = 0;
	while (x >>= 1)
		res++;
	return res;
}

```
### Find log base 2 of 32 bit integer 
```
int log2(int x)
{
	int res = 0;
	while (x >>= 1)
		res++;
	return res;
}

```
Logic: We right shift x repeatedly until it becomes 0, meanwhile we keep count on the shift operation. This count value is the log2(x).

### Checking if given 32 bit integer is power of 2 
```
int isPowerof2(int x)
{
	return (x && !(x & x-1));
}
```
### Logic:
All the power of 2 have only single bit set e.g. 16 (00010000). If we minus 1 from this, all the bits from LSB to set bit get toggled, i.e., 16-1 = 15 (00001111). Now if we AND x with (x-1) and the result is 0 then we can say that x is power of 2 otherwise not. We have to take extra care when x = 0.
Example 
x = 16(000100000) 

x – 1 = 15(00001111) 

x & (x-1) = 0 

so 16 is power of 2
---------------------
The Quickest way to swap two numbers: 
 
a ^= b;

b ^= a; 

a ^= b;

