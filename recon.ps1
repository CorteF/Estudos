$site = Read-Host "Digite o Site"
$web = (Invoke-WebRequest $site)
echo "O servidor roda:"
$web.headers.server
echo ""
echo "Servidor aceita os métodos:"
$web.headers.allow
echo ""
echo "Links Encontrados:"
$web.links.href | Select-String "http"
