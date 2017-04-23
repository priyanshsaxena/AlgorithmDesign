For simple testing of the code, provide input to the code in the format specified below for different problems. All the source codes are present as ques<problem-number>.cpp. 

Root-directory of the project: (from where bin, src, input and output folders can be seen), named 'project'.

To compile and run ques1.cpp, use the following commands from the root directory of the project, in order:
	g++ src/ques1.cpp -o bin/ques1
	./bin/ques1 < input/inp1.txt

The above example assumes that the input to question 1 is present in the inp1.txt file in the input folder. Manual input can be supplied through the console. Same goes for all the other files.

Problem-wise specifications

Problem 1 Input -> First line of the input contains n and m, the number of nodes and edges in the graph respectively. Next m lines of input contain 3 space-separated natural numbers x, y (in the range [1,n]) and w, representing an edge from x to y (1-based indexing) with weight w.

SAMPLE INPUT:

5 7
1 3 5
1 4 3
3 5 3
3 2 3
3 4 3
4 2 5
2 5 7
1 5

Problem 1 Output -> The first line of input shows the maximum value of flow in the network. Then, all the directed edges in the network showing their assigned flow values are printed.

SAMPLE OUTPUT:

Max Flow: 8
1 --> 3 : 5
1 --> 4 : 3
2 --> 5 : 5
3 --> 5 : 3
3 --> 2 : 2
4 --> 2 : 3

Problem 2 Input -> First line of the input contains n and mw , representing the number of types of items to be considered and the maximum weight that can be carried. Next n lines of input contain 2 space-separated integers val and num, representing the value and number of the i-th type of item respectively.

SAMPLE INPUT:

6 10
15 5
23 4
21 2
16 4
19 5
18 2

Problem 2 Output -> The first line of output contains the maximum value that can be carried under the given constraints. The items included to make up the maximum value are given with their weights in separate lines.

SAMPLE OUTPUT:

Max value: 62
Included: 23 with weight 4
Included: 21 with weight 2
Included: 18 with weight 2

Problem 3 Input -> First line of the input contains n, m and s the number of nodes and edges in the graph, and the source-node (1-based indexing) respectively. Next m lines of input contain 3 space-separated natural numbers x, y (in the range [1,n]) and w, representing an edge between nodes x and y (1-based indexing) with weight w.

SAMPLE INPUT:

5 5 3
1 5 50
3 5 160
1 3 100
2 3 100
3 4 100

Problem 3 Output -> The only line of output contains n space-separated non-negative integers, the i-th representing the minimum distance of the i-th node from the source-node s.  

SAMPLE OUTPUT:

100 100 0 100 140

Easy Testing:

For the convenience of the user, a makefile is provided. From the root directory of the project, run the following commands in order:
	make clean
	make

The outputs of the problems can then be seen in the output folder, with out<number>.txt corresponding to the output of ques<number>.cpp. To provide custom input to ques<number>.cpp, modify the file inp<number>.txt in the input folder.