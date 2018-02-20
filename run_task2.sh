#!/bin/bash

if [ ! $# -eq 1 ]
then
	echo "Usage: $0 <exploit2 executable name>"
	exit 1
fi

exp=$1

rm -f f0
rm -f f1
mkfifo f0 f1

./$exp < f0 > f1 &

echo "Now run your vulnerable program (if there were no errors)"
