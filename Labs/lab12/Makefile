part1: part1.cpp Pair.cpp Pair.h
	g++ part1.cpp Pair.cpp -o part1
part2: part2.cpp Pair.cpp Pair.h
	g++ part2.cpp Pair.cpp -o part2
part3: part3.cpp Pair.cpp Pair.h
	g++ part3.cpp Pair.cpp -o part3
part4: part4.cpp Pair.cpp Pair.h
	g++ part4.cpp Pair.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py