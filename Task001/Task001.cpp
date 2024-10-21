#include "pch.h"
#include "CppUnitTest.h"

//minh duc nguyen - 9002756 - f24- section 2 -asn2 
extern "C" int getPerimeter(int*length ,int*width );
extern "C" int getArea(int* length, int* width); 
extern "C" void setLength(int input, int* length); 
extern "C" void setWidth(int input, int* width); 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task001
{
	TEST_CLASS(Task1)
	{
	public:
		
		TEST_METHOD(getPerimeterFunctionality) 
		{ 
			// this is testing the get perimeter function 
			int lengthIntValue  = 1;
			int widthIntValue  = 2;
			int* length = &lengthIntValue  ; // int *length is a pointer => assign address of value 
			int* width = &widthIntValue  ;

			int ExpectedResult = 4;  // 1+1+2 = 4 
			int RealResult = getPerimeter(length, width); 

			Assert::AreEqual(ExpectedResult , RealResult ); 

		}
		TEST_METHOD(getAreaFunctionality) {
			// this is testing the get area function 
			int lengthIntValue  = 1;
			int widthIntValue   = 2;
			int* length = &lengthIntValue  ; // int *length is a pointer => assign address of value 
			int* width = &widthIntValue    ;

			int ExpectedResult  = 2;    // 1*2 = 2 
			int RealResult  = getArea(length, width);

			Assert::AreEqual(ExpectedResult , RealResult );
		} 
	};
	TEST_CLASS(Task2) {
    public: 

	

        // test for setLength function 

        //test case : input valid limit of length 
         TEST_METHOD(ValidLimitOfSetLength)
         {
         int ValidLimitlength = 0;  
         int* length = &ValidLimitlength; // int* length is a pointer = > assign address of value

         setLength(17, length);  
         Assert::AreEqual(17, ValidLimitlength );
         }

         // test case : input is lower boundary 
          TEST_METHOD(LowerBoundaryOfSetLength)
          {
           int LowerBoundarylength  = -1;  // assign to an invalid value
           int* length = &LowerBoundarylength ;// int* length is a pointer = > assign address of value

           setLength(0, length); 
           Assert::AreEqual(0, LowerBoundarylength );  // make sure length is set to 0
          }

            // test case : input out of range 
           TEST_METHOD(OutOfRangeOfSetLength)
           {
            int OutOfRangelength  = 101;  // assign to an invalid value
            int* length = &OutOfRangelength;// int* length is a pointer = > assign address of value

            setLength(100, length);  
            Assert::AreNotEqual(100, OutOfRangelength);  // make sure  length remains unchanged
           }

           // test for setWidth function 

              //test case : input valid limit of length 
           TEST_METHOD(ValidLimitOfSetLengt)
           {
           int ValidLimitWidth = 0;
           int* width  = &ValidLimitWidth;  // assign to an invalid value

           setWidth(25, width );  
           Assert::AreEqual(25, ValidLimitWidth);  
           }

            // test case: upper boundary 
           TEST_METHOD(UpperBoundaryOfSetWidth)
           {
            int UpperBoundaryWidth = 0;
            int* width = &UpperBoundaryWidth;

             setWidth(100, width); 
             Assert::AreEqual(100, UpperBoundaryWidth);  
           }

            // test case :  invalid input 
           TEST_METHOD(InvalidInputOfSetWidth)
           {
           int InvalidWidth = 99;  // assign to a valid value
           int* width = &InvalidWidth; 

           setWidth(-1, width);  
           Assert::AreEqual(99, InvalidWidth);  
           }
    };
}











	