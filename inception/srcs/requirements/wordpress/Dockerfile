FROM debian:buster

RUN apt-get update && apt-get install -y php-fpm \
php-mysql \
php-mbstring \
wget

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf latest.tar.gz
RUN rm latest.tar.gz

CMD tail -f /dev/null 
