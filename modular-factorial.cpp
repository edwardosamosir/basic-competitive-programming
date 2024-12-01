/*
    Question: Implement  n! mod k  Using Modular Arithmetic
    
    Write a program in C++ to compute  n! mod k , where  n!  (factorial of  n ) is defined as the product of all positive integers up to  n :
    n! = n x (n-1) x (n-2) x \ldots x 1
    
    Constraints:

	1.	Use the modular arithmetic property:
    
    (a×b) mod m = ((a mod m)×(b mod m)) mod m
    
    to ensure the intermediate results are kept within manageable bounds and to optimize calculations.

	2.	Take  n  and  k  as inputs from the user.
	3.	 k  must be a positive integer ( k > 0 ).

    Example Input and Output:

    	•	Input:
            Enter n: 5
            Enter k: 3
        
        •	Output:
            n! mod k = 0

        •	Explanation:
            5! = 120
            120 mod 3 = 0

        •	Input:
            Enter n: 4
            Enter k: 7

        •	Output:
            n! mod k = 3

        •	Explanation:
            4! = 24
            24 mod 7 = 3


 */

#include<iostream>
#include <cmath>
#include <chrono>
using namespace std;


int main(){
    int n, k;

    // Input values for n and k
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    // Validate inputs
    if(k <= 0){
        cout << "k must be a positive integer." << endl;
        return 1;
    }

    // Compute factorial modulo k
    long long result = 1;
    for (int i = 1; i <= n; i++){
        result = (result * i) % k;
        if(result == 0) break;
    }
    
    // Output the result
    cout << "n! mod k = " << result << endl;

    return 0;
}

/*
Test Case 1:  n = 5 ,  k = 3 

Calculation of  5! mod 3 :
	•	Step 1:  1 mod 3 = 1 
	•	Step 2:  (1 x 2) mod 3 = 2 
	•	Step 3:  (2 x 3) mod 3 = 0 
	•	Step 4:  (0 x 4) mod 3 = 0 
	•	Step 5:  (0 x 5) mod 3 = 0 

Explanation:
	•	Once the intermediate result becomes  0  in Step 3, the subsequent calculations remain  0  due to the property of modular arithmetic. 
    The final answer is  0 .

Test Case 2:  n = 4 ,  k = 3 

Calculation of  4! mod 3 :
	•	Step 1:  1 mod 3 = 1 
	•	Step 2:  (1 x 2) mod 3 = 2 
	•	Step 3:  (2 x 3) mod 3 = 0 
	•	Step 4:  (0 x 4) mod 3 = 0 

Explanation:
	•	Similar to the previous case, the intermediate result becomes  0  in Step 3, making the final result  0  after Step 4.

Test Case 3:  n = 4 ,  k = 5 

Calculation of  4! mod 5 :
	•	Step 1:  1 mod 5 = 1 
	•	Step 2:  (1 x 2) mod 5 = 2 
	•	Step 3:  (2 x 3) mod 5 = 6 mod 5 = 1 
	•	Step 4:  (1 x 4) mod 5 = 4 

Explanation:
	•	The multiplication up to Step 3 results in  1  when  6 mod 5  is evaluated.
	•	The final result after Step 4 is  4 .

Test Case 4:  n = 4 ,  k = 7 

Calculation of  4! mod 7 :
	•	Step 1:  1 mod 7 = 1 
	•	Step 2:  (1 x 2) mod 7 = 2 
	•	Step 3:  (2 x 3) mod 7 = 6 
	•	Step 4:  (6 x 4) mod 7 = 24 mod 7 = 3 

Explanation:
	•	After multiplying up to Step 3, the result is  6 , and after the final multiplication in Step 4, we find that  24 mod 7 = 3 .

General Explanation:

The program uses modular arithmetic at each step to ensure the intermediate results remain within bounds. The rule used is:


(a x b) mod m = ((a mod m) x (b mod m)) mod m


This approach helps to prevent integer overflow and keeps calculations efficient. Each multiplication step is followed by the modulo operation, 
ensuring that the result is always reduced within the range of  0  to  k-1 .
*/