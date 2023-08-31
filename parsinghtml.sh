#!/bin/bash
if [ "$1" == "" ]
then
        echo "Parsing HTML"
        echo "Tutorial, digite: ./parsing.sh www.site.com.br"
        echo "Descubra domínios de sites!"
else
        site=$1;
        urls=$(wget -O - "$site" | grep -Eo 'https?://[^"]+' | awk -F/ '{print $3}' | sort -u);

        echo "Urls encontradas:"
        echo "$urls"

        echo "Verificando Hosts:"
        for url in $urls; do
        teste=$(host "$url");
        teste1=$(echo "$teste" | sed 's/has address/=/g' | grep " = ");
        teste2+="$teste1\n";
        echo "$teste1"
    done
        teste3=$(echo -e "$teste2" | cut -d " " -f 3 | sort -u);
        echo "Teste de Ping:";
        for ip in $teste3; do
        ping -c 2 $ip | grep "64 bytes" | cut -d " " -f 4 | sed 's/.$//';
    done
fi
