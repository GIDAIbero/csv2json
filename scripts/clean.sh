if [ -a "CSV2JSON" ]
then
    echo "removing binary"
    rm -rf CSV2JSON
else
    echo "there is no binary"
fi
if  ls *.o &> /dev/null 
then
    echo "removing .o files"
    rm *.o
else
    echo "there are no .o files"
fi

