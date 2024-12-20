# Number to English

This is a command line application that converts numbers (-12345.6789) to their
english counterparts (negative twelve thousand three hundred forty-five and 
six thousand seven hundred eighty nine ten thousandths).

It supports negatives, decimals, leading and trailing zeros, trailing garbage
(123al;djfljdadf -> one hundred twenty-three), and numbers up to 10^36 - 1 on
either side of the decimal, this is after extra zeros are removed.

In the future, I plan to support a much wider range of numbers up to 10^66 - 1
and even scientific notation, within that range.

No string copies or alterations are made other than appending to the english
conversion as it parses the number. It relies heavily on pointer arithmetic and
uses custom parsing methods to account for numbers outside the range of IEEE 754
double-precision floating-point numbers.
