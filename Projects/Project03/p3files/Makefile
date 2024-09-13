part1: part1.cpp mylib.cpp Pos.cpp easycurses.cpp easycurses.h Pos.h mylib.h
	g++ part1.cpp mylib.cpp Pos.cpp easycurses.cpp -l ncurses -o part1
part2: part2.cpp mylib.cpp Pos.cpp easycurses.cpp easycurses.h Pos.h mylib.h
	g++ part2.cpp mylib.cpp Pos.cpp easycurses.cpp -l ncurses -o part2
part3: part3.cpp mylib.cpp Pos.cpp easycurses.cpp easycurses.h Pos.h mylib.h
	g++ part3.cpp mylib.cpp Pos.cpp easycurses.cpp -l ncurses -o part3
part4: part4.cpp mylib.cpp Pos.cpp easycurses.cpp easycurses.h Pos.h mylib.h
	g++ part4.cpp mylib.cpp Pos.cpp easycurses.cpp -l ncurses -o part4
part5: part5.cpp mylib.cpp Pos.cpp easycurses.cpp easycurses.h Pos.h mylib.h
	g++ part5.cpp mylib.cpp Pos.cpp easycurses.cpp -l ncurses -o part5
################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

