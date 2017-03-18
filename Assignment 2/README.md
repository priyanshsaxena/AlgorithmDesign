For simple testing of the code, provide input to the code in the format specified below for different problems. All the source codes are present as ques<problem-number>.cpp. Problem 1 has ques1a.cpp and ques1b.cpp separately.

Root-directory of the project: (from where bin, src, input and output folders can be seen), named 'project'.

To compile and run ques1.cpp, use the following commands from the root directory of the project, in order:
	g++ src/ques1.cpp -o bin/ques1
	./bin/ques1 < input/inp1.txt

The above example assumes that the input to question 1 is present in the inp1.txt file in the input folder. Manual input can be supplied through the console. Same goes for all the other files.

Problem-wise specifications

Problem 1 Input -> First line of the input contains 'n', the number of letters in the alphabet. Next n lines of input contain a character 'c' and a float number 'p' in the range [0.00,1.00] - separated by a single whitespace - denoting the letter of the alphabet and the probability of occurence of that alphabet.

SAMPLE INPUT:

4
a 0.25
b 0.3
c 0.4
d 0.05

Problem 1 Output -> The output lists the final encoding reported by the code, as "<alphabet>:<prefix-code>", in n separate lines.

SAMPLE OUTPUT:

c:0
b:10
d:110
a:111

Problem 2 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the directed graph respectively. Next m lines of input contain 2 space-separated natural numbers 'x' and 'y' in the range [1,n], representing an edge between nodes x and y, from x to y (1-based indexing). Next line of input contains a single integer 'num', the number of columns to be tested as subset. The next line contains 'num' natural numbers in the range [1,m], denoting the columns to be used for checking independence, 1-based indexing.

SAMPLE INPUT:

3 3
1 2
2 3
1 3
3
1 2 3

Problem 2 Output -> The code prints "Dependent vectors. Directed cycle may or may not be present." if the columns of the incidence matrix are found to be dependent, otherwise it prints "Independent vectors. No directed cycles can be present." and then looks for cycles in the graph, reporting whether a cycle was found or not.

SAMPLE OUTPUT:

Dependent vectors. Directed cycle may or may not be present.

Problem 3 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the graph respectively. Next m lines of input contain 3 space-separated natural numbers - 'x' and 'y' in the range [1,n], and 'w' as any whole number, representing an edge between nodes x and y (1-based indexing) with weight w.

SAMPLE INPUT:

3 3
1 2 1
2 3 2
1 3 3

Problem 3 Output -> The code outputs the MST, edge by edge as "<x> <-> <y> : <w>", where every line denotes an edge in the MST (Maximum Spanning Tree). The final line of output prints the weight of the resultant subset of edges.

SAMPLE OUTPUT:

1 <-> 3 : 3
2 <-> 3 : 2
Maximum weight: 5

Problem 4 Input -> First line of the input contains 'n', the number of tasks. Next line of input contains n space-separated natural numbers, the i-th number denoting the duration of i-th task.

SAMPLE INPUT:

4
2 5 4 6

Problem 4 Output -> The output consists of n+1 lines. The first n lines list the schedule, the i-th denoting the i-th task as listed in the final schedule reported by the code as "Task <i>". The last line shows the minimum average completion-time.

SAMPLE OUTPUT:

Task 1
Task 3
Task 2
Task 4
Minimum average completion time: 4.25

Problem 5 Input -> First line of the input contains 'n', the number of activities. Next n lines of input contain 2 space-separated whole numbers 'x' and 'y', the number in i-th line representing the start-time and end-time of the i-th activity.

SAMPLE INPUT:

3
1 2
2 3
3 4

Problem 5 Output -> The code prints n+1 lines. The first n lines show the labels, i-th line denoting the label assigned to the i-th activity as "Label <i>: <l>". The last line prints the minimum number of resources required.

SAMPLE OUTPUT:

Label 1: 1
Label 2: 1
Label 3: 1
Number of resources used: 1

Problem 6 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the graph respectively. Next m lines of input contain 3 space-separated natural numbers - 'x' and 'y' in the range [1,n], and 'w' as any natural number, representing an edge between nodes x and y (1-based indexing) with weight w.

SAMPLE INPUT:

3 3
1 2 1
2 3 2
1 3 3

Problem 6 Output -> The only line of output says "Same MST." if the MSTs are found to be same for both the trees, otherwise it prints "Different MSTs.".

SAMPLE OUTPUT:

Same MST.

Easy Testing:

For the convenience of the user, a makefile is provided. From the root directory of the project, run the following commands in order:
	make clean
	make

The outputs of the problems can then be seen in the output folder, with out<number>.txt corresponding to the output of ques<number>.cpp. To provide custom input to ques<number>.cpp, modify the file inp<number>.txt in the input folder.