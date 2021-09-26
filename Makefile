
.SUFFIXES: .cxx .o .x .hxx .c .cpp
NAME1 = BinaryTree
NAME2 = generator
NAME3 = TreeIteration
NAME4 = TestBinaryTree

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x


CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) 


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS)

$(EXEC2):
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS)

$(EXEC4):
	$(CO) -o $@ $(CXX4) $(FLAGS)

.PHONY: binarytree
binarytree: all
	@echo "*Binary tree\n"
	./$(EXEC2) 100 10000 | ./$(EXEC1) 
#	./$(EXEC1) < input100.txt > out3.txt
#	@echo "\n*output file:*\n"
#	@diff -s output100.txt out3.txt

.PHONY: treeiteration
treeiteration: all
	@echo "*Iterative traversal of the tree*\n"
	./$(EXEC2) 100 10000 | ./$(EXEC3) 
#	./$(EXEC3) < input100.txt > 4out2.txt
#	@echo "\n*output file:*\n"
#	@diff -s output100.txt 4out2.txt

.PHONY: test
test: all
	@echo "*TESTER*\n"
	@./$(EXEC4) 

.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.dat *.txt *.x core core* a.out; rm -rf ${LIB_DIR}
