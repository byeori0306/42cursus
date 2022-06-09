#!/bin/sh
if [ ! -f $WP_PATH/wp-config.php ]
then
mv $WP_PATH/wp-config-sample.php $WP_PATH/wp-config.php

sed -i -e "s/database_name_here/$MARIADB_DB/g" $WP_PATH/wp-config.php
sed -i -e "s/username_here/$MARIADB_ID/g" $WP_PATH/wp-config.php
sed -i -e "s/password_here/$MARIADB_PW/g" $WP_PATH/wp-config.php
sed -i -e "s/localhost/$MARIADB_HOST/g" $WP_PATH/wp-config.php

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar usr/local/bin/wp

while ! mysqladmin ping -h "$MARIADB_HOST" --silent; do
	echo "waiting"
	sleep 2
done

wp core install \
	--url=$DOMAIN_NAME \
	--title=$TITLE \
	--admin_user=$ADMIN_ID \
	--admin_password=$ADMIN_PW \
	--admin_email=$ADMIN_EMAIL \
	--skip-email \
	--allow-root \
	--path=$WP_PATH

wp user create $USER_ID $USER_EMAIL \
	--user_pass=$USER_PW \
	--allow-root \
	--path=$WP_PATH
fi

exec "$@"
