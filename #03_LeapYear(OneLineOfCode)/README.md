# Leap Year
## One-Line Implementation
### [In this program](https://github.com/MajdiAl-Hijazi/08-Algorithms-ProblemSolvingLevel4/blob/main/%2303_LeapYear(OneLineOfCode)/%2303_LeapYear(OneLineOfCode).cpp) :
In the `IsLeapYear` function, we use the following:
```cpp
bool IsLeapYear(short Year) {

	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
```
We optimized the leap year conditions by combining them into a single line using logical operators, which makes the code more concise and readable😎.
___
## Multi-Line Implementation
### [That program](https://github.com/MajdiAl-Hijazi/08-Algorithms-ProblemSolvingLevel4/blob/main/%2302_LeapYear.cpp) :
In the `IsLeapYear` function, we use the following:
```cpp
bool IsLeapYear(short Year) {

	if (Year % 400 == 0)
		return true;
	else
		if (Year % 4 == 0 && Year % 100 != 0)
			return true;
	return false;
}
```
In this version, the leap year logic is implemented using multiple conditional statements to make the rules clearer and easier to follow compared to the single-line implementation👌.
