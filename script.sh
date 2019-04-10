#!/bin/bash
for i in {1..10}
do
	for j in 10 50 100 200 400 500 800 1000
	do
		echo $j > input.txt
		./a.out < input.txt >> result.txt
	done
done
