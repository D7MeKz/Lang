# https://lazyadmin.nl/powershell/download-file-powershell/
# *1. use Invoke-WebRequest
# Source URL 
$url = "http://sample.com/a.txt"

# Destation file 
$dest = "c:\temp\b.txt"

# Download the file 
Invoke-WebRequest -Url $url -OutFile $dest

# *2 Authentication with Invoke-WebRequest
