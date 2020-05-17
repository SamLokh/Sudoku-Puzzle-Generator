# Sudoku-Puzzle-Generator
Ahh... This one is messy! One of the first projects. Its supposed to generate a Sudoku puzzle for you to solve.

It works but it takes a random amount of time to generate a puzzle everytime. I was bored and things got out of hand and I was writing messier code with each passing second. I have had a couple of ideas that would generate the puzzle in constant time (haven't implemented them yet). But, I'm afraid to revisit that mess and try to recall the different things like the variables, where they fit in, etc. even tough I am the one who has written that program from scratch! But the program works,... eventually.


**Basic working:
First it fills in the diagonal boxes(3x3) with random numbers while following the Sudoku rules, than starts filling the individual unfilled boxes(3x3) starting with the second one while following the Sudoku rules. The random number generated for a cell in a box(3x3) is checked against all the other digits in the same row, the same column and the same box.

**IMPOTANT:
The program fails when a puzzle configuration is reached, where the random number generated does not fit in a cell because some Sudoku rule(either row, col or box) is not satisfied and the Random Function (which has the system clock time as its seed) keeps on generating the same set of invalid random numbers. To counter this block, I set up a system to restart the program from scratch when such a block occurs but than I saw that this block occurs quite often and it depends on the Random Function.
