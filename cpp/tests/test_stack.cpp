//
//	test_stack.cpp	- Test code for Stack class.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

#include "stack.hpp"

TEST_CASE("Stack")
{
	Stack<char> stack;
	SUBCASE("Empty stack has no depth.")
	{
		CHECK(stack.depth() == 0);
	}

	SUBCASE("Empty stack has no tos.")
	{
		CHECK_THROWS_AS(stack.tos(), const Stack<char>::Underflow);
	}

	SUBCASE("Empty stack can't pop.")
	{
		CHECK_THROWS_AS(stack.pop(), const Stack<char>::Underflow);
	}
}

TEST_CASE("Signature Checks")
{
	Signature sig;

	SUBCASE("Default Signature is Empty.")
	{
		CHECK(sig.in_seq.depth() == 0);
		CHECK(sig.out_seq.depth() == 0);
	}

	SUBCASE("Adding Stack Signatures")
	{
		Type A = Type::find_or_make("AType");
		Type B = Type::find_or_make("BType");

		//auto a = std::make_pair(A, std::make_optional<std::any>());
		auto a = make_stacksig(A);
		std::cout << a << std::endl;

		sig.in_seq.push( a );
		//sig.in_seq.push_back(B);

		CHECK(sig.in_seq.depth() == 1);
	}
}
