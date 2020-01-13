ps | grep "/mnt/tf/3 -qws" | grep -v grep >/dev/null
if [ $? -eq 0 ]
then
    id=`ps | grep "/mnt/tf/3 -qws" | awk 'NR==1{print $1}'`
    echo "kill $id"
    kill $id
fi
