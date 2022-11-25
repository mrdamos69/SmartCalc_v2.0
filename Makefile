OS := $(shell uname -s)
CC = g++
FLAG = 
FLAG_C = -c 
CL_11 = -std=c++17 -Wall -Wextra -Werror
PR_NAME = s21_smartcalc
ALL_FILE_CC = ./model/model.cc ./controller/controller.cc
ALL_FILE_H = ./model/model.h ./controller/controller.h
ALL_FILE_O = model.o

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lgtest
else
	FLAGS_PLATFORM = -lgtest -lsubunit -lrt -lm -lpthread -g
endif

all: clean $(PR_NAME).a

temp_test:
	@$(CC) $(PR_NAME).cc
	@./a.out

$(PR_NAME).a:
	@$(CC) $(FLAG_C) $(ALL_FILE_CC) $(ALL_FILE_H)
	@ar rcs $(PR_NAME).a $(ALL_FILE_O) 

test: $(PR_NAME).a
	@$(CC) $(CL_11) ./unit_test/unit_test.cc ./model/model.cc -o tests.o -lgtest
	@./tests.o

gcov_report:
	@$(CC) --coverage $(ALL_FILE) ./unit_test/unit_test.cc $(FLAGS_PLATFORM) -o gov_report.o
	@./gov_report.o
	@lcov -t $(PR_NAME)_tests -o $(PR_NAME)_tests.info -c -d .
	@genhtml -o report $(PR_NAME)_tests.info
	@open ./report/index.html

install:
	@make clean
	@mkdir build
	@cd view && qmake && make && make clean && rm Makefile && cd ../ && mkdir build && mv view/view.app build/
	
uninstall:
	@rm -rf build*

dvi:
	open https://github.com/mrdamos69/SmartCalc_v2.0

dist:
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	mv  ./build/view.app  Archive_SmartCalc_v2.0/src/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	rm -rf Archive_SmartCalc_v2.0/

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f *.out
	@rm -f *.gcda
	@rm -f *.gcdo
	@rm -f *.gcno
	@rm -f *.info
	@rm -f *.info
	@rm -f ./*/*.gch
	@rm -rf build
	@rm -f RESULT_VALGRIND.txt

leaks: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests.o

check:
	@cp ../materials/linters/.clang-format ./
	@cd view && clang-format -i ./*.cc ./*.h
	@cd model && clang-format -i ./*.cc ./*.h
	@cd controller && clang-format -i ./*.cc ./*.h
	@rm -rf .clang-format

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(ALL_FILE_CC)