#!/bin/sh
sed -i -e "s/database_name_here/$MARIADB_DB/g" /var/www/html/wp-config.php
sed -i -e "s/username_here/$MARIADB_ID/g" /var/www/html/wp-config.php
sed -i -e "s/password_here/$MARIADB_PW/g" /var/www/html/wp-config.php
sed -i -e "s/localhost/$MARIADB_HOST/g" /var/www/html/wp-config.php

exec "$@"
