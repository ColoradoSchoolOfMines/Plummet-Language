all:
	# clang++ ./plummet_bubble_sort.cpp -c -o ./bubble_sort.o
	clang++ `llvm-config --cxxflags --ldflags --system-libs --libs all` ./plummet_bubble_sort.cpp -o ./bubble_sort_generator
	./bubble_sort_generator bubble_sort > ./bubble_sort.ll
	rm ./bubble_sort_generator
	clang++ -c ./bubble_sort.ll -o ./bubble_sort.o
	clang ./main.c -c -o ./main.o
	clang ./bubble_sort.o ./main.o -o ./program

make_ir:
	clang++ -S -emit-llvm ./plummet_bubble_sort.cpp -o ./bubble_sort.ll
	clang -S -emit-llvm ./main.c -o ./main.ll

clean:
	[ -f ./program ] && rm ./program -i || true
	[ -f ./main.o ] && rm ./main.o -i || true
	[ -f ./main.ll ] && rm ./main.ll -i || true
	[ -f ./bubble_sort.o ] && rm ./bubble_sort.o -i || true
	[ -f ./bubble_sort.ll ] && rm ./bubble_sort.ll -i || true
