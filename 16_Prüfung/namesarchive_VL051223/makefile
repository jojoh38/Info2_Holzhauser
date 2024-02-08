namesarchive: main.o libnamesarchive.so
		gcc -Wall -o namesarchive main.o libnamesarchive.so
		
main.o: main.c
		gcc -c -Wall main.c
		
namesarchive.o: namesarchive.c namesarchive.h
		gcc -c -Wall namesarchive.c
		
libnamesarchive.so: namesarchive.o
		gcc -shared -o libnamesarchive.so namesarchive.o

namesarchive_timing: main_timing.o libnamesarchive_timing.so
		gcc -Wall -o namesarchive_timing main_timing.o libnamesarchive_timing.so

main_timing.o: main_timing.c
		gcc -c -g -Wall main_timing.c

namesarchive_141123.o: namesarchive_141123.c namesarchive_141123.h
		gcc -c -Wall namesarchive_141123.c

namesarchive_211123.o: namesarchive_211123.c namesarchive_211123.h
		gcc -c -Wall namesarchive_211123.c

libnamesarchive_timing.so: namesarchive.o namesarchive_141123.o namesarchive_211123.o
		gcc -shared -o libnamesarchive_timing.so namesarchive.o namesarchive_141123.o namesarchive_211123.o
		
clean:
		del /f namesarchive.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
#       rm -f namesarchive *.o *.so