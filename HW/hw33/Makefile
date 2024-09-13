hw: hw.cpp ll.cpp ll.h
	g++ hw.cpp ll.cpp -o hw

############### DON'T TOUCH BELOW #######################
run: hw
	@valgrind ./hw 2> out; python3 val.py
