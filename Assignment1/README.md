For simple testing of the code, provide input to the code in the format specified below for different problems. All the source codes are present as ques<problem-number>.cpp. 

Root-directory of the project: (from where bin, src, input and output folders can be seen), named 'project'.

To compile and run ques1.cpp, use the following commands from the root directory of the project, in order:
	g++ src/ques1.cpp -o bin/ques1
	./bin/ques1 < input/inp1.txt

The above example assumes that the input to question 1 is present in the inp1.txt file in the input folder. Manual input can be supplied through the console. Same goes for all the other files.

Problem-wise specifications

Problem 1 Input -> First line of the input contains 'n', the number of men and women (n women and n men). Next n lines of input contain n space-separated natural numbers in the range [1,n] in the (1+i)-th line, denoting the priorities of the i-th man. Next n lines of input contain n space-separated natural numbers in the range [1,n] in the (n+1+i)-th line, denoting the priorities of the i-th woman.

SAMPLE INPUT:

4
4 2 3 1
2 1 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

Problem 1 Output -> The output lists the final matching reported by the code, as "Woman <i> is married to Man <j>".

SAMPLE OUTPUT:

Woman 1 married to Man 3
Woman 2 married to Man 2
Woman 3 married to Man 4
Woman 4 married to Man 1

Problem 2 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the graph respectively. Next m lines of input contain 2 space-separated natural numbers 'x' and 'y' in the range [1,n], representing an edge between nodes x and y (1-based indexing).

SAMPLE INPUT:

3 3
1 2
2 3
1 3

Problem 2 Output -> The code prints "No cycles" if no cycle is detected, otherwise it prints a comma-separated list of all the nodes in any cycle that it discovers. The i-th and (i+1)-th nodes in this output have an edge between them, as do the first and last nodes.

SAMPLE OUTPUT:

2,3,1

Problem 3 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the graph respectively. Next m lines of input contain 2 space-separated natural numbers 'x' and 'y' in the range [1,n], representing an edge between nodes x and y (1-based indexing). The last line of input takes 2 space-separated natural numbers 's' and 'e' in the range [1,n], denoting the start and end index respectively.

SAMPLE INPUT:

5 5
1 3
2 3
1 2
3 5
4 5
1 4

Problem 3 Output -> The only line of output contains '0' if 'end' vertex is not reachable from 'start' vertex. Otherwise, it prints the number of edges in the shortest path from 'start' to 'end'.

SAMPLE OUTPUT:

3

Easy Testing:

For the convenience of the user, a makefile is provided. From the root directory of the project, run the following commands in order:
	make clean
	make

The outputs of the problems can then be seen in the output folder, with out<number>.txt corresponding to the output of ques<number>.cpp. To provide custom input to ques<number>.cpp, modify the file inp<number>.txt in the input folder.