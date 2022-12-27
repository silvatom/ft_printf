# FT_PRINTF
The goal of this project is pretty straightforward. It's a recode of printf(). It's the first encounter with **variadic functions** in C, used to make functions with variable number of arguments. 

* [**Mandatory Part**](#Mandatory-Part) - Recode **printf()** function from **libc** with "**cspdiuxX%**" flags.
* [**Bonus Part**](#Bonus-Part) - Manage any combination of the flags "**-0.**" and the field minimum width under all conversions and all the "**# +**" flags (one of them is a space).
* [**How to Use**](#How-to-Use) - How to use and compile with the project's static library.
* [**References**](#References) - References to understand and learn more about the project.

## Mandatory Part
Basically, the goal is mimic the libc printf() behavior. Here are the requirements:
 - No buffer management
 - Handle the following flags: **cspdiuxX%**.
 - ft_printf() should behave as the original printf().

Here is a table with the specifier characters:
| Placeholder | Description |
|--|--|
| %c | Prints a single character. |
| %s | Prints a string (as defined by the common C convention. |
| %p | The void * pointer argument has to be printed in hexadecimal format. |
| %d or %i| Prints a decimal (base 10) number. |
| %u | Prints an unsigned decimal (base 10) number. |
| %x | Prints a number in hexadecimal (base 16) lowercase format. |
| %X | Prints a number in hexadecimal (base 16) uppercase format. |
| %% | Prints a percent sign. |

## Bonus Part
Implements Adicional flags:
| Flags | Description |
| -- | -- |
| - | Left-justify within the given field width. |
| + | Forces to preceed the result with a plus sign. |
| 0 | Left-pads the number with zeroes (0) instead of spaces. |
| # | Used to print an hexadecimal number with 0x. |
| (space) | A blank space before the value. |

And some field width flags

| Flags | Description |
| -- | -- |
| number | Minimum number of characters to be printed |
| .* | Integers: minimum number of digits to be written. |


## How to Use



## References
https://cplusplus.com/reference/cstdio/printf/
