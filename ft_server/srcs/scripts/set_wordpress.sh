#!/bin/sh

wget https://wordpress.org/latest.tar.gz
tar -xf latest.tar.gz
rm latest.tar.gz
mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
