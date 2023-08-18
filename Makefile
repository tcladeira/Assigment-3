all: seq.o GeometricSequence.o
	clang++ seq.o GeometricSequence.o -o seq

seq.o: seq.cpp
	clang++ -c seq.cpp

GeometricSequence.o: GeometricSequence.cpp
	clang++ -c GeometricSequence.cpp

all2: seq2.o GeometricSequence2.o
	clang++ seq2.o GeometricSequence2.o -o seq2

seq2.o: seq2.cpp
	clang++ -c seq2.cpp

GeometricSequence2.o: GeometricSequence2.cpp
	clang++ -c GeometricSequence2.cpp

clean:
	$(RM) GeometricSequence.o
	$(RM) seq.o
	$(RM) seq
	$(RM) GeometricSequence2.o
	$(RM) seq2.o
	$(RM) seq2

run: seq
	./seq

run2: seq2
	./seq2