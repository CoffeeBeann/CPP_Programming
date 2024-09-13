hw: hw.cpp
	g++ hw.cpp -o hw

############### DON'T TOUCH BELOW #######################
run: hw
	@valgrind ./hw 2> out; python3 val.py
