#!/bin/bash

if [ ${AUTO} -eq 0 ];then
	sed -i 's/autoindex on;/autoindex off;/g' /etc/nginx/sites-available/default
fi
service nginx start
service php7.3-fpm start
service php7.3-fpm status
service mysql start
sleep infinity
