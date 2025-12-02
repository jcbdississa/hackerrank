/****************************************************************************************************
 * Source : https://www.hackerrank.com/challenges/prettyprint/problem?isFullScreen=true
 * 
 * Problem : Given a text file with many lines of numbers to format and print, for each row of 3
 *           space-separated doubles, format and print the numbers using the specifications in the
 *           Output Format section below.
 *           For each test case, print 3 lines containing the formatted A, B, and C, respectively.
 *           Each A, B, and C must be formatted as follows:
 *           1. A : Strip its decimal (i.e., truncate it) and print its hexadecimal representation
 *              (including the 0x prefix) in lower case letters.
 *           2. B : Print it to a scale of 2 decimal places, preceded by a + or - sign (indicating if
 *              it's positive or negative), right justified, and left-padded with underscores so that
 *              the printed result is exactly 15 characters wide.
 *           3. C : Print it to a scale of exactly nine decimal places, expressed in scientific
 *              notation using upper case
 *****************************************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        
        // cout<<setw(0)<<resetiosflags(ios_base::dec|ios_base::uppercase)
        //     <<setiosflags(ios_base::hex|ios_base::showbase)
        //     <<(int64_t)A<<endl;

        // cout<<setw(15)<<setfill('_')<<setprecision(2)
        //     <<resetiosflags(ios_base::internal|ios_base::scientific)
        //     <<setiosflags(ios_base::showpos|ios_base::fixed)<<B<<endl;
        
        // cout<<setprecision(9)<<resetiosflags(ios_base::showpos|ios_base::fixed)
        //     <<setiosflags(ios_base::scientific|ios_base::uppercase)<<C<<endl;


        cout<<setw(0)<<nouppercase<<showbase<<hex<<(int64_t)A<<endl;                   // The formatting is done from right to left
                                                                                       // 1. (int64_t) because the hexadecimal flag does not work on double
                                                                                       // 2. hex : display in hexadecimal
                                                                                       // 3. showbase: display "0x" or "0X" before the number and given
                                                                                       //    that we also have nouppercase, we'll then display "0x"
                                                                                       // 4. nouppercase : display in lowercase  
                                                                                       // 5. setw: set the widht of the number

        cout<<setw(15)<<setprecision(2)<<right<<showpos<<fixed<<setfill('_')<<B<<endl; // 1. setfill : filling caracter when width is larger the number
                                                                                       // 2. fixed : to format decimal numbers
                                                                                       // 3. showpos: display the "+" sign for positive number
                                                                                       // 4. right: put the number on the right and the filling characters
                                                                                       //    if required on the left
                                                                                       // 5. setprecision : using this with "fixed" will set the number of 
                                                                                       //    decimal digits (given by the argument of setprecision) i
                                                                                       //    setprecision if used alone, it gives the total number of digits
                                                                                       //    of the number

        cout<<setprecision(9)<<noshowpos<<uppercase<<scientific<<C<<endl;              // 1. scientific: display in scientific notation
                                                                                       // 2. uppercase: will display the E character in uppercase
                                                                                       // 3. noshowpos: do not display the "+" sign for positive number
    }

	return 0;
}

/*
Input example
100.998 2006.008 2331.41592653498
*/