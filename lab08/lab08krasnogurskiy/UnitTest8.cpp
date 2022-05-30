#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab08/set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest8
{
	TEST_CLASS(UnitTest8)
	{
	public:

		TEST_METHOD(TestAddElement)
		{
			MySet s;
			Assert::AreNotEqual(true, s.is_in_set('a'));
			s.add_element('a');
			Assert::AreEqual(true, s.is_in_set('a'));
			s.add_element('m');
			s.add_element('t');
			Assert::AreEqual(true, s.is_in_set('m'));
			Assert::AreEqual(true, s.is_in_set('t'));
			Assert::AreNotEqual(true, s.is_in_set('9'));
			Assert::AreNotEqual(true, s.is_in_set('/'));
			s.add_element('9');
			s.add_element('/');
			Assert::AreEqual(true, s.is_in_set('9'));
			Assert::AreEqual(true, s.is_in_set('/'));
		}

		TEST_METHOD(TestRemoveElement)
		{
			MySet s;
			s.add_element('a');
			s.add_element('m');
			s.add_element('t');
			s.add_element('9');
			s.add_element('/');
			Assert::AreEqual(true, s.is_in_set('a'));
			Assert::AreEqual(true, s.is_in_set('m'));
			Assert::AreEqual(true, s.is_in_set('t'));
			Assert::AreEqual(true, s.is_in_set('9'));
			Assert::AreEqual(true, s.is_in_set('/'));

			s.remove_element('a');

			Assert::AreEqual(false, s.is_in_set('a'));

			s.remove_element('9');
			s.remove_element('/');

			Assert::AreEqual(false, s.is_in_set('9'));
			Assert::AreEqual(false, s.is_in_set('/'));

			Assert::AreEqual(true, s.is_in_set('m'));
			Assert::AreEqual(true, s.is_in_set('t'));
		}

		TEST_METHOD(TestUnion)
		{
			MySet s;
			s.add_element('a');
			s.add_element('m');
			s.add_element('t');
			MySet g;
			g.add_element('9');
			g.add_element('/');

			MySet sAndg = s.set_union(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			Assert::AreEqual(true, sAndg.is_in_set('m'));
			Assert::AreEqual(true, sAndg.is_in_set('t'));
			Assert::AreEqual(true, sAndg.is_in_set('9'));
			Assert::AreEqual(true, sAndg.is_in_set('/'));

			g.add_element('m');
			sAndg = s.set_union(g);
			Assert::AreEqual(true, sAndg.is_in_set('m'));

			g.add_element('a');
			sAndg = s.set_union(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			s.remove_element('a');
			sAndg = s.set_union(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			g.remove_element('a');
			sAndg = s.set_union(g);
			Assert::AreEqual(false, sAndg.is_in_set('a'));
		}

		TEST_METHOD(TestIntersect)
		{
			MySet s;
			s.add_element('a');
			s.add_element('m');
			s.add_element('t');
			MySet g;
			g.add_element('9');
			g.add_element('/');

			MySet sAndg = s.set_intersect(g);
			Assert::AreEqual(false, sAndg.is_in_set('a'));
			Assert::AreEqual(false, sAndg.is_in_set('m'));
			Assert::AreEqual(false, sAndg.is_in_set('t'));
			Assert::AreEqual(false, sAndg.is_in_set('9'));
			Assert::AreEqual(false, sAndg.is_in_set('/'));

			g.add_element('m');
			sAndg = s.set_intersect(g);
			Assert::AreEqual(true, sAndg.is_in_set('m'));

			g.add_element('t');
			sAndg = s.set_intersect(g);
			Assert::AreEqual(true, sAndg.is_in_set('m'));
			Assert::AreEqual(true, sAndg.is_in_set('t'));

			s.add_element('/');
			sAndg = s.set_intersect(g);
			Assert::AreEqual(true, sAndg.is_in_set('m'));
			Assert::AreEqual(true, sAndg.is_in_set('t'));
			Assert::AreEqual(true, sAndg.is_in_set('/'));
		}

		TEST_METHOD(TestDiff)
		{
			MySet s;
			s.add_element('a');
			s.add_element('m');
			s.add_element('t');

			MySet g;

			MySet sAndg = s.set_diff(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			Assert::AreEqual(true, sAndg.is_in_set('m'));
			Assert::AreEqual(true, sAndg.is_in_set('t'));

			g.add_element('m');
			g.add_element('t');

			sAndg = s.set_diff(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			Assert::AreEqual(false, sAndg.is_in_set('m'));
			Assert::AreEqual(false, sAndg.is_in_set('t'));

			g.remove_element('t');
			sAndg = s.set_diff(g);
			Assert::AreEqual(true, sAndg.is_in_set('a'));
			Assert::AreEqual(false, sAndg.is_in_set('m'));
			Assert::AreEqual(true, sAndg.is_in_set('t'));
		}
	};
}
