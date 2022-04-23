#!/bin/bash
if [ ! -d /var/lib/mysql/$MARIADB_DB ]
then
service mysql start

mysql -u root -e "CREATE DATABASE $MARIADB_DB;"
mysql -u root -e "CREATE USER '$MARIADB_ID'@'%' IDENTIFIED BY '$MARIADB_PW';"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO '$MARIADB_ID'@'%';"
mysql -u root -e "FLUSH PRIVILEGES;"
mysql -u root -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MARIADB_ROOT_PW');"
mysql -u root -e "UPDATE mysql.user SET plugin = '' WHERE user = 'root' AND host = 'localhost';"

sleep 3

service mysql stop
fi

exec "$@"
