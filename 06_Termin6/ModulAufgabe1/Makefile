# Makefile für das C-Projekt

# Compiler
CC = gcc

# Compiler-Flags
CFLAGS = -Wall -g

# Ziel: das ausführbare Programm
TARGET = MakefileTest.exe

# Liste der Quelldateien
SRCS = TestComplex.c complex.c

# Regel zum Erstellen des ausführbaren Programms
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Regel zum Löschen des ausführbaren Programms
clean:
	rm -f $(TARGET)