#include<iostream>

const int k_min_input_value = 000000000;
const int k_max_input_value = 999999999;
const char k_newline = '\n';
const int k_mod_divisor = 10;

const int k_digit_eight_divisor = 10;
const int k_digit_seven_divisor = 100;
const int k_digit_six_divisor = 1000;
const int k_digit_five_divisor = 10000;
const int k_digit_four_divisor = 100000;
const int k_digit_three_divisor = 1000000;
const int k_digit_two_divisor = 10000000;
const int k_digit_one_divisor = 100000000;

const int k_multiplier_one = 1;
const int k_multiplier_two = 2;
const int k_multiplier_three = 3;
const int k_multiplier_four = 4;
const int k_multiplier_five = 5;
const int k_multiplier_six= 6;
const int k_multiplier_seven= 7;
const int k_multiplier_eight= 8;
const int k_multiplier_nine = 9;
const int k_mod_digit_checksum = 11;
const int k_checksum_limit = 10;


int main()
{
	std::cout << "Enter the first 9 digits of an ISBN as integer:";
	auto input_value = 0;
	std::cin >> input_value;

	while (std::cin.fail()||input_value > k_max_input_value || input_value < k_min_input_value)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
		std::cout << "Invalid ISBN,try again!"<<std::endl;
		std::cout << "Enter the first 9 digits of an ISBN as integer:";
		std::cin >> input_value;
	}

	auto digit_nine = input_value % k_mod_divisor;
	auto digit_eight = (input_value / k_mod_divisor) % k_mod_divisor;
	auto digit_seven = (input_value / k_digit_seven_divisor) % k_mod_divisor;
	auto digit_six = (input_value / k_digit_six_divisor) % k_mod_divisor;
	auto digit_five = (input_value / k_digit_five_divisor) % k_mod_divisor;
	auto digit_four = (input_value / k_digit_four_divisor) % k_mod_divisor;
	auto digit_three = (input_value / k_digit_three_divisor) % k_mod_divisor;
	auto digit_two = (input_value / k_digit_two_divisor) % k_mod_divisor;
	auto digit_one = (input_value / k_digit_one_divisor) % k_mod_divisor;

	auto digit_checksum = ((digit_one * k_multiplier_one)+ (digit_two * k_multiplier_two) + (digit_three * k_multiplier_three)
						+ (digit_four * k_multiplier_four) + (digit_five * k_multiplier_five) + (digit_six * k_multiplier_six) +
						(digit_seven * k_multiplier_seven) + (digit_eight * k_multiplier_eight) + (digit_nine * k_multiplier_nine)) % k_mod_digit_checksum;

	auto is_checksum_equals_ten = digit_checksum==k_checksum_limit;



	if (is_checksum_equals_ten)
	{
		std::cout << "The ISBN-10 number is :" << digit_one << digit_two << digit_three << digit_four << digit_five << digit_six <<
			digit_seven << digit_eight << digit_nine << "X" << std::endl;
	}
	else
	{
		std::cout << "The ISBN-10 number is :" << digit_one << digit_two << digit_three << digit_four << digit_five << digit_six <<
			digit_seven << digit_eight << digit_nine <<digit_checksum << std::endl;
	}
	
	return 0;
}
