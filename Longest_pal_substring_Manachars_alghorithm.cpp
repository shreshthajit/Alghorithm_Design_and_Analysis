#include<bits/stdc++.h>

using namespace std;


char input[1000];

void longestPalindromicSubstringLinear()
{

int length=2*(strlen(input))+1;
int index = 0;
        //preprocess the input to convert it into type abc -> $a$b$c$ to handle even length case.
        //Total size will be 2*n + 1 of this new array.
        char newInput[length];/// = new char[2*input.length + 1];
        for(int i=0; i < length; i++)
        {
            if(i % 2 != 0)
            {
                newInput[i] = input[index++];
            } else
            {
                newInput[i] = '$';
            }
        }
        cout<<newInput<<endl;
        //create temporary array for holding largest palindrome at every point. There are 2*n + 1 such points.
        int T[length];/// = new int[newInput.length];
        int start = 0;
        int End = 0;
        //here i is the center.

        for(int i=0;i<length;i++)
        T[i]=0;

        for(int i=0; i < length;)
        {
            //expand around i. See how far we can go.
            while(start >0 && End < length-1 && newInput[start-1] == newInput[End+1])
            {
                start--;
                End++;
            }
            //set the longest value of palindrome around center i at T[i]
            T[i] = End - start + 1;

            //this is case 2. Current palindrome is proper suffix of input. No need to proceed. Just break out of loop.
            if(End == length -1)
            {
                break;
            }
            //Mark newCenter to be either end or end + 1 depending on if we dealing with even or old number input.
            int newCenter = End + (i%2 ==0 ? 1 : 0);

            for(int j = i + 1; j <= End; j++)
            {
                //i - (j - i) is left mirror. Its possible left mirror might go beyond current center palindrome. So take minimum
                //of either left side palindrome or distance of j to end.
                T[j] = min(T[i - (j - i)], 2 * (End - j) + 1);
                //Only proceed if we get case 3. This check is to make sure we do not pick j as new center for case 1 or case 4
                //As soon as we find a center lets break out of this inner while loop.
                if(j + T[i - (j - i)]/2 == End)
                {
                    newCenter = j;
                    break;
                }
            }
            //make i as newCenter. Set right and left to atleast the value we already know should be matching based of left side palindrome.
            i = newCenter;
            End = i + (T[i]/2);
            start = i - (T[i]/2);
        }
        //find the max palindrome in T and return it.
        int Max = 0;///Integer.MIN_VALUE;
        for(int i = 0; i < length; i++)
        {
            int val;
            val = T[i]/2;
            if(Max < val)
            {
                Max = val;
            }
       }
       cout<<Max<<endl;
}


int main(int argc, char *argv[]){

    string s;
    cin>>s;
    ///strcpy(input,"bbabxcxbabb");
    ///strcpy(input,s);
    for(int i=0;i<s.length();i++)
    input[i]=s[i];

    longestPalindromicSubstringLinear();
}
