#!/bin/bash

find -type f \( -name '*.exe' -o -name '*.o' -o -name '*.dll' \) -exec rm {} \;
