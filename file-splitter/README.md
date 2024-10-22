### File splitter
This one is based
Basically if you see the example in data, this program takes it and splits it up into a chosen amount of pieces. It writes it to seperate files

This is made possible with file descriptors. As the strings are being written into the files through their descriptors

Dynamic memory allocation is used to display the partitioned string when running the program.

## How to use
Just compile the program and run it with arg of how many pieces to split
```
cc splitter.c -o split
./split 4
```
The 4 is used as example
