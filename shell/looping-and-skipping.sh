#!/usr/bin/env bash

i_start=1
i_end=99

for i in $(seq $i_start $i_end); do
  if (($i % 2 == 1 )); then
    echo $i
  fi
done