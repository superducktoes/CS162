#!/bin/bash

for i in $(seq 25 41);
do  ./lab_10 $i
    echo "testing " $i
done
