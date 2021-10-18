#!/bin/bash

declare -a mat1
declare -a mat2

echo "Enter row1, col1, col2 :"
read r1
read c1
read c2

echo "Enter mat1 :"
for((i=0; i<r1; i++))
do
	for((j=0; j<c1; j++))
	do
		read mat1[$((c1*i+j))]
	done
done

echo "Enter mat2 :"
for((i=0; i<c1; i++))
do
	for((j=0; j<c2; j++))
	do
		read mat2[$((c2*i+j))]
	done
done

echo "Product :"
for((i=0; i<r1; i++))
do
	for((j=0; j<c2; j++))
	do
		sum=0
		for((k=0; k<c1; k++))
		do
			sum=$((sum + mat1[c1*i+k] * mat2[c2*k+j]))
		done
		echo -n "$sum "
	done
	echo
done

unset mat1
unset mat2
