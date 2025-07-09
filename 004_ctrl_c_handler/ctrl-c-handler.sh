#!/bin/bash

trap 'ctrlCHandler' SIGINT

ctrlCPressed=0
pendExit=0

ctrlCHandler() {
  if [ $ctrlCPressed == 0 ]; then
    echo First
    ctrlCPressed=1
#     pendExit=1
  else
    echo Second
    echo Interrupted
    exit
  fi
}

main() {
  while [ $pendExit == 0 ]; do
    echo sleep 1
    sleep 3
    echo doing I/O
    dd if=/dev/random of=tmp.dat bs=1024 count=$((100*1024))
    echo sleep 2
    sleep 3
  done
  echo While exited
}

main
