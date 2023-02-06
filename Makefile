CXXFLAGS += -Wall -std=c++17 -pedantic -g -fsanitize=address

test:new1.o
	$(CXX) -o $@ $^ -fsanitize=address