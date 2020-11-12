
all:
	cppcheck --enable=all --inconclusive main_test.c linked_list.c linked_list.h
	gcc main_test.c linked_list.c -o main_test.out -Wall 
	g++ gtest.cpp -lgtest -pthread -o gtest.out -Wall
clean:
	rm *.out

