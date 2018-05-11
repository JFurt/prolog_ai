#!/bin/bash

make clean && make

if [ ! -d "Resultados" ]
then
	mkdir Resultados
fi

./timer.sh 500 512 1022 1024 1026 2046 2048
