#!/bin/bash

script_dir=$(realpath "$(dirname "${BASH_SOURCE[0]}")")
cd $script_dir
last=$(find ./ -maxdepth 1 -type d -printf "%f\n" | grep -Po "^\d+" | sed -E 's/^0+//' | sort -n | tail -n 1)
next=$(printf "%03d" $(( last + 1 )))
if [ -n "$1" ]; then
  next=${next}_$1
fi
mkdir $next && cd $next
$SHELL
