solu.dat : solu.x
	./solu.x


solu.x : solu.cpp
	c++ solu.cpp -o solu.x