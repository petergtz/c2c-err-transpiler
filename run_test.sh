#!/bin/sh

./c2c < $1 > /tmp/error_handling_inter_output.c
astyle --style=stroustrup <  /tmp/error_handling_inter_output.c > /tmp/error_handling_output.c 
diff --ignore-all-space -U 1000 --strip-trailing-cr /tmp/error_handling_output.c $2
RC=$?
if [ "$RC" -ne "0" ]; then
    meld /tmp/error_handling_output.c $2 2>&1 > /dev/null
fi
rm /tmp/error_handling_output.c
rm /tmp/error_handling_inter_output.c
exit ${RC}

