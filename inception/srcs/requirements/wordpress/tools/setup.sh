#!/bin/sh
sed -i -e "s/database_name_here/$MARIADB_DB/g" $WP_PATH/wp-config.php
sed -i -e "s/username_here/$MARIADB_ID/g" $WP_PATH/wp-config.php
sed -i -e "s/password_here/$MARIADB_PW/g" $WP_PATH/wp-config.php
sed -i -e "s/localhost/$MARIADB_HOST/g" $WP_PATH/wp-config.php

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar usr/local/bin/wp

sleep 10
# while ! mysqladmin ping -h "$DB_HOST" --silent; do
#	echo "waiting"
#	sleep 1
#done

wp core install \
	--url=127.0.0.1 \
	--title=$TITLE \
	--admin_user=$ADMIN_ID \
	--admin_password=$ADMIN_PW \
	--admin_email=$ADMIN_EMAIL \
	--skip-email \
	--allow-root \
	--path=$WP_PATH

wp user create $USER_ID $USER_EMAIL \
	--user_pass=USER_PW \
	--allow-root \
	--path=$WP_PATH

exec "$@"
