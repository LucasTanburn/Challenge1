# Challenge1


The challenge was to take a text file and an optional flag from the command line and write an edited version to stdout.
The text file was read line by line and each space was replaced by a new line unless it was in quotation marks.
The output showed the original line, then a line of seperator characters, then the edited line.
The seperator character was '-' by default but could be changed using the optional -d flag.
Below is the output of two example files.

Example file 1:  
Invocation:
```
./Challenge1 Ch1Example1.txt
```
Output:
```
Input text "Processed text"
---------------------------
Input
text
Processed text

Output_text
-----------
Output_text
```
Example File 2:  
Invocation:
```
./Challenge1 Ch1Example2.txt -d ^
```
Output:
```
foobar
^^^^^^
foobar
```
