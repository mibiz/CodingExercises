#include <iostream>
#include <sstream>
#include <cstring>
#include "cppunit/TestFixture.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TextTestRunner.h"
#include "cppunit/TextOutputter.h"
using namespace std;

/**
 * The program prints the numbers from 1 to 100, one per line. But for multiples
 * of three it prints "Fizz" instead of the number, and for the multiples of five it prints "Buzz". 
 * For numbers which are multiples of both three and five it prints "FizzBuzz".
 */
void FizzBuzz() {
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

/** Test the FizzBuzz function by redirecting its stdout to a
 *  private string buffer. We will then test the contents of this
 *  buffer if it has the correct output.
 */
class TestFizzBuzz : public CppUnit::TestFixture {
private:
    stringstream oss;
    streambuf* tmp_cout_buf;
    
public:
    TestFizzBuzz() {}
    
    void setUp() {
        //redirect cout to oss
        tmp_cout_buf = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());
    }
    
    void testFizzBuzz() {
        FizzBuzz();
        int t;
        string s;
        //read the first line into integer
        oss >> t;
        CPPUNIT_ASSERT( t == 1 );
        //read the second line into integer
        oss >> t;
        CPPUNIT_ASSERT (t == 2);
        //the third line should say "Fizz"
        oss >> s;
        CPPUNIT_ASSERT( s == "Fizz" );
        oss >> t;
        CPPUNIT_ASSERT( t == 4 );
        oss >> s;
        //fifth line should say "Buzz"
        CPPUNIT_ASSERT( s == "Buzz" );
    }
    
    void tearDown() {
        //un-redirect cout
        cout.rdbuf(tmp_cout_buf);
    }
};

int main (int argc, char** argv) {
    CppUnit::Test *test = new CppUnit::TestCaller<TestFizzBuzz>( "testFizzBuzz", &TestFizzBuzz::testFizzBuzz );
    CppUnit::TextTestRunner runner;
    runner.addTest(test);
    runner.run();
    return 0;
}
