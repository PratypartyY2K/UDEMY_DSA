/*
Given a list of 'n' strings S0,S1,S2,......,Sn-1, each consisting of digits and spaces, the number of spaces is the same for each entyry, the goal is to implement a variation of a sort command.

None of the string contains consecutive spaces.

Also, no string starts with a spaces nor ends with it.

Spaces are used to divide string into columns, which can be used as keys in comparisons.

The program has to support the required parameters:

key: integer denoting the column used as akey in comparisions. The left-most column denoted by 1.

reversed: boolean variable indicating whether to reverse the result of comparisions.

comparision-type: either lexicographic or numeric.
                  
                Lexicographic means that we use lexicographical order where for example (122<13).

                Numeric means that we compaer the strings by their numeric values, so (13<122). 
                
                If the comparision type is 'numeric' ad numeric values of keys of Si and Sj are equal for i<j, then Si is considered strictly smaller than Sj because it comes first.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;