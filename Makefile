# To compile and update changes across the dsu header file and the primary c++ program file [main.cpp]

# Generating the ./output
output: main.o disjoint_set.hpp.gch
	g++ -std=c++14 main.o disjoint_set.hpp -o output

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

disjoint_set.hpp.gch: disjoint_set.hpp
	g++ -std=c++14 -c disjoint_set.hpp

# To clean the object files of cpp and hpp [.o and .hpp.gch] & the executible ./output.
clean: 
	rm *.o output *.hpp.gch