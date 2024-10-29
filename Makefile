all: 
	gcc src/main.c src/utils/resizeImage.c -o game -lraylib -lm -lpthread -ldl -lrt -lX11

run:
	./game
