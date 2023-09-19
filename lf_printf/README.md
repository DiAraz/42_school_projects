ft_printf

For the ft_printf project of the 42 school, we must recreate the famous C library printf function. This project teaches us about variadic arguments as well as structures if we plan to implement printf's extra flags.

Supported conversions: %, c, s, p, i, d, u, x, X
Supported flags: # + (space)
Supported options: - 0 . * width

Advanced Usage: Format Specifiers
This ft_printf function supports several format specifiers, described below. These are optional, can be used in any combination, and are implemented as: %[flags][width][.precision]specifier

The table below lists supported format specifiers:

Flags
-	Left justify the result within the field. By default it is right justified.
+	Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a sign.
(space)	If there is no sign, a space is attached to the beginning of the result.
#	Used with x or X specifiers the value is preceded with 0x or 0X respectively for values different than zero.
0	Leading zeros are used to pad the numbers instead of space.


Width
(number)	Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
*	The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.


Precision
.(number)	For integer specifiers (d, i, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.
.(*)	The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.


Specifiers
%	% followed by another % character writes % to the screen.
c	writes a single character.
s	writes a character string.
p	writes an implementation-defined character sequence defining a pointer address.
d or i	writes a signed integer to decimal representation.
u	writes an unsigned integer to decimal representation.
x or X	writes an unsigned integer to hexadecimal representation.