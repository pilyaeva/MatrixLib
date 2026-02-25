CC=g++
CPPFLAGS=-Wall -Werror -Wextra -std=c++17
LFLAGS=-lgtest -lgmock -pthread
LDFLAGS=-lgtest -lgmock -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -fPIC
CFILES=s21_matrix_oop.a
CEXE=s21_test

#============= ALL ==================================================================
all: clean ${CFILES}

#============= LIBRIRY & TEST LIBRARY================================================

s21_matrix_oop.a:
	${CC} ${CPPFLAGS} -c s21_matrix*.cpp
	ar rc ${CFILES} *.o
	ranlib ${CFILES}
	@rm -f *.o
#	g++ --version


gcov_s21_matrix_oop.a: clean
	${CC} ${CPPFLAGS} -c *.cpp ${GCOV_FLAGS}
	ar rcs ${CFILES} *.o
	ranlib ${CFILES}
	@rm -f *.o

#============= TEST ==============================================================

test: clean s21_matrix_oop.a
	$(CC) ${CPPFLAGS} tests/*.cpp  ${CFILES} -o ${CEXE} ${LDFLAGS}
	./${CEXE}

gcov_report: clean gcov_s21_matrix_oop.a
	@$(CC) ${CPPFLAGS} -fprofile-arcs -ftest-coverage tests/*.cpp s21_matrix_oop.a -o ${CEXE} ${LDFLAGS} ${GCOV_FLAGS}
	@mkdir report
	@./${CEXE} >> report/s21_report.txt
	@lcov --ignore-errors inconsistent -t "gcov_test" -o gcov_test.info --no-external -c -d .
	@genhtml gcov_test.info --output-directory coverage_report
	@genhtml -o report/ gcov_test.info
	@rm -rf *.gcda *.gcno *.info ${CEXE} coverage_report
	@open report/index.html
	

#=========== STYLE ====================================================================
format_check:
	@cp ../materials/linters/.clang-format ../src/.clang-format
	@clang-format -n tests/*.cpp *.cpp *.h
	@rm -f .clang-format

format:
	@cp ../materials/linters/.clang-format ../src/.clang-format
	@clang-format -i tests/*.cpp *.cpp *.h
	@rm -f .clang-format

#========== CLEAN ======================================================================
clean:
	@rm -rf s21_test
	@rm -rf *.o
	@rm -rf *.out
	@rm -rf *.a
	@rm -rf *.gcno
	@rm -rf *.gcda
	@rm -rf *.gcov
	@rm -rf *.log
	@rm -rf *.html
	@rm -rf *.css
	@rm -rf report
	@rm -rf *.dSYM
	@rm -rf *.info

valgrind: clean s21_matrix_oop.a
	@$(CC) ${CPPFLAGS} tests/*.cpp ${CFILES} -o ${CEXE} ${LFLAGS}
	@valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./${CEXE}