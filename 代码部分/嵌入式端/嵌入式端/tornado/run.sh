#!/bin/sh
ps | grep "/mnt/tf/3 -qws" | grep -v grep >/dev/null
if [ $? -ne 0 ]
then
    /mnt/tf/3 -qws >/dev/null 2>&1 &
fi
