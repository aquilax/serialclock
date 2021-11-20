serialclock:
	cc -o serialclock serialclock.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm serialclock