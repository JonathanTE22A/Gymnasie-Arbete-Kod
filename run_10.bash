#!/bin/bash

# Usage: ./run_multiple_times.sh <number_of_times> <script_or_program>

if [ $# -ne 2 ]; then
  echo "Usage: $0 <number_of_times> <script_or_program>"
  exit 1
fi

number_of_times=$1
script_or_program=$2

for ((i=1; i<=number_of_times; i++))
do
  echo "Run #$i"
  $script_or_program
  echo "----------"
done
