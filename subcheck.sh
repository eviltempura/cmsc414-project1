#!/bin/bash

# subcheck.sh
#
# Please do not include any unnecessary subdirectories.

if [ ! $# -eq 1 ]
then
	echo "Usage: $0 <submission directory>"
	exit 1
fi

erred=0

err()
{
	echo "[error] $1"
	erred=1
}

wrn()
{
	echo "[warning] $1"
}

submitdir=`echo "$1" | sed 's/\/$//'`

if [ ! -d $submitdir ]
then
	echo "Directory $submitdir doesn't exist"
	exit 1
fi


echo "Checking files in $submitdir/"


for x in 1 2 3
do
	if [ ! -f $submitdir/guesser$x.c ]
	then
		err "missing $submitdir/guesser$x.c"
	fi
done

for x in 1 2
do
	if [ ! -f $submitdir/exploit$x.c ]
	then
		err "missing $submitdir/exploit$x.c"
	fi
done

for fname in $submitdir/task3/substring.c $submitdir/task3/read.c
do
	if [ ! -f $fname ]
	then
		err "missing $fname"
	fi
done

if [ -d $submitdir/task5 ]
then
	if [ ! -f $submitdir/task5/exploit5.txt ]
	then
		wrn "there's a task5/ but no task5/readme.txt (OPTIONAL)"
	fi
	if [ ! -f $submitdir/task5/readme.txt ]
	then
		wrn "there's a task5/ but no task5/readme.txt (OPTIONAL)"
	fi
fi

if [ -d $submitdir/task6 ]
then
	if [ ! -f $submitdir/task6/readme.txt ]
	then
		wrn "there's a task5/ but no task5/readme.txt (OPTIONAL)"
	fi
fi

echo ""

if [ $erred -eq 0 ]
then
	echo "[success] $submitdir has all of the files required for submission."
	echo "         Be sure to also post your security review on Piazza."
else
	echo "[error] For full credit, fix the [error]s above before submitting."
	echo "        Consult the spec for details."
fi

echo ""
