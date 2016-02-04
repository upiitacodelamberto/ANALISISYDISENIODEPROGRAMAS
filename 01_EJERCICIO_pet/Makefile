CC=g++

all:TestIntegral SquaredX linearX

TestIntegral:TestIntegracion.cpp
	${CC} $< -o $@

SquaredX:IntegrarSquaredX.cpp
	${CC} $< -o $@

linearX:IntegrarX.cpp
	${CC} $< -o $@

clean:
	rm -v TestIntegral SquaredX linearX
