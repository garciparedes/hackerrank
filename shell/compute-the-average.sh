#!/usr/bin/env bash

readonly PRECISSION=3

read n

x=0
for i in $(seq 1 $n); do
  read v
  ((x+=$v))
done

y=$(bc -l <<< "$x / $n")

echo `printf "%.*f" $PRECISSION $y`