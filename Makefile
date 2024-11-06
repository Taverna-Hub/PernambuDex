# CC = gcc
# SRC = $(shell find src -name '*.c')  
# OBJ = $(SRC:.c=.o)  
# TARGET = pernambudex.out
# CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  

# $(TARGET): $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

# %.o: %.c
# 	$(CC) -c $< -o $@

# clean:
# 	rm -f $(OBJ) $(TARGET)

# all: ./$(TARGET)

# run: clean all
# 	clear
# 	./$(TARGET)

# Compiladores
CC_LINUX = gcc
CC_WINDOWS = x86_64-w64-mingw32-gcc  # Compilador MinGW para Windows

# Fontes e objetos
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)

# Nome dos binários
TARGET_LINUX = pernambudex.out
TARGET_WINDOWS = pernambudex.exe

# Flags de compilação para cada sistema operacional
CFLAGS_LINUX = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CFLAGS_WINDOWS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Detectar sistema operacional
ifeq ($(OS),Windows_NT)
	COMPILER = $(CC_WINDOWS)
	CFLAGS = $(CFLAGS_WINDOWS)
	TARGET = $(TARGET_WINDOWS)
else
	COMPILER = $(CC_LINUX)
	CFLAGS = $(CFLAGS_LINUX)
	TARGET = $(TARGET_LINUX)
endif

# Regra principal
$(TARGET): $(OBJ)
	$(COMPILER) -o $@ $^ $(CFLAGS)

# Compilar objetos em paralelo
%.o: %.c
	$(COMPILER) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJ) $(TARGET_LINUX) $(TARGET_WINDOWS)

# Compilar tudo com paralelismo
all: $(TARGET)

run: clean all
	./$(TARGET)
