# random_c
a program for getting a random number.
## Installation:
cloning the repo:
```
git clone https://github.com/lorisbovcon/random_c.git
```
compiling the program:
```
make all
```
## Running the program:
Linux:
```
./random
```
## Usage:
when you launch the program you will first get a prompt:
>random_number_generator>

depending on the input the program will do diferent actions:
### h:
help: prints a brief help text
### q:
quit: quit the program
### r:
random: will generate a random number
#### Rules for generating random numbers:
the program takes the folowing format: r-[uniqe two letter identefyer (later refered to as "class")]-[number of objects in the class]
the program takes the class and checks if it is new, if so it will add it to the "USED_NUMS.txt" file with the number of objects else it will overwrite the number of objects in the class but not the numbers that were already used
#### USED_NUMS.txt:
The program writes to the file in the folowing way:
```
-1a-10
4
2
7
5
...
```
where the dash before the class tels the program that it is a heading and everything after the heading is a already used number. The program automatically delegates 32 lines to the class (in reality 31, because the first line is the heading), so the program allows for 31 objects in the class (although this can be changed)
#### Headings:
the headings have the folowing format:
-[class]-[number of objects]
#### Overflow:
when the number of used number equals the number of objects aka all objects have been outputed the program will start over but will copy the last entery to the top of the list of used number so that  the number does not apear twice in a row
#### Max input:
By default the program supports 16 classes and 32 objects per class (realy 31)
### n:
no: will remove the last entery in the specefied class
#### Format:
n-[class]
