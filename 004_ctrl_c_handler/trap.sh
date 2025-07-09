#!/bin/bash

set -o errexit -o errtrace

trap 'echo trap $?' ERR

function f() {
  echo 1
#   false
  echo 2
}

function trap_func() {
  echo trap_func $?
}

f
