# Printf

_printf project is a emulation of "printf" function for c languaje. printf format strings are nested according to the reading of parameters initialized by the character '%' validating its existence and type so that it are finally printed.

# Features
- The main function "_printf" gives the arguments to the "switch_case" function to evaluate the case in order to create the buffer
- The buffer is created by allocating memory according to the size of the case.
- The returns of our function are the number of characters printed, and when there's an incorrect input the return is going to be -1 as an error, just like the original printf.
- when buffer is complete then it is use on "write()" to be printed to standar output

------
## Files and Descriptions
| FILE  | DESCRIPTION |
| ------------- | ------------- |
| _printf  | Function that simulates a real printf funtion  |
| main.h  | Header file that contains our prototypes and include. |
| _strlen.c  | Returns the length of a string.  |
| nest.c  | Creates and initializes the buffer to print an char in it. |
| neststring.c  | Creates and initializes the buffer to print an string in it.  |
| nestint.c  | Creates and initializes the buffer to print an int in it.  |
| man_3_printf  | Our manual with documentation about the function _printf  |

## Flowchart:
![_printf](https://cdn.discordapp.com/attachments/242350770161188864/907432106903367741/printf.drawio.png "_printf")