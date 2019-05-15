#!/usr/bin/env bash

readonly PRECISSION=3

read expression

result=$(bc -l <<< ${expression})
result_rounded=`printf "%.*f" ${PRECISSION} ${result}`
echo ${result_rounded}