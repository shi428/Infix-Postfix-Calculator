# Infix/Postfix-Calculator

A simple calculator that takes user input, translates it into a postfix expression, and evaluates it.

## Usage

Commands
* help - Displays command information.
* clear - Clears the screen.
* calc - Opens the infix/postfix calculator. Type an arithmetic expression, and it will be converted, and then evaluated. Type ans to retrieve the answer to the previous entered expression.
* delete - Deletes either global history or local history or any expression in the local history.
usage: delete [global/local]
* history -Prints the history of entered expressions so far.
* quit - Quits out of the program.

Makefile Commands
* ```make``` removes computer-generated files, compiles all source files, builds executable, and runs it in a memory checker before actually running it.
* ```make gdb``` removes computer-generated files, compiles all source files, builds executable, and runs it in the gdb debugger.
* ```make memory``` removes computer generated files, compiles all source files, builds executable, and runs it in a memory checker.
* ```make clean``` removes computer generated files.
