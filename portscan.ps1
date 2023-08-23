param($ip)
if (!$ip){
    echo "Modo de uso:"
    echo "Digite .\portscan 192.168.1.10"
} else {
$topport = 21,22,80,443,3306
try {foreach ($porta in $topport){
if (Test-NetConnection $ip -Port $porta -WarningAction SilentlyContinue -InformationLevel Quiet) {
    echo "Porta $porta aberta"
}} else {
    echo "porta fechada"
}} catch {}
}