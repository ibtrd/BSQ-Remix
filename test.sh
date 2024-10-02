#!/bin/bash

set -o pipefail
while :
do
    X=5
    Y=70
    RANGE=$((Y-X+1))
    R1=$(($(($RANDOM%$RANGE))+X))
    R2=$(($(($RANDOM%$RANGE))+X))
    if [ $R1 -gt $R2 ]
    then
        RANGE2=$R2
    else
        RANGE2=$R1
    fi
    R3=$(($(($RANDOM%$RANGE2))+1))

    ./generator $R1 $R2 $R3 > map
    cat map
    echo && echo
    ./bsq map
    sleep 1
	echo && echo
done