default: compile run

compile:
	g++ src/ques1.cpp -o bin/ques1
	g++ src/ques2.cpp -o bin/ques2
	g++ src/ques3.cpp -o bin/ques3

one:
	g++ src/ques1.cpp -o bin/ques1

two:
	g++ src/ques2.cpp -o bin/ques2

three:
	g++ src/ques3.cpp -o bin/ques3

run:
	./bin/ques1 < input/inp1.txt > output/out1.txt
	./bin/ques2 < input/inp2.txt > output/out2.txt
	./bin/ques3 < input/inp3.txt > output/out3.txt

clean:
	rm -f bin/*
	rm -f output/*
