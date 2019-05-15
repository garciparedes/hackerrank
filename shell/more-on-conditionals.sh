#!/usr/bin/env bash

readonly SCALENE="SCALENE"
readonly EQUILATERAL="EQUILATERAL"
readonly ISOSCELES="ISOSCELES"

read x
read y
read z

if ((x == y && y == z && z == x)); then
  echo EQUILATERAL
elif (((x == y)) && ((y != z))) \
        || (((y == z)) && ((z != x))) \
        || (((z == x)) && ((x != y))); then
  echo ISOSCELES
else
  echo SCALENE
fi