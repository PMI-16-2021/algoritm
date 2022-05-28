#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр7/markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(MarkovTest) {
	public:
		TEST_METHOD(TestFind) {
			String str1 = "123456789";
			String str2 = "12";

			Assert::AreEqual(str1.Find(str2), 0);

			String str3 = "1234567890";
			String str4 = "89";
			Assert::AreEqual(str3.Find(str4), 7);
		}
		TEST_METHOD(TestReplace) {
			String str1 = "123456789";
			String str2 = "34";
			String str3 = "";

			str1.Replace(str2, str3);
			String str_help = "4";

			Assert::AreEqual(str1.Find(str2), -1);
			Assert::AreEqual(str1.Find(str_help), -1);

			String str5 = "123456789";
			String str6 = "678";
			String str7 = "rty";

			str5.Replace(str6, str7);
			String str_help_1 = "t";
			Assert::AreNotEqual(str5.Find(str_help_1), 7);
		}
		TEST_METHOD(TestEqual) {
			String from_char = "mamont";
			String from_string = from_char;
			String from_char2 = "mamont";

			bool ret_val = true;

			ret_val &= from_char == from_string;
			ret_val &= from_string == from_char2;
			ret_val &= from_char == from_char2;
			ret_val &= from_string == "mamont";
			ret_val &= !(from_string == "mamonts");
			ret_val &= !(from_string == "mamant");
			Assert::IsTrue(ret_val);
		}
		TEST_METHOD(TestOperatorPlus) {
			String mam("mam");
			String onts("onts");
			String mamonts;
			mamonts = mam + onts;
			bool ret_val = true;
			ret_val &= mamonts == "mamonts";
			Assert::IsTrue(ret_val);
		}
		TEST_METHOD(TestLength) {
			String mam("mam");
			String onts("onts");
			String mamonts;
			mamonts = mam + onts;

			Assert::AreEqual(mamonts.leng(), size_t(7));

			String mar("mar");
			String kov("kov");
			String markov;
			markov = mar + kov;

			Assert::AreNotEqual(markov.leng(), size_t(7));
		}
		TEST_METHOD(TestBinToDec) {
			String mama("111");
			String papa("101");
			rules_for_bin_to_dec r;
			String result("|||||||");
			Assert::IsTrue(mama.for_bin_to_dec(r) == result);
		}
		TEST_METHOD(TestMultiply) {
			String mama("|*|||");
			String papa("|||*||");
			rules_for_multiply r;
			String result("|||||||");
			Assert::IsTrue(mama.for_multiply(r) == "|||");
			Assert::IsTrue(papa.for_multiply(r) == "||||||");
		}
		TEST_METHOD(TestMyRules) {
			String mama("acbcbabcabc");
			String papa("acbbca");
			my_rules r;
			String result("a");
			Assert::IsTrue(mama.for_my_rules(r) == result);
			Assert::IsTrue(papa.for_my_rules(r) == "bbaa");
		}
	};
}
