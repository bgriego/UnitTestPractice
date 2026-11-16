/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) //(type of test, what were testing)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual); //checks if the actual "single letter password" 'z' returns 1
}
TEST(PasswordTest, long_repeating_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("PPPPPPPPPPassword");
	ASSERT_EQ(10, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, regular_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("password");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, same_char_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("PPPPP");
	ASSERT_EQ(5, actual);
}
TEST(PasswordTest, hasUpperAndLower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("passWord");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, hasOnlyUpper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, hasOnlyLower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("password");
	ASSERT_EQ(false, actual);
}