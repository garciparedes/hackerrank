#!/usr/bin/env bash

read logical

logical=${logical,,}

if [ $logical == "y" ]; then
  echo "YES"
else
  echo "NO"
fi
