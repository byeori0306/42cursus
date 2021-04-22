#!/bin/sh

openssl req -x509 -newkey rsa:4096 -nodes -sha256 -keyout ft_server.key -out ft_server.crt -days 365 -subj "/C=KR/ST=SEOUL/L=SEOUL/O=42seoul/OU=gun/CN=localhost"
mv ft_server.key /etc/ssl/private
mv ft_server.crt /etc/ssl/certs
chmod 600 /etc/ssl/*
