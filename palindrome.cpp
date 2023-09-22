/*g
C++ Programming DC: Palindrome Checker

by Akhil Baidya 

(with help from Mr. Galbraith, Mr. Galbraith's videos on Canvas,

GeeksforGeeks - https://www.geeksforgeeks.org/type-conversion-in-c/#,

and Carnegie Mellon University - https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html) 


Date (mm/dd/yy): 9/21/23

Notes:
The user will input a series of characters after prompted to by the computer.
The computer will read a max of 80 characters (including non-alphanumeric characters)
and then print out whether the series is a palindrome or not. 

The non-alphanumeric characters will not be considered in whether the series of
characters is a palindrome (ex. tacocat and taco_!!cat are both palindromes)

WARNING - do not backspace when entering inputs, as these backspaces will be 
read by the computer as part of the input. 
*/


//INCLUDING: 
#include <iostream>
#include <cstring> //always use "cstrings" not strings!

using namespace std;

//MAIN FUNCTION (asks for input and prints out if it is palindrome or not):
int main(){


  //Variables:
  /*(source: help from Mr. Galbraith in clarifying that to read in "n" characters, I
    should set array sizes to n+1 due to null character also being read in) 
   */

  char input[81]; //this will contain the whole input
  char clean[81]; // this will only contain the alphanumeric characters
  int j = 0; //this will measure the number of alphanumeric characters

  
  //Get input:
  cout << "Please input something (don't backspace!). I will check if it is a palindrome." << endl;
  cin.get(input, 81);
  cin.get();


  //Keep only alphanumeric characters for cleaned cstring:
  for (int i = 0; i < strlen(input); i++) { //for all characters in input...

    /*(source: learned about string length, strlen(), from Mr. Galbraith)

      (source 2: learned how to typecast from char to int using (int) from GeeksforGeeks
      website at https://www.geeksforgeeks.org/type-conversion-in-c/#)

      (source  3: referenced Carnegie Mellons ASCII chart at
      https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
     */
    
    
    if ((int)input[i] >= 97 && (int)input[i] <= 122) {
      /*only selecting characters from input with ASCII value indicating that they are
	lower case alphabets*/
      
      clean[j] = input[i]; //move this character into the cleaned character array at position j
      j++; //set position j to the next spot in the cleaned array 
    }

    else if ((int)input[i] >= 48 && (int)input[i] <= 57) {
      /*repeat, but only selecting characters from input with ASCII value indicating that they are
       numbers*/
      
      clean[j] = input[i];
      j++;
    }

    else if ((int)input[i] >= 65 && (int)input[i] <= 90) {
      /*repeat, but only selecting characters from input with ASCII value indicating that they are
	upper case alphabets*/

      clean[j] = (char)((int)input[i] + 32); //add 32 to ASCII value to shift reference to upper case alphabets to lower case 
      j++;
     }
      
    else {
      cout << "exclude: " << input[i];
     }
    }
  
  clean[j] = '\0'; /*add null character after reading in needed characters into cleaned array (to help with cout - it will
  stop reading when reaching the null character, reading out the needed characters) */

  for (int k = 0; k < (j - (j%2))/2; k++) { /*for half the length of all the alphanumeric characters, j in number, in the cleaned
  array (subtracted j mod 2 from j such that half of odd numbers is the (length-1)/2) ... */

    if (clean[k] != clean[j-k-1]) { /*as soon as a value k steps into the series of alphanumerics does not equal a value k steps
    from the series' end ... */

      cout << "Not a palindrome" << endl; //it is not a palindrome!
      return 0;
    }
    
  }

  cout << "Palindrome!" << endl; //otherwise, if characters on each end match (and the for loop finishes), it is a palindrome
  return 0;
}
