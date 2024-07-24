#!/bin/bash

while [ 1 ]
do
	./generator 30 30 5 | ./bsq
	sleep 1
	echo
done