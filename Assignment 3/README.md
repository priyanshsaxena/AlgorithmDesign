For simple testing of the code, provide input to the code in the format specified below for different problems. All the source codes are present as ques<problem-number>.cpp. 

Root-directory of the project: (from where bin, src, input and output folders can be seen), named 'project'.

To compile and run ques1.cpp, use the following commands from the root directory of the project, in order:
	g++ src/ques1.cpp -o bin/ques1
	./bin/ques1 < input/inp1.txt

The above example assumes that the input to question 1 is present in the inp1.txt file in the input folder. Manual input can be supplied through the console. Same goes for all the other files.

Problem-wise specifications

Problem 1 Input -> First line of the input contains 'n', the number of activities. Next 'n' lines of input contain 3 space-separated integers each, denoting the start time, finish time and the weight of the tasks. The last line of input contains the choice of the function: 1 for Opt-Cost, 2 for M-Opt-Cost and 3 for Opt-Solution.

SAMPLE INPUT:

5
1 3 6
2 4 5
1 5 4
3 7 5
5 9 2
3

Problem 1 Output -> The output gives the optimal solution or the optimal cost, as required by the user.

SAMPLE OUTPUT:

Press 1 for Optimal Cost.
Press 2 for Memoised Optimal Cost.
Press 3 for solution.
Default is exit: The solution contains these intervals:
1-3:6
3-7:5

Problem 2 Input -> First line of the input contains 'n' , the number of elements in the array. Next line of input contain n space-separated integers, representing the elements of the array.

SAMPLE INPUT:

5
1 2 3 4 5

Problem 2 Output -> The only line of output contains the number of inversion in the given input array.

SAMPLE OUTPUT:

Number of inversions are 0

Problem 3 Input -> First line of the input contains 'n' and 'm', the number of nodes and edges in the graph respectively. Next m lines of input contain 2 space-separated natural numbers 'x' and 'y' in the range [1,n], representing an edge between nodes x and y (1-based indexing). The last line of input takes 2 space-separated natural numbers 's' and 'e' in the range [1,n], denoting the start and end index respectively.

SAMPLE INPUT:

5 5
1 3
2 3
1 2
3 5
4 5
1 4

Problem 3 Output -> The only line of output contains the shortes distance between any two points in the plane.

SAMPLE OUTPUT:

The shortest distance is 1.41421

Problem 4 Input -> First line of the input contains 'n, the number of points. Next n lines of input contain 2 space-separated natural numbers 'x' and 'y', representing the x- and y-coordinates of the points.

SAMPLE INPUT:

6
2 3
12 30
40 50
5 1
13 10
3 4

Problem 4 Output -> There will be n*(n-1)/2 lines in the output. Every line denotes the error for the set of points [i,j].

SAMPLE OUTPUT:

Eij for 1 to 2: 0
Eij for 1 to 3: 1.78572
Eij for 1 to 4: 68.6724
Eij for 1 to 5: 269.643
Eij for 1 to 6: 288.487
Eij for 2 to 3: 0
Eij for 2 to 4: 46.5742
Eij for 2 to 5: 264.221
Eij for 2 to 6: 288.487
Eij for 3 to 4: 0
Eij for 3 to 5: 250.535
Eij for 3 to 6: 288.385
Eij for 4 to 5: 0
Eij for 4 to 6: 222.193
Eij for 5 to 6: 0

Easy Testing:

For the convenience of the user, a makefile is provided. From the root directory of the project, run the following commands in order:
	make clean
	make

The outputs of the problems can then be seen in the output folder, with out<number>.txt corresponding to the output of ques<number>.cpp. To provide custom input to ques<number>.cpp, modify the file inp<number>.txt in the input folder.