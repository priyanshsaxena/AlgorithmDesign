For simple testing of the code, provide input to the code in the format specified below for different problems. All the source codes are present as ques<problem-number>.cpp. 

Root-directory of the project: (from where bin, src, input and output folders can be seen), named 'project'.

To compile and run ques1.cpp, use the following commands from the root directory of the project, in order:
	g++ src/ques1.cpp -o bin/ques1
	./bin/ques1 < input/inp1.txt

The above example assumes that the input to question 1 is present in the inp1.txt file in the input folder. Manual input can be supplied through the console. Same goes for all the other files.

Problem-wise specifications

Problem 1 Input -> First line of the input contains n,m and k, the number of nodes and edges in the graph and the size of the independent set to be found respectively. Next m lines of input contain 2 space-separated integers x and y, representing an edge from x to y (1-based indexing)..

SAMPLE INPUT:

3 3 1
1 2
1 3
2 3

Problem 1 Output -> The only line of output contains the list of nodes in a k-node vertex-cover - if possible - otherwise it prints that no such vertex-cover is possible.

SAMPLE OUTPUT:

No 1-node vertex cover possible...

Problem 2 Input -> First line of the input contains n and m , representing the number of nodes and edges in the graph. Next m lines of input contain 2 space-separated integers x and y, representing an edge between nodes x and y.

SAMPLE INPUT:

3 2
1 2
1 3

Problem 2 Output -> The first line of output contains the number of nodes in the maximum-sized independent set. Next line contains the nodes in this set.

SAMPLE OUTPUT:

Maximum-sized independent set is of size 2.
The nodes in this set are: 2 3

Problem 3 Input -> The first line of input contains two space-separated integers n and m, the number of nodes and edges in the graph respectively. Next line contains n space-separated integers denoting the weights of the nodes. Next m lines contain two space-separated integers x and y, denoting the edge between nodes x and y (1-based indexing).

SAMPLE INPUT:

14 13 1
2 5 4 6 7 10 2 4 5 4 9 7 8 3
1 2
2 3
2 4
4 5
4 6
5 7
5 8
1 9
9 10
9 11
9 12
12 13
12 14

Problem 3 Output -> The only line of output contains the weight of the maximum-weight independent set.

SAMPLE OUTPUT:

Weight of max-weight independent set is: 47;

Easy Testing:

For the convenience of the user, a makefile is provided. From the root directory of the project, run the following commands in order:
	make clean
	make

The outputs of the problems can then be seen in the output folder, with out<number>.txt corresponding to the output of ques<number>.cpp. To provide custom input to ques<number>.cpp, modify the file inp<number>.txt in the input folder.