# Makefile 구성요소 : 목적파일(target), 의존성(dependency), 명령어(command), 매크로(macro)
# 1. 목적파일 : 명령어 수행 후 나온 파일을 저장할 파일
# 2. 의존성 : 목적 파일을 만들기 위한 재료 파일
# 3. 명령어 : 실행되어야 할 명령어들
# 4. 매크로 : 코드 단순화

#add_nbo : add_nbo.o 
#	gcc -o add_nbo_exe add_nbo.o

#add_nbo.o : add_nbo.c
#	gcc -c -o add_nbo.o add_nbo.c 

#clean : 
#	rm *.o add_nbo_exe


# marco로도 만들어보자
CC = gcc
TARGET = add_nbo
$(TARGET) : add_nbo.o
	$(CC) -o $(TARGET) add_nbo.o

add_nbo.o : add_nbo.c 
	$(CC) -c -o add_nbo.o add_nbo.c

clean :
	rm *.o add_nbo
