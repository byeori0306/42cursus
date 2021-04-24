FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y nginx openssl php-fpm \
	mariadb-server php-mysql php-mbstring \
	wget

COPY srcs/scripts /scripts

ENV AUTO 1
COPY srcs/ssl/priv.key /etc/ssl/private/
COPY srcs/ssl/cert.crt /etc/ssl/certs/
RUN chmod 600 /etc/ssl/*
COPY srcs/files/default /etc/nginx/sites-available/

RUN sh scripts/set_phpmyadmin.sh
COPY srcs/files/config.inc.php /var/www/html/admin/

RUN service mysql start && \
	mysql -u root < scripts/set_db.sql && \
	mysql -u root < /var/www/html/admin/sql/create_tables.sql

RUN sh scripts/set_wordpress.sh
COPY srcs/files/wp-config.php /var/www/html/wordpress/

EXPOSE 80 443

CMD sh scripts/init_container.sh
