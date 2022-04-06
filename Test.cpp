#include "doctest.h"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

TEST_CASE("GOOD INPUT")
{
    /*
        in all the cases "I" is short for the identity matrix.
        I<number> means an identity matrix of size <number>
        <number>I means an identity matrix with a diagonal made out of <number> (default 1)
    */
    SUBCASE("+")
    {
        vector<double> I4Vector = {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
        Matrix I4{I4Vector, 4, 4};
        
        for (int i = 1; i <= 150; i++)
        {
            vector<double> iI4Vector = {
                (double)i,0,0,0, 
                0,(double)i,0,0,
                0,0,(double)i,0,
                0,0,0,(double)i
            };
            Matrix iI4{iI4Vector,4,4};
            CHECK(iI4 == I4);
            if(i%2 == 0)
            {
                I4++;
            }
            else
            {
                ++I4;
            }
        }
        
        Matrix I4_2{I4Vector, 4, 4};
        for (int i = 0; i < 150; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(I4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + I4_2);
            }
        }
        
        vector<double> X4 = {
            5.15, 0, 0, 5.15,
            0, 5.15, 5.15, 0,
            0, 5.15, 5.15, 0,
            5.15, 0, 0, 5.15
        };
        Matrix x4_1{X4, 4, 4};
        Matrix x4_2{X4, 4, 4}; 
        for (int i = 0; i < 150; i++)
        {
            if(i%2 == 0)
            {
                CHECK_NOTHROW(x4_1 + x4_2);
            }
            else
            {
                CHECK_NOTHROW(x4_2 + x4_1);
            }
        }

        vector<double> M2x2Vector = {
            3.14, 2.71,
            1.41, 1.61
        };
        Matrix M2x2{M2x2Vector, 2, 2};
        
        CHECK(M2x2 == +M2x2);
        
        M2x2+=5;
        
        CHECK(M2x2 == Matrix{vector<double>{8.14,7.71,6.41,6.61}, 2, 2});
    }

    SUBCASE("-")
    {
        vector<double> I4Vector = {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
        Matrix I4_1{I4Vector, 4, 4};
        
        for (int i = 1; i > 20; i--)
        {
            vector<double> iI4Vector = {
                (double)i,0,0,0, 
                0,(double)i,0,0,
                0,0,(double)i,0,
                0,0,0,(double)i
            };
            Matrix iI4{iI4Vector,4,4};
            CHECK(iI4 == I4_1);
            if(i%2 == 0)
            {
                I4_1--;
            }
            else
            {
                --I4_1;
            }
        }
        
        Matrix identity4x4_2{I4Vector, 4, 4};
        for (int i = 0; i < 100; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(identity4x4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + identity4x4_2);
            }
        }
        
        vector<double> x4 = {
            1.33, 0, 0, 1.33,
            0, 1.33, 1.33, 0,
            0, 1.33, 1.33, 0,
            1.33, 0, 0, 1.33
        };
        Matrix x4_1{I4Vector, 4, 4};
        Matrix x4_2{I4Vector, 4, 4}; 
        for (int i = 0; i < 150; i++)
        {
            if(i%2 == 0)
            {
                CHECK_NOTHROW(x4_1 + x4_2);
            }
            else
            {
                CHECK_NOTHROW(x4_2 + x4_1);
            }
        }
        
        vector<double> M2x2Vector = {
            3.14, 2.71,
            1.41, 1.61
        };
        vector<double> minusM2x2Vector = {
            -3.14, -2.71,
            -1.41, -1.61
        };
        Matrix M2x2{M2x2Vector, 2, 2};
        Matrix minusM2x2{minusM2x2Vector, 2, 2};
        
        CHECK(M2x2 == -M2x2);

        M2x2 -= 5;
        CHECK(M2x2 == Matrix{vector<double>{-2.14,-3.71,-4.41,-4.61}, 2, 2});
    }
    SUBCASE("*")
    {
        vector<double> identity =  {
            1,0,0,0, 
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
        for (int i = 1; i <= 150; i++)
        {
            vector<double> iI4Vector = {
                (double)i,0,0,0, 
                0,(double)i,0,0,
                0,0,(double)i,0,
                0,0,0,(double)i
            };
            
            Matrix iI4{identity,4,4};
            
            if(i%2 == 0)
            {
                iI4*i;
            }
            else
            {
                i*iI4;
            }
            CHECK(iI4 == Matrix{iI4Vector,4,4});
        }

         vector<double> X4Vector = {
            1.33, 0, 0, 1.33,
            0, 1.33, 1.33, 0,
            0, 1.33, 1.33, 0,
            1.33, 0, 0, 1.33
        };
        Matrix X4_1{X4Vector, 4, 4};
        Matrix X4_2{X4Vector, 4, 4};
        for (int i = 0; i < 15; i++)
        {
            if(i%2 == 0)
            {
                CHECK_NOTHROW(X4_1 * X4_2);
            }
            else
            {
                CHECK_NOTHROW(X4_2 * X4_1);
            }
        }
    }
    SUBCASE("/")
    {
        vector<double> I4Vector =  {
            1,0,0,0, 
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
        for (int i = 1; i <= 150; i++)
        {
            vector<double> iI4Vector = {
                (double)i,0,0,0, 
                0,(double)i,0,0,
                0,0,(double)i,0,
                0,0,0,(double)i
            };
            
            Matrix I4{I4Vector,4,4};
            
            if(i%2 == 0)
            {
                I4/i;
            }
            else
            {
                i/I4;
            }
            CHECK(I4 == Matrix{iI4Vector,4,4});
        }
    }
}

TEST_CASE("BAD INPUT")
{
    vector<double> I4Vector = {
        1,0,0,0, 
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };
    Matrix I4{I4Vector, 4, 4};
        
    vector<double> I3Vector = {
        1,0,0, 
        0,1,0,
        0,0,1
    };
    Matrix I3{I3Vector, 3, 3};
    SUBCASE("mat + mat")
    {   
        CHECK_THROWS(I3 + I4);
        CHECK_THROWS(I4 + I3);
    }
    SUBCASE("mat - mat")
    {
        CHECK_THROWS(I3 - I4);
        CHECK_THROWS(I4 - I3);
        
    }
    SUBCASE("mat * mat")
    {
        CHECK_THROWS(I3 * I4);
        CHECK_THROWS(I4 * I3);
    }
    SUBCASE("mat / scalar OR scalar / mat")
    {
        CHECK_THROWS(I3 / 0);
        CHECK_NOTHROW(0 / I4);
    }
}