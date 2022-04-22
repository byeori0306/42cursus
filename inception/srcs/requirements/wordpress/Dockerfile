FROM debian:buster

RUN apt-get update && apt-get install -y php-fpm \
php-mysql \
php-mbstring \
wget \
mariadb-client

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf latest.tar.gz
RUN rm latest.tar.gz
RUN mkdir -p var/www/html
RUN mv wordpress/* var/www/html/

RUN sed -i 's%/run/php/php7.3-fpm.sock%0.0.0.0:9000%g' /etc/php/7.3/fpm/pool.d/www.conf

RUN service php7.3-fpm start

COPY tools/setup.sh .
RUN chmod 755 ./setup.sh
ENTRYPOINT ["/setup.sh"]
CMD ["php-fpm7.3", "--nodaemonize"]
