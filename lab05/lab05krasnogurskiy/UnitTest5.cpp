#include "pch.h"
#include "CppUnitTest.h"
#include"..//lab05/polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
	TEST_CLASS(UnitTest5)
	{
	public:
		
        TEST_METHOD(BasicTest)
        {
            std::string expression = "(4-2)^((-3) + 5) * (tg4)+1";
            std::string rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Assert::AreEqual(rpolish_calculate(rpolish_expression), (double)(4 * tan(4) + 1));
            Assert::AreNotEqual(rpolish_calculate(rpolish_expression), (double)(4 * (tan(4) + 1)));
        }

        TEST_METHOD(TestTrigonometry)
        {
            std::string expression = "(sin3)";
            std::string rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Logger::WriteMessage("\n");
            Assert::AreEqual(rpolish_calculate(rpolish_expression), sin(3));

            expression = "(sin3) + (cos2) + (tg1) + (ctg2)";
            rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Assert::AreEqual(rpolish_calculate(rpolish_expression), sin(3) + cos(2) + tan(1) + (float)1 / tan(2));
        }

        TEST_METHOD(TestUnaryMinus)
        {
            std::string expression = "7 + (-4)";
            std::string rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Logger::WriteMessage("\n");
            Assert::AreEqual(rpolish_calculate(rpolish_expression), (double)3);
            Assert::AreNotEqual(rpolish_calculate(rpolish_expression), (double)11);

            expression = "(-4) + 5";
            rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Logger::WriteMessage("\n");
            Assert::AreEqual(rpolish_calculate(rpolish_expression), (double)1);
            Assert::AreNotEqual(rpolish_calculate(rpolish_expression), (double)9);

            expression = "7 + (-4) * 3";
            rpolish_expression = rpolish(expression);
            Logger::WriteMessage(rpolish_expression.c_str());
            Assert::AreEqual(rpolish_calculate(rpolish_expression), (double)-5);
            Assert::AreNotEqual(rpolish_calculate(rpolish_expression), (double)19);
            Assert::AreNotEqual(rpolish_calculate(rpolish_expression), (double)9);
        }
	};
}
