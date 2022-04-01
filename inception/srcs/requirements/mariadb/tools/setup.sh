service mysql start

mysql -u root -e "CREATE DATABASE ${MARIADB_DB};"
mysql -u root -e "CREATE USER '${MARIADB_ID}'@'localhost' IDENTIFIED BY '${MARIADB_PW}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIADB_ID}'@'localhost' WITH GRANT OPTION;"
mysql -u root -e "UPDATE mysql.user SET Password = PASSWORD('{MARIADB_ROOT_PW}') WHERE User = 'root';"
mysql -u root -e "FLUSH PRIVILEGES;"

