I have taken the X-axis parameter as the number of cache lines,
that is 1 to 65536 number of lines.

For my linearread and linearwrite:
Input is the size of m1 array, the size should be given in the array initialization.
The input is the number of cache lines itself since m1 is an array of structures, ie 1 to 65536.

for my randomread and randomwrite:
Here I have Declared only an array, so for 1 cache line there will ne 16 elements(SINCE THE SIZEOF INT IS 4 BYTES) in this array, int m1[];
The input is the number of cache lines multiplied by16, ie 1*16 to 65536*16


