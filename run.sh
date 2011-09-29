#!/bin/sh

make && ./c2c < test_file > /tmp/error_handling_output.c
astyle --style=stroustrup <  /tmp/error_handling_output.c
rm /tmp/error_handling_output.c
