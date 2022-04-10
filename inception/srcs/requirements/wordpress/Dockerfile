FROM debian:buster

RUN apt-get update && apt-get install -y php-fpm \
php-mysql \
php-mbstring \
wget

ARG ${MARIADB_DB}
ENV MARIADB_DB=${MARIADB_DB}

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf latest.tar.gz
RUN rm latest.tar.gz
RUN mkdir -p var/www/html
RUN mv wordpress/* var/www/html/
RUN mv var/www/html/wp-config-sample.php var/www/html/wp-config.php

RUN sed -i 's%/run/php/php7.3-fpm.sock%0.0.0.0:9000%g' /etc/php/7.3/fpm/pool.d/www.conf
RUN service php7.3-fpm start

RUN sed -i 's/database_name_here/${MARIADB_DB}/g' /var/www/html/wp-config.php
RUN sed -i 's/username_here/${MARIADB_ID}/g' /var/www/html/wp-config.php
RUN sed -i 's/password_here/${MARIADB_PW}/g' /var/www/html/wp-config.php
RUN sed -i 's/localhost/${MARIADB_HOST}/g' /var/www/html/wp-config.php

CMD php-fpm7.3 --nodaemonize 
