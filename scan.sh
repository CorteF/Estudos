
#!/bin/bash

if [ "$1" == "" ]
then
        echo  "Scan de Rede "
        echo  "Para utilizar:"
        echo  "Digite - $0 192.168.1"
else
for host in {1..254};
do
ping -c 1 $1.$host | grep "64 bytes" | cut -d " " -f 4 | sed 's/.$//';
done
fi


