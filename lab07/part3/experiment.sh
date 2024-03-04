#!/bin/bash

NUMBER=256
echo -n "Choose an algorithm: "

read CHOICE

for ((i=0;i<8;i++))
do
	if (("$CHOICE" == 1))
	then
		echo Pushing output for ./matrix_math 1 to data.txt...
		./matrix_math 1 $NUMBER >> data.txt
		let NUMBER=NUMBER+256
	elif (("$CHOICE" == 2))
	then
		./matrix_math 2 $NUMBER >> data.txt
		let NUMBER=NUMBER+256
	else
		echo "ERROR! Usage: 1 or 2"
		break
	fi
	echo Done.
done