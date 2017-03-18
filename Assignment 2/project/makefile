default: compile run

compile:
	g++ src/ques1a.cpp -o bin/ques1a
	g++ src/ques1b.cpp -o bin/ques1b
	g++ src/ques2.cpp -o bin/ques2
	g++ src/ques3.cpp -o bin/ques3
	g++ src/ques4.cpp -o bin/ques4
	g++ src/ques5.cpp -o bin/ques5
	g++ src/ques6.cpp -o bin/ques6

one:
	g++ src/ques1a.cpp -o bin/ques1a
	g++ src/ques1b.cpp -o bin/ques1b

two:
	g++ src/ques2.cpp -o bin/ques2

three:
	g++ src/ques3.cpp -o bin/ques3

four:
	g++ src/ques4.cpp -o bin/ques4

five:
	g++ src/ques5.cpp -o bin/ques5

six:
	g++ src/ques6.cpp -o bin/ques6

run:
	./bin/ques1a < input/inp1.txt > output/out1a.txt
	./bin/ques1b < input/inp1.txt > output/out1b.txt
	./bin/ques2 < input/inp2.txt > output/out2.txt
	./bin/ques3 < input/inp3.txt > output/out3.txt
	./bin/ques4 < input/inp4.txt > output/out4.txt
	./bin/ques5 < input/inp5.txt > output/out5.txt
	./bin/ques6 < input/inp6.txt > output/out6.txt

clean:
	rm -f bin/*
	rm -f output/*
