seq: seq.o GeometricSequence.o
	clang++ seq.o GeometricSequence.o -o seq

seq.o: seq.cpp
	clang++ -c seq.cpp

GeometricSequence.o: GeometricSequence.cpp
	clang++ -c GeometricSequence.cpp

clean:
	$(RM) GeometricSequence.o
	$(RM) seq.o
	$(RM) seq

run: seq
	./seq