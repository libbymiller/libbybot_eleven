# Installation

The idea is to have WebRTC (web-based peer-to-peer audio / video / data) using 
[RTCMulticonnection](http://www.rtcmulticonnection.org) running on an https server 
using [letsencrypt](https://letsencrypt.org).

Chrome and Chromium won’t work without https, hence letsencrypt.

I have a slightly custom version of the RTCMulticonnection server, js and html files, included in this repo.

I run this on a linode small instance. I've had trouble with AWS, but that might just be me. Bear in mind that webRTC needs [a lot of ports open](https://www.quora.com/What-ports-does-WebRTC-use?share=1).

I'm assuming Ubuntu.

## Install and configure Apache 

I used [this guide](https://www.digitalocean.com/community/tutorials/how-to-secure-apache-with-let-s-encrypt-on-ubuntu-16-04) for letsencrypt.

First set up your subdomain, for example 'libbybot.example.com' and make sure your DNS is in place. 

Install apache

    sudo apt-get install apache2

    sudo mkdir -p /var/www/your-server/public_html
    sudo chown -R $USER:$USER /var/www/your-server
    sudo chmod -R 755 /var/www
    nano /var/www/your-server/public_html/index.html
    sudo cp /etc/apache2/sites-available/000-default.conf /etc/apache2/sites-available/your-server.conf

Configure

    sudo nano /etc/apache2/sites-available/your-server.conf

contents:

    <VirtualHost *:80>     
        ServerAdmin webmaster@localhost
        ServerName your-server
        ServerAlias your-server
        ErrorLog ${APACHE_LOG_DIR}/your-server_error.log
        CustomLog ${APACHE_LOG_DIR}/your-server_access.log combined
        RewriteEngine on
        RewriteCond %{SERVER_NAME} your-server
        RewriteRule ^ https://%{SERVER_NAME}%{REQUEST_URI} [END,QSA,R=permanent]
    </VirtualHost>

    sudo a2ensite your-server.conf
    sudo a2enmod rewrite
    sudo service apache2 reload
    sudo service apache2 restart

## Add certs

    sudo apt-get install git
    sudo git clone https://github.com/letsencrypt/letsencrypt /opt/letsencrypt
    cd /opt/letsencrypt
    ./letsencrypt-auto --apache -d your-server
    /opt/letsencrypt/letsencrypt-auto renew >> /var/log/le-renew.log
    sudo /opt/letsencrypt/letsencrypt-auto renew >> /var/log/le-renew.log
    sudo mkdir /var/log/
    sudo mkdir /var/log/lets-encrypt

auto-renew

     crontab -e

contents

     # m h  dom mon dow   command
     30 2 * * 1 sudo -H /opt/letsencrypt/letsencrypt-auto renew >> /var/log/lets-encrypt/le-renew.log


## Get and install [RTCMultiConnection](http://www.rtcmulticonnection.org)

Install node

    curl -sL https://deb.nodesource.com/setup_4.x — Node.js v4 LTS "Argon"

    sudo apt-get install -y nodejs

[Install RTCMulticonnection server and API](https://github.com/muaz-khan/RTCMultiConnection/blob/master/docs/installation-guide.md)

    cd /var/www/your-server/
    git clone https://github.com/muaz-khan/RTCMultiConnection
    cd RTCMultiConnection
    npm install --production

Replace the default server with the one in this in this github, replacing "yourserver" with your server's name.

Add a new directory 'libbybot', and add the html and javascript files from 
this github repo directory into that directory.

## Run the server:

    nohup nodejs server.js > /dev/null 2>&1 &

Longer term, you need to figure out how to do notifications. There's a 
place in [server.js](/../server/server.js) where you can send a dm tweet,
for example.
