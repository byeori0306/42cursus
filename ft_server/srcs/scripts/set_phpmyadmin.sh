#!/bin/sh

wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz
tar -xf phpMyAdmin-4.9.7-all-languages.tar.gz
rm phpMyAdmin-4.9.7-all-languages.tar.gz
mv phpMyAdmin-4.9.7-all-languages/ admin
mv admin /var/www/html/
chown -R www-data /var/www/html/
