#include <iostream>
using namespace std;

/**
 * The program prints the numbers from 1 to 100, one per line. But for multiples
 * of three it prints "Fizz" instead of the number, and for the multiples of five it prints "Buzz". 
 * For numbers which are multiples of both three and five it prints "FizzBuzz".
 */
int main(int argc, char** argv) {
    int i;
    int mul_three = 3;
    int mul_five = 5;
    
        for (i = 1; i < 101; i++) {
			if ((i != mul_three) && (i != mul_five)) {
				cout << i << endl;
			}
			else {
				if(i == mul_three) {
					cout << "Fizz";
					mul_three+= 3;
				}
				if(i == mul_five) {
					cout << "Buzz";
					mul_five+= 5;
				}
				cout << endl;
			}
        }

}